{
  int v3; // eax@47
  int v4; // ST4C_4@57
  int result; // eax@60
  int v6; // [sp+24h] [bp-48h]@1
  char v7; // [sp+48h] [bp-24h]@28
  signed int v8; // [sp+4Ch] [bp-20h]@51
  signed int j; // [sp+50h] [bp-1Ch]@51
  signed int i; // [sp+54h] [bp-18h]@1
  signed int k; // [sp+58h] [bp-14h]@53
  char v12; // [sp+5Ch] [bp-10h]@47
  int v13; // [sp+60h] [bp-Ch]@0
  int v14; // [sp+64h] [bp-8h]@1
  char v15; // [sp+68h] [bp-4h]@16

  v6 = this;
  v14 = (unsigned __int8)tileToTerrainType[*(_WORD *)(*(_DWORD *)(this + 2878)
                                                    + 12 * a3 * *(_DWORD *)(this + 2886)
                                                    + 12 * a2)];
  for ( i = 0; i < 30; ++i )
  {
    switch ( v14 )
    {
      case 1:
      case 6:
        v13 = unseededNextRand(1, 6);
        if ( v13 == 1 )
          v13 = 0;
        break;
      case 2:
        v13 = unseededNextRand(2, 6);
        break;
      case 3:
        v13 = unseededNextRand(0, 6);
        break;
      case 4:
        v13 = 1;
        break;
      default:
        v13 = unseededNextRand(1, 6);
        break;
    }
    if ( !word_522FA0[v13] )
      i = 30;
  }
  ++word_522FA0[v13];
  if ( v13 )
  {
    if ( v13 == 1 )
    {
      v15 = 25;
    }
    else
    {
      if ( v14 == 1 )
      {
        v15 = 15;
      }
      else
      {
        if ( v14 == 2 )
          v15 = 19;
        else
          v15 = 9;
      }
    }
  }
  else
  {
    v15 = 5;
  }
  if ( v13 )
  {
    if ( v13 == 1 )
    {
      if ( v14 == 3 )
      {
        v7 = 43;
      }
      else
      {
        if ( v14 == 4 )
          v7 = 35;
        else
          v7 = 27;
      }
    }
    else
    {
      switch ( v14 )
      {
        case 1:
          v7 = 17;
          break;
        case 2:
          v7 = 21;
          break;
        case 3:
          v7 = 23;
          break;
        case 5:
          v7 = 13;
          break;
        default:
          v7 = 11;
          break;
      }
    }
  }
  else
  {
    v7 = 7;
  }
  *(_BYTE *)(*(_DWORD *)(v6 + 2878) + 12 * a3 * *(_DWORD *)(v6 + 2886) + 12 * a2 + 3) = v7;
  *(_BYTE *)(*(_DWORD *)(v6 + 2878) + 12 * a3 * *(_DWORD *)(v6 + 2886) + 4 * (3 * a2 + 3) + 3) = v7 + 1;
  *(_BYTE *)(*(_DWORD *)(v6 + 2878) + 12 * (a3 - 1) * *(_DWORD *)(v6 + 2886) + 12 * a2 + 7) = v15;
  *(_BYTE *)(*(_DWORD *)(v6 + 2878) + 12 * (a3 - 1) * *(_DWORD *)(v6 + 2886) + 4 * (3 * a2 + 3) + 7) = v15 + 1;
  if ( v13 == 1 )
  {
    v3 = *(_DWORD *)(v6 + 2878) + 12 * a3 * *(_DWORD *)(v6 + 2886) + 4 * (3 * a2 + 3);
    *(_BYTE *)(v3 + 2) |= 1u;
    v12 = 1;
  }
  else
  {
    if ( v13 )
    {
      sub_470100(
        (MapTiles *)(v6 + 2878),
        *(_DWORD *)(v6 + 2878) + 12 * a3 * *(_DWORD *)(v6 + 2886) + 4 * (3 * a2 + 3),
        a2 + 1,
        a3,
        29,
        v13 - 2,
        0,
        -1);
      v12 = 23;
    }
    else
    {
      v12 = 29;
    }
  }
  v8 = sub_419D20((void *)v6, a2, a3);
  for ( j = 0; j < 2; ++j )
  {
    for ( k = 0; k < 2; ++k )
    {
      if ( (*(_BYTE *)(12 * (a2 + k) + 12 * (a3 - j) * *(_DWORD *)(v6 + 2886) + *(_DWORD *)(v6 + 2878) + 9) & 0x7F) <= 0
        || (*(_BYTE *)(12 * (a2 + k) + 12 * (a3 - j) * *(_DWORD *)(v6 + 2886) + *(_DWORD *)(v6 + 2878) + 9) & 0x7Fu) > 0x30 )
      {
        v4 = *(_DWORD *)(v6 + 2878) + 12 * (a2 + k) + 12 * (a3 - j) * *(_DWORD *)(v6 + 2886);
        *(_WORD *)(v4 + 4) = *(_WORD *)(v4 + 4) & 7 | 8 * v8;
        *(_BYTE *)(*(_DWORD *)(v6 + 2878) + 12 * (a2 + k) + 12 * (a3 - j) * *(_DWORD *)(v6 + 2886) + 9) = v12;
      }
    }
  }
  result = *(_DWORD *)(v6 + 2878) + 12 * a3 * *(_DWORD *)(v6 + 2886) + 12 * a2;
  *(_BYTE *)(result + 9) |= 0x80u;
  LOBYTE(result) = v13;
  *(_BYTE *)(7 * v8 + v6 + 23736) = v13;
  return result;
}
