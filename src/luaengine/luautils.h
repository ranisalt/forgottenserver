#ifndef TFS_LUAUTILS_H
#define TFS_LUAUTILS_H

#include "luascript.h"
#include "../position.h"

struct LuaVariant {
	LuaVariantType_t type = VARIANT_NONE;
	std::string text;
	Position pos;
	uint32_t number = 0;
};

void reportError(const char* function, const std::string& error_desc, bool stack_trace = false);

#define reportErrorFunc(a)  reportError(__FUNCTION__, a, true)

#endif //TFS_LUAUTILS_H
