
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "manager.h"
#include "resourceManager.h"
#include "resources.h"

struct tag_message;

struct managerVtable
{
  int (__thiscall *Open)(baseManager *, int);
  void (__thiscall *Close)(baseManager *);
  int (__fastcall *Main)(baseManager *, tag_message *);
};

class executive
{
public:

  baseManager *firstManager;
  baseManager *lastManager;
  baseManager *currentManager;
  int field_C;
  int InitSystem();
};

struct FileInAGGInfo;

class soundManager
{
public:

  managerVtable *vtable;
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;
  int redbookStatus;
  int hdidriver;
  int field_3E;
  char _0[22];
  int hsamples[14];
  int field_90;
  int field_94;
  int numSamplesAllocated;
  char _1[84];
  char _2[1152];
  int field_570;
  int _3;
  int field_578;
  char currentTrack;
  char _4[267];
  int aiMusicOff;
  int volRelated;
  int _5;
  int field_694;
  int field_698;
  __int16 outputDeviceID;
  int field_69E;
  int usingRedbookRelated;
  int field_6A6;
  float field_6AA;
  int someTick;
};

extern executive* gpExec;
extern resourceManager* gpResourceManager;
extern soundManager* gpSoundManager;


// Dummies because it won't assemble if we don't override these
struct SSpellInfo { int _;};
SSpellInfo gsSpellInfo[1];
struct SCmbtHero { int _;};
SCmbtHero sCmbtHero[1];

void finish_init() {
  gpExec->InitSystem();

  ((int (__fastcall *)(soundManager *,int,int))gpSoundManager->vtable->Open)(gpSoundManager,0,0);
}

extern struct SAMPLE2 __fastcall LoadPlaySample(char*);

#define BUF_SIZE 100

void run_viewer() {
  finish_init();

  while (true) {
    char buf[BUF_SIZE];
    printf("Name a sample file: \n");
    scanf_s("%s", buf, BUF_SIZE);

    if (strcmp(buf, "") == 0) {
      break;
    }

    LoadPlaySample(buf);
  }

  exit(0);
}
