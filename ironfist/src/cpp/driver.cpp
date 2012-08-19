#include "tied/combat/creatures.h"

void IronfistInit() {
	LoadCreatures();
}

extern void __fastcall CleanUpWinGraphics();
extern void __fastcall CleanUpMenus();

void __fastcall AppExit() {
	CleanUpWinGraphics();
	CleanUpMenus();
	UnloadCreatures();
}
