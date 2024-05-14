#include "router.h"

#include "error.h"
#include "login.h"

#include <boost/json/parse.hpp>
#include <boost/json/serialize.hpp>

namespace {

std::pair<boost::beast::http::status, boost::json::value> router(std::string_view type, const boost::json::object& body)
{
	using namespace tfs::http;

	if (type == "login") {
		return handle_login(body);
	}

	return {boost::beast::http::status::not_found, {}};
}

} // namespace

boost::beast::http::message_generator tfs::http::handle_request(const Request& req)
{
	auto&& [status, responseBody] = [&req]() {
		boost::json::error_code ec;
		auto requestBody = boost::json::parse(req.body(), ec);
		if (ec || !requestBody.is_object()) {
			return make_error_response({.code = 2, .message = "Invalid request body."});
		}

		const auto& requestBodyObj = requestBody.get_object();
		auto typeField = requestBodyObj.if_contains("type");
		if (!typeField || !typeField->is_string()) {
			return make_error_response({.code = 2, .message = "Invalid request type."});
		}

		return router(typeField->get_string(), requestBodyObj);
	}();

	boost::beast::http::response<boost::beast::http::string_body> res{status, req.version()};
	res.body() = boost::json::serialize(responseBody);
	res.keep_alive(req.keep_alive());
	res.prepare_payload();
	return res;
}
