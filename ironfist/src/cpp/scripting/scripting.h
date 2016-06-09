#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>

typedef std::map<const char*, std::pair<const char*, std::string>> luaTable;

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

std::map<const char*, mapVariable> GetMapVariables();

void SetMapVariables(std::map<const char*, mapVariable>);

#endif