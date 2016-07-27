{
  __int16 v1; // ST1C_2@35
  int v2; // [sp+Ch] [bp-28h]@1
  int v3; // [sp+18h] [bp-1Ch]@10
  signed int j; // [sp+1Ch] [bp-18h]@8
  int v5; // [sp+20h] [bp-14h]@30
  int v6; // [sp+24h] [bp-10h]@1
  signed int i; // [sp+24h] [bp-10h]@6
  int row; // [sp+28h] [bp-Ch]@28
  int col; // [sp+2Ch] [bp-8h]@26
  __int16 v10; // [sp+30h] [bp-4h]@11

  v2 = this;
  ++*(_WORD *)(this + 1178);
  v6 = unseededNextRand(1, 10);
  if ( v6 > 5 )
  {
    if ( v6 > 9 )
    {
      dword_524A74 = 2;
    }
    else
    {
      dword_524A74 = 1;
      *(_DWORD *)&dword_52343C = byte_4EF660[unseededNextRand(0, 11)];
    }
  }
  else
  {
    dword_524A74 = 0;
    *(_DWORD *)&dword_52343C = unseededNextRand(0, 9);
  }
  for ( i = 0; i < 72; ++i )
  {
    for ( j = 19; j <= 30; ++j )
    {
      v3 = v2 + 100 * i + 2899;
      if ( (1 << j) & *(_DWORD *)(v2 + 100 * i + 2923) )
      {
        v10 = creature_table[LOBYTE((&buildingShortNames[3 * *(_BYTE *)(v2 + 100 * i + 2902) + 27])[j + 1])].growth;
        if ( *(_BYTE *)(v2 + 100 * i + 2923) & 0x10 )
          v10 += 2;
        if ( j == 19 && *(_BYTE *)(v2 + 100 * i + 2924) & 8 )
          v10 += 8;
        if ( dword_524A74 == 1
          && LOBYTE((&buildingShortNames[3 * *(_BYTE *)(v2 + 100 * i + 2902) + 27])[j + 1]) == *(_DWORD *)&dword_52343C )
          *(_WORD *)(v3 + 2 * j - 8) *= 2;
        if ( dword_524A74 == 2 )
        {
          *(_WORD *)(v3 + 2 * j - 8) -= v10;
          if ( (signed int)*(_WORD *)(v3 + 2 * j - 8) < 0 )
            *(_WORD *)(v3 + 2 * j - 8) = 0;
          *(_WORD *)(v3 + 2 * j - 8) = (signed int)*(_WORD *)(v3 + 2 * j - 8) >> 1;
        }
      }
    }
  }
  if ( dword_524A74 == 1 )
  {
    for ( col = 0; col < mapWidth; ++col )
    {
      for ( row = 0; row < mapHeight; ++row )
      {
        v5 = usedToCheckForBoatByCastle(advManager, col, row);
        if ( !*(_BYTE *)(v5 + 9) )
        {
          if ( !((*(_WORD *)(v5 + 4) >> 1) & 1) )
          {
            if ( !(*(_WORD *)(v5 + 4) & 1) )
            {
              if ( tileToTerrainType[*(_WORD *)v5] )
              {
                if ( unseededNextRand(0, 360) == 10 )
                {
                  *(_BYTE *)(v5 + 9) = -104;
                  *(_BYTE *)(v5 + 2) = *(_BYTE *)(v5 + 2) & 3 | 0x30;
                  *(_BYTE *)(v5 + 3) = *(_BYTE *)&dword_52343C;
                  v1 = sub_423760(*(int *)&dword_52343C);
                  *(_WORD *)(v5 + 4) = *(_WORD *)(v5 + 4) & 7 | 8 * (sub_423760(*(int *)&dword_52343C) + v1);
                  if ( unseededNextRand(0, 100) < 20 )
                    *(_WORD *)(v5 + 4) = *(_WORD *)(v5 + 4) & 7 | 8
                                                                * ((unsigned __int8)((unsigned __int8)(*(_WORD *)(v5 + 4) >> 8) >> -5) | 0x1000);
                }
              }
            }
          }
        }
      }
    }
  }
  sub_448110(advManager, 0);
}
