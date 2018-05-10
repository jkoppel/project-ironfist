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

void DisplayLuaError(lua_State *L) {
  const char* msg = luaL_checkstring(L, -1);
  DisplayError(msg, "Script Error");
}

int LuaGlobalExists(lua_State *L, const char* nam) {
  int t = lua_getglobal(L, nam);
  lua_pop(L, 1);
  return t != LUA_TNIL;
}