#ifndef EVENTS_H
#define EVENTS_H

#include "manager.h"

#include "adventure/adv.h"
#include "resource/resources.h"

#pragma pack(push, 1)

class eventsManager : public baseManager {
public:
	icon* overlayIcn;

	void EditTown(int, int);
	int EditHero(int, int, int);
	int EditHero_orig(int, int, int);
	int EditEvent(int);
	int EditEvent_orig(int);
};

extern void __fastcall ResizeWindow(int x, int y,int width, int height);

void __stdcall FillInEventEdit(EventExtra *);
extern void __stdcall FillInEventEdit_orig(EventExtra *);

// The EditEvent dialog automatically fills in the artifacts from the
// base game and expansion. To get any extra items defined in the xml
// file, we need to request that a function that runs after EditEvent
// fill in the rest. (That function is FillInEventEdit.)
void EditEvent_RequestUserDefinedElements();

#pragma pack(pop)

#endif