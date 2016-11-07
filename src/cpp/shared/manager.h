#ifndef TIED_MANAGER_H
#define TIED_MANAGER_H

#include "msg.h"

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
};

enum MANAGER_RETURN_CODE
{
  MANAGER_SUCCESS = 0,
  MANAGER_FINISHED = 2,
  MANAGER_FAILED = 3,
};

#pragma pack(pop)

#endif