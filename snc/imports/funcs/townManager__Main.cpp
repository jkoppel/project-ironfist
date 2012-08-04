{
  armyGroup *v2; // ST20_4@36
  int v3; // eax@36
  int v4; // ST2C_4@47
  int v5; // eax@47
  const char *v6; // eax@87
  signed int v7; // eax@93
  const char *v8; // eax@124
  const char *v9; // eax@125
  signed int result; // eax@169
  int v11; // [sp+Ch] [bp-250h]@176
  int v12; // [sp+10h] [bp-24Ch]@171
  int v13; // [sp+14h] [bp-248h]@153
  int v14; // [sp+18h] [bp-244h]@17
  int msgType; // [sp+1Ch] [bp-240h]@16
  INPUT_EVENT_CODE code; // [sp+20h] [bp-23Ch]@15
  townManager *thisa; // [sp+24h] [bp-238h]@1
  heroWindow *v18; // [sp+44h] [bp-218h]@99
  heroWindow *v19; // [sp+4Ch] [bp-210h]@79
  heroWindow *v20; // [sp+54h] [bp-208h]@72
  heroWindow *v21; // [sp+5Ch] [bp-200h]@64
  strip *v22; // [sp+60h] [bp-1FCh]@46
  strip *v23; // [sp+68h] [bp-1F4h]@44
  strip *ecx0; // [sp+74h] [bp-1E8h]@35
  strip *v25; // [sp+7Ch] [bp-1E0h]@33
  heroWindow *window; // [sp+84h] [bp-1D8h]@27
  recruitUnit *thisb; // [sp+8Ch] [bp-1D0h]@20
  hero *hro; // [sp+94h] [bp-1C8h]@139
  signed int v29; // [sp+98h] [bp-1C4h]@130
  signed int v30; // [sp+A8h] [bp-1B4h]@115
  baseManager *a2; // [sp+B0h] [bp-1ACh]@21
  signed int v32; // [sp+B4h] [bp-1A8h]@2
  char msg; // [sp+B8h] [bp-1A4h]@87
  signed int buildingCode; // [sp+248h] [bp-14h]@3
  sample_resource res; // [sp+24Ch] [bp-10h]@40
  int v36; // [sp+254h] [bp-8h]@1
  int isRightClick; // [sp+258h] [bp-4h]@1

  thisa = this;
  v36 = 0;
  isRightClick = (BYTE1(evt->inputTypeBitmask) & 2) != 0;
  if ( giDebugBuildingToBuild != -1 )
  {
    v32 = giDebugBuildingToBuild;
    giDebugBuildingToBuild = -1;
    if ( v32 == 100 )
    {
      for ( buildingCode = 0; buildingCode < 32; ++buildingCode )
      {
        if ( (1 << buildingCode) & gTownEligibleBuildMask[thisa->castle->factionID] || buildingCode == 6 )
          townManager::BuildObj(thisa, buildingCode);
      }
    }
    else if ( (1 << v32) & gTownEligibleBuildMask[this->castle->factionID] || v32 == 6 )
    {
      townManager::BuildObj(this, v32);
    }
  }
  if ( KBTickCount() > glTimers )
  {
    townManager::DrawTown(thisa, 1, 1);
    glTimers = KBTickCount() + 150;
  }
  code = evt->eventCode;
  if ( code > INPUT_GUI_MESSAGE_CODE )
    goto LABEL_188;
  if ( code == INPUT_GUI_MESSAGE_CODE )
  {
    msgType = evt->messageType;
    if ( msgType == 12 )
      goto LABEL_201;
    if ( msgType == 13 )
    {
      v13 = evt->fieldID;
      if ( v13 >= 903 )
      {
        if ( v13 <= 904 )
        {
          if ( thisa->castle->ownerIdx == giCurPlayer && gpCurPlayer->numCastles > 1 )
          {
            thisa->castle = &gpGame->castles[gpCurPlayer->castlesOwned[(getCastleOwnedIdx(
                                                                          gpCurPlayer,
                                                                          thisa->castle->idx)
                                                                      + gpCurPlayer->numCastles
                                                                      + ((unsigned int)(evt->fieldID - 903) < 1 ? -1 : 1))
                                                                     % gpCurPlayer->numCastles]];
            townManager::ChangeTown(thisa);
          }
        }
        else if ( v13 == 30720 && !isRightClick )
        {
          ++v36;
        }
      }
      goto LABEL_188;
    }
    if ( msgType == 14 )
    {
LABEL_201:
      v14 = evt->fieldID;
      if ( v14 > 15 )
      {
        if ( v14 >= 19 )
        {
          if ( v14 <= 30 )
          {
            if ( isRightClick )
            {
              QuickViewRecruit(thisa->castle, evt->fieldID - 19);
            }
            else
            {
              townManager::DrawTown(thisa, 1, 1);
              thisb = (recruitUnit *)operator new(126);
              if ( thisb )
                a2 = (baseManager *)recruitUnit::recruitUnit(thisb, (int)&thisa->castle->idx, evt->fieldID - 19, 1);
              else
                a2 = 0;
              if ( !a2 )
                MemError();
              executive::DoDialog(gpExec, a2);
              operator delete(a2);
            }
            goto LABEL_188;
          }
          if ( v14 == 30720 )
          {
            if ( !isRightClick )
              townManager::SetCommandAndText(thisa, evt);
            goto LABEL_188;
          }
        }
      }
      else
      {
        if ( v14 == 15 )
        {
LABEL_123:
          if ( isRightClick )
          {
LABEL_124:
            v8 = GetBuildingInfo(thisa->castle->factionID, evt->fieldID, 1);
            sprintf(&msg, v8);
            NormalDialog(&msg, 4, -1, -1, thisa->castle->factionID + 19, evt->fieldID, -1, 0, -1, 0);
          }
          else
          {
            v9 = GetBuildingInfo(thisa->castle->factionID, evt->fieldID, 1);
            sprintf(&msg, v9);
            NormalDialog(&msg, 1, -1, -1, thisa->castle->factionID + 19, evt->fieldID, -1, 0, -1, 0);
          }
          goto LABEL_188;
        }
        switch ( v14 )
        {
          case BUILDING_CASTLE:
            if ( isRightClick )
              goto LABEL_124;
            window = (heroWindow *)operator new(68);
            if ( window )
              thisa->curScreen = heroWindow::heroWindow(window, 0, 0, "caslwind.bin");
            else
              thisa->curScreen = 0;
            if ( !thisa->curScreen )
              MemError();
            townManager::SetupCastle(thisa, thisa->curScreen, 0);
            thisa->field_15A = 1;
            thisa->field_14E = 0;
            heroWindowManager::DoDialog(
              gpWindowManager,
              thisa->curScreen,
              (int (__fastcall *)(tag_message *))CastleHandler,
              0);
            thisa->field_15A = 0;
            operator delete(thisa->curScreen);
            if ( thisa->field_14E )
            {
              townManager::RedrawTownScreen(thisa);
              heroWindowManager::SaveFizzleSource(gpWindowManager, 0, 256, 552, 204);
              v25 = thisa->visitingArmyDisplay;
              if ( v25 )
              {
                strip::_strip(v25);
                operator delete(v25);
              }
              sprintf(gText, "port%04d.icn", *(_BYTE *)(*(_DWORD *)&thisa->_3[16] + 24));
              ecx0 = (strip *)operator new(132);
              if ( ecx0 )
              {
                v2 = (armyGroup *)(*(_DWORD *)&thisa->_3[16] + 101);
                v3 = resourceManager::MakeId(gpResourceManager, gText, 1);
                thisa->visitingArmyDisplay = strip::strip(ecx0, 0, 355, 3, v3, 0, v2, 122, 0, -1);
              }
              else
              {
                thisa->visitingArmyDisplay = 0;
              }
              if ( !thisa->visitingArmyDisplay )
                MemError();
              res = LoadPlaySample("buildtwn.82M");
              heroWindow::DrawWindow(thisa->townScreen, 0);
              strip::DrawIcons(thisa->garrisonDisplay, 0);
              strip::DrawIcons(thisa->visitingArmyDisplay, 0);
              heroWindowManager::FizzleForward(gpWindowManager, 0, 256, 552, 204, -1, 0, 0);
              WaitEndSample(-1, res);
              thisa->field_14E = 0;
              heroWindowManager::ReleaseFizzleSource(gpWindowManager);
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
                    strip::_strip(v23);
                    operator delete(v23);
                  }
                }
                thisa->visitingArmyDisplay = 0;
                sprintf(gText, "port%04d.icn", thisa->castle->factionID + 90);
                v22 = (strip *)operator new(132);
                if ( v22 )
                {
                  v4 = gpCurPlayer->color;
                  v5 = resourceManager::MakeId(gpResourceManager, gText, 1);
                  thisa->visitingArmyDisplay = strip::strip(v22, 0, 355, 3, v5, 0, 0, -1, 0, v4);
                }
                else
                {
                  thisa->visitingArmyDisplay = 0;
                }
                if ( !thisa->visitingArmyDisplay )
                  MemError();
              }
              townManager::RedrawTownScreen(thisa);
              if ( thisa->field_15E != -1 )
                townManager::BuildObj(thisa, thisa->field_15E);
            }
            goto LABEL_188;
          case BUILDING_MAGE_GUILD:
            if ( isRightClick )
              goto LABEL_124;
            if ( thisa->castle->visitingHeroIdx == -1
              || hero::HasArtifact(&gpGame->heroes[thisa->castle->visitingHeroIdx], ARTIFACT_MAGIC_BOOK) )
            {
              v21 = (heroWindow *)operator new(68);
              if ( v21 )
                thisa->curScreen = heroWindow::heroWindow(v21, 0, 0, "magewind.bin");
              else
                thisa->curScreen = 0;
              if ( !thisa->curScreen )
                MemError();
              SetWinText(thisa->curScreen, 17);
              townManager::SetupMage(thisa, thisa->curScreen);
              heroWindowManager::DoDialog(gpWindowManager, thisa->curScreen, MageGuildHandler, 0);
              operator delete(thisa->curScreen);
            }
            else if ( hero::NumArtifacts(&gpGame->heroes[thisa->castle->visitingHeroIdx]) == 14 )
            {
              NormalDialog(
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
            else if ( gpCurPlayer->resources[6] >= 500 )
            {
              NormalDialog(
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
              if ( gpWindowManager->buttonPressedCode == 30725 )
              {
                GiveArtifact(&gpGame->heroes[thisa->castle->visitingHeroIdx], ARTIFACT_MAGIC_BOOK, 1, -1);
                gpCurPlayer->resources[6] -= 500;
                bankBox::Update(thisa->bankbox, 1);
                heroWindow::DrawWindow(thisa->townScreen);
                town::GiveSpells(thisa->castle, 0);
              }
            }
            else
            {
              NormalDialog(
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
            town::GiveSpells(thisa->castle, 0);
            townManager::RedrawTownScreen(thisa);
            goto LABEL_188;
          case BUILDING_WELL:
            if ( isRightClick )
              goto LABEL_124;
            v20 = (heroWindow *)operator new(68);
            if ( v20 )
              thisa->curScreen = heroWindow::heroWindow(v20, 0, 0, "wellwind.bin");
            else
              thisa->curScreen = 0;
            if ( !thisa->curScreen )
              MemError();
            townManager::SetupWell(thisa, thisa->curScreen);
            heroWindowManager::DoDialog(gpWindowManager, thisa->curScreen, TrueFalseDialogHandler, 0);
            operator delete(thisa->curScreen);
            townManager::RedrawTownScreen(thisa);
            goto LABEL_188;
          case BUILDING_THIEVES_GUILD:
            if ( isRightClick )
              goto LABEL_124;
            v19 = (heroWindow *)operator new(68);
            if ( v19 )
              thisa->curScreen = heroWindow::heroWindow(v19, 0, 0, "thiefwin.bin");
            else
              thisa->curScreen = 0;
            if ( !thisa->curScreen )
              MemError();
            SetWinText(thisa->curScreen, 14);
            townManager::SetupThievesGuild(thisa->curScreen, -1);
            heroWindowManager::DoDialog(gpWindowManager, thisa->curScreen, TrueFalseDialogHandler, 0);
            operator delete(thisa->curScreen);
            townManager::RedrawTownScreen(thisa);
            goto LABEL_188;
          case BUILDING_TAVERN:
            if ( isRightClick )
              goto LABEL_124;
            if ( thisa->castle->factionID == FACTION_NECROMANCER )
            {
              v6 = GetBuildingInfo(thisa->castle->factionID, evt->fieldID, 1);
              sprintf(&msg, v6);
              NormalDialog(&msg, 1, -1, -1, thisa->castle->factionID + 19, evt->fieldID, -1, 0, -1, 0);
            }
            else
            {
              townManager::DoTavern(thisa);
            }
            goto LABEL_188;
          case BUILDING_TENT:
            if ( isRightClick )
              goto LABEL_124;
            if ( thisa->castle->mayNotBeUpgradedToCastle )
            {
              NormalDialog("This town may not be upgraded to a castle.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
            else
            {
              v7 = CanBuy((int)&thisa->castle->idx, 6);
              if ( townManager::BuyBuild(thisa, 6, (unsigned int)v7 < 1, isRightClick) )
                townManager::BuildObj(thisa, 6);
            }
            goto LABEL_188;
          case BUILDING_DOCK:
            if ( isRightClick )
              goto LABEL_124;
            heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 5, 30720, 16392);
            if ( game::GetBoatsBuilt(gpGame) >= 48
              || advManager::GetCell(gpAdvManager, LOBYTE(thisa->castle->field_6), HIBYTE(thisa->castle->field_6))->objType )
            {
              NormalDialog("Cannot build another boat.", 1, 208, 40, -1, 0, -1, 0, -1, 0);
            }
            else
            {
              v18 = (heroWindow *)operator new(68);
              if ( v18 )
                thisa->curScreen = heroWindow::heroWindow(v18, 177, 20, "shipwind.bin");
              else
                thisa->curScreen = 0;
              if ( !thisa->curScreen )
                MemError();
              SetWinText(thisa->curScreen, 12);
              if ( gpGame->players[giCurPlayer].resources[6] < 1000 || gpGame->players[giCurPlayer].resources[0] < 10 )
              {
                evt->eventCode = 512;
                evt->messageType = 5;
                evt->fieldID = 30722;
                evt->payload = (void *)4096;
                heroWindow::BroadcastMessage(thisa->curScreen, (Event *)evt);
                evt->messageType = 6;
                evt->payload = (void *)2;
                heroWindow::BroadcastMessage(thisa->curScreen, (Event *)evt);
              }
              heroWindowManager::DoDialog(gpWindowManager, thisa->curScreen, TrueFalseDialogHandler, 0);
              operator delete(thisa->curScreen);
              if ( gpWindowManager->buttonPressedCode == 30722 )
              {
                if ( game::CreateBoat(gpGame, LOBYTE(thisa->castle->field_6), HIBYTE(thisa->castle->field_6), 0) == -1 )
                {
                  LogStr("Can't create boat!");
                }
                else
                {
                  townManager::BuildObj(thisa, 14);
                  gpGame->players[giCurPlayer].resources[6] -= 1000;
                  gpGame->players[giCurPlayer].resources[0] -= 10;
                  bankBox::Update(thisa->bankbox, 1);
                }
              }
            }
            heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
            goto LABEL_188;
          case BUILDING_MARKET:
            if ( isRightClick )
              goto LABEL_124;
            v30 = 0;
            for ( buildingCode = 0; gpCurPlayer->numCastles > buildingCode; ++buildingCode )
            {
              if ( BYTE1(gpGame->castles[gpCurPlayer->castlesOwned[buildingCode]].buildingsBuiltFlags) & 4 )
                ++v30;
            }
            if ( v30 > 10 )
              v30 = 10;
            DoTradingPost((void *)1, dword_4F5268[v30]);
            townManager::RedrawTownScreen(thisa);
            goto LABEL_188;
          case BUILDING_STATUE:
          case BUILDING_LEFT_TURRET:
          case BUILDING_RIGHT_TURRET:
          case BUILDING_SPECIAL_GROWTH:
          case BUILDING_MOAT:
          case BUILDING_SPECIAL:
            goto LABEL_123;
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
            hro = &gpGame->heroes[thisa->castle->visitingHeroIdx];
          else
            hro = 0;
          game::ViewArmy(
            gpGame,
            119,
            20,
            (CREATURES)thisa->field_D6->army->creatureTypes[thisa->field_DA],
            thisa->field_D6->army->quantities[thisa->field_DA],
            (int)&thisa->castle->idx,
            1,
            1u,
            1,
            hro,
            0,
            thisa->field_D6->army,
            thisa->field_DA);
          bankBox::Update(thisa->bankbox, 1);
        }
      }
      else
      {
        townManager::DoCommand(thisa, thisa->field_14A);
        townManager::SetCommandAndText(thisa, evt);
      }
    }
    goto LABEL_188;
  }
  if ( code == 1 )
  {
    v11 = evt->messageType;
    if ( v11 == 1 )
    {
      ++v36;
    }
    else if ( v11 == 42 || v11 == 54 )
    {
      townManager::ShiftQualChange();
    }
    goto LABEL_188;
  }
  if ( code == 2 )
  {
    v12 = evt->messageType;
    if ( v12 == 42 || v12 == 54 )
      townManager::ShiftQualChange();
    goto LABEL_188;
  }
  if ( code != 4 )
  {
LABEL_188:
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
  heroWindowManager::ConvertToHover(gpWindowManager, (tag_message *)evt);
  if ( evt->fieldID != thisa->field_142 || evt->inputTypeBitmask != thisa->field_146 )
  {
    thisa->field_142 = evt->fieldID;
    thisa->field_146 = evt->inputTypeBitmask;
    townManager::SetCommandAndText(thisa, evt);
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}