#ifndef LUA_UTILS_H
#define LUA_UTILS_H

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

void lua_setconst(lua_State *L, const char* nam, int i);
void lua_setconst_nil(lua_State *L, const char* nam);

void DisplayCustomLuaError(lua_State *L, const char* msg);
void DisplayCustomLuaError(lua_State *L, std::string msg);
void DisplayLuaError(lua_State *L);

int LuaGlobalExists(lua_State *L, const char* nam);
int lua_pcall_nresult(lua_State *L, int nargs, int *nres);

#endif