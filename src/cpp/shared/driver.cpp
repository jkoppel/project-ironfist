#include "combat/creatures.h"
#include "scripting/scripting.h"
#include "windows.h"

#include <xercesc/util/PlatformUtils.hpp>

extern void* hInstApp;

void IronfistInit() {
  xercesc::XMLPlatformUtils::Initialize();
	LoadCreatures();
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
  xercesc::XMLPlatformUtils::Terminate();
}
