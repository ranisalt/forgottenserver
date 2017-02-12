#include <set>
#include "../otpch.h"

#include "functions.h"
#include "luascript.h"

#include "../cylinder.h"
#include "../monster.h"
#include "../teleport.h"
#include "../spells.h"

extern Game g_game;

bool getBoolean(lua_State* L, int32_t arg)
{
	return lua_toboolean(L, arg) != 0;
}

bool getBoolean(lua_State* L, int32_t arg, bool defaultValue)
{
	const auto parameters = lua_gettop(L);
	if (parameters == 0 || arg > parameters) {
		return defaultValue;
	}
	return lua_toboolean(L, arg) != 0;
}

Creature* getCreature(lua_State* L, int32_t arg)
{
	if (isUserdata(L, arg)) {
		return getUserdata<Creature>(L, arg);
	}
	return g_game.getCreatureByID(getNumber<uint32_t>(L, arg));
}

Outfit_t getOutfit(lua_State* L, int32_t arg)
{
	Outfit_t outfit;
	outfit.lookMount = getField<uint16_t>(L, arg, "lookMount");
	outfit.lookAddons = getField<uint8_t>(L, arg, "lookAddons");

	outfit.lookFeet = getField<uint8_t>(L, arg, "lookFeet");
	outfit.lookLegs = getField<uint8_t>(L, arg, "lookLegs");
	outfit.lookBody = getField<uint8_t>(L, arg, "lookBody");
	outfit.lookHead = getField<uint8_t>(L, arg, "lookHead");

	outfit.lookTypeEx = getField<uint16_t>(L, arg, "lookTypeEx");
	outfit.lookType = getField<uint16_t>(L, arg, "lookType");

	lua_pop(L, 8);
	return outfit;
}

Player* getPlayer(lua_State* L, int32_t arg)
{
	if (isUserdata(L, arg)) {
		return getUserdata<Player>(L, arg);
	}
	return g_game.getPlayerByID(getNumber<uint32_t>(L, arg));
}

Position getPosition(lua_State* L, int32_t arg)
{
	Position position;
	position.x = getField<uint16_t>(L, arg, "x");
	position.y = getField<uint16_t>(L, arg, "y");
	position.z = getField<uint8_t>(L, arg, "z");

	lua_pop(L, 3);
	return position;
}

Position getPosition(lua_State* L, int32_t arg, int32_t& stackpos)
{
	Position position;
	position.x = getField<uint16_t>(L, arg, "x");
	position.y = getField<uint16_t>(L, arg, "y");
	position.z = getField<uint8_t>(L, arg, "z");

	lua_getfield(L, arg, "stackpos");
	if (lua_isnil(L, -1) == 1) {
		stackpos = 0;
	} else {
		stackpos = getNumber<int32_t>(L, -1);
	}

	lua_pop(L, 4);
	return position;
}

std::string getString(lua_State* L, int32_t arg)
{
	size_t len;
	const char* c_str = lua_tolstring(L, arg, &len);
	if (!c_str || len == 0) {
		return std::string();
	}
	return std::string(c_str, len);
}

Thing* getThing(lua_State* L, int32_t arg)
{
	Thing* thing;
	if (lua_getmetatable(L, arg) != 0) {
		lua_rawgeti(L, -1, 't');
		switch(getNumber<uint32_t>(L, -1)) {
			case LuaData_Item:
				thing = getUserdata<Item>(L, arg);
				break;
			case LuaData_Container:
				thing = getUserdata<Container>(L, arg);
				break;
			case LuaData_Teleport:
				thing = getUserdata<Teleport>(L, arg);
				break;
			case LuaData_Player:
				thing = getUserdata<Player>(L, arg);
				break;
			case LuaData_Monster:
				thing = getUserdata<Monster>(L, arg);
				break;
			case LuaData_Npc:
				thing = getUserdata<Npc>(L, arg);
				break;
			default:
				thing = nullptr;
				break;
		}
		lua_pop(L, 2);
	} else {
		thing = LuaScriptInterface::getScriptEnv()->getThingByUID(getNumber<uint32_t>(L, arg));
	}
	return thing;
}

LuaVariant getVariant(lua_State* L, int32_t arg)
{
	LuaVariant var;
	switch (var.type = getField<LuaVariantType_t>(L, arg, "type")) {
		case VARIANT_NUMBER: {
			var.number = getField<uint32_t>(L, arg, "number");
			lua_pop(L, 2);
			break;
		}

		case VARIANT_STRING: {
			var.text = getFieldString(L, arg, "string");
			lua_pop(L, 2);
			break;
		}

		case VARIANT_POSITION:
		case VARIANT_TARGETPOSITION: {
			lua_getfield(L, arg, "pos");
			var.pos = getPosition(L, lua_gettop(L));
			lua_pop(L, 2);
			break;
		}

		default: {
			var.type = VARIANT_NONE;
			lua_pop(L, 1);
			break;
		}
	}
	return var;
}

std::string getFieldString(lua_State* L, int32_t arg, const std::string& key)
{
	lua_getfield(L, arg, key.c_str());
	return getString(L, -1);
}

LuaDataType getUserdataType(lua_State* L, int32_t arg)
{
	if (lua_getmetatable(L, arg) == 0) {
		return LuaData_Unknown;
	}
	lua_rawgeti(L, -1, 't');

	LuaDataType type = getNumber<LuaDataType>(L, -1);
	lua_pop(L, 2);

	return type;
}

bool isBoolean(lua_State* L, int32_t arg)
{
	return lua_isboolean(L, arg);
}

bool isFunction(lua_State* L, int32_t arg)
{
	return lua_isfunction(L, arg);
}

bool isNumber(lua_State* L, int32_t arg)
{
	return lua_type(L, arg) == LUA_TNUMBER;
}

bool isString(lua_State* L, int32_t arg)
{
	return lua_isstring(L, arg) != 0;
}

bool isTable(lua_State* L, int32_t arg)
{
	return lua_istable(L, arg);
}

bool isUserdata(lua_State* L, int32_t arg)
{
	return lua_isuserdata(L, arg) != 0;
}

void pushBoolean(lua_State* L, bool value)
{
	lua_pushboolean(L, value ? 1 : 0);
}

void pushCallback(lua_State* L, int32_t callback)
{
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback);
}

void pushCylinder(lua_State* L, Cylinder* cylinder)
{
	if (Creature* creature = cylinder->getCreature()) {
		pushUserdata<Creature>(L, creature);
		setCreatureMetatable(L, -1, creature);
	} else if (Item* parentItem = cylinder->getItem()) {
		pushUserdata<Item>(L, parentItem);
		setItemMetatable(L, -1, parentItem);
	} else if (Tile* tile = cylinder->getTile()) {
		pushUserdata<Tile>(L, tile);
		setMetatable(L, -1, "Tile");
	} else if (cylinder == VirtualCylinder::virtualCylinder) {
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
}

void pushInstantSpell(lua_State* L, const InstantSpell& spell)
{
	lua_createtable(L, 0, 6);

	setField(L, "name", spell.getName());
	setField(L, "words", spell.getWords());
	setField(L, "level", spell.getLevel());
	setField(L, "mlevel", spell.getMagicLevel());
	setField(L, "mana", spell.getMana());
	setField(L, "manapercent", spell.getManaPercent());

	setMetatable(L, -1, "Spell");
}

void pushOutfit(lua_State* L, const Outfit_t& outfit)
{
	lua_createtable(L, 0, 8);
	setField(L, "lookType", outfit.lookType);
	setField(L, "lookTypeEx", outfit.lookTypeEx);
	setField(L, "lookHead", outfit.lookHead);
	setField(L, "lookBody", outfit.lookBody);
	setField(L, "lookLegs", outfit.lookLegs);
	setField(L, "lookFeet", outfit.lookFeet);
	setField(L, "lookAddons", outfit.lookAddons);
	setField(L, "lookMount", outfit.lookMount);
}

void pushPosition(lua_State* L, const Position& position, int32_t stackpos/* = 0*/)
{
	lua_createtable(L, 0, 4);

	setField(L, "x", position.x);
	setField(L, "y", position.y);
	setField(L, "z", position.z);
	setField(L, "stackpos", stackpos);

	setMetatable(L, -1, "Position");
}

void pushString(lua_State* L, const std::string& value)
{
	lua_pushlstring(L, value.c_str(), value.length());
}

void pushThing(lua_State* L, Thing* thing)
{
	if (!thing) {
		lua_createtable(L, 0, 4);
		setField(L, "uid", 0);
		setField(L, "itemid", 0);
		setField(L, "actionid", 0);
		setField(L, "type", 0);
		return;
	}

	if (Item* item = thing->getItem()) {
		pushUserdata<Item>(L, item);
		setItemMetatable(L, -1, item);
	} else if (Creature* creature = thing->getCreature()) {
		pushUserdata<Creature>(L, creature);
		setCreatureMetatable(L, -1, creature);
	} else {
		lua_pushnil(L);
	}
}

void pushVariant(lua_State* L, const LuaVariant& var)
{
	lua_createtable(L, 0, 2);
	setField(L, "type", var.type);
	switch (var.type) {
		case VARIANT_NUMBER:
			setField(L, "number", var.number);
			break;
		case VARIANT_STRING:
			setField(L, "string", var.text);
			break;
		case VARIANT_TARGETPOSITION:
		case VARIANT_POSITION: {
			pushPosition(L, var.pos);
			lua_setfield(L, -2, "pos");
			break;
		}
		default:
			break;
	}
	setMetatable(L, -1, "Variant");
}

std::string popString(lua_State* L)
{
	if (lua_gettop(L) == 0) {
		return std::string();
	}

	std::string str(getString(L, -1));
	lua_pop(L, 1);
	return str;
}

int32_t popCallback(lua_State* L)
{
	return luaL_ref(L, LUA_REGISTRYINDEX);
}

void setField(lua_State* L, const char* index, lua_Number value)
{
	lua_pushnumber(L, value);
	lua_setfield(L, -2, index);
}

void setField(lua_State* L, const char* index, const std::string& value)
{
	pushString(L, value);
	lua_setfield(L, -2, index);
}

void setMetatable(lua_State* L, int32_t index, const std::string& name)
{
	luaL_getmetatable(L, name.c_str());
	lua_setmetatable(L, index - 1);
}

void setWeakMetatable(lua_State* L, int32_t index, const std::string& name)
{
	static std::set<std::string> weakObjectTypes;
	const std::string& weakName = name + "_weak";

	auto result = weakObjectTypes.emplace(name);
	if (result.second) {
		luaL_getmetatable(L, name.c_str());
		int childMetatable = lua_gettop(L);

		luaL_newmetatable(L, weakName.c_str());
		int metatable = lua_gettop(L);

		static const std::vector<std::string> methodKeys = {"__index", "__metatable", "__eq"};
		for (const std::string& metaKey : methodKeys) {
			lua_getfield(L, childMetatable, metaKey.c_str());
			lua_setfield(L, metatable, metaKey.c_str());
		}

		static const std::vector<int> methodIndexes = {'h', 'p', 't'};
		for (int metaIndex : methodIndexes) {
			lua_rawgeti(L, childMetatable, metaIndex);
			lua_rawseti(L, metatable, metaIndex);
		}

		lua_pushnil(L);
		lua_setfield(L, metatable, "__gc");

		lua_remove(L, childMetatable);
	} else {
		luaL_getmetatable(L, weakName.c_str());
	}
	lua_setmetatable(L, index - 1);
}

void setCreatureMetatable(lua_State* L, int32_t index, const Creature* creature)
{
	if (creature->getPlayer()) {
		luaL_getmetatable(L, "Player");
	} else if (creature->getMonster()) {
		luaL_getmetatable(L, "Monster");
	} else {
		luaL_getmetatable(L, "Npc");
	}
	lua_setmetatable(L, index - 1);
}

void setItemMetatable(lua_State* L, int32_t index, const Item* item)
{
	if (item->getContainer()) {
		luaL_getmetatable(L, "Container");
	} else if (item->getTeleport()) {
		luaL_getmetatable(L, "Teleport");
	} else {
		luaL_getmetatable(L, "Item");
	}
	lua_setmetatable(L, index - 1);
}

std::string getErrorDesc(ErrorCode_t code)
{
	switch (code) {
		case LUA_ERROR_PLAYER_NOT_FOUND: return "Player not found";
		case LUA_ERROR_CREATURE_NOT_FOUND: return "Creature not found";
		case LUA_ERROR_ITEM_NOT_FOUND: return "Item not found";
		case LUA_ERROR_THING_NOT_FOUND: return "Thing not found";
		case LUA_ERROR_TILE_NOT_FOUND: return "Tile not found";
		case LUA_ERROR_HOUSE_NOT_FOUND: return "House not found";
		case LUA_ERROR_COMBAT_NOT_FOUND: return "Combat not found";
		case LUA_ERROR_CONDITION_NOT_FOUND: return "Condition not found";
		case LUA_ERROR_AREA_NOT_FOUND: return "Area not found";
		case LUA_ERROR_CONTAINER_NOT_FOUND: return "Container not found";
		case LUA_ERROR_VARIANT_NOT_FOUND: return "Variant not found";
		case LUA_ERROR_VARIANT_UNKNOWN: return "Unknown variant type";
		case LUA_ERROR_SPELL_NOT_FOUND: return "Spell not found";
		default: return "Bad error code";
	}
}

void reportError(const char* function, const std::string& error_desc, bool stack_trace/* = false*/)
{
	int32_t scriptId;
	int32_t callbackId;
	bool timerEvent;
	LuaScriptInterface* scriptInterface;
	LuaScriptInterface::getScriptEnv()->getEventInfo(scriptId, scriptInterface, callbackId, timerEvent);

	std::cout << std::endl << "Lua Script Error: ";

	if (scriptInterface) {
		std::cout << '[' << scriptInterface->getInterfaceName() << "] " << std::endl;

		if (timerEvent) {
			std::cout << "in a timer event called from: " << std::endl;
		}

		if (callbackId) {
			std::cout << "in callback: " << scriptInterface->getFileById(callbackId) << std::endl;
		}

		std::cout << scriptInterface->getFileById(scriptId) << std::endl;
	}

	if (function) {
		std::cout << function << "(). ";
	}

	if (stack_trace && scriptInterface) {
		std::cout << scriptInterface->getStackTrace(error_desc) << std::endl;
	} else {
		std::cout << error_desc << std::endl;
	}
}
