#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>

typedef std::map<const char*, std::pair<const char*, const char*>> luaTable;

struct mapVariable {
	const char* luaType;
	union {
		const char* singleValue;
		luaTable tableValue;
	};
};

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();


std::map<const char*, mapVariable> GetMapVariables();

void SetMapVariable(const char*, const char*);
void SetMapVariableTable(const char*, std::map<const char*, const char*>);

#endif