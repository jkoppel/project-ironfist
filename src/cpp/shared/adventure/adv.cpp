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

  tag_message evt;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  for(int j = 0; j < 4; ++j) {
    int townID = *(&gpCurPlayer->castlesOwned[j] + gpCurPlayer->relatedToUnknown);
    evt.xCoordOrKeycode = 8;
    evt.yCoordOrFieldID = j + 32;
    if(gpCurPlayer->mightBeCurCastleIdx == -1 || gpCurPlayer->mightBeCurCastleIdx != townID || gbAllBlack)
      evt.payload = (void *)36;
    else
      evt.payload = (void *)153;
    this->adventureScreen->BroadcastMessage(evt);
    evt.yCoordOrFieldID = j + 16;
    if(townID == -1 || gbAllBlack) {
      evt.xCoordOrKeycode = 4;
      evt.payload = (void *)(j + 5);
      this->adventureScreen->BroadcastMessage(evt);
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)2;
      this->adventureScreen->BroadcastMessage(evt);
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
      evt.yCoordOrFieldID = j + 300;
      this->adventureScreen->BroadcastMessage(evt);
    } else {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)2;
      this->adventureScreen->BroadcastMessage(evt);
      evt.xCoordOrKeycode = 4;
      int faction = gpGame->castles[townID].factionID;
      evt.payload = (void *)castleIconFrames[faction];
      if(!(gpGame->castles[townID].buildingsBuiltFlags & 0x40))
          evt.payload = (char *)townIconFrames[faction];
      this->adventureScreen->BroadcastMessage(evt);

      if(BitTest((const LONG*)gpGame->builtToday, townID))
        evt.xCoordOrKeycode = 5;
      else
        evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
      evt.yCoordOrFieldID = j + 300;
      this->adventureScreen->BroadcastMessage(evt);
    }
  }
  this->castleScrollbarKnob->offsetY = gpCurPlayer->numCastles >= 5 ? (unsigned __int16)(signed __int64)((double)gpCurPlayer->relatedToUnknown * 74.0 / (double)((signed int)gpCurPlayer->numCastles - 4) + 195.0) : 232;
  if(a2)
    this->adventureScreen->DrawWindow(updateScreen);
}

void advManager::TownQuickView(int townID, int _104, int xOff, int a3) {
  int v5; // eax@19
  char *v6; // eax@24
  __int16 v7; // ST14_2@57
  int v8; // ebx@57
  int v9; // ST04_4@57
  int v10; // ebx@57
  IconEntry *v11; // eax@57
  char *v12; // eax@64
  __int16 v13; // ST14_2@78
  int v14; // ebx@78
  int v15; // ST04_4@78
  int v16; // ebx@78
  IconEntry *v17; // eax@78
  char *v18; // eax@85
  textWidget *v20; // [sp+1Ch] [bp-DCh]@87
  iconWidget *v21; // [sp+20h] [bp-D8h]@77
  textWidget *v22; // [sp+24h] [bp-D4h]@66
  iconWidget *v23; // [sp+28h] [bp-D0h]@56
  textWidget *v24; // [sp+2Ch] [bp-CCh]@34
  signed int v26; // [sp+34h] [bp-C4h]@41
  signed int v27; // [sp+38h] [bp-C0h]@40
  int v28; // [sp+38h] [bp-C0h]@73
  int v29; // [sp+3Ch] [bp-BCh]@48
  int v30; // [sp+40h] [bp-B8h]@48
  int v31; // [sp+40h] [bp-B8h]@73
  int v32; // [sp+44h] [bp-B4h]@48
  char *v33[4]; // [sp+4Ch] [bp-ACh]@61
  int v34; // [sp+60h] [bp-98h]@48
  int v35; // [sp+64h] [bp-94h]@41
  int imgIdx; // [sp+68h] [bp-90h]@56
  iconWidget *iconWidgetArray[5]; // [sp+6Ch] [bp-8Ch]@57
  int v38; // [sp+80h] [bp-78h]@48
  textWidget *textWidgetArray[5]; // [sp+84h] [bp-74h]@67
  char *content; // [sp+98h] [bp-60h]@31
  widget *guiObj; // [sp+9Ch] [bp-5Ch]@35
  __int16 v42; // [sp+A0h] [bp-58h]@1
  __int16 v43; // [sp+A4h] [bp-54h]@1
  tag_message evt; // [sp+A8h] [bp-50h]@16
  icon *res; // [sp+C4h] [bp-34h]@2
  __int16 v46; // [sp+C8h] [bp-30h]@1
  __int16 v47; // [sp+CCh] [bp-2Ch]@1
  int i; // [sp+D0h] [bp-28h]@24
  int v49; // [sp+D4h] [bp-24h]@93
  int v50; // [sp+D8h] [bp-20h]@93
  int thievesGuildsLevel; // [sp+DCh] [bp-1Ch]@11
  __int16 v52; // [sp+E0h] [bp-18h]@1
  heroWindow *window; // [sp+E4h] [bp-14h]@5
  town *town; // [sp+E8h] [bp-10h]@2
  int garrisonCreatures; // [sp+ECh] [bp-Ch]@16
  __int16 v56; // [sp+F0h] [bp-8h]@1
  __int16 v57; // [sp+F4h] [bp-4h]@1

  std::string str;

  v42 = 192;
  v47 = 22;
  v46 = 32;
  v56 = 32;
  v57 = 1;
  v43 = 2;
  v52 = 8;
  if(townID == -1)
    return;
  res = gpResourceManager->GetIcon("mons32.icn");
  town = &gpGame->castles[townID];
  if(xOff == -1) {
    xOff = 328;
    a3 = 176;
  }
  window = new heroWindow(xOff, a3, "qtown1.bin");
  if(!window)
    MemError();
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
  garrisonCreatures = 0;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = 4;
  evt.yCoordOrFieldID = 2;
  evt.payload = (void *)(town->factionID + 9);
  if(!(gpGame->castles[townID].buildingsBuiltFlags & 0x40))
    evt.payload = (char *)evt.payload + 6;
  window->BroadcastMessage(evt);
  if(thievesGuildsLevel != 3 || (v5 = BitTest((const LONG*)gpGame->builtToday, town->idx), !v5)) {
    evt.xCoordOrKeycode = 6;
    evt.yCoordOrFieldID = 300;
    evt.payload = (void *)4;
    window->BroadcastMessage(evt);
  }
  if(town->ownerIdx == -1) {
    evt.xCoordOrKeycode = 6;
    evt.yCoordOrFieldID = 8;
    evt.payload = (void *)4;
    window->BroadcastMessage(evt);
    ++evt.yCoordOrFieldID;
    window->BroadcastMessage(evt);
  } else {
    evt.xCoordOrKeycode = 4;
    evt.yCoordOrFieldID = 8;
    evt.payload = (void *)(2 * gpGame->players[town->ownerIdx].color);
    window->BroadcastMessage(evt);
    ++evt.yCoordOrFieldID;
    evt.payload = (void*)((int)evt.payload + 1);
    window->BroadcastMessage(evt);
  }
  v6 = GetTownName(town->idx);
  sprintf(gText, v6);
  evt.xCoordOrKeycode = 3;
  evt.yCoordOrFieldID = 1;
  evt.payload = gText;
  window->BroadcastMessage(evt);
  garrisonCreatures = 0;
  for(i = 0; i < 5; ++i) {
    if(town->garrison.creatureTypes[i] != -1)
      ++garrisonCreatures;
  }
  if(thievesGuildsLevel && garrisonCreatures) {
    v27 = 76;
    if(garrisonCreatures < 1)
      goto LABEL_43;
    if(garrisonCreatures <= 3) {
      v27 = 98;
      v26 = garrisonCreatures;
      v35 = 0;
    } else {
      if(garrisonCreatures != 4) {
      LABEL_43:
        v26 = 2;
        v35 = 3;
        goto LABEL_48;
      }
      v26 = 2;
      v35 = 2;
    }
  LABEL_48:
    v38 = 0;
    v29 = 0;
    v34 = 192 / v26;
    v30 = (192 / v26 - 32) / 2 + 22;
    v32 = 0;
    for(i = 0; i < v26; ++i) {
      if(garrisonCreatures == 5) {
        if(i)
          v32 = -12;
        else
          v32 = 12;
      }
      while(town->garrison.creatureTypes[v29] == -1)
        ++v29;
      imgIdx = town->garrison.creatureTypes[v29];

      v7 = imgIdx;
      v8 = v27 - GetIconEntry(res, imgIdx)->offsetY;
      v9 = v8 - GetIconEntry(res, imgIdx)->height + 30;
      v10 = v32 + v30 + v34 * v38 - GetIconEntry(res, imgIdx)->offsetX;
      v11 = GetIconEntry(res, imgIdx);
      iconWidgetArray[v38] = new iconWidget(
                                (32 - v11->width) / 2 + v10 + 1,
                                v9,
                                32,
                                32,
                                "mons32.icn",
                                v7,
                                0,
                                -1,
                                16,
                                1);
      if(!iconWidgetArray[v38])
        MemError();

      std::string quantityStr;
      if(thievesGuildsLevel == 3)
        quantityStr = std::to_string(town->garrison.quantities[v29]);
      else if(thievesGuildsLevel == 2)
        quantityStr = this->GetArmySizeName(town->garrison.quantities[v29], 0);
      else
        quantityStr = "???";

      char *charStr = (char*)BaseAlloc(quantityStr.size(), __FILE__, __LINE__);
      charStr = strdup(quantityStr.c_str());

      textWidgetArray[v38] = new textWidget(
                                 v32 + v30 + v34 * v38 - 14,
                                 v27 + 32,
                                 60,
                                 12,
                                 charStr,
                                 "smalfont.fnt",
                                 1,
                                 -1,
                                 512,
                                 1);

      if(!textWidgetArray[v38])
        MemError();
      window->AddWidget((widget *)iconWidgetArray[v38], -1);
      window->AddWidget((widget *)textWidgetArray[v38++], -1);
      ++v29;
    }
    if(v35) {
      v34 = 192 / v35;
      v31 = (192 / v35 - 32) / 2 + 22;
      v28 = v27 + 44;
      for(i = v26; v35 + v26 > i; ++i) {
        while(town->garrison.creatureTypes[v29] == -1)
          ++v29;
        imgIdx = town->garrison.creatureTypes[v29];

        v13 = imgIdx;
        v14 = v28 - GetIconEntry(res, imgIdx)->offsetY;
        v15 = v14 - GetIconEntry(res, imgIdx)->height + 30;
        v16 = v31 + v34 * (v38 - v26) - GetIconEntry(res, imgIdx)->offsetX;
        v17 = GetIconEntry(res, imgIdx);
        iconWidgetArray[v38] = new iconWidget(
                                  (32 - v17->width) / 2 + v16 + 1,
                                  v15,
                                  32,
                                  32,
                                  "mons32.icn",
                                  v13,
                                  0,
                                  -1,
                                  16,
                                  1);

        if(!iconWidgetArray[v38])
          MemError();
        
        std::string quantityStr;
        if(thievesGuildsLevel == 3)
          quantityStr = std::to_string(town->garrison.quantities[v29]);
        else if(thievesGuildsLevel == 2)
          quantityStr = this->GetArmySizeName(town->garrison.quantities[v29], 0);
        else
          quantityStr = "???";

        char *charStr = (char*)BaseAlloc(quantityStr.size(), __FILE__, __LINE__);
        charStr = strdup(quantityStr.c_str());

        textWidgetArray[v38] = new textWidget(
                                  v31 + v34 * (v38 - v26) - 14,
                                  v28 + 32,
                                  60,
                                  12,
                                  charStr,
                                  "smalfont.fnt",
                                  1,
                                  -1,
                                  512,
                                  1);

        if(!textWidgetArray[v38])
          MemError();
        window->AddWidget((widget *)iconWidgetArray[v38], -1);
        window->AddWidget((widget *)textWidgetArray[v38++], -1);
        ++v29;
      }
    }
    goto LABEL_93;
  }
 
  if(thievesGuildsLevel)
    str = "None";
  else
    str = "Unknown";

  char *charStr = (char*)BaseAlloc(str.size(), __FILE__, __LINE__);
        charStr = strdup(str.c_str());

  guiObj = new textWidget(13, 117, 211, 12, charStr, "smalfont.fnt", 1, -1, 512, 1);

  if(!guiObj)
    MemError();
  window->AddWidget(guiObj, -1);
LABEL_93:
  gpWindowManager->AddWindow(window, -1, 1);
  v50 = this->viewX;
  v49 = this->viewY;
  this->viewX = town->x - 7;
  this->viewY = town->y - 7;
  this->UpdateRadar(1, 0);
  QuickViewWait();
  gpWindowManager->RemoveWindow(window);
  delete window;
  this->viewX = v50;
  this->viewY = v49;
  this->UpdateRadar(1, 0);
  this->CompleteDraw(0);
  this->UpdateScreen(0, 0);
  if(evt.eventCode == 8 && town->ownerIdx == giCurPlayer)
    this->SetTownContext(town->idx);
  gpResourceManager->Dispose((resource *)res);
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
