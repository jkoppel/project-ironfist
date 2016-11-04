{
  ArmyInfo *v2; // ST20_4@39
  int v3; // eax@39
  int v4; // ST2C_4@50
  int v5; // eax@50
  const char *v6; // eax@90
  signed int v7; // eax@96
  const char *v8; // eax@127
  const char *v9; // eax@128
  signed int result; // eax@172
  int v11; // [sp+Ch] [bp-250h]@179
  int v12; // [sp+10h] [bp-24Ch]@174
  int v13; // [sp+14h] [bp-248h]@156
  int v14; // [sp+18h] [bp-244h]@20
  int msgType; // [sp+1Ch] [bp-240h]@19
  INPUT_EVENT_CODE code; // [sp+20h] [bp-23Ch]@18
  TownManager *thisa; // [sp+24h] [bp-238h]@1
  GUIWindow *v18; // [sp+44h] [bp-218h]@102
  GUIWindow *v19; // [sp+4Ch] [bp-210h]@82
  GUIWindow *v20; // [sp+54h] [bp-208h]@75
  GUIWindow *v21; // [sp+5Ch] [bp-200h]@67
  ArmyDisplay *v22; // [sp+60h] [bp-1FCh]@49
  ArmyDisplay *v23; // [sp+68h] [bp-1F4h]@47
  ArmyDisplay *ecx0; // [sp+74h] [bp-1E8h]@38
  ArmyDisplay *v25; // [sp+7Ch] [bp-1E0h]@36
  GUIWindow *window; // [sp+84h] [bp-1D8h]@30
  RecruitManager *thisb; // [sp+8Ch] [bp-1D0h]@23
  Hero *a10; // [sp+94h] [bp-1C8h]@142
  signed int v29; // [sp+98h] [bp-1C4h]@133
  signed int v30; // [sp+A8h] [bp-1B4h]@118
  AbstractManager *a2; // [sp+B0h] [bp-1ACh]@24
  signed int v32; // [sp+B4h] [bp-1A8h]@5
  char msg; // [sp+B8h] [bp-1A4h]@90
  signed int buildingCode; // [sp+248h] [bp-14h]@6
  sample_resource res; // [sp+24Ch] [bp-10h]@43
  int v36; // [sp+254h] [bp-8h]@1
  int isRightClick; // [sp+258h] [bp-4h]@2

  thisa = this;
  v36 = 0;
  if ( BYTE1(evt->inputTypeBitmask) & 2 )
    isRightClick = 1;
  else
    isRightClick = 0;
  if ( dword_4F4B88 != -1 )
  {
    v32 = dword_4F4B88;
    dword_4F4B88 = -1;
    if ( v32 == 100 )
    {
      for ( buildingCode = 0; buildingCode < 32; ++buildingCode )
      {
        if ( (1 << buildingCode) & dword_4F19B8[thisa->castle->factionID] || buildingCode == 6 )
          sub_4158D0(thisa, buildingCode);
      }
    }
    else
    {
      if ( (1 << v32) & dword_4F19B8[this->castle->factionID] || v32 == 6 )
        sub_4158D0(this, v32);
    }
  }
  if ( getTickCount() > animationFrameSwitchTime )
  {
    TownManager::paintTown(thisa, 1, 1);
    animationFrameSwitchTime = getTickCount() + 150;
  }
  code = evt->eventCode;
  if ( code > INPUT_GUI_MESSAGE_CODE )
    goto LABEL_191;
  if ( code == INPUT_GUI_MESSAGE_CODE )
  {
    msgType = evt->messageType;
    if ( msgType == 12 )
      goto LABEL_204;
    if ( msgType == 13 )
    {
      v13 = evt->fieldID;
      if ( v13 >= 903 )
      {
        if ( v13 <= 904 )
        {
          if ( thisa->castle->ownerIdx == curPlayerIdx && curPlayer->numCastles > 1 )
          {
            thisa->castle = &gameObject->castles[curPlayer->castlesOwned[(getCastleOwnedIdx(
                                                                            curPlayer,
                                                                            thisa->castle->idx)
                                                                        + curPlayer->numCastles
                                                                        + ((unsigned int)(evt->fieldID - 903) < 1 ? -1 : 1))
                                                                       % curPlayer->numCastles]];
            TownManager::switchedCastle(thisa);
          }
        }
        else
        {
          if ( v13 == 30720 && !isRightClick )
            ++v36;
        }
      }
      goto LABEL_191;
    }
    if ( msgType == 14 )
    {
LABEL_204:
      v14 = evt->fieldID;
      if ( v14 > 15 )
      {
        if ( v14 >= 19 )
        {
          if ( v14 <= 30 )
          {
            if ( isRightClick )
            {
              dwellingRightClicked(thisa->castle, evt->fieldID - 19);
            }
            else
            {
              TownManager::paintTown(thisa, 1, 1);
              thisb = (RecruitManager *)operator new(0x7Eu);
              if ( thisb )
                a2 = (AbstractManager *)RecruitManager_constructor2(
                                          thisb,
                                          (int)&thisa->castle->idx,
                                          evt->fieldID - 19,
                                          1);
              else
                a2 = 0;
              if ( !a2 )
                fatalOutOfMemoryError();
              ManagerManager::weirdAddAndRemoveManagerThing(managerManager, a2);
              operator delete(a2);
            }
            goto LABEL_191;
          }
          if ( v14 == 30720 )
          {
            if ( !isRightClick )
              TownManager::setMessageForMouseover(thisa, evt);
            goto LABEL_191;
          }
        }
      }
      else
      {
        if ( v14 == 15 )
        {
LABEL_126:
          if ( isRightClick )
          {
LABEL_127:
            v8 = buildingDescription(thisa->castle->factionID, evt->fieldID, 1);
            sprintf(&msg, v8);
            display_message_window(&msg, 4, -1, -1, thisa->castle->factionID + 19, evt->fieldID, -1, 0, -1, 0);
          }
          else
          {
            v9 = buildingDescription(thisa->castle->factionID, evt->fieldID, 1);
            sprintf(&msg, v9);
            display_message_window(&msg, 1, -1, -1, thisa->castle->factionID + 19, evt->fieldID, -1, 0, -1, 0);
          }
          goto LABEL_191;
        }
        switch ( v14 )
        {
          case BUILDING_CASTLE:
            if ( isRightClick )
              goto LABEL_127;
            window = (GUIWindow *)operator new(0x44u);
            if ( window )
              thisa->curScreen = GUIWindow_constructorFromFile(window, 0, 0, "caslwind.bin");
            else
              thisa->curScreen = 0;
            if ( !thisa->curScreen )
              fatalOutOfMemoryError();
            sub_409850(thisa, thisa->curScreen, 0);
            thisa->field_15A = 1;
            thisa->field_14E = 0;
            HeroWindowManager::displayWindow(
              HeroWindowManager::instance,
              thisa->curScreen,
              (int (__fastcall *)(InputEvent *))sub_40A780,
              0);
            thisa->field_15A = 0;
            operator delete(thisa->curScreen);
            if ( thisa->field_14E )
            {
              TownManager::paint(thisa);
              HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 0, 256, 552, 204);
              v25 = thisa->visitingArmyDisplay;
              if ( v25 )
              {
                ArmyDisplay::cleanUp(v25);
                operator delete(v25);
              }
              sprintf(globBuf, "port%04d.icn", *(_BYTE *)(*(_DWORD *)&thisa->_3[16] + 24));
              ecx0 = (ArmyDisplay *)operator new(0x84u);
              if ( ecx0 )
              {
                v2 = (ArmyInfo *)(*(_DWORD *)&thisa->_3[16] + 101);
                v3 = ResourceManager::setResource(resourceManager, globBuf, 1);
                thisa->visitingArmyDisplay = ArmyDisplay::constructor(ecx0, 0, 355, 3, v3, 0, v2, 122, 0, -1);
              }
              else
              {
                thisa->visitingArmyDisplay = 0;
              }
              if ( !thisa->visitingArmyDisplay )
                fatalOutOfMemoryError();
              res = playSample("buildtwn.82M");
              GUIWindow::repaint(thisa->townScreen, 0);
              ArmyDisplay::paint(thisa->garrisonDisplay, 0);
              ArmyDisplay::paint(thisa->visitingArmyDisplay, 0);
              sub_4C7E00(HeroWindowManager::instance, 0, 256, 552, 204, -1, 0, 0);
              waitForSampleToFinish(-1, res);
              thisa->field_14E = 0;
              HeroWindowManager::deleteSomeBMP(HeroWindowManager::instance);
            }
            else
            {
              if ( thisa->field_15E == 15 && thisa->castle->visitingHeroIdx == -1 )
              {
                if ( thisa->visitingArmyDisplay )
                {
                  v23 = thisa->visitingArmyDisplay;
                  if ( v23 )
                  {
                    ArmyDisplay::cleanUp(v23);
                    operator delete(v23);
                  }
                }
                thisa->visitingArmyDisplay = 0;
                sprintf(globBuf, "port%04d.icn", thisa->castle->factionID + 90);
                v22 = (ArmyDisplay *)operator new(0x84u);
                if ( v22 )
                {
                  v4 = curPlayer->color;
                  v5 = ResourceManager::setResource(resourceManager, globBuf, 1);
                  thisa->visitingArmyDisplay = ArmyDisplay::constructor(v22, 0, 355, 3, v5, 0, 0, -1, 0, v4);
                }
                else
                {
                  thisa->visitingArmyDisplay = 0;
                }
                if ( !thisa->visitingArmyDisplay )
                  fatalOutOfMemoryError();
              }
              TownManager::paint(thisa);
              if ( thisa->field_15E != -1 )
                sub_4158D0(thisa, thisa->field_15E);
            }
            goto LABEL_191;
          case BUILDING_MAGE_GUILD:
            if ( isRightClick )
              goto LABEL_127;
            if ( thisa->castle->visitingHeroIdx == -1
              || Hero::hasArtifact(&gameObject->heroes[thisa->castle->visitingHeroIdx], ARTIFACT_MAGIC_BOOK) )
            {
              v21 = (GUIWindow *)operator new(0x44u);
              if ( v21 )
                thisa->curScreen = GUIWindow_constructorFromFile(v21, 0, 0, "magewind.bin");
              else
                thisa->curScreen = 0;
              if ( !thisa->curScreen )
                fatalOutOfMemoryError();
              setOptionsScreenTitles(thisa->curScreen, 17);
              TownManager::enterMageGuild(thisa, thisa->curScreen);
              HeroWindowManager::displayWindow(HeroWindowManager::instance, thisa->curScreen, mageGuildCallback, 0);
              operator delete(thisa->curScreen);
            }
            else
            {
              if ( Hero::numArtifacts(&gameObject->heroes[thisa->castle->visitingHeroIdx]) == 14 )
              {
                display_message_window(
                  "You must purchase a spell book to use the mage guild, but you currently have no room for a spell book.  Try giving one of your artifacts to another hero.",
                  1,
                  -1,
                  -1,
                  -1,
                  0,
                  -1,
                  0,
                  -1,
                  0);
              }
              else
              {
                if ( curPlayer->resources[6] >= 500 )
                {
                  display_message_window(
                    "To cast spells, you must first buy a spell book for 500 gold.  Do you wish to buy one?",
                    2,
                    -1,
                    -1,
                    7,
                    81,
                    -1,
                    0,
                    -1,
                    0);
                  if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
                  {
                    grantArtifact(&gameObject->heroes[thisa->castle->visitingHeroIdx], ARTIFACT_MAGIC_BOOK, 1, -1);
                    curPlayer->resources[6] -= 500;
                    Bankbox::refreshCaptions(thisa->bankbox, 1);
                    GUIWindow::repaintAndUpdateScreen(thisa->townScreen);
                    Castle::grantHeroSpellsFromMageGuild(thisa->castle, 0);
                  }
                }
                else
                {
                  display_message_window(
                    "To cast spells, you must first buy a spell book for 500 gold.  Unfortunately, you seem to be a little short of cash at the moment.",
                    1,
                    -1,
                    -1,
                    7,
                    81,
                    -1,
                    0,
                    -1,
                    0);
                }
              }
            }
            Castle::grantHeroSpellsFromMageGuild(thisa->castle, 0);
            TownManager::paint(thisa);
            goto LABEL_191;
          case BUILDING_WELL:
            if ( isRightClick )
              goto LABEL_127;
            v20 = (GUIWindow *)operator new(0x44u);
            if ( v20 )
              thisa->curScreen = GUIWindow_constructorFromFile(v20, 0, 0, "wellwind.bin");
            else
              thisa->curScreen = 0;
            if ( !thisa->curScreen )
              fatalOutOfMemoryError();
            TownManager::setUpWellWindow(thisa, thisa->curScreen);
            HeroWindowManager::displayWindow(HeroWindowManager::instance, thisa->curScreen, sub_432E90, 0);
            operator delete(thisa->curScreen);
            TownManager::paint(thisa);
            goto LABEL_191;
          case BUILDING_THIEVES_GUILD:
            if ( isRightClick )
              goto LABEL_127;
            v19 = (GUIWindow *)operator new(0x44u);
            if ( v19 )
              thisa->curScreen = GUIWindow_constructorFromFile(v19, 0, 0, "thiefwin.bin");
            else
              thisa->curScreen = 0;
            if ( !thisa->curScreen )
              fatalOutOfMemoryError();
            setOptionsScreenTitles(thisa->curScreen, 14);
            populateThievesGuildWindow(thisa->curScreen, -1);
            HeroWindowManager::displayWindow(HeroWindowManager::instance, thisa->curScreen, sub_432E90, 0);
            operator delete(thisa->curScreen);
            TownManager::paint(thisa);
            goto LABEL_191;
          case BUILDING_TAVERN:
            if ( isRightClick )
              goto LABEL_127;
            if ( thisa->castle->factionID == FACTION_NECROMANCER )
            {
              v6 = buildingDescription(thisa->castle->factionID, evt->fieldID, 1);
              sprintf(&msg, v6);
              display_message_window(&msg, 1, -1, -1, thisa->castle->factionID + 19, evt->fieldID, -1, 0, -1, 0);
            }
            else
            {
              TownManager::visitTavern(thisa);
            }
            goto LABEL_191;
          case BUILDING_TENT:
            if ( isRightClick )
              goto LABEL_127;
            if ( thisa->castle->mayNotBeUpgradedToCastle )
            {
              display_message_window("This town may not be upgraded to a castle.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            else
            {
              v7 = sub_432680((int)&thisa->castle->idx, 6);
              if ( sub_414AC0(thisa, 6, (unsigned int)v7 < 1, isRightClick) )
                sub_4158D0(thisa, 6);
            }
            goto LABEL_191;
          case BUILDING_DOCK:
            if ( isRightClick )
              goto LABEL_127;
            HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 30720, 16392);
            if ( sub_42C880(gameObject) >= 48
              || *(_BYTE *)(usedToCheckForBoatByCastle(
                              advManager,
                              LOBYTE(thisa->castle->field_6),
                              HIBYTE(thisa->castle->field_6))
                          + 9) )
            {
              display_message_window("Cannot build another boat.", 1, 208, 40, -1, 0, -1, 0, -1, 0);
            }
            else
            {
              v18 = (GUIWindow *)operator new(0x44u);
              if ( v18 )
                thisa->curScreen = GUIWindow_constructorFromFile(v18, 177, 20, "shipwind.bin");
              else
                thisa->curScreen = 0;
              if ( !thisa->curScreen )
                fatalOutOfMemoryError();
              setOptionsScreenTitles(thisa->curScreen, 12);
              if ( gameObject->players[curPlayerIdx].resources[6] < 1000
                || gameObject->players[curPlayerIdx].resources[0] < 10 )
              {
                evt->eventCode = 512;
                evt->messageType = 5;
                evt->fieldID = 30722;
                evt->payload = (void *)4096;
                GUIWindow::processMessage(thisa->curScreen, (Event *)evt);
                evt->messageType = 6;
                evt->payload = (void *)2;
                GUIWindow::processMessage(thisa->curScreen, (Event *)evt);
              }
              HeroWindowManager::displayWindow(HeroWindowManager::instance, thisa->curScreen, sub_432E90, 0);
              operator delete(thisa->curScreen);
              if ( HeroWindowManager::instance->buttonPressedCode == 30722 )
              {
                if ( sub_419870(gameObject, LOBYTE(thisa->castle->field_6), HIBYTE(thisa->castle->field_6), 0) == -1 )
                {
                  debugLog("Can't create boat!");
                }
                else
                {
                  sub_4158D0(thisa, 14);
                  gameObject->players[curPlayerIdx].resources[6] -= 1000;
                  gameObject->players[curPlayerIdx].resources[0] -= 10;
                  Bankbox::refreshCaptions(thisa->bankbox, 1);
                }
              }
            }
            HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
            goto LABEL_191;
          case BUILDING_MARKET:
            if ( isRightClick )
              goto LABEL_127;
            v30 = 0;
            for ( buildingCode = 0; curPlayer->numCastles > buildingCode; ++buildingCode )
            {
              if ( BYTE1(gameObject->castles[curPlayer->castlesOwned[buildingCode]].buildingsBuiltFlags) & 4 )
                ++v30;
            }
            if ( v30 > 10 )
              v30 = 10;
            sub_40EDB0((void *)1, dword_4F5268[v30]);
            TownManager::paint(thisa);
            goto LABEL_191;
          case BUILDING_STATUE:
          case BUILDING_LEFT_TURRET:
          case BUILDING_RIGHT_TURRET:
          case BUILDING_SPECIAL_GROWTH:
          case BUILDING_MOAT:
          case BUILDING_SPECIAL:
            goto LABEL_126;
          default:
            break;
        }
      }
      if ( isRightClick )
      {
        v29 = 0;
        if ( evt->fieldID >= 117 && evt->fieldID <= 121 )
        {
          thisa->field_D6 = thisa->garrisonDisplay;
          thisa->field_DA = evt->fieldID - 117;
          v29 = 1;
        }
        if ( evt->fieldID >= 123 && evt->fieldID <= 127 )
        {
          thisa->field_D6 = thisa->visitingArmyDisplay;
          thisa->field_DA = evt->fieldID - 123;
          v29 = 1;
        }
        if ( v29 && thisa->field_D6->army->creatureTypes[thisa->field_DA] != -1 )
        {
          if ( thisa->field_D6 == thisa->visitingArmyDisplay )
            a10 = &gameObject->heroes[thisa->castle->visitingHeroIdx];
          else
            a10 = 0;
          GameInfo::showStackInfo(
            gameObject,
            119,
            20,
            (CREATURES)thisa->field_D6->army->creatureTypes[thisa->field_DA],
            thisa->field_D6->army->quantities[thisa->field_DA],
            (int)&thisa->castle->idx,
            1,
            1u,
            1,
            a10,
            0,
            thisa->field_D6->army,
            thisa->field_DA);
          Bankbox::refreshCaptions(thisa->bankbox, 1);
        }
      }
      else
      {
        sub_413F80((int)thisa, thisa->field_14A);
        TownManager::setMessageForMouseover(thisa, evt);
      }
    }
    goto LABEL_191;
  }
  if ( code == 1 )
  {
    v11 = evt->messageType;
    if ( v11 == 1 )
    {
      ++v36;
    }
    else
    {
      if ( v11 == 42 || v11 == 54 )
        sub_4148A0();
    }
    goto LABEL_191;
  }
  if ( code == 2 )
  {
    v12 = evt->messageType;
    if ( v12 == 42 || v12 == 54 )
      sub_4148A0();
    goto LABEL_191;
  }
  if ( code != 4 )
  {
LABEL_191:
    if ( v36 == 1 )
    {
      evt->eventCode = 16384;
      evt->messageType = 1;
      result = 2;
    }
    else
    {
      result = 1;
    }
    return result;
  }
  HeroWindowManager::handleInputThunk(HeroWindowManager::instance, (InputEvent *)evt);
  if ( evt->fieldID != thisa->field_142 || evt->inputTypeBitmask != thisa->field_146 )
  {
    thisa->field_142 = evt->fieldID;
    thisa->field_146 = evt->inputTypeBitmask;
    TownManager::setMessageForMouseover(thisa, evt);
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}
