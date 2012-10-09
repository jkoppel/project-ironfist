#include "base.h"
#include "game/game.h"
#include "combat/creatures.h"


int game::GetRandomNumTroops(int creat) {
	return Random(gMonRandBound[creat][0], gMonRandBound[creat][1]);
}