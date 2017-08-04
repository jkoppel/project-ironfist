#ifndef SCRIPTING_CALLBACK_H
#define SCRIPTING_CALLBACK_H

#include <string>
#include "combat/army.h"
#include "adventure/adv.h"
#include "game/game.h"
#include "town/town.h"

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

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

template<typename T>
void ironfist_lua_push(T arg) {
	lua_createtable(map_lua, 0, 0);
	lua_pushstring(map_lua, "ptr");
	lua_pushinteger(map_lua, (int)arg);
	lua_settable(map_lua, -3);

	if (typeid(T) == typeid(army*)) {
		lua_getglobal(map_lua, "battleStack_mt");
		lua_setmetatable(map_lua, -2);
	}
	else if (typeid(T) == typeid(hero*)) {
		lua_getglobal(map_lua, "hero_mt");
		lua_setmetatable(map_lua, -2);
	}
	else if (typeid(T) == typeid(playerData*)) {
		lua_getglobal(map_lua, "playerData_mt");
		lua_setmetatable(map_lua, -2);
	}
	else if (typeid(T) == typeid(town*)) {
		lua_getglobal(map_lua, "town_mt");
		lua_setmetatable(map_lua, -2);
	}
}

template<typename... Args>
void ScriptCallback(const char * funcName, Args... args) {
  if (!map_lua) // if it's not an ironfist map
    return;
  lua_getglobal(map_lua, funcName);
  ironfist_lua_pushmulti(args...);
  int size = sizeof...(Args);
  lua_pcall(map_lua, size, 0, 0);
}

#endif