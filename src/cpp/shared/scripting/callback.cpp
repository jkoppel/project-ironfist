#include "scripting/callback.h"

void ironfist_lua_push(int arg) {
  lua_pushinteger(map_lua, arg);
}

void ironfist_lua_push(bool arg) {
  lua_pushboolean(map_lua, arg);
}

void ironfist_lua_push(std::string arg) {
  lua_pushstring(map_lua, arg.c_str());
}

void ScriptCallback(const char * funcName) {
  lua_getglobal(map_lua, funcName);
  lua_pcall(map_lua, 0, 0, 0);
}