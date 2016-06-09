#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>

typedef std::map<std::string, std::pair<const char*, std::string>> luaTable;

struct mapVariable {
	const char* luaType;
	std::string singleValue;
	luaTable tableValue;
};

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();


bool isTable(const char*);
bool isStringNumBool(const char*);
//bool isTable(std::string);
//bool isStringNumBool(std::string);

std::map <std::string , mapVariable > GetMapVariables();

void SetMapVariables(std::map<std::string, mapVariable>);

#endif