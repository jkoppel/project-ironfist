{
  signed int result; // eax@2
  PathfindingInfo *v6; // ST68_4@22
  int v7; // ebx@46
  int v8; // ebx@88
  int v9; // ST80_4@102
  int v10; // ebx@113
  int v11; // ebx@113
  int v12; // esi@113
  void *v13; // [sp+2Ch] [bp-70h]@1
  int v14; // [sp+40h] [bp-5Ch]@3
  mapCell *v15; // [sp+44h] [bp-58h]@63
  signed int v16; // [sp+48h] [bp-54h]@22
  int v17; // [sp+4Ch] [bp-50h]@3
  int v18; // [sp+50h] [bp-4Ch]@98
  int v19; // [sp+54h] [bp-48h]@1
  int v20; // [sp+58h] [bp-44h]@88
  int j; // [sp+5Ch] [bp-40h]@91
  int i; // [sp+60h] [bp-3Ch]@30
  int row; // [sp+64h] [bp-38h]@39
  int v24; // [sp+68h] [bp-34h]@3
  int v25; // [sp+6Ch] [bp-30h]@100
  int col; // [sp+70h] [bp-2Ch]@35
  int v27; // [sp+74h] [bp-28h]@3
  int v28; // [sp+78h] [bp-24h]@28
  int v29; // [sp+7Ch] [bp-20h]@20
  int v30; // [sp+80h] [bp-1Ch]@26
  int v31; // [sp+84h] [bp-18h]@24
  bool v32; // [sp+88h] [bp-14h]@65
  int v33; // [sp+8Ch] [bp-10h]@37
  signed int a5a; // [sp+90h] [bp-Ch]@22
  int v35; // [sp+94h] [bp-8h]@46
  int v36; // [sp+98h] [bp-4h]@22

  v13 = this;
  if ( philAI::GoodAdjacent(this, (int)&v19) )
  {
    *a2 = gpCurAIHero->x + normalDirTable[4 * v19];
    *a3 = gpCurAIHero->y + byte_4F1DC1[4 * v19];
    *(_DWORD *)a5 = v19;
    result = 1000;
  }
  else
  {
    *(_DWORD *)a5 = -1;
    v27 = -1;
    v24 = -1;
    v14 = -999999;
    dword_5305CC = -1;
    dword_5306E0 = 0;
    dword_532CE8 = 0;
    dword_532CEC = 0;
    v17 = (unsigned __int8)giGroundToTerrain[advManager::GetCell(gpAdvManager, gpCurAIHero->x, gpCurAIHero->y)->tileType];
    if ( gpCurAIHero->secondarySkillLevel[0] > 1 )
    {
      switch ( gpGame->_1[682] )
      {
        case 0x24:
          a4 = (signed __int64)((double)a4 * 0.9);
          break;
        case 0x6C:
          a4 = (signed __int64)((double)a4 * 1.05);
          break;
        case 0x90:
          a4 = (signed __int64)((double)a4 * 1.1);
          break;
      }
    }
    else
    {
      if ( v17 == 2 || v17 == 3 )
        a4 = (signed __int64)((double)a4 * 1.15);
      if ( v17 == 5 )
        a4 = (signed __int64)((double)a4 * 1.35);
      if ( v17 == 7 )
        a4 = (signed __int64)((double)a4 * 1.25);
    }
    if ( gpCurPlayer->personality == 2 )
      a4 = (signed __int64)((double)a4 * 1.15);
    v29 = a4 / 100 / 4;
    if ( v29 < 6 )
      v29 = 6;
    a5a = 2 * a4;
    searchArray::SeedPosition(
      gpSearchArray,
      gpCurAIHero->x,
      gpCurAIHero->y,
      HIBYTE(gpCurAIHero->field_2B),
      2 * a4,
      *(_DWORD *)&gpCurAIHero->flags1 & 0x80,
      1,
      *(_DWORD *)&gpCurAIHero->field_35,
      gpCurAIHero->secondarySkillLevel[0],
      -1i64,
      0,
      0);
    v6 = &gpSearchArray->field_2414[gpCurAIHero->x] + MAP_WIDTH * gpCurAIHero->y;
    v6->field_4 &= 0xFEu;
    v16 = -1;
    v36 = gpCurAIHero->x - 25;
    if ( v36 < 0 )
      v36 = 0;
    v31 = gpCurAIHero->y - 25;
    if ( v31 < 0 )
      v31 = 0;
    v30 = gpCurAIHero->x + 25;
    if ( MAP_WIDTH - 1 < v30 )
      v30 = MAP_WIDTH;
    v28 = gpCurAIHero->y + 25;
    if ( MAP_HEIGHT - 1 < v28 )
      v28 = MAP_HEIGHT;
    for ( i = 0; ; ++i )
    {
      if ( i < 2 )
      {
        if ( gpCurAIHero->flags1 & 0x80 && !i )
          continue;
        for ( col = v36; col < v30; ++col )
        {
          v33 = -1;
          ++v16;
          if ( v29 <= v16 )
            v16 = 0;
          for ( row = v31; row < v28; ++row )
          {
            ++v33;
            if ( v29 <= v33 )
              v33 = 0;
            if ( *(&gpSearchArray->field_2414[col].field_4 + 9 * row * MAP_WIDTH) & 1 )
            {
              if ( gpCurAIHero->flags1 & 0x80
                || ((v7 = abs(col - gpCurAIHero->x), v35 = abs(row - gpCurAIHero->y) + v7, i)
                 || v35 <= 5
                 || *(_DWORD *)&gpCurAIHero->field_21 == col && *(_DWORD *)&gpCurAIHero->field_25 == row
                 || v35 < 16
                 && (advManager::GetCell(gpAdvManager, col, row)->objType == 170
                  || advManager::GetCell(gpAdvManager, col, row)->objType == 163
                  && gpGame->castles[(unsigned __int8)((unsigned __int8)(advManager::GetCell(gpAdvManager, col, row)->flags >> 8) >> -5)].ownerIdx != giCurPlayer))
                && (i != 1
                 || v35 > 5
                 && (*(_DWORD *)&gpCurAIHero->field_21 != col || *(_DWORD *)&gpCurAIHero->field_25 != row)
                 && (v35 >= 16
                  || advManager::GetCell(gpAdvManager, col, row)->objType != 170
                  && (advManager::GetCell(gpAdvManager, col, row)->objType != 163
                   || gpGame->castles[(unsigned __int8)((unsigned __int8)(advManager::GetCell(gpAdvManager, col, row)->flags >> 8) >> -5)].ownerIdx == giCurPlayer))) )
              {
                v15 = advManager::GetCell(gpAdvManager, col, row);
                if ( *(__int16 *)((char *)&gpSearchArray->field_2414[col].field_2 + 9 * row * MAP_WIDTH) <= a4 )
                {
                  v32 = v15->objType & 0x80
                     || v15->objType == 28 && gpCurAIHero->flags1 & 0x80
                     || !(col % v29)
                     && !(row % v29)
                     && (gpCurAIHero->flags1 & 0x80 && !giGroundToTerrain[v15->tileType]
                      || !(gpCurAIHero->flags1 & 0x80) && giGroundToTerrain[v15->tileType])
                     || LOBYTE(gpCurPlayer->field_41) == col && HIBYTE(gpCurPlayer->field_41) == row;
                }
                else if ( *(__int16 *)((char *)&gpSearchArray->field_2414[col].field_2 + 9 * row * MAP_WIDTH) <= a5a )
                {
                  v32 = v15->objType == 163
                     || v15->objType == 170
                     || v15->objType == 171 && !(gpCurAIHero->flags1 & 0x80);
                }
                else
                {
                  v32 = 0;
                }
                if ( v32 )
                {
                  if ( LOBYTE(gpCurAIHero->field_29) != 255 )
                  {
                    v8 = abs(row - HIBYTE(gpCurAIHero->field_29));
                    v20 = abs(col - LOBYTE(gpCurAIHero->field_29)) + v8;
                    if ( SLOBYTE(gpCurAIHero->field_2B) < v20 )
                      v32 = 0;
                  }
                }
                if ( v32 )
                {
                  for ( j = 0; gpCurPlayer->numHeroes > j; ++j )
                  {
                    if ( v15->objType != 163
                      && v15->objType != 170
                      && gpCurPlayer->heroesOwned[j] != gpCurAIHero->couldBeHeroIdx
                      && *(_DWORD *)&gpGame->heroes[gpCurPlayer->heroesOwned[j]].field_21 == col
                      && *(_DWORD *)&gpGame->heroes[gpCurPlayer->heroesOwned[j]].field_25 == row )
                    {
                      v18 = -2000;
                      goto LABEL_107;
                    }
                  }
                  CheckDoMain(0, 0);
                  v25 = *(_DWORD *)&gpCurAIHero->field_31
                      - *(__int16 *)((char *)&gpSearchArray->field_2414[col].field_2 + 9 * row * MAP_WIDTH);
                  if ( v25 < 0 )
                    v25 = 0;
                  v9 = philAI::RVOfPosition(
                         (int)v13,
                         col,
                         row,
                         ((unsigned __int8)*(&gpSearchArray->field_2414[col].field_4 + 9 * row * MAP_WIDTH) >> 2) & 1,
                         *((_BYTE *)&gpSearchArray->field_2414[col].field_5 + 9 * row * MAP_WIDTH),
                         *((_BYTE *)&gpSearchArray->field_2414[col].field_5 + 9 * row * MAP_WIDTH + 1),
                         ((unsigned __int8)*(&gpSearchArray->field_2414[col].field_4 + 9 * row * MAP_WIDTH) >> 3) & 1,
                         *((_BYTE *)&gpSearchArray->field_2414[col].field_5 + 9 * row * MAP_WIDTH + 2),
                         *((_BYTE *)&gpSearchArray->field_2414[col].field_5 + 9 * row * MAP_WIDTH + 3),
                         2);
                  v18 = v9 * (Random(1, 50) + 75) / 100;
                }
                else
                {
                  v18 = -100;
                }
                if ( *a2 == col && *a3 == row )
                  v18 = (unsigned __int64)(signed __int64)((double)v18 * 1.5) + 20;
LABEL_107:
                if ( v14 >= v18 )
                {
                  if ( v14 == v18 )
                  {
                    if ( !v18 )
                    {
                      if ( !(advManager::GetCell(gpAdvManager, col, row)->objType & 0x80) )
                      {
                        if ( advManager::GetCell(gpAdvManager, v27, v24)->objType & 0x80
                          || (v10 = abs(v27 - gpCurAIHero->x),
                              v11 = abs(v24 - gpCurAIHero->y) + v10,
                              v12 = abs(col - gpCurAIHero->x),
                              v11 < abs(row - gpCurAIHero->y) + v12) )
                        {
                          v27 = col;
                          v24 = row;
                        }
                      }
                    }
                  }
                }
                else
                {
                  v27 = col;
                  v24 = row;
                  v14 = v18;
                }
              }
            }
          }
        }
        if ( i || v14 <= 150 )
          continue;
      }
      break;
    }
    if ( v14 < 75 && (dword_5306E0 || dword_532CE8) && !dword_532CEC && giCurTurn > 3 )
    {
      if ( (dword_532CE8 || giBuildShipyard[giCurPlayer] < 0 || giBuildShipyard[giCurPlayer] == dword_5305CC)
        && gpCurPlayer->resources[0] + 6 * *(_DWORD *)&gpCurPlayer->_4[60] >= ((unsigned int)dword_532CE8 < 1 ? 30 : 10) )
      {
        if ( !dword_532CE8 )
          giBuildShipyard[giCurPlayer] = dword_5305CC;
        giBuildBoat[giCurPlayer] = dword_5305CC;
        giBuildBoatStuffTurn[giCurPlayer] = giCurTurn;
        v14 = 123;
        v27 = gpGame->castles[dword_5305CC].field_4;
        v24 = gpGame->castles[dword_5305CC].field_5;
        if ( gpCurAIHero->x == v27 && gpCurAIHero->y == v24 )
          *(_DWORD *)&gpCurAIHero->field_35 = 0;
      }
      philAI::CheckBuyStuff(v13);
    }
    *a2 = v27;
    *a3 = v24;
    if ( LOBYTE(gpCurAIHero->field_29) != 255 && v14 <= 0 )
    {
      *a2 = LOBYTE(gpCurAIHero->field_29);
      *a3 = HIBYTE(gpCurAIHero->field_29);
    }
    LogInt(
      (int)"Hero, Best RV target XY  current XY",
      gpCurAIHero->probablyOwnerIdx,
      v14,
      *a2,
      *a3,
      gpCurAIHero->x,
      gpCurAIHero->y,
      -999);
    LogStr("\n\n****");
    result = v14;
  }
  return result;
}