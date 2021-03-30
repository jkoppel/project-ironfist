#include "artifacts.h"
#include "campaign/campaign.h"
#include "combat/creatures.h"
#include "scripting/scripting.h"
#include "town/town.h"
#include "windows.h"

extern void* hInstApp;
extern void LoadOverlays();
extern void LoadOverlayNames();

void IronfistInit() {
  LoadCreatures();
  LoadArtifacts();
#ifndef EDITOR
  InitializeTownConstants();
#endif
#ifdef EDITOR
  LoadOverlays();
  LoadOverlayNames();
#endif

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
