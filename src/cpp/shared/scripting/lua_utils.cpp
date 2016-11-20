extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

void lua_setconst(lua_State *L, const char* nam, int i) {
	lua_pushinteger(L, i);
	lua_setglobal(L, nam);
}