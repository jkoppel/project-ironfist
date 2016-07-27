#ifndef SCRIPTING_H
#define SCRIPTING_H

void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

void DisplayError();

void GetNextMapVariable(int &, const char *&, const char *&);
void SetMapVariables(const char*, const char*);

#endif