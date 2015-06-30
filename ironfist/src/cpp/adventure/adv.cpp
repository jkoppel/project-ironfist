#include "adventure/adv.h"
#include "adventure/map.h"
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

void game::ShareVision(int sourcePlayer, int destPlayer) {
    this->sharePlayerVision[sourcePlayer][destPlayer] = 1;
    this->PropagateVision();
}

void game::PropagateVision() {
    for (int p1 = 0; p1 < NUM_PLAYERS; p1++) {
        for (int p2 = 0; p2 < NUM_PLAYERS; p2++) {
            if (this->sharePlayerVision[p1][p2]) {
                for (int i = 0; i < MAP_HEIGHT; i++) {
                    for (int j = 0; j < MAP_WIDTH; j++) {
                        if (MapCellVisible(j, i, p1)) {
                            RevealMapCell(j, i, p2);
                        }
                    }
                }
            }
        }
    }
}

void game::SetVisibility(int x, int y, int player, int radius) {
    this->SetVisibility_orig(x, y, player, radius);

    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (this->sharePlayerVision[player][i]) {
            // Would take more work to be transitive without infinite recursion
            this->SetVisibility_orig(x, y, i, radius);
        }
    }
}

void game::MakeAllWaterVisible(int player) {
    this->MakeAllWaterVisible_orig(player);

    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (this->sharePlayerVision[player][i]) {
            // Would take more work to be transitive without infinite recursion
            this->MakeAllWaterVisible_orig(i);
        }
    }
}