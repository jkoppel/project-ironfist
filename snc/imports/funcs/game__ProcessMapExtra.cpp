{
  signed int v1; // ST20_4@6
  int result; // eax@28
  signed int v3; // [sp+Ch] [bp-20h]@5
  int v4; // [sp+10h] [bp-1Ch]@1
  int v5; // [sp+14h] [bp-18h]@5
  int v6; // [sp+14h] [bp-18h]@16
  int i; // [sp+1Ch] [bp-10h]@1
  int k; // [sp+1Ch] [bp-10h]@12
  int m; // [sp+1Ch] [bp-10h]@27
  int j; // [sp+20h] [bp-Ch]@3
  int l; // [sp+20h] [bp-Ch]@14
  int n; // [sp+20h] [bp-Ch]@29

  v4 = (int)this;
  for ( i = 0; MAP_HEIGHT > i; ++i )
  {
    for ( j = 0; j < MAP_WIDTH; ++j )
    {
      v5 = *(_DWORD *)(v4 + 2878) + 12 * i * *(_DWORD *)(v4 + 2886) + 12 * j;
      v3 = *(_BYTE *)(v5 + 9);
      if ( v3 == 163 || v3 >= 176 && v3 <= 177 )
      {
        v1 = game::GetTownId((void *)v4, j, i);
        *(_WORD *)(100 * v1 + v4 + 2957) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v5 + 4) >> 8) >> -5);
        *(_WORD *)(v5 + 4) = 8 * v1 | *(_WORD *)(v5 + 4) & 7;
      }
    }
  }
  for ( k = 0; MAP_HEIGHT > k; ++k )
  {
    for ( l = 0; l < MAP_WIDTH; ++l )
    {
      v6 = *(_DWORD *)(v4 + 2878) + 12 * k * *(_DWORD *)(v4 + 2886) + 12 * l;
      if ( *(_BYTE *)(v6 + 9) == 151 && k > 0 && game::HasLateOverlay(v4, l, k - 1) )
        game::ConvertFlagToLateOverlay((game *)v4, l, k);
      if ( *(_BYTE *)(v6 + 9) == 129 )
      {
        if ( k > 0 )
          game::ConvertFlagToLateOverlay((game *)v4, l, k - 1);
        if ( k > 1 )
          game::ConvertFlagToLateOverlay((game *)v4, l, k - 2);
      }
    }
  }
  for ( m = 0; ; ++m )
  {
    result = m;
    if ( MAP_HEIGHT <= m )
      break;
    for ( n = 0; n < MAP_WIDTH; ++n )
    {
      if ( game::HasLateOverlay(v4, n, m) )
        game::ConvertAllToLateOverlay(v4, n, m);
    }
  }
  return result;
}