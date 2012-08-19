#include "tied/base.h"
#include "tied/game/game.h"
#include "tied/combat/creatures.h"


int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}