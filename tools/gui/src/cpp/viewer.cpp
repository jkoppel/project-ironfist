
#include<stdio.h>
#include<stdlib.h>

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

class mouseManager
{
public:

  float vtable;
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;
  bitmap *bitmap;
  int spriteIdx;
  icon *cursorIcon;
  int cursorCategory;
  int cursorIdx;
  int field_4A;
  int field_4E;
  int field_52;
  int field_56;
  int field_5A;
  int cursorTopLeftX;
  int cursorTopLeftY;
  int field_66;
  int field_6A;
  int field_6E;
  int field_72;
  int cursorWidth;
  int cursorHeight;
  int field_7E;
  int couldBeShowMouse;
  int cursorDisabled;
  void SetPointer(char*,int, int);
  void SetColorMice(int);
  void ShowColorPointer();
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

extern executive* gpExec;
extern palette* gPalette;
extern font* smallFont;
extern font* bigFont;
extern resourceManager* gpResourceManager;
extern mouseManager* gpMouseManager;
extern soundManager* gpSoundManager;

extern heroWindowManager* gpWindowManager;

struct MainWindow
{
  unsigned int showMenu;
  signed int x;
  signed int y;
  unsigned int width;
  unsigned int height;
  unsigned int fullScreen;
  unsigned int colorMouseCursor;
};


extern void __fastcall SetPalette(signed char *a1, int a2);

extern MainWindow bMenu[2];
extern int giCurExe;

void finish_init() {
  gpExec->InitSystem();
  gPalette = gpResourceManager->GetPalette("kb.pal");
  smallFont = gpResourceManager->GetFont("smalfont.fnt");
  bigFont = gpResourceManager->GetFont("bigfont.fnt");
  gpMouseManager->SetPointer("advmice.mse", 0, -999);
  gpMouseManager->SetColorMice(bMenu[giCurExe].colorMouseCursor);
  gpMouseManager->ShowColorPointer();

  ((int (__fastcall *)(soundManager *,int,int))gpSoundManager->vtable->Open)(gpSoundManager,0,0);

  SetPalette((signed char*)gPalette->contents, 1);
}

extern int __fastcall NullHandler(tag_message &);
extern int __fastcall EventWindowHandler(tag_message &);


void run_viewer() {
  finish_init();

  char buf[100];
  printf("Name a bin file: \n");
  scanf("%s", buf);

  heroWindow *wind = new heroWindow(0,0,buf);
  
  for(widget* w = wind->firstWidget; w != NULL; w = w->nextInLinkedList) {
	  inspect_widget(w);
  }

  gpWindowManager->DoDialog(wind, NullHandler, 0);
  exit(0);
}
