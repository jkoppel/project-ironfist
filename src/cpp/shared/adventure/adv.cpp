#include "adventure/adv.h"
#include "adventure/map.h"
#include "artifacts.h"
#include "combat/creatures.h"
#include "combat/speed.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "gui/gui.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "prefs.h"

#include "optional.hpp"
#include <sstream>
#include <string>

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
  return res;
}

mapCell* advManager::MoveHero(int a2, int a3, int *a4, int *a5, int *a6, int a7, int *a8, int a9) {
  mapCell* res = MoveHero_orig(a2, a3, a4, a5, a6, a7, a8, a9);
  hero *hro = GetCurrentHero();
  ScriptCallback("OnHeroMove", hro->x, hro->y);
  return res;
}

void game::ShareVision(int sourcePlayer, int destPlayer) {
  this->sharePlayerVision[sourcePlayer][destPlayer] = true;
  this->PropagateVision();
}

void game::CancelShareVision(int sourcePlayer, int destPlayer) {
	this->sharePlayerVision[sourcePlayer][destPlayer] = false;
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
  hero *hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  int locationType = cell->objType & 0x7F;
  SAMPLE2 res2 = NULL_SAMPLE2;
  nonstd::optional<bool> shouldSkip = ScriptCallbackResult<bool>("OnLocationVisit", locationType, locX, locY);
  if (!shouldSkip.value_or(false)) {
    if (locationType != LOCATION_SHRINE_FIRST_ORDER && locationType != LOCATION_SHRINE_SECOND_ORDER && locationType != LOCATION_SHRINE_THIRD_ORDER) {
      this->DoEvent_orig(cell, locX, locY);
      return;
    }
    this->HandleSpellShrine(cell, locationType, hro, res2, locX, locY);
  }

  this->UpdateRadar(1, 0);
  this->UpdateHeroLocators(1, 1);
  this->UpdateTownLocators(1, 1);
  this->UpdBottomView(1, 1, 1);
  this->UpdateScreen(0, 0);
  gpSoundManager->SwitchAmbientMusic(giTerrainToMusicTrack[this->currentTerrain]);
  WaitEndSample(res2, res2.sample);
  CheckEndGame(0, 0);
}

void advManager::HandleSpellShrine(class mapCell *cell, int locationType, hero *hro, SAMPLE2 res2, int locX, int locY) {
  switch (locationType) {
    case LOCATION_SHRINE_FIRST_ORDER: {
      sprintf(gText, "{Shrine of the 1st Circle}\n\nYou come across a small shrine attended by a group of novice acolytes.  In exchange for your protection, they agree to teach you a simple spell - '%s'.  ", gSpellNames[cell->extraInfo - 1]);
      break;
    }
    case LOCATION_SHRINE_SECOND_ORDER: {
      sprintf(gText, "{Shrine of the 2nd Circle}\n\nYou come across an ornate shrine attended by a group of rotund friars.  In exchange for your protection, they agree to teach you a spell - '%s'.  ", gSpellNames[cell->extraInfo - 1]);
      break;
    }
    case LOCATION_SHRINE_THIRD_ORDER: {
      sprintf(gText, "{Shrine of the 3rd Circle}\n\nYou come across a lavish shrine attended by a group of high priests.  In exchange for your protection, they agree to teach you a sophisticated spell - '%s'.  ", gSpellNames[cell->extraInfo - 1]);
      break;
    }
  }

  if (hro->HasArtifact(ARTIFACT_MAGIC_BOOK)) {
    if (gsSpellInfo[cell->extraInfo - 1].level > hro->secondarySkillLevel[SECONDARY_SKILL_WISDOM] + 2) {
      strcat(gText, "Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.  ");  // Why is there a trailing space here?
      this->EventWindow(-1, 1, gText, -1, 0, -1, 0, -1);
    } else {
      this->EventSound(locationType, NULL, &res2);
      int heroKnowledge = hro->Stats(PRIMARY_SKILL_KNOWLEDGE);
      hro->AddSpell(cell->extraInfo - 1, heroKnowledge);
      this->EventWindow(-1, 1, gText, 8, cell->extraInfo - 1, -1, 0, -1);
    }
  } else {
    strcat(gText, "Unfortunately, you have no Magic Book to record the spell with.");
    this->EventWindow(-1, 1, gText, -1, 0, -1, 0, -1);
  }
}

int advManager::MapPutArmy(int x, int y, int monIdx, int monQty) {
  int cellIdx = x * gpGame->map.height + y;
  gpGame->map.tiles[cellIdx].objectIndex = monIdx;
  gpGame->map.tiles[cellIdx].extraInfo = monQty;
  gpGame->map.tiles[cellIdx].objTileset = TILESET_MONSTER;
  gpGame->map.tiles[cellIdx].objType = TILE_HAS_EVENT | LOCATION_ARMY_CAMP;
  gpGame->map.tiles[cellIdx].overlayIndex = -1;
  gpGame->map.tiles[cellIdx].field_4_1 = 0;
  gpGame->map.tiles[cellIdx].isShadow = 0;
  return 0;
}

int mapCell::getLocationType() {
  return this->objType & 0x7F;
}

void advManager::QuickInfo(int x, int y) {
  const int xLoc = x + viewX;
  const int yLoc = y + viewY;
  if (!(xLoc >= 0 && xLoc < MAP_WIDTH && yLoc >= 0 && yLoc < MAP_HEIGHT)) {
    // Outside map boundary
    QuickInfo_orig(x, y);
    return;
  }

  const auto mapCell = GetCell(xLoc, yLoc);
  const int locationType = mapCell->objType & 0x7F;
  auto overrideText = ScriptCallbackResult<std::string>("GetTooltipText", locationType, xLoc, yLoc);
  if (!overrideText || overrideText->empty()) {
    // Lua error occurred or tooltip text not overridden.
    QuickInfo_orig(x, y);
    return;
  }

  // Ensure the tooltip box is visible on the screen.
  int pxOffset = 32 * x - 57;
  if (pxOffset < 30) {
    pxOffset = 30;
  } else if (pxOffset + 160 > 464) {
    pxOffset = 304;
  }

  int pyOffset = 32 * y - 25;
  if (pyOffset < 16) {
    pyOffset = 16;
  } else if (pyOffset + 96 > 448) {
    pyOffset = 352;
  }

  heroWindow tooltip(pxOffset, pyOffset, "qwikinfo.bin");
  GUISetText(&tooltip, 1, *overrideText);
  gpWindowManager->AddWindow(&tooltip, 1, -1);
  QuickViewWait();
  gpWindowManager->RemoveWindow(&tooltip);
}