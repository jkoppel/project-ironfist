/*
 * Various low-level things used by Heroes II
 * all over the codebase, for better or for worse
 */

#ifndef BASE_H
#define BASE_H

#define INTERNAL_WINDOW_WIDTH 640
#define INTERNAL_WINDOW_HEIGHT 480

#define ELEMENTS_IN(x) ((sizeof(x))/(sizeof((x)[0])))

extern void __fastcall BaseFree(void *,char *,int);
extern void * __fastcall BaseAlloc(unsigned int,char *,int);

#define FREE(x) (BaseFree((x), __FILE__, __LINE__))
#define ALLOC(x) (BaseAlloc((x), __FILE__, __LINE__))

extern void __fastcall MemError();

extern void __fastcall ProcessAssert(int,char *,int);

#define ASSERT(x) (ProcessAssert((x), __FILE__, __LINE__))

extern void __fastcall ShutDown(char *);
extern void __fastcall EarlyShutdown(char*, char*);

extern char gText[];
extern void __fastcall LogStr(char *);
extern int glTimers;
extern long __fastcall KBTickCount();
extern float gfCombatSpeedMod[3];
extern int giCombatSpeed;
extern int giMinExtentX;
extern int giMinExtentY;
extern int giMaxExtentX;
extern int giMaxExtentY;
extern void __fastcall DelayTil(int *);
extern void __fastcall DelayMilli(long);
extern signed char gArmyEffected[2][20];
extern int bSecondAttack;
/*
 * Updates sound, graphics if needed.
 *
 * This is called in a lot of really random, low-level places.
 * It's how Heroes II implements concurrency without having real threads.
 */
extern "C" void __fastcall PollSound();

extern int __fastcall Random(int,int);
extern int __fastcall SRandom(int,int);

#endif