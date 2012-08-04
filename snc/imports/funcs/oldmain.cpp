{
  char *v1; // ST1C_4@153
  signed int v2; // eax@153
  int v3; // eax@172
  const char *v4; // ST1C_4@198
  int v5; // ebx@198
  __int16 v6; // ax@198
  int v7; // [sp-4h] [bp-174h]@5
  heroWindow *this; // [sp+24h] [bp-14Ch]@52
  signed int v9; // [sp+28h] [bp-148h]@184
  bool v10; // [sp+28h] [bp-148h]@197
  char v11; // [sp+2Ch] [bp-144h]@122
  char v12; // [sp+32h] [bp-13Eh]@131
  char v13; // [sp+33h] [bp-13Dh]@131
  char v14; // [sp+34h] [bp-13Ch]@122
  char v15[8]; // [sp+12Ch] [bp-44h]@92
  int j; // [sp+134h] [bp-3Ch]@92
  int k; // [sp+138h] [bp-38h]@96
  char v18[8]; // [sp+13Ch] [bp-34h]@92
  int v19; // [sp+144h] [bp-2Ch]@68
  int v20; // [sp+148h] [bp-28h]@11
  int v21; // [sp+154h] [bp-1Ch]@14
  int i; // [sp+158h] [bp-18h]@62
  int v23; // [sp+15Ch] [bp-14h]@133
  int v24; // [sp+164h] [bp-Ch]@3
  int v25; // [sp+168h] [bp-8h]@14
  int v26; // [sp+16Ch] [bp-4h]@14

  if ( bKBDone )
    return 0;
  bKBDone = 1;
  LogStr("OM1");
  LogStr("OM2");
  v24 = -1;
  if ( executive::InitSystem(gpExec) )
    ShutDown("Initialization failed!");
  LogStr("OM3");
  KBChangeMenu(hmnuDflt);
  gPalette = resourceManager::GetPalette(gpResourceManager, "kb.pal");
  gpWindowManager->field_56 = 1;
  smallFont = resourceManager::GetFont(gpResourceManager, "smalfont.fnt");
  bigFont = resourceManager::GetFont(gpResourceManager, "bigfont.fnt");
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  mouseManager::SetColorMice(gpMouseManager, *(&bMenu + 7 * giCurExe + 6));
  LogStr("OM4");
  SetupCDRom();
  LogStr("OM5");
  v7 = -1;
  if ( ((int (__thiscall *)(soundManager *))gpSoundManager->vtable->initialize)(gpSoundManager) )
    ShutDown("Unable to initialize sound.");
  if ( giDebugLevel < 9 )
    CheckMem();
  LogStr("OM6");
  if ( giShowIntro )
  {
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 0, 640u, 480, 0);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
    if ( !gbSkipIntro )
    {
      v20 = gpWindowManager->field_56;
      gpWindowManager->field_56 = 0;
      if ( PlaySmacker(66) )
        PlaySmacker(1);
      PlaySmacker(65);
      gpWindowManager->field_56 = v20;
    }
  }
  LoadSystemwideIcons();
  memset(&gbThisNetHumanPlayer, 0, 6u);
  mouseManager::ShowColorPointer(gpMouseManager);
  v26 = 0;
  v21 = 0;
  v25 = 1;
LABEL_15:
  if ( !v26 )
  {
    while ( 1 )
    {
      do
      {
        while ( 1 )
        {
LABEL_16:
          if ( !gShingleAnim )
            gShingleAnim = resourceManager::GetIcon(gpResourceManager, "shnganim.icn");
          if ( gGameCommand != 105 )
            soundManager::SwitchAmbientMusic(gpSoundManager, 42);
          if ( !v21 )
          {
            if ( gGameCommand != 105 )
            {
              resourceManager::GetBackdrop(gpResourceManager, "heroes.icn", gpWindowManager->screenBuffer, 1);
              heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
              if ( v25 )
                SetPalette(gPalette->contents, 1);
              else
                heroWindowManager::FadeScreen(gpWindowManager, 0, 8, gPalette);
              v25 = 0;
            }
            mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
          }
          v21 = 1;
          if ( gGameCommand != 105 )
            gpWindowManager->field_56 = 1;
          if ( giTCPHostStatus == -1 || !gbTCPFirstTime )
          {
            if ( giMenuCommand != -1 )
              goto LABEL_48;
            if ( gGameCommand == -1 )
            {
              this = (heroWindow *)operator new(68);
              if ( this )
                gpInitWin = heroWindow::heroWindow(this, 0, 0, "stpmain.bin");
              else
                gpInitWin = 0;
              if ( !gpInitWin )
                MemError();
              gbInSetupDialog = 1;
              heroWindowManager::DoDialog(
                gpWindowManager,
                gpInitWin,
                (int (__fastcall *)(tag_message *))InitMenuHandler,
                0);
              operator delete(gpInitWin);
              gpInitWin = 0;
              v24 = gpWindowManager->buttonPressedCode;
              gbInSetupDialog = 0;
            }
            else
            {
              v24 = gGameCommand;
              gGameCommand = -1;
            }
            goto LABEL_58;
          }
          gbTCPFirstTime = 0;
          iLastMsgNumHumanPlayers = 1;
          iMPBaseType = 1;
          iMPNetProtocol = 2;
          iMPExtendedType = giTCPHostStatus ? 1 : 2;
          giSetupGameType = giTCPType;
          RemoteMain((void *)iMPExtendedType);
          gbWaitForRemoteReceive = iMPExtendedType == 2;
          giTCPHostStatus = -1;
          if ( !giSetupGameType )
            break;
          if ( (unsigned __int8)giSetupGameType != 1 || game::PickLoadGame() )
            goto LABEL_58;
        }
      }
      while ( !game::NewGame(gpGame) );
LABEL_58:
      if ( giMenuCommand != -1 )
        goto LABEL_48;
      switch ( v24 )
      {
        case 102:
          giSetupGameType = 1;
          goto LABEL_62;
        case 101:
          giSetupGameType = 0;
LABEL_62:
          for ( i = 0; i < 6; ++i )
            sprintf(&cPlayerNames[21 * i], byte_50CE04);
          if ( !game::SetupGame() )
            goto LABEL_16;
          if ( !giSetupGameType )
          {
            if ( gbInCampaign )
            {
              game::InitEntireCampaign(gpGame, gbCampaignSideChoice[0]);
              v19 = game::HandleCampaignWin(gpGame);
              if ( v19 )
              {
                game::InitCampaignMap((int)gpGame);
                goto LABEL_147;
              }
              heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
              v21 = 0;
            }
            else if ( xIsPlayingExpansionCampaign )
            {
              if ( ExpCampaign::HandleVictory((int)&xCampaign) )
              {
                ExpCampaign::InitMap((int)&xCampaign);
                goto LABEL_147;
              }
              heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
              v21 = 0;
            }
            else
            {
              LogStr("New Game 1");
              if ( game::NewGame(gpGame) )
              {
                LogStr("New Game 2");
                goto LABEL_88;
              }
            }
            goto LABEL_16;
          }
          if ( (unsigned __int8)giSetupGameType != 1 )
          {
LABEL_88:
            while ( giMenuCommand != -1 )
            {
LABEL_48:
              switch ( giMenuCommand )
              {
                case 40123:
                case 40124:
                case 40127:
                case 40128:
                case 40129:
                case 40131:
                case 40132:
                case 40134:
                case 40135:
                case 40137:
                case 40138:
                  if ( game::PickLoadGame() )
                    goto LABEL_88;
                  goto LABEL_16;
                case 40102:
                case 40104:
                case 40105:
                case 40106:
                case 40107:
                case 40110:
                case 40111:
                case 40112:
                case 40114:
                case 40115:
                case 40117:
                case 40118:
                case 40120:
                case 40121:
                  if ( game::NewGame(gpGame) )
                    goto LABEL_88;
                  goto LABEL_16;
                default:
                  goto LABEL_88;
              }
            }
            LogStr("DWM 1");
            if ( !v26 )
            {
              LogStr("DWM 2");
              if ( gbRemoteOn && !giThisNetPos )
              {
                LogStr("DWM 3");
                memset(v18, 0, 6u);
                memset(v15, 0, 6u);
                for ( j = 0; j < 6; ++j )
                {
                  if ( gbHumanPlayer[j] )
                  {
                    for ( k = 0; k < 6; ++k )
                    {
                      if ( strlen((int)&gpGame->_10[4 * k]) == 3
                        && !strcmp((int)&gpGame->_10[4 * k], (int)((char *)&gsNetPlayerInfo + 34 * j))
                        && !gpGame->couldBePlayerAlive[k]
                        && !v18[k] )
                      {
                        if ( !v15[j] )
                        {
                          v18[k] = 1;
                          v15[j] = 1;
                          *((_BYTE *)&gbGamePosToNetPos + k) = j;
                        }
                      }
                    }
                  }
                }
                for ( k = 0; k < 6 && v18[k]; ++k )
                  ;
                for ( j = 0; j < 6; ++j )
                {
                  if ( !v15[j] )
                  {
                    if ( gbHumanPlayer[j] )
                    {
                      *((_BYTE *)&gbGamePosToNetPos + j) = k;
                      strcpy(&gpGame->_10[4 * k++], (char *)&gsNetPlayerInfo + 34 * j);
                      while ( k < 6 && v18[k] )
                        ++k;
                    }
                    else
                    {
                      *((_BYTE *)&gbGamePosToNetPos + j) = -1;
                    }
                  }
                }
                memcpy(&v11, &gbGamePosToNetPos, 6u);
                memcpy(&v14, &gsNetPlayerInfo, 0xCCu);
                giThisGamePos = NetPosToGamePos(0);
                gbUseDiffCompression = 1;
                gbUseRegularCompression = 1;
                if ( giHighMemBuffer < 6000 )
                  gbUseRegularCompression = 0;
                for ( i = 0; i < iLastMsgNumHumanPlayers; ++i )
                {
                  if ( !byte_526CFA[34 * i] )
                    gbUseRegularCompression = 0;
                  if ( !byte_526CFB[34 * i] )
                    gbUseDiffCompression = 0;
                }
                v12 = gbUseRegularCompression;
                v13 = gbUseDiffCompression;
                for ( i = 1; i < iLastMsgNumHumanPlayers; ++i )
                {
                  v23 = TransmitRemoteData(&v11, i, 0xD4u, 32, 1, 1, -1);
                  if ( !v23 )
                    ShutDown(0);
                }
                for ( i = 1; i < iLastMsgNumHumanPlayers; ++i )
                {
                  if ( !game::TransmitSaveGame(gpGame, i, 0, 1) )
                    ShutDown(0);
                }
                memset(&gbThisNetHumanPlayer, 0, 6u);
                *(&gbThisNetHumanPlayer + giThisGamePos) = 1;
                iLastDiffSendTo = -1;
                game::SaveGame(gpGame, (const char *)&gConfig + 314, 0, 0);
              }
              LogStr("DWM 4");
              if ( gbRemoteOn && gbWaitForRemoteReceive )
              {
                LogStr("DWM 5");
                giWaitType = 0;
                NormalDialog("Waiting to receive game data.", 6, -1, -1, -1, 0, -1, 0, -1, 0);
                if ( !gbFunctionComplete )
                  ShutDown(0);
                game::LoadGame(gpGame, (const char *)&gConfig + 327, 0, 1);
                sprintf(&gpGame->_1[325], "NEWGAME");
                iLastDiffSendTo = -1;
                game::SaveGame(gpGame, (const char *)&gConfig + 353, 0, 0);
              }
              goto LABEL_147;
            }
LABEL_177:
            if ( gbGameOver )
            {
              while ( 1 )
              {
                RemoteCleanup();
                bShowIt = 1;
                mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
                sprintf(
                  gcWinText,
                  "My heroes, our foes have been scattered, their castles broken and laid bare.  The great campaign is now complete, and I stand before you as the undisputed High King!\n\nOur victory was achieved in %d days!",
                  giCurTurn);
                if ( giEndSequence != 1 )
                  break;
                if ( gbInCampaign )
                {
                  v9 = game::HandleCampaignWin(gpGame);
                  if ( gpGame->field_4 == 10 && gpGame->_1[12 * gpGame->field_2 + 10]
                    || gpGame->field_4 == 9 && !gpGame->field_2 && gpGame->_1[12 * gpGame->field_2 + 9] )
                  {
                    gbShowHighScore = 1;
                    ShowCongrats(0);
                    AddScoreToHighScore(
                      *(_WORD *)&gpGame->_1[181],
                      *(_WORD *)&gpGame->_1[181],
                      0,
                      0,
                      &aArchibald[("Roland" - "Archibald") & ((gpGame->field_2 == 1) - 1)]);
                  }
                  if ( !v9 )
                    goto LABEL_208;
                  for ( i = 0; i < 6; ++i )
                    sprintf(&cPlayerNames[21 * i], byte_50CFB4);
                  game::InitCampaignMap((int)gpGame);
                  gbGameOver = 0;
                  bForceCheckTimeEvent = 1;
                }
                else
                {
                  if ( !xIsPlayingExpansionCampaign )
                  {
                    ShowCongrats((void *)1);
                    if ( gbShowHighScore )
                    {
                      soundManager::PlayAmbientMusic(gpSoundManager, 43, 0, -1, v7);
                    }
                    else
                    {
                      heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
                      resourceManager::GetBackdrop(gpResourceManager, "heroes.icn", gpWindowManager->screenBuffer, 1);
                      heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
                      heroWindowManager::FadeScreen(gpWindowManager, 0, 8, gPalette);
                      gpWindowManager->field_56 = 1;
                      v21 = 1;
                      soundManager::PlayAmbientMusic(gpSoundManager, 42, 0, -1, v7);
                    }
                    goto LABEL_208;
                  }
                  v10 = ExpCampaign::HandleVictory((int)&xCampaign);
                  if ( ExpCampaign::IsCompleted((int)&xCampaign) )
                  {
                    gbShowHighScore = 1;
                    ShowCongrats((void *)2);
                    v4 = (&xHSCampaignNames)[4 * ExpCampaign::CampaignID(&xCampaign)];
                    v5 = (signed __int16)ExpCampaign::Days((int)&xCampaign);
                    v6 = ExpCampaign::Days((int)&xCampaign);
                    AddScoreToHighScore(v6, v5, 0, 2, v4);
                  }
                  if ( !v10 )
                    goto LABEL_208;
                  for ( i = 0; i < 6; ++i )
                    sprintf(&cPlayerNames[21 * i], byte_50CFB8);
                  ExpCampaign::InitMap((int)&xCampaign);
                  gbGameOver = 0;
                  bForceCheckTimeEvent = 1;
                }
LABEL_147:
                gpWindowManager->field_56 = 1;
                if ( gShingleAnim )
                  resourceManager::Dispose(gpResourceManager, (resource *)gShingleAnim);
                gShingleAnim = 0;
                if ( iLastMsgNumHumanPlayers > 1 )
                {
                  for ( i = 0; i < iLastMsgNumHumanPlayers; ++i )
                  {
                    if ( iMPBaseType != 2 )
                    {
                      v1 = (char *)&gsNetPlayerInfo + 34 * i + 4;
                      v2 = NetPosToGamePos((void *)i);
                      strcpy(&cPlayerNames[21 * v2], v1);
                    }
                  }
                }
                for ( i = 0; gpGame->numPlayers > i; ++i )
                {
                  if ( !strlen((int)&cPlayerNames[21 * i]) )
                  {
                    sprintf(&cPlayerNames[21 * i], "%s player", (&gColors)[4 * gpGame->players[i].color]);
                    cPlayerNames[21 * i] -= 32;
                  }
                }
                ComputeAdvNetControl();
                gbGameInitialized = 1;
                v21 = 0;
                soundManager::StopAllSamples(gpSoundManager, 1, v7);
                heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
                gMapX = 0;
                gMapY = 0;
                for ( giCurWatchPlayer = giCurPlayer;
                      !*(&gbThisNetHumanPlayer + giCurWatchPlayer);
                      giCurWatchPlayer = (giCurWatchPlayer + 1) % gpGame->numPlayers )
                  ;
                giCurWatchPlayerBit = 1 << giCurWatchPlayer;
                if ( gbInCampaign && gpGame->_1[203] )
                {
                  giEndSequence = 1;
                }
                else
                {
                  if ( !xIsPlayingExpansionCampaign || !ExpCampaign::IsThisMapCompleted((int)&xCampaign) )
                  {
                    if ( executive::AddManager(gpExec, (baseManager *)gpAdvManager, -1) )
                      ShutDown("Can't add manager!");
                    if ( v24 == 101 )
                    {
                      v3 = playerData::NextHero(gpGame->players, 0);
                      advManager::SetHeroContext(gpAdvManager, v3, 0);
                    }
                    if ( v24 == 101 || bForceCheckTimeEvent )
                    {
                      bForceCheckTimeEvent = 0;
                      game::CheckForTimeEvent(gpGame);
                    }
                    executive::MainLoop(gpExec);
                    gMapX = gpAdvManager->viewX;
                    gMapY = gpAdvManager->viewY;
                    executive::RemoveManager(gpExec, (baseManager *)gpAdvManager);
                    heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
                    goto LABEL_177;
                  }
                  giEndSequence = 1;
                }
              }
              gpWindowManager->field_56 = 0;
              if ( xIsExpansionMap )
                PlaySmacker(64);
              else
                PlaySmacker(3);
              heroWindowManager::FadeScreen(gpWindowManager, 1, 128, gPalette);
              resourceManager::GetBackdrop(gpResourceManager, "heroes.icn", gpWindowManager->screenBuffer, 1);
              heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
              heroWindowManager::FadeScreen(gpWindowManager, 0, 8, gPalette);
              gpWindowManager->field_56 = 1;
              v21 = 1;
              soundManager::PlayAmbientMusic(gpSoundManager, 42, 0, -1, v7);
LABEL_208:
              gbGameOver = 0;
              if ( gbShowHighScore )
              {
                gbShowHighScore = 0;
                if ( executive::AddManager(gpExec, gpHighScoreManager, -1) )
                  ShutDown("Can't add manager!");
                executive::MainLoop(gpExec);
                executive::RemoveManager(gpExec, gpHighScoreManager);
                giHighScoreRank = -1;
                soundManager::SwitchAmbientMusic(gpSoundManager, 42);
                resourceManager::GetBackdrop(gpResourceManager, "heroes.icn", gpWindowManager->screenBuffer, 1);
                heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
                heroWindowManager::FadeScreen(gpWindowManager, 0, 8, gPalette);
                v21 = 1;
              }
            }
            if ( gbRemoteOn )
              v26 = 1;
            goto LABEL_15;
          }
          LogStr("Load Game 1");
          if ( game::PickLoadGame() )
          {
            LogStr("Load Game 2");
            goto LABEL_88;
          }
          break;
        case 103:
          if ( executive::AddManager(gpExec, gpHighScoreManager, -1) )
            ShutDown("Can't add manager!");
          executive::MainLoop(gpExec);
          executive::RemoveManager(gpExec, gpHighScoreManager);
          v21 = 0;
          goto LABEL_16;
        case 104:
          heroWindowManager::FadeScreen(gpWindowManager, 1, 8, gPalette);
          PlaySmacker(72);
          PlaySmacker(36);
          v21 = 0;
          heroWindowManager::FadeScreen(gpWindowManager, 1, 128, gPalette);
          goto LABEL_16;
        case 105:
          v26 = 1;
          goto LABEL_88;
        default:
          goto LABEL_88;
      }
    }
  }
  ShutDown(0);
  return 0;
}