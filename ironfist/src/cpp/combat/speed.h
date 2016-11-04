#ifndef COMBAT_SPEED_H
#define COMBAT_SPEED_H

void __fastcall DelayTil(int *);
long __fastcall KBTickCount();

extern int glTimers;

extern int giCombatSpeed;
extern float gfCombatSpeedMod[];

#endif