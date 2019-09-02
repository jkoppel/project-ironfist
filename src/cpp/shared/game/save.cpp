#include "adventure/adv.h"
#include "artifacts.h"
#include "base.h"
#include "adventure/map.h"
#include "campaign/campaign.h"
#include "game/game.h"
#include "game/ironfist_xml.h"
#include "game/map_xml.hxx"
#include "scripting/scripting.h"
#include "spell/spells.h"
#include "gui/dialog.h"
#include "skills.h"

#include "lib/tinyxml2/tinyxml2.h"
#include<iostream>
#include<fstream>
#include<io.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <map>

extern int bShowIt;
extern unsigned char giCurPlayerBit;
extern int giCurWatchPlayer;
extern unsigned char giCurWatchPlayerBit;
extern void __fastcall GenerateStandardFileName(char*, char*);


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

      gpAdvManager->PurgeMapChangeQueue();

      ClearMapExtra();
      IronfistXML xmlDoc;
      xmlDoc.Read(v8);
      if(strnicmp(filnam, "RMT", 3))
        sprintf(gpGame->lastSaveFile, filnam);

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
  if(autosave) {
    if(gbInCampaign)
      sprintf(path, "%s.%s", saveFile, "GMC");
    else if(xIsPlayingExpansionCampaign)
      sprintf(path, "%s.%s", saveFile, "GXC");
    else {
      int aliveHumanPlayers = 0;
      for(int i = 0; i < NUM_PLAYERS; ++i)
        if(!this->playerDead[i] && gbHumanPlayer[i])
          ++aliveHumanPlayers;
      if(!xIsExpansionMap || baseGame) {
        sprintf(path, "%s.GM%d", saveFile, aliveHumanPlayers);
      } else {
        sprintf(path, "%s.GX%d", saveFile, aliveHumanPlayers);
      }
    }
  } else {
    sprintf(path, saveFile);
  }

  if(strnicmp(path, "RMT", 3)) {
    sprintf(v9, "%s%s", ".\\GAMES\\", &path);
    if(strnicmp(path, "AUTOSAVE", 8) && strnicmp(path, "PLYREXIT", 8))
      strcpy(gpGame->lastSaveFile, saveFile);
  } else {
    sprintf(v9, "%s%s", ".\\DATA\\", path);
  }

  IronfistXML xml;
  xml.Save(v9);
  return 1;
}