#ifndef LIFTED_RESOURCEMANAGER_H
#define LIFTED_RESOURCEMANAGER_H

#include <string>

#include "resource/resources.h"
#include "manager.h"
#include "gui/msg.h"

#pragma pack(push, 1)

#define NUM_AGG_FILES 3

extern unsigned long __fastcall MAKEFILEID(char *);

struct AggregateHeader
{
  int id;
  int off;
  int length;
};

class resourceManager : baseManager
{
  //managerVtable *vtable;
  //baseManager *next;
  //baseManager *prev;
  //MANAGER_TYPE type;
  //int idx;
  //char name[30];
  //int ready;
  resource *firstLoadedResource;
  int numOpenAGGFiles;
  int curHandleIdx;
  int fileDescriptors[NUM_AGG_FILES];
  AggregateHeader *aggContentInfo[NUM_AGG_FILES];
  int numberOfFilesInAGG[NUM_AGG_FILES];
  int expunging;
  int field_5E;
  char resourceToLoad[60];
  int fileID;

public:
  resourceManager();
  
  int Open(int);
  void Close();
  int Main(tag_message&);

  void GetBackdrop(char*,bitmap*,int);
  palette* GetPalette(char*);
  bitmap* GetBitmap(char*);
  icon* GetIcon(char*);
  icon* GetIcon(unsigned long);
  tileset* GetTileset(char*);
  font* GetFont(char*);
  sample* GetSample(const std::string &filename);
  sample* GetSample(char*);
  MIDIWrap* GetMIDIWrap(char*);
  void Dispose(resource*);
  void AddResource(resource*);
  void Expunge();
  resource* Query(unsigned long);
  void RemoveResource(resource*);
  int LoadAggregateHeader(char*);
  void PointToFile(unsigned long);
  unsigned long GetFileSize(unsigned long);
  void SavePosition();
  void RestorePosition();
  short ReadWord();
  long ReadLong();
  unsigned long MakeId(char*,int);
  void Read13(signed char*);
  void ReadBlock(signed char*, unsigned long);
};

extern resourceManager* gpResourceManager;

enum MOUSE_CURSOR_CATEGORY {
  MOUSE_CURSOR_CATEGORY_ADVENTURE = 0x0,
  MOUSE_CURSOR_CATEGORY_COMBAT = 0x1,
  MOUSE_CURSOR_CATEGORY_SPELL = 0x2,
};

class mouseManager : baseManager {
public:
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

	mouseManager();
	void ShowColorPointer();
  void SetPointer(int spriteIdxArg);
  void SetPointer(char *mse, int spriteIdx, signed int protoCategory);
};

extern mouseManager* gpMouseManager;

#pragma pack(pop)

#endif