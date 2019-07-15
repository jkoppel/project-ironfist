#ifndef GUI_H
#define GUI_H

#include "manager.h"
#include "resource/resources.h"
#include <string>

#pragma pack(push,1)

class heroWindow;

class widget {
public:
  heroWindow *parentWindow;
  widget *nextInLinkedList;
  widget *prevInLinkedList;
  __int16 fieldID;
  __int16 componentIndex;
  __int16 field_14;
  __int16 flags;
  __int16 offsetX;
  __int16 offsetY;
  __int16 width;
  __int16 height;

  virtual void Draw();
  virtual ~widget();
  virtual int main(tag_message&);
};

class textWidget : public widget {
  char *content;
  font *font;
  __int16 field_28;
  char field_2A;
};

class heroWindow {
public:
  int idx;
  heroWindow *nextWindow;
  heroWindow *prevWindow;
  char filename[20];
  int flags1;
  int flags2;
  int xOffset;
  int yOffset;
  int width;
  int height;
  widget *lastWidget;
  widget *firstWidget;
  bitmap *bitmap;

  heroWindow(int, int, char*);
  int BroadcastMessage(tag_message&);
  void DrawWindow();
};

class heroWindowManager : public baseManager
{
public:
  heroWindow *firstWindow;
  heroWindow *lastWindow;
  heroWindow *topmostWindow;
  heroWindow *nextTopmostWindow;
  bitmap *screenBuffer;
  bitmap *fizzleSource;
  bitmap *field_4E;
  int numScreenshots;
  int field_56;
  int buttonPressedCode;
  int hoveredFieldID;

  heroWindowManager();

  int DoDialog(heroWindow *,int (__fastcall*)(tag_message &),int);
  void UpdateScreenRegion(int, int, int, int);
  void AddWindow(heroWindow*, int, int);
  void RemoveWindow(heroWindow*);
  void SaveFizzleSource(int, int, int, int);
  void FizzleForward(int, int, int, int, int, signed char *, signed char *);

class border {
public:
  void *vtable; //widgetVtable *vtable;
  heroWindow *parentWindow;
  widget *nextInLinkedList;
  int prevInLinkedList;
  short fieldID;
  short field_12;
  short backgroundType;
  short flagsRelatedToShouldDisplayAndPerhapsMouseCode;
  short offsetX;
  short offsetY;
  short width;
  short height;
  bitmap *bitmap;
  icon *icon;
  short color;

  border(short x, short y, short width, short height, short fieldID, short a7, short color, char *filename);
};

extern heroWindowManager* gpWindowManager;

extern class playerData;
struct bankBox
{
  playerData *player;
  short x;
  short y;
  heroWindow *window;

public:
  bankBox(short x, short y, playerData *player) {
    this->player = player;
    this->x = x;
    this->y = y;
    this->window = new heroWindow(this->x, this->y, "bankbox.bin");
    if(!this->window)
      MemError();
    gpWindowManager->AddWindow(this->window, -1, 1);
    this->Update(1);
  }
  void Update(int);
};

extern class armyGroup;
class strip {
  heroWindow *window;
  char _1[24];
  int x;
  int y;
  int field_24;
  int drawBorder;
  void *field_2C[6];
  icon *stripIcon;
  icon *creaturePortraits[5];
  int creatureTypes[5];
  icon *portraitIcon;
  icon *portraitFlagIcon;
  int portraitIconIdx;
  int field_7C;
  armyGroup *army;

public:
  strip(int x, int y, int a4, unsigned long portraitFileID, int portraitIconIdx, armyGroup *armyGrp, int fieldIDStart, int redraw, int a10);
};

enum ICON_GUI_FLAGS
{
  ICON_GUI_VISIBLE = 0x4,
};

enum GENERAL_GUI_FIELD_IDS {
  FIELD_TOP_BANNER = 2,
  BUTTON_CANCEL = 30721,
  BUTTON_OK = 30722,
  BUTTON_YES = 30725,
};

/* These functions provide a simpler API to parts of the old GUI "BroadcastMessage" API */

void GUIAddFlag(heroWindow*, int, int);
void GUIRemoveFlag(heroWindow*, int, int);
void GUISetImgIdx(heroWindow*, int, int);
void GUISetIcon(heroWindow*, int, char*);
void GUISetIcon(heroWindow*, int, std::string&);
void GUISetText(heroWindow*, int, char*);
void GUISetText(heroWindow*, int, std::string&);
void GUIDroplistAdd(heroWindow*, int, char*);
void GUIDroplistAdd(heroWindow*, int, std::string&);
void GUIDroplistClear(heroWindow*, int);

void GUIBroadcastMessage(heroWindow*, int, int, void*);
int GUIGetDropdownSelection(heroWindow*, int);
void GUISetDropdownSelection(heroWindow*, int, int);

void __fastcall QuickViewWait(void);

#pragma pack(pop)

#endif
