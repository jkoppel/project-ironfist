#ifndef SCRIPTING_HOOK_H
#define SCRIPTING_HOOK_H

void ScriptSignal(int, const char*); 

enum SCRIPT_EVENTS {
	SCRIPT_EVT_NEW_DAY,
	SCRIPT_EVT_MAP_START,
	SCRIPT_EVT_TOWN_LOADED,
};

#endif