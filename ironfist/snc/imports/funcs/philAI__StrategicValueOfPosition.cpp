{
  int v8; // ST50_4@29
  int v9; // ebx@73
  int v10; // ecx@74
  int v11; // [sp+1Ch] [bp-64h]@1
  searchArray *v12; // [sp+2Ch] [bp-54h]@15
  int v13; // [sp+30h] [bp-50h]@66
  signed int v14; // [sp+34h] [bp-4Ch]@5
  mapCell *v15; // [sp+38h] [bp-48h]@5
  mapCell *v16; // [sp+38h] [bp-48h]@34
  int v17; // [sp+3Ch] [bp-44h]@70
  int v18; // [sp+40h] [bp-40h]@73
  searchArray *this; // [sp+44h] [bp-3Ch]@16
  signed int v20; // [sp+48h] [bp-38h]@49
  signed int i; // [sp+4Ch] [bp-34h]@70
  signed int v22; // [sp+54h] [bp-2Ch]@5
  signed int v23; // [sp+5Ch] [bp-24h]@5
  int v24; // [sp+5Ch] [bp-24h]@87
  int row; // [sp+60h] [bp-20h]@31
  int v26; // [sp+64h] [bp-1Ch]@52
  int col; // [sp+68h] [bp-18h]@29
  int a6; // [sp+6Ch] [bp-14h]@22
  signed int a5; // [sp+70h] [bp-10h]@27
  int v30; // [sp+78h] [bp-8h]@39

  v11 = a1;
  if ( !a7 && !a4 && *((_WORD *)gaiHeroStrategicRVOfPos + a2 + MAP_WIDTH * a2_4) != -32001 )
  {
    *arg10 = *((_WORD *)gaiLiveChanceOfPos + a2 + MAP_WIDTH * a2_4);
    return *((_WORD *)gaiHeroStrategicRVOfPos + a2 + MAP_WIDTH * a2_4);
  }
  v23 = 0;
  v22 = 0;
  v14 = 0;
  v15 = advManager::GetCell(gpAdvManager, a2, a2_4);
  if ( v15->objType == 163
    && gpGame->castles[(unsigned __int8)((unsigned __int8)(v15->flags >> 8) >> -5)].ownerIdx == giCurPlayer
    && gpGame->castles[(unsigned __int8)((unsigned __int8)(v15->flags >> 8) >> -5)].buildingsBuiltFlags & 0x40 )
    v14 = 1;
  *arg10 = 100;
  if ( argC && !*((_BYTE *)gaiEnemyHeroReachable + a2 + MAP_WIDTH * a2_4) )
  {
    if ( a4 )
      return 0;
    argC = 0;
  }
  if ( dword_51D768 )
  {
    v22 = 1;
    v12 = (searchArray *)operator new(9496);
    if ( v12 )
      this = searchArray::searchArray(v12);
    else
      this = 0;
    if ( !this )
      MemError();
    searchArray::Init(this);
  }
  else
  {
    dword_51D768 = 1;
    this = &SVSearchArray;
  }
  a6 = *(_DWORD *)&gpCurAIHero->flags1 & 0x80;
  if ( a6 && advManager::GetCell(gpAdvManager, a2, a2_4)->objType == 28 )
    a6 = 0;
  if ( a4 || argC )
    a5 = 1700;
  else
    a5 = 700;
  searchArray::SeedPosition(this, a2, a2_4, 2, a5, a6, 0, 59999, gpCurAIHero->secondarySkillLevel[0], -1i64, 0, 0);
  v8 = (int)(&this->field_2414[MAP_WIDTH * a2_4] + a2);
  *(_BYTE *)(v8 + 4) &= 0xFEu;
  for ( col = 0; MAP_WIDTH > col; ++col )
  {
    for ( row = 0; MAP_HEIGHT > row; ++row )
    {
      if ( *(&this->field_2414[col].field_4 + 9 * row * MAP_WIDTH) & 1 )
      {
        v16 = advManager::GetCell(gpAdvManager, col, row);
        if ( !a4
          && v16->objType & 0x80
          && *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH) <= 700
          || argC && v16->objType == 170 )
        {
          CheckDoMain(0, 0);
          v30 = (signed __int64)((double)(25
                                        * philAI::ValueOfEventAtPosition(
                                            (void *)v11,
                                            __PAIR__(row, col),
                                            0,
                                            (int)&unk_5305C8))
                               / ((double)*(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH)
                                + 50.0));
          if ( !v14 || v16->objType != 170 || v30 >= 0 )
            v23 += v30;
        }
        if ( v16->objType == 170 )
        {
          if ( gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)] == -32001 )
            philAI::ValueOfEventAtPosition((void *)v11, __PAIR__(row, col), 0, (int)&unk_5305C8);
          if ( gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)] != -32001
            && gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)] < 100
            && !v14 )
          {
            v20 = *(_DWORD *)&gpGame->heroes[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)].field_31;
            if ( gbHumanPlayer[gpGame->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)]] )
            {
              if ( a7 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH) > v20 )
              {
                v26 = (signed __int64)((double)(100
                                              - (signed int)gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)])
                                     * 0.2);
              }
              else if ( a7 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH) > 500 )
              {
                v26 = (100 - gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)])
                    * (v20 - (a7 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH)) + 250)
                    / v20;
              }
              else
              {
                v26 = 100 - gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)];
              }
            }
            else
            {
              v26 = (100 - gaiHeroLiveChance[(unsigned __int8)((unsigned __int8)(v16->flags >> 8) >> -5)])
                  * (v20 + 500 - (a7 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH)))
                  / (v20 + 500);
            }
            *arg10 = *arg10 * (100 - v26) / 100;
          }
        }
        if ( gpCurAIHero->couldBeHeroIdx != iAlphaMale && (a2 != col || a2_4 != row) )
        {
          if ( *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH) < 1024
            && advManager::GetCell(gpAdvManager, col, row)->objType == 170
            && (unsigned __int8)((unsigned __int8)(advManager::GetCell(gpAdvManager, col, row)->flags >> 8) >> -5) != gpCurAIHero->couldBeHeroIdx
            && gpGame->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(advManager::GetCell(
                                                                                        gpAdvManager,
                                                                                        col,
                                                                                        row)->flags >> 8) >> -5)] == gpCurAIHero->probablyOwnerIdx )
          {
            v13 = 600 * (1024 - *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * MAP_WIDTH)) >> 10;
            if ( v13 > 0 )
              v23 -= v13;
          }
        }
      }
    }
  }
  v17 = (unsigned __int8)giGroundToTerrain[advManager::GetCell(gpAdvManager, a2, a2_4)->tileType];
  for ( i = 0; gpCurPlayer->numHeroes > i; ++i )
  {
    if ( gpCurPlayer->heroesOwned[i] != gpCurAIHero->couldBeHeroIdx )
    {
      v9 = abs(*(_DWORD *)&gpGame->heroes[gpCurPlayer->heroesOwned[i]].field_25 - a2_4);
      v18 = abs(*(_DWORD *)&gpGame->heroes[gpCurPlayer->heroesOwned[i]].field_21 - a2) + v9;
      if ( v18 < 9 )
      {
        v10 = advManager::GetCell(
                gpAdvManager,
                *(_DWORD *)&gpGame->heroes[gpCurPlayer->heroesOwned[i]].field_21,
                *(_DWORD *)&gpGame->heroes[gpCurPlayer->heroesOwned[i]].field_25)->tileType;
        if ( v17 || (signed int)(unsigned __int8)giGroundToTerrain[v10] <= 0 )
        {
          if ( v17 <= 0 || giGroundToTerrain[v10] )
            v23 -= 600 * (9 - v18) / 9;
        }
      }
    }
  }
  if ( v22 )
  {
    if ( this )
    {
      searchArray::_searchArray(this);
      operator delete(this);
    }
  }
  else
  {
    dword_51D768 = 0;
  }
  if ( *arg10 < 100 )
    v23 -= 2500 * (100 - *arg10) / 100;
  v24 = (signed __int64)((double)v23 * 1.25);
  if ( v24 > 32000 )
    v24 = 32000;
  if ( !a4 && !a7 )
  {
    *((_WORD *)gaiHeroStrategicRVOfPos + a2 + MAP_WIDTH * a2_4) = v24;
    *((_WORD *)gaiLiveChanceOfPos + a2 + MAP_WIDTH * a2_4) = *arg10;
  }
  return v24;
}