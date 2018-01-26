#include "scripting/callback.h"
#include "scripting/lua_utils.h"

void ironfist_lua_push(int arg) {
  lua_pushinteger(map_lua, arg);
}

void ironfist_lua_push(void *arg) {
  lua_pushlightuserdata(map_lua, arg);
}

void ironfist_lua_push(bool arg) {
  lua_pushboolean(map_lua, arg);
}

void ironfist_lua_push(std::string arg) {
  lua_pushstring(map_lua, arg.c_str());
}

void ironfist_lua_pushmulti() {
}