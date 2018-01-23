#pragma once

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

void lua_setconst(lua_State *L, const char* nam, int i);
void DisplayLuaError(lua_State *L);
int LuaGlobalExists(lua_State *L, const char* nam);