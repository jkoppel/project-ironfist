{
  int v2; // edx@1
  signed int result; // eax@5
  int v4; // edx@6
  int v5; // eax@134
  const CHAR *v6; // [sp+0h] [bp-54h]@0
  int v7; // [sp+Ch] [bp-48h]@60
  int v8; // [sp+14h] [bp-40h]@22
  INPUT_EVENT_CODE v9; // [sp+18h] [bp-3Ch]@21
  signed int a8; // [sp+20h] [bp-34h]@138
  int a6; // [sp+24h] [bp-30h]@138
  int v13; // [sp+28h] [bp-2Ch]@83
  int v14; // [sp+2Ch] [bp-28h]@27
  hero *hro; // [sp+30h] [bp-24h]@46
  int a2; // [sp+34h] [bp-20h]@45
  mapCell *loc; // [sp+38h] [bp-1Ch]@20
  int i; // [sp+40h] [bp-14h]@66
  int v19; // [sp+4Ch] [bp-8h]@20
  int a3; // [sp+50h] [bp-4h]@20

  if ( KBTickCount() > glTimers && advManager::ComboDraw(this, 1) )
    advManager::UpdateScreen(this, 1, 0);
  if ( gbGameOver )
  {
    evt->eventCode = 16384;
    evt->xCoordOrKeycode = 1;
    return 2;
  }
  advManager::CheckHandleNet(this, v2);
  if ( !gbThisNetGotAdventureControl )
    return advManager::CheckHandleNetPlayerWait(this, (int)evt, 0);
  if ( !gbHumanPlayer[giCurPlayer] )
  {
    philAI::DoAI((void *)gpPhilAI, giCurPlayer);
    game::NextPlayer(gpGame);
    return 1;
  }
  if ( giScreenScroll && gbForegroundApp )
    advManager::CheckScreenScroll(this);
  if ( !gbNoSound && *(_DWORD *)&Data && giForceSwitchMusic > 0 && KBTickCount() - giForceSwitchMusic > 6000 )
  {
    giForceSwitchMusic = -1;
    if ( gpSoundManager->currentTrack == 21 )
      soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
    advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
  }
  v19 = 1;
  a3 = 0;
  loc = 0;
  if ( evt->eventCode )
  {
    v9 = evt->eventCode;
    if ( v9 == INPUT_KEYDOWN_EVENT_CODE )
    {
      a2 = -1;
      if ( gpCurPlayer->curHeroIdx == -1 )
        hro = 0;
      else
        hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
      if ( giDebugLevel >= 1
        || evt->xCoordOrKeycode != 61
        && evt->xCoordOrKeycode != 62
        && evt->xCoordOrKeycode != 63
        && evt->xCoordOrKeycode != 64
        && evt->xCoordOrKeycode != 65
        && evt->xCoordOrKeycode != 66
        && evt->xCoordOrKeycode != 67
        && evt->xCoordOrKeycode != 68
        && evt->xCoordOrKeycode != 87
        && evt->xCoordOrKeycode != 88 )
      {
        v7 = evt->xCoordOrKeycode;
        while ( 2 )
        {
          --v7;
          switch ( v7 )
          {
            case 59:
              CreateColorTables(v6);
              PopNetBox(0, (void *)0xFFFFFFFF);
              goto LABEL_136;
            case 63:
              game::CheckHeroConsistency(gpGame);
              goto LABEL_136;
            case 64:
              gpCurPlayer->_3[0] += 12;
              if ( hro )
                advManager::GiveExperience(hro, 3000, 1);
              goto LABEL_136;
            case 66:
              for ( i = 0; i < 7; ++i )
              {
                if ( i == 6 )
                  gpCurPlayer->resources[6] += 1000;
                else
                  gpCurPlayer->resources[i] += 10;
              }
              goto LABEL_136;
            case 10:
              i = 0;
              goto LABEL_83;
            case 1:
              i = 1;
              goto LABEL_83;
            case 2:
              i = 2;
              goto LABEL_83;
            case 3:
              i = 3;
              goto LABEL_83;
            case 4:
              i = 4;
              goto LABEL_83;
            case 5:
              i = 5;
              goto LABEL_83;
            case 6:
              i = 6;
              goto LABEL_83;
            case 7:
              i = 7;
              goto LABEL_83;
            case 8:
              i = 8;
              goto LABEL_83;
            case 9:
              i = 9;
LABEL_83:
              v13 = 0;
              JUMPOUT(*(int *)loc_444C90);
              return result;
            case 71:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 0, 0);
              else
                a2 = 0;
              goto LABEL_136;
            case 72:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 1, 0);
              else
                a2 = 1;
              goto LABEL_136;
            case 76:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 2, 0);
              else
                a2 = 2;
              goto LABEL_136;
            case 80:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 3, 0);
              else
                a2 = 3;
              goto LABEL_136;
            case 79:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 4, 0);
              else
                a2 = 4;
              goto LABEL_136;
            case 78:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 5, 0);
              else
                a2 = 5;
              goto LABEL_136;
            case 74:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 6, 0);
              else
                a2 = 6;
              goto LABEL_136;
            case 70:
              if ( evt->inputTypeBitmask & 0xC )
                advManager::ScreenScroll(this, 7, 0);
              else
                a2 = 7;
              goto LABEL_136;
            case 45:
              advManager::CheckCastSpell();
              goto LABEL_136;
            case 31:
              advManager::ProcessSearch(this, -1i64);
              goto LABEL_136;
            case 24:
              advManager::ViewPuzzle(this);
              goto LABEL_136;
            case 46:
              advManager::ViewWorld(this, v4, 53, 0, 0);
              goto LABEL_136;
            case 48:
              i = 101;
              strcpy(gText, "Are you sure you want to restart?  (Your current game will be lost)");
              goto LABEL_123;
            case 37:
              i = 102;
              strcpy(gText, "Are you sure you want to load a new game?  (Your current game will be lost)");
              goto LABEL_123;
            case 15:
              i = 105;
              strcpy(gText, "Are you sure you want to quit?");
LABEL_123:
              a3 = 1;
              NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
              if ( gpWindowManager->buttonPressedCode == 30726 )
                a3 = 0;
              else
                gGameCommand = i;
              goto LABEL_136;
            case 30:
              SaveGame();
              goto LABEL_136;
            case 22:
              if ( gbInCampaign )
              {
                advManager::SetEnvironmentOrigin(this, -1, -1, 1);
                game::ShowCampaignInfo(gpGame, 1, 0);
                advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
                advManager::RedrawAdvScreen(this, 1, 0);
                soundManager::SwitchAmbientMusic(
                  gpSoundManager,
                  (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
              }
              else if ( xIsPlayingExpansionCampaign )
              {
                advManager::SetEnvironmentOrigin(this, -1, -1, 1);
                ExpCampaign::ShowInfo((int)&xCampaign, 1, 0);
                advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
                advManager::RedrawAdvScreen(this, 1, 0);
                soundManager::SwitchAmbientMusic(
                  gpSoundManager,
                  (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
              }
              else
              {
                game::ShowScenInfo(gpGame);
              }
              goto LABEL_136;
            case 34:
              v5 = playerData::NextHero(gpCurPlayer, 0);
              advManager::SetHeroContext(this, v5, 0);
              goto LABEL_136;
            case 27:
              continue;
            case 65:
            case 0:
            case 19:
LABEL_136:
              if ( gpCurPlayer->curHeroIdx != -1 && a2 >= 0 )
              {
                advManager::HideRoute(this, 1, 1, 1);
                mouseManager::HideColorPointer(gpMouseManager);
                loc = advManager::MoveHero(this, a2, 1, &TrigX, &TrigX + 1, (int)&a6, 0, (signed int)&a8, 0);
                advManager::UpdateHeroLocator(this, -1, 1, 1);
                while ( gpMouseManager->cursorDisabled )
                  mouseManager::ShowColorPointer(gpMouseManager);
                soundManager::SwitchAmbientMusic(
                  gpSoundManager,
                  (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
                if ( loc )
                {
                  advManager::StopCursor(this, 1);
                  advManager::DoEvent(this, loc, TrigX, *(&TrigX + 1));
                  loc = 0;
                }
                advManager::Reseed(0, 0);
                advManager::ForceNewHover(this);
                advManager::UpdBottomView(this, 1, 1, 1);
                advManager::CheckDimHero(this);
              }
              break;
          }
          break;
        }
      }
      goto LABEL_148;
    }
    if ( v9 == 4 )
    {
      v19 = advManager::ProcessHover(this, evt->altXCoord, evt->altYCoord);
    }
    else if ( v9 == 512 )
    {
      v8 = evt->xCoordOrKeycode;
      if ( v8 == 12 )
        goto LABEL_157;
      if ( v8 == 13 )
      {
        if ( !(BYTE1(evt->inputTypeBitmask) & 2) )
          v19 = advManager::ProcessDeSelect(this, (GUIMessage *)evt, (int)&a3, (int)&loc);
        goto LABEL_148;
      }
      if ( v8 == 14 )
      {
        if ( !(BYTE1(evt->inputTypeBitmask) & 2) )
          goto LABEL_158;
LABEL_157:
        v14 = -1;
        switch ( evt->yCoord )
        {
          case 1:
            v14 = 0;
            break;
          case 2:
            v14 = 1;
            break;
          case 3:
            v14 = 2;
            break;
          case 4:
            v14 = 3;
            break;
          case 5:
            v14 = 4;
            break;
          case 6:
            v14 = 5;
            break;
          case 7:
            v14 = 6;
            break;
          case 8:
            v14 = 7;
            break;
          default:
            break;
        }
        if ( v14 >= 0 )
          NormalDialog(gEventText[v14 + 122], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        else
LABEL_158:
          v19 = advManager::ProcessSelect((int)this, (int)evt, (int)&loc);
      }
    }
  }
LABEL_148:
  if ( loc )
    advManager::DoEvent(this, loc, TrigX, *(&TrigX + 1));
  if ( gbGameOver || a3 == 1 || giMenuCommand != -1 )
  {
    evt->eventCode = 16384;
    evt->xCoordOrKeycode = 1;
    result = 2;
  }
  else
  {
    result = v19;
  }
  return result;
}