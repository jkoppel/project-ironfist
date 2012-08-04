
#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H


struct baseManager;

 managerVtable
{
  int (__thiscall *initialize)(baseManager *, int);
  void (__thiscall *cleanUp)(baseManager *);
  int (__thiscall *handleInput)(baseManager *, tag_message *);
};

struct baseManager
{
  ManagerVtable *vtable;
  baseManager *next;
  baseManager *prev;
  int type;
  int idx;
  char name[30];
  int ready;
};

#endif
