{
  int v1; // eax@9
  int v2; // [sp+0h] [bp-58h]@0
  game *thisa; // [sp+Ch] [bp-4Ch]@1
  int track; // [sp+10h] [bp-48h]@20
  char v5; // [sp+14h] [bp-44h]@23
  char a1; // [sp+48h] [bp-10h]@20

  thisa = this;
  game::CheckForTimeEvent(this);
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    giBottomViewOverrideEndTime = KBTickCount() + 3000;
    giBottomViewOverride = 1;
    advManager::UpdBottomView(gpAdvManager, 1, 1, 1);
    advManager::SetInitialMapOrigin(gpAdvManager);
    advManager::CompleteDraw(gpAdvManager, 0);
    advManager::UpdateScreen(gpAdvManager, 0, 0);
    CheckEndGame(0, 0);
    if ( gpCurPlayer->field_43 >= 0 )
    {
      if ( gpCurPlayer->field_43 == 1 )
        sprintf(gText, off_4F6544, &cPlayerNames[21 * giCurPlayer]);
      else
        sprintf(gText, cNewTurn, &cPlayerNames[21 * giCurPlayer], gpCurPlayer->field_43);
      NormalDialog(gText, 1, -1, -1, 9, gpGame->players[(char)giCurPlayer].color, -1, 0, -1, 0);
    }
    if ( gpCurPlayer->numHeroes <= 0 )
    {
      if ( gpCurPlayer->numCastles > 0 )
        advManager::SetTownContext(gpAdvManager, gpCurPlayer->castlesOwned[0]);
    }
    else
    {
      v1 = playerData::NextHero(gpCurPlayer, 0);
      advManager::SetHeroContext(gpAdvManager, v1, 0);
    }
    advManager::CheckDimNextHeroBut();
    if ( thisa->day == 1 && (thisa->month != 1 || thisa->week != 1 || thisa->day != 1) )
    {
      if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
        gpSoundManager->aiMusicOff = 1;
      if ( *(_DWORD *)&giWeekType != -1 )
      {
        if ( thisa->week == 1 )
        {
          track = 21;
          strcpy(&a1, "newmonth.82m");
          if ( giMonthType )
          {
            if ( giMonthType == 1 )
            {
              strcpy(&v5, gArmyNames[*(_DWORD *)&giMonthTypeExtra]);
              v5 -= 32;
              sprintf(gText, off_4F654C, gArmyNames[*(_DWORD *)&giMonthTypeExtra], &v5);
            }
            else
            {
              sprintf(gText, off_4F6550);
            }
          }
          else
          {
            sprintf(gText, off_4F6548, gMonthNames[*(_DWORD *)&giMonthTypeExtra]);
          }
        }
        else
        {
          track = 20;
          strcpy(&a1, "newweek.82m");
          if ( *(_DWORD *)&giWeekType )
          {
            strcpy(&v5, gArmyNames[*(_DWORD *)&giWeekTypeExtra]);
            v5 -= 32;
            sprintf(gText, off_4F6558, gArmyNames[*(_DWORD *)&giWeekTypeExtra], &v5);
          }
          else
          {
            sprintf(gText, off_4F6554, gWeekNames[*(_DWORD *)&giWeekTypeExtra]);
          }
        }
        soundManager::PlayAmbientMusic(gpSoundManager, track, 0, -1, v2);
        mouseManager::SetPointer(gpMouseManager, 0);
        NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        soundManager::SwitchAmbientMusic(
          gpSoundManager,
          (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
      }
    }
    soundManager::SwitchAmbientMusic(
      gpSoundManager,
      (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
    advManager::SetEnvironmentOrigin(gpAdvManager, gpAdvManager->viewX + 7, gpAdvManager->viewY + 7, 1);
  }
  else
  {
    CheckEndGame(0, 0);
  }
}