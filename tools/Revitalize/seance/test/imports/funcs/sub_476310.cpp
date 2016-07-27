{
  CombatManager *thisa; // ST1C_4@1
  char v3[24]; // [sp+18h] [bp-3Ch]@1
  int v4; // [sp+30h] [bp-24h]@10
  int j; // [sp+34h] [bp-20h]@3
  int v6; // [sp+38h] [bp-1Ch]@1
  int i; // [sp+3Ch] [bp-18h]@1
  int v8; // [sp+40h] [bp-14h]@16
  int v9; // [sp+44h] [bp-10h]@1
  int row; // [sp+48h] [bp-Ch]@6
  int col; // [sp+4Ch] [bp-8h]@6
  int v12; // [sp+50h] [bp-4h]@16

  thisa = this;
  memset(v3, -1, 0x18u);
  v9 = *(_DWORD *)&thisa->_15[28];
  v6 = *(_DWORD *)&thisa->_15[32];
  for ( i = 0; i < 3; ++i )
  {
    for ( j = 0; j < 8; ++j )
    {
      col = v9 + i * byte_4F1DC0[4 * j];
      row = v6 + i * byte_4F1DC1[4 * j];
      if ( col >= 0 && mapWidth > col && row >= 0 && row < mapHeight )
      {
        v4 = usedToCheckForBoatByCastle(advManager, col, row);
        switch ( (*(_BYTE *)(v4 + 2) >> 2) & 0x3F )
        {
          case 0x16:
          case 0x17:
          case 0x18:
          case 0x19:
          case 0x1A:
          case 0x1B:
          case 0x1F:
          case 0x20:
            *(&v3[8 * i] + j) = 0;
            break;
          case 0x21:
          case 0x22:
          case 0x2A:
          case 0x2B:
          case 0x2C:
            *(&v3[8 * i] + j) = 1;
            break;
          default:
            continue;
        }
      }
    }
  }
  v8 = 0;
  v12 = 0;
  for ( i = 0; i < 3; ++i )
  {
    for ( j = 0; j < 8; ++j )
    {
      if ( !*(&v3[8 * i] + j) )
        ++v12;
      if ( *(&v3[8 * i] + j) == 1 )
        ++v8;
    }
  }
  return v8 > v12;
}
