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

#include "game/game.h"
#include "gui/dialog.h"

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

void lua_setint(lua_State *L, const char* nam, int i) {
	lua_pushinteger(L, i);
	lua_setglobal(L, nam);
}

void set_lua_globals(lua_State *L) {
	lua_register(L, "MessageBox", l_msgbox);
	lua_register(L, "Trigger", l_trigger);
	lua_register(L, "GetDay", l_getday);

	lua_setint(L, "NEW_DAY", SCRIPT_EVT_NEW_DAY);
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