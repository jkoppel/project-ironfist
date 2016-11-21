#ifndef SCRIPTING_CALLBACK_H
#define SCRIPTING_CALLBACK_H

#include <string>

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

void ironfist_lua_push(int arg);
void ironfist_lua_push(bool arg);
void ironfist_lua_push(std::string arg);

extern lua_State* map_lua;

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

void ScriptCallback(const char * funcName);

#endif