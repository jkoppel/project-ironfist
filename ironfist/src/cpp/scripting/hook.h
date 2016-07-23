#ifndef SCRIPTING_HOOK_H
#define SCRIPTING_HOOK_H

#include<string>

void ScriptSetSpecialVariableData(const char*, void*);
void ScriptSignal(int, const char*); 
void ScriptSignal(int, const std::string&);

enum SCRIPT_EVENTS {
  SCRIPT_EVT_NEW_DAY,
  SCRIPT_EVT_MAP_START,
  SCRIPT_EVT_TOWN_LOADED,
  SCRIPT_EVT_MOVEHERO,
  SCRIPT_EVT_RECRUIT,
  SCRIPT_EVT_BATTLE_START,
  SCRIPT_EVT_BATTLE_ATTACK_M,
  SCRIPT_EVT_VISIT_CAMPFIRE
};

#endif
