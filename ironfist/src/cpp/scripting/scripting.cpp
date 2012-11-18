#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

#include<map>
#include<string>
#include<utility>

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "adventure/adv.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "town/town.h"

#include "scripting/hook.h"
#include "scripting/scripting.h"

using namespace std;

lua_State* map_lua = NULL;
map<pair<int, string>, const char* > *triggers;

void SetHook(int id, const char* obj, const char* hook) {
	(*triggers)[make_pair(id, string(obj))] = hook;
}

const char* GetHook(int id, const char* obj) {
	if(triggers->count(make_pair(id, obj)) > 0)
		return (*triggers)[make_pair(id, string(obj))];
	else
		return NULL;
}

void ScriptSignal(int id, const char* obj) {
	const char* hook = GetHook(id, obj);
	
	if(hook != NULL) {
		lua_getglobal(map_lua, hook);
		lua_call(map_lua,  0, 0);
	}
}

int l_msgbox(lua_State *L) {
	const char* msg = luaL_checkstring(L, 1);
	H2MessageBox((char*)msg);
	return 0;
}

int l_trigger(lua_State *L) {
	int id = (int)luaL_checknumber(L, 1);
	const char* obj = luaL_checkstring(L, 2);
	const char* hook = luaL_checkstring(L, 3);
	SetHook(id, obj, hook);
	return 0;
}

int l_getday(lua_State *L) {
	lua_pushinteger(L, gpGame->day);
	return 1;
}

int l_getweek(lua_State *L) {
	lua_pushinteger(L, gpGame->week);
	return 1;
}

int l_getmonth(lua_State *L) {
	lua_pushinteger(L, gpGame->month);
	return 1;
}

int l_getcurrenthero(lua_State *L) {
	lua_pushlightuserdata(L, GetCurrentHero());
	return 1;
}

int l_grantspell(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int sp = (int)luaL_checknumber(L, 2);
	hro->AddSpell(sp);
	return 0;
}

int l_getplayer(lua_State *L) {
	int n = (int)luaL_checknumber(L, 1);
	lua_pushlightuserdata(L, &gpGame->players[n]);
	return 1;
}

int l_getnumheroes(lua_State *L) {
	playerData* p = (playerData*)lua_touserdata(L, 1);
	lua_pushinteger(L, p->numHeroes);
	return 1;
}

int l_gethero(lua_State *L) {
	playerData* p = (playerData*)lua_touserdata(L, 1);
	int n = (int)luaL_checknumber(L, 2);
	lua_pushlightuserdata(L, &gpGame->heroes[p->heroesOwned[n]]);
	return 1;
}

int l_grantartifact(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int art = (int)luaL_checknumber(L, 2);
	GiveArtifact(hro, art, 1, -1);
	return 0;
}

int l_hasartifact(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int art = (int)luaL_checknumber(L, 2);
	lua_pushboolean(L, hro->HasArtifact(art));
	return 1;
}

int l_grantarmy(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int cr = (int)luaL_checknumber(L, 2);
	int n = (int)luaL_checknumber(L, 3);
	hro->army.Add(cr, n, -1);
	return 0;
}

int l_getcurrenttown(lua_State *L) {
	lua_pushlightuserdata(L, gpTownManager->castle);
	return 1;
}

int l_setnumguildspells(lua_State *L) {
	town* twn = (town*)lua_touserdata(L, 1);
	int l = (int)luaL_checknumber(L, 2);
	int n = (int)luaL_checknumber(L, 3);
	twn->SetNumSpellsOfLevel(l, n);
	return 0;
}

int l_buildincurrenttown(lua_State *L) {
	int obj = (int)luaL_checknumber(L, 1);
	gpTownManager->BuildObj(obj);
	return 0;
}

void lua_setconst(lua_State *L, const char* nam, int i) {
	lua_pushinteger(L, i);
	lua_setglobal(L, nam);
}

void set_lua_globals(lua_State *L) {
	lua_register(L, "MessageBox", l_msgbox);
	lua_register(L, "Trigger", l_trigger);
	lua_register(L, "GetDay", l_getday);
	lua_register(L, "GetWeek", l_getweek);
	lua_register(L, "GetMonth", l_getmonth);
	lua_register(L, "GetCurrentHero", l_getcurrenthero);
	lua_register(L, "GrantSpell", l_grantspell);
	lua_register(L, "GetPlayer", l_getplayer);
	lua_register(L, "GetNumHeroes", l_getnumheroes);
	lua_register(L, "GetHero", l_gethero);
	lua_register(L, "GrantArtifact", l_grantartifact);
	lua_register(L, "GrantArmy", l_grantarmy);
	lua_register(L, "HasArtifact", l_hasartifact);
	lua_register(L, "GetCurrentTown", l_getcurrenttown);
	lua_register(L, "BuildInCurrentTown", l_buildincurrenttown);
	lua_register(L, "SetNumGuildSpells", l_setnumguildspells);

	lua_setconst(L, "NEW_DAY", SCRIPT_EVT_NEW_DAY);
	lua_setconst(L, "MAP_START", SCRIPT_EVT_MAP_START);
	lua_setconst(L, "TOWN_LOADED", SCRIPT_EVT_TOWN_LOADED);
}

void ScriptingInit(char* map_filnam) {
	ScriptingShutdown();

	int size = _scprintf(".\\SCRIPTS\\%s.lua", map_filnam)+1; //+1 for null
	char* script_file = (char*)malloc(sizeof(char)*size);
	sprintf_s(script_file, size, ".\\SCRIPTS\\%s.lua", map_filnam);

	struct stat st;

	if(stat(script_file, &st) == 0) { //script exists
		map_lua = luaL_newstate();
		triggers = new map<pair<int, string>, const char* >;

		luaL_openlibs(map_lua);

		set_lua_globals(map_lua);

		luaL_dofile(map_lua, script_file);
	}

	free(script_file);
}

void ScriptingShutdown() {
	if(map_lua != NULL) {
		lua_close(map_lua);
		map_lua = NULL;
		delete triggers;
	}
}