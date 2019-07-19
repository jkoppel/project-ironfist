extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "gui/dialog.h"
#include "scripting/lua_utils.h"

void lua_setconst(lua_State *L, const char* nam, int i) {
	lua_pushinteger(L, i);
	lua_setglobal(L, nam);
}

void lua_setconst_nil(lua_State *L, const char* nam) {
	lua_pushnil(L);
	lua_setglobal(L, nam);
}

void DisplayCustomLuaError(lua_State *L, const char* msg) {
  DisplayError(msg, "Script Error");
  lua_pop(L, 1);
}

void DisplayCustomLuaError(lua_State *L, std::string msg) {
  DisplayCustomLuaError(L, msg.c_str());
}

void DisplayLuaError(lua_State *L) {
  const char* msg = luaL_checkstring(L, -1);
  DisplayCustomLuaError(L, msg);
}

int LuaGlobalExists(lua_State *L, const char* nam) {
  int t = lua_getglobal(L, nam);
  lua_pop(L, 1);
  return t != LUA_TNIL;
}

// Uses the Lua stack size to get the number of returned arguments
// Thanks to https://stackoverflow.com/questions/50920640/dynamically-find-out-the-number-of-return-values-of-lua-function for suggesting
// this approach
int lua_pcall_nresult(lua_State *L, int nargs, int *nres) {
  const int stack_size = lua_gettop(L);

  const int res_code = lua_pcall(L, nargs, LUA_MULTRET, 0);

  const int stack_size_before_call = stack_size - nargs - 1;
  const int num_returns = lua_gettop(L) - stack_size_before_call;
  *nres = num_returns;

  return res_code;
}