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
  MANAGER_TYPE_ADVMAP_MANAGER = 0x400,
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

struct fileRequester : public baseManager {
  int field_36;
  int field_3A;
  int field_3E;
  int field_42;
  char field_46[300];
  char field_172[300];
  int field_29E;
  int field_2A2;
  int field_2A6;
  int field_2AA;
  char field_2AE[356];
  int field_412;
  int field_416;
  int field_41A;
  int field_41E;
  int field_422;
  int field_426;
  int field_42A;
  char field_42E;
  fileRequester(int a2, int a3, int a4, char *extensionMask, char *folder, char *extension);
};

extern inputManager* gpInputManager;

#pragma pack(pop)

#endif