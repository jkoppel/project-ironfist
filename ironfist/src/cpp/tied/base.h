/*
 * Various low-level things used by Heroes II
 * all over the codebase, for better or for worse
 */

#ifndef TIED_BASE_H
#define TIED_BASE_H

extern void __fastcall BaseFree(void *,char *,int);
extern void * __fastcall BaseAlloc(unsigned int,char *,int);

#define FREE(x) (BaseFree((x), __FILE__, __LINE__))
#define ALLOC(x) (BaseAlloc((x), __FILE__, __LINE__))


extern void __fastcall ProcessAssert(int,char *,int);

#define ASSERT(x) (ProcessAssert((x), __FILE__, __LINE__))

extern void __fastcall ShutDown(char *);

extern char gText[];
extern void __fastcall LogStr(char *);

extern "C" void __fastcall PollSound();

#endif