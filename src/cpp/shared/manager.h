#ifndef TIED_MANAGER_H
#define TIED_MANAGER_H

#include "gui/msg.h"

#pragma pack(push,1)

class baseManager
{
public:
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;

  baseManager();

  virtual int Open(int);
  virtual void Close();
  virtual int Main(tag_message&);
};

enum MANAGER_TYPE
{
  MANAGER_TYPE_HERO_WINDOW_MANAGER = 0x20,
  MANAGER_TYPE_RESOURCE_MAMANGER = 0x80,
  MANAGER_TYPE_SWAP_MANAGER = 0x100,
  MANAGER_TYPE_COMBAT_MANAGER = 0x200,
  MANAGER_TYPE_RECRUIT_UNIT = 0x4000,
};

enum MANAGER_RETURN_CODE
{
  MANAGER_SUCCESS = 0,
  MANAGER_FINISHED = 2,
  MANAGER_FAILED = 3,
};

class executive {
public:
  char _[16];
  executive();

  int DoDialog(baseManager *a2);
  int AddManager(baseManager *mgr, int argIdx);
  int AddManager_orig(baseManager *mgr, int argIdx);
};

extern executive* gpExec;

class inputManager {
public:
	char _[2154];
	inputManager();
  tag_message GetEvent();
};

extern inputManager* gpInputManager;

#pragma pack(pop)

#endif