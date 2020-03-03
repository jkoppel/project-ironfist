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

extern unsigned char giCurWatchPlayerBit;
extern int bShowIt;
const int gTextSize = 300;
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
extern int giWalkingFrom;
extern int giWalkingFrom2;
extern int giWalkingTo;
extern int giWalkingTo2;
extern int giWalkingYMod;
extern int gbComputeExtent;
extern int gbSaveBiggestExtent;
extern int gbReturnAfterComputeExtent;
extern int gbCurrArmyDrawn;
extern int gbLimitToExtent;
extern int gbFullCombatScreenDrawn;
extern int gbEnlargeScreenBlit;
extern unsigned __int8 moatCell[];
extern void __fastcall DelayTil(int *);
extern void __fastcall DelayMilli(long);
extern signed char gArmyEffected[2][20];
extern int bSecondAttack;
extern int giDebugBuildingToBuild;
extern signed char gbThisNetHumanPlayer[];
extern int gbAllBlack;
extern int giDebugLevel;
extern int combatArmyInfoLevel;
extern float gfBattleStat[];
extern int gbNewGameShadowHidden;
extern int gbRemoteOn;
extern char cPlayerNames[6][21];
extern char *cTextReceivedBuffer[];
extern char *cDifficulty[5];
extern char *cMapSize[9];
extern int giWeekType;
extern int giWeekTypeExtra;
enum WEEK_TYPES {
  WEEK_REGULAR,
  WEEK_CREATURE
};
extern int giMonthType;
extern int giMonthTypeExtra;
enum MONTH_TYPES {
  MONTH_REGULAR,
  MONTH_CREATURE,
  MONTH_PLAGUE
};
extern unsigned char bPuzzleDraw[];
extern unsigned char gColorTableRed[];
extern int gbDrawingPuzzle;
extern unsigned char monAnimDrawFrame[];
extern int iCurBottomView;
extern int gbLoadingMonoIcon;
extern "C" int walkSpeed;
extern int giBottomViewOverride;
extern int giCurWatchPlayer;
extern "C" int soundVolume;
extern int bMoveSoundMade;
extern int bSpecialHideCursor;
extern int gbDrawSavedCursor;
extern int EveryOther;
extern int S1cursorDirection;
extern int S1cursorBaseFrame;
extern int S1cursorFrameCount;
extern int S1cursorCycle;
extern int S1cursorTurning;
extern int gbInSetPointer;
extern int gbPutzingWithMouseCtr;
extern int giCurExe;
extern int gbColorMice;
extern signed char iHotSpot[][2];
extern void *cColorBits[];
extern void *cAndBits[];

struct configStruct {
  int data[103];
};

extern configStruct gConfig;

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