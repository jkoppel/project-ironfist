// pociron.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "pociron.h"

#include "ironfistasm.h"

#include "HEROES2W.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

#include <stdio.h>

//extern "C" void bar(HINSTANCE, HINSTANCE, LPTSTR, int);

extern "C" {
	void CreatureStack__removeEffect(int x);
	void CombatManager__displayCombatMessage(int a, int b, int c, int d);
	void sleep();
	void CombatManager__drawRay(int a[17]);
	void playSample();
	void yieldToGlobalUpdater();
	void CombatManager__animateMultitargetSpellEffect(int a, int b, int c);
	void CreatureStack__takeDamage(int a, int b);
	void CreatureStack__doAttackAndDamageTakenAnimations(int a, int b, int c, int d);
}

void aCreatureStack__doAttackAndDamageTakenAnimations(void* thisa, int a, int b, int c, int d) {
	__asm {
		push d
		push c
		push b
		push a
		mov ecx, thisa
		call CreatureStack__doAttackAndDamageTakenAnimations
	}
}

void aCreatureStack__takeDamage(void* thisa, int a, int b) {
	__asm {
		push b
		push a
		mov ecx, thisa
		call CreatureStack__takeDamage
	}
}

void aCombatManager__animateMultitargetSpellEffect(void* thisa, int a, int b, int c) {
	__asm {
		push c
		push b
		push a
		mov ecx, thisa
		call CombatManager__animateMultitargetSpellEffect
	}
}

void __fastcall aCreatureStack__removeEffect(CreatureStack *thisa, STACK_MODIFYING_EFFECT e) {
	__asm {
		push e
		mov ecx, thisa
		call CreatureStack__removeEffect
	}
}

void aCombatManager__displayCombatMessage(void* thisa, char* buf, int a, int b, int c) {
	__asm {
		push c
		push b
		push a
		push buf
		mov ecx, thisa
		call CombatManager__displayCombatMessage
	}
}

void asleep(int x) {
	__asm {
		mov ecx, x
		call sleep
	}
}

void* aplaySample(char* c) {
	__asm {
		mov ecx, c
		call playSample
	}
}

void drawRay(void *thisa, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17) {
	__asm {
		push a17
		push a16
		push a15
		push a14
		push a13
		push a12
		push a11
		push a10
		push a9
		push a8
		push a7
		push a6
		push a5
		push a4
		push a3
		push a2
		push a1
		mov ecx, thisa
		call CombatManager__drawRay
	}
}



extern "C" void __fastcall CreatureStack__cure(CreatureStack *thisa, int foo, int spellpower)
{
  aCreatureStack__removeEffect(thisa, EFFECT_SLOW);
  aCreatureStack__removeEffect(thisa, EFFECT_BLIND);
  aCreatureStack__removeEffect(thisa, EFFECT_CURSE);
  aCreatureStack__removeEffect(thisa, EFFECT_BERSERKER);
  aCreatureStack__removeEffect(thisa, EFFECT_PARALYZE);
  aCreatureStack__removeEffect(thisa, EFFECT_HYPNOTIZE);
  aCreatureStack__removeEffect(thisa, EFFECT_PETRIFY);
  thisa->damage += 10 * spellpower;
  if ( thisa->damage < 0 )
    thisa->damage = 0;
  asleep(5000);

}

void rayTo(void * mgr, int x, int y) {
	void* res = aplaySample("lightblt.82m");
	drawRay(mgr,
		1, //clear immediately 
		480, -50, //startpos
		x, y, //end pos
		150, 100, // control forking
		11, 3, //start width, end width
		301, //controls colors in some complicated way
		-80, 80, //min and max random path divergence. The path is self correcting.
		30,//diverge frequency
		0, //unused
		1 , 0 , 1); //can't tell
	asleep(400);
	yieldToGlobalUpdater();
}

void bigRay(void *mgr, int x, int y, int clear) {
	drawRay(mgr,
		clear, //clear immediately 
		480, -50, //startpos
		x, y, //end pos
		100, 500, // control forking
		13, 4, //start width, end width
		301, //controls colors in some complicated way
		-80, 80, //min and max random path divergence. The path is self correcting.
		30,//diverge frequency
		0, //unused
		1 , 0 , 1); //can't tell
}

extern "C" void __fastcall CombatManager__lightningStormSequence(char *thisa) {
	asleep(5000);
	aCombatManager__displayCombatMessage(thisa, "The Turris Lucens sends lightning from afar.", 1, 0, 0);
	rayTo(thisa, 70, 100);
	rayTo(thisa, 70, 150);
	rayTo(thisa, 70, 200);
	rayTo(thisa, 70, 250);
	rayTo(thisa, 70, 300);
	rayTo(thisa, 70, 350);
	rayTo(thisa, 70, 400);
	rayTo(thisa, 70, 450);
	asleep(1000);
	
	void* res = aplaySample("chainlte.82m");
	bigRay(thisa, 100, 100, 0);
	bigRay(thisa, 100, 150, 0);
	bigRay(thisa, 100, 200, 0);
	bigRay(thisa, 100, 250, 0);
	bigRay(thisa, 100, 300, 0);
	bigRay(thisa, 100, 350, 0);
	bigRay(thisa, 100, 400, 0);
	bigRay(thisa, 100, 450, 1);

	for(int i = 0; i < 5; i++) {
		void *creat = thisa+0x354F+i*0x482;
		aCreatureStack__takeDamage(creat, 90000, -1);
	}

	char aff[2][20] = {{1,1,1,1,1},{0}};
	aCombatManager__animateMultitargetSpellEffect(thisa, (int)aff, 15, 1);
	
	aCreatureStack__doAttackAndDamageTakenAnimations(thisa+0x354F, -1, 1, -1, -1);
	
	asleep(5000);
}