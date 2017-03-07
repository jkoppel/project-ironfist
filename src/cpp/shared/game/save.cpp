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

static void ReadGameStateXML(ironfist_map::gamestate_t& gs, game* gam) {
  ClearMapExtra();
  gam->allowAIArmySharing = gs.allowAIArmySharing();
  gam->map.width = gs.mapWidth();
  gam->map.height = gs.mapHeight();
  gam->SetMapSize(gam->map.width, gam->map.height);

  SMapHeader *mh = &gam->mapHeader;
  mh->field_0 = gs.mapHeader().back().field_0();
  mh->field_4 = gs.mapHeader().back().field_4();
  mh->width = gs.mapHeader().back().width();
  mh->height = gs.mapHeader().back().height();
  mh->numPlayers = gs.mapHeader().back().numPlayers();
  mh->minHumans = gs.mapHeader().back().minHumans();
  mh->maxHumans = gs.mapHeader().back().maxHumans();
  mh->winConditionType = gs.mapHeader().back().winConditionType();
  mh->field_1E = gs.mapHeader().back().field_1E();
  mh->allowDefeatAllVictory = gs.mapHeader().back().allowDefeatAllVictory();
  mh->winConditionArgument = gs.mapHeader().back().winConditionArgument();
  mh->field_22 = gs.mapHeader().back().field_22();
  mh->field_23 = gs.mapHeader().back().field_23();
  mh->field_24 = gs.mapHeader().back().field_24();
  mh->noStartingHeroInCastle = gs.mapHeader().back().noStartingHeroInCastle();
  mh->field_2C = gs.mapHeader().back().field_2C();
  mh->field_2E = gs.mapHeader().back().field_2E();
  mh->field_32 = gs.mapHeader().back().field_32();
  mh->field_36 = gs.mapHeader().back().field_36();
  mh->field_37 = gs.mapHeader().back().field_37();
  mh->nextTownName = gs.mapHeader().back().nextTownName();
  mh->field_39 = gs.mapHeader().back().field_39();
  strcpy(gam->mapHeader.name, gs.mapHeader().back().name().c_str());
  strcpy(gam->mapHeader.description, gs.mapHeader().back().description().c_str());
  mh->field_1A0 = gs.mapHeader().back().field_1A0();
  mh->field_1A1 = gs.mapHeader().back().field_1A1();
  mh->numRumors = gs.mapHeader().back().numRumors();
  mh->numEvents = gs.mapHeader().back().numEvents();

  for (int i = 0; i < gs.mapHeader().back().hasPlayer().size(); i++) {
    mh->hasPlayer[i] = gs.mapHeader().back().hasPlayer().at(i).player();
    mh->playerMayBeHuman[i] = gs.mapHeader().back().playerMayBeHuman().at(i).player();
    mh->playerMayBeComp[i] = gs.mapHeader().back().playerMayBeComp().at(i).player();
    mh->playerFactions[i] = gs.mapHeader().back().playerFactions().at(i).player();
  }

  gam->field_44D = gs.field_44D();
  gam->field_451 = gs.field_451();
  for (int i = 0; i < gs.playerHandicap().size(); i++) {
    gam->playerHandicap[i] = gs.playerHandicap().at(i).handicap().get();
    gam->field_459[i] = gs.field_459().at(i).value().get();
    gam->field_45F[i] = gs.field_45F().at(i).value().get();
  }
  gam->difficulty = gs.difficulty();
  strcpy(gam->mapFilename, gs.mapFilename().c_str());
  gam->gameDifficulty = gs.gameDifficulty();
  giMonthType = gs.monthType();
  giMonthTypeExtra = gs.monthTypeExtra();
  giWeekType = gs.weekType();
  giWeekTypeExtra = gs.weekTypeExtra();
  for (int i = 0; i < gs.playerNames().size(); i++) {
    strcpy(cPlayerNames[i], gs.playerNames().at(i).name().get().c_str());
  }
  gpAdvManager->PurgeMapChangeQueue();
  giMapChangeCtr = gs.mapChangeCtr();
  gam->numPlayers = gs.numPlayers();
  giCurPlayer = gs.currentPlayer();
  gam->couldBeNumDefeatedPlayers = gs.numDefatedPlayers();

  char hasPlayer[6];
  int c = 0;
  for (int i = 0; i < gs.deadPlayers().size(); i++) {
    gam->playerDead[i] = gs.deadPlayers().at(i).playerID().get();
    hasPlayer[i] = gs.alivePlayers().at(i).playerID().get();
    if (hasPlayer[i] && c < iLastMsgNumHumanPlayers) {
      c++;
      gbHumanPlayer[i] = 1;
    } else {
      gbHumanPlayer[i] = 0;
    }
  }

  for (int i = 0; i < 6; ++i) {
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
    gam->players[i].color = gs.playerData().at(i).color();
    gam->players[i].numHeroes = gs.playerData().at(i).numHeroes();
    gam->players[i].curHeroIdx = gs.playerData().at(i).curHeroIdx();
    gam->players[i].field_3 = gs.playerData().at(i).field_3();
    for (int j = 0; j < gs.playerData().at(i).heroesForPurchase().size(); j++) {
      gam->players[i].heroesForPurchase[j] = gs.playerData().at(i).heroesForPurchase().at(j).hero().get();
    }
    for (int j = 0; j < gs.playerData().at(i).heroesOwned().size(); j++) {
      gam->players[i].heroesOwned[j] = gs.playerData().at(i).heroesOwned().at(j).hero().get();
    }
    gam->_B[1] = gs.playerData().at(i).game_B();
    gam->players[i]._3[0] = gs.playerData().at(i)._3();
    gam->players[i].personality = gs.playerData().at(i).personality();
    gam->players[i]._2 = gs.playerData().at(i)._2();
    gam->players[i]._4_1 = gs.playerData().at(i)._4_1();
    gam->players[i].field_40 = gs.playerData().at(i).field_40();
    gam->players[i].field_41 = gs.playerData().at(i).field_41();
    gam->players[i].daysLeftWithoutCastle = gs.playerData().at(i).daysLeftWithoutCastle();
    gam->players[i].numCastles = gs.playerData().at(i).numCastles();
    gam->players[i].field_45 = gs.playerData().at(i).field_45();
    for (int j = 0; j < gs.playerData().at(i).castlesOwned().size(); j++) {
      gam->players[i].castlesOwned[j] = gs.playerData().at(i).castlesOwned().at(j).castle().get();
    }
    for (int j = 0; j < gs.playerData().at(i).resources().size(); j++) {
      gam->players[i].resources[j] = gs.playerData().at(i).resources().at(j).quantity().get();
    }
    for (int j = 0; j < gs.playerData().at(i).field_E7().size(); j++) {
      gam->players[i].field_E7[j] = gs.playerData().at(i).field_E7().at(j).value().get();
    }
    gam->players[i].barrierTentsVisited = gs.playerData().at(i).barrierTentsVisited();
    for (int j = 0; j < gs.playerData().at(i)._4_2().size(); j++) {
      gam->players[i]._4_2[j] = gs.playerData().at(i)._4_2().at(j).value().get();
    }
  }
  gam->numObelisks = gs.numObelisks();

  for (int i = 0; i < gs.heroHireStatus().size(); i++) {
    gam->relatedToHeroForHireStatus[i] = gs.heroHireStatus().at(i).status().get();
  }
  for (int i = 0; i < gs.towns().size(); i++) {
    gam->castles[i].idx = gs.towns().at(i).idx();
    gam->castles[i].ownerIdx = gs.towns().at(i).ownerIdx();
    gam->castles[i].alignment = gs.towns().at(i).alignment();
    gam->castles[i].factionID = gs.towns().at(i).factionID();
    gam->castles[i].x = gs.towns().at(i).x();
    gam->castles[i].y = gs.towns().at(i).y();
    gam->castles[i].buildDockRelated = gs.towns().at(i).buildDockRelated();
    gam->castles[i].field_7 = gs.towns().at(i).field_7();
    gam->castles[i].visitingHeroIdx = gs.towns().at(i).visitingHeroIdx();
    gam->castles[i].buildingsBuiltFlags = gs.towns().at(i).buildingsBuiltFlags();
    gam->castles[i].mageGuildLevel = gs.towns().at(i).mageGuildLevel();
    gam->castles[i].field_1D = gs.towns().at(i).field_1D();
    gam->castles[i].exists = gs.towns().at(i).exists();
    gam->castles[i].mayNotBeUpgradedToCastle = gs.towns().at(i).mayNotBeUpgradedToCastle();
    gam->castles[i].field_38 = gs.towns().at(i).field_38();
    gam->castles[i].playerPos = gs.towns().at(i).playerPos();
    gam->castles[i].extraIdx = gs.towns().at(i).extraIdx();
    gam->castles[i].field_55 = gs.towns().at(i).field_55();
    gam->castles[i].field_63 = gs.towns().at(i).field_63();
    strcpy(gam->castles[i].name, gs.towns().at(i).name().c_str());
    for (int j = 0; j < gs.towns().at(i).garrison().back().creature().size(); j++) {
      gam->castles[i].garrison.creatureTypes[i] = gs.towns().at(i).garrison().back().creature().at(j).type();
      gam->castles[i].garrison.quantities[i] = gs.towns().at(i).garrison().back().creature().at(j).quantity();
    }
    for (int j = 0; j < gs.towns().at(i).numCreaturesInDwelling().size(); j++) {
      gam->castles[i].numCreaturesInDwelling[j] = gs.towns().at(i).numCreaturesInDwelling().at(j).quantity().get();
    }
    for (int j = 0; j < gs.towns().at(i).mageGuildSpells().size(); j++) {
      *(gam->castles[i].mageGuildSpells[0] + j) = gs.towns().at(i).mageGuildSpells().at(j).spell().get();
    }
    for (int j = 0; j < gs.towns().at(i).numSpellsOfLevel().size(); j++) {
      gam->castles[i].numSpellsOfLevel[j] = gs.towns().at(i).numSpellsOfLevel().at(j).spell().get();
    }
  }
  for (int i = 0; i < gs.field_2773().size(); i++) {
    gam->field_2773[i] = gs.field_2773().at(i).value().get();
  }
  for (int i = 0; i < gs.field_27BB().size(); i++) {
    gam->field_27BB[i] = gs.field_27BB().at(i).value().get();
  }
  for (int i = 0; i < gs.mine().size(); i++) {
    gam->mines[i].field_0 = gs.mine().at(i).field_0();
    gam->mines[i].owner = gs.mine().at(i).owner();
    gam->mines[i].type = gs.mine().at(i).type();
    gam->mines[i].guardianType = gs.mine().at(i).guardianType();
    gam->mines[i].guadianQty = gs.mine().at(i).guardianQty();
    gam->mines[i].x = gs.mine().at(i).x();
    gam->mines[i].y = gs.mine().at(i).y();
  }
  for (int i = 0; i < gs.field_60A6().size(); i++) {
    gam->field_60A6[i] = gs.field_60A6().at(i).value().get();
  }
  for (int i = 0; i < gs.randomArtifacts().size(); i++) {
    gam->artifactGeneratedRandomly[i] = gs.randomArtifacts().at(i).artifact().get();
  }
  for (int i = 0; i < gs.boat().size(); i++) {
    gam->boats[i].idx = gs.boat().at(i).idx();
    gam->boats[i].x = gs.boat().at(i).x();
    gam->boats[i].y = gs.boat().at(i).y();
    gam->boats[i].field_3 = gs.boat().at(i).field_3();
    gam->boats[i].underlyingObjType = gs.boat().at(i).underlyingObjType();
    gam->boats[i].underlyingObjExtra = gs.boat().at(i).underlyingObjExtra();
    gam->boats[i].field_6 = gs.boat().at(i).field_6();
    gam->boats[i].owner = gs.boat().at(i).owner();
  }
  for (int i = 0; i < gs.boatBuilt().size(); i++) {
    gam->boatBuilt[i] = gs.boatBuilt().at(i).boat().get();
  }
  for (int i = 0; i < gs.obeliskVisitedMasks().size(); i++) {
    gam->obeliskVisitedMasks[i] = gs.obeliskVisitedMasks().at(i).obelisk().get();
  }
  gam->field_6395 = gs.field_6395();
  gam->field_6396 = gs.field_6396();
  gam->field_6397 = gs.field_6397();
  strcpy(gam->currentRumor, gs.currentRumor().c_str());
  for (int i = 0; i < gs.field_637D().size(); i++) {
    gam->field_637D[i] = gs.field_637D().at(i).value().get();
  }
  gam->numRumors = gs.numRumors();
  gam->numEvents = gs.numEvents();
  gam->field_657B = gs.field_657B();
  for (int i = 0; i < 2 * gam->field_657B; i++) {
    gam->_D[i] = gs._D().at(i).value().get();
  }
  iMaxMapExtra = gs.maxMapExtra();

  for (int i = 0; i < gs.rumorIndices().size(); i++) {
    gam->rumorIndices[i] = gs.rumorIndices().at(i).index().get();
  }
  for (int i = 0; i < gs.eventIndices().size(); i++) {
    gam->eventIndices[i] = gs.eventIndices().at(i).index().get();
  }
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

  for (int i = 0; i < gs.mapRevealed().size(); i++) {
    mapRevealed[i] = gs.mapRevealed().at(i).revealed().get();
  }

  gam->map.width = gs.fullMap().back().width();
  gam->map.height = gs.fullMap().back().height();
  gam->map.Init(gam->map.width, gam->map.height);
  for (int i = 0; i < gs.fullMap().back().mapCell().size(); i++) {
    gam->map.tiles[i].groundIndex = gs.fullMap().back().mapCell().at(i).groundIndex();
    gam->map.tiles[i].hasObject = gs.fullMap().back().mapCell().at(i).hasObject();
    gam->map.tiles[i].isRoad = gs.fullMap().back().mapCell().at(i).isRoad();
    gam->map.tiles[i].objTileset = gs.fullMap().back().mapCell().at(i).objTileset();
    gam->map.tiles[i].objectIndex = gs.fullMap().back().mapCell().at(i).objectIndex();
    gam->map.tiles[i].field_4_1 = gs.fullMap().back().mapCell().at(i).field_4_1();
    gam->map.tiles[i].isShadow = gs.fullMap().back().mapCell().at(i).isShadow();
    gam->map.tiles[i].field_4_3 = gs.fullMap().back().mapCell().at(i).field_4_3();
    gam->map.tiles[i].extraInfo = gs.fullMap().back().mapCell().at(i).extraInfo();
    gam->map.tiles[i].hasOverlay = gs.fullMap().back().mapCell().at(i).hasOverlay();
    gam->map.tiles[i].hasLateOverlay = gs.fullMap().back().mapCell().at(i).hasLateOverlay();
    gam->map.tiles[i].overlayTileset = gs.fullMap().back().mapCell().at(i).overlayTileset();
    gam->map.tiles[i].overlayIndex = gs.fullMap().back().mapCell().at(i).overlayIndex();
    gam->map.tiles[i].displayFlags = gs.fullMap().back().mapCell().at(i).displayFlags();
    gam->map.tiles[i].objType = gs.fullMap().back().mapCell().at(i).objType();
    gam->map.tiles[i].extraIdx = gs.fullMap().back().mapCell().at(i).extraIdx();
  }
  gam->map.numCellExtras = gs.fullMap().back().numCellExtras();
  if (gam->map.numCellExtras)
    delete(gam->map.cellExtras);
  gam->map.cellExtras = (mapCellExtra *)operator new(7 * gam->map.numCellExtras);

  for (int i = 0; i < gs.fullMap().back().mapCellExtra().size(); i++) {
    gam->map.cellExtras[i].nextIdx = gs.fullMap().back().mapCellExtra().at(i).nextIdx();
    gam->map.cellExtras[i].animatedObject = gs.fullMap().back().mapCellExtra().at(i).animatedObject();
    gam->map.cellExtras[i].objTileset = gs.fullMap().back().mapCellExtra().at(i).objTileset();
    gam->map.cellExtras[i].objectIndex = gs.fullMap().back().mapCellExtra().at(i).objectIndex();
    gam->map.cellExtras[i].field_4_1 = gs.fullMap().back().mapCellExtra().at(i).field_4_1();
    gam->map.cellExtras[i].field_4_2 = gs.fullMap().back().mapCellExtra().at(i).field_4_2();
    gam->map.cellExtras[i].field_4_3 = gs.fullMap().back().mapCellExtra().at(i).field_4_3();
    gam->map.cellExtras[i].field_4_4 = gs.fullMap().back().mapCellExtra().at(i).field_4_4();
    gam->map.cellExtras[i].animatedLateOverlay = gs.fullMap().back().mapCellExtra().at(i).animatedLateOverlay();
    gam->map.cellExtras[i].hasLateOverlay = gs.fullMap().back().mapCellExtra().at(i).hasLateOverlay();
    gam->map.cellExtras[i].tileset = gs.fullMap().back().mapCellExtra().at(i).tileset();
    gam->map.cellExtras[i].overlayIndex = gs.fullMap().back().mapCellExtra().at(i).overlayIndex();
  }
}

ironfist_map::gamestate_t WriteGameStateXML(game* gam) {

  ironfist_map::gamestate_t gs(
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

  gs.mapHeader().push_back(ironfist_map::gamestate_t::mapHeader_type(
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

  for (int i = 0; i < ELEMENTS_IN(mh->hasPlayer); i++) {
    gs.mapHeader().back().hasPlayer().push_back(ironfist_map::gamestate_t::mapHeader_type::hasPlayer_type(mh->hasPlayer[i]));
    gs.mapHeader().back().playerMayBeHuman().push_back(ironfist_map::gamestate_t::mapHeader_type::playerMayBeHuman_type(mh->playerMayBeHuman[i]));
    gs.mapHeader().back().playerMayBeComp().push_back(ironfist_map::gamestate_t::mapHeader_type::playerMayBeComp_type(mh->playerMayBeComp[i]));
    gs.mapHeader().back().playerFactions().push_back(ironfist_map::gamestate_t::mapHeader_type::playerFactions_type(mh->playerFactions[i]));
  }

  for (int i = 0; i < ELEMENTS_IN(cPlayerNames); i++) {
    gs.playerNames().push_back(ironfist_map::gamestate_t::playerNames_type(i));
    gs.playerNames().back().name(cPlayerNames[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->playerDead); i++) {
    gs.deadPlayers().push_back(ironfist_map::gamestate_t::deadPlayers_type(i));
    gs.deadPlayers().back().playerID(gam->playerDead[i]);
  }

  char playerAlive[6];
  for (int i = 0; i < 6; ++i) {
    playerAlive[i] = gbHumanPlayer[i];
    if (gam->playerDead[i])
      playerAlive[i] = 0;
  }

  for (int i = 0; i < ELEMENTS_IN(playerAlive); i++) {
    gs.alivePlayers().push_back(ironfist_map::gamestate_t::alivePlayers_type(i));
    gs.alivePlayers().back().playerID(playerAlive[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->relatedToHeroForHireStatus); i++) {
    gs.heroHireStatus().push_back(ironfist_map::gamestate_t::heroHireStatus_type(i));
    gs.heroHireStatus().back().status(gam->relatedToHeroForHireStatus[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->playerHandicap); i++) {
    gs.playerHandicap().push_back(ironfist_map::gamestate_t::playerHandicap_type(i));
    gs.playerHandicap().back().handicap(gam->playerHandicap[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->field_459); i++) {
    gs.field_459().push_back(ironfist_map::gamestate_t::field_459_type(i));
    gs.field_459().back().value(gam->field_459[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->field_45F); i++) {
    gs.field_45F().push_back(ironfist_map::gamestate_t::field_45F_type(i));
    gs.field_45F().back().value(gam->field_45F[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->field_2773); i++) {
    gs.field_2773().push_back(ironfist_map::gamestate_t::field_2773_type(i));
    gs.field_2773().back().value(gam->field_2773[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->field_27BB); i++) {
    gs.field_27BB().push_back(ironfist_map::gamestate_t::field_27BB_type(i));
    gs.field_27BB().back().value(gam->field_27BB[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->field_60A6); i++) {
    gs.field_60A6().push_back(ironfist_map::gamestate_t::field_60A6_type(i));
    gs.field_60A6().back().value(gam->field_60A6[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->artifactGeneratedRandomly); i++) {
    gs.randomArtifacts().push_back(ironfist_map::gamestate_t::randomArtifacts_type(i));
    gs.randomArtifacts().back().artifact(gam->artifactGeneratedRandomly[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->boatBuilt); i++) {
    gs.boatBuilt().push_back(ironfist_map::gamestate_t::boatBuilt_type(i));
    gs.boatBuilt().back().boat(gam->boatBuilt[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->obeliskVisitedMasks); i++) {
    gs.obeliskVisitedMasks().push_back(ironfist_map::gamestate_t::obeliskVisitedMasks_type(i));
    gs.obeliskVisitedMasks().back().obelisk(gam->obeliskVisitedMasks[i]);
  }

  for (int i = 0; i < ELEMENTS_IN(gam->field_637D); i++) {
    gs.field_637D().push_back(ironfist_map::gamestate_t::field_637D_type(i));
    gs.field_637D().back().value(gam->field_637D[i]);
  }
  for (int i = 0; i < ELEMENTS_IN(gam->rumorIndices); i++) {
    gs.rumorIndices().push_back(ironfist_map::gamestate_t::rumorIndices_type(i));
    gs.rumorIndices().back().index(gam->rumorIndices[i]);
  }
  for (int i = 0; i < ELEMENTS_IN(gam->eventIndices); i++) {
    gs.eventIndices().push_back(ironfist_map::gamestate_t::eventIndices_type(i));
    gs.eventIndices().back().index(gam->eventIndices[i]);
  }
  for (int i = 0; i < ELEMENTS_IN(gam->_D); i++) {
    gs._D().push_back(ironfist_map::gamestate_t::_D_type(i));
    gs._D().back().value(gam->_D[i]);
  }
  for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    int x = i % MAP_HEIGHT;
    int y = i / MAP_HEIGHT;
    gs.mapRevealed().push_back(ironfist_map::gamestate_t::mapRevealed_type(x, y));
    gs.mapRevealed().back().revealed(mapRevealed[i]);
  }

  for (int i = 1; i < iMaxMapExtra; i++) {
    gs.mapExtra().push_back(ironfist_map::gamestate_t::mapExtra_type());
    for (int j = 0; j < pwSizeOfMapExtra[i]; j++) {
      gs.mapExtra().back().ppMapExtra().push_back(ironfist_map::mapExtra_t::ppMapExtra_type());
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

    ironfist_map::gamestate_t::playerData_type data(
      player.color,
      player.numHeroes,
      player.curHeroIdx,
      player.field_3,
      gam->_B[1],
      player._3[0],
      player.personality,
      player._2,
      player._4_1,
      player.field_40,
      player.field_41,
      player.daysLeftWithoutCastle,
      player.numCastles,
      player.field_45,
      player.barrierTentsVisited
    );
    gs.playerData().push_back(data);

    for (int j = 0; j < ELEMENTS_IN(player.heroesOwned); j++) {
      gs.playerData().back().heroesOwned().push_back(ironfist_map::playerData_t::heroesOwned_type(j));
      gs.playerData().back().heroesOwned().back().hero(player.heroesOwned[j]);
    }

    for (int j = 0; j < ELEMENTS_IN(player.heroesForPurchase); j++) {
      gs.playerData().back().heroesForPurchase().push_back(ironfist_map::playerData_t::heroesForPurchase_type(j));
      gs.playerData().back().heroesForPurchase().back().hero(player.heroesForPurchase[j]);
    }

    for (int j = 0; j < ELEMENTS_IN(player.castlesOwned); j++) {
      gs.playerData().back().castlesOwned().push_back(ironfist_map::playerData_t::castlesOwned_type(j));
      gs.playerData().back().castlesOwned().back().castle(player.castlesOwned[j]);
    }

    for (int j = 0; j < ELEMENTS_IN(player.resources); j++) {
      gs.playerData().back().resources().push_back(ironfist_map::playerData_t::resources_type(j));
      gs.playerData().back().resources().back().quantity(player.resources[j]);
    }

    for (int j = 0; j < ELEMENTS_IN(player.field_E7); j++) {
      gs.playerData().back().field_E7().push_back(ironfist_map::playerData_t::field_E7_type(j));
      gs.playerData().back().field_E7().back().value(player.field_E7[j]);
    }

    for (int j = 0; j < 6; j++) {
      gs.playerData().back()._4_2().push_back(ironfist_map::playerData_t::_4_2_type(j));
      gs.playerData().back()._4_2().back().value(player._4_2[j]);
    }
  }

  for (int i = 0; i < ELEMENTS_IN(gam->castles); i++) {
    town twn = gam->castles[i];
    ironfist_map::gamestate_t::towns_type data(
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

    for (int j = 0; j < ELEMENTS_IN(twn.numCreaturesInDwelling); j++) {
      gs.towns().back().numCreaturesInDwelling().push_back(ironfist_map::town_t::numCreaturesInDwelling_type(j));
      gs.towns().back().numCreaturesInDwelling().back().quantity(twn.numCreaturesInDwelling[j]);
    }

    for (int j = 0; j < 20; j++) {
      int x = j % 5;
      int y = j / 5;
      gs.towns().back().mageGuildSpells().push_back(ironfist_map::town_t::mageGuildSpells_type(j));
      gs.towns().back().mageGuildSpells().back().spell(twn.mageGuildSpells[x][y]);
    }

    for (int j = 0; j < ELEMENTS_IN(twn.numSpellsOfLevel); j++) {
      gs.towns().back().numSpellsOfLevel().push_back(ironfist_map::town_t::numSpellsOfLevel_type(j));
      gs.towns().back().numSpellsOfLevel().back().spell(twn.numSpellsOfLevel[j]);
    }

    gs.towns().back().garrison().push_back(ironfist_map::town_t::garrison_type());
    for (int j = 0; j < ELEMENTS_IN(twn.garrison.creatureTypes); j++) {
      gs.towns().back().garrison().back().creature().push_back(ironfist_map::armyGroup_t::creature_type(twn.garrison.creatureTypes[j], twn.garrison.quantities[j]));
    }
  }

  for (int i = 0; i < ELEMENTS_IN(gam->mines); i++) {
    mine *m = &gam->mines[i];
    gs.mine().push_back(ironfist_map::gamestate_t::mine_type(m->field_0, m->owner, m->type, m->guardianType, m->guadianQty, m->x, m->y));
  }
  for (int i = 0; i < ELEMENTS_IN(gam->boats); i++) {
    boat *b = &gam->boats[i];
    gs.boat().push_back(ironfist_map::gamestate_t::boat_type(b->idx, b->x, b->y, b->field_3, b->underlyingObjType, b->underlyingObjExtra, b->field_6, b->owner));
  }

  fullMap *map = &gam->map;
  gs.fullMap().push_back(ironfist_map::gamestate_t::fullMap_type(map->width, map->height, map->numCellExtras));
  for (int i = 0; i < map->height * map->width; i++) {
    mapCell *c = &map->tiles[i];
    ironfist_map::fullMap_t::mapCell_type cell(
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
    gs.fullMap().back().mapCell().push_back(cell);
  }
  for (int i = 0; i < map->numCellExtras; i++) {
    mapCellExtra *e = &map->cellExtras[i];
    ironfist_map::fullMap_t::mapCellExtra_type cellExtra(
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
    gs.fullMap().back().mapCellExtra().push_back(cellExtra);
  }
  return gs;
}

static void ReadHeroXML(ironfist_map::hero_t& hx, hero* hro) {
  hro->Clear();

  hro->army = armyGroup();

  int i = 0;
  for (ironfist_map::army_t::slot_const_iterator it = hx.army().slot().begin();
    it != hx.army().slot().end();
    it++,
    i++) {

    hro->army.Add(it->id().get(), it->quantity().get(), i);
  }


  memset(hro->artifacts, -1, sizeof(hro->artifacts));
  i = 0;
  for (ironfist_map::hero_t::artifact_const_iterator jt = hx.artifact().begin();
    jt != hx.artifact().end();
    jt++,
    i++) {

    hro->artifacts[i] = jt->id();
    hro->scrollSpell[i] = jt->spell();
  }

  int nSS = 0;
  for (ironfist_map::hero_t::secondarySkill_const_iterator it =
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

  for (ironfist_map::hero_t::spell_const_iterator it = hx.spell().begin();
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

luaTable *ReadMapVarXML(ironfist_map::table_t table) {

  luaTable *lt = new luaTable;
  for (ironfist_map::table_t::tableElement_const_iterator tableE = table.tableElement().begin();
    tableE != table.tableElement().end(); tableE++) {
    mapVariable *mapVar = new mapVariable;
    mapVar->type = StringToMapVarType(tableE->type());

    std::string *sV = new std::string(tableE->value().get());
    mapVar->singleValue = sV;
    (*lt)[tableE->key().get()] = *mapVar;
  }

  for (ironfist_map::table_t::table_const_iterator subTable = table.table().begin();
    subTable != table.table().end(); subTable++) {
    mapVariable *mapVar = new mapVariable;
    mapVar->type = MAPVAR_TYPE_TABLE;
    mapVar->tableValue = ReadMapVarXML(*subTable);
    (*lt)[subTable->tableId().get()] = *mapVar;
  }
  return lt;
}

ironfist_map::hero_t WriteHeroXML(hero* hro) {

  ironfist_map::army_t arm;

  for (int i = 0; i < ELEMENTS_IN(hro->army.creatureTypes); i++) {
    ironfist_map::slot_t sl;
    sl.id(hro->army.creatureTypes[i]);
    sl.quantity(hro->army.quantities[i]);

    arm.slot().push_back(sl);
  }

  ironfist_map::hero_t hx(
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
    ironfist_map::secondarySkill sk;
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
    hx.artifact().push_back(ironfist_map::hero_t::artifact_type(hro->artifacts[i]));
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

static ironfist_map::table_t WriteMapVariableTableXML(std::string id, luaTable *lt) {
  ironfist_map::table_t xsdTable;
  xsdTable.tableId(id);
  for (luaTable::const_iterator it = (*lt).begin(); it != (*lt).end(); ++it) {
    if (it->second.type == MAPVAR_TYPE_TABLE) {
      xsdTable.table().push_back(WriteMapVariableTableXML(it->first, it->second.tableValue));
    } else {
      ironfist_map::tableElement_t element;
      element.key(it->first);
      element.type(MapVarTypeToString(it->second.type));
      element.value(*it->second.singleValue);
      xsdTable.tableElement().push_back(element);
    }
  }
  return xsdTable;
}

static void WriteMapVariablesXML(ironfist_map::map_t& m) {

  std::map<std::string, mapVariable> mapVariables = LoadMapVariablesFromLUA();

  for (std::map<std::string, mapVariable>::const_iterator it = mapVariables.begin(); it != mapVariables.end(); ++it) {
    ironfist_map::mapVariable_t mapVar;
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

      std::auto_ptr<ironfist_map::map_t> mp = ironfist_map::map(std::string(v8));

      int i = 0;
      for (ironfist_map::map_t::hero_const_iterator it = mp->hero().begin();
        it != mp->hero().end();
        it++, i++) {
        ironfist_map::hero_t hx = *it;
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
      for (ironfist_map::map_t::mapVariable_const_iterator it = mp->mapVariable().begin();
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
  void* extraMemory = ALLOC(50000);
  memset(extraMemory, 0, 50000u);
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

  int fd = open(tmpFileName, O_WRONLY | O_TRUNC | O_CREAT | O_BINARY, S_IWRITE);
  if (fd == -1)
    FileError("tmp");

  _write(fd, &this->map.width, 4);
  _write(fd, &this->map.height, 4);
  _write(fd, &this->mapHeader, 420);
  _write(fd, &this->field_44D, 65);
  _write(fd, this, 2);
  _write(fd, &giMonthType, 1);
  _write(fd, &giMonthTypeExtra, 1);
  _write(fd, &giWeekType, 1);
  _write(fd, &giWeekTypeExtra, 1);
  _write(fd, cPlayerNames, 126);

  char buf[100];

  gpAdvManager->PurgeMapChangeQueue();
  _write(fd, &giMapChangeCtr, 4);
  GenerateStandardFileName(this->lastSaveFile, buf);
  _write(fd, &this->numPlayers, 1);
  int v14 = giCurPlayer;
  _write(fd, &v14, 1);
  _write(fd, &this->couldBeNumDefeatedPlayers, 1);
  _write(fd, this->playerDead, 6);
  char playerAlive[6];
  for (int i = 0; i < 6; ++i) {
    playerAlive[i] = gbHumanPlayer[i];
    if (this->playerDead[i])
      playerAlive[i] = 0;
  }
  _write(fd, playerAlive, 6);
  _write(fd, &this->day, 2);
  _write(fd, &this->week, 2);
  _write(fd, &this->month, 2);
  for (int i = 0; i < 6; ++i)
    this->players[i].Write(fd);
  _write(fd, &this->numObelisks, 1);
  _write(fd, this->relatedToHeroForHireStatus, 54);
  _write(fd, this->castles, 7200);
  _write(fd, this->field_2773, 72);
  _write(fd, this->field_27BB, 9);
  _write(fd, this->mines, 1008);
  _write(fd, this->field_60A6, 144);
  _write(fd, this->artifactGeneratedRandomly, 103);
  _write(fd, this->boats, 384);
  _write(fd, this->boatBuilt, 48);
  _write(fd, this->obeliskVisitedMasks, 48);
  _write(fd, &this->field_6395, 1);
  _write(fd, &this->field_6396, 1);
  _write(fd, &this->field_6397, 1);
  _write(fd, this->currentRumor, 301);
  _write(fd, this->field_637D, 24);
  _write(fd, &this->numRumors, 4);
  _write(fd, this->rumorIndices, 2 * this->numRumors);
  _write(fd, &this->numEvents, 4);
  _write(fd, this->eventIndices, 2 * this->numEvents);
  _write(fd, &this->field_657B, 4);
  _write(fd, this->_D, 2 * this->field_657B);
  _write(fd, &iMaxMapExtra, 4);
  for (int i = 1; i < iMaxMapExtra; ++i) {
    _write(fd, &pwSizeOfMapExtra[i], 2);
    if (ppMapExtra[i])
      _write(fd, ppMapExtra[i], pwSizeOfMapExtra[i]);
    else
      _write(fd, extraMemory, pwSizeOfMapExtra[i]);
  }
  _write(fd, mapRevealed, MAP_HEIGHT * MAP_WIDTH);
  this->map.Write(fd);
  _close(fd);
  FREE(extraMemory);


  unsigned char dat[1000000];
  fd = _open(tmpFileName, O_BINARY);
  lseek(fd, 0, SEEK_END);
  int sz = tell(fd);
  lseek(fd, 0, SEEK_SET);
  read(fd, dat, sz);
  close(fd);
  remove(tmpFileName);

  const xml_schema::base64_binary datbin(dat, sz);

  std::ofstream os(v9);

  ironfist_map::map_t m(datbin);

  for (int i = 0; i < ELEMENTS_IN(this->heroes); i++) {
    m.hero().push_back(WriteHeroXML(&this->heroes[i]));
  }

  m.gamestate(WriteGameStateXML(gpGame));
  m.script(GetScriptContents());
  WriteMapVariablesXML(m);


  xml_schema::namespace_infomap infomap;
  infomap[""].name = "ironfist_map";
  infomap[""].schema = "map_xml.xsd";

  ironfist_map::map(os, m, infomap);

  return 1;
}