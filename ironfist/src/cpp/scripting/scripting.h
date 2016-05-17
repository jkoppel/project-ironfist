#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <map>

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();

bool GetNextMapVariable(int &, const char *&, bool &);

const char* GetMapVariableValue(const char *&);
std::map<const char*, const char*> GetMapVariableValueTable(const char *&);

void SetMapVariable(const char*, const char*);
void SetMapVariableTable(const char*, std::map<const char*, const char*>);

#endif