{
  mapCell *v2; // ST28_4@33
  hero *thisa; // [sp+Ch] [bp-20h]@1
  int v4; // [sp+14h] [bp-18h]@37
  char *v5; // [sp+1Ch] [bp-10h]@3
  signed int v6; // [sp+20h] [bp-Ch]@23
  signed int idx; // [sp+24h] [bp-8h]@8
  int idxa; // [sp+24h] [bp-8h]@20
  signed int idxb; // [sp+24h] [bp-8h]@23
  int idxc; // [sp+24h] [bp-8h]@28
  int v11; // [sp+28h] [bp-4h]@3

  thisa = this;
  if ( a2 )
    SendMapChange(6, this->couldBeHeroIdx, this->x, this->y, -999, 0, 0);
  v11 = thisa->probablyOwnerIdx;
  v5 = (char *)&gpGame->players[thisa->probablyOwnerIdx];
  if ( a2 )
    advManager::MobilizeCurrHero(gpAdvManager, 0);
  if ( a2 )
    advManager::HideRoute(gpAdvManager, 0, 0, 0);
  if ( thisa->flags1 & 0x80 )
  {
    for ( idx = 0; idx < 48; ++idx )
    {
      if ( gpGame->probablyArtifactGeneratedRandomly[8 * idx + 109] == thisa->couldBeHeroIdx )
      {
        gpGame->probablyArtifactGeneratedRandomly[8 * idx + 109] = -1;
        gpGame->field_6236[idx + 231] = -1;
      }
    }
  }
  if ( thisa->occupiedObjType == 163 )
    gpGame->castles[thisa->occupiedObjVal].visitingHeroIdx = -1;
  if ( thisa->probablyOwnerIdx != giCurPlayer
    || gpGame->players[thisa->probablyOwnerIdx].curHeroIdx != thisa->couldBeHeroIdx
    || !gpAdvManager->field_2A6 )
    game::RestoreCell(thisa->x, thisa->y, thisa->occupiedObjType, thisa->occupiedObjVal, 0, 1);
  if ( !gbCombatSurrender )
  {
    for ( idxa = 0; idxa < 5; ++idxa )
      armyGroup::Dismiss(&thisa->army, idxa);
  }
  v6 = -1;
  for ( idxb = 0; v5[1] > idxb; ++idxb )
  {
    if ( v5[idxb + 4] == thisa->couldBeHeroIdx )
      v6 = idxb;
  }
  for ( idxc = v6; v5[1] - 1 > idxc; ++idxc )
    v5[idxc + 4] = v5[idxc + 5];
  v5[v5[1] + 3] = -1;
  if ( v5[2] == thisa->couldBeHeroIdx )
  {
    v5[2] = -1;
    if ( thisa->probablyOwnerIdx == giCurPlayer )
    {
      gpAdvManager->field_272 = 0;
      v2 = &gpGame->map.tiles[thisa->x] + thisa->y * gpGame->map.width;
      v2->field_8 &= 0xBFu;
    }
    if ( giCurPlayer == v11 )
      gpAdvManager->field_2A6 = 0;
  }
  --v5[1];
  v5[3] = 0;
  gpGame->relatedToHeroForHireStatus[thisa->couldBeHeroIdx] = -1;
  if ( gbRetreatWin )
  {
    v4 = Random(0, 1);
    if ( gpGame->heroes[gpGame->players[thisa->probablyOwnerIdx].heroesForPurchase[v4]].flags3 & 1 )
      v4 = 1 - v4;
    if ( gpGame->relatedToHeroForHireStatus[gpGame->players[thisa->probablyOwnerIdx].heroesForPurchase[v4]] == 64 )
      gpGame->relatedToHeroForHireStatus[gpGame->players[thisa->probablyOwnerIdx].heroesForPurchase[v4]] = -1;
    gpGame->players[thisa->probablyOwnerIdx].heroesForPurchase[v4] = thisa->couldBeHeroIdx;
    gpGame->relatedToHeroForHireStatus[thisa->couldBeHeroIdx] = 64;
    *(_DWORD *)&thisa->flags1 |= 0x10000u;
  }
  *(_DWORD *)&thisa->flags1 &= 0xFFFF7FFFu;
  thisa->probablyOwnerIdx = -1;
  *(_DWORD *)&thisa->field_25 = -1;
  *(_DWORD *)&thisa->field_21 = *(_DWORD *)&thisa->field_25;
  if ( !gbCombatSurrender )
    game::SetRandomHeroArmies(gpGame, thisa->couldBeHeroIdx, 0);
  if ( gbInCampaign
    && thisa->heroID == 55
    && !gpGame->field_2
    && gpGame->field_4 == 8
    && !gbRetreatWin
    && !gbCombatSurrender )
    gpGame->_1[125] = 1;
  if ( a2 )
    CheckEndGame(0, 0);
}