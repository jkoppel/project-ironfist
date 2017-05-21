#include "adventure/adv.h"
#include "base.h"
#include "adventure/map.h"
#include "game/game.h"

#include "game/map_xml.hxx"
#include "scripting/scripting.h"
#include "spell/spells.h"
#include "gui/dialog.h"

#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
#include<sys/stat.h>

extern int giMonthType;
extern int giMonthTypeExtra;
extern int giWeekType;
extern int giWeekTypeExtra;
extern char cPlayerNames[6][21];

extern int giCurPlayer;
extern int iLastMsgNumHumanPlayers;
extern int bShowIt;

extern int giCurTurn;

extern playerData* gpCurPlayer;
extern unsigned char giCurPlayerBit;

extern signed char gbThisNetHumanPlayer[];
extern int giCurWatchPlayer;
extern unsigned char giCurWatchPlayerBit;

extern int gbRemoteOn;
extern int giThisGamePos;

extern void __fastcall FileError(char*);

extern void __fastcall GenerateStandardFileName(char*, char*);
static const char *tmpFileName = "tmp";
static const LPCWSTR tmpFileNameW = L"tmp";

template<typename T>
void ReadArrayFromXML(T &dest, xsd::cxx::tree::sequence<ironfist_save::arrayInt_t> &src) {
  for (int i = 0; i < src.size(); i++)
    dest[i] = src.at(i).value();
}

template<typename T>
void WriteArrayToXML(xsd::cxx::tree::sequence<ironfist_save::arrayInt_t> &dest, T &src) {
  for (int i = 0; i < ELEMENTS_IN(src); i++)
    dest.push_back(ironfist_save::arrayInt_t::value_type(src[i]));
}

static void ReadGameStateXML(ironfist_save::gamestate_t& gs, game* gam) {
  ClearMapExtra();

  gam->allowAIArmySharing = gs.allowAIArmySharing();
  gam->map.width = gs.mapWidth();
  gam->map.height = gs.mapHeight();
  gam->SetMapSize(gam->map.width, gam->map.height);

  SMapHeader *mh = &gam->mapHeader;
  ironfist_save::gamestate_t::mapHeader_type *mh_xml = &gs.mapHeader().back();
  mh->field_0 = mh_xml->field_0();
  mh->field_4 = mh_xml->field_4();
  mh->width = mh_xml->width();
  mh->height = mh_xml->height();
  mh->numPlayers = mh_xml->numPlayers();
  mh->minHumans = mh_xml->minHumans();
  mh->maxHumans = mh_xml->maxHumans();
  mh->winConditionType = mh_xml->winConditionType();
  mh->field_1E = mh_xml->field_1E();
  mh->allowDefeatAllVictory = mh_xml->allowDefeatAllVictory();
  mh->winConditionArgument = mh_xml->winConditionArgument();
  mh->field_22 = mh_xml->field_22();
  mh->field_23 = mh_xml->field_23();
  mh->field_24 = mh_xml->field_24();
  mh->noStartingHeroInCastle = mh_xml->noStartingHeroInCastle();
  mh->field_2C = mh_xml->field_2C();
  mh->field_2E = mh_xml->field_2E();
  mh->field_32 = mh_xml->field_32();
  mh->field_36 = mh_xml->field_36();
  mh->field_37 = mh_xml->field_37();
  mh->nextTownName = mh_xml->nextTownName();
  mh->field_39 = mh_xml->field_39();
  strcpy(gam->mapHeader.name, mh_xml->name().c_str());
  strcpy(gam->mapHeader.description, mh_xml->description().c_str());
  mh->field_1A0 = mh_xml->field_1A0();
  mh->field_1A1 = mh_xml->field_1A1();
  mh->numRumors = mh_xml->numRumors();
  mh->numEvents = mh_xml->numEvents();

  ReadArrayFromXML(mh->hasPlayer, mh_xml->hasPlayer());
  ReadArrayFromXML(mh->playerMayBeHuman, mh_xml->playerMayBeHuman());
  ReadArrayFromXML(mh->playerMayBeComp, mh_xml->playerMayBeComp());
  ReadArrayFromXML(mh->playerFactions, mh_xml->playerFactions());

  gam->field_44D = gs.field_44D();
  gam->field_451 = gs.field_451();

  ReadArrayFromXML(gam->playerHandicap, gs.playerHandicap());
  ReadArrayFromXML(gam->relatedToColorOfPlayerOrFaction, gs.relatedToColorOfPlayerOrFaction());
  ReadArrayFromXML(gam->field_45F, gs.field_45F());

  gam->difficulty = gs.difficulty();
  strcpy(gam->mapFilename, gs.mapFilename().c_str());
  gam->gameDifficulty = gs.gameDifficulty();
  giMonthType = gs.monthType();
  giMonthTypeExtra = gs.monthTypeExtra();
  giWeekType = gs.weekType();
  giWeekTypeExtra = gs.weekTypeExtra();
  for (int i = 0; i < gs.playerNames().size(); i++)
    strcpy(cPlayerNames[i], gs.playerNames().at(i).value().c_str());
  gpAdvManager->PurgeMapChangeQueue();
  giMapChangeCtr = gs.mapChangeCtr();
  gam->numPlayers = gs.numPlayers();
  giCurPlayer = gs.currentPlayer();
  gam->couldBeNumDefeatedPlayers = gs.numDefatedPlayers();

  char hasPlayer[6];
  int c = 0;

  ReadArrayFromXML(gam->playerDead, gs.deadPlayers());
  ReadArrayFromXML(hasPlayer, gs.alivePlayers());

  for (int i = 0; i < ELEMENTS_IN(hasPlayer); i++) {
    if (hasPlayer[i] && c < iLastMsgNumHumanPlayers) {
      c++;
      gbHumanPlayer[i] = 1;
    } else {
      gbHumanPlayer[i] = 0;
    }
    if (gbHumanPlayer[i])
      gbThisNetHumanPlayer[i] = !gbRemoteOn || i == giThisGamePos;
    else
      gbThisNetHumanPlayer[i] = 0;
  }

  gam->day = gs.day();
  gam->week = gs.week();
  gam->month = gs.month();

  giCurTurn = gam->day + 7 * (gam->week - 1) + 28 * (gam->month - 1);

  for (int i = 0; i < gs.playerData().size(); i++) {
    playerData *pdata = &gam->players[i];
    ironfist_save::gamestate_t::playerData_type *pdata_xml = &gs.playerData().at(i);

    pdata->color = pdata_xml->color();
    pdata->numHeroes = pdata_xml->numHeroes();
    pdata->curHeroIdx = pdata_xml->curHeroIdx();
    pdata->relatedToSomeSortOfHeroCountOrIdx = pdata_xml->relatedToSomeSortOfHeroCountOrIdx();

    ReadArrayFromXML(pdata->heroesForPurchase, pdata_xml->heroesForPurchase());
    ReadArrayFromXML(pdata->heroesOwned, pdata_xml->heroesOwned());

    gam->_B[1] = pdata_xml->game_B();
    pdata->_3[0] = pdata_xml->_3();
    pdata->personality = pdata_xml->personality();
    pdata->_2 = pdata_xml->_2();
    pdata->hasEvilFaction = pdata_xml->hasEvilFaction();
    pdata->field_40 = pdata_xml->field_40();
    pdata->field_41 = pdata_xml->field_41();
    pdata->daysLeftWithoutCastle = pdata_xml->daysLeftWithoutCastle();
    pdata->numCastles = pdata_xml->numCastles();
    pdata->field_45 = pdata_xml->field_45();

    ReadArrayFromXML(pdata->castlesOwned, pdata_xml->castlesOwned());
    ReadArrayFromXML(pdata->resources, pdata_xml->resources());
    ReadArrayFromXML(pdata->field_E7, pdata_xml->field_E7());
    ReadArrayFromXML(pdata->_4_2, pdata_xml->_4_2());

    pdata->barrierTentsVisited = pdata_xml->barrierTentsVisited();
  }
  gam->numObelisks = gs.numObelisks();
  
  ReadArrayFromXML(gam->relatedToHeroForHireStatus, gs.heroHireStatus());

  for (int i = 0; i < gs.towns().size(); i++) {
    town *twn = &gam->castles[i];
    ironfist_save::gamestate_t::towns_type *twn_xml = &gs.towns().at(i);

    twn->idx = twn_xml->idx();
    twn->ownerIdx = twn_xml->ownerIdx();
    twn->alignment = twn_xml->alignment();
    twn->factionID = twn_xml->factionID();
    twn->x = twn_xml->x();
    twn->y = twn_xml->y();
    twn->buildDockRelated = twn_xml->buildDockRelated();
    twn->field_7 = twn_xml->field_7();
    twn->visitingHeroIdx = twn_xml->visitingHeroIdx();
    twn->buildingsBuiltFlags = twn_xml->buildingsBuiltFlags();
    twn->mageGuildLevel = twn_xml->mageGuildLevel();
    twn->field_1D = twn_xml->field_1D();
    twn->exists = twn_xml->exists();
    twn->mayNotBeUpgradedToCastle = twn_xml->mayNotBeUpgradedToCastle();
    twn->field_38 = twn_xml->field_38();
    twn->playerPos = twn_xml->playerPos();
    twn->extraIdx = twn_xml->extraIdx();
    twn->field_55 = twn_xml->field_55();
    twn->field_63 = twn_xml->field_63();
    strcpy(twn->name, twn_xml->name().c_str());
    for (int j = 0; j < twn_xml->garrison().back().creature().size(); j++) {
      twn->garrison.creatureTypes[i] = twn_xml->garrison().back().creature().at(j).type();
      twn->garrison.quantities[i] = twn_xml->garrison().back().creature().at(j).quantity();
    }
    
    for (int j = 0; j < twn_xml->mageGuildSpells().size(); j++)
      *(twn->mageGuildSpells[0] + j) = twn_xml->mageGuildSpells().at(j).value();

    ReadArrayFromXML(twn->numCreaturesInDwelling, twn_xml->numCreaturesInDwelling());
    ReadArrayFromXML(twn->numSpellsOfLevel, twn_xml->numSpellsOfLevel());
  }

  ReadArrayFromXML(gam->field_2773, gs.field_2773());
  ReadArrayFromXML(gam->field_27BB, gs.field_27BB());

  for (int i = 0; i < gs.mine().size(); i++) {
    mine *mn = &gam->mines[i];
    ironfist_save::mine_t *mn_xml = &gs.mine().at(i);
    mn->field_0 = mn_xml->field_0();
    mn->owner = mn_xml->owner();
    mn->type = mn_xml->type();
    mn->guardianType = mn_xml->guardianType();
    mn->guadianQty = mn_xml->guardianQty();
    mn->x = mn_xml->x();
    mn->y = mn_xml->y();
  }

  ReadArrayFromXML(gam->field_60A6, gs.field_60A6());
  ReadArrayFromXML(gam->artifactGeneratedRandomly, gs.randomArtifacts());

  for (int i = 0; i < gs.boat().size(); i++) {
    boat *bt = &gam->boats[i];
    ironfist_save::boat_t *bt_xml = &gs.boat().at(i);
    bt->idx = bt_xml->idx();
    bt->x = bt_xml->x();
    bt->y = bt_xml->y();
    bt->field_3 = bt_xml->field_3();
    bt->underlyingObjType = bt_xml->underlyingObjType();
    bt->underlyingObjExtra = bt_xml->underlyingObjExtra();
    bt->field_6 = bt_xml->field_6();
    bt->owner = bt_xml->owner();
  }
  ReadArrayFromXML(gam->boatBuilt, gs.boatBuilt());
  ReadArrayFromXML(gam->obeliskVisitedMasks, gs.obeliskVisitedMasks());

  gam->field_6395 = gs.field_6395();
  gam->field_6396 = gs.field_6396();
  gam->field_6397 = gs.field_6397();
  strcpy(gam->currentRumor, gs.currentRumor().c_str());

  ReadArrayFromXML(gam->field_637D, gs.field_637D());

  gam->numRumors = gs.numRumors();
  gam->numEvents = gs.numEvents();
  gam->field_657B = gs.field_657B();
  for (int i = 0; i < 2 * gam->field_657B; i++)
    gam->_D[i] = gs._D().at(i).value();

  // Reading map cells and their extra data
  iMaxMapExtra = gs.maxMapExtra();

  ReadArrayFromXML(gam->rumorIndices, gs.rumorIndices());
  ReadArrayFromXML(gam->eventIndices, gs.eventIndices());

  ppMapExtra = (void**)ALLOC(4 * iMaxMapExtra);
  pwSizeOfMapExtra = (short*)ALLOC(2 * iMaxMapExtra);
  memset(ppMapExtra, 0, 4 * iMaxMapExtra);
  memset(pwSizeOfMapExtra, 0, 2 * iMaxMapExtra);
  for (int i = 1; i < iMaxMapExtra; ++i) {
    pwSizeOfMapExtra[i] = gs.mapExtra().at(i - 1).ppMapExtra().size();
    ppMapExtra[i] = ALLOC(pwSizeOfMapExtra[i]);
    for (int j = 0; j < pwSizeOfMapExtra[i]; j++) {
      *((char*)ppMapExtra[i] + j) = (char)gs.mapExtra().at(i - 1).ppMapExtra().at(j).value().get();
    }
  }
  for (int i = 0; i < gs.mapRevealed().size(); i++)
    mapRevealed[i] = gs.mapRevealed().at(i).revealed().get();
  gam->map.width = gs.map().back().width();
  gam->map.height = gs.map().back().height();
  gam->map.Init(gam->map.width, gam->map.height);
  for (int i = 0; i < gs.map().back().mapCell().size(); i++) {
    mapCell *cell = &gam->map.tiles[i];
    ironfist_save::mapCell_t *cell_xml = &gs.map().back().mapCell().at(i);
    cell->groundIndex = cell_xml->groundIndex();
    cell->hasObject = cell_xml->hasObject();
    cell->isRoad = cell_xml->isRoad();
    cell->objTileset = cell_xml->objTileset();
    cell->objectIndex = cell_xml->objectIndex();
    cell->field_4_1 = cell_xml->field_4_1();
    cell->isShadow = cell_xml->isShadow();
    cell->field_4_3 = cell_xml->field_4_3();
    cell->extraInfo = cell_xml->extraInfo();
    cell->hasOverlay = cell_xml->hasOverlay();
    cell->hasLateOverlay = cell_xml->hasLateOverlay();
    cell->overlayTileset = cell_xml->overlayTileset();
    cell->overlayIndex = cell_xml->overlayIndex();
    cell->displayFlags = cell_xml->displayFlags();
    cell->objType = cell_xml->objType();
    cell->extraIdx = cell_xml->extraIdx();
  }
  gam->map.numCellExtras = gs.map().back().numCellExtras();
  if (gam->map.numCellExtras)
    delete(gam->map.cellExtras);
  gam->map.cellExtras = (mapCellExtra *)operator new(7 * gam->map.numCellExtras);
  for (int i = 0; i < gs.map().back().mapCellExtra().size(); i++) {
    mapCellExtra *ext = &gam->map.cellExtras[i];
    ironfist_save::mapCellExtra_t *ext_xml = &gs.map().back().mapCellExtra().at(i);
    ext->nextIdx = ext_xml->nextIdx();
    ext->animatedObject = ext_xml->animatedObject();
    ext->objTileset = ext_xml->objTileset();
    ext->objectIndex = ext_xml->objectIndex();
    ext->field_4_1 = ext_xml->field_4_1();
    ext->field_4_2 = ext_xml->field_4_2();
    ext->field_4_3 = ext_xml->field_4_3();
    ext->field_4_4 = ext_xml->field_4_4();
    ext->animatedLateOverlay = ext_xml->animatedLateOverlay();
    ext->hasLateOverlay = ext_xml->hasLateOverlay();
    ext->tileset = ext_xml->tileset();
    ext->overlayIndex = ext_xml->overlayIndex();
  }
}

ironfist_save::gamestate_t WriteGameStateXML(game* gam) {
  ironfist_save::gamestate_t gs(
    (int)gam->allowAIArmySharing,
    gam->map.width,
    gam->map.height,
    gam->gameDifficulty,
    giMonthType,
    giMonthTypeExtra,
    giWeekType,
    giWeekTypeExtra,
    giMapChangeCtr,
    (int)gam->numPlayers,
    giCurPlayer,
    (int)gam->couldBeNumDefeatedPlayers,
    (int)gam->day,
    (int)gam->week,
    (int)gam->month,
    (int)gam->numObelisks,
    (int)gam->field_6395,
    (int)gam->field_6396,
    (int)gam->field_6397,
    gam->currentRumor,
    (int)gam->numRumors,
    (int)gam->numEvents,
    (int)gam->field_657B,
    iMaxMapExtra,
    gam->field_44D,
    gam->field_451,
    gam->difficulty,
    gam->mapFilename
  );

  SMapHeader *mh = &gam->mapHeader;
  gs.mapHeader().push_back(ironfist_save::gamestate_t::mapHeader_type(
    mh->field_0,
    mh->field_4,
    mh->width,
    mh->height,
    mh->numPlayers,
    mh->minHumans,
    mh->maxHumans,
    mh->winConditionType,
    mh->field_1E,
    mh->allowDefeatAllVictory,
    mh->winConditionArgument,
    mh->field_22,
    mh->field_23,
    mh->field_24,
    mh->noStartingHeroInCastle,
    mh->field_2C,
    mh->field_2E,
    mh->field_32,
    mh->field_36,
    mh->field_37,
    mh->nextTownName,
    mh->field_39,
    mh->name,
    mh->description,
    mh->field_1A0,
    mh->field_1A1,
    mh->numRumors,
    mh->numEvents
  ));

  WriteArrayToXML(gs.mapHeader().back().hasPlayer(), mh->hasPlayer);
  WriteArrayToXML(gs.mapHeader().back().playerMayBeHuman(), mh->playerMayBeHuman);
  WriteArrayToXML(gs.mapHeader().back().playerMayBeComp(), mh->playerMayBeComp);
  WriteArrayToXML(gs.mapHeader().back().playerFactions(), mh->playerFactions);

  for (int i = 0; i < ELEMENTS_IN(cPlayerNames); i++)
    gs.playerNames().push_back(ironfist_save::gamestate_t::playerNames_type(cPlayerNames[i]));

  WriteArrayToXML(gs.deadPlayers(), gam->playerDead);

  char playerAlive[6];
  for (int i = 0; i < 6; ++i) {
    playerAlive[i] = gbHumanPlayer[i];
    if (gam->playerDead[i])
      playerAlive[i] = 0;
  }

  WriteArrayToXML(gs.alivePlayers(), playerAlive);
  WriteArrayToXML(gs.heroHireStatus(), gam->relatedToHeroForHireStatus);
  WriteArrayToXML(gs.playerHandicap(), gam->playerHandicap);
  WriteArrayToXML(gs.relatedToColorOfPlayerOrFaction(), gam->relatedToColorOfPlayerOrFaction);
  WriteArrayToXML(gs.field_45F(), gam->field_45F);
  WriteArrayToXML(gs.field_2773(), gam->field_2773);
  WriteArrayToXML(gs.field_27BB(), gam->field_27BB);
  WriteArrayToXML(gs.field_60A6(), gam->field_60A6);
  WriteArrayToXML(gs.randomArtifacts(), gam->artifactGeneratedRandomly);
  WriteArrayToXML(gs.boatBuilt(), gam->boatBuilt);
  WriteArrayToXML(gs.obeliskVisitedMasks(), gam->obeliskVisitedMasks);
  WriteArrayToXML(gs.field_637D(), gam->field_637D);
  WriteArrayToXML(gs.rumorIndices(), gam->rumorIndices);
  WriteArrayToXML(gs.eventIndices(), gam->eventIndices);
  WriteArrayToXML(gs._D(), gam->_D);

  for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    int x = i % MAP_HEIGHT;
    int y = i / MAP_HEIGHT;
    gs.mapRevealed().push_back(ironfist_save::gamestate_t::mapRevealed_type(x, y));
    gs.mapRevealed().back().revealed(mapRevealed[i]);
  }

  for (int i = 1; i < iMaxMapExtra; i++) {
    gs.mapExtra().push_back(ironfist_save::gamestate_t::mapExtra_type());
    for (int j = 0; j < pwSizeOfMapExtra[i]; j++) {
      gs.mapExtra().back().ppMapExtra().push_back(ironfist_save::mapExtra_t::ppMapExtra_type());
      gs.mapExtra().back().ppMapExtra().back().mapExtraIndex(i);
      if (ppMapExtra[i]) {
        gs.mapExtra().back().ppMapExtra().back().value(*((char*)ppMapExtra[i] + j));
      } else {
        gs.mapExtra().back().ppMapExtra().back().value(0);
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    playerData player = gam->players[i];

    ironfist_save::gamestate_t::playerData_type data(
      player.color,
      player.numHeroes,
      player.curHeroIdx,
      player.relatedToSomeSortOfHeroCountOrIdx,
      gam->_B[1],
      player._3[0],
      player.personality,
      player._2,
      player.hasEvilFaction,
      player.field_40,
      player.field_41,
      player.daysLeftWithoutCastle,
      player.numCastles,
      player.field_45,
      player.barrierTentsVisited
    );
    gs.playerData().push_back(data);

    WriteArrayToXML(gs.playerData().back().heroesOwned(), player.heroesOwned);
    WriteArrayToXML(gs.playerData().back().heroesForPurchase(), player.heroesForPurchase);
    WriteArrayToXML(gs.playerData().back().castlesOwned(), player.castlesOwned);
    WriteArrayToXML(gs.playerData().back().resources(), player.resources);
    WriteArrayToXML(gs.playerData().back().field_E7(), player.field_E7);
    WriteArrayToXML(gs.playerData().back()._4_2(), player._4_2);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->castles); i++) {
    town twn = gam->castles[i];
    ironfist_save::gamestate_t::towns_type data(
      twn.idx,
      twn.ownerIdx,
      twn.alignment,
      twn.factionID,
      twn.x,
      twn.y,
      twn.buildDockRelated,
      twn.field_7,
      twn.visitingHeroIdx,
      (int)twn.buildingsBuiltFlags,
      twn.mageGuildLevel,
      twn.field_1D,
      twn.exists,
      twn.mayNotBeUpgradedToCastle,
      twn.field_38,
      twn.playerPos,
      twn.extraIdx,
      twn.field_55,
      twn.field_63,
      twn.name
    );
    gs.towns().push_back(data);

    WriteArrayToXML(gs.towns().back().numCreaturesInDwelling(), twn.numCreaturesInDwelling);
    WriteArrayToXML(gs.towns().back().numSpellsOfLevel(), twn.numSpellsOfLevel);

    for (int j = 0; j < 20; j++) {
      int x = j % 5;
      int y = j / 5;
      gs.towns().back().mageGuildSpells().push_back(ironfist_save::town_t::mageGuildSpells_type(j));
      gs.towns().back().mageGuildSpells().back().value(twn.mageGuildSpells[x][y]);
    }

    gs.towns().back().garrison().push_back(ironfist_save::town_t::garrison_type());
    for (int j = 0; j < ELEMENTS_IN(twn.garrison.creatureTypes); j++) {
      gs.towns().back().garrison().back().creature().push_back(ironfist_save::armyGroup_t::creature_type(twn.garrison.creatureTypes[j], twn.garrison.quantities[j]));
    }
  }

  for (int i = 0; i < ELEMENTS_IN(gam->mines); i++) {
    mine *m = &gam->mines[i];
    gs.mine().push_back(ironfist_save::gamestate_t::mine_type(m->field_0, m->owner, m->type, m->guardianType, m->guadianQty, m->x, m->y));
  }
  for (int i = 0; i < ELEMENTS_IN(gam->boats); i++) {
    boat *b = &gam->boats[i];
    gs.boat().push_back(ironfist_save::gamestate_t::boat_type(b->idx, b->x, b->y, b->field_3, b->underlyingObjType, b->underlyingObjExtra, b->field_6, b->owner));
  }

  fullMap *map = &gam->map;
  gs.map().push_back(ironfist_save::gamestate_t::map_type(map->width, map->height, map->numCellExtras));
  for (int i = 0; i < map->height * map->width; i++) {
    mapCell *c = &map->tiles[i];
    ironfist_save::map_t::mapCell_type cell(
      c->groundIndex,
      c->hasObject,
      c->isRoad,
      c->objTileset,
      c->objectIndex,
      c->field_4_1,
      c->isShadow,
      c->field_4_3,
      c->extraInfo,
      c->hasOverlay,
      c->hasLateOverlay,
      c->overlayTileset,
      c->overlayIndex,
      c->displayFlags,
      c->objType,
      c->extraIdx);
    gs.map().back().mapCell().push_back(cell);
  }
  for (int i = 0; i < map->numCellExtras; i++) {
    mapCellExtra *e = &map->cellExtras[i];
    ironfist_save::map_t::mapCellExtra_type cellExtra(
      e->nextIdx,
      e->animatedObject,
      e->objTileset,
      e->objectIndex,
      e->field_4_1,
      e->field_4_2,
      e->field_4_3,
      e->field_4_4,
      e->animatedLateOverlay,
      e->hasLateOverlay,
      e->tileset,
      e->overlayIndex
    );
    gs.map().back().mapCellExtra().push_back(cellExtra);
  }
  return gs;
}

static void ReadHeroXML(ironfist_save::hero_t& hx, hero* hro) {
  hro->Clear();

  hro->army = armyGroup();

  int i = 0;
  for (ironfist_save::army_t::slot_const_iterator it = hx.army().slot().begin();
    it != hx.army().slot().end();
    it++,
    i++) {

    hro->army.Add(it->id().get(), it->quantity().get(), i);
  }


  memset(hro->artifacts, -1, sizeof(hro->artifacts));
  i = 0;
  for (ironfist_save::hero_t::artifact_const_iterator jt = hx.artifact().begin();
    jt != hx.artifact().end();
    jt++,
    i++) {

    hro->artifacts[i] = jt->id();
    hro->scrollSpell[i] = jt->spell();
  }

  int nSS = 0;
  for (ironfist_save::hero_t::secondarySkill_const_iterator it =
    hx.secondarySkill().begin();
    it != hx.secondarySkill().end();
    it++) {

    hro->secondarySkillLevel[it->id().get()] = it->level().get();
    hro->skillIndex[it->id().get()] = it->idx().get();

    if (it->level().get() > 0)
      nSS++;
  }

  hro->numSecSkillsKnown = nSS;

  hro->GetNumSpells(1);

  for (ironfist_save::hero_t::spell_const_iterator it = hx.spell().begin();
    it != hx.spell().end();
    it++) {

    hro->spellsLearned[*it] = 1;
  }
  hro->GetNumSpells(1);

  hro->experience = hx.experience();
  hro->factionID = hx.factionID();
  hro->field_21 = hx.field_21();
  hro->field_23 = hx.field_23();
  hro->field_25 = hx.field_25();
  hro->field_27 = hx.field_27();
  hro->field_29 = hx.field_29();
  hro->field_2B = hx.field_2B();
  hro->field_4 = hx.field_4();
  hro->field_43 = hx.field_43();
  hro->field_46 = hx.field_46();
  hro->field_5 = hx.field_5();
  hro->field_6 = hx.field_6();
  hro->field_7 = hx.field_7();
  hro->field_8 = hx.field_8();
  hro->field_9 = hx.field_9();
  hro->field_E8 = hx.field_E8();
  hro->flags = hx.flags();
  hro->fortsVisited = hx.fortsVisited();
  hro->gazeboesVisited = hx.gazeboesVisited();
  hro->heroID = hx.heroID();
  hro->idx = hx.idx();
  hro->isCaptain = hx.isCaptain();
  hro->mercenaryCampsVisited = hx.mercenaryCampsVisited();
  hro->mobility = hx.mobility();
  strncpy(hro->name, hx.name().c_str(), sizeof(hro->name));

  hro->occupiedObjType = hx.occupiedObjType();
  hro->occupiedObjVal = hx.occupiedObjVal();
  hro->oldLevel = hx.oldLevel();
  hro->ownerIdx = hx.ownerIdx();

  hro->primarySkills[PRIMARY_SKILL_ATTACK] = hx.attack();
  hro->primarySkills[PRIMARY_SKILL_DEFENSE] = hx.defense();
  hro->primarySkills[PRIMARY_SKILL_SPELLPOWER] = hx.spellpower();
  hro->primarySkills[PRIMARY_SKILL_KNOWLEDGE] = hx.knowledge();

  hro->randomSeed = hx.randomSeed();
  hro->remainingMobility = hx.remainingMobility();

  hro->spellpoints = hx.spellpoints();
  hro->standingStonesVisited = hx.standingStonesVisited();
  hro->tempLuckBonuses = hx.tempLuckBonuses();
  hro->tempMoraleBonuses = hx.tempMoraleBonuses();
  hro->treesOfKnowledgeVisited = hx.treesOfKnowledgeVisited();
  hro->wisdomLastOffered = hx.wisdomLastOffered();
  hro->witchDoctorHutsVisited = hx.witchDoctorHutsVisited();
  hro->x = hx.x();
  hro->xanadusVisited = hx.xanadusVisited();
  hro->y = hx.y();
}

luaTable *ReadMapVarXML(ironfist_save::table_t table) {

  luaTable *lt = new luaTable;
  for (ironfist_save::table_t::tableElement_const_iterator tableE = table.tableElement().begin();
    tableE != table.tableElement().end(); tableE++) {
    mapVariable *mapVar = new mapVariable;
    mapVar->type = StringToMapVarType(tableE->type());

    std::string *sV = new std::string(tableE->value().get());
    mapVar->singleValue = sV;
    (*lt)[tableE->key().get()] = *mapVar;
  }

  for (ironfist_save::table_t::table_const_iterator subTable = table.table().begin();
    subTable != table.table().end(); subTable++) {
    mapVariable *mapVar = new mapVariable;
    mapVar->type = MAPVAR_TYPE_TABLE;
    mapVar->tableValue = ReadMapVarXML(*subTable);
    (*lt)[subTable->tableId().get()] = *mapVar;
  }
  return lt;
}

ironfist_save::hero_t WriteHeroXML(hero* hro) {

  ironfist_save::army_t arm;

  for (int i = 0; i < ELEMENTS_IN(hro->army.creatureTypes); i++) {
    ironfist_save::slot_t sl;
    sl.id(hro->army.creatureTypes[i]);
    sl.quantity(hro->army.quantities[i]);

    arm.slot().push_back(sl);
  }

  ironfist_save::hero_t hx(
    hro->spellpoints,
    hro->idx,
    hro->ownerIdx,
    hro->field_4,
    hro->field_5,
    hro->field_6,
    hro->field_7,
    hro->field_8,
    hro->field_9,
    hro->name,
    hro->factionID,
    hro->heroID,
    hro->x,
    hro->y,
    hro->field_21,
    hro->field_23,
    hro->field_25,
    hro->field_27,
    hro->field_29,
    hro->field_2B,
    hro->occupiedObjType,
    hro->occupiedObjVal,
    hro->mobility,
    hro->remainingMobility,
    hro->experience,
    hro->oldLevel,
    hro->primarySkills[PRIMARY_SKILL_ATTACK],
    hro->primarySkills[PRIMARY_SKILL_DEFENSE],
    hro->primarySkills[PRIMARY_SKILL_SPELLPOWER],
    hro->primarySkills[PRIMARY_SKILL_KNOWLEDGE],
    hro->field_43,
    hro->tempMoraleBonuses,
    hro->tempLuckBonuses,
    hro->field_46,
    hro->gazeboesVisited,
    hro->fortsVisited,
    hro->witchDoctorHutsVisited,
    hro->mercenaryCampsVisited,
    hro->standingStonesVisited,
    hro->treesOfKnowledgeVisited,
    hro->xanadusVisited,
    hro->randomSeed,
    hro->wisdomLastOffered,
    arm,
    hro->flags,
    hro->isCaptain,
    hro->field_E8);

  for (int i = 0; i < ELEMENTS_IN(hro->secondarySkillLevel); i++) {
    ironfist_save::secondarySkill sk;
    sk.id(i);
    sk.level(hro->secondarySkillLevel[i]);
    sk.idx(hro->skillIndex[i]);
    hx.secondarySkill().push_back(sk);
  }

  for (int i = 0; i < NUM_SPELLS; i++) {
    if (hro->spellsLearned[i])
      hx.spell().push_back(i);
  }

  for (int i = 0; i < ELEMENTS_IN(hro->artifacts); i++) {
    hx.artifact().push_back(ironfist_save::hero_t::artifact_type(hro->artifacts[i]));
    hx.artifact().back().spell(hro->scrollSpell[i]); // This will save this in the sub-element of the complex element "artifact",
  }                                                  // even though the scrollSpell data is actually not part of the "artifacts" array in the hero class.

  return hx;
}

static std::string MapVarTypeToString(MapVarType type) {
  if (type == MAPVAR_TYPE_STRING) {
    return "string";
  } else if (type == MAPVAR_TYPE_NUMBER) {
    return "number";
  } else if (type == MAPVAR_TYPE_BOOLEAN) {
    return "boolean";
  } else if (type == MAPVAR_TYPE_TABLE) {
    return "table";
  }
}

static ironfist_save::table_t WriteMapVariableTableXML(std::string id, luaTable *lt) {
  ironfist_save::table_t xsdTable;
  xsdTable.tableId(id);
  for (luaTable::const_iterator it = (*lt).begin(); it != (*lt).end(); ++it) {
    if (it->second.type == MAPVAR_TYPE_TABLE) {
      xsdTable.table().push_back(WriteMapVariableTableXML(it->first, it->second.tableValue));
    } else {
      ironfist_save::tableElement_t element;
      element.key(it->first);
      element.type(MapVarTypeToString(it->second.type));
      element.value(*it->second.singleValue);
      xsdTable.tableElement().push_back(element);
    }
  }
  return xsdTable;
}

static void WriteMapVariablesXML(ironfist_save::save_t& m) {

  std::map<std::string, mapVariable> mapVariables = LoadMapVariablesFromLUA();

  for (std::map<std::string, mapVariable>::const_iterator it = mapVariables.begin(); it != mapVariables.end(); ++it) {
    ironfist_save::mapVariable_t mapVar;
    mapVar.id(it->first);
    mapVar.type(MapVarTypeToString(it->second.type));
    if (isTable(it->second.type)) {
      mapVar.table(WriteMapVariableTableXML(it->first, it->second.tableValue));
    } else if (isStringNumBool(it->second.type)) {
      mapVar.value(*it->second.singleValue);
    } else {
      DisplayError("Wrong Type created by GetMapVariables", "In function SaveMapVariables");
    }
    m.mapVariable().push_back(mapVar);
  }
}

void game::LoadGame(char* filnam, int newGame, int a3) {
  if (newGame) {
    this->SetupOrigData();

    gpGame->ResetIronfistGameState();

    for (int i = 0; i < MAX_HEROES; i++) {
      //SetupOrigData clears out spellsLearned. Of course, we've changed
      //spellsLearned from an array to a pointer, so that actually NULLs it out
      this->heroes[i].ResetSpellsLearned();
    }
  } else {
    try {
      char v8[100];
      int v14 = 0;
      gbGameOver = 0;
      this->field_660E = 1;
      sprintf(v8, "%s%s", ".\\GAMES\\", filnam);

      /*
       * Check if original save format
       */
      int fd = _open(v8, O_BINARY);
      char first_byte;
      _read(fd, &first_byte, sizeof(first_byte));
      _close(fd);

      if (first_byte != '<') {
        this->LoadGame_orig(filnam, newGame, a3);
        return;
      }

      std::auto_ptr<ironfist_save::save_t> mp = ironfist_save::save(std::string(v8));

      int i = 0;
      for (ironfist_save::save_t::hero_const_iterator it = mp->hero().begin();
        it != mp->hero().end();
        it++, i++) {
        ironfist_save::hero_t hx = *it;
        ReadHeroXML(hx, &this->heroes[i]);
      }

      if (mp->gamestate())
        ReadGameStateXML(*mp->gamestate(), gpGame);

      gpAdvManager->heroMobilized = 0;
      gpCurPlayer = &gpGame->players[giCurPlayer];
      giCurPlayerBit = 1 << giCurPlayer;
      for (giCurWatchPlayer = giCurPlayer;
        !gbThisNetHumanPlayer[giCurWatchPlayer];
        giCurWatchPlayer = (giCurWatchPlayer + 1) % this->numPlayers)
        ;
      giCurWatchPlayerBit = 1 << giCurWatchPlayer;
      bShowIt = gbThisNetHumanPlayer[giCurPlayer];
      this->SetupAdjacentMons();
      gpAdvManager->CheckSetEvilInterface(0, -1);

      gpGame->ResetIronfistGameState();

      if (mp->script().present()) {
        ScriptingInitFromString(mp->script().get());
      }

      std::map<std::string, mapVariable> mapVariables;
      for (ironfist_save::save_t::mapVariable_const_iterator it = mp->mapVariable().begin();
        it != mp->mapVariable().end(); it++) {
        mapVariable *mapVar = new mapVariable;
        std::string mapVariableId = it->id().get();
        MapVarType mapVariableType = StringToMapVarType(it->type());
        mapVar->type = mapVariableType;
        if (isTable(mapVariableType)) {
          mapVar->tableValue = ReadMapVarXML(it->table().get());
        } else if (isStringNumBool(mapVariableType)) {
          std::string *sV = new std::string;
          *sV = it->value().get();
          mapVar->singleValue = sV;
        } else {
          ErrorLoadingMapVariable(mapVariableId, " A map variable can only be a table, number, string or boolean.");
        }
        mapVariables[mapVariableId] = *mapVar;
      }
      WriteMapVariablesToLUA(mapVariables);

    }
    catch (xml_schema::exception& e) {
      DisplayError("Error parsing save file", "Fatal Error");
      std::cerr << e << std::endl;
      exit(1);
    }
  }
}

int game::SaveGame(char *saveFile, int autosave, signed char baseGame) {
  baseGame = 0;
  gpAdvManager->DemobilizeCurrHero();
  char path[100];
  char v9[100];
  if (autosave) {
    if (!xIsExpansionMap || baseGame) {
      sprintf(path, "%s.GM1", saveFile);
    } else {
      sprintf(path, "%s.GX1", saveFile);
    }
  } else {
    sprintf(path, saveFile);
  }
  sprintf(v9, "%s%s", ".\\GAMES\\", &path);
  if (strnicmp(path, "AUTOSAVE", 8) && strnicmp(path, "PLYREXIT", 8))
    strcpy(gpGame->lastSaveFile, saveFile);

  std::ofstream os(v9);

  ironfist_save::save_t m;

  for (int i = 0; i < ELEMENTS_IN(this->heroes); i++) {
    m.hero().push_back(WriteHeroXML(&this->heroes[i]));
  }

  m.gamestate(WriteGameStateXML(gpGame));
  m.script(GetScriptContents());
  WriteMapVariablesXML(m);
  
  xml_schema::namespace_infomap infomap;
  infomap[""].name = "ironfist_save";
  infomap[""].schema = "map_xml.xsd";

  ironfist_save::save(os, m, infomap);

  return 1;
}