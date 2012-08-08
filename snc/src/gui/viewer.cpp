
#include "gui.h"
#include "resource.h"

class baseManager;

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

struct managerVtable
{
  int (__thiscall *Open)(baseManager *, int);
  void (__thiscall *Close)(baseManager *);
  int (__fastcall *Main)(baseManager *, tag_message *);
};

enum MANAGER_TYPE
{
  MANAGER_TYPE_HERO_WINDOW_MANAGER = 0x20,
  MANAGER_TYPE_RESOURCE_MAMANGER = 0x80,
  MANAGER_TYPE_SWAP_MANAGER = 0x100,
  MANAGER_TYPE_COMBAT_MANAGER = 0x200,
};

class executive
{
public:

  baseManager *firstManager;
  baseManager *lastManager;
  baseManager *currentManager;
  _DWORD field_C;
  int InitSystem();
};

struct FileInAGGInfo
{
  int id;
  int off;
  int length;
};

class resourceManager
{
public:

  managerVtable *vtable;
  baseManager *next;
  baseManager *prev;
  MANAGER_TYPE type;
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
  palette * GetPalette( const char * filename);
  font * GetFont( const char * filename);
};

enum MOUSE_CURSOR_CATEGORY
{
  MOUSE_CURSOR_CATEGORY_ADVENTURE = 0x0,
  MOUSE_CURSOR_CATEGORY_COMBAT = 0x1,
  MOUSE_CURSOR_CATEGORY_SPELL = 0x2,
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
  MOUSE_CURSOR_CATEGORY cursorCategory;
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
  void SetPointer( int  spriteIdxArg);
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
  HDIGDRIVER hdidriver;
  int field_3E;
  char _0[22];
  HSAMPLE hsamples[14];
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
extern resourceMAnager* gpResourceManager;
extern mouseManager* gpMouseManager;
extern soundManager* gpSoundManager;

extern heroWindowManager* gpWindowManager;

void finish_init() {
  gpExec->InitSystem();
  gPalette = gpResourceManager->GetPalette("kb.pal");
  smallFont = gpResourceManager->GetFont("smalfont.fnt");
  bigFont = gpResourceManager->GetFont("bigfont.fnt");
  gpMouseManager->setPointer("advmice.mse", 0, -999);

  ((int (__fastcall *)(soundManager *))gpSoundManager->vtable->Open)(gpSoundManager);
}

void run_viewer() {
  finish_init();
}
