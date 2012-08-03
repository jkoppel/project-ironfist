{
  mapCell *v4; // [sp+10h] [bp-10h]@5
  int v5; // [sp+14h] [bp-Ch]@5
  int v6; // [sp+14h] [bp-Ch]@18
  signed int i; // [sp+18h] [bp-8h]@5
  hero *v8; // [sp+1Ch] [bp-4h]@2

  if ( a2 != -1 )
  {
    advManager::DeactivateCurrTown();
    advManager::HideRoute(this, 0, 0, 1);
    advManager::DeactivateCurrHero(this);
    this->field_2A6 = 1;
    gpCurPlayer->curHeroIdx = a2;
    v8 = &gpGame->heroes[gpCurPlayer->curHeroIdx];
    this->viewX = gpGame->heroes[gpCurPlayer->curHeroIdx].x - 7;
    this->viewY = v8->y - 7;
    *(_DWORD *)&this->field_292[8] = 7;
    *(_DWORD *)&this->field_292[0] = *(_DWORD *)&this->field_292[8];
    *(_DWORD *)&this->field_292[12] = -1;
    *(_DWORD *)&this->field_292[4] = *(_DWORD *)&this->field_292[12];
    if ( v8->flags1 & HERO_AT_SEA )
      this->field_27A = 6;
    else
      this->field_27A = v8->factionID;
    this->field_27E = HIBYTE(v8->field_2B);
    this->field_282 = advManager::GetCursorBaseFrame(this->field_27E);
    v4 = advManager::GetCell(this, v8->x, v8->y);
    v4->field_8 |= 0x40u;
    game::RestoreCell(v8->x, v8->y, v8->occupiedObjType, v8->occupiedObjVal, 0, 4);
    v5 = 0;
    for ( i = 0; gpCurPlayer->numHeroes > i; ++i )
    {
      if ( gpCurPlayer->heroesOwned[i] == a2 )
        v5 = i;
    }
    if ( gpCurPlayer->field_3 <= v5 )
    {
      if ( gpCurPlayer->field_3 + 3 < v5 )
        gpCurPlayer->field_3 = v5 - 3;
    }
    else
    {
      gpCurPlayer->field_3 = v5;
    }
    advManager::UpdateHeroLocators(this, 1, 1);
    advManager::UpdateTownLocators(this, 1, 1);
    if ( !a3 && (this->ready == 1 || *(&gbThisNetHumanPlayer + giCurPlayer)) )
    {
      advManager::Reseed(0, 0);
      advManager::SeedTo((int)this, *(_QWORD *)&v8->field_21);
      advManager::ShowRoute(this, 0, 0, 1);
    }
    advManager::UpdBottomView(this, 1, 1, 1);
    this->field_272 = 1;
    advManager::UpdateRadar((int)this, 1, 0);
    advManager::CompleteDraw(this, this->viewX, this->viewY, 0, 1);
    advManager::UpdateScreen(this, 0, 0);
    advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
    v6 = (unsigned __int8)giGroundToTerrain[v4->tileType];
    if ( this->currentTerrain != v6 )
    {
      this->currentTerrain = v6;
      soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
    }
    if ( !gbHeroMoving )
    {
      inputManager::ForceMouseMove();
      *(_DWORD *)&this->_2[8] = 0;
    }
  }
}