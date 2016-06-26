#ifndef SCRIPTING_H
#define SCRIPTING_H

#include<string>

void ScriptingInit(std::string&);
void ScriptingInitFromString(std::string&);
void ScriptingShutdown();

std::string& GetScriptContents();

void DisplayError();

void GetNextMapVariable(int &, const char *&, const char *&);
void SetMapVariables(const char*, const char*);

#endif