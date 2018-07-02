#ifndef SCRIPTING_CALLBACK_H
#define SCRIPTING_CALLBACK_H

#include <string>

#include "optional.hpp"

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

/*
 * The implementations use Lua functions like lua_isnumber and lua_tonumber.
 * We need template specialization to implement these.
 */
template <typename Res>
nonstd::optional<Res> PopLuaResult(lua_State *L, int arg);

template <>
nonstd::optional<bool> PopLuaResult(lua_State *L, int arg);

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
  const int size = sizeof...(Args);
  if (lua_pcall(map_lua, size, 0, 0) != LUA_OK) {
    DisplayLuaError(map_lua);
  }
}

/*
 * Note: As of 6/25/2018, if you want a Res other than bool, you'll need to add new implementations
 * of GetLuaResult
 */
template<typename Res, typename... Args>
nonstd::optional<Res> ScriptCallbackResult(const char * funcName, Args... args) {
  if (!map_lua) { // if it's not an ironfist map
    return nonstd::optional<Res>();
  }

  if (!LuaGlobalExists(map_lua, funcName)) {
    return nonstd::optional<Res>();
  }

  lua_getglobal(map_lua, funcName);
  ironfist_lua_pushmulti(args...);
  const int size = sizeof...(Args);
  if (lua_pcall(map_lua, size, 1, 0) != LUA_OK) {
    DisplayLuaError(map_lua);
    return nonstd::optional<Res>();
  }

  return PopLuaResult<Res>(map_lua, -1);
}

#endif