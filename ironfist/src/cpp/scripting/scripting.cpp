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
#include "scripting/register.h"
#include "scripting/scripting.h"

using namespace std;

char *script_contents = NULL;

bool scripting_on = false;
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
	if(!scripting_on)
		return;

	const char* hook = GetHook(id, obj);
	
	if(hook != NULL) {
		lua_getglobal(map_lua, hook);

		if (lua_pcall(map_lua, 0, -1, 0)) {
			DisplayError();
		}
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

int l_getheroforhire(lua_State *L) {
	playerData* p = (playerData*)lua_touserdata(L, 1);
	int n = (int)luaL_checknumber(L, 2);
	lua_pushlightuserdata(L, &gpGame->heroes[p->heroesForPurchase[n]]);
	return 1;
}

int l_getheroinpool(lua_State *L) {
	int n = (int)luaL_checknumber(L, 1);
	lua_pushlightuserdata(L, &gpGame->heroes[n]);
	return 1;
}

int l_getheroname(lua_State *L) {
	hero *hro = (hero*)lua_touserdata(L, 1);
	lua_pushstring(L, hro->name);
	return 1;
}

int l_getheroowner(lua_State *L) {
	hero *hro = (hero*)lua_touserdata(L, 1);
	lua_pushinteger(L, hro->ownerIdx);
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

int l_takeartifact(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int art = (int)luaL_checknumber(L, 2);
	hro->TakeArtifact(art);
	return 0;
}

int l_setprimaryskill(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int skill = (int)luaL_checknumber(L, 2);
	int amt   = (int)luaL_checknumber(L, 3);
	hro->SetPrimarySkill(skill, amt);
	return 0;
}

int l_setspellpoints(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int points = (int)luaL_checknumber(L, 2);
	hro->spellpoints = points;
	return 0;
}

int l_setsecondaryskill(lua_State *L) {
	hero* hro = (hero*)lua_touserdata(L, 1);
	int skill = (int)luaL_checknumber(L, 2);
	int level = (int)luaL_checknumber(L, 3);
	hro->SetSS(skill, level);
	return 0;
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


int l_hasvisitinghero(lua_State *L) {
	town* twn = (town*)lua_touserdata(L, 1);
	lua_pushboolean(L, twn->visitingHeroIdx >= 0);
	return 1;
}

int l_getvisitinghero(lua_State *L) {
	town* twn = (town*)lua_touserdata(L, 1);
	lua_pushlightuserdata(L, &gpGame->heroes[twn->visitingHeroIdx]);
	return 1;
}

int l_buildincurrenttown(lua_State *L) {
	int obj = (int)luaL_checknumber(L, 1);
	gpTownManager->BuildObj(obj);
	return 0;
}

int l_setnumguildspells(lua_State *L) {
	town* twn = (town*)lua_touserdata(L, 1);
	int l = (int)luaL_checknumber(L, 2);
	int n = (int)luaL_checknumber(L, 3);
	twn->SetNumSpellsOfLevel(l, n);
	return 0;
}

int l_setguildspell(lua_State *L) {
	town* twn = (town*)lua_touserdata(L, 1);
	int l = (int)luaL_checknumber(L, 2);
	int n = (int)luaL_checknumber(L, 3);
	int s = (int)luaL_checknumber(L, 4);
	twn->mageGuildSpells[l][n] = s;
	return 0;
}

int l_sharevision(lua_State *L) {
    int sourcePlayer = (int)luaL_checknumber(L, 1);
    int destPlayer = (int)luaL_checknumber(L, 2);
    gpGame->ShareVision(sourcePlayer, destPlayer);
    return 0;
}


void set_lua_globals(lua_State *L) {
	lua_register(L, "MessageBox", l_msgbox);
	lua_register(L, "Trigger", l_trigger);
	lua_register(L, "GetDay", l_getday);
	lua_register(L, "GetWeek", l_getweek);
	lua_register(L, "GetMonth", l_getmonth);
	lua_register(L, "GetCurrentHero", l_getcurrenthero);
	lua_register(L, "GetPlayer", l_getplayer);
	lua_register(L, "GetNumHeroes", l_getnumheroes);
	lua_register(L, "GetHero", l_gethero);
	lua_register(L, "GetHeroForHire", l_getheroforhire);
	lua_register(L, "GetHeroInPool", l_getheroinpool);
	lua_register(L, "GetHeroName", l_getheroname);
	lua_register(L, "GetHeroOwner", l_getheroowner);
	lua_register(L, "GrantArtifact", l_grantartifact);
	lua_register(L, "GrantSpell", l_grantspell);
	lua_register(L, "GrantArmy", l_grantarmy);
	lua_register(L, "HasArtifact", l_hasartifact);
	lua_register(L, "TakeArtifact", l_takeartifact);
	lua_register(L, "SetPrimarySkill", l_setprimaryskill);
	lua_register(L, "SetSpellpoints", l_setspellpoints);
	lua_register(L, "SetSecondarySkill", l_setsecondaryskill);
	lua_register(L, "GetCurrentTown", l_getcurrenttown);
	lua_register(L, "HasVisitingHero", l_hasvisitinghero);
	lua_register(L, "GetVisitingHero", l_getvisitinghero);
	lua_register(L, "BuildInCurrentTown", l_buildincurrenttown);
	lua_register(L, "SetNumGuildSpells", l_setnumguildspells);
	lua_register(L, "SetGuildSpell", l_setguildspell);
    lua_register(L, "ShareVision", l_sharevision);

	lua_setconst(L, "NEW_DAY", SCRIPT_EVT_NEW_DAY);
	lua_setconst(L, "MAP_START", SCRIPT_EVT_MAP_START);
	lua_setconst(L, "TOWN_LOADED", SCRIPT_EVT_TOWN_LOADED);

	set_scripting_consts(L);
}

void RunScript() {
	if (script_contents != NULL) {
		map_lua = luaL_newstate();
		triggers = new map<pair<int, string>, const char* >;
		scripting_on = true;

		luaL_openlibs(map_lua);

		set_lua_globals(map_lua);

		if (luaL_dostring(map_lua, script_contents)) {
			DisplayError();
		}
	}
}

void LoadScript(char* script_filname) {
	if (script_contents != NULL) {
		free(script_contents);
	}

	script_contents = NULL;

	FILE *fil = fopen(script_filname, "r");
	if (fil != NULL) {
		fseek(fil, 0, SEEK_END);
		int length = ftell(fil);
		fseek(fil, 0, SEEK_SET);
		script_contents = (char*)calloc(length + 1, sizeof(char));
		fread(script_contents, sizeof(char), length, fil);
		fclose(fil);
	}
}

void SetScript(const char *script) {
	if (script_contents != NULL) {
		free(script_contents);
	}

	script_contents = strdup(script);
}


void ScriptingInit(char* map_filnam) {
	ScriptingShutdown();

	int size = _scprintf(".\\SCRIPTS\\%s.lua", map_filnam)+1; //+1 for null
	char* script_file = (char*)malloc(sizeof(char)*size);
	sprintf_s(script_file, size, ".\\SCRIPTS\\%s.lua", map_filnam);

	struct stat st;

	if(stat(script_file, &st) == 0) { //script exists
		LoadScript(script_file);
		RunScript();
	}

	free(script_file);
}

void ScriptingInitFromString(const char *script) {
	SetScript(script);
	RunScript();
}

void ScriptingShutdown() {
	if(map_lua != NULL) {
		lua_close(map_lua);
		map_lua = NULL;
		delete triggers;
		scripting_on = false;
	}
	
	if (script_contents != NULL) {
		free(script_contents);
		script_contents = NULL;
	}
}

char *GetScriptContents() {
	return script_contents;
}

void GetNextMapVariable(int &key, const char *&mapVariableId, const char *&mapVariableValue) {
	// PUSH THE MAP VARIABLES LIST TO THE TOP OF THE STACK OR nil IF THERE IS NO LIST
	lua_getglobal(map_lua, "mapVariables");

	// CHECK IF THERE IS INDEED A LIST OF MAP VARIABLES
	if (lua_isnil(map_lua, -1)) {
		mapVariableId = "noMapVariables";
		return;
	}

	// GO TO THE mapVariable INDEXED BY key
	if (key >= 0) {
		lua_pushnumber(map_lua, key);
	}
	else {
		lua_pushnil(map_lua);
	}
	if (lua_next(map_lua, -2)) {
		key = lua_tointeger(map_lua, -2);
		mapVariableId = lua_tostring(map_lua, -1);
		lua_pop(map_lua, 2);
		lua_getglobal(map_lua, mapVariableId);
		mapVariableValue = lua_tostring(map_lua, -1);
	}
	else {
		mapVariableId = "noMapVariables";
	}
}

void SetMapVariables(const char *id, const char *quantity) {
	lua_pushstring(map_lua, quantity);
	lua_setglobal(map_lua, id);
}

void DisplayError() {
	const char* msg = luaL_checkstring(map_lua, -1);
	DisplayError(msg, "Script Error");
}