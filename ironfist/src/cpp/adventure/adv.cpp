#include "adventure/adv.h"
#include "adventure/map.h"
#include "game/game.h"
#include "scripting/hook.h"
#include "prefs.h"

extern void __fastcall NormalDialog(char *, int, int, int, int, int, int, int, int, int);

const int BUTTON_CODE_OKAY = 30725;
const int BUTTON_CODE_CANCEL = 30726;

extern long __fastcall KBTickCount();

int advManager::ProcessDeSelect(struct tag_message *GUIMessage_evt, int *a3, class mapCell * *a4) {
	extern int giBottomViewOverride;
	extern int iCurBottomView;
	extern int giBottomViewOverrideEndTime;
	
	if(GUIMessage_evt->yCoordOrFieldID == 4) {
		DWORD hero_reminder_reg_dword = read_pref<DWORD>("Show Hero Movement Reminder");
		//default is true, but read_pref() returns -1 if the value is not set
		bool show_hero_movement_reminder = !(hero_reminder_reg_dword == 0);
		
		if(gpCurPlayer->HasMobileHero()) { //if there are any heroes with movement remaining
			if(!show_hero_movement_reminder) { //if the movement reminder is turned off, end turn
				gpGame->NextPlayer();
				}
			else { //if the movement reminder is on, ask player if he/she really wants to end turn
				NormalDialog("One or more heroes may still move, are you sure you want to end your turn?",
								2, -1, -1, -1, 0, -1, 0, -1, 0);

				if(gpWindowManager->buttonPressedCode != BUTTON_CODE_CANCEL)
					gpGame->NextPlayer();
				}
			}
		else { //there are no heroes with movement points left, end turn
			gpGame->NextPlayer();
			}
		if(GUIMessage_evt->yCoordOrFieldID >= 2000
		   && GUIMessage_evt->yCoordOrFieldID <= 2200) {
			if(giBottomViewOverride == 2) {
				giBottomViewOverride = 1;
				}
			else if(giBottomViewOverride) {
				giBottomViewOverride = 0;
				}
			else if(iCurBottomView == 2) {
				giBottomViewOverride = 1;
				}
			else {
				giBottomViewOverride = 2;
				}
			giBottomViewOverrideEndTime = KBTickCount() + 3000;
			UpdBottomView(1, 1, 1);
		}
		return 1;
	}
	return ProcessDeSelect_orig(GUIMessage_evt, a3, a4);
}


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