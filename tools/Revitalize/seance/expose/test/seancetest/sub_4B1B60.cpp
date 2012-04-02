signed int __stdcall sub_4B1B60(__int64 a1, int a2, int a3, int a4, int a5)
{
  PathfindingInfo *v6; // ST50_4@29
  int v7; // ebx@72
  int v8; // ecx@73
  Pathfinder *v9; // [sp+2Ch] [bp-54h]@15
  int v10; // [sp+30h] [bp-50h]@65
  signed int v11; // [sp+34h] [bp-4Ch]@5
  int v12; // [sp+38h] [bp-48h]@5
  int v13; // [sp+38h] [bp-48h]@34
  int v14; // [sp+3Ch] [bp-44h]@69
  int v15; // [sp+40h] [bp-40h]@72
  Pathfinder *this; // [sp+44h] [bp-3Ch]@16
  signed int v17; // [sp+48h] [bp-38h]@49
  signed int i; // [sp+4Ch] [bp-34h]@69
  signed int v19; // [sp+54h] [bp-2Ch]@5
  signed int v20; // [sp+5Ch] [bp-24h]@5
  signed int v21; // [sp+5Ch] [bp-24h]@86
  int row; // [sp+60h] [bp-20h]@31
  int v23; // [sp+64h] [bp-1Ch]@52
  int col; // [sp+68h] [bp-18h]@29
  int a6; // [sp+6Ch] [bp-14h]@22
  signed int a5a; // [sp+70h] [bp-10h]@27
  int v27; // [sp+78h] [bp-8h]@39

  if ( !a5 && !a2 && *((_WORD *)dword_51D5A0 + a1 + mapWidth * HIDWORD(a1)) != -32001 )
  {
    *(_DWORD *)a4 = *((_WORD *)dword_51D59C + a1 + mapWidth * HIDWORD(a1));
    return *((_WORD *)dword_51D5A0 + a1 + mapWidth * HIDWORD(a1));
  }
  v20 = 0;
  v19 = 0;
  v11 = 0;
  v12 = usedToCheckForBoatByCastle(advManager, a1, SHIDWORD(a1));
  if ( *(_BYTE *)(v12 + 9) == 163
    && gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v12 + 4) >> 8) >> -5)].ownerIdx == curPlayerIdx
    && gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v12 + 4) >> 8) >> -5)].buildingsBuiltFlags & 0x40 )
    v11 = 1;
  *(_DWORD *)a4 = 100;
  if ( a3 && !*((_BYTE *)dword_51D5AC + a1 + mapWidth * HIDWORD(a1)) )
  {
    if ( a2 )
      return 0;
    a3 = 0;
  }
  if ( dword_51D768 )
  {
    v19 = 1;
    v9 = (Pathfinder *)operator new(0x2518u);
    if ( v9 )
      this = Pathfinder_constructor(v9);
    else
      this = 0;
    if ( !this )
      fatalOutOfMemoryError();
    Pathfinder::resetSomething(this);
  }
  else
  {
    dword_51D768 = 1;
    this = &aiPathfinder;
  }
  a6 = *(_DWORD *)&dword_51D5BC->flags1 & 0x80;
  if ( a6 && *(_BYTE *)(usedToCheckForBoatByCastle(advManager, a1, SHIDWORD(a1)) + 9) == 28 )
    a6 = 0;
  if ( a2 || a3 )
    a5a = 1700;
  else
    a5a = 700;
  Pathfinder::doSomething2(
    this,
    a1,
    SHIDWORD(a1),
    2,
    a5a,
    a6,
    0,
    59999,
    dword_51D5BC->secondarySkillLevel[0],
    -1i64,
    0,
    0);
  v6 = &this->field_2414[mapWidth * HIDWORD(a1)] + a1;
  v6->field_4 &= 0xFEu;
  for ( col = 0; mapWidth > col; ++col )
  {
    for ( row = 0; mapHeight > row; ++row )
    {
      if ( *(&this->field_2414[col].field_4 + 9 * row * mapWidth) & 1 )
      {
        v13 = usedToCheckForBoatByCastle(advManager, col, row);
        if ( !a2
          && *(_BYTE *)(v13 + 9) & 0x80
          && *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth) <= 700
          || a3 && *(_BYTE *)(v13 + 9) == 170 )
        {
          sub_4AA7B0(0, 0);
          v27 = (signed __int64)((double)(25 * aiHandleObject(__PAIR__(row, col), 0, (int)&unk_5305C8))
                               / ((double)*(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth)
                                + 50.0));
          if ( !v11 || *(_BYTE *)(v13 + 9) != 170 || v27 >= 0 )
            v20 += v27;
        }
        if ( *(_BYTE *)(v13 + 9) == 170 )
        {
          if ( word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)] == -32001 )
            aiHandleObject(__PAIR__(row, col), 0, (int)&unk_5305C8);
          if ( word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)] != -32001
            && word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)] < 100
            && !v11 )
          {
            v17 = *(_DWORD *)&gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)]._4[16];
            if ( dword_524810[gameObject->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)]] )
            {
              if ( a5 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth) > v17 )
              {
                v23 = (signed __int64)((double)(100
                                              - (signed int)word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)])
                                     * 0.2);
              }
              else
              {
                if ( a5 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth) > 500 )
                  v23 = (100 - word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)])
                      * (v17 - (a5 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth)) + 250)
                      / v17;
                else
                  v23 = 100 - word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)];
              }
            }
            else
            {
              v23 = (100 - word_532C60[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v13 + 4) >> 8) >> -5)])
                  * (v17 + 500 - (a5 + *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth)))
                  / (v17 + 500);
            }
            *(_DWORD *)a4 = *(_DWORD *)a4 * (100 - v23) / 100;
          }
        }
        if ( dword_51D5BC->field_2 != dword_530734
          && a1 != __PAIR__(row, col)
          && *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth) < 1024
          && *(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) == 170
          && (unsigned __int8)((unsigned __int8)(*(_WORD *)(usedToCheckForBoatByCastle(advManager, col, row) + 4) >> 8) >> -5) != dword_51D5BC->field_2
          && gameObject->relatedToHeroForHireStatus[(unsigned __int8)((unsigned __int8)(*(_WORD *)(usedToCheckForBoatByCastle(
                                                                                                     advManager,
                                                                                                     col,
                                                                                                     row)
                                                                                                 + 4) >> 8) >> -5)] == dword_51D5BC->probablyOwnerIdx )
        {
          v10 = 600 * (1024 - *(__int16 *)((char *)&this->field_2414[col].field_2 + 9 * row * mapWidth)) >> 10;
          if ( v10 > 0 )
            v20 -= v10;
        }
      }
    }
  }
  v14 = (unsigned __int8)tileToTerrainType[*(_WORD *)usedToCheckForBoatByCastle(advManager, a1, SHIDWORD(a1))];
  for ( i = 0; curPlayer->numHeroes > i; ++i )
  {
    if ( curPlayer->heroesOwned[i] != dword_51D5BC->field_2 )
    {
      v7 = abs(*(_DWORD *)&gameObject->heroes[curPlayer->heroesOwned[i]]._4[4] - HIDWORD(a1));
      v15 = abs(*(_DWORD *)&gameObject->heroes[curPlayer->heroesOwned[i]]._4[0] - a1) + v7;
      if ( v15 < 9 )
      {
        v8 = *(_WORD *)usedToCheckForBoatByCastle(
                         advManager,
                         *(_DWORD *)&gameObject->heroes[curPlayer->heroesOwned[i]]._4[0],
                         *(_DWORD *)&gameObject->heroes[curPlayer->heroesOwned[i]]._4[4]);
        if ( v14 || (signed int)(unsigned __int8)tileToTerrainType[v8] <= 0 )
        {
          if ( v14 <= 0 || tileToTerrainType[v8] )
            v20 -= 600 * (9 - v15) / 9;
        }
      }
    }
  }
  if ( v19 )
  {
    if ( this )
    {
      Pathfinder::cleanUp(this);
      operator delete(this);
    }
  }
  else
  {
    dword_51D768 = 0;
  }
  if ( *(_DWORD *)a4 < 100 )
    v20 -= 2500 * (100 - *(_DWORD *)a4) / 100;
  v21 = (signed __int64)((double)v20 * 1.25);
  if ( v21 > 32000 )
    v21 = 32000;
  if ( !a2 && !a5 )
  {
    *((_WORD *)dword_51D5A0 + a1 + mapWidth * HIDWORD(a1)) = v21;
    *((_WORD *)dword_51D59C + a1 + mapWidth * HIDWORD(a1)) = *(_DWORD *)a4;
  }
  return v21;
}
