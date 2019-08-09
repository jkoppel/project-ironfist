#include "adventure/adv.h"
#include "adventure/map.h"
#include "artifacts.h"
#include "combat/creatures.h"
#include "combat/speed.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "gui/gui.h"
#include "resource/resourceManager.h"
#include "scripting/callback.h"
#include "sound/sound.h"
#include "spell/spells.h"
#include "prefs.h"
#include "skills.h"

#include "optional.hpp"
#include <sstream>
#include <string>

static const int END_TURN_BUTTON = 4;

int castleIconFrames[MAX_FACTIONS] = {
  9,
  10,
  11,
  12,
  13,
  14,
  0,
  0,
  0,
  0,
  0,
  0,
  25
};

int townIconFrames[MAX_FACTIONS] = {
  15,
  16,
  17,
  18,
  19,
  20,
  0,
  0,
  0,
  0,
  0,
  0,
  26
};

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

    switch (locationType) {
    case LOCATION_SHRINE_FIRST_ORDER:
    case LOCATION_SHRINE_SECOND_ORDER:
    case LOCATION_SHRINE_THIRD_ORDER:
      this->HandleSpellShrine(cell, locationType, hro, &res2, locX, locY);
      break;
    case LOCATION_PYRAMID:
      this->HandlePyramid(cell, locationType, hro, &res2, locX, locY);
      break;
    default:
      this->DoEvent_orig(cell, locX, locY);
      return;
    }
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

void advManager::HandleSpellShrine(class mapCell *cell, int locationType, hero *hro, SAMPLE2 *res2, int locX, int locY) {
  int spellId = cell->extraInfo - 1;

  std::string shrineText;
  switch (locationType) {
    case LOCATION_SHRINE_FIRST_ORDER: {
      shrineText = "{Shrine of the 1st Circle}\n\nYou come across a small shrine attended by a group of novice acolytes.  In exchange for your protection, they agree to teach you a simple spell - '";
      shrineText += gSpellNames[spellId];
      shrineText += "'.  ";
      break;
    }
    case LOCATION_SHRINE_SECOND_ORDER: {
      shrineText = "{Shrine of the 2nd Circle}\n\nYou come across an ornate shrine attended by a group of rotund friars.  In exchange for your protection, they agree to teach you a spell - '";
      shrineText += gSpellNames[spellId];
      shrineText += "'.  ";
      break;
    }
    case LOCATION_SHRINE_THIRD_ORDER: {
      shrineText = "{Shrine of the 3rd Circle}\n\nYou come across a lavish shrine attended by a group of high priests.  In exchange for your protection, they agree to teach you a sophisticated spell - '";
      shrineText += gSpellNames[spellId];
      shrineText += "'.  ";
      break;
    }
  }

  if (hro->HasArtifact(ARTIFACT_MAGIC_BOOK)) {
    if (gsSpellInfo[spellId].level > hro->secondarySkillLevel[SECONDARY_SKILL_WISDOM] + 2) {
      shrineText += "Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.";
      this->EventWindow(-1, 1, &shrineText[0], -1, 0, -1, 0, -1);
    } else {
      this->EventSound(locationType, NULL, res2);
      int heroKnowledge = hro->Stats(PRIMARY_SKILL_KNOWLEDGE);
      hro->AddSpell(spellId, heroKnowledge);
      this->EventWindow(-1, 1, &shrineText[0], 8, spellId, -1, 0, -1);
    }
  } else {
    shrineText += "Unfortunately, you have no Magic Book to record the spell with.";
    this->EventWindow(-1, 1, &shrineText[0], -1, 0, -1, 0, -1);
  }
}

void advManager::HandlePyramid(class mapCell *cell,int locType, hero *hro, SAMPLE2 *res2, int locX, int locY) {
  int spellId = cell->extraInfo - 1;

  this->EventSound(locType, cell->extraInfo, res2);

  this->EventWindow(-1, 2,
    "You come upon the pyramid of a great and ancient king.  You are tempted to search it for treasure, but all the old stories warn of fearful curses and undead guardians.  Will you search?",
    -1, 0, -1, 0, -1);

  if (gpWindowManager->buttonPressedCode == BUTTON_YES) {
    if (cell->extraInfo != 0) {
      
      if (!this->CombatMonsterEvent(hro, CREATURE_ROYAL_MUMMY, 30, cell, locX, locY, 0, locX, locY, CREATURE_VAMPIRE_LORD, 20, 2, -1, 0, 0)) {
        hro->CheckLevel();
        
        std::string msg;
        msg += "Upon defeating the monsters, you decipher an ancient glyph on the wall, telling the secret of the spell - '";
        msg += gSpellNames[spellId];
        msg += "'.  ";

        if (hro->HasArtifact(ARTIFACT_MAGIC_BOOK)) {
          if (hro->secondarySkillLevel[SECONDARY_SKILL_WISDOM] < gsSpellInfo[spellId].level - 2) {
            msg += "  Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.  ";
            advManager::EventWindow(-1, 1, &msg[0], -1, 0, -1, 0, -1);
          } else {
            int knowledge = hro->Stats(PRIMARY_SKILL_KNOWLEDGE);

            hro->AddSpell(spellId, knowledge);
            advManager::EventWindow(-1, 1, &msg[0], 8, spellId, -1, 0, -1);
          }
        } else {
          msg += "  Unfortunately, you have no Magic Book to record the spell with.";
          this->EventWindow(-1, 1, &msg[0], -1, 0, -1, 0, -1);
        }
        cell->extraInfo = 0;
      }
    } else {
      NormalDialog(
        "You come upon the pyramid of a great and ancient king.  Routine exploration reveals that the pyramid is completely empty.",
        1, -1, -1,11, 0, 11, 0, -1, 0);

      if (!(hro->flags & HERO_FLAG_RELATED_TO_PYRAMID)) {
        hro->flags |= HERO_FLAG_RELATED_TO_PYRAMID;
        hro->tempLuckBonuses -= 2;
      }
    }
  }
}

int advManager::MapPutArmy(int x, int y, int monIdx, int monQty) {
  int cellIdx = y * gpGame->map.height + x;
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
  const int pTileSize = 32;
  const int pxOffset = -57;  // tooltip is drawn (-57,-25) pixels from the mouse
  const int pyOffset = -25;
  const int pTooltipWidth = 160;
  const int pTooltipHeight = 96;

  int px = pTileSize * x + pxOffset;
  if (px < 30) {
    // minimum indent from left edge
    px = 30;
  } else if (px + pTooltipWidth > 464) {
    // don't overrun right edge
    px = 304;
  }

  int py = pTileSize * y + pyOffset;
  if (py < 16) {
    // minimum indent from top edge
    py = 16;
  } else if (py + pTooltipHeight > 448) {
    // don't overrun bottom edge
    py = 352;
  }

  heroWindow tooltip(px, py, "qwikinfo.bin");
  GUISetText(&tooltip, 1, *overrideText);
  gpWindowManager->AddWindow(&tooltip, 1, -1);
  QuickViewWait();
  gpWindowManager->RemoveWindow(&tooltip);
}

void advManager::PlayerMonsterInteract(mapCell *cell, mapCell *other, hero *player, int *window, int a1, int a2, int a3, int a4, int a5) {
	int x;
	int y;
	if (cell->objType != (LOCATION_ARMY_CAMP | TILE_HAS_EVENT)) {
		this->PlayerMonsterInteract_orig(cell, other, player, window, a1, a2, a3, a4, a5);
		return;
	}
	if (GetMapCellXY(cell, &x, &y)) {
		ScriptCallback("OnMonsterInteract", x, y);
	}
	this->PlayerMonsterInteract_orig(cell, other, player, window, a1, a2, a3, a4, a5);
}

void advManager::ComputerMonsterInteract(mapCell *cell, hero *computer, int *a1) {
	int x;
	int y;
	if (cell->objType != (LOCATION_ARMY_CAMP | TILE_HAS_EVENT)) {
		this->ComputerMonsterInteract_orig(cell, computer, a1);
		return;
	}
	if (GetMapCellXY(cell, &x, &y)) {
		ScriptCallback("OnMonsterInteract", x, y);
	}
	this->ComputerMonsterInteract_orig(cell, computer, a1);
}

void advManager::UpdateTownLocators(int a2, int updateScreen) { 
  if(!gbThisNetHumanPlayer[giCurPlayer])
    return;

  const int NUM_GUI_ROWS = 4;
  for(int guiRow = 0; guiRow < NUM_GUI_ROWS; ++guiRow) {
    int townID = *(&gpCurPlayer->castlesOwned[guiRow] + gpCurPlayer->directionFacing);
    tag_message evt;
    evt.eventCode = INPUT_GUI_MESSAGE_CODE;
    evt.xCoordOrKeycode = 8;
    evt.yCoordOrFieldID = guiRow + 32;
    if(gpCurPlayer->mightBeCurCastleIdx == -1 || gpCurPlayer->mightBeCurCastleIdx != townID || gbAllBlack)
      evt.payload = (void *)36;
    else
      evt.payload = (void *)153;
    this->adventureScreen->BroadcastMessage(evt);
    
    if(townID == -1 || gbAllBlack) {
      int guiField = guiRow + 16;
      GUISetImgIdx(this->adventureScreen, guiField, guiRow + 5);
      GUIRemoveFlag(this->adventureScreen, guiField, 2);
      guiField = guiRow + 300;
      GUIRemoveFlag(this->adventureScreen, guiField, 4);
    } else {
      int guiField = guiRow + 16;
      GUIAddFlag(this->adventureScreen, guiField, 2);

      int faction = gpGame->castles[townID].factionID;     
      if(!(gpGame->castles[townID].buildingsBuiltFlags & 0x40))
        GUISetImgIdx(this->adventureScreen, guiField, townIconFrames[faction]);
      else
        GUISetImgIdx(this->adventureScreen, guiField, castleIconFrames[faction]);

      guiField = guiRow + 300;
      if(BitTest((const LONG*)gpGame->builtToday, townID))
        GUIAddFlag(this->adventureScreen, guiField, 4);
      else
        GUIRemoveFlag(this->adventureScreen, guiField, 4);
    }
  }
  this->castleScrollbarKnob->offsetY = gpCurPlayer->numCastles >= 5 ? (unsigned __int16)(signed __int64)((double)gpCurPlayer->directionFacing * 74.0 / (double)((signed int)gpCurPlayer->numCastles - 4) + 195.0) : 232;
  if(a2)
    this->adventureScreen->DrawWindow(updateScreen);
}

void advManager::TownQuickView(int townID, int _104, int xOff, int a3) {
  if(townID == -1)
    return;  
  
  const int MAX_GARRISON_CREATURE_SLOTS = 5;

  icon *res = gpResourceManager->GetIcon("mons32.icn");
  town *town = &gpGame->castles[townID];

  if(xOff == -1) {
    xOff = 328;
    a3 = 176;
  }

  heroWindow *window = new heroWindow(xOff, a3, "qtown1.bin");
  if(!window)
    MemError();

  int thievesGuildsLevel;
  if(town->ownerIdx != giCurPlayer && giDebugLevel < 2) {
    thievesGuildsLevel = gpGame->getNumberOfThievesGuilds(giCurPlayer);
    if(thievesGuildsLevel > 2)
      thievesGuildsLevel = 2;
  } else {
    thievesGuildsLevel = 3;
  }
  if(this->IsCrystalBallInEffect(town->x, town->y, 8))
    thievesGuildsLevel = 3;
  SetWinText(window, 19);
  
  int faction = town->factionID;
  if(!(gpGame->castles[townID].buildingsBuiltFlags & 0x40))
    GUISetImgIdx(window, 2, townIconFrames[faction]);
  else
    GUISetImgIdx(window, 2, castleIconFrames[faction]);

  // built today icon
  if(thievesGuildsLevel != 3 || !BitTest((const LONG*)gpGame->builtToday, town->idx))
    GUIRemoveFlag(window, 300, 4);

  if(town->ownerIdx == -1) {
    GUIRemoveFlag(window, 8, 4);
    GUIRemoveFlag(window, 9, 4);
  } else {
    int val = 2 * gpGame->players[town->ownerIdx].color;
    GUISetImgIdx(window, 8, val);
    GUISetImgIdx(window, 9, val + 1);
  }

  GUISetText(window, 1, GetTownName(town->idx));

  int garrisonCreatures = 0;
  for(int i = 0; i < MAX_GARRISON_CREATURE_SLOTS; ++i) {
    if(town->garrison.creatureTypes[i] != -1)
      ++garrisonCreatures;
  }

  if(thievesGuildsLevel && garrisonCreatures) {
    iconWidget *iconWidgetArray[MAX_GARRISON_CREATURE_SLOTS];
    textWidget *textWidgetArray[MAX_GARRISON_CREATURE_SLOTS];

    int yOffset = 76;
    int numCreaturesSecondRow;
    int numCreaturesFirstRow;
    if(garrisonCreatures < 1 || garrisonCreatures >= 5) {
      numCreaturesSecondRow = 2;
      numCreaturesFirstRow = 3;
    } else if(garrisonCreatures >= 1 && garrisonCreatures <= 3) {
      yOffset = 98;
      numCreaturesSecondRow = garrisonCreatures;
      numCreaturesFirstRow = 0;
    } else {
      numCreaturesSecondRow = 2;
      numCreaturesFirstRow = 2;
    }
    
    int xOffset = 0;
    int xOffset2 = (192 / numCreaturesSecondRow - 32) / 2 + 22;
    int xOffset3 = 192 / numCreaturesSecondRow;

    int widgetIdx = 0;
    int garrisonIdx = 0;
    for(int i = 0; i < numCreaturesSecondRow; ++i) {
      if(garrisonCreatures == 5) {
        if(i)
          xOffset = -12;
        else
          xOffset = 12;
      }
      while(town->garrison.creatureTypes[garrisonIdx] == -1)
        ++garrisonIdx;

      int imgIdx = town->garrison.creatureTypes[garrisonIdx];

      IconEntry *iconEntry = GetIconEntry(res, imgIdx);

      int v10 = xOffset + xOffset2 + xOffset3 * widgetIdx - iconEntry->offsetX;
      int x = (32 - iconEntry->width) / 2 + v10 + 1;
      int y = (yOffset - iconEntry->offsetY) - iconEntry->height + 30;

      iconWidgetArray[widgetIdx] = new iconWidget(x, y, 32, 32, "mons32.icn", imgIdx, 0, -1, 16, 1);
      if(!iconWidgetArray[widgetIdx])
        MemError();           

      x = xOffset + xOffset2 + xOffset3 * widgetIdx - 14;
      y = yOffset + 32;
      char *quantityStr = this->GetQuantityString(thievesGuildsLevel, town, garrisonIdx);
      textWidgetArray[widgetIdx] = new textWidget(x, y, 60, 12, quantityStr, "smalfont.fnt", 1, -1, 512, 1);
      if(!textWidgetArray[widgetIdx])
        MemError();

      window->AddWidget((widget *)iconWidgetArray[widgetIdx], -1);
      window->AddWidget((widget *)textWidgetArray[widgetIdx++], -1);
      ++garrisonIdx;
    }

    if(numCreaturesFirstRow) {
      xOffset3 = 192 / numCreaturesFirstRow;
      int v31 = (192 / numCreaturesFirstRow - 32) / 2 + 22;
      int yOffset2 = yOffset + 44;
      for(int i = numCreaturesSecondRow; numCreaturesFirstRow + numCreaturesSecondRow > i; ++i) {
        while(town->garrison.creatureTypes[garrisonIdx] == -1)
          ++garrisonIdx;
        int imgIdx = town->garrison.creatureTypes[garrisonIdx];

        int v14 = yOffset2 - GetIconEntry(res, imgIdx)->offsetY;
        int y = v14 - GetIconEntry(res, imgIdx)->height + 30;
        int v16 = v31 + xOffset3 * (widgetIdx - numCreaturesSecondRow) - GetIconEntry(res, imgIdx)->offsetX;
        IconEntry *v17 = GetIconEntry(res, imgIdx);
        int x = (32 - v17->width) / 2 + v16 + 1;
        iconWidgetArray[widgetIdx] = new iconWidget(x, y, 32, 32, "mons32.icn", imgIdx, 0, -1, 16, 1);

        if(!iconWidgetArray[widgetIdx])
          MemError();       

        x = v31 + xOffset3 * (widgetIdx - numCreaturesSecondRow) - 14;
        y = yOffset2 + 32;
        char *quantityStr = this->GetQuantityString(thievesGuildsLevel, town, garrisonIdx);
        textWidgetArray[widgetIdx] = new textWidget(x, y, 60, 12, quantityStr, "smalfont.fnt", 1, -1, 512, 1);

        if(!textWidgetArray[widgetIdx])
          MemError();
        window->AddWidget((widget *)iconWidgetArray[widgetIdx], -1);
        window->AddWidget((widget *)textWidgetArray[widgetIdx++], -1);
        ++garrisonIdx;
      }
    }
  } else {
    std::string str;
    if(thievesGuildsLevel)
      str = "None";
    else
      str = "Unknown";
    char *charStr = (char*)BaseAlloc(str.size(), __FILE__, __LINE__);
          charStr = strdup(str.c_str());

    widget *guiObj = new textWidget(13, 117, 211, 12, charStr, "smalfont.fnt", 1, -1, 512, 1);

    if(!guiObj)
      MemError();
    window->AddWidget(guiObj, -1);
  }
  gpWindowManager->AddWindow(window, -1, 1);
  int tmpViewX = this->viewX;
  int tmpViewY = this->viewY;
  this->viewX = town->x - 7;
  this->viewY = town->y - 7;
  this->UpdateRadar(1, 0);
  QuickViewWait();
  gpWindowManager->RemoveWindow(window);
  delete window;
  this->viewX = tmpViewX;
  this->viewY = tmpViewY;
  this->UpdateRadar(1, 0);
  this->CompleteDraw(0);
  this->UpdateScreen(0, 0);
  // Never called anyway?
  //if(evt.eventCode == 8 && town->ownerIdx == giCurPlayer)
  //  this->SetTownContext(town->idx);
  gpResourceManager->Dispose((resource *)res);
}

char * advManager::GetQuantityString(int thievesGuildsLevel, town* town, int garrisonIdx) {
  std::string quantityStr;
  int quantity = town->garrison.quantities[garrisonIdx];
  if(thievesGuildsLevel == 3)
    quantityStr = std::to_string(quantity);
  else if(thievesGuildsLevel == 2)
    quantityStr = this->GetArmySizeName(quantity, 0);
  else
    quantityStr = "???";

  char *charStr = (char*)BaseAlloc(quantityStr.size(), __FILE__, __LINE__);
  charStr = strdup(quantityStr.c_str());
  return charStr;
}

bool GetMapCellXY(mapCell* cell, int* x, int* y) {
	for (int i = 0; i < gpGame->map.width; i++) {
		for (int j = 0; j < gpGame->map.height; j++) {
			if (cell == (&(gpGame->map.tiles[j * gpGame->map.width])) + i) {
				// heroCell = &this->map.tiles[heroLocationY * this->map.width] + heroLocationX;
				*x = i;
				*y = j;
				return true;
			}
		}
	}
	return false;
}

extern "C" char TileToBitmap(tileset *tiles, int idx, bitmap *targ, int x, int y);
extern unsigned char bPuzzleDraw[];


//extern "C" int spriteIdx;

extern unsigned char gColorTableRed[];
extern int gbDrawingPuzzle;

extern unsigned char monAnimDrawFrame[];

void advManager::DrawCell(int x, int y, int cellCol, int cellRow, int cellDrawingPhaseFlags, int a6) {
  hero *curDrawingHero;
  mapCell *currentlyDrawnMapTile;
  mapCell* dword_524D08;
  int curDrawingHeroColor;
  int curDrawingHeroFaction;
  int dword_524CD4;
  int dword_524CE4;
  int dword_524CF8;
  int dword_524D14;
  int dword_524D24;
  int isDrawingHeroOrBoat;
  __int16 word_524CAC;
  mapCellExtra *currentlyDrawingMapCellExtra;
  mine* dword_524EA8;

  int dword_524D2C;
  
  int spriteIdx;

  signed int v8; // [sp+10h] [bp-18h]@201
  signed int v9; // [sp+14h] [bp-14h]@194
  int v10; // [sp+1Ch] [bp-Ch]@199
  int v11; // [sp+20h] [bp-8h]@182
  int v12; // [sp+24h] [bp-4h]@127

  if(!a6 && !bShowIt)
    return;

  int drawX = 32 * cellCol;
  int drawY = 32 * cellRow;
  currentlyDrawnMapTile = this->GetCell(x, y);

  // Draw stone outline
  if(!gbAllBlack && (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)) {
  //if(!gbAllBlack && ((signed __int64)__PAIR__(y, x) < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)) {
    idx = -1;
    if(x == -1) {
      if(y == -1) {
        idx = 16;
      } else if(y == MAP_HEIGHT) {
        idx = 19;
      } else if(y >= 0 && y < MAP_HEIGHT) {
        idx = (y & 3) + 32;
      }
    } else if(x == MAP_WIDTH) {
      if(y == -1) {
        idx = 17;
      } else if(y == MAP_HEIGHT) {
        idx = 18;
      } else if(y >= 0 && y < MAP_HEIGHT) {
        idx = (y & 3) + 24;
      }
    } else if(y == -1) {
      if(x >= 0 && x < MAP_WIDTH)
        idx = (x & 3) + 20;
    } else if(y == MAP_HEIGHT && x >= 0 && x < MAP_WIDTH) {
      idx = (x & 3) + 28;
    }
    if(idx == -1)
      idx = (((unsigned __int64)(x + 16) >> 32) ^ abs(x + 16) & 3)
      + 4 * ((((unsigned __int64)(y + 16) >> 32) ^ abs(y + 16) & 3) - ((unsigned __int64)(y + 16) >> 32))
      - ((unsigned __int64)(x + 16) >> 32);
    TileToBitmap(this->stonTileset, idx, gpWindowManager->screenBuffer, drawX, drawY);
    return;
  }

  // Draw Terra Incognita
  if(!gbAllBlack && (unsigned __int8)(*(&mapRevealed[x] + MAP_WIDTH * y) & giCurWatchPlayerBit) || gbDrawingPuzzle) {
    dword_524CF8 = 0;
  } else {
    dword_524CF8 = 1;
    if(gbAllBlack)
      dword_524D24 = 0;
    else
      dword_524D24 = advManager::GetCloudLookup(x, y);
    if(!dword_524D24) {
      if(cellDrawingPhaseFlags & 0x20)
        //TileToBitmap(this->clofTileset, ((_BYTE)x + (_BYTE)y) & 3, gpWindowManager->screenBuffer, drawX, drawY);
        TileToBitmap(this->clofTileset, (x + y) & 3, gpWindowManager->screenBuffer, drawX, drawY);
      return;
    }
    if(dword_524D24 < 100) {
      dword_524CD4 = 0;
    } else {
      dword_524CD4 = 1;
      dword_524D24 -= 100;
    }
    if((dword_524D24 == 1 || dword_524D24 == 5) && x & 1)
      ++dword_524D24;
    if(dword_524D24 == 3 && y & 1)
      ++dword_524D24;
  }

  
  // DRAW SHITTON OF CRAP

  if(!(cellDrawingPhaseFlags & 0x20) || gbDrawingPuzzle) {
    if(cellDrawingPhaseFlags & 1) {
      word_524CAC = currentlyDrawnMapTile->flags;
      word_524CAC <<= 14;
      word_524CAC |= currentlyDrawnMapTile->groundIndex;
      TileToBitmap(this->groundTileset, (unsigned __int16)word_524CAC, gpWindowManager->screenBuffer, drawX, drawY);
      if(currentlyDrawnMapTile->field_4_1 && (!gbDrawingPuzzle || (currentlyDrawnMapTile->objTileset != 56 || (unsigned char)currentlyDrawnMapTile->objectIndex != 140))) {
        if(!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawnMapTile->objTileset]) {
          // draw roads
          IconToBitmap(
            this->tilesetIcns[currentlyDrawnMapTile->objTileset],
            gpWindowManager->screenBuffer,
            drawX,
            drawY,
            (unsigned char)currentlyDrawnMapTile->objectIndex,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          //  Draw campfires (???)
          if(currentlyDrawnMapTile->hasObject) {            
            dword_524CE4 = GetIconEntry(this->tilesetIcns[currentlyDrawnMapTile->objTileset], (unsigned char)currentlyDrawnMapTile->objectIndex)->someSortOfLength & 0x1F;
            IconToBitmap(
              this->tilesetIcns[currentlyDrawnMapTile->objTileset],
              gpWindowManager->screenBuffer,
              drawX,
              drawY,
              (unsigned char)currentlyDrawnMapTile->objectIndex + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }

      // Draw some objects like water wheel thing?
      if ( currentlyDrawnMapTile->extraIdx && (unsigned char)this->map->cellExtras[currentlyDrawnMapTile->extraIdx].nextIdx != 255 )
        currentlyDrawingMapCellExtra = &this->map->cellExtras[currentlyDrawnMapTile->extraIdx];
      else
        currentlyDrawingMapCellExtra = 0;
      while(currentlyDrawingMapCellExtra) {
        if(currentlyDrawingMapCellExtra->animatedObject
          && (!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawingMapCellExtra->objTileset])) {
          IconToBitmap(
            this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
            gpWindowManager->screenBuffer,
            drawX,
            drawY,
            currentlyDrawingMapCellExtra->objectIndex,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if(currentlyDrawingMapCellExtra->animatedObject) {
            dword_524CE4 = GetIconEntry(this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset], currentlyDrawingMapCellExtra->objectIndex)->someSortOfLength & 0x1F;
            IconToBitmap(
              this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
              gpWindowManager->screenBuffer,
              drawX,
              drawY,
              currentlyDrawingMapCellExtra->objectIndex + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if((unsigned char)currentlyDrawingMapCellExtra->nextIdx && (unsigned char)this->map->cellExtras[currentlyDrawingMapCellExtra->objectIndex].nextIdx != 255 )
          currentlyDrawingMapCellExtra = &this->map->cellExtras[currentlyDrawingMapCellExtra->objectIndex];
        else
          currentlyDrawingMapCellExtra = 0;
      }

      // Drawing shadows
      if((currentlyDrawnMapTile->isShadow) && !(currentlyDrawnMapTile->field_4_1) && (!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawnMapTile->objTileset])) {
        IconToBitmap(
          this->tilesetIcns[currentlyDrawnMapTile->objTileset],
          gpWindowManager->screenBuffer,
          drawX,
          drawY,
          (unsigned char)currentlyDrawnMapTile->objectIndex,
          0,
          0,
          0,
          0x1E0u,
          480,
          0);
        if(currentlyDrawnMapTile->hasObject) {
          dword_524CE4 = GetIconEntry(this->tilesetIcns[currentlyDrawnMapTile->objTileset], (unsigned char)currentlyDrawnMapTile->objectIndex)->someSortOfLength & 0x1F;
          IconToBitmap(
            this->tilesetIcns[currentlyDrawnMapTile->objTileset],
            gpWindowManager->screenBuffer,
            drawX,
            drawY,
            (unsigned char)currentlyDrawnMapTile->objectIndex + this->field_202 % dword_524CE4 + 1,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
        }
      }

      if ( currentlyDrawnMapTile->extraIdx && (unsigned char)this->map->cellExtras[currentlyDrawnMapTile->extraIdx].nextIdx != 255 )
        currentlyDrawingMapCellExtra = &this->map->cellExtras[currentlyDrawnMapTile->extraIdx];
      else
        currentlyDrawingMapCellExtra = 0;

      // Drawing more shadows ??
      while(currentlyDrawingMapCellExtra) {
        if((currentlyDrawingMapCellExtra->field_4_2) && !(currentlyDrawingMapCellExtra->field_4_4) // ???
          && (!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawingMapCellExtra->objTileset])) {
          IconToBitmap(
            this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
            gpWindowManager->screenBuffer,
            drawX,
            drawY,
            currentlyDrawingMapCellExtra->objectIndex,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if(currentlyDrawingMapCellExtra->animatedObject) {
            dword_524CE4 = GetIconEntry(this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset], currentlyDrawingMapCellExtra->objectIndex)->someSortOfLength & 0x1F;
            IconToBitmap(
              this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
              gpWindowManager->screenBuffer,
              drawX,
              drawY,
              currentlyDrawingMapCellExtra->objectIndex + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if((unsigned char)currentlyDrawingMapCellExtra->nextIdx && (unsigned char)this->map->cellExtras[currentlyDrawingMapCellExtra->objectIndex].nextIdx != 255 )
          currentlyDrawingMapCellExtra = &this->map->cellExtras[currentlyDrawingMapCellExtra->objectIndex];
        else
          currentlyDrawingMapCellExtra = 0;
      }
    }
    if(cellDrawingPhaseFlags & 2) {
      // Drawing treasures / resources / main tiles of those
      if((unsigned char)currentlyDrawnMapTile->objectIndex != 255
        && !(currentlyDrawnMapTile->field_4_1)
        && !(currentlyDrawnMapTile->isShadow)
        && !(currentlyDrawnMapTile->field_4_3)
        && (currentlyDrawnMapTile->objTileset) != 12
        && (!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawnMapTile->objTileset])) {
        IconToBitmap(
          this->tilesetIcns[currentlyDrawnMapTile->objTileset],
          gpWindowManager->screenBuffer,
          drawX,
          drawY,
          (unsigned char)currentlyDrawnMapTile->objectIndex,
          0,
          0,
          0,
          0x1E0u,
          480,
          0);
        if(currentlyDrawnMapTile->hasObject) {
          dword_524CE4 = GetIconEntry(this->tilesetIcns[currentlyDrawnMapTile->objTileset], (unsigned char)currentlyDrawnMapTile->objectIndex)->someSortOfLength & 0x1F;
          v12 = this->field_202 % dword_524CE4;
          if(currentlyDrawnMapTile->objType == 223) {
            if(currentlyDrawnMapTile->extraInfo)
              v12 = this->field_202 % (dword_524CE4 - 1);
            else
              v12 = dword_524CE4 - 1;
          }
          IconToBitmap(
            this->tilesetIcns[currentlyDrawnMapTile->objTileset],
            gpWindowManager->screenBuffer,
            drawX,
            drawY,
            v12 + (unsigned char)currentlyDrawnMapTile->objectIndex + 1,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
        }
      }
      if (currentlyDrawnMapTile->extraIdx && (unsigned char)this->map->cellExtras[currentlyDrawnMapTile->extraIdx].nextIdx != 255)
        currentlyDrawingMapCellExtra = &this->map->cellExtras[currentlyDrawnMapTile->extraIdx];
      else
        currentlyDrawingMapCellExtra = 0;

      while(currentlyDrawingMapCellExtra) {
        if(!(currentlyDrawingMapCellExtra->field_4_4) // ??? should be 4_1 but it crashes!?
          && !(currentlyDrawingMapCellExtra->field_4_2)
          && !(currentlyDrawingMapCellExtra->field_4_3)
          && (currentlyDrawingMapCellExtra->objTileset) != 12
          && (!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawingMapCellExtra->objTileset])) {
          IconToBitmap(
            this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
            gpWindowManager->screenBuffer,
            drawX,
            drawY,
            (unsigned char)currentlyDrawingMapCellExtra->objectIndex,
            0,
            0,
            0,
            0x1E0u,
            480,
            0);
          if(currentlyDrawingMapCellExtra->animatedObject) {
            dword_524CE4 = GetIconEntry(this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset], (unsigned char)currentlyDrawingMapCellExtra->objectIndex)->someSortOfLength & 0x1F;
            IconToBitmap(
              this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
              gpWindowManager->screenBuffer,
              drawX,
              drawY,
              (unsigned char)currentlyDrawingMapCellExtra->objectIndex + this->field_202 % dword_524CE4 + 1,
              0,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
        if((unsigned char)currentlyDrawingMapCellExtra->nextIdx && (unsigned char)this->map->cellExtras[(unsigned char)currentlyDrawingMapCellExtra->objectIndex].nextIdx != 255 )
          currentlyDrawingMapCellExtra = &this->map->cellExtras[(unsigned char)currentlyDrawingMapCellExtra->objectIndex];
        else
          currentlyDrawingMapCellExtra = 0;
      }
    }
    if((cellDrawingPhaseFlags & 8 || cellDrawingPhaseFlags & 0x80) && !gbDrawingPuzzle) {
      isDrawingHeroOrBoat = 0;
      curDrawingHero = 0;
      // Drawing creatures?!
      if(cellDrawingPhaseFlags & 8) {
        if(x > 0) {
          dword_524D08 = this->GetCell(x - 1, y);
          if(dword_524D08->objType == 151) {
            dword_524EA8 = &gpGame->mines[dword_524D08->extraInfo];
            if(dword_524EA8->guardianType == 59) {
              IconToBitmap(
                this->tilesetIcns[10],
                gpWindowManager->screenBuffer,
                drawX - 16,
                drawY,
                (x + y + this->field_202) % 15,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            } else if(dword_524EA8->guardianType != -1) {
              IconToBitmap(
                this->tilesetIcns[39],
                gpWindowManager->screenBuffer,
                drawX - 32,
                drawY,
                dword_524EA8->guardianType - 62,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
          }
        }
        if(currentlyDrawnMapTile->objTileset == 12) {
          if(this->field_2B2 != x || this->field_2B6 != y) {
            IconToBitmap(
              this->tilesetIcns[20],
              gpWindowManager->screenBuffer,
              drawX + 16,
              drawY + 30,
              9 * (signed char)currentlyDrawnMapTile->objectIndex,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
            if((signed char)currentlyDrawnMapTile->objectIndex != 59 && (signed char)currentlyDrawnMapTile->objectIndex != 60)
              dword_524D14 = (unsigned __int8)monAnimDrawFrame[*(&this->field_20A + (x & 3))];
            else
              dword_524D14 = *(&this->field_20A + (x & 3)) % 6;
            IconToBitmap(
              this->tilesetIcns[20],
              gpWindowManager->screenBuffer,
              drawX + 16,
              drawY + 30,
              dword_524D14 + 9 * (signed char)currentlyDrawnMapTile->objectIndex + 1,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          } else {
            IconToBitmap(
              this->tilesetIcns[20],
              gpWindowManager->screenBuffer,
              drawX + 16,
              drawY + 30,
              8 - (this->field_2BA < 1u) + 9 * (signed char)currentlyDrawnMapTile->objectIndex,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          }
        }
      }
      // boats or smth?
      if(currentlyDrawnMapTile->objType == 171) {
        curDrawingHeroColor = -1;
        curDrawingHeroFaction = 6;
        spriteIdx = this->GetCursorBaseFrame(gpGame->boats[currentlyDrawnMapTile->extraInfo].field_3);
        isDrawingHeroOrBoat = 1;
        dword_524D2C = -10;
      } else {
        dword_524D2C = 0;
        if(currentlyDrawnMapTile->objType == 170) {
          curDrawingHero = &gpGame->heroes[currentlyDrawnMapTile->extraInfo];
          curDrawingHeroColor = gpGame->players[curDrawingHero->ownerIdx].color;
          curDrawingHeroFaction = curDrawingHero->flags & HERO_AT_SEA ? 6 : curDrawingHero->factionID;
          spriteIdx = advManager::GetCursorBaseFrame(curDrawingHero->directionFacing);
          isDrawingHeroOrBoat = 1;
          if(curDrawingHero->flags & 0x80)
            dword_524D2C = -10;
        }
      }

      if(isDrawingHeroOrBoat) {
        if(spriteIdx & 0x80) {
          if(cellDrawingPhaseFlags & 0x80) {
            if(this->field_276 && curDrawingHeroFaction != 6) {
              v11 = spriteIdx & 0x7F;
              if(v11 == 51)
                v11 = 56;
              if(v11 == 50)
                v11 = 57;
              if(v11 == 49)
                v11 = 58;
              if(v11 == 47)
                v11 = 55;
              if(v11 == 46)
                v11 = 55;
              if(v11 < 9 || v11 >= 36)
                v9 = 0;
              else
                v9 = 50;
              IconToBitmap(
                this->shadowIcon,
                gpWindowManager->screenBuffer,
                drawX,
                drawY + 31,
                v9 + v11,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
            if(this->field_276 && curDrawingHeroFaction == 6) {
              v10 = spriteIdx & 0x7F;
              if(v10 < 9 || v10 >= 36)
                v8 = 0;
              else
                v8 = 36;
              IconToBitmap(
                this->boatShadowIcon,
                gpWindowManager->screenBuffer,
                drawX,
                dword_524D2C + drawY + 31,
                v8 + v10,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            }
          } else {
            if(curDrawingHeroFaction == 6 && !(currentlyDrawnMapTile->flags & 4))
              FlipIconToBitmap(
                this->frothIcon,
                gpWindowManager->screenBuffer,
                drawX + 32,
                dword_524D2C + drawY + 31,
                spriteIdx & 0x7F,
                1,
                0,
                0,
                480,
                480,
                0);
            FlipIconToBitmap(
              (icon *)this->heroIcons[curDrawingHeroFaction],
              gpWindowManager->screenBuffer,
              drawX + 32,
              dword_524D2C + drawY + 31,
              spriteIdx & 0x7F,
              1,
              0,
              0,
              480,
              480,
              0);
            if(curDrawingHeroColor != -1) {
              if(curDrawingHeroFaction == 6)
                FlipIconToBitmap(
                (icon *)this->flagIconsBoat[curDrawingHeroColor],
                  gpWindowManager->screenBuffer,
                  drawX + 32,
                  dword_524D2C + drawY + 31,
                  spriteIdx & 0x7F,
                  1,
                  0,
                  0,
                  480,
                  480,
                  0);
              else
                FlipIconToBitmap(
                (icon *)this->flagIconsHero[curDrawingHeroColor],
                  gpWindowManager->screenBuffer,
                  drawX + 32,
                  drawY + 31,
                  (spriteIdx & 0x7F)
                + (((unsigned __int64)this->field_202 >> 32) ^ abs(this->field_202) & 7)
                - ((unsigned __int64)this->field_202 >> 32)
                + 56,
                  1,
                  0,
                  0,
                  480,
                  480,
                  0);
            }
          }
        } else if(cellDrawingPhaseFlags & 0x80) {
          if(this->field_276 && curDrawingHeroFaction != 6 && cellDrawingPhaseFlags & 0x80)
            IconToBitmap(
              this->shadowIcon,
              gpWindowManager->screenBuffer,
              drawX,
              drawY + 31,
              spriteIdx,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          if(this->field_276 && curDrawingHeroFaction == 6)
            IconToBitmap(
              this->boatShadowIcon,
              gpWindowManager->screenBuffer,
              drawX,
              dword_524D2C + drawY + 31,
              spriteIdx,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
        } else {
          if(curDrawingHeroFaction == 6 && !(currentlyDrawnMapTile->flags & 4))
            IconToBitmap(
              this->frothIcon,
              gpWindowManager->screenBuffer,
              drawX,
              dword_524D2C + drawY + 31,
              spriteIdx,
              1,
              0,
              0,
              0x1E0u,
              480,
              0);
          IconToBitmap(
            (icon *)this->heroIcons[curDrawingHeroFaction],
            gpWindowManager->screenBuffer,
            drawX,
            dword_524D2C + drawY + 31,
            spriteIdx,
            1,
            0,
            0,
            0x1E0u,
            480,
            0);
          if(curDrawingHeroColor != -1) {
            if(curDrawingHeroFaction == 6)
              IconToBitmap(
              (icon *)this->flagIconsBoat[curDrawingHeroColor],
                gpWindowManager->screenBuffer,
                drawX,
                dword_524D2C + drawY + 31,
                spriteIdx & 0x7F,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
            else
              IconToBitmap(
              (icon *)this->flagIconsHero[curDrawingHeroColor],
                gpWindowManager->screenBuffer,
                drawX,
                drawY + 31,
                (spriteIdx & 0x7F)
              + (((unsigned __int64)this->field_202 >> 32) ^ abs(this->field_202) & 7)
              - ((unsigned __int64)this->field_202 >> 32)
              + 56,
                1,
                0,
                0,
                0x1E0u,
                480,
                0);
          }
        }
      }
      if(this->field_272
        && currentlyDrawnMapTile->flags & MAP_CELL_HAS_ACTIVE_HERO
        && (!this->hasDrawnCursor || cellDrawingPhaseFlags & 0x80)
        && this->viewX + 7 == x
        && this->viewY + 7 == y
        && !(cellDrawingPhaseFlags & 0x80)) {
        this->DrawCursorShadow();
        this->DrawCursor();
        this->hasDrawnCursor = 1;
      }
    }
    if(cellDrawingPhaseFlags & 4 || cellDrawingPhaseFlags & 0x40) {
      //if(cellDrawingPhaseFlags & 4 && currentlyDrawnMapTile->objectIndex != 255) {
      //  if((currentlyDrawnMapTile->field_4_3)
      //    && (!gbDrawingPuzzle
      //      || bPuzzleDraw[((unsigned __int8)currentlyDrawnMapTile->objTileset])) {
      //    IconToBitmap(
      //      this->tilesetIcns[((unsigned __int8)currentlyDrawnMapTile->objTileset],
      //      gpWindowManager->screenBuffer,
      //      drawX,
      //      drawY,
      //      currentlyDrawnMapTile->objectIndex,
      //      0,
      //      0,
      //      0,
      //      0x1E0u,
      //      480,
      //      0);
      //    if(currentlyDrawnMapTile->hasObject) {
      //      dword_524CE4 = GetIconEntry(
      //        this->tilesetIcns[((unsigned __int8)currentlyDrawnMapTile->objTileset],
      //                       currentlyDrawnMapTile->objectIndex)->someSortOfLength & 0x1F;
      //      IconToBitmap(
      //        this->tilesetIcns[((unsigned __int8)currentlyDrawnMapTile->objTileset],
      //        gpWindowManager->screenBuffer,
      //        drawX,
      //        drawY,
      //        currentlyDrawnMapTile->objectIndex + this->field_202 % dword_524CE4 + 1,
      //        0,
      //        0,
      //        0,
      //        0x1E0u,
      //        480,
      //        0);
      //    }
      //  }
      //  if(currentlyDrawnMapTile->extraIdx
      //    //&& *(&this->map->cellExtras->objectIndex + 8 * currentlyDrawnMapTile->extraIdx - currentlyDrawnMapTile->extraIdx) != 255)
      //    && this->map->cellExtras->objectIndex != 255)
      //    currentlyDrawingMapCellExtra = (mapCellExtra *)((char *)this->map->cellExtras
      //                                                  + 8 * currentlyDrawnMapTile->extraIdx
      //                                                  - currentlyDrawnMapTile->extraIdx);
      //  else
      //    currentlyDrawingMapCellExtra = 0;
      //  while(currentlyDrawingMapCellExtra) {
      //    if(((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 2) & 1
      //      && (!gbDrawingPuzzle || bPuzzleDraw[currentlyDrawingMapCellExtra->objTileset])) {
      //      IconToBitmap(
      //        this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
      //        gpWindowManager->screenBuffer,
      //        drawX,
      //        drawY,
      //        currentlyDrawingMapCellExtra->objectIndex,
      //        0,
      //        0,
      //        0,
      //        0x1E0u,
      //        480,
      //        0);
      //      if(currentlyDrawingMapCellExtra->hasObject) {
      //        dword_524CE4 = GetIconEntry(
      //          this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
      //                         currentlyDrawingMapCellExtra->objectIndex)->someSortOfLength & 0x1F;
      //        IconToBitmap(
      //          this->tilesetIcns[currentlyDrawingMapCellExtra->objTileset],
      //          gpWindowManager->screenBuffer,
      //          drawX,
      //          drawY,
      //          currentlyDrawingMapCellExtra->objectIndex + this->field_202 % dword_524CE4 + 1,
      //          0,
      //          0,
      //          0,
      //          0x1E0u,
      //          480,
      //          0);
      //      }
      //    }
      //    if(currentlyDrawingMapCellExtra->nextIdx
      //      //&& *(&this->map->cellExtras->objectIndex + 8 * currentlyDrawingMapCellExtra->nextIdx - currentlyDrawingMapCellExtra->nextIdx) != 255)
      //      && this->map->cellExtras->objectIndex != 255)
      //      currentlyDrawingMapCellExtra = (mapCellExtra *)((char *)this->map->cellExtras
      //                                                    + 8 * currentlyDrawingMapCellExtra->nextIdx
      //                                                    - currentlyDrawingMapCellExtra->nextIdx);
      //    else
      //      currentlyDrawingMapCellExtra = 0;
      //  }
      //}
      //if(currentlyDrawnMapTile->overlayIndex != 255
      //  && (cellDrawingPhaseFlags & 4
      //    && !(((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 1) & 1)
      //    || cellDrawingPhaseFlags & 0x40
      //    && ((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 1) & 1)) {
      //  if(!gbDrawingPuzzle
      //    || bPuzzleDraw[((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 2) & 0x3F]) {
      //    IconToBitmap(
      //      this->tilesetIcns[((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 2) & 0x3F],
      //      gpWindowManager->screenBuffer,
      //      drawX,
      //      drawY,
      //      currentlyDrawnMapTile->overlayIndex,
      //      (((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 2) & 0x3F) == 14,
      //      0,
      //      0,
      //      0x1E0u,
      //      480,
      //      0);
      //    if(currentlyDrawnMapTile->overlayTileset & 1) {
      //      dword_524CE4 = GetIconEntry(
      //        this->tilesetIcns[((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 2) & 0x3F],
      //                       currentlyDrawnMapTile->overlayIndex)->someSortOfLength & 0x1F;
      //      IconToBitmap(
      //        this->tilesetIcns[((unsigned __int8)currentlyDrawnMapTile->overlayTileset >> 2) & 0x3F],
      //        gpWindowManager->screenBuffer,
      //        drawX,
      //        drawY,
      //        currentlyDrawnMapTile->overlayIndex + this->field_202 % dword_524CE4 + 1,
      //        0,
      //        0,
      //        0,
      //        0x1E0u,
      //        480,
      //        0);
      //    }
      //  }
      //}
      //if(currentlyDrawnMapTile->extraIdx
      //  // && *(&this->map->cellExtras->tileset + 8 * currentlyDrawnMapTile->extraIdx - currentlyDrawnMapTile->extraIdx) != 255)
      //  && this->map->cellExtras->tileset != 255)
      //  currentlyDrawingMapCellExtra = (mapCellExtra *)((char *)this->map->cellExtras
      //                                                + 8 * currentlyDrawnMapTile->extraIdx
      //                                                - currentlyDrawnMapTile->extraIdx);
      //else
      //  currentlyDrawingMapCellExtra = 0;
      //while(currentlyDrawingMapCellExtra) {
      //  if(cellDrawingPhaseFlags & 4
      //    && !(((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 1) & 1)
      //    || cellDrawingPhaseFlags & 0x40
      //    && ((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 1) & 1) {
      //    if(!gbDrawingPuzzle
      //      || bPuzzleDraw[((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 2) & 0x3F]) {
      //      IconToBitmap(
      //        this->tilesetIcns[((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 2) & 0x3F],
      //        gpWindowManager->screenBuffer,
      //        drawX,
      //        drawY,
      //        currentlyDrawingMapCellExtra->tileset,
      //        (((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 2) & 0x3F) == 14,
      //        0,
      //        0,
      //        0x1E0u,
      //        480,
      //        0);
      //      if(currentlyDrawingMapCellExtra->animatedObject) {
      //        dword_524CE4 = GetIconEntry(
      //          this->tilesetIcns[((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 2) & 0x3F],
      //                         currentlyDrawingMapCellExtra->tileset)->someSortOfLength & 0x1F;
      //        IconToBitmap(
      //          this->tilesetIcns[((unsigned __int8)currentlyDrawingMapCellExtra->tileset >> 2) & 0x3F],
      //          gpWindowManager->screenBuffer,
      //          drawX,
      //          drawY,
      //          currentlyDrawingMapCellExtra->tileset + this->field_202 % dword_524CE4 + 1,
      //          0,
      //          0,
      //          0,
      //          0x1E0u,
      //          480,
      //          0);
      //      }
      //    }
      //  }
      //  if(currentlyDrawingMapCellExtra->nextIdx
      //    //&& *(&this->map->cellExtras->tileset + 8 * currentlyDrawingMapCellExtra->nextIdx- currentlyDrawingMapCellExtra->nextIdx) != 255)
      //    && this->map->cellExtras->tileset != 255)
      //    currentlyDrawingMapCellExtra = (mapCellExtra *)((char *)this->map->cellExtras
      //                                                  + 8 * currentlyDrawingMapCellExtra->nextIdx
      //                                                  - currentlyDrawingMapCellExtra->nextIdx);
      //  else
      //    currentlyDrawingMapCellExtra = 0;
      //}
    }
  } else if(dword_524CF8) { // Draw Terra Incognita borders
    if(dword_524CD4)
      FlipIconToBitmap(this->clopIcon, gpWindowManager->screenBuffer, drawX + 31, drawY, dword_524D24 - 1, 0, 0, 0, 0, 0, 0);
    else
      IconToBitmap(this->clopIcon, gpWindowManager->screenBuffer, drawX, drawY, dword_524D24 - 1, 0, 0, 0, 0, 0, 0);
  } else if(this->field_A2 && *(unsigned short *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated)) {
    if((*(unsigned short *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) >> 8) & 1)
      IconToBitmapColorTable(this->tilesetIcns[17], gpWindowManager->screenBuffer, drawX - 12, drawY + 2,
        (unsigned __int8)(*(unsigned short *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) - 1),
        1, 0, 0, 0x1E0u, 480, 0, gColorTableRed, 1);
    else
      IconToBitmap(this->tilesetIcns[17], gpWindowManager->screenBuffer, drawX - 12, drawY + 2,
        (unsigned __int8)(*(unsigned short *)(2 * x + 2 * MAP_WIDTH * y + this->sizeOfSomethingMapRelated) - 1),
        1, 0, 0, 0x1E0u, 480, 0);
  }

}