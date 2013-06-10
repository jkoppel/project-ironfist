#ifndef EVENTS_H
#define EVENTS_H

#include "manager.h"

#include "resource/resources.h"

class eventsManager : public baseManager {
public:
	icon* overlayIcn;

	int EditTown(int, int);
	int EditTown_orig(int, int);
};

#endif