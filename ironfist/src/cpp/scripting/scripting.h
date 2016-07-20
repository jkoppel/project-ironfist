#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>
#include <list>
#include<string>

enum MapVarType {
  MAPVAR_TYPE_STRING,
  MAPVAR_TYPE_NUMBER,
  MAPVAR_TYPE_TABLE,
  MAPVAR_TYPE_BOOLEAN,
  MAPVAR_TYPE_ERROR
};

typedef std::map<std::string, std::pair<MapVarType, std::string>> luaTableElements;
typedef std::list<std::string> luaSubTables;
typedef std::map<std::string, std::pair<luaTableElements, luaSubTables>> luaTable;

struct mapVariable {
  ~mapVariable() {
    if (type == MAPVAR_TYPE_TABLE) {
      delete tableValue;
    } else {
      delete singleValue;
    }
  }

	MapVarType type;
    union {
      std::string *singleValue; // we treat all non-table values the same
      luaTable *tableValue;
    };
};

void ScriptingInit(std::string&);
void ScriptingInitFromString(std::string&);
void ScriptingShutdown();

std::string& GetScriptContents();

void DisplayError();

bool isTable(MapVarType);
bool isStringNumBool(MapVarType);

MapVarType StringToMapVarType(std::string);

std::map <std::string , mapVariable > LoadMapVariablesFromLUA();

void WriteMapVariablesToLUA(std::map<std::string, mapVariable>);

void ErrorLoadingMapVariable(std::string&, const std::string&);

#endif