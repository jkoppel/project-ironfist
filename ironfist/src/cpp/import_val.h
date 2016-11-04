#ifndef IMPORT_VAL_H
#define IMPORT_VAL_H

#include "resources.h"

extern "C" int useEvilBorders;
extern "C" char* goodEvilIcons[NUM_GOOD_EVIL_ICONS][2];

extern "C" char globBuf[];

extern "C" char* heroes2agg_path;
extern "C" char* heroes2xagg_path;

extern "C" int handleIndicesStack[];
extern "C" int fileOffsetStack[];
extern "C" int indexOfFileOffsetStack;

extern "C" ManagerVtable ResourceManager_vtable;

#endif