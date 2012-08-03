{
  advManager *result; // eax@12
  int v4; // [sp+10h] [bp-Ch]@1
  int v5; // [sp+10h] [bp-Ch]@10
  signed int i; // [sp+14h] [bp-8h]@1
  char *v7; // [sp+18h] [bp-4h]@1

  advManager::DeactivateCurrHero(this);
  LOBYTE(gpCurPlayer->field_45) = a2;
  v7 = (char *)&gpGame->castles[LOBYTE(gpCurPlayer->field_45)];
  this->viewX = gpGame->castles[LOBYTE(gpCurPlayer->field_45)].field_4 - 7;
  this->viewY = (unsigned __int8)v7[5] - 7;
  v4 = 0;
  for ( i = 0; gpCurPlayer->numCastles > i; ++i )
  {
    if ( gpCurPlayer->castlesOwned[i] == a2 )
      v4 = i;
  }
  if ( SHIBYTE(gpCurPlayer->field_45) <= v4 )
  {
    if ( HIBYTE(gpCurPlayer->field_45) + 3 < v4 )
      HIBYTE(gpCurPlayer->field_45) = v4 - 3;
  }
  else
  {
    HIBYTE(gpCurPlayer->field_45) = v4;
  }
  advManager::UpdateHeroLocators(this, 1, 1);
  advManager::UpdateTownLocators(this, 1, 1);
  advManager::HideRoute(this, 0, 0, 1);
  advManager::UpdBottomView(this, 1, 1, 1);
  advManager::UpdateRadar((int)this, 1, 0);
  advManager::CompleteDraw(this, this->viewX, this->viewY, 0, 1);
  advManager::UpdateScreen(this, 0, 0);
  advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
  v5 = (unsigned __int8)giGroundToTerrain[advManager::GetCell(this, (unsigned __int8)v7[4], (unsigned __int8)v7[5])->tileType];
  if ( this->currentTerrain != v5 )
  {
    this->currentTerrain = v5;
    soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
  }
  inputManager::ForceMouseMove();
  result = this;
  *(_DWORD *)&this->_2[8] = 0;
  return result;
}