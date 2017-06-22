
#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H

#pragma pack(push,1)

struct managerVtable;

struct baseManager
{
  managerVtable *vtable;
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;
};

#pragma pack(pop)

#endif
