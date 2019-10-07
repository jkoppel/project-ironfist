#include "game/game.h"

#include "gui/dialog.h"

#include "xml/save_xml.h"

#include<io.h>
#include<fcntl.h>


extern unsigned char giCurPlayerBit;
extern signed char xNetHasOldPlayers;
extern int bFreshSave;

static std::string GetSaveFileExtension(bool isPickLoad) {
  if(gbInCampaign)
    return ".GMC";
  else if(xIsPlayingExpansionCampaign) {
    int campID = xCampaign.campaignID;
    if(campID <= 3)
      return ".GXC";
    else if(campID == 4) // Ironfist campaign
      return ".GIC";
    else // Custom campaign
      return ".GCC";
  } else {
    int aliveHumanPlayers = 0;
    if(isPickLoad)
      aliveHumanPlayers = iLastMsgNumHumanPlayers;
    else {
      for(int i = 0; i < NUM_PLAYERS; ++i)
        if(!gpGame->playerDead[i] && gbHumanPlayer[i])
          ++aliveHumanPlayers;
    }

    std::string ext;
    if((isPickLoad && gbRemoteOn && xNetHasOldPlayers) || !xIsExpansionMap)
      return ".GM" + std::to_string(aliveHumanPlayers);
    else
      return ".GX" + std::to_string(aliveHumanPlayers);
  }
}

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

  if(autosave)
    filePath = saveName + GetSaveFileExtension(false);
  else
    filePath = saveName;

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

int game::PickLoadGame() {
  if(gbWaitForRemoteReceive)
    return 1;

  if(gbRemoteOn && xNetHasOldPlayers && !gbInCampaign && !xIsPlayingExpansionCampaign) {
    NormalDialog("At least one player does not have the Heroes II Expansion set.  You will only be able to choose from original Heroes II games.",
      1, -1, -1, -1, 0, -1, 0, -1, 0);
  } else if (!gbInCampaign && !xIsPlayingExpansionCampaign) {
    heroWindow *window = new heroWindow(405, 8, "x_mapmnu.bin");
    if(!window)
      MemError();

    gpWindowManager->DoDialog(window, ExpStdGameHandler, 0);
    delete window;
    switch(gpWindowManager->buttonPressedCode) {
      case 1:
        xIsExpansionMap = 0;
        break;
      case 2:
        xIsExpansionMap = 1;
        break;
      case BUTTON_CANCEL:
        return 0;
    }    
  }  

  std::string ext = GetSaveFileExtension(true);
  std::string ext2 = "*" + ext;

  // This is done in order to avoid error messages hardcoded in fileRequester::Main
  int tmp = giDebugLevel;
  int tmp2 = iLastMsgNumHumanPlayers;
  if(xCampaign.campaignID >= 4) {
    iLastMsgNumHumanPlayers = 999;
    giDebugLevel = 3;
  }

  fileRequester *loadDialog = new fileRequester(200, 58, 2, &ext2[0u], ".\\GAMES\\", &ext[0u]);
  if(!loadDialog)
    MemError();

  int buttonCode = gpExec->DoDialog(loadDialog);
  delete loadDialog;

  iLastMsgNumHumanPlayers = tmp2;
  giDebugLevel = tmp;
  if(buttonCode == BUTTON_OK) {
    gpGame->LoadGame(gLastFilename, 0, 0);
    return 1;
  } else
    return 0;
}

int __fastcall SaveGame() {  
  gpAdvManager->DisableButtons();
  gpMouseManager->SetPointer("advmice.mse", 0, -999);

  int numHumanPlayers = 0;
  for(int i = 0; i < NUM_PLAYERS; ++i) {
    if(!gpGame->playerDead[i]) {
      if(gbHumanPlayer[i])
        ++numHumanPlayers;
    }
  }
  
  std::string ext1 = GetSaveFileExtension(false);
  std::string ext2 = "*" + ext1;
  fileRequester *saveDialog = new fileRequester(131, 58, 3, &ext2[0u], ".\\GAMES\\", &ext1[0u]);
  if(!saveDialog)
    MemError();

  int result = 0;
  int returnCode = gpExec->DoDialog(saveDialog);
  if(returnCode == BUTTON_OK) {
    result = 1;
    bFreshSave = 1;
    result = gpGame->SaveGame(gLastFilename, 0, 0);
    if(result)
      NormalDialog("Game saved successfully.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  delete saveDialog;
  gpAdvManager->EnableButtons();
  return result;
}