#ifndef LUA_UTILS_H
#define LUA_UTILS_H

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

void lua_setconst(lua_State *L, const char* nam, int i);
void lua_setconst_nil(lua_State *L, const char* nam);
void DisplayLuaError(lua_State *L);
int LuaGlobalExists(lua_State *L, const char* nam);

#endif