#include "artifacts.h"
#include "combat/creatures.h"
#include "scripting/scripting.h"
#include "town/town.h"
#include "windows.h"

extern void* hInstApp;

void IronfistInit() {
  LoadCreatures();
  LoadArtifacts();
  InitializeTownConstants();
  //LoadMenu((HINSTANCE)hInstApp, "MNUADV");
}

extern void __fastcall CleanUpWinGraphics();
extern void __fastcall CleanUpMenus();

void __fastcall AppExit() {
  CleanUpWinGraphics();
  CleanUpMenus();
  UnloadCreatures();
#ifndef EDITOR
  ScriptingShutdown();
#endif
}
