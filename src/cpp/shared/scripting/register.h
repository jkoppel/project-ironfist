#ifndef SCRIPTING_REGISTER_H
#define SCRIPTING_REIGSTER_H

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

void lua_setconst(lua_State *L, const char* nam, int i);
void set_scripting_consts(lua_State *L);

#endif