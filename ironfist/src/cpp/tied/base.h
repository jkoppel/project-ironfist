/*
 * Various low-level things used by Heroes II
 * all over the codebase, for better or for worse
 */

#ifndef TIED_BASE_H
#define TIED_BASE_H

#define ELEMENTS_IN(x) ((sizeof(x))/(sizeof((x)[0])))

extern void __fastcall BaseFree(void *,char *,int);
extern void * __fastcall BaseAlloc(unsigned int,char *,int);

#define FREE(x) (BaseFree((x), __FILE__, __LINE__))
#define ALLOC(x) (BaseAlloc((x), __FILE__, __LINE__))


extern void __fastcall ProcessAssert(int,char *,int);

#define ASSERT(x) (ProcessAssert((x), __FILE__, __LINE__))

extern void __fastcall NormalDialog(char *,int,int,int,int,int,int,int,int,int);

extern void __fastcall ShutDown(char *);
extern void __fastcall EarlyShutdown(char*, char*);

extern char gText[];
extern void __fastcall LogStr(char *);

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