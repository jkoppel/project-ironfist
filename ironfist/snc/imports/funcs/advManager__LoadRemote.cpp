{
  heroWindow *result; // eax@13
  void *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
    mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  game::LoadGame(gpGame, (const char *)&gConfig + 327, 0, 1);
  if ( (gpGame->day != 1 || gpGame->week == 1 && gpGame->month == 1)
    && gbRemoteOn
    && *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    gpSoundManager->aiMusicOff = 1;
    soundManager::SwitchAmbientMusic(gpSoundManager, 21);
    gpSoundManager->aiMusicOff = 0;
    giForceSwitchMusic = KBTickCount();
  }
  if ( gpGame->couldBePlayerAlive[giCurPlayer] )
    ComputeAdvNetControl();
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    game::CancelComputerScreen();
    gbThisNetGotAdventureControl = 1;
    gpSoundManager->aiMusicOff = 0;
  }
  game::DoNewTurn(gpGame);
  advManager::UpdateHeroLocators((advManager *)thisa, 1, 1);
  advManager::UpdateTownLocators(thisa, 1, 1);
  advManager::UpdateRadar((int)thisa, 1, 0);
  advManager::UpdBottomView((advManager *)thisa, 1, 1, 1);
  advManager::ForceNewHover(gpAdvManager);
  SendMapChange(11, 0, 0, 0, -999, 0, 0);
  gpSoundManager->aiMusicOff = 1;
  result = (heroWindow *)gpGame->_10[32];
  if ( gpGame->_10[32] && !dword_50EA80 )
  {
    dword_50EA80 = 1;
    sprintf(gText, "Someone is cheating!\n");
    result = NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  if ( giDebugLevel > 0 )
  {
    if ( !dword_50EA84 )
    {
      dword_50EA84 = 1;
      sprintf(gText, "Someone has their debug level set!\n");
      result = NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  return result;
}