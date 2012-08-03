{
  char *v1; // ST1C_4@18
  signed int result; // eax@45
  signed int i; // [sp+28h] [bp-Ch]@3
  signed int j; // [sp+28h] [bp-Ch]@16
  int v6; // [sp+2Ch] [bp-8h]@3

  *(_DWORD *)&this->heroes[gpCurPlayer->heroesForPurchase[0]].flags1 &= 0xFFFEFFFFu;
  *(_DWORD *)&this->heroes[gpCurPlayer->heroesForPurchase[1]].flags1 &= 0xFFFEFFFFu;
  LODWORD(iCurHourGlassPhase) = 0;
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) && *(_DWORD *)&shouldAutosave )
  {
    v6 = 0;
    for ( i = 0; i < 6; ++i )
    {
      if ( !this->couldBePlayerAlive[i] )
      {
        if ( gbHumanPlayer[i] )
          ++v6;
      }
    }
    game::SaveGame(this, "AUTOSAVE", 1, 0);
  }
  gpAdvManager->identifyCast = 0;
  if ( gpGame->players[giCurPlayer].field_43 > 0 )
    --gpGame->players[giCurPlayer].field_43;
  CheckEndGame(0, 0);
  advManager::DeactivateCurrTown();
  advManager::DeactivateCurrHero(gpAdvManager);
  do
  {
    ++giCurPlayer;
    if ( this->numPlayers <= giCurPlayer )
    {
      giCurPlayer = 0;
      game::PerDay(this);
    }
  }
  while ( gpGame->couldBePlayerAlive[giCurPlayer] );
  gpCurPlayer = &gpGame->players[giCurPlayer];
  giCurPlayerBit = 1 << giCurPlayer;
  for ( j = 0; this->players[giCurPlayer].numHeroes > j; ++j )
  {
    v1 = (char *)&this->heroes[*(&this->players[0].heroesOwned[284 * giCurPlayer] + j - giCurPlayer)];
    *(_DWORD *)(v1 + 49) = hero::CalcMobility((hero *)v1);
    *(_DWORD *)(v1 + 53) = *(_DWORD *)(v1 + 49);
  }
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    SetNoDialogMenus(1);
    inputManager::Flush(gpInputManager);
    gbAllBlack = 1;
    advManager::CheckSetEvilInterface(gpAdvManager, 1, giCurPlayer);
    gbAllBlack = 0;
    if ( gbBlackoutPlayer && iLastMsgNumHumanPlayers > 1 )
    {
      sprintf(gText, "%s's turn.", &cPlayerNames[21 * giCurPlayer]);
      game::WaitForPlayer((int)gText, giCurPlayer);
    }
    if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
      game::CancelComputerScreen();
    giCurWatchPlayerBit = giCurPlayerBit;
    giCurWatchPlayer = giCurPlayer;
  }
  else
  {
    mouseManager::SetPointer(gpMouseManager, 1);
    advManager::HideRoute(gpAdvManager, 1, 0, 1);
    advManager::CheckDimNextHeroBut();
    game::TurnOnAIMusic();
    SetNoDialogMenus(0);
    giBottomViewOverride = 6;
    game::ShowComputerScreen();
    bShowIt = 0;
    if ( gbRemoteOn )
    {
      if ( gbHumanPlayer[giCurPlayer] )
      {
        gbThisNetGotAdventureControl = 0;
        if ( !game::TransmitSaveGame(gpGame, *((_BYTE *)&gbGamePosToNetPos + giCurPlayer), 0, 0) )
          ShutDown(0);
      }
    }
    if ( giBottomViewOverride == 6 )
      giBottomViewOverride = 0;
  }
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) && gbRemoteOn && this->day != 1 && giForceSwitchMusic == -1 )
  {
    soundManager::SwitchAmbientMusic(gpSoundManager, 21);
    giForceSwitchMusic = KBTickCount();
    gpSoundManager->aiMusicOff = 0;
  }
  if ( this->day == 1 && giCurTurn != 1 )
    gpSoundManager->aiMusicOff = 0;
  game::DoNewTurn(this);
  CheckEndGame(0, 0);
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) && !gpSoundManager->aiMusicOff && giForceSwitchMusic == -1 )
  {
    gpSoundManager->aiMusicOff = 1;
    soundManager::SwitchAmbientMusic(
      gpSoundManager,
      (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
    advManager::SetEnvironmentOrigin(gpAdvManager, gpAdvManager->viewX + 7, gpAdvManager->viewY + 7, 1);
  }
  result = *(&gbThisNetHumanPlayer + giCurPlayer);
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
    result = advManager::ForceNewHover(gpAdvManager);
  return result;
}