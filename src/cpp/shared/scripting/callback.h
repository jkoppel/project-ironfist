#ifndef SCRIPTING_CALLBACK_H
#define SCRIPTING_CALLBACK_H

#include <string>

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "scripting/lua_utils.h"

void ironfist_lua_push(int arg);
void ironfist_lua_push(bool arg);
void ironfist_lua_push(void *arg);
void ironfist_lua_push(std::string arg);
void ironfist_lua_pushmulti();

template<typename T, typename... Args>
void ironfist_lua_pushmulti(T first, Args... args) {
  ironfist_lua_push(first);
  ironfist_lua_pushmulti(args...);
}

extern lua_State* map_lua;

template<typename... Args>
void ScriptCallback(const char * funcName, Args... args) {
  if (!map_lua) { // if it's not an ironfist map
    return;
  }

  if (!LuaGlobalExists(map_lua, funcName)) {
    return;
  }

  lua_getglobal(map_lua, funcName);
  ironfist_lua_pushmulti(args...);
  int size = sizeof...(Args);
  if (lua_pcall(map_lua, size, 0, 0) != LUA_OK) {
    DisplayLuaError(map_lua);
  }
}

#endif