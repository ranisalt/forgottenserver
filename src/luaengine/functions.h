#ifndef TFS_LUAUTILS_H
#define TFS_LUAUTILS_H

#include <lua.hpp>

#include "../game.h"
#include "../position.h"

class Cylinder;
class InstantSpell;
class Thing;

enum ErrorCode_t {
	LUA_ERROR_PLAYER_NOT_FOUND,
	LUA_ERROR_CREATURE_NOT_FOUND,
	LUA_ERROR_ITEM_NOT_FOUND,
	LUA_ERROR_THING_NOT_FOUND,
	LUA_ERROR_TILE_NOT_FOUND,
	LUA_ERROR_HOUSE_NOT_FOUND,
	LUA_ERROR_COMBAT_NOT_FOUND,
	LUA_ERROR_CONDITION_NOT_FOUND,
	LUA_ERROR_AREA_NOT_FOUND,
	LUA_ERROR_CONTAINER_NOT_FOUND,
	LUA_ERROR_VARIANT_NOT_FOUND,
	LUA_ERROR_VARIANT_UNKNOWN,
	LUA_ERROR_SPELL_NOT_FOUND,
};

enum LuaVariantType_t {
	VARIANT_NONE,

	VARIANT_NUMBER,
	VARIANT_POSITION,
	VARIANT_TARGETPOSITION,
	VARIANT_STRING,
};

struct LuaVariant {
	LuaVariantType_t type = VARIANT_NONE;
	std::string text;
	Position pos;
	uint32_t number = 0;
};

template<typename T>
static typename std::enable_if<std::is_enum<T>::value, T>::type
getNumber(lua_State* L, int32_t arg)
{
	return static_cast<T>(static_cast<int64_t>(lua_tonumber(L, arg)));
}
template<typename T>
static typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, T>::type
getNumber(lua_State* L, int32_t arg)
{
	return static_cast<T>(lua_tonumber(L, arg));
}
template<typename T>
static T getNumber(lua_State *L, int32_t arg, T defaultValue)
{
	const auto parameters = lua_gettop(L);
	if (parameters == 0 || arg > parameters) {
		return defaultValue;
	}
	return getNumber<T>(L, arg);
}

template<class T>
T** getRawUserdata(lua_State* L, int32_t arg)
{
	return static_cast<T**>(lua_touserdata(L, arg));
}

template<class T>
T* getUserdata(lua_State* L, int32_t arg)
{
	T** userdata = getRawUserdata<T>(L, arg);
	if (!userdata) {
		return nullptr;
	}
	return *userdata;
}

bool getBoolean(lua_State* L, int32_t arg);
bool getBoolean(lua_State* L, int32_t arg, bool defaultValue);
Creature* getCreature(lua_State* L, int32_t arg);
std::string getFieldString(lua_State* L, int32_t arg, const std::string& key);
Outfit_t getOutfit(lua_State* L, int32_t arg);
Player* getPlayer(lua_State* L, int32_t arg);
Position getPosition(lua_State* L, int32_t arg);
Position getPosition(lua_State* L, int32_t arg, int32_t& stackpos);
std::string getString(lua_State* L, int32_t arg);
Thing* getThing(lua_State* L, int32_t arg);
LuaDataType getUserdataType(lua_State* L, int32_t arg);
LuaVariant getVariant(lua_State* L, int32_t arg);

template<typename T>
T getField(lua_State* L, int32_t arg, const std::string& key)
{
	lua_getfield(L, arg, key.c_str());
	return getNumber<T>(L, -1);
}

bool isBoolean(lua_State* L, int32_t arg);
bool isFunction(lua_State* L, int32_t arg);
bool isNumber(lua_State* L, int32_t arg);
bool isString(lua_State* L, int32_t arg);
bool isTable(lua_State* L, int32_t arg);
bool isUserdata(lua_State* L, int32_t arg);

void pushBoolean(lua_State* L, bool value);
void pushCallback(lua_State* L, int32_t callback);
void pushCylinder(lua_State* L, Cylinder* cylinder);
void pushInstantSpell(lua_State* L, const InstantSpell& spell);
void pushOutfit(lua_State* L, const Outfit_t& outfit);
void pushPosition(lua_State* L, const Position& position, int32_t stackpos = 0);
void pushString(lua_State* L, const std::string& value);
void pushThing(lua_State* L, Thing* thing);
void pushVariant(lua_State* L, const LuaVariant& var);

template<class T>
void pushUserdata(lua_State* L, T* value)
{
	T** userdata = static_cast<T**>(lua_newuserdata(L, sizeof(T*)));
	*userdata = value;
}

std::string popString(lua_State* L);
int32_t popCallback(lua_State* L);

void setField(lua_State* L, const char* index, lua_Number value);
void setField(lua_State* L, const char* index, const std::string& value);

void setMetatable(lua_State* L, int32_t index, const std::string& name);
void setWeakMetatable(lua_State* L, int32_t index, const std::string& name);

void setCreatureMetatable(lua_State* L, int32_t index, const Creature* creature);
void setItemMetatable(lua_State* L, int32_t index, const Item* item);

std::string getErrorDesc(ErrorCode_t code);
void reportError(const char* function, const std::string& error_desc, bool stack_trace = false);

#define reportErrorFunc(a)  reportError(__FUNCTION__, a, true)

#endif //TFS_LUAUTILS_H
