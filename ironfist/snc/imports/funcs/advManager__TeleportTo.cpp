{
  int v6; // ebx@18
  signed int v7; // eax@18
  mapCell *v10; // [sp+18h] [bp-18h]@3
  mapCell *v11; // [sp+1Ch] [bp-14h]@3
  signed int v12; // [sp+20h] [bp-10h]@5
  int v13; // [sp+24h] [bp-Ch]@1
  int v14; // [sp+2Ch] [bp-4h]@26

  v13 = bShowIt;
  if ( !a6 )
    SendMapChange(9, a2->couldBeHeroIdx, col, a4, -999, 0, 0);
  v10 = advManager::GetCell(this, col, a4);
  v11 = advManager::GetCell(this, a2->x, a2->y);
  if ( a2->occupiedObjType == 163 )
    gpGame->castles[a2->occupiedObjVal].visitingHeroIdx = -1;
  v12 = 0;
  if ( v11->field_8 & 0x40 )
  {
    v11->field_8 -= 64;
    v12 = 1;
  }
  else
  {
    game::RestoreCell(a2->x, a2->y, a2->occupiedObjType, a2->occupiedObjVal, 0, 99);
  }
  advManager::CompleteDraw(this, 0);
  if ( !*(&gbThisNetHumanPlayer + giCurPlayer) )
    bShowIt = !*(_DWORD *)&blackoutComputer && MapExtraPosAndAdjacentsSet(a2->x, a2->y, giCurWatchPlayerBit)
           || MapExtraPosAndAdjacentsSet(col, a4, giCurWatchPlayerBit);
  if ( v13 )
    advManager::HideRoute(this, 1, 1, 1);
  if ( bShowIt )
  {
    this->viewX = col - 7;
    this->viewY = a4 - 7;
    DelayMilli(90);
  }
  a2->x = col;
  a2->y = a4;
  v6 = giVisRange[a2->secondarySkillLevel[3]];
  v7 = hero::HasArtifact(a2, ARTIFACT_TELESCOPE);
  game::SetVisibility(this->viewX + 7, this->viewY + 7, giCurPlayer, ((unsigned int)v7 >= 1) + v6);
  if ( bShowIt )
  {
    v10->field_8 |= 0x40u;
    heroWindowManager::SaveFizzleSource(gpWindowManager, 16, 16, 448, 448);
    advManager::CompleteDraw(this, 0);
    PollSound();
    heroWindowManager::FizzleForward(gpWindowManager, 16, 16, 448, 448, -1, 0, 0);
    PollSound();
  }
  else
  {
    a2->occupiedObjType = v10->objType;
    a2->occupiedObjVal = (unsigned __int8)((unsigned __int8)(v10->flags >> 8) >> -5);
    if ( v12 )
    {
      v10->field_8 |= 0x40u;
    }
    else
    {
      v10->objType = -86;
      v10->flags = v10->flags & 7 | 8 * a2->couldBeHeroIdx;
    }
    if ( this->field_27A == 6 )
      *(_DWORD *)&a2->flags1 |= 0x80u;
    this->field_272 = 0;
  }
  advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
  v14 = (unsigned __int8)giGroundToTerrain[v10->tileType];
  if ( this->currentTerrain != v14 )
  {
    this->currentTerrain = v14;
    soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
  }
  advManager::Reseed(0, 0);
  advManager::UpdateRadar((int)this, 1, 0);
  advManager::CompleteDraw(this, 0);
  return advManager::ForceNewHover(this);
}