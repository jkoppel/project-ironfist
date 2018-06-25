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

void ironfist_lua_pushmulti() {
}

template <>
nonstd::optional<bool> GetLuaResult(lua_State *L, int arg) {
  if (lua_isboolean(L, -1)) {
    return nonstd::optional<bool>(lua_toboolean(L, -1));
  } else {
    DisplayError("Incorrect return value: expected bool; got something else", "Script error");
    return nonstd::optional<bool>();
  }
}