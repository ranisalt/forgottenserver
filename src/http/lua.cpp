#include "../otpch.h"

#include "lua.h"

#include "../luascript.h"
#include "session.h"

#include <boost/json/monotonic_resource.hpp>
#include <boost/json/parse.hpp>
#include <boost/json/serialize.hpp>
#include <fmt/core.h>
#include <mutex>

namespace tfs::http {

namespace {

void luaPushJson(lua_State* L, const boost::json::value& jv)
{
	switch (jv.kind()) {
		case boost::json::kind::null:
			lua_pushnil(L);
			break;
		case boost::json::kind::bool_:
			lua_pushboolean(L, jv.get_bool());
			break;
		case boost::json::kind::int64:
			lua_pushinteger(L, jv.get_int64());
			break;
		case boost::json::kind::uint64:
			lua_pushinteger(L, jv.get_uint64());
			break;
		case boost::json::kind::double_:
			lua_pushnumber(L, jv.get_double());
			break;
		case boost::json::kind::string: {
			const auto& str = jv.get_string();
			lua_pushlstring(L, str.data(), str.size());
			break;
		}
		case boost::json::kind::array: {
			const auto& arr = jv.get_array();
			lua_createtable(L, arr.size(), 0);
			for (auto i = 0u; i < arr.size(); ++i) {
				luaPushJson(L, arr.at(i));
				lua_rawseti(L, -2, i + 1);
			}
			break;
		}
		case boost::json::kind::object:
			const auto& obj = jv.get_object();
			lua_createtable(L, 0, obj.size());
			for (auto& [key, value] : obj) {
				luaPushJson(L, value);
				lua_setfield(L, -2, key.data());
			}
			break;
	}
}

boost::json::value luaPopJson(lua_State* L, int idx)
{
	switch (lua_type(L, idx)) {
		case LUA_TNIL:
			return nullptr;
		case LUA_TBOOLEAN:
			return !!lua_toboolean(L, idx);
		case LUA_TNUMBER:
			if (lua_isinteger(L, idx)) {
				return lua_tointeger(L, idx);
			}
			return lua_tonumber(L, idx);
		case LUA_TSTRING: {
			size_t len;
			const char* str = lua_tolstring(L, idx, &len);
			return boost::json::string{str, len};
		}
		case LUA_TTABLE: {
			if (luaL_len(L, idx) > 0) {
				boost::json::array arr;
				lua_pushnil(L);
				while (lua_next(L, idx) != 0) {
					arr.push_back(luaPopJson(L, -1));
					lua_pop(L, 1);
				}
				return arr;
			} else {
				boost::json::object obj;
				lua_pushnil(L);
				while (lua_next(L, idx) != 0) {
					auto key = lua_tostring(L, -2);
					obj[key] = luaPopJson(L, -1);
					lua_pop(L, 1);
				}
				return obj;
			}
		}

		default:
			throw std::runtime_error("Unsupported JSON type");
	}
}

int luaRequestJson(lua_State* L)
{
	if (lua_gettop(L) <= 0) {
		lua_pushnil(L);
		return 1;
	}

	Request* req = lua::getUserdata<Request>(L, 1);
	if (!req) {
		lua_pushnil(L);
		return 1;
	}

	boost::system::error_code ec;
	boost::json::monotonic_resource mr;
	auto json = boost::json::parse(req->body(), ec, &mr);
	if (ec) {
		lua_pushnil(L);
		return 1;
	}

	luaPushJson(L, json);

	return 1;
};

int luaResponseCreate(lua_State* L)
{
	if (lua_gettop(L) <= 1) {
		lua_pushnil(L);
		return 1;
	}

	Request* req = lua::getUserdata<Request>(L, 2);
	if (!req) {
		lua_pushnil(L);
		return 1;
	}

	auto res = new Response{boost::beast::http::status::ok, req->version()};
	lua::pushUserdata(L, res);
	lua::setMetatable(L, -1, "Response");
	return 1;
}

int luaResponseJson(lua_State* L)
{
	if (lua_gettop(L) <= 1) {
		lua_pushnil(L);
		return 1;
	}

	Response* res = lua::getUserdata<Response>(L, 1);
	if (!res) {
		lua_pushnil(L);
		return 1;
	}

	auto jv = luaPopJson(L, 2);
	res->body() = boost::json::serialize(jv);
	res->set(boost::beast::http::field::content_type, "application/json");

	return 1;
}

auto make_lua_state()
{
	std::unique_ptr<lua_State, decltype(&lua_close)> L_ptr{luaL_newstate(), lua_close};
	if (!L_ptr) {
		throw std::runtime_error("Failed to create Lua state");
	}
	auto L = L_ptr.get();

	luaL_openlibs(L);

	int err = luaL_dofile(L, "data/http/http.lua");
	if (err) {
		throw std::runtime_error(fmt::format("Failed to load http.lua: {:s}", lua_tostring(L, -1)));
		lua_pop(L, 1);
	}

	lua::registerClass(L, "Request", "");
	lua::registerMethod(L, "Request", "json", luaRequestJson);

	lua::registerClass(L, "Response", "", luaResponseCreate);
	lua::registerMethod(L, "Response", "json", luaResponseJson);

	return L_ptr;
}

} // namespace

boost::beast::http::message_generator handle_request(Request&& req)
{
	auto L_ptr = make_lua_state();
	auto* L = L_ptr.get();

	lua_getglobal(L, "handleRequest");
	if (!lua_isfunction(L, -1)) {
		throw std::runtime_error("Failed to get handleRequest function");
	}

	lua::pushUserdata(L, &req);
	lua::setMetatable(L, -1, "Request");

	Response res{boost::beast::http::status::ok, req.version()};
	lua::pushUserdata(L, &res);
	lua::setMetatable(L, -1, "Response");

	int err = lua_pcall(L, 2, 1, 0);
	if (err) {
		throw std::runtime_error(fmt::format("Failed to call handleRequest: {:s}", lua_tostring(L, -1)));
	}

	res.keep_alive(req.keep_alive());
	res.prepare_payload();
	return res;
}

} // namespace tfs::http
