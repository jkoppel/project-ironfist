
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "gui.h"
#include "resource.h"
#include "inspect.h"

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

class resourceManager
{
public:

  managerVtable *vtable;
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;
  resource *loadedFileLinkedList;
  int numOpenAGGFiles;
  int curHandleIdx;
  int fileDescriptors[2];
  FileInAGGInfo *aggContentInfo[2];
  int numberOfFilesInAGG[2];
  int isFreeingAllResources;
  int field_5E;
  char resourceToLoad[60];
  int fileID;
  palette * GetPalette( char * filename);
  font * GetFont( char * filename);
};

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

struct SAMPLE2 { int _[2]; };

extern executive* gpExec;
extern resourceManager* gpResourceManager;
extern soundManager* gpSoundManager;


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
