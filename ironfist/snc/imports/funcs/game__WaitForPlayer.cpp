{
  if ( gbBlackoutPlayer && iLastMsgNumHumanPlayers > 1 )
  {
    if ( !gbRemoteOn )
    {
      mouseManager::SetPointer(gpMouseManager, 0);
      gbAllBlack = 1;
      giBottomViewOverrideEndTime = KBTickCount() + 9999999;
      giBottomViewOverride = *(&gbThisNetHumanPlayer + giCurPlayer) != 0;
      gpSoundManager->aiMusicOff = 1;
      soundManager::SwitchAmbientMusic(gpSoundManager, 21);
      advManager::CompleteDraw(gpAdvManager, 1);
      advManager::UpdateHeroLocators(gpAdvManager, 1, 1);
      advManager::UpdateTownLocators(gpAdvManager, 1, 1);
      advManager::UpdateScreen(gpAdvManager, 0, 1);
      game::ShowHeroesLogo();
      gbAllBlack = 0;
      NormalDialog((char *)a1, 1, -1, -1, 9, gpGame->players[a2].color, -1, 0, -1, 0);
      soundManager::SwitchAmbientMusic(gpSoundManager, -1);
    }
  }
}