extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "combat/army.h"
#include "scripting/deepbinding.h"
#include "town/town.h"

static void make_deepbound_object(lua_State *L, int ptrAddr, std::string metatable_name) {
  lua_newtable(L);
  lua_pushstring(L, "ptr");
  lua_pushinteger(L, ptrAddr);
  lua_settable(L, -3);
  lua_getglobal(L, metatable_name.c_str());
  lua_setmetatable(L, -2);
}


void deepbound_push(lua_State *L, deepbind<army*> ptrAddr) {
  make_deepbound_object(L, (int)ptrAddr.get(), "battleStack_mt");
}

void deepbound_push(lua_State *L, deepbind<hero*> ptrAddr) {
  make_deepbound_object(L, (int)ptrAddr.get(), "hero_mt");
}

void deepbound_push(lua_State *L, deepbind<playerData*> ptrAddr) {
  make_deepbound_object(L, (int)ptrAddr.get(), "player_mt");
}

void deepbound_push(lua_State *L, deepbind<town*> ptrAddr) {
  make_deepbound_object(L, (int)ptrAddr.get(), "town_mt");
}

void deepbound_push(lua_State *L, deepbind<SCampaignChoice*> ptrAddr) {
  make_deepbound_object(L, (int)ptrAddr.get(), "campaignChoice_mt");
}

void* GetPointerFromLuaClassTable(lua_State *L, int stackIndex) {
  lua_pushstring(L, "ptr");
  lua_gettable(L, -1 - stackIndex);
  void* ret = (void*)(int)lua_tonumber(L, -1);
  lua_pop(L, 1);
  return ret;
}