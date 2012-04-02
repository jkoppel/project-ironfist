signed int __thiscall sub_4AE590(void *this, int *a2, int *a3, signed int a4, int a5)
{
  signed int result; // eax@2
  PathfindingInfo *v6; // ST68_4@22
  int v7; // ebx@46
  int v8; // ebx@88
  __int64 v9; // ST20_8@102
  __int64 v10; // ST14_8@102
  int v11; // ST80_4@102
  int v12; // ebx@113
  int v13; // ebx@113
  int v14; // esi@113
  void *v15; // [sp+2Ch] [bp-70h]@1
  int v16; // [sp+40h] [bp-5Ch]@3
  int v17; // [sp+44h] [bp-58h]@63
  signed int v18; // [sp+48h] [bp-54h]@22
  int v19; // [sp+4Ch] [bp-50h]@3
  int v20; // [sp+50h] [bp-4Ch]@98
  int v21; // [sp+54h] [bp-48h]@1
  int v22; // [sp+58h] [bp-44h]@88
  int j; // [sp+5Ch] [bp-40h]@91
  int i; // [sp+60h] [bp-3Ch]@30
  int row; // [sp+64h] [bp-38h]@39
  int v26; // [sp+68h] [bp-34h]@3
  int v27; // [sp+6Ch] [bp-30h]@100
  int col; // [sp+70h] [bp-2Ch]@35
  int v29; // [sp+74h] [bp-28h]@3
  int v30; // [sp+78h] [bp-24h]@28
  int v31; // [sp+7Ch] [bp-20h]@20
  int v32; // [sp+80h] [bp-1Ch]@26
  int v33; // [sp+84h] [bp-18h]@24
  bool v34; // [sp+88h] [bp-14h]@65
  int v35; // [sp+8Ch] [bp-10h]@37
  signed int a5a; // [sp+90h] [bp-Ch]@22
  int v37; // [sp+94h] [bp-8h]@46
  int v38; // [sp+98h] [bp-4h]@22

  v15 = this;
  if ( sub_4AB290((int)&v21) )
  {
    *a2 = dword_51D5BC->x + byte_4F1DC0[4 * v21];
    *a3 = dword_51D5BC->y + byte_4F1DC1[4 * v21];
    *(_DWORD *)a5 = v21;
    result = 1000;
  }
  else
  {
    *(_DWORD *)a5 = -1;
    v29 = -1;
    v26 = -1;
    v16 = -999999;
    dword_5305CC = -1;
    dword_5306E0 = 0;
    dword_532CE8 = 0;
    dword_532CEC = 0;
    v19 = (unsigned __int8)tileToTerrainType[*(_WORD *)usedToCheckForBoatByCastle(
                                                         advManager,
                                                         dword_51D5BC->x,
                                                         dword_51D5BC->y)];
    if ( dword_51D5BC->secondarySkillLevel[0] > 1 )
    {
      switch ( gameObject->_1[682] )
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
      if ( v19 == 2 || v19 == 3 )
        a4 = (signed __int64)((double)a4 * 1.15);
      if ( v19 == 5 )
        a4 = (signed __int64)((double)a4 * 1.35);
      if ( v19 == 7 )
        a4 = (signed __int64)((double)a4 * 1.25);
    }
    if ( curPlayer->personality == 2 )
      a4 = (signed __int64)((double)a4 * 1.15);
    v31 = a4 / 100 / 4;
    if ( v31 < 6 )
      v31 = 6;
    a5a = 2 * a4;
    Pathfinder::doSomething2(
      pathfinder,
      dword_51D5BC->x,
      dword_51D5BC->y,
      dword_51D5BC->_4[11],
      2 * a4,
      *(_DWORD *)&dword_51D5BC->flags1 & 0x80,
      1,
      *(_DWORD *)&dword_51D5BC->_4[20],
      dword_51D5BC->secondarySkillLevel[0],
      -1i64,
      0,
      0);
    v6 = &pathfinder->field_2414[dword_51D5BC->x] + mapWidth * dword_51D5BC->y;
    v6->field_4 &= 0xFEu;
    v18 = -1;
    v38 = dword_51D5BC->x - 25;
    if ( v38 < 0 )
      v38 = 0;
    v33 = dword_51D5BC->y - 25;
    if ( v33 < 0 )
      v33 = 0;
    v32 = dword_51D5BC->x + 25;
    if ( mapWidth - 1 < v32 )
      v32 = mapWidth;
    v30 = dword_51D5BC->y + 25;
    if ( mapHeight - 1 < v30 )
      v30 = mapHeight;
    for ( i = 0; ; ++i )
    {
      if ( i < 2 )
      {
        if ( dword_51D5BC->flags1 & 0x80 && !i )
          continue;
        for ( col = v38; col < v32; ++col )
        {
          v35 = -1;
          ++v18;
          if ( v31 <= v18 )
            v18 = 0;
          for ( row = v33; row < v30; ++row )
          {
            ++v35;
            if ( v31 <= v35 )
              v35 = 0;
            if ( *(&pathfinder->field_2414[col].field_4 + 9 * row * mapWidth) & 1 )
            {
              if ( dword_51D5BC->flags1 & 0x80
                || ((v7 = abs(col - dword_51D5BC->x), v37 = abs(row - dword_51D5BC->y) + v7, i)
                 || v37 <= 5
                 || *(_DWORD *)&dword_51D5BC->_4[0] == col && *(_DWORD *)&dword_51D5BC->_4[4] == row
                 || v37 < 16
                 && (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) == 170
                  || *(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) == 163
                  && gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(usedToCheckForBoatByCastle(
                                                                                          advManager,
                                                                                          col,
                                                                                          row)
                                                                                      + 4) >> 8) >> -5)].ownerIdx != curPlayerIdx))
                && (i != 1
                 || v37 > 5
                 && (*(_DWORD *)&dword_51D5BC->_4[0] != col || *(_DWORD *)&dword_51D5BC->_4[4] != row)
                 && (v37 >= 16
                  || *(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) != 170
                  && (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) != 163
                   || gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(usedToCheckForBoatByCastle(
                                                                                           advManager,
                                                                                           col,
                                                                                           row)
                                                                                       + 4) >> 8) >> -5)].ownerIdx == curPlayerIdx))) )
              {
                v17 = usedToCheckForBoatByCastle(advManager, col, row);
                if ( *(__int16 *)((char *)&pathfinder->field_2414[col].field_2 + 9 * row * mapWidth) <= a4 )
                {
                  v34 = *(_BYTE *)(v17 + 9) & 0x80
                     || *(_BYTE *)(v17 + 9) == 28 && dword_51D5BC->flags1 & 0x80
                     || !(col % v31)
                     && !(row % v31)
                     && (dword_51D5BC->flags1 & 0x80 && !tileToTerrainType[*(_WORD *)v17]
                      || !(dword_51D5BC->flags1 & 0x80) && tileToTerrainType[*(_WORD *)v17])
                     || LOBYTE(curPlayer->field_41) == col && HIBYTE(curPlayer->field_41) == row;
                }
                else
                {
                  if ( *(__int16 *)((char *)&pathfinder->field_2414[col].field_2 + 9 * row * mapWidth) <= a5a )
                    v34 = *(_BYTE *)(v17 + 9) == 163
                       || *(_BYTE *)(v17 + 9) == 170
                       || *(_BYTE *)(v17 + 9) == 171 && !(dword_51D5BC->flags1 & 0x80);
                  else
                    v34 = 0;
                }
                if ( v34 )
                {
                  if ( dword_51D5BC->_4[8] != 255 )
                  {
                    v8 = abs(row - dword_51D5BC->_4[9]);
                    v22 = abs(col - dword_51D5BC->_4[8]) + v8;
                    if ( dword_51D5BC->_4[10] < v22 )
                      v34 = 0;
                  }
                }
                if ( v34 )
                {
                  for ( j = 0; curPlayer->numHeroes > j; ++j )
                  {
                    if ( *(_BYTE *)(v17 + 9) != 163
                      && *(_BYTE *)(v17 + 9) != 170
                      && curPlayer->heroesOwned[j] != dword_51D5BC->field_2
                      && *(_DWORD *)&gameObject->heroes[curPlayer->heroesOwned[j]]._4[0] == col
                      && *(_DWORD *)&gameObject->heroes[curPlayer->heroesOwned[j]]._4[4] == row )
                    {
                      v20 = -2000;
                      goto LABEL_107;
                    }
                  }
                  sub_4AA7B0(0, 0);
                  v27 = *(_DWORD *)&dword_51D5BC->_4[16]
                      - *(__int16 *)((char *)&pathfinder->field_2414[col].field_2 + 9 * row * mapWidth);
                  if ( v27 < 0 )
                    v27 = 0;
                  HIDWORD(v9) = *((_BYTE *)&pathfinder->field_2414[col].field_5 + 9 * row * mapWidth + 3);
                  LODWORD(v9) = *((_BYTE *)&pathfinder->field_2414[col].field_5 + 9 * row * mapWidth + 2);
                  HIDWORD(v10) = *((_BYTE *)&pathfinder->field_2414[col].field_5 + 9 * row * mapWidth + 1);
                  LODWORD(v10) = *((_BYTE *)&pathfinder->field_2414[col].field_5 + 9 * row * mapWidth);
                  v11 = sub_4B1570(
                          __PAIR__(row, col),
                          ((unsigned __int8)*(&pathfinder->field_2414[col].field_4 + 9 * row * mapWidth) >> 2) & 1,
                          v10,
                          ((unsigned __int8)*(&pathfinder->field_2414[col].field_4 + 9 * row * mapWidth) >> 3) & 1,
                          v9,
                          2,
                          v27);
                  v20 = v11 * (unseededNextRand(1, 50) + 75) / 100;
                }
                else
                {
                  v20 = -100;
                }
                if ( *a2 == col && *a3 == row )
                  v20 = (unsigned __int64)(signed __int64)((double)v20 * 1.5) + 20;
LABEL_107:
                if ( v16 >= v20 )
                {
                  if ( v16 == v20 )
                  {
                    if ( !v20 )
                    {
                      if ( !(*(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) & 0x80) )
                      {
                        if ( *(_BYTE *)(usedToCheckForBoatByCastle(advManager, v29, v26) + 9) & 0x80
                          || (v12 = abs(v29 - dword_51D5BC->x),
                              v13 = abs(v26 - dword_51D5BC->y) + v12,
                              v14 = abs(col - dword_51D5BC->x),
                              v13 < abs(row - dword_51D5BC->y) + v14) )
                        {
                          v29 = col;
                          v26 = row;
                        }
                      }
                    }
                  }
                }
                else
                {
                  v29 = col;
                  v26 = row;
                  v16 = v20;
                }
              }
            }
          }
        }
        if ( i || v16 <= 150 )
          continue;
      }
      break;
    }
    if ( v16 < 75 && (dword_5306E0 || dword_532CE8) && !dword_532CEC && dword_532C54 > 3 )
    {
      if ( (dword_532CE8 || byte_532CD8[curPlayerIdx] < 0 || byte_532CD8[curPlayerIdx] == dword_5305CC)
        && curPlayer->resources[0] + 6 * *(_DWORD *)&curPlayer->_4[60] >= ((unsigned int)dword_532CE8 < 1 ? 30 : 10) )
      {
        if ( !dword_532CE8 )
          byte_532CD8[curPlayerIdx] = dword_5305CC;
        byte_5306C8[curPlayerIdx] = dword_5305CC;
        byte_5306E8[curPlayerIdx] = dword_532C54;
        v16 = 123;
        v29 = gameObject->castles[dword_5305CC].field_4;
        v26 = gameObject->castles[dword_5305CC].field_5;
        if ( dword_51D5BC->x == v29 && dword_51D5BC->y == v26 )
          *(_DWORD *)&dword_51D5BC->_4[20] = 0;
      }
      sub_4AADD0(v15);
    }
    *a2 = v29;
    *a3 = v26;
    if ( dword_51D5BC->_4[8] != 255 && v16 <= 0 )
    {
      *a2 = dword_51D5BC->_4[8];
      *a3 = dword_51D5BC->_4[9];
    }
    logUpTo7Ints(
      (int)"Hero, Best RV target XY  current XY",
      dword_51D5BC->probablyOwnerIdx,
      v16,
      *a2,
      *a3,
      dword_51D5BC->x,
      dword_51D5BC->y,
      -999);
    debugLog("\n\n****");
    result = v16;
  }
  return result;
}
