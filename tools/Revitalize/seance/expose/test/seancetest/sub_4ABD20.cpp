signed int __stdcall sub_4ABD20(signed int a1)
{
  signed int result; // eax@2
  int v2; // ST44_4@24
  int v3; // [sp+10h] [bp-34h]@19
  int v4; // [sp+14h] [bp-30h]@4
  int v5; // [sp+18h] [bp-2Ch]@42
  int v6; // [sp+1Ch] [bp-28h]@24
  int row; // [sp+20h] [bp-24h]@10
  signed int i; // [sp+24h] [bp-20h]@25
  int col; // [sp+28h] [bp-1Ch]@8
  int v10; // [sp+2Ch] [bp-18h]@29
  int v11; // [sp+30h] [bp-14h]@0
  signed int v12; // [sp+34h] [bp-10h]@3
  int v13; // [sp+38h] [bp-Ch]@29
  char v14; // [sp+3Ch] [bp-8h]@41
  char v15; // [sp+40h] [bp-4h]@41

  if ( dword_51D5BC->flags1 & 0x80 )
  {
    result = 0;
  }
  else
  {
    v12 = -1;
    if ( a1 <= 25 )
      v4 = unseededNextRand(0, 125) - 50;
    else
      v4 = a1 + 1000;
    if ( !Hero::hasSpell(dword_51D5BC, SPELL_DIMENSION_DOOR) || dword_51D5BC->spellpoints < 30 )
      goto LABEL_55;
    for ( col = 0; col < mapWidth; ++col )
    {
      for ( row = 0; row < mapHeight; ++row )
      {
        if ( !(*(&pathfinder->field_2414[col].field_4 + 9 * row * mapWidth) & 1)
          && abs(col - dword_51D5BC->x) <= 7
          && abs(row - dword_51D5BC->y) <= 7
          && (dword_51D5BC->x != col || dword_51D5BC->y != row) )
        {
          v3 = usedToCheckForBoatByCastle(advManager, col, row);
          if ( tileToTerrainType[*(_WORD *)v3] && (*(_BYTE *)(v3 + 9) & 0x80 || a1 < 25 && unseededNextRand(0, 10) < 2) )
          {
            v2 = sub_4B1570(__PAIR__(row, col), 0, -1i64, 0, -1i64, 2, *(_DWORD *)&dword_51D5BC->_4[20]);
            v6 = unseededNextRand(0, 30) + v2;
            if ( v4 < v6 )
            {
              for ( i = 0; i < 3; ++i )
              {
                if ( i )
                {
                  if ( i == 1 )
                  {
                    v13 = col;
                    v10 = row + 1;
                  }
                  else
                  {
                    v13 = col + 1;
                    v10 = row;
                  }
                }
                else
                {
                  v13 = col - 1;
                  v10 = row;
                }
                if ( !(*(&pathfinder->field_2414[v13].field_4 + 9 * v10 * mapWidth) & 1)
                  && (dword_51D5BC->x != v13 || dword_51D5BC->y != v10) )
                {
                  if ( v13 >= 0 )
                  {
                    if ( mapWidth - 1 >= v13 )
                    {
                      if ( v10 >= 0 )
                      {
                        if ( mapHeight - 1 >= v10 )
                        {
                          if ( !sub_456630(advManager, __PAIR__(v10, v13), (int)&v15, (int)&v14, -1, -1) )
                          {
                            v5 = usedToCheckForBoatByCastle(advManager, v13, v10);
                            if ( tileToTerrainType[*(_WORD *)v5] )
                            {
                              if ( !(*(_BYTE *)(v5 + 8) & 8)
                                && !(*(_BYTE *)(v5 + 9) & 0x80)
                                && (*(_BYTE *)(v5 + 3) == 255 || *(_BYTE *)(v5 + 8) & 0x80) )
                              {
                                v12 = v13;
                                v11 = v10;
                                v4 = v6;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( v12 != -1 )
    {
      sub_4ABCA0(__PAIR__(v11, v12));
      result = 1;
    }
    else
    {
LABEL_55:
      result = 0;
    }
  }
  return result;
}
