#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

#include<fstream>
#include<map>
#include<sstream>
#include<string>
#include<utility>

extern "C" {
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include "lua/src/lauxlib.h"
}

#include "gui/dialog.h"

#include "scripting/register.h"
#include "scripting/scripting.h"
#include "scripting/temporary_file.h"

using namespace std;

static string script_contents("");

static bool scripting_on = false;
lua_State* map_lua = NULL;

static void DisplayLuaError() {
	const char* msg = luaL_checkstring(map_lua, -1);
	DisplayError(msg, "Script Error");
}

void set_lua_globals(lua_State *L) {
  set_scripting_funcs(L);
  set_scripting_consts(L);
}

static void LoadScriptContents(string &filnam) {
  ifstream in(filnam);
  stringstream buffer;
  buffer << in.rdbuf();
  script_contents = buffer.str();
}

void RunScript(string& script_filename) {
  map_lua = luaL_newstate();
  scripting_on = true;

  luaL_openlibs(map_lua);

  set_lua_globals(map_lua);

  if (luaL_dofile(map_lua, ".\\SCRIPTS\\MODULES\\binding.lua")) {
    DisplayLuaError();
  }

  LoadScriptContents(script_filename);

  if (luaL_dofile(map_lua, script_filename.c_str())) {
    DisplayLuaError();
  }
}

void ScriptingInit(string& map_filnam) {
  ScriptingShutdown();

  string script_file = ".\\SCRIPTS\\" + map_filnam + ".lua";
  struct stat st;

  if (stat(script_file.c_str(), &st) == 0) { //script exists
    RunScript(script_file);
  }
}

void ScriptingInitFromString(string &script) {
  string filename = dumpToTemp(string(script));
  RunScript(filename);
  remove(filename.c_str());
}

void ScriptingShutdown() {
  if (map_lua != NULL) {
    lua_close(map_lua);
    map_lua = NULL;
    scripting_on = false;
  }

  script_contents = "";
}

// Returns "" if none
string& GetScriptContents() {
  return script_contents;
}



/*****************************   Map variables ***********************************************************/

void ErrorMapVariable(std::string& mapVariableId, const std::string& s2, const std::string& addErrorMessage) {
	const std::string s1("MapVariable '");
	const std::string errorMessage = s1 + mapVariableId + s2 + addErrorMessage;
	const std::string errorLabel("mapVariable Error");
	DisplayError(errorMessage, errorLabel);
}

void ErrorSavingMapVariable(std::string& mapVariableId, const std::string& addErrorMessage) {
	const std::string s2("' could not be saved properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

void ErrorLoadingMapVariable(std::string& mapVariableId, const std::string& addErrorMessage) {
	const std::string s2("' could not be loaded properly.");
	ErrorMapVariable(mapVariableId, s2, addErrorMessage);
}

bool isTable(MapVarType type) {
	return (type == MAPVAR_TYPE_TABLE);
}

bool isStringNumBool(MapVarType type) {
	return (type == MAPVAR_TYPE_STRING || type == MAPVAR_TYPE_NUMBER || type == MAPVAR_TYPE_BOOLEAN);
}

MapVarType StringToMapVarType(std::string stringType) {
	if (stringType == "string") {
		return MAPVAR_TYPE_STRING;
	} else if (stringType == "number") {
		return MAPVAR_TYPE_NUMBER;
	} else if (stringType == "boolean") {
		return MAPVAR_TYPE_BOOLEAN;
	} else if (stringType == "table") {
		return MAPVAR_TYPE_TABLE;
	} else {
		return MAPVAR_TYPE_ERROR;
	}
}

static std::string getMVKeyFromLUA() {
	MapVarType type = StringToMapVarType(lua_typename(map_lua, lua_type(map_lua, -2)));
	if (type == MAPVAR_TYPE_STRING) {
		std::string stringValue(lua_tostring(map_lua, -2));
		return stringValue;
	} else if (type == MAPVAR_TYPE_NUMBER) {
		return std::to_string(lua_tonumber(map_lua, -2));
	}
}

static std::string GetMVValueFromLUA(MapVarType &type) {
	if (type == MAPVAR_TYPE_STRING) {
		std::string stringValue(lua_tostring(map_lua, -1));
		return stringValue;
	} else if (type == MAPVAR_TYPE_NUMBER) {
		return std::to_string(lua_tonumber(map_lua, -1));
	} else if (type == MAPVAR_TYPE_BOOLEAN) {
		return std::to_string(lua_toboolean(map_lua, -1));
	}
}

static luaTable *GetMVTablesFromLUA(std::string &mapVariableId) {
	luaTable *lt = new luaTable;
	lua_pushnil(map_lua);
	while (lua_next(map_lua, -2) != 0) {
		std::string key = getMVKeyFromLUA();
		mapVariable *mapVar = new mapVariable;
		MapVarType valueType = StringToMapVarType(lua_typename(map_lua, lua_type(map_lua, -1)));
		mapVar->type = valueType;
		if (isStringNumBool(valueType)) {
			std::string *sV = new std::string(GetMVValueFromLUA(valueType));
			mapVar->singleValue = sV;
			(*lt)[key] = *mapVar;
			lua_pop(map_lua, 1);
		} else if (isTable(valueType)) {
			mapVar->tableValue = GetMVTablesFromLUA(key);
			(*lt)[key] = *mapVar;
		} else {
			ErrorSavingMapVariable(mapVariableId, " Wrong type in the table.");
		}
	}
	lua_pop(map_lua, 1);
	return lt;
}

std::map<std::string, mapVariable> LoadMapVariablesFromLUA() {

	std::map<std::string, mapVariable> mapVariables;

    if (!scripting_on) {
      return mapVariables;
    }

	lua_getglobal(map_lua, "mapVariables");

	if (lua_isnil(map_lua, -1)) return mapVariables;

	lua_pushnil(map_lua);
	while (lua_next(map_lua, -2) != 0) {
		std::string mapVariableId(lua_tostring(map_lua, -1));
		lua_getglobal(map_lua, mapVariableId.c_str());
		MapVarType mapVariableType = StringToMapVarType(lua_typename(map_lua, lua_type(map_lua, -1)));
		mapVariable *mapVar = new mapVariable;
		mapVar->type = mapVariableType;
		if (isTable(mapVariableType)) {
			mapVar->tableValue = GetMVTablesFromLUA(mapVariableId);
		} else if (isStringNumBool(mapVariableType)) {
			std::string *sV = new std::string;
			*sV = GetMVValueFromLUA(mapVariableType);
			mapVar->singleValue = sV;
			lua_pop(map_lua, 1);
		} else {
			ErrorSavingMapVariable(mapVariableId, " A map variable can only be a table, number, string or boolean.");
		}
		lua_pop(map_lua, 1);
		mapVariables[mapVariableId] = *mapVar;
	}
	return mapVariables;
}

static void PushStringNumBoolToLUA(MapVarType type, std::string value) {
	if (type == MAPVAR_TYPE_STRING) {
		lua_pushstring(map_lua, value.c_str());
	} else if (type == MAPVAR_TYPE_NUMBER) {
		lua_pushnumber(map_lua, atof(value.c_str()));
	} else if (type == MAPVAR_TYPE_BOOLEAN) {
		lua_pushboolean(map_lua, atoi(value.c_str()));
	}
}

static void PushTableToLUA(luaTable *lt) {
	lua_newtable(map_lua);
	int top = lua_gettop(map_lua);
	for (luaTable::const_iterator it = (*lt).begin(); it != (*lt).end(); ++it) {
		if (it->second.type == MAPVAR_TYPE_TABLE) {
			lua_pushstring(map_lua, it->first.c_str());
			PushTableToLUA(it->second.tableValue);
			lua_settable(map_lua, top);
		} else {
			lua_pushstring(map_lua, it->first.c_str());
			PushStringNumBoolToLUA(it->second.type, *it->second.singleValue);
			lua_settable(map_lua, top);
		}
	}
}

void WriteMapVariablesToLUA(std::map<std::string, mapVariable> &mapVariables) {
    if (!scripting_on) {
      DisplayError("Warning: Map variables detected in map without a script.", "Ironfist bug detected");
      return;
    }

	for (std::map<std::string, mapVariable>::const_iterator it = mapVariables.begin(); it != mapVariables.end(); ++it) {
		if (isTable(it->second.type)) {
			PushTableToLUA(it->second.tableValue);
			lua_setglobal(map_lua, it->first.c_str());
		} else {
			PushStringNumBoolToLUA(it->second.type, *it->second.singleValue);
			lua_setglobal(map_lua, it->first.c_str());
		}
	}
}
