#include "adventure/adv.h"
#include "game/game.h"
#include "scripting/hook.h"

int advManager::Open(int idx) {
	int res = this->Open_orig(idx);
	if(gpGame->day == 1 && gpGame->week == 1 && gpGame->month == 1) {
		//The NEW_DAY event is triggered after game::PerDay, but that is not called
		//before the first day
		//
		//The correct place to put this is wherever the start-of-map events fire
		//This kinda works, but will also fire after exiting the town screen or
		//combat on the first day
		ScriptSignal(SCRIPT_EVT_MAP_START, "");
		ScriptSignal(SCRIPT_EVT_NEW_DAY, "");
	}
	return res;
}