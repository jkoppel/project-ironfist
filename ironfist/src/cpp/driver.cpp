#include "tied/combat/creatures.h"
#include "windows.h"

extern void* hInstApp;

void IronfistInit() {
	LoadCreatures();
	//LoadMenu((HINSTANCE)hInstApp, "MNUADV");
}

extern void __fastcall CleanUpWinGraphics();
extern void __fastcall CleanUpMenus();

void __fastcall AppExit() {
	CleanUpWinGraphics();
	CleanUpMenus();
	UnloadCreatures();
}
