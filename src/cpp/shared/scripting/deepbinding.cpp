extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "combat/army.h"
#include "scripting/deepbinding.h"
#include "town/town.h"


void deepbound_push(lua_State *L, deepbind<army*> ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr.get());
  lua_settable(L, -3);
  lua_getglobal(L, "battleStack_mt");
  lua_setmetatable(L, -2);
}

void deepbound_push(lua_State *L, deepbind<hero*> ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr.get());
  lua_settable(L, -3);
  lua_getglobal(L, "hero_mt");
  lua_setmetatable(L, -2);
}

void deepbound_push(lua_State *L, deepbind<playerData*> ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr.get());
  lua_settable(L, -3);
  lua_getglobal(L, "player_mt");
  lua_setmetatable(L, -2);
}

void deepbound_push(lua_State *L, deepbind<town*> ptrAddr) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, (int)ptrAddr.get());
  lua_settable(L, -3);
  lua_getglobal(L, "town_mt");
  lua_setmetatable(L, -2);
}

void* GetPointerFromLuaClassTable(lua_State *L, int stackIndex) {
  lua_pushstring(L, "ptr");
  lua_gettable(L, -1 - stackIndex);
  void* ret = (void*)(int)lua_tonumber(L, -1);
  lua_pop(L, 1);
  return ret;
}