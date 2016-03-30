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
};

#pragma pack(pop)

#endif