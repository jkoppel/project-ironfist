{
  __int16 v1; // ST1C_2@35
  int v2; // [sp+Ch] [bp-28h]@1
  int v3; // [sp+18h] [bp-1Ch]@10
  signed int j; // [sp+1Ch] [bp-18h]@8
  mapCell *v5; // [sp+20h] [bp-14h]@30
  int v6; // [sp+24h] [bp-10h]@1
  signed int i; // [sp+24h] [bp-10h]@6
  int row; // [sp+28h] [bp-Ch]@28
  int col; // [sp+2Ch] [bp-8h]@26
  __int16 v10; // [sp+30h] [bp-4h]@11

  v2 = this;
  ++*(_WORD *)(this + 1178);
  v6 = Random(1, 10);
  if ( v6 > 5 )
  {
    if ( v6 > 9 )
    {
      giMonthType = 2;
    }
    else
    {
      giMonthType = 1;
      *(_DWORD *)&giMonthTypeExtra = byte_4EF660[Random(0, 11)];
    }
  }
  else
  {
    giMonthType = 0;
    *(_DWORD *)&giMonthTypeExtra = Random(0, 9);
  }
  for ( i = 0; i < 72; ++i )
  {
    for ( j = 19; j <= 30; ++j )
    {
      v3 = v2 + 100 * i + 2899;
      if ( (1 << j) & *(_DWORD *)(v2 + 100 * i + 2923) )
      {
        v10 = gMonsterDatabase[LOBYTE((&gTownObjNames[3 * *(_BYTE *)(v2 + 100 * i + 2902) + 27])[j + 1])].growth;
        if ( *(_BYTE *)(v2 + 100 * i + 2923) & 0x10 )
          v10 += 2;
        if ( j == 19 && *(_BYTE *)(v2 + 100 * i + 2924) & 8 )
          v10 += 8;
        if ( giMonthType == 1
          && LOBYTE((&gTownObjNames[3 * *(_BYTE *)(v2 + 100 * i + 2902) + 27])[j + 1]) == *(_DWORD *)&giMonthTypeExtra )
          *(_WORD *)(v3 + 2 * j - 8) *= 2;
        if ( giMonthType == 2 )
        {
          *(_WORD *)(v3 + 2 * j - 8) -= v10;
          if ( (signed int)*(_WORD *)(v3 + 2 * j - 8) < 0 )
            *(_WORD *)(v3 + 2 * j - 8) = 0;
          *(_WORD *)(v3 + 2 * j - 8) >>= 1;
        }
      }
    }
  }
  if ( giMonthType == 1 )
  {
    for ( col = 0; col < MAP_WIDTH; ++col )
    {
      for ( row = 0; row < MAP_HEIGHT; ++row )
      {
        v5 = advManager::GetCell(gpAdvManager, col, row);
        if ( !v5->objType )
        {
          if ( !((v5->flags >> 1) & 1) )
          {
            if ( !(v5->flags & 1) )
            {
              if ( giGroundToTerrain[v5->tileType] )
              {
                if ( Random(0, 360) == 10 )
                {
                  v5->objType = -104;
                  LOBYTE(v5->field_2) = v5->field_2 & 3 | 0x30;
                  HIBYTE(v5->field_2) = *(_BYTE *)&giMonthTypeExtra;
                  v1 = game::GetRandomNumTroops(*(int *)&giMonthTypeExtra);
                  v5->flags = v5->flags & 7 | 8 * (game::GetRandomNumTroops(*(int *)&giMonthTypeExtra) + v1);
                  if ( Random(0, 100) < 20 )
                    v5->flags = v5->flags & 7 | 8
                                              * ((unsigned __int8)((unsigned __int8)(v5->flags >> 8) >> -5) | 0x1000);
                }
              }
            }
          }
        }
      }
    }
  }
  advManager::CompleteDraw(gpAdvManager, 0);
}