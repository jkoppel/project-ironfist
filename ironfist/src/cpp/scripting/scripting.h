#ifndef SCRIPTING_H
#define SCRIPTING_H

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();

bool GetNextMapVariableType(int &, const char *&);
const char* GetNextMapVariableValue(const char *&);
const char* GetNextMapVariableValue(const char *&, bool &);
void SetMapVariables(const char*, const char*);

#endif