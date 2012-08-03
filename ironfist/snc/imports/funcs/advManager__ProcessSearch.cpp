{
  unsigned __int16 v3; // ax@21
  unsigned __int16 v4; // ax@21
  char v6; // [sp+1Ch] [bp-34h]@29
  mapCell *v7; // [sp+3Ch] [bp-14h]@9
  int i; // [sp+40h] [bp-10h]@48
  sample_resource res; // [sp+44h] [bp-Ch]@1
  char *hro; // [sp+4Ch] [bp-4h]@1

  res = NULL_SAMPLE2;
  hro = (char *)&gpGame->heroes[gpCurPlayer->curHeroIdx];
  if ( *(_DWORD *)&gpGame->heroes[gpCurPlayer->curHeroIdx].field_35 != *(_DWORD *)&gpGame->heroes[gpCurPlayer->curHeroIdx].field_31 )
  {
    if ( gbHumanPlayer[giCurPlayer] )
    {
      NormalDialog("Digging for artifacts requires a whole day, try again tomorrow.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      return 1;
    }
LABEL_52:
    gpCurPlayer->field_40 = 0;
    return 1;
  }
  if ( hero::NumArtifacts((hero *)hro) == 14 )
  {
    if ( gbHumanPlayer[giCurPlayer] )
    {
      NormalDialog(
        "Searching for the Ultimate Artifact is fruitless.  Your hero could not carry it even if he found it - all his artifact slots are full.",
        1,
        -1,
        -1,
        -1,
        0,
        -1,
        0,
        -1,
        0);
      return 1;
    }
    goto LABEL_52;
  }
  advManager::MobilizeCurrHero(this, 0);
  advManager::CompleteDraw(this, 0);
  advManager::UpdateScreen(this, 0, 0);
  if ( (_DWORD)a2 == -1 )
  {
    LODWORD(a2) = this->viewX + 7;
    HIDWORD(a2) = this->viewY + 7;
  }
  v7 = advManager::GetCell(this, a2, SHIDWORD(a2));
  if ( HIBYTE(v7->field_2) != 255 && ((LOBYTE(v7->field_2) >> 2) & 0x3F) != 47 || v7->field_7 != 255 )
  {
    if ( gbHumanPlayer[giCurPlayer] )
    {
      NormalDialog("Try searching on clear ground.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      return 1;
    }
    goto LABEL_52;
  }
  if ( !giGroundToTerrain[v7->tileType] )
  {
    if ( gbHumanPlayer[giCurPlayer] )
    {
      NormalDialog("Try looking on land!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      return 1;
    }
    goto LABEL_52;
  }
  if ( gbHumanPlayer[giCurPlayer] )
    res = LoadPlaySample("DIGSOUND.82M");
  if ( HIBYTE(v7->field_2) == 255 || ((LOBYTE(v7->field_2) >> 2) & 0x3F) == 47 )
  {
    LOBYTE(v7->field_2) = v7->field_2 & 3 | 0xE0;
    HIBYTE(v7->field_2) = -116;
    v3 = v7->flags;
    LOBYTE(v3) = v3 | 1;
    v7->flags = v3;
    v4 = v7->flags;
    LOBYTE(v4) = v4 | 2;
    v7->flags = v4;
    v7->field_8 |= 0x80u;
  }
  advManager::CompleteDraw(this, 0);
  advManager::UpdateScreen(this, 0, 0);
  if ( gpGame->_10[24] != (_DWORD)a2 || gpGame->_10[25] != HIDWORD(a2) || gpGame->_10[26] == -1 )
  {
    if ( gbHumanPlayer[giCurPlayer] )
      NormalDialog("Nothing here.\nWhere could it be?", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  else if ( hero::NumArtifacts((hero *)hro) < 14 )
  {
    v6 = 0;
    if ( xIsPlayingExpansionCampaign )
      v6 = ExpCampaign::IsSpecialUA((int)&xCampaign);
    if ( gbHumanPlayer[giCurPlayer] )
    {
      soundManager::SwitchAmbientMusic(gpSoundManager, 41);
      if ( v6 )
        sprintf(
          gText,
          "%s%s",
          "Congratulations! After spending many hours digging here, you have uncovered the ",
          gArtifactNames[98]);
      else
        sprintf(
          gText,
          "%s%s",
          "Congratulations! After spending many hours digging here, you have uncovered the ",
          gArtifactNames[gpGame->_10[26]]);
      NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( v6 )
        hero::ViewArtifact(ARTIFACT_SPHERE_OF_NEGATION, 0, -1);
      else
        hero::ViewArtifact((ARTIFACT)gpGame->_10[26], 0, -1);
      soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
    }
    if ( v6 )
      GiveArtifact((hero *)hro, ARTIFACT_SPHERE_OF_NEGATION, 1, -1);
    else
      GiveArtifact((hero *)hro, (ARTIFACT)gpGame->_10[26], 1, -1);
    gpGame->_10[26] = -1;
  }
  else if ( gbHumanPlayer[giCurPlayer] )
  {
    NormalDialog("You have no room to carry another artifact!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  if ( gbHumanPlayer[giCurPlayer] )
    WaitEndSample(-1, res);
  for ( i = 0; gpGame->numPlayers > i; ++i )
    ComputeUALoc(i);
  *(_DWORD *)(hro + 53) = 0;
  advManager::UpdBottomView(this, 1, 1, 1);
  advManager::CheckDimHero(this);
  advManager::Reseed(0, 0);
  CheckEndGame(0, 0);
  return 1;
}