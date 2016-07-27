{
  const char *v1; // ST1C_4@156
  signed int v2; // eax@156
  int v3; // eax@175
  const char *v4; // ST1C_4@201
  int v5; // ebx@201
  __int16 v6; // ax@201
  int v7; // [sp-4h] [bp-174h]@5
  GUIWindow *this; // [sp+24h] [bp-14Ch]@55
  signed int v9; // [sp+28h] [bp-148h]@187
  bool v10; // [sp+28h] [bp-148h]@200
  char v11; // [sp+2Ch] [bp-144h]@125
  char v12; // [sp+32h] [bp-13Eh]@134
  char v13; // [sp+33h] [bp-13Dh]@134
  char v14; // [sp+34h] [bp-13Ch]@125
  char v15[8]; // [sp+12Ch] [bp-44h]@95
  int j; // [sp+134h] [bp-3Ch]@95
  int k; // [sp+138h] [bp-38h]@99
  char v18[8]; // [sp+13Ch] [bp-34h]@95
  int v19; // [sp+144h] [bp-2Ch]@71
  int v20; // [sp+148h] [bp-28h]@11
  int v21; // [sp+154h] [bp-1Ch]@14
  int i; // [sp+158h] [bp-18h]@65
  int v23; // [sp+15Ch] [bp-14h]@136
  int v24; // [sp+164h] [bp-Ch]@3
  int v25; // [sp+168h] [bp-8h]@14
  int v26; // [sp+16Ch] [bp-4h]@14

  if ( dword_50CD40 )
    return 0;
  dword_50CD40 = 1;
  debugLog("OM1");
  debugLog("OM2");
  v24 = -1;
  if ( ManagerManager::initializeSeveralManagers(managerManager) )
    terminate("Initialization failed!");
  debugLog("OM3");
  changeMenu(dfltMenu);
  dword_524234 = ResourceManager::getPal(resourceManager, "kb.pal");
  HeroWindowManager::instance->field_56 = 1;
  smallFont = ResourceManager::getFontByFilename(resourceManager, "smalfont.fnt");
  bigFont = ResourceManager::getFontByFilename(resourceManager, "bigfont.fnt");
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  sub_4CEB90(mouseManager, *(&mainWindows + 7 * gameOrEditorIdx + 6));
  debugLog("OM4");
  sub_42F650();
  debugLog("OM5");
  v7 = -1;
  if ( ((int (__thiscall *)(SoundManager *))soundManager->vtable->initialize)(soundManager) )
    terminate("Unable to initialize sound.");
  if ( debugLogLevel < 9 )
    sub_4396F0();
  debugLog("OM6");
  if ( dword_52409C )
  {
    sub_4D6A50(HeroWindowManager::instance->screenBuffer, 0, 0, 640u, 480, 0);
    renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 480, 0, 0);
    if ( !dword_4F7468 )
    {
      v20 = HeroWindowManager::instance->field_56;
      HeroWindowManager::instance->field_56 = 0;
      if ( sub_45A2A0(66) )
        sub_45A2A0(1);
      sub_45A2A0(65);
      HeroWindowManager::instance->field_56 = v20;
    }
  }
  sub_437670();
  memset(&byte_524758, 0, 6u);
  MouseManager::enableCursor(mouseManager);
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
          if ( !a2 )
            a2 = ResourceManager::getIconByFilename(resourceManager, "shnganim.icn");
          if ( dword_523408 != 105 )
            SoundManager::couldBePlayCDTrack(soundManager, 42);
          if ( !v21 )
          {
            if ( dword_523408 != 105 )
            {
              ResourceManager::dumpImageToScreen(
                resourceManager,
                "heroes.icn",
                HeroWindowManager::instance->screenBuffer,
                1);
              HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
              if ( v25 )
                someSortOfPaletteSwap(dword_524234->contents, 1);
              else
                sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
              v25 = 0;
            }
            MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
          }
          v21 = 1;
          if ( dword_523408 != 105 )
            HeroWindowManager::instance->field_56 = 1;
          if ( dword_52340C == -1 || !dword_524BE0 )
          {
            if ( dword_4F19A8 != -1 )
              goto LABEL_51;
            if ( dword_523408 == -1 )
            {
              this = (GUIWindow *)operator new(0x44u);
              if ( this )
                dword_4F4BC8 = GUIWindow_constructorFromFile(this, 0, 0, "stpmain.bin");
              else
                dword_4F4BC8 = 0;
              if ( !dword_4F4BC8 )
                fatalOutOfMemoryError();
              dword_4F307C = 1;
              HeroWindowManager::displayWindow(
                HeroWindowManager::instance,
                dword_4F4BC8,
                (int (__fastcall *)(InputEvent *))sub_431650,
                0);
              operator delete(dword_4F4BC8);
              dword_4F4BC8 = 0;
              v24 = HeroWindowManager::instance->buttonPressedCode;
              dword_4F307C = 0;
            }
            else
            {
              v24 = dword_523408;
              dword_523408 = -1;
            }
            goto LABEL_61;
          }
          dword_524BE0 = 0;
          dword_5235D4 = 1;
          dword_524778 = 1;
          dword_4F31B4 = 2;
          dword_523ED8 = dword_52340C ? 1 : 2;
          byte_523004 = dword_523EE0;
          sub_46D4F0((void *)dword_523ED8);
          dword_523F08 = dword_523ED8 == 2 ? 1 : 0;
          dword_52340C = -1;
          if ( !byte_523004 )
            break;
          if ( (unsigned __int8)byte_523004 != 1 || sub_4BB840() )
            goto LABEL_61;
        }
      }
      while ( !sub_45AF30((int)gameObject) );
LABEL_61:
      if ( dword_4F19A8 != -1 )
        goto LABEL_51;
      switch ( v24 )
      {
        case 102:
          byte_523004 = 1;
          goto LABEL_65;
        case 101:
          byte_523004 = 0;
LABEL_65:
          for ( i = 0; i < 6; ++i )
            sprintf(&dword_5235E0[21 * i], byte_50CE04);
          if ( !sub_4BB170() )
            goto LABEL_16;
          if ( !byte_523004 )
          {
            if ( loadOrNewGameSelected )
            {
              sub_4A9500((int)gameObject, dword_5247B8);
              v19 = sub_4A7880(gameObject);
              if ( v19 )
              {
                sub_4A9550((int)gameObject);
                goto LABEL_150;
              }
              sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
              v21 = 0;
            }
            else
            {
              if ( byte_5304A0 )
              {
                if ( sub_471A60((int)&unk_530450) )
                {
                  sub_470620((int)&unk_530450);
                  goto LABEL_150;
                }
                sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
                v21 = 0;
              }
              else
              {
                debugLog("New Game 1");
                if ( sub_45AF30((int)gameObject) )
                {
                  debugLog("New Game 2");
                  goto LABEL_91;
                }
              }
            }
            goto LABEL_16;
          }
          if ( (unsigned __int8)byte_523004 != 1 )
          {
LABEL_91:
            while ( dword_4F19A8 != -1 )
            {
LABEL_51:
              switch ( dword_4F19A8 )
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
                  if ( sub_4BB840() )
                    goto LABEL_91;
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
                  if ( sub_45AF30((int)gameObject) )
                    goto LABEL_91;
                  goto LABEL_16;
                default:
                  goto LABEL_91;
              }
            }
            debugLog("DWM 1");
            if ( !v26 )
            {
              debugLog("DWM 2");
              if ( dword_4F7494 && !dword_523F14 )
              {
                debugLog("DWM 3");
                memset(v18, 0, 6u);
                memset(v15, 0, 6u);
                for ( j = 0; j < 6; ++j )
                {
                  if ( dword_524810[j] )
                  {
                    for ( k = 0; k < 6; ++k )
                    {
                      if ( strlen(&gameObject->_10[4 * k]) == 3
                        && !strcmp(&gameObject->_10[4 * k], (const char *)&dword_526CE0 + 34 * j)
                        && !gameObject->couldBePlayerAlive[k]
                        && !v18[k] )
                      {
                        if ( !v15[j] )
                        {
                          v18[k] = 1;
                          v15[j] = 1;
                          *((_BYTE *)&byte_5247A0 + k) = j;
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
                    if ( dword_524810[j] )
                    {
                      *((_BYTE *)&byte_5247A0 + j) = k;
                      strcpy(&gameObject->_10[4 * k++], (const char *)&dword_526CE0 + 34 * j);
                      while ( k < 6 && v18[k] )
                        ++k;
                    }
                    else
                    {
                      *((_BYTE *)&byte_5247A0 + j) = -1;
                    }
                  }
                }
                memcpy(&v11, &byte_5247A0, 6u);
                memcpy(&v14, &dword_526CE0, 0xCCu);
                dword_524730 = sub_435DC0(0);
                byte_526DAC = 1;
                byte_526ED8 = 1;
                if ( dword_4F74AC < 6000 )
                  byte_526ED8 = 0;
                for ( i = 0; i < dword_5235D4; ++i )
                {
                  if ( !byte_526CFA[34 * i] )
                    byte_526ED8 = 0;
                  if ( !byte_526CFB[34 * i] )
                    byte_526DAC = 0;
                }
                v12 = byte_526ED8;
                v13 = byte_526DAC;
                for ( i = 1; i < dword_5235D4; ++i )
                {
                  v23 = sub_46E1D0(&v11, i, 0xD4u, 32, 1, 1, -1);
                  if ( !v23 )
                    terminate(0);
                }
                for ( i = 1; i < dword_5235D4; ++i )
                {
                  if ( !sub_42B410(gameObject, i, 0, 1) )
                    terminate(0);
                }
                memset(&byte_524758, 0, 6u);
                *(&byte_524758 + dword_524730) = 1;
                dword_4F31B8 = -1;
                GameInfo::saveGame(gameObject, (const char *)&computerWalkSpeed + 314, 0, 0);
              }
              debugLog("DWM 4");
              if ( dword_4F7494 && dword_523F08 )
              {
                debugLog("DWM 5");
                dword_524750 = 0;
                display_message_window("Waiting to receive game data.", 6, -1, -1, -1, 0, -1, 0, -1, 0);
                if ( !dword_523018 )
                  terminate(0);
                sub_41B5F0(gameObject, (const char *)&computerWalkSpeed + 327, 0, 1);
                sprintf(&gameObject->_1[325], "NEWGAME");
                dword_4F31B8 = -1;
                GameInfo::saveGame(gameObject, (const char *)&computerWalkSpeed + 353, 0, 0);
              }
              goto LABEL_150;
            }
LABEL_180:
            if ( dword_4EF268 )
            {
              while ( 1 )
              {
                sub_46D360();
                dword_524C14 = 1;
                MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
                sprintf(
                  byte_523F30,
                  "My heroes, our foes have been scattered, their castles broken and laid bare.  The great campaign is now complete, and I stand before you as the undisputed High King!\n\nOur victory was achieved in %d days!",
                  dword_532C54);
                if ( dword_522FF8 != 1 )
                  break;
                if ( loadOrNewGameSelected )
                {
                  v9 = sub_4A7880(gameObject);
                  if ( gameObject->field_4 == 10 && gameObject->_1[12 * gameObject->field_2 + 10]
                    || gameObject->field_4 == 9 && !gameObject->field_2 && gameObject->_1[12 * gameObject->field_2 + 9] )
                  {
                    dword_4F74A4 = 1;
                    winScenario(0);
                    sub_435860(
                      *(_WORD *)&gameObject->_1[181],
                      *(_WORD *)&gameObject->_1[181],
                      0,
                      0,
                      &aArchibald[("Roland" - "Archibald") & ((gameObject->field_2 == 1) - 1)]);
                  }
                  if ( !v9 )
                    goto LABEL_211;
                  for ( i = 0; i < 6; ++i )
                    sprintf(&dword_5235E0[21 * i], byte_50CFB4);
                  sub_4A9550((int)gameObject);
                  dword_4EF268 = 0;
                  dword_50CD48 = 1;
                }
                else
                {
                  if ( !byte_5304A0 )
                  {
                    winScenario((void *)1);
                    if ( dword_4F74A4 )
                    {
                      SoundManager::otherPlayTrack(soundManager, 43, 0, -1, v7);
                    }
                    else
                    {
                      sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
                      ResourceManager::dumpImageToScreen(
                        resourceManager,
                        "heroes.icn",
                        HeroWindowManager::instance->screenBuffer,
                        1);
                      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
                      sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
                      HeroWindowManager::instance->field_56 = 1;
                      v21 = 1;
                      SoundManager::otherPlayTrack(soundManager, 42, 0, -1, v7);
                    }
                    goto LABEL_211;
                  }
                  v10 = sub_471A60((int)&unk_530450);
                  if ( sub_4723E0((int)&unk_530450) )
                  {
                    dword_4F74A4 = 1;
                    winScenario((void *)2);
                    v4 = (&off_51A880)[4 * sub_4728C0(&unk_530450)];
                    v5 = (signed __int16)sub_472850((int)&unk_530450);
                    v6 = sub_472850((int)&unk_530450);
                    sub_435860(v6, v5, 0, 2, v4);
                  }
                  if ( !v10 )
                    goto LABEL_211;
                  for ( i = 0; i < 6; ++i )
                    sprintf(&dword_5235E0[21 * i], byte_50CFB8);
                  sub_470620((int)&unk_530450);
                  dword_4EF268 = 0;
                  dword_50CD48 = 1;
                }
LABEL_150:
                HeroWindowManager::instance->field_56 = 1;
                if ( a2 )
                  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)a2);
                a2 = 0;
                if ( dword_5235D4 > 1 )
                {
                  for ( i = 0; i < dword_5235D4; ++i )
                  {
                    if ( dword_524778 != 2 )
                    {
                      v1 = (char *)&dword_526CE0 + 34 * i + 4;
                      v2 = sub_435DC0((void *)i);
                      strcpy(&dword_5235E0[21 * v2], v1);
                    }
                  }
                }
                for ( i = 0; gameObject->numPlayers > i; ++i )
                {
                  if ( !strlen(&dword_5235E0[21 * i]) )
                  {
                    sprintf(&dword_5235E0[21 * i], "%s player", (&off_4F62F8)[4 * gameObject->players[i].color]);
                    dword_5235E0[21 * i] -= 32;
                  }
                }
                sub_456A10();
                dword_4F7498 = 1;
                v21 = 0;
                sub_4035A0(soundManager, 1, v7);
                sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
                dword_524214 = 0;
                dword_524218 = 0;
                for ( dword_523EDC = curPlayerIdx;
                      !*(&byte_524758 + dword_523EDC);
                      dword_523EDC = (dword_523EDC + 1) % gameObject->numPlayers )
                  ;
                byte_5306F0 = 1 << dword_523EDC;
                if ( loadOrNewGameSelected && gameObject->_1[203] )
                {
                  dword_522FF8 = 1;
                }
                else
                {
                  if ( !byte_5304A0 || !sub_472440((int)&unk_530450) )
                  {
                    if ( ManagerManager::addManager(managerManager, (AbstractManager *)advManager, -1) )
                      terminate("Can't add manager!");
                    if ( v24 == 101 )
                    {
                      v3 = sub_418CE0(gameObject->players, 0);
                      sub_450C10(advManager, v3, 0);
                    }
                    if ( v24 == 101 || dword_50CD48 )
                    {
                      dword_50CD48 = 0;
                      sub_42E330(gameObject);
                    }
                    ManagerManager::sendInputToManagers(managerManager);
                    dword_524214 = advManager->viewX;
                    dword_524218 = advManager->viewY;
                    ManagerManager__removeManager(managerManager, (AbstractManager *)advManager);
                    sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
                    goto LABEL_180;
                  }
                  dword_522FF8 = 1;
                }
              }
              HeroWindowManager::instance->field_56 = 0;
              if ( inExpansion )
                sub_45A2A0(64);
              else
                sub_45A2A0(3);
              sub_4C7C60(HeroWindowManager::instance, 1, 128, dword_524234);
              ResourceManager::dumpImageToScreen(
                resourceManager,
                "heroes.icn",
                HeroWindowManager::instance->screenBuffer,
                1);
              HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
              sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
              HeroWindowManager::instance->field_56 = 1;
              v21 = 1;
              SoundManager::otherPlayTrack(soundManager, 42, 0, -1, v7);
LABEL_211:
              dword_4EF268 = 0;
              if ( dword_4F74A4 )
              {
                dword_4F74A4 = 0;
                if ( ManagerManager::addManager(managerManager, highScoreManager, -1) )
                  terminate("Can't add manager!");
                ManagerManager::sendInputToManagers(managerManager);
                ManagerManager__removeManager(managerManager, highScoreManager);
                dword_4F749C = -1;
                SoundManager::couldBePlayCDTrack(soundManager, 42);
                ResourceManager::dumpImageToScreen(
                  resourceManager,
                  "heroes.icn",
                  HeroWindowManager::instance->screenBuffer,
                  1);
                HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
                sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
                v21 = 1;
              }
            }
            if ( dword_4F7494 )
              v26 = 1;
            goto LABEL_15;
          }
          debugLog("Load Game 1");
          if ( sub_4BB840() )
          {
            debugLog("Load Game 2");
            goto LABEL_91;
          }
          break;
        case 103:
          if ( ManagerManager::addManager(managerManager, highScoreManager, -1) )
            terminate("Can't add manager!");
          ManagerManager::sendInputToManagers(managerManager);
          ManagerManager__removeManager(managerManager, highScoreManager);
          v21 = 0;
          goto LABEL_16;
        case 104:
          sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
          sub_45A2A0(72);
          sub_45A2A0(36);
          v21 = 0;
          sub_4C7C60(HeroWindowManager::instance, 1, 128, dword_524234);
          goto LABEL_16;
        case 105:
          v26 = 1;
          goto LABEL_91;
        default:
          goto LABEL_91;
      }
    }
  }
  terminate(0);
  return 0;
}
