#include "game/game.h"
#include "game/ironfist_xml.h"
#include "gui/dialog.h"

#include "lib/tinyxml2/tinyxml2.h"

#include<io.h>
#include<fcntl.h>


extern unsigned char giCurPlayerBit;


void game::LoadGame(char* fileName, int newGame, int a3) {   
  if (newGame) {
    this->SetupOrigData();

    gpGame->ResetIronfistGameState();

    for (int i = 0; i < MAX_HEROES; i++) {
      //SetupOrigData clears out spellsLearned. Of course, we've changed
      //spellsLearned from an array to a pointer, so that actually NULLs it out
      this->heroes[i].ResetSpellsLearned();
    }
  } else {
    gbGameOver = 0;
    this->field_660E = 1;
    std::string filePath = ".\\GAMES\\";
    filePath += fileName;

    /*
      * Check if original save format
      */
    int fd = _open(filePath.c_str(), O_BINARY);
    char first_byte;
    _read(fd, &first_byte, sizeof(first_byte));
    _close(fd);

    if(first_byte != '<') {
      this->LoadGame_orig(fileName, newGame, a3);
      return;
    }

    gpAdvManager->PurgeMapChangeQueue();

    gpGame->ResetIronfistGameState();

    ClearMapExtra();
    IronfistXML xmlDoc;
    tinyxml2::XMLError err = xmlDoc.Read(filePath.c_str());
    if(err) {
      H2MessageBox("Could not load XML. " + std::string(xmlDoc.GetError()));
      exit(1);
    }

    if(strnicmp(fileName, "RMT", 3))
      sprintf(gpGame->lastSaveFile, fileName);

    gpAdvManager->heroMobilized = 0;
    gpCurPlayer = &gpGame->players[giCurPlayer];
    giCurPlayerBit = 1 << giCurPlayer;
    for(giCurWatchPlayer = giCurPlayer;
      !gbThisNetHumanPlayer[giCurWatchPlayer];
      giCurWatchPlayer = (giCurWatchPlayer + 1) % this->numPlayers)
      ;
    giCurWatchPlayerBit = 1 << giCurWatchPlayer;
    bShowIt = gbThisNetHumanPlayer[giCurPlayer];
    this->SetupAdjacentMons();
    gpAdvManager->CheckSetEvilInterface(0, -1);
  }
}

int game::SaveGame(char *saveFile, int autosave, signed char baseGame) {
  baseGame = 0;
  gpAdvManager->DemobilizeCurrHero();
  std::string filePath;
  std::string saveName = saveFile;

  if(autosave) {
    if(gbInCampaign)
      filePath = saveName + ".GMC";
    else if(xIsPlayingExpansionCampaign)
      filePath = saveName + ".GXC";
    else {
      int aliveHumanPlayers = 0;
      for(int i = 0; i < NUM_PLAYERS; ++i)
        if(!this->playerDead[i] && gbHumanPlayer[i])
          ++aliveHumanPlayers;
      if(!xIsExpansionMap || baseGame) {
        filePath = saveName + ".GM" + std::to_string(aliveHumanPlayers);
      } else {
        filePath = saveName + ".GX" + std::to_string(aliveHumanPlayers);
      }
    }
  } else {
    filePath = saveName;
  }

  if(strnicmp(filePath.c_str(), "RMT", 3)) {
    filePath = ".\\GAMES\\" + filePath;
    if(strnicmp(filePath.c_str(), "AUTOSAVE", 8) && strnicmp(filePath.c_str(), "PLYREXIT", 8))
      strcpy(gpGame->lastSaveFile, saveName.c_str());
  } else {
    filePath = ".\\DATA\\" + filePath;
  }

  IronfistXML xml;
  tinyxml2::XMLError err = xml.Save(filePath.c_str());
  if(err) {
    H2MessageBox("Could not save XML. " + std::string(xml.GetError()));
    exit(1);
  }
  return 1;
}