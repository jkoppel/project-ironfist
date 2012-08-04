{
  char *v1; // ST2C_4@3
  hero *v2; // ST24_4@11
  char *v3; // ST20_4@13
  playerData *v6; // [sp+18h] [bp-Ch]@8

  heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 5, 2, 16392);
  *(_DWORD *)&this->_2[12] = 0;
  *(_DWORD *)&this->_2[8] = *(_DWORD *)&this->_2[12];
  this->field_272 = 0;
  gbHeroMoving = 0;
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) && LOBYTE(gpCurPlayer->field_45) != -1 )
  {
    v1 = (char *)&gpGame->castles[LOBYTE(gpCurPlayer->field_45)];
    this->viewX = gpGame->castles[LOBYTE(gpCurPlayer->field_45)].field_4 - 7;
    this->viewY = (unsigned __int8)v1[5] - 7;
  }
  else if ( *(&gbThisNetHumanPlayer + giCurPlayer) && gpCurPlayer->curHeroIdx != -1 )
  {
    advManager::MobilizeCurrHero(this, 0);
  }
  else
  {
    if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
      v6 = gpCurPlayer;
    else
      v6 = &gpGame->players[giThisGamePos];
    if ( v6->numHeroes <= 0 )
    {
      if ( v6->numCastles <= 0 )
      {
        this->viewX = 0;
        this->viewY = 0;
      }
      else
      {
        v3 = (char *)&gpGame->castles[v6->castlesOwned[0]];
        this->viewX = gpGame->castles[v6->castlesOwned[0]].field_4 - 7;
        this->viewY = (unsigned __int8)v3[5] - 7;
      }
    }
    else
    {
      v2 = &gpGame->heroes[v6->heroesOwned[0]];
      this->viewX = gpGame->heroes[v6->heroesOwned[0]].x - 7;
      this->viewY = v2->y - 7;
    }
  }
  this->currentTerrain = (unsigned __int8)giGroundToTerrain[advManager::GetCell(this, this->viewX + 7, this->viewY + 7)->tileType];
  soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
  advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
  advManager::Reseed(0, 0);
  return advManager::CheckDimNextHeroBut();
}