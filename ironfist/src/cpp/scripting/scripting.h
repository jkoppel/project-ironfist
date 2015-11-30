#ifndef SCRIPTING_H
#define SCRIPTING_H

void DisplayError();
void ScriptingInit(char*);
void ScriptingInitFromString(const char*);
void ScriptingShutdown();

char *GetScriptContents();

#endif