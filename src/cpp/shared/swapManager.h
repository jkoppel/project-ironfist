#ifndef SWAPMANAGER_H
#define SWAPMANAGER_H

#include "manager.h"
#include "gui/gui.h"
#include "game/game.h"

#pragma pack(push,1)

struct swapManager : public baseManager
{
	heroWindow *window;
	icon* swapButtonIcn;
	hero *heroes[2];
	int heroIdxMovingFrom;
	int heroIdxMovingTo;
	int idxMovingFrom;
	int idxMovingTo;
	int field_56;
	int Open(int a2);
	void Reset();
	void Update();
};
#pragma pack(pop)

#endif