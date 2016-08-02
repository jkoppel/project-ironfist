#include "adventure/adv.h"
#include "adventure/map.h"
#include "combat/creatures.h"
#include "combat/speed.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "scripting/hook.h"
#include "prefs.h"

#include <sstream>

static const int END_TURN_BUTTON = 4;

int advManager::ProcessDeSelect(tag_message *evt, int *n, mapCell **cells) {
  extern int giBottomViewOverride;
  extern int iCurBottomView;
  extern int giBottomViewOverrideEndTime;

  if (evt->yCoordOrFieldID == END_TURN_BUTTON) {
    int hero_reminder_pref = read_pref<DWORD>("Show Hero Movement Reminder");
    //default is true, but read_pref() returns -1 if the value is not set
    bool show_hero_movement_reminder = hero_reminder_pref != 0;

    if (gpCurPlayer->HasMobileHero()) {
      if (!show_hero_movement_reminder) {
        gpGame->NextPlayer();
      } else { //if the movement reminder is on, ask player if he/she really wants to end turn
        NormalDialog("One or more heroes may still move, are you sure you want to end your turn?",
          2, -1, -1, -1, 0, -1, 0, -1, 0);

        if (gpWindowManager->buttonPressedCode != BUTTON_CODE_CANCEL)
          gpGame->NextPlayer();
      }
    } else { //there are no heroes with movement points left, end turn
      gpGame->NextPlayer();
    }

    // This is taken out of the original ProcessDeSelect. Exact purpose is unknown; could quite
    // possible be removed
    if (evt->yCoordOrFieldID >= 2000
      && evt->yCoordOrFieldID <= 2200) {
      if (giBottomViewOverride == 2) {
        giBottomViewOverride = 1;
      } else if (giBottomViewOverride) {
        giBottomViewOverride = 0;
      } else if (iCurBottomView == 2) {
        giBottomViewOverride = 1;
      } else {
        giBottomViewOverride = 2;
      }

      giBottomViewOverrideEndTime = KBTickCount() + 3000;
      UpdBottomView(1, 1, 1);
  
    }

    return 1;
  } else {
    return ProcessDeSelect_orig(evt, n, cells);
  }

}


int advManager::Open(int idx) {
  int res = this->Open_orig(idx);
  if (gpGame->day == 1 && gpGame->week == 1 && gpGame->month == 1) {
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

mapCell* advManager::MoveHero(int a2, int a3, int *a4, int *a5, int *a6, int a7, int *a8, int a9){
  mapCell* res = MoveHero_orig(a2, a3, a4, a5, a6, a7, a8, a9);
  hero *hro = GetCurrentHero();
  std::ostringstream msg;
  msg << hro->x << "," << hro->y;
  ScriptSignal(SCRIPT_EVT_MOVEHERO, msg.str());
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

void advManager::DoEvent(class mapCell *cell, int locX, int locY) {
	int locType = cell->objType & 0x7F;
	if (locType == LOCATION_CAMPFIRE) {
		std::ostringstream tmp;
		tmp << locX << "," << locY;
		ScriptSignal(SCRIPT_EVT_VISIT_CAMPFIRE, tmp.str());
	}
	this->DoEvent_orig(cell, locX, locY);
}

int advManager::CombatMonsterEvent(class hero *hero, int mon1, int mon1quantity, class mapCell *mapcell, int locX, int locY, int a8, int locX2, int locY2, int mon2, int mon2quantity, int mon2stacks, int mon3, int mon3quantity, int mon3stacks) {
	return CombatMonsterEvent_orig(hero, mon1, mon1quantity, mapcell, locX, locY, a8, locX2, locY2, mon2, mon2quantity, mon2stacks, mon3, mon3quantity, mon3stacks);
}