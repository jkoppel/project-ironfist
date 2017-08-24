#include "scripting/callback.h"

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

void ironfist_lua_push(playerData *arg) {
  MakeLuaPlayerTable(map_lua, arg);
}

void ironfist_lua_push(hero *arg) {
  MakeLuaHeroTable(map_lua, arg);
}

void ironfist_lua_push(town *arg) {
  MakeLuaTownTable(map_lua, arg);
}

void ironfist_lua_push(army *arg) {
  MakeLuaBattleStackTable(map_lua, arg);
}

void ironfist_lua_pushmulti() {
};

void ScriptCallback(const char * funcName) {
  lua_getglobal(map_lua, funcName);
  lua_pcall(map_lua, 0, 0, 0);
}