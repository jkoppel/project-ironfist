#include "xml/save_xml.h"

#include "xml/campaign_xml.h"
#include "xml/utils_xml.h"
#include "expansions.h"
#include "game/game.h"
#include "gui/dialog.h"

extern int gbIAmGreatest;
extern int giMonthType;
extern int giMonthTypeExtra;
extern int giWeekType;
extern int giWeekTypeExtra;
extern char cPlayerNames[6][21];
extern int gbRemoteOn;
extern int giThisGamePos;

using namespace UtilsXML;

tinyxml2::XMLError IronfistXML::Save(const char* fileName) {
  tinyxml2::XMLNode * pRoot = tempDoc->NewElement("ironfist_save");
  tempDoc->InsertFirstChild(pRoot);

  PushBack(pRoot, "allowAIArmySharing", gpGame->allowAIArmySharing);
  PushBack(pRoot, "mapWidth", gpGame->map.width);
  PushBack(pRoot, "mapHeight", gpGame->map.height);
  PushBack(pRoot, "gameDifficulty", gpGame->gameDifficulty);
  PushBack(pRoot, "monthType", giMonthType);
  PushBack(pRoot, "monthTypeExtra", giMonthTypeExtra);
  PushBack(pRoot, "weekType", giWeekType);
  PushBack(pRoot, "weekTypeExtra", giWeekTypeExtra);
  PushBack(pRoot, "giMapChangeCtr", giMapChangeCtr);
  PushBack(pRoot, "numPlayers", (int)gpGame->numPlayers);
  PushBack(pRoot, "giCurPlayer", giCurPlayer);
  PushBack(pRoot, "couldBeNumDefeatedPlayers", (int)gpGame->couldBeNumDefeatedPlayers);
  PushBack(pRoot, "day", gpGame->day);
  PushBack(pRoot, "week", gpGame->week);
  PushBack(pRoot, "month", gpGame->month);
  PushBack(pRoot, "numObelisks", (int)gpGame->numObelisks);
  PushBack(pRoot, "ultimateArtifactLocX", (int)gpGame->ultimateArtifactLocX);
  PushBack(pRoot, "ultimateArtifactLocY", (int)gpGame->ultimateArtifactLocY);
  PushBack(pRoot, "ultimateArtifactIdx", (int)gpGame->ultimateArtifactIdx);
  PushBack(pRoot, "currentRumor", gpGame->currentRumor);
  PushBack(pRoot, "numRumors", gpGame->numRumors);
  PushBack(pRoot, "numEvents", gpGame->numEvents);
  PushBack(pRoot, "numMapEvents", gpGame->numMapEvents);
  PushBack(pRoot, "iMaxMapExtra", iMaxMapExtra);
  PushBack(pRoot, "difficulty", (int)gpGame->difficulty);
  PushBack(pRoot, "mapFilename", gpGame->mapFilename);
  PushBack(pRoot, "relatedToNewGameSelection", (int)gpGame->relatedToNewGameSelection);
  PushBack(pRoot, "relatedToNewGameInit", (int)gpGame->relatedToNewGameInit);
  PushBack(pRoot, "numHumanPlayers", (int)gpGame->numHumanPlayers);
  PushBack(pRoot, "gbIAmGreatest", gbIAmGreatest);
  CAMPAIGN_TYPE campaignType = GetCurrentCampaignType();
  PushBack(pRoot, "campaignType", campaignType);

  tinyxml2::XMLElement *pElement;
  if(campaignType) {
    pElement = tempDoc->NewElement("campaign");
    if(campaignType == CAMPAIGN_TYPE_ORIGINAL) {      
      PushBack(pElement, "campID", gpGame->campID);
      PushBack(pElement, "campIDanother", gpGame->campIDanother);
      PushBack(pElement, "campMapID", gpGame->campMapID);
      PushBack(pElement, "campUnknown", gpGame->campUnknown);
      PushBack(pElement, "campDaysPlayedCurrent", gpGame->campDaysPlayedCurrent);
      PushBack(pElement, "campMaybeWon", gpGame->campMaybeWon);
      PushBack(pElement, "campHasCheated", gpGame->campHasCheated);

      WriteCampaignDDArray(pElement, "campMapsWon", gpGame->campMapsWon);
      WriteCampaignDDArray(pElement, "campDaysPlayed", gpGame->campDaysPlayed);
      WriteCampaignDDArray(pElement, "campDaysPlayed2", gpGame->campDaysPlayed2);
      WriteCampaignDDArray(pElement, "campChoices", gpGame->campChoices);
      WriteCampaignDDArray(pElement, "campMapsPlayed", gpGame->campMapsPlayed);

      WriteArray(pElement, "campBonuses", gpGame->campBonuses);
      WriteArray(pElement, "campPlayerCreatures", gpGame->campPlayerCreatures);
      WriteArray(pElement, "campPlayerCreatureQuantities", gpGame->campPlayerCreatureQuantities);
      WriteArray(pElement, "relatedToCampaign", gpGame->relatedToCampaign);
    } else if(campaignType == CAMPAIGN_TYPE_EXPANSION) {
      PushBack(pElement, "campaignID", xCampaign.campaignID);
      PushBack(pElement, "currentMapID", xCampaign.currentMapID);
      PushBack(pElement, "numMaps", xCampaign.numMaps);
      PushBack(pElement, "unknownVariable", xCampaign.unknownVariable);
      PushBack(pElement, "mightBeScenarioID", xCampaign.mightBeScenarioID);
      PushBack(pElement, "window", (int)xCampaign.window);
      PushBack(pElement, "anIntVariable", xCampaign.anIntVariable);

      WriteArray(pElement, "mapChoice", xCampaign.mapChoice);
      WriteArray(pElement, "mapsPlayed", xCampaign.mapsPlayed);
      WriteArray(pElement, "daysPlayed", xCampaign.daysPlayed);
      WriteArray(pElement, "awards", xCampaign.awards);
      WriteArray(pElement, "bonusChoices", xCampaign.bonusChoices);

      // saved hero for autosaved saves
      for (auto &i : gIronfistExtra.campaign.savedHeroData) {
        campaignExtra::partialHeroData *savedHero = &i.second;
        tinyxml2::XMLElement *savedHeroElem = tempDoc->NewElement("savedHero");
        savedHeroElem->SetAttribute("index", i.first);
        WriteArray(savedHeroElem, "primarySkills", savedHero->primarySkills);
        WriteArray(savedHeroElem, "skillIndex", savedHero->skillIndex);
        WriteArray(savedHeroElem, "secondarySkillLevel", savedHero->secondarySkillLevel);
        //WriteArray(savedHeroElem, "artifacts", savedHero->artifacts);
        //WriteArray(savedHeroElem, "scrollSpell", savedHero->scrollSpell);
        for (int j = 0; j < NUM_SPELLS; j++) {
          if(savedHero->spellsLearned[j]) {
            tinyxml2::XMLElement *spellElem = tempDoc->NewElement("spell");
            spellElem->SetAttribute("idx", j);
            savedHeroElem->InsertEndChild(spellElem);
          }
        }
        //for (int j = 0; j < ELEMENTS_IN(savedHero->army.creatureTypes); j++) {
        //  tinyxml2::XMLElement *armyElem = tempDoc->NewElement("army");
        //  //armyElem->SetAttribute("heroIdx", i);
        //  armyElem->SetAttribute("index", j);
        //  armyElem->SetAttribute("type", savedHero->army.creatureTypes[j]);
        //  armyElem->SetAttribute("quantity", savedHero->army.quantities[j]);
        //  savedHeroElem->InsertEndChild(armyElem);
        //}        
        PushBack(savedHeroElem, "numSecSkillsKnown", savedHero->numSecSkillsKnown);
        PushBack(savedHeroElem, "experience", savedHero->experience);

        pElement->InsertEndChild(savedHeroElem);
      }

      int campaignID = xCampaign.campaignID;
      if(campaignID >= 4) {       
         tinyxml2::XMLElement *metadata = tempDoc->NewElement("campaignMetadata");
         PushBack(metadata, "id", campaignID);
         PushBack(metadata, "name", xCampaignNames[campaignID].c_str());
         PushBack(metadata, "shortName", xShortCampaignNames[campaignID].c_str());
         PushBack(metadata, "numMaps", expCampaignNumMaps[campaignID]);
         WriteArray(metadata, "scenarioName", xScenarioName[campaignID]);
         WriteArray(metadata, "scenarioDescription", xScenarioDescription[campaignID]);
         WriteArray(metadata, "scenarioDifficulty", xCampaignDifficulties[campaignID]);

         for(int index = 0u; index < scenarioIconOffsets[campaignID].size(); index++) {
           tinyxml2::XMLElement *icn = tempDoc->NewElement("scenarioIcon");
           icn->SetAttribute("scenarioID", index);
           icn->SetAttribute("x", scenarioIconOffsets[campaignID][index]._x);
           icn->SetAttribute("y", scenarioIconOffsets[campaignID][index]._y);
           metadata->InsertEndChild(icn);
         }

         for(int index = 0u; index < xCampaignChoices[campaignID].size(); index++) {
           for(int choiceID = 0u; choiceID < MAX_CAMPAIGN_CHOICES; choiceID++) {
             tinyxml2::XMLElement *choiceElem = tempDoc->NewElement("choice");
             choiceElem->SetAttribute("scenarioID", index);
             choiceElem->SetAttribute("id", choiceID);
             SCampaignChoice choice = xCampaignChoices[campaignID][index][choiceID];
             choiceElem->SetAttribute("type", choice.type);
             choiceElem->SetAttribute("field", choice.field);
             choiceElem->SetAttribute("amount", choice.amount);
             metadata->InsertEndChild(choiceElem);
           }
         }

         WriteArray(metadata, "replaySMK", replaySMK[campaignID]);
         WriteArray(metadata, "victorySMK", victorySMK[campaignID]);
         WriteArray(metadata, "mapToComplete", mapsToComplete[campaignID]);
         WriteArray(metadata, "award", awardsToGive[campaignID]);

         for(int scenario = 0u; scenario < xCampaignHeroesToSave[campaignID].size(); scenario++) {
           for(auto &heroData : xCampaignHeroesToSave[campaignID][scenario]) {
             tinyxml2::XMLElement *heroElem = tempDoc->NewElement("saveHero");
             heroElem->SetAttribute("scenarioID", scenario);
             heroElem->SetAttribute("playerID", heroData.first);
             heroElem->SetAttribute("ownedHeroID", heroData.second);
             metadata->InsertEndChild(heroElem);
           }
         }

         for(int scenario = 0u; scenario < xCampaignHeroesToLoad[campaignID].size(); scenario++) {
           for(auto &heroData : xCampaignHeroesToLoad[campaignID][scenario]) {
             tinyxml2::XMLElement *heroElem = tempDoc->NewElement("loadHero");
             heroElem->SetAttribute("scenarioID", scenario);
             heroElem->SetAttribute("playerID", heroData.first);
             heroElem->SetAttribute("ownedHeroID", heroData.second);
             metadata->InsertEndChild(heroElem);
           }
         }
         pElement->InsertEndChild(metadata);
      }
    }
    pRoot->InsertEndChild(pElement);
  }

  pElement = tempDoc->NewElement("mapHeader");
  SMapHeader *mh = &gpGame->mapHeader;
  PushBack(pElement, "field_0", mh->field_0);
  PushBack(pElement, "field_4", mh->field_4);
  PushBack(pElement, "width", (unsigned char)mh->width);
  PushBack(pElement, "height", (unsigned char)mh->height);
  PushBack(pElement, "numPlayers", mh->numPlayers);
  PushBack(pElement, "minHumans", mh->minHumans);
  PushBack(pElement, "maxHumans", mh->maxHumans);
  PushBack(pElement, "winConditionType", mh->winConditionType);
  PushBack(pElement, "relatedToWinConditionType", mh->relatedToWinConditionType);
  PushBack(pElement, "allowDefeatAllVictory", mh->allowDefeatAllVictory);
  PushBack(pElement, "winConditionArgumentOrLocX", mh->winConditionArgumentOrLocX);
  PushBack(pElement, "lossConditionType", mh->lossConditionType);
  PushBack(pElement, "lossConditionArgumentOrLocX", mh->lossConditionArgumentOrLocX);
  PushBack(pElement, "field_24", mh->field_24);
  PushBack(pElement, "noStartingHeroInCastle", mh->noStartingHeroInCastle);
  PushBack(pElement, "winConditionArgumentOrLocY", mh->winConditionArgumentOrLocY);
  PushBack(pElement, "lossConditionArgumentOrLocY", mh->lossConditionArgumentOrLocY);
  PushBack(pElement, "relatedToPlayerColorOrSide", mh->relatedToPlayerColorOrSide);
  PushBack(pElement, "field_32", mh->field_32);
  PushBack(pElement, "field_36", mh->field_36);
  PushBack(pElement, "field_37", mh->field_37);
  PushBack(pElement, "nextTownName", mh->nextTownName);
  PushBack(pElement, "field_39", mh->field_39);
  PushBack(pElement, "name", mh->name);
  PushBack(pElement, "description", mh->description);
  PushBack(pElement, "field_1A0", mh->field_1A0);
  PushBack(pElement, "field_1A1", mh->field_1A1);
  PushBack(pElement, "numRumors", mh->numRumors);
  PushBack(pElement, "numEvents", mh->numEvents);
  WriteArray(pElement, "hasPlayer", mh->hasPlayer);
  WriteArray(pElement, "playerMayBeHuman", mh->playerMayBeHuman);
  WriteArray(pElement, "playerMayBeComp", mh->playerMayBeComp);
  WriteArray(pElement, "playerFactions", mh->playerFactions);
  pRoot->InsertEndChild(pElement);

  WriteArray(pRoot, "playerNames", cPlayerNames);
  WriteArray(pRoot, "deadPlayers", gpGame->playerDead);

  char playerAlive[NUM_PLAYERS];
  for (int i = 0; i < NUM_PLAYERS; ++i) {
    playerAlive[i] = gbHumanPlayer[i];
    if (gpGame->playerDead[i])
      playerAlive[i] = 0;
  }

  WriteArray(pRoot, "alivePlayers", playerAlive);
  WriteArray(pRoot, "heroHireStatus", gpGame->heroHireStatus);
  WriteArray(pRoot, "relatedToPlayerPosAndColor", gpGame->relatedToPlayerPosAndColor);
  WriteArray(pRoot, "playerHandicap", gpGame->playerHandicap);
  WriteArray(pRoot, "newGameSelectedFaction", gpGame->newGameSelectedFaction);
  WriteArray(pRoot, "somePlayerCodeOr10IfMayBeHuman", gpGame->somePlayerCodeOr10IfMayBeHuman);
  WriteArray(pRoot, "somePlayerNumData", gpGame->somePlayerNumData);
  WriteArray(pRoot, "field_47C", gpGame->field_47C);
  WriteArray(pRoot, "field_2773", gpGame->field_2773);
  WriteArray(pRoot, "builtToday", gpGame->builtToday);
  WriteArray(pRoot, "field_60A6", gpGame->field_60A6);
  WriteArray(pRoot, "randomArtifacts", SerializeGeneratedArtifacts());
  WriteArray(pRoot, "boatBuilt", gpGame->boatBuilt);
  WriteArray(pRoot, "obeliskVisitedMasks", gpGame->obeliskVisitedMasks);
  WriteArray(pRoot, "field_637D", gpGame->field_637D);
  WriteArray(pRoot, "rumorIndices", gpGame->rumorIndices);
  WriteArray(pRoot, "eventIndices", gpGame->eventIndices);
  WriteArray(pRoot, "mapEventIndices", gpGame->mapEventIndices);

  for (int i = 1; i < iMaxMapExtra; i++) {
    tinyxml2::XMLElement *extraElem = tempDoc->NewElement("mapExtra");
    extraElem->SetAttribute("index", i);
    for (int j = 0; j < pwSizeOfMapExtra[i]; j++) {
      tinyxml2::XMLElement *ppMapExtraElem = tempDoc->NewElement("ppMapExtra");
      //ppMapExtraElem->SetAttribute("index", j);
      if (ppMapExtra[i]) {
        ppMapExtraElem->SetAttribute("value", *((char*)ppMapExtra[i] + j));
      } else {
        ppMapExtraElem->SetAttribute("value", 0);
      }
      extraElem->InsertEndChild(ppMapExtraElem);
    }
    pRoot->InsertEndChild(extraElem);
  }

  for (int i = 0; i < NUM_PLAYERS; i++) {
    playerData *player = &gpGame->players[i];
    tinyxml2::XMLElement *playerElem = tempDoc->NewElement("playerData");
    playerElem->SetAttribute("index", i);

    PushBack(playerElem, "color", player->color);
    PushBack(playerElem, "numHeroes", player->numHeroes);
    PushBack(playerElem, "curHeroIdx", player->curHeroIdx);
    PushBack(playerElem, "relatedToSomeSortOfHeroCountOrIdx", player->relatedToSomeSortOfHeroCountOrIdx);
    PushBack(playerElem, "hasCheated", gpGame->hasCheated);
    PushBack(playerElem, "puzzlePieces", player->puzzlePieces);
    PushBack(playerElem, "personality", player->personality);
    PushBack(playerElem, "relatedToMaxOrNumHeroes", player->relatedToMaxOrNumHeroes);
    PushBack(playerElem, "hasEvilFaction", player->hasEvilFaction);
    PushBack(playerElem, "field_40", player->field_40);
    PushBack(playerElem, "field_41", player->field_41);
    PushBack(playerElem, "daysLeftWithoutCastle", player->daysLeftWithoutCastle);
    PushBack(playerElem, "numCastles", player->numCastles);
    PushBack(playerElem, "mightBeCurCastleIdx", player->mightBeCurCastleIdx);
    PushBack(playerElem, "relatedToUnknown", player->relatedToUnknown);
    PushBack(playerElem, "barrierTentsVisited", player->barrierTentsVisited);

    WriteArray(playerElem, "heroesOwned", player->heroesOwned);
    WriteArray(playerElem, "heroesForPurchase", player->heroesForPurchase);
    WriteArray(playerElem, "castlesOwned", player->castlesOwned);
    WriteArray(playerElem, "resources", player->resources);
    WriteArray(playerElem, "field_E7", player->field_E7);
    WriteArray(playerElem, "_4_2", player->_4_2);

    pRoot->InsertEndChild(playerElem);
  }

  for (int i = 0; i < ELEMENTS_IN(gpGame->castles); i++) {
    town *twn = &gpGame->castles[i];
    tinyxml2::XMLElement *townElem = tempDoc->NewElement("town");
    townElem->SetAttribute("index", i);
    PushBack(townElem, "idx", twn->idx);
    PushBack(townElem, "ownerIdx", twn->ownerIdx);
    PushBack(townElem, "alignment", twn->alignment);
    PushBack(townElem, "factionID", twn->factionID);
    PushBack(townElem, "x", twn->x);
    PushBack(townElem, "y", twn->y);
    PushBack(townElem, "buildDockRelated", twn->buildDockRelated);
    PushBack(townElem, "boatCell", twn->boatCell);
    PushBack(townElem, "visitingHeroIdx", twn->visitingHeroIdx);
    PushBack(townElem, "buildingsBuiltFlags", (int)twn->buildingsBuiltFlags);
    PushBack(townElem, "mageGuildLevel", twn->mageGuildLevel);
    PushBack(townElem, "field_1D", twn->field_1D);
    PushBack(townElem, "exists", twn->exists);
    PushBack(townElem, "mayNotBeUpgradedToCastle", twn->mayNotBeUpgradedToCastle);
    PushBack(townElem, "field_38", twn->field_38);
    PushBack(townElem, "playerPos", twn->playerPos);
    PushBack(townElem, "extraIdx", twn->extraIdx);
    PushBack(townElem, "field_55", twn->field_55);
    PushBack(townElem, "field_63", twn->field_63);
    PushBack(townElem, "name", twn->name);

    WriteArray(townElem, "numCreaturesInDwelling", twn->numCreaturesInDwelling);
    WriteArray(townElem, "numSpellsOfLevel", twn->numSpellsOfLevel);

    for (int j = 0; j < 20; j++) {      
      int x = j % 5;
      int y = j / 5;
      tinyxml2::XMLElement *spellElem = tempDoc->NewElement("mageGuildSpell");
      //spellElem->SetAttribute("townIdx", i);
      spellElem->SetAttribute("level", x);
      spellElem->SetAttribute("idx", y);
      spellElem->SetAttribute("spell",  twn->mageGuildSpells[x][y]);
      townElem->InsertEndChild(spellElem);
    }

    for (int j = 0; j < ELEMENTS_IN(twn->garrison.creatureTypes); j++) {
      tinyxml2::XMLElement *creatElem = tempDoc->NewElement("garrisonCreature");
      creatElem->SetAttribute("index", j);
      //creatElem->SetAttribute("townIdx", i);
      creatElem->SetAttribute("type", twn->garrison.creatureTypes[j]);
      creatElem->SetAttribute("quantity", twn->garrison.quantities[j]);
      townElem->InsertEndChild(creatElem);
    }

    pRoot->InsertEndChild(townElem);
  }

  for(int i = 0; i < ELEMENTS_IN(gpGame->mines); i++) {
    mine *m = &gpGame->mines[i];
    tinyxml2::XMLElement *mineElem = tempDoc->NewElement("mine");
    mineElem->SetAttribute("index", i);
    mineElem->SetAttribute("x", m->x);
    mineElem->SetAttribute("y", m->y);
    mineElem->SetAttribute("field_0", m->field_0);
    mineElem->SetAttribute("owner", m->owner);
    mineElem->SetAttribute("type", m->type);
    mineElem->SetAttribute("guardianType", m->guardianType);
    mineElem->SetAttribute("guardianQty", m->guardianQty);
    pRoot->InsertEndChild(mineElem);
  }

  for(int i = 0; i < ELEMENTS_IN(gpGame->boats); i++) {
    boat *b = &gpGame->boats[i];
    tinyxml2::XMLElement *boatElem = tempDoc->NewElement("boat");
    boatElem->SetAttribute("index", i);
    boatElem->SetAttribute("idx", b->idx);
    boatElem->SetAttribute("x", b->x);
    boatElem->SetAttribute("y", b->y);
    boatElem->SetAttribute("field_3", b->field_3);
    boatElem->SetAttribute("underlyingObjType", b->underlyingObjType);
    boatElem->SetAttribute("underlyingObjExtra", b->underlyingObjExtra);
    boatElem->SetAttribute("field_6", b->field_6);
    boatElem->SetAttribute("owner", b->owner);
    pRoot->InsertEndChild(boatElem);
  }

  pElement = tempDoc->NewElement("map");
  fullMap *map = &gpGame->map;
  pElement->SetAttribute("width", map->width);
  pElement->SetAttribute("height", map->height);
  pElement->SetAttribute("numCellExtras", map->numCellExtras);
  for(int i = 0; i < map->height * map->width; i++) {
    mapCell *c = &map->tiles[i];
    tinyxml2::XMLElement *mapElement = tempDoc->NewElement("mapCell");
    mapElement->SetAttribute("index", i);
    mapElement->SetAttribute("groundIndex", c->groundIndex);
    mapElement->SetAttribute("hasObject", c->hasObject);
    mapElement->SetAttribute("isRoad", c->isRoad);
    mapElement->SetAttribute("objTileset", c->objTileset);
    mapElement->SetAttribute("objectIndex", c->objectIndex);
    mapElement->SetAttribute("field_4_1", c->field_4_1);
    mapElement->SetAttribute("isShadow", c->isShadow);
    mapElement->SetAttribute("field_4_3", c->field_4_3);
    mapElement->SetAttribute("extraInfo", c->extraInfo);
    mapElement->SetAttribute("hasOverlay", c->hasOverlay);
    mapElement->SetAttribute("hasLateOverlay", c->hasLateOverlay);
    mapElement->SetAttribute("overlayTileset", c->overlayTileset);
    mapElement->SetAttribute("overlayIndex", c->overlayIndex);
    mapElement->SetAttribute("flags", c->flags);
    mapElement->SetAttribute("objType", c->objType);
    mapElement->SetAttribute("extraIdx", c->extraIdx);
    pElement->InsertEndChild(mapElement);
  }

  for(int i = 0; i < map->numCellExtras; i++) {
    mapCellExtra *e = &map->cellExtras[i];
    tinyxml2::XMLElement *mapElement = tempDoc->NewElement("mapCellExtra");
    mapElement->SetAttribute("index", i);
    mapElement->SetAttribute("nextIdx", e->nextIdx);
    mapElement->SetAttribute("animatedObject", e->animatedObject);
    mapElement->SetAttribute("objTileset", e->objTileset);
    mapElement->SetAttribute("objectIndex", e->objectIndex);
    mapElement->SetAttribute("field_4_1", e->field_4_1);
    mapElement->SetAttribute("field_4_2", e->field_4_2);
    mapElement->SetAttribute("field_4_3", e->field_4_3);
    mapElement->SetAttribute("field_4_4", e->field_4_4);
    mapElement->SetAttribute("animatedLateOverlay", e->animatedLateOverlay);
    mapElement->SetAttribute("hasLateOverlay", e->hasLateOverlay);
    mapElement->SetAttribute("tileset", e->tileset);
    mapElement->SetAttribute("overlayIndex", e->overlayIndex);
    pElement->InsertEndChild(mapElement);
  }
  pRoot->InsertEndChild(pElement);

  for(int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    tinyxml2::XMLElement *elem = tempDoc->NewElement("mapRevealed");
    elem->SetAttribute("index", i);
    int x = i % MAP_HEIGHT;
    int y = i / MAP_HEIGHT;
    elem->SetAttribute("x", x);
    elem->SetAttribute("y", y);
    elem->SetAttribute("value", mapRevealed[i]);
    pRoot->InsertEndChild(elem);
  }

  for (int i = 0; i < ELEMENTS_IN(gpGame->heroes); i++) {
    hero* hro = &gpGame->heroes[i];
    tinyxml2::XMLElement *heroElement = tempDoc->NewElement("hero");
    heroElement->SetAttribute("index", i);
    PushBack(heroElement, "idx", hro->idx);
    PushBack(heroElement, "spellpoints", hro->spellpoints);
    PushBack(heroElement, "ownerIdx", hro->ownerIdx);
    PushBack(heroElement, "field_4", hro->field_4);
    PushBack(heroElement, "field_5", hro->field_5);
    PushBack(heroElement, "field_6", hro->field_6);
    PushBack(heroElement, "field_7", hro->field_7);
    PushBack(heroElement, "field_8", hro->field_8);
    PushBack(heroElement, "field_9", hro->field_9);
    PushBack(heroElement, "name", hro->name);
    PushBack(heroElement, "experience", hro->experience);
    PushBack(heroElement, "factionID", hro->factionID);
    PushBack(heroElement, "heroID", hro->heroID);
    PushBack(heroElement, "x", hro->x);
    PushBack(heroElement, "y", hro->y);
    PushBack(heroElement, "field_21", hro->field_21);
    PushBack(heroElement, "field_23", hro->field_23);
    PushBack(heroElement, "field_25", hro->field_25);
    PushBack(heroElement, "field_27", hro->field_27);
    PushBack(heroElement, "relatedToX", hro->relatedToX);
    PushBack(heroElement, "relatedToY", hro->relatedToY);
    PushBack(heroElement, "relatedToFactionID", hro->relatedToFactionID);
    PushBack(heroElement, "directionFacing", hro->directionFacing);
    PushBack(heroElement, "occupiedObjType", hro->occupiedObjType);
    PushBack(heroElement, "occupiedObjVal", hro->occupiedObjVal);
    PushBack(heroElement, "mobility", hro->mobility);
    PushBack(heroElement, "remainingMobility", hro->remainingMobility);
    PushBack(heroElement, "oldLevel", hro->oldLevel);
    PushBack(heroElement, "attack", hro->primarySkills[PRIMARY_SKILL_ATTACK]);
    PushBack(heroElement, "defense", hro->primarySkills[PRIMARY_SKILL_DEFENSE]);
    PushBack(heroElement, "spellpower", hro->primarySkills[PRIMARY_SKILL_SPELLPOWER]);
    PushBack(heroElement, "knowledge", hro->primarySkills[PRIMARY_SKILL_KNOWLEDGE]);
    PushBack(heroElement, "field_43", hro->field_43);
    PushBack(heroElement, "tempMoraleBonuses", hro->tempMoraleBonuses);
    PushBack(heroElement, "tempLuckBonuses", hro->tempLuckBonuses);
    PushBack(heroElement, "field_46", hro->field_46);
    PushBack(heroElement, "gazeboesVisited", hro->gazeboesVisited);
    PushBack(heroElement, "fortsVisited", hro->fortsVisited);
    PushBack(heroElement, "witchDoctorHutsVisited", hro->witchDoctorHutsVisited);
    PushBack(heroElement, "mercenaryCampsVisited", hro->mercenaryCampsVisited);
    PushBack(heroElement, "standingStonesVisited", hro->standingStonesVisited);
    PushBack(heroElement, "treesOfKnowledgeVisited", hro->treesOfKnowledgeVisited);
    PushBack(heroElement, "xanadusVisited", hro->xanadusVisited);
    PushBack(heroElement, "randomSeed", hro->randomSeed);
    PushBack(heroElement, "wisdomLastOffered", hro->wisdomLastOffered);
    PushBack(heroElement, "numSecSkillsKnown", hro->numSecSkillsKnown);
    PushBack(heroElement, "flags", hro->flags);
    PushBack(heroElement, "isCaptain", hro->isCaptain);
    PushBack(heroElement, "field_E8", hro->field_E8);

    for (int j = 0; j < ELEMENTS_IN(hro->army.creatureTypes); j++) {
      tinyxml2::XMLElement *armyElem = tempDoc->NewElement("army");
      //armyElem->SetAttribute("heroIdx", i);
      armyElem->SetAttribute("index", j);
      armyElem->SetAttribute("type", hro->army.creatureTypes[j]);
      armyElem->SetAttribute("quantity", hro->army.quantities[j]);
      heroElement->InsertEndChild(armyElem);
    }
    
    for (int j = 0; j < ELEMENTS_IN(hro->secondarySkillLevel); j++) {
      tinyxml2::XMLElement *ssElem = tempDoc->NewElement("secondarySkill");
      //ssElem->SetAttribute("heroIdx", i);
      ssElem->SetAttribute("index", j);
      ssElem->SetAttribute("level", hro->secondarySkillLevel[j]);
      ssElem->SetAttribute("idx", hro->skillIndex[j]);
      heroElement->InsertEndChild(ssElem);
    }

    for (int j = 0; j < NUM_SPELLS; j++) {
      if(hro->spellsLearned[j]) {
        tinyxml2::XMLElement *spellElem = tempDoc->NewElement("spell");
        //spellElem->SetAttribute("heroIdx", i);
        spellElem->SetAttribute("idx", j);
        heroElement->InsertEndChild(spellElem);
      }
    }

    for (int j = 0; j < ELEMENTS_IN(hro->artifacts); j++) {
      tinyxml2::XMLElement *artElem = tempDoc->NewElement("artifact");
      //artElem->SetAttribute("heroIdx", i);
      artElem->SetAttribute("index", j);
      artElem->SetAttribute("id", hro->artifacts[j]);
      artElem->SetAttribute("spell", hro->scrollSpell[j]);
      heroElement->InsertEndChild(artElem);
    }
    pRoot->InsertEndChild(heroElement);
  }

  WriteMapVariables(pRoot);
  std::string script = GetScriptContents();
  if(script.length())
    PushBack(pRoot, "script", script.c_str());
  return tempDoc->SaveFile(fileName);
}

tinyxml2::XMLError IronfistXML::Read(const char* fileName) {
  tinyxml2::XMLError eResult = tempDoc->LoadFile(fileName);
  if(!eResult) {
    tinyxml2::XMLNode *pRoot = tempDoc->FirstChild();
    ReadRoot(pRoot);
  }
  return eResult;
}

luaTable* IronfistXML::ReadTable(tinyxml2::XMLNode *root) {
  luaTable *lt = new luaTable;

  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    if(name == "table") {
      mapVariable *mapVar = new mapVariable;
      mapVar->type = MAPVAR_TYPE_TABLE;
      mapVar->tableValue = ReadTable(elem);
      std::string tableId = elem->Attribute("tableId");
      (*lt)[tableId] = *mapVar;
    }
    else if(name == "tableElement")
      this->ReadTableElement(elem, lt);
  }
  return lt;
}

void IronfistXML::ReadTableElement(tinyxml2::XMLElement *elem, luaTable *lt) {
  mapVariable *mapVar = new mapVariable;
  mapVar->type = StringToMapVarType(elem->Attribute("type"));
  std::string *sV = new std::string(elem->Attribute("value"));
  mapVar->singleValue = sV;
  (*lt)[elem->Attribute("key")] = *mapVar;
}

void IronfistXML::WriteMapVarTable(tinyxml2::XMLNode *dest, std::string id, luaTable *lt) {
  tinyxml2::XMLElement *tableElem = tempDoc->NewElement("table");
  tableElem->SetAttribute("tableId", id.c_str());

  for (luaTable::const_iterator it = (*lt).begin(); it != (*lt).end(); ++it) {
    tinyxml2::XMLElement *elem = tableElem;
    if (it->second.type == MAPVAR_TYPE_TABLE) {
      WriteMapVarTable(tableElem, it->first, it->second.tableValue);
    } else {
      elem = tempDoc->NewElement("tableElement");
      elem->SetAttribute("key", it->first.c_str());
      elem->SetAttribute("type", MapVarTypeToString(it->second.type).c_str());
      elem->SetAttribute("value", (*it->second.singleValue).c_str());
    }
    tableElem->InsertEndChild(elem);
  }
  dest->InsertEndChild(tableElem);
}

void IronfistXML::WriteMapVariables(tinyxml2::XMLNode *dest) {
  std::map<std::string, mapVariable> mapVariables = LoadMapVariablesFromLUA();
  if(!mapVariables.size())
    return;

  for (int i = 0; i != MAX_HEROES; ++i) {
    for (int j = 0; j != MAX_HEROES; ++j) {
      if (gpGame->forcedComputerPlayerChases[i][j]) {
        std::string mapVariableId = "_AICHASE_" + std::to_string(i) + "_" + std::to_string(j) + "_";
        mapVariable mapVar;
        mapVar.singleValue = nullptr;
        mapVar.type = MAPVAR_TYPE_BOOLEAN;
        mapVariables[mapVariableId] = mapVar;
        mapVariables[mapVariableId].type = MAPVAR_TYPE_BOOLEAN;
        mapVariables[mapVariableId].singleValue = new std::string("true");
      }
    }
  }
  for (std::map<std::string, mapVariable>::const_iterator it = mapVariables.begin(); it != mapVariables.end(); ++it) {
    tinyxml2::XMLElement *elem = tempDoc->NewElement("mapVariable");
    elem->SetAttribute("id", it->first.c_str());
    elem->SetAttribute("type", MapVarTypeToString(it->second.type).c_str());
    if (isTable(it->second.type)) {
      WriteMapVarTable(elem, it->first, it->second.tableValue);
    } else if (isStringNumBool(it->second.type)) {
      elem->SetAttribute("value", (*it->second.singleValue).c_str());
    } else {
      DisplayError("Wrong Type created by GetMapVariables", "In function SaveMapVariables");
    }
    dest->InsertEndChild(elem);
  }
}

void IronfistXML::ReadCampaign(tinyxml2::XMLNode* root, CAMPAIGN_TYPE campaignType) {
  gIronfistExtra.campaign.savedHeroData.clear();
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(campaignType == CAMPAIGN_TYPE_ORIGINAL) {
      if(name == "campID") QueryCharText(elem, &gpGame->campID);
      else if(name == "campIDanother") QueryCharText(elem, &gpGame->campIDanother);
      else if(name == "campMapID") QueryCharText(elem, &gpGame->campMapID);
      else if(name == "campUnknown") QueryCharText(elem, &gpGame->campUnknown);
      else if(name == "campDaysPlayedCurrent") QueryShortText(elem, &gpGame->campDaysPlayedCurrent);
      else if(name == "campMaybeWon") QueryCharText(elem, &gpGame->campMaybeWon);
      else if(name == "campHasCheated") QueryCharText(elem, &gpGame->campHasCheated);
      else if(name == "campMapsWon") gpGame->campMapsWon[elem->IntAttribute("campID")][elem->IntAttribute("mapID")] = value;
      else if(name == "campDaysPlayed") gpGame->campDaysPlayed[elem->IntAttribute("campID")][elem->IntAttribute("mapID")] = value;
      else if(name == "campDaysPlayed2") gpGame->campDaysPlayed2[elem->IntAttribute("campID")][elem->IntAttribute("mapID")] = value;
      else if(name == "campChoices") gpGame->campChoices[elem->IntAttribute("campID")][elem->IntAttribute("mapID")] = value;
      else if(name == "campMapsPlayed") gpGame->campMapsPlayed[elem->IntAttribute("campID")][elem->IntAttribute("mapID")] = value;
      else if(name == "campBonuses") gpGame->campBonuses[index] = value;
      else if(name == "campPlayerCreatures") gpGame->campPlayerCreatures[index] = value;
      else if(name == "campPlayerCreatureQuantities") gpGame->campPlayerCreatureQuantities[index] = value;
      else if(name == "relatedToCampaign") gpGame->relatedToCampaign[index] = value;
    } else if(campaignType == CAMPAIGN_TYPE_EXPANSION) {
      if(name == "campaignID") elem->QueryIntText(&xCampaign.campaignID);
      else if(name == "currentMapID") elem->QueryIntText(&xCampaign.currentMapID);
      else if(name == "numMaps") elem->QueryIntText(&xCampaign.numMaps);
      else if(name == "unknownVariable") elem->QueryIntText(&xCampaign.unknownVariable);
      else if(name == "mightBeScenarioID") elem->QueryIntText(&xCampaign.mightBeScenarioID);
      else if(name == "window") elem->QueryIntText((int*)&xCampaign.window);
      else if(name == "anIntVariable") elem->QueryIntText(&xCampaign.anIntVariable);
      else if(name == "mapChoice") xCampaign.mapChoice[index] = value;
      else if(name == "mapsPlayed") xCampaign.mapsPlayed[index] = value;
      else if(name == "daysPlayed") xCampaign.daysPlayed[index] = value;
      else if(name == "awards") xCampaign.awards[index] = value;
      else if(name == "bonusChoices") xCampaign.bonusChoices[index] = value;
      else if(name == "savedHero") ReadCampaignSavedHero(elem);
      else if(name == "campaignMetadata") ReadCampaignMetadata(child);
    }
  }
}

void IronfistXML::ReadCampaignSavedHero(tinyxml2::XMLNode* root) {
  int savedHeroIdx = root->ToElement()->IntAttribute("index");
  campaignExtra::partialHeroData *savedHero = &gIronfistExtra.campaign.savedHeroData[savedHeroIdx];
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "primarySkills") savedHero->primarySkills[index] = value;
    if(name == "skillIndex") savedHero->skillIndex[index] = value;
    if(name == "secondarySkillLevel") savedHero->secondarySkillLevel[index] = value;
    //if(name == "artifacts") savedHero->artifacts[index] = value;
    //if(name == "scrollSpell") savedHero->scrollSpell[index] = value;
    if(name == "spell") savedHero->spellsLearned[elem->IntAttribute("idx")] = 1;
    else if(name == "numSecSkillsKnown") elem->QueryIntText(&savedHero->numSecSkillsKnown);
    /*else if(name == "army") {
      savedHero->army.creatureTypes[index] = elem->IntAttribute("type");
      savedHero->army.quantities[index] = elem->IntAttribute("quantity");
    }*/
    else if(name == "experience") elem->QueryIntText(&savedHero->experience);
  }
}

void IronfistXML::ReadMapHeader(tinyxml2::XMLNode* root) {
  SMapHeader *mh = &gpGame->mapHeader;
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "field_0") elem->QueryIntText(&mh->field_0);
    else if(name == "field_4") QueryShortText(elem, &mh->field_4);
    else if(name == "width") QueryCharText(elem, &mh->width);
    else if(name == "height") QueryCharText(elem, &mh->height);
    else if(name == "numPlayers") QueryCharText(elem, &mh->numPlayers);
    else if(name == "minHumans") QueryCharText(elem, &mh->minHumans);
    else if(name == "maxHumans") QueryCharText(elem, &mh->maxHumans);
    else if(name == "winConditionType") QueryCharText(elem, &mh->winConditionType);
    else if(name == "relatedToWinConditionType") QueryCharText(elem, &mh->relatedToWinConditionType);
    else if(name == "allowDefeatAllVictory") QueryCharText(elem, &mh->allowDefeatAllVictory);
    else if(name == "winConditionArgumentOrLocX") QueryShortText(elem, &mh->winConditionArgumentOrLocX);
    else if(name == "lossConditionType") QueryCharText(elem, &mh->lossConditionType);
    else if(name == "lossConditionArgumentOrLocX") QueryCharText(elem, &mh->lossConditionArgumentOrLocX);
    else if(name == "field_24") QueryCharText(elem, &mh->field_24);
    else if(name == "noStartingHeroInCastle") QueryCharText(elem, &mh->noStartingHeroInCastle);
    else if(name == "winConditionArgumentOrLocY") QueryShortText(elem, &mh->winConditionArgumentOrLocY);
    else if(name == "lossConditionArgumentOrLocY") QueryShortText(elem, &mh->lossConditionArgumentOrLocY);
    else if(name == "relatedToPlayerColorOrSide") QueryShortText(elem, &mh->relatedToPlayerColorOrSide);
    else if(name == "field_32") elem->QueryIntText(&mh->field_32);
    else if(name == "field_36") QueryCharText(elem, &mh->field_36);
    else if(name == "field_37") QueryCharText(elem, &mh->field_37);
    else if(name == "nextTownName") QueryCharText(elem, &mh->nextTownName);
    else if(name == "field_39") QueryCharText(elem, &mh->field_39);
    else if(name == "name") QueryText(elem, mh->name);
    else if(name == "description") QueryText(elem, mh->description);
    else if(name == "field_1A0") QueryCharText(elem, &mh->field_1A0);
    else if(name == "field_1A1") QueryCharText(elem, &mh->field_1A1);
    else if(name == "numRumors") QueryCharText(elem, &mh->numRumors);
    else if(name == "numEvents") QueryCharText(elem, &mh->numEvents);
    else if(name == "hasPlayer") mh->hasPlayer[index] = value;
    else if(name == "playerMayBeHuman") mh->playerMayBeHuman[index] = value;
    else if(name == "playerMayBeComp") mh->playerMayBeComp[index] = value;
    else if(name == "playerFactions") mh->playerFactions[index] = value;
  }
}

void IronfistXML::ReadMap(tinyxml2::XMLNode* root) {
  gpGame->map.width = root->ToElement()->IntAttribute("width");
  gpGame->map.height = root->ToElement()->IntAttribute("height");
  gpGame->map.Init(gpGame->map.width, gpGame->map.height); 

  gpGame->map.numCellExtras = root->ToElement()->IntAttribute("numCellExtras");
  if (gpGame->map.numCellExtras)
    delete(gpGame->map.cellExtras);
  gpGame->map.cellExtras = (mapCellExtra *)operator new(7 * gpGame->map.numCellExtras);

  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    auto nam = elem->Name();
    int index = elem->IntAttribute("index");
    if("mapCell" == std::string(nam)) {
      mapCell *cell = &gpGame->map.tiles[index];
      cell->groundIndex = elem->IntAttribute("groundIndex");
      cell->hasObject = elem->IntAttribute("hasObject");
      cell->isRoad = elem->IntAttribute("isRoad");
      cell->objTileset = elem->IntAttribute("objTileset");
      cell->objectIndex = elem->IntAttribute("objectIndex");
      cell->field_4_1 = elem->IntAttribute("field_4_1");
      cell->isShadow = elem->IntAttribute("isShadow");
      cell->field_4_3 = elem->IntAttribute("field_4_3");
      cell->extraInfo = elem->IntAttribute("extraInfo");
      cell->hasOverlay = elem->IntAttribute("hasOverlay");
      cell->hasLateOverlay = elem->IntAttribute("hasLateOverlay");
      cell->overlayTileset = elem->IntAttribute("overlayTileset");
      cell->overlayIndex = elem->IntAttribute("overlayIndex");
      cell->flags = elem->IntAttribute("flags");
      cell->objType = elem->IntAttribute("objType");
      cell->extraIdx = elem->IntAttribute("extraIdx");
    } else if("mapCellExtra" == std::string(nam)) {
      mapCellExtra *ext = &gpGame->map.cellExtras[index];
      ext->nextIdx = elem->IntAttribute("nextIdx");
      ext->animatedObject = elem->IntAttribute("animatedObject");
      ext->objTileset = elem->IntAttribute("objTileset");
      ext->objectIndex = elem->IntAttribute("objectIndex");
      ext->field_4_1 = elem->IntAttribute("field_4_1");
      ext->field_4_2 = elem->IntAttribute("field_4_2");
      ext->field_4_3 = elem->IntAttribute("field_4_3");
      ext->field_4_4 = elem->IntAttribute("field_4_4");
      ext->animatedLateOverlay = elem->IntAttribute("animatedLateOverlay");
      ext->hasLateOverlay = elem->IntAttribute("hasLateOverlay");
      ext->tileset = elem->IntAttribute("tileset");
      ext->overlayIndex = elem->IntAttribute("overlayIndex");
    }
  }
}

void IronfistXML::ReadMapExtra(tinyxml2::XMLNode* root) {
  int size = 0;
  int index = root->ToElement()->IntAttribute("index");
  std::vector<int> values;
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    auto nam = elem->Name();
    if("ppMapExtra" == std::string(nam)) {
      values.push_back(elem->IntAttribute("value"));
      size++;
    }
  }

  pwSizeOfMapExtra[index] = size;
  ppMapExtra[index] = ALLOC(pwSizeOfMapExtra[index]);

  for (int j = 0; j < pwSizeOfMapExtra[index]; j++) {
    *((char*)ppMapExtra[index] + j) = (char)values.at(j);
  }
}

void IronfistXML::ReadPlayerData(tinyxml2::XMLNode* root, int dataIndex) {
  playerData *pdata = &gpGame->players[dataIndex];
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "color") QueryCharText(elem, &pdata->color);
    else if(name == "numHeroes") QueryCharText(elem, &pdata->numHeroes);
    else if(name == "curHeroIdx") QueryCharText(elem, &pdata->curHeroIdx);
    else if(name == "relatedToSomeSortOfHeroCountOrIdx") QueryCharText(elem, &pdata->relatedToSomeSortOfHeroCountOrIdx);
    else if(name == "hasCheated") QueryCharText(elem, &gpGame->hasCheated);
    else if(name == "puzzlePieces") QueryCharText(elem, &pdata->puzzlePieces);
    else if(name == "personality") elem->QueryIntText(&pdata->personality);
    else if(name == "relatedToMaxOrNumHeroes") QueryCharText(elem, &pdata->relatedToMaxOrNumHeroes);
    else if(name == "hasEvilFaction") QueryCharText(elem, &pdata->hasEvilFaction);
    else if(name == "field_40") QueryCharText(elem, &pdata->field_40);
    else if(name == "field_41") QueryShortText(elem, &pdata->field_41);
    else if(name == "daysLeftWithoutCastle") QueryCharText(elem, &pdata->daysLeftWithoutCastle);
    else if(name == "numCastles") QueryCharText(elem, &pdata->numCastles);
    else if(name == "mightBeCurCastleIdx") QueryCharText(elem, &pdata->mightBeCurCastleIdx);
    else if(name == "relatedToUnknown") QueryCharText(elem, &pdata->relatedToUnknown);
    else if(name == "barrierTentsVisited") QueryCharText(elem, &pdata->barrierTentsVisited);
    else if(name == "heroesOwned") pdata->heroesOwned[index] = value;
    else if(name == "heroesForPurchase") pdata->heroesForPurchase[index] = value;
    else if(name == "castlesOwned") pdata->castlesOwned[index] = value;
    else if(name == "resources") pdata->resources[index] = value;
    else if(name == "field_E7") pdata->field_E7[index] = value;
    else if(name == "_4_2") pdata->_4_2[index] = value;
  }
}

void IronfistXML::ReadHero(tinyxml2::XMLNode* root, int heroIndex) {
  hero* hro = &gpGame->heroes[heroIndex];
  hro->Clear();
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "idx") QueryCharText(elem, &hro->idx);
    else if(name == "spellpoints") QueryShortText(elem, &hro->spellpoints);
    else if(name == "ownerIdx") QueryCharText(elem, &hro->ownerIdx);
    else if(name == "field_4") QueryCharText(elem, &hro->field_4);
    else if(name == "field_5") QueryCharText(elem, &hro->field_5);
    else if(name == "field_6") QueryCharText(elem, &hro->field_6);
    else if(name == "field_7") QueryCharText(elem, &hro->field_7);
    else if(name == "field_8") QueryCharText(elem, &hro->field_8);
    else if(name == "field_9") QueryCharText(elem, &hro->field_9);
    else if(name == "name") QueryText(elem, hro->name);
    else if(name == "experience") elem->QueryIntText(&hro->experience);
    else if(name == "factionID") QueryCharText(elem, &hro->factionID);
    else if(name == "heroID") QueryCharText(elem, &hro->heroID);
    else if(name == "x") elem->QueryIntText(&hro->x);
    else if(name == "y") elem->QueryIntText(&hro->y);
    else if(name == "field_21") QueryShortText(elem, &hro->field_21);
    else if(name == "field_23") QueryShortText(elem, &hro->field_23);
    else if(name == "field_25") QueryShortText(elem, &hro->field_25);
    else if(name == "field_27") QueryShortText(elem, &hro->field_27);
    else if(name == "relatedToX") QueryCharText(elem, &hro->relatedToX);
    else if(name == "relatedToY") QueryCharText(elem, &hro->relatedToY);
    else if(name == "relatedToFactionID") QueryCharText(elem, &hro->relatedToFactionID);
    else if(name == "directionFacing") QueryCharText(elem, &hro->directionFacing);
    else if(name == "occupiedObjType") QueryShortText(elem, &hro->occupiedObjType);
    else if(name == "occupiedObjVal") QueryShortText(elem, &hro->occupiedObjVal);
    else if(name == "mobility") elem->QueryIntText(&hro->mobility);
    else if(name == "remainingMobility") elem->QueryIntText(&hro->remainingMobility);
    else if(name == "oldLevel") QueryShortText(elem, &hro->oldLevel);
    else if(name == "attack") QueryCharText(elem, &hro->primarySkills[PRIMARY_SKILL_ATTACK]);
    else if(name == "defense") QueryCharText(elem, &hro->primarySkills[PRIMARY_SKILL_DEFENSE]);
    else if(name == "spellpower") QueryCharText(elem, &hro->primarySkills[PRIMARY_SKILL_SPELLPOWER]);
    else if(name == "knowledge") QueryCharText(elem, &hro->primarySkills[PRIMARY_SKILL_KNOWLEDGE]);
    else if(name == "field_43") QueryCharText(elem, &hro->field_43);
    else if(name == "tempMoraleBonuses") QueryCharText(elem, &hro->tempMoraleBonuses);
    else if(name == "tempLuckBonuses") QueryCharText(elem, &hro->tempLuckBonuses);
    else if(name == "field_46") QueryCharText(elem, &hro->field_46);
    else if(name == "gazeboesVisited") elem->QueryIntText(&hro->gazeboesVisited);
    else if(name == "fortsVisited") elem->QueryIntText(&hro->fortsVisited);
    else if(name == "witchDoctorHutsVisited") elem->QueryIntText(&hro->witchDoctorHutsVisited);
    else if(name == "mercenaryCampsVisited") elem->QueryIntText(&hro->mercenaryCampsVisited);
    else if(name == "standingStonesVisited") elem->QueryIntText(&hro->standingStonesVisited);
    else if(name == "treesOfKnowledgeVisited") elem->QueryIntText(&hro->treesOfKnowledgeVisited);
    else if(name == "xanadusVisited") elem->QueryIntText(&hro->xanadusVisited);
    else if(name == "randomSeed") QueryCharText(elem, &hro->randomSeed);
    else if(name == "wisdomLastOffered") QueryCharText(elem, &hro->wisdomLastOffered);
    else if(name == "flags") elem->QueryIntText(&hro->flags);
    else if(name == "isCaptain") QueryCharText(elem, &hro->isCaptain);
    else if(name == "field_E8") elem->QueryIntText(&hro->field_E8);
    else if(name == "army") {
      hro->army.creatureTypes[index] = elem->IntAttribute("type");
      hro->army.quantities[index] = elem->IntAttribute("quantity");
    }
    else if(name == "secondarySkill") {
      hro->secondarySkillLevel[index] = elem->IntAttribute("level");
      hro->skillIndex[index] = elem->IntAttribute("idx");
    }
    else if(name == "numSecSkillsKnown") elem->QueryIntText(&hro->numSecSkillsKnown);
    else if(name == "spell") hro->spellsLearned[elem->IntAttribute("idx")] = 1;
    else if(name == "artifact") {
      hro->artifacts[index] = elem->IntAttribute("id");
      hro->scrollSpell[index] = elem->IntAttribute("spell");
    }
  }
}

void IronfistXML::ReadTown(tinyxml2::XMLNode* root, int townIdx) {
  town* twn = &gpGame->castles[townIdx];
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "idx") QueryCharText(elem, &twn->idx);
    else if(name == "ownerIdx") QueryCharText(elem, &twn->ownerIdx);
    else if(name == "alignment") QueryCharText(elem, &twn->alignment);
    else if(name == "factionID") QueryCharText(elem, &twn->factionID);
    else if(name == "x") QueryCharText(elem, &twn->x);
    else if(name == "y") QueryCharText(elem, &twn->y);
    else if(name == "buildDockRelated") QueryCharText(elem, &twn->buildDockRelated);
    else if(name == "boatCell") QueryCharText(elem, &twn->boatCell);
    else if(name == "visitingHeroIdx") QueryCharText(elem, &twn->visitingHeroIdx);
    else if(name == "buildingsBuiltFlags") elem->QueryUnsignedText(&twn->buildingsBuiltFlags);
    else if(name == "mageGuildLevel") QueryCharText(elem, &twn->mageGuildLevel);
    else if(name == "field_1D") QueryCharText(elem, &twn->field_1D);
    else if(name == "exists") QueryCharText(elem, &twn->exists);
    else if(name == "mayNotBeUpgradedToCastle") QueryCharText(elem, &twn->mayNotBeUpgradedToCastle);
    else if(name == "field_38") QueryCharText(elem, &twn->field_38);
    else if(name == "playerPos") QueryCharText(elem, &twn->playerPos);
    else if(name == "extraIdx") QueryShortText(elem, &twn->extraIdx);
    else if(name == "field_55") QueryShortText(elem, &twn->field_55);
    else if(name == "field_63") QueryCharText(elem, &twn->field_63);
    else if(name == "name") QueryText(elem, twn->name);
    else if(name == "garrisonCreature") {
      twn->garrison.creatureTypes[index] = elem->IntAttribute("type");
      twn->garrison.quantities[index] = elem->IntAttribute("quantity");
    }
    else if(name == "mageGuildSpell") {
      int level = elem->IntAttribute("level");
      int idx = elem->IntAttribute("idx");
      int spell = elem->IntAttribute("spell");
      twn->mageGuildSpells[level][idx] = spell;
    }
    else if(name == "numCreaturesInDwelling") twn->numCreaturesInDwelling[index] = value;
    else if(name == "numSpellsOfLevel") twn->numSpellsOfLevel[index] = value;
  }
}

void IronfistXML::ReadRoot(tinyxml2::XMLNode* root) {
  int campaignType;
  char hasPlayer[NUM_PLAYERS];
  std::vector<int> xmlArtifacts;
  std::map<std::string, mapVariable> mapVariables;
  for(tinyxml2::XMLNode* child = root->FirstChild(); child; child = child->NextSibling()) {
    tinyxml2::XMLElement *elem = child->ToElement();
    std::string name = elem->Name();
    int index = elem->IntAttribute("index"); // used for arrays
    int value = elem->IntAttribute("value"); // used for arrays
    if(name == "allowAIArmySharing") elem->QueryBoolText(&gpGame->allowAIArmySharing);
    else if(name == "mapWidth") elem->QueryIntText(&gpGame->map.width);
    else if(name == "mapHeight") {
      elem->QueryIntText(&gpGame->map.height);
      gpGame->SetMapSize(gpGame->map.width, gpGame->map.height);
    }
    else if(name == "gameDifficulty") QueryShortText(elem, &gpGame->gameDifficulty);
    else if(name == "monthType") elem->QueryIntText(&giMonthType);
    else if(name == "monthTypeExtra") elem->QueryIntText(&giMonthTypeExtra);
    else if(name == "weekType") elem->QueryIntText(&giWeekType);
    else if(name == "weekTypeExtra") elem->QueryIntText(&giWeekTypeExtra);
    else if(name == "giMapChangeCtr") {
      gpAdvManager->PurgeMapChangeQueue();
      elem->QueryIntText(&giMapChangeCtr);
    }
    else if(name == "numPlayers") QueryCharText(elem, &gpGame->numPlayers);
    else if(name == "giCurPlayer") elem->QueryIntText(&giCurPlayer);
    else if(name == "couldBeNumDefeatedPlayers") QueryCharText(elem, &gpGame->couldBeNumDefeatedPlayers);
    else if(name == "day") QueryShortText(elem, &gpGame->day);
    else if(name == "week") QueryShortText(elem, &gpGame->week);
    else if(name == "month") QueryShortText(elem, &gpGame->month);
    else if(name == "numObelisks") QueryCharText(elem, &gpGame->numObelisks);
    else if(name == "ultimateArtifactLocX") QueryCharText(elem, &gpGame->ultimateArtifactLocX);
    else if(name == "ultimateArtifactLocY") QueryCharText(elem, &gpGame->ultimateArtifactLocY);
    else if(name == "ultimateArtifactIdx") QueryCharText(elem, &gpGame->ultimateArtifactIdx);
    else if(name == "currentRumor") QueryText(elem, gpGame->currentRumor);
    else if(name == "numRumors") QueryShortText(elem, &gpGame->numRumors);
    else if(name == "numEvents") QueryShortText(elem, &gpGame->numEvents);
    else if(name == "numMapEvents") QueryShortText(elem, &gpGame->numMapEvents);
    else if(name == "iMaxMapExtra") {
      elem->QueryIntText(&iMaxMapExtra);
      ppMapExtra = (void**)ALLOC(4 * iMaxMapExtra);
      pwSizeOfMapExtra = (short*)ALLOC(2 * iMaxMapExtra);
      memset(ppMapExtra, 0, 4 * iMaxMapExtra);
      memset(pwSizeOfMapExtra, 0, 2 * iMaxMapExtra);
    }
    else if(name == "difficulty") QueryCharText(elem, &gpGame->difficulty);
    else if(name == "mapFilename") QueryText(elem, gpGame->mapFilename);
    else if(name == "relatedToNewGameSelection") QueryCharText(elem, &gpGame->relatedToNewGameSelection);
    else if(name == "relatedToNewGameInit") QueryCharText(elem, &gpGame->relatedToNewGameInit);
    else if(name == "numHumanPlayers") QueryCharText(elem, &gpGame->numHumanPlayers);
    else if(name == "gbIAmGreatest") elem->QueryIntText(&gbIAmGreatest);
    else if(name == "campaignType") elem->QueryIntText(&campaignType);
    else if(name == "mapHeader") ReadMapHeader(elem);
    else if(name == "playerNames") QueryText(elem, cPlayerNames[index]);
    else if(name == "deadPlayers") gpGame->playerDead[index] = value;
    else if(name == "alivePlayers") hasPlayer[index] = value;
    else if(name == "heroHireStatus") gpGame->heroHireStatus[index] = value;
    else if(name == "relatedToPlayerPosAndColor") gpGame->relatedToPlayerPosAndColor[index] = value;
    else if(name == "playerHandicap") gpGame->playerHandicap[index] = value;
    else if(name == "newGameSelectedFaction") gpGame->newGameSelectedFaction[index] = value;
    else if(name == "somePlayerCodeOr10IfMayBeHuman") gpGame->somePlayerCodeOr10IfMayBeHuman[index] = value;
    else if(name == "somePlayerNumData") gpGame->somePlayerNumData[index] = value;
    else if(name == "field_47C") gpGame->field_47C[index] = value;
    else if(name == "field_2773") gpGame->field_2773[index] = value;
    else if(name == "builtToday") gpGame->builtToday[index] = value;
    else if(name == "field_60A6") gpGame->field_60A6[index] = value;
    else if(name == "randomArtifacts") xmlArtifacts.push_back(value);
    else if(name == "boatBuilt") gpGame->boatBuilt[index] = value;
    else if(name == "obeliskVisitedMasks") gpGame->obeliskVisitedMasks[index] = value;
    else if(name == "field_637D") gpGame->field_637D[index] = value;
    else if(name == "rumorIndices") gpGame->rumorIndices[index] = value;
    else if(name == "eventIndices") gpGame->eventIndices[index] = value;
    else if(name == "mapEventIndices") gpGame->mapEventIndices[index] = value;
    else if(name == "mapRevealed") mapRevealed[index] = value;
    else if(name == "mine") {
      mine *m = &gpGame->mines[index];
      m->x = elem->IntAttribute("x");
      m->y = elem->IntAttribute("y");
      m->field_0 = elem->IntAttribute("field_0");
      m->owner = elem->IntAttribute("owner");
      m->type = elem->IntAttribute("type");
      m->guardianType = elem->IntAttribute("guardianType");
      m->guardianQty = elem->IntAttribute("guardianQty");
    }
    else if(name == "boat") {
      boat *b = &gpGame->boats[index];
      b->idx = elem->IntAttribute("idx");
      b->x = elem->IntAttribute("x");
      b->y = elem->IntAttribute("y");
      b->field_3 = elem->IntAttribute("field_3");
      b->underlyingObjType = elem->IntAttribute("underlyingObjType");
      b->underlyingObjExtra = elem->IntAttribute("underlyingObjExtra");
      b->field_6 = elem->IntAttribute("field_6");
      b->owner = elem->IntAttribute("owner");
    }
    else if(name == "script") {
      const char *script = elem->GetText();
      if(script) {
        ScriptingInitFromString(std::string(script));
      }
    }
    else if(name == "mapExtra") ReadMapExtra(elem);
    else if(name == "playerData") ReadPlayerData(elem, index);
    else if(name == "town") ReadTown(elem, index);
    else if(name == "map") ReadMap(elem);      
    else if(name == "hero") ReadHero(elem, index);
    else if(name == "campaign") ReadCampaign(elem, (CAMPAIGN_TYPE)campaignType);
    else if(name == "mapVariable") {
      std::string mapVariableId = elem->Attribute("id");
      
      MapVarType mapVariableType = StringToMapVarType(elem->Attribute("type"));
      int x;
      int y;
      if ((mapVariableType == MAPVAR_TYPE_BOOLEAN) && (std::string(elem->Attribute("value")) == "true") && (sscanf(mapVariableId.c_str(), "_AICHASE_%d_%d_", &x, &y))) {
        gpGame->forcedComputerPlayerChases[x][y] = true;
      }
      mapVariable *mapVar = new mapVariable;
      mapVar->type = mapVariableType;
      if (isTable(mapVariableType)) {
        mapVar->tableValue = ReadTable(elem->FirstChild());
      } else if (isStringNumBool(mapVariableType)) {
        std::string *sV = new std::string;
        *sV = elem->Attribute("value");
        mapVar->singleValue = sV;
      } else {
        ErrorLoadingMapVariable(mapVariableId, " A map variable can only be a table, number, string or boolean.");
      }
      mapVariables[mapVariableId] = *mapVar;
    }
  }

  int c = 0;
  for(int i = 0; i < ELEMENTS_IN(hasPlayer); i++) {
    if(hasPlayer[i] && c < iLastMsgNumHumanPlayers) {
      c++;
      gbHumanPlayer[i] = 1;
    } else {
      gbHumanPlayer[i] = 0;
    }
    if(gbHumanPlayer[i])
      gbThisNetHumanPlayer[i] = !gbRemoteOn || i == giThisGamePos;
    else
      gbThisNetHumanPlayer[i] = 0;
  }
  giCurTurn = gpGame->day + 7 * (gpGame->week - 1) + 28 * (gpGame->month - 1);
  DeserializeGeneratedArtifacts(xmlArtifacts);
  if(mapVariables.size())
    WriteMapVariablesToLUA(mapVariables);
}