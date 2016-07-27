{
  MapTile *v2; // ST28_4@33
  Hero *thisa; // [sp+Ch] [bp-20h]@1
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
    sub_4C3190(6, this->field_2, this->x, this->y, -999, 0, 0);
  v11 = thisa->probablyOwnerIdx;
  v5 = (char *)&gameObject->players[thisa->probablyOwnerIdx];
  if ( a2 )
    sub_450820((int)advManager, 0);
  if ( a2 )
    sub_455030(advManager, 0, 0, 0);
  if ( thisa->flags1 & 0x80 )
  {
    for ( idx = 0; idx < 48; ++idx )
    {
      if ( gameObject->probablyArtifactGeneratedRandomly[8 * idx + 109] == thisa->field_2 )
      {
        gameObject->probablyArtifactGeneratedRandomly[8 * idx + 109] = -1;
        gameObject->field_6236[idx + 231] = -1;
      }
    }
  }
  if ( *(_WORD *)&thisa->_4[12] == 163 )
    gameObject->castles[*(_WORD *)&thisa->_4[14]].visitingHeroIdx = -1;
  if ( thisa->probablyOwnerIdx != curPlayerIdx
    || gameObject->players[thisa->probablyOwnerIdx]._1[0] != thisa->field_2
    || !advManager->field_2A6 )
    sub_42CC90(thisa->x, thisa->y, *(_WORD *)&thisa->_4[12], *(_WORD *)&thisa->_4[14], 0, 1);
  if ( !isSurrendering )
  {
    for ( idxa = 0; idxa < 5; ++idxa )
      ArmyInfo::deleteStack(&thisa->army, idxa);
  }
  v6 = -1;
  for ( idxb = 0; v5[1] > idxb; ++idxb )
  {
    if ( v5[idxb + 4] == thisa->field_2 )
      v6 = idxb;
  }
  for ( idxc = v6; v5[1] - 1 > idxc; ++idxc )
    v5[idxc + 4] = v5[idxc + 5];
  v5[v5[1] + 3] = -1;
  if ( v5[2] == thisa->field_2 )
  {
    v5[2] = -1;
    if ( thisa->probablyOwnerIdx == curPlayerIdx )
    {
      advManager->field_272 = 0;
      v2 = &gameObject->map.tiles[thisa->x] + thisa->y * gameObject->map.width;
      v2->field_8 &= 0xBFu;
    }
    if ( curPlayerIdx == v11 )
      advManager->field_2A6 = 0;
  }
  --v5[1];
  v5[3] = 0;
  gameObject->relatedToHeroForHireStatus[thisa->field_2] = -1;
  if ( isRetreating )
  {
    v4 = unseededNextRand(0, 1);
    if ( gameObject->heroes[gameObject->players[thisa->probablyOwnerIdx].heroesForPurchase[v4]].flags3 & 1 )
      v4 = 1 - v4;
    if ( gameObject->relatedToHeroForHireStatus[gameObject->players[thisa->probablyOwnerIdx].heroesForPurchase[v4]] == 64 )
      gameObject->relatedToHeroForHireStatus[gameObject->players[thisa->probablyOwnerIdx].heroesForPurchase[v4]] = -1;
    gameObject->players[thisa->probablyOwnerIdx].heroesForPurchase[v4] = thisa->field_2;
    gameObject->relatedToHeroForHireStatus[thisa->field_2] = 64;
    *(_DWORD *)&thisa->flags1 |= 0x10000u;
  }
  *(_DWORD *)&thisa->flags1 &= 0xFFFF7FFFu;
  thisa->probablyOwnerIdx = -1;
  *(_DWORD *)&thisa->_4[4] = -1;
  *(_DWORD *)&thisa->_4[0] = *(_DWORD *)&thisa->_4[4];
  if ( !isSurrendering )
    sub_4281E0(gameObject, thisa->field_2, 0);
  if ( loadOrNewGameSelected
    && thisa->heroID == 55
    && !gameObject->field_2
    && gameObject->field_4 == 8
    && !isRetreating
    && !isSurrendering )
    gameObject->_1[125] = 1;
  if ( a2 )
    checkGameEnd(0, 0);
}
