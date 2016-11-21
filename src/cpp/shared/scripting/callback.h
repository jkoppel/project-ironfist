#ifndef SCRIPTING_CALLBACK_H
#define SCRIPTING_CALLBACK_H

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

extern lua_State* map_lua;

void ironfist_lua_push(int arg) {
  lua_pushinteger(map_lua, arg);
}

void ironfist_lua_push(bool arg) {
  lua_pushboolean(map_lua, arg);
}

void ironfist_lua_push(std::string arg) {
  lua_pushstring(map_lua, arg.c_str());
}

template<typename... Args, typename T>
void ScriptCallback(const char * funcName, T first, Args... args) {
  lua_getglobal(map_lua, funcName);
  ironfist_lua_push(first);
  ironfist_lua_push(args...);
  int size = 1 + sizeof...(Args);
  lua_pcall(map_lua, size, 0, 0);
}

template<typename T>
void ScriptCallback(const char * funcName, T first) {
  lua_getglobal(map_lua, funcName);
  ironfist_lua_push(first);
  lua_pcall(map_lua, 1, 0, 0);
}

void ScriptCallback(const char * funcName) {
  lua_getglobal(map_lua, funcName);
  lua_pcall(map_lua, 0, 0, 0);
}

#endif