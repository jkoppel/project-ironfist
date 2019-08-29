#ifndef DEEPBINDING_H
#define DEEPBINDING_H

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "adventure/adv.h"
#include "campaign/campaign.h"
#include "combat/army.h"
#include "game/game.h"
#include "town/town.h"

template <typename T>
class deepbind {
  T _t;

public:
  deepbind(T t) : _t(t) {}

  T get() { return _t; }
};

void deepbound_push(lua_State *L, deepbind<army*> x);
void deepbound_push(lua_State *L, deepbind<playerData*> x);
void deepbound_push(lua_State *L, deepbind<hero*> x);
void deepbound_push(lua_State *L, deepbind<town*> x);
void deepbound_push(lua_State *L, deepbind<SCampaignChoice*> x);

void* GetPointerFromLuaClassTable(lua_State *L, int stackIndex);

#endif