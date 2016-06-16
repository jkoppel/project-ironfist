#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>
#include <list>

enum MapVarType {MAPVAR_TYPE_STRING, MAPVAR_TYPE_NUMBER, MAPVAR_TYPE_TABLE, MAPVAR_TYPE_BOOLEAN, MAPVAR_TYPE_ERROR};

typedef std::map<std::string, mapVariable> luaTable;

extern std::string MAPVARS_TABLE_ROOT;

struct mapVariable {
	MapVarType type;
	std::string singleValue;
	luaTable tableValue;
};

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();

bool isTable(MapVarType);
bool isStringNumBool(MapVarType);

MapVarType StringToMapVarType(std::string);

std::map <std::string , mapVariable > GetMapVariables();

void SetMapVariables(std::map<std::string, mapVariable>);

void ErrorLoadingMapVariable(std::string&, const std::string&);

#endif