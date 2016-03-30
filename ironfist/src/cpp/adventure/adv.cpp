#include "adventure/adv.h"
#include "game/game.h"
#include "scripting/hook.h"
#include "combat/creatures.h"

int advManager::Open(int idx) {
	int res = this->Open_orig(idx);
	if(gpGame->day == 1 && gpGame->week == 1 && gpGame->month == 1) {
		//The NEW_DAY event is triggered after game::PerDay, but that is not called
		//before the first day
		//
		//The correct place to put this is wherever the start-of-map events fire
		//This kinda works, but will also fire after exiting the town screen or
		//combat on the first day
	}
	return res;
}

mapCell* advManager::MoveHero(int a2, int a3, int *a4, int *a5, int *a6, int a7, int *a8, int a9)
{
	char tr[10];
	mapCell* res = MoveHero_orig(a2, a3, a4, a5, a6, a7, a8, a9);
	sprintf_s(tr, "%i,%i", GetCurrentHero()->x, GetCurrentHero()->y);
	ScriptSignal(SCRIPT_EVT_MOVEHERO, tr);
	return res;
}

int recruitUnit::Open(int x)
{
	char ctype[4];
	itoa(creatureType, ctype, 10);
	ScriptSignal(SCRIPT_EVT_RECRUIT, ctype );
	return Open_orig(x);
}