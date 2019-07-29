#include "gui/dialog.h"

#include "scripting/callback.h"
#include "scripting/lua_utils.h"

#include "optional.hpp"

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

void ironfist_lua_push(char *arg) {
  lua_pushstring(map_lua, arg);
}

void ironfist_lua_pushmulti() {
}

template <>
nonstd::optional<bool> PopLuaResult(lua_State *L, int arg) {
  if (lua_isboolean(L, arg)) {
    const bool retVal = (lua_toboolean(L, arg) != 0);
    lua_remove(L, arg);
    return retVal;
  } else {
    DisplayError("Incorrect return value: expected bool; got something else", "Script error");
    return {};
  }
}

template <>
nonstd::optional<std::string> PopLuaResult(lua_State *L, int arg) {
  const char *luaStr = lua_tostring(L, arg);
  if (luaStr) {
    const std::string ret = luaStr;
    lua_remove(L, arg);
    return ret;
  }

  // Tolerate nil but warn if we got some other type.
  if (!lua_isnil(L, arg)) {
    DisplayError("Incorrect return value: expected string; got something else", "Script error");
  }
  return {};
}