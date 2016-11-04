{
  int result; // eax@2
  MapTile *v13; // [sp+10h] [bp-10h]@11
  int v14; // [sp+14h] [bp-Ch]@20
  int v15; // [sp+14h] [bp-Ch]@39
  int j; // [sp+18h] [bp-8h]@3
  int i; // [sp+1Ch] [bp-4h]@1

  for ( i = a2; ; ++i )
  {
    result = i;
    if ( a4 < i )
      break;
    for ( j = a3; a5 >= j; ++j )
    {
      if ( i >= 0 && mapWidth > i && j >= 0 && j < mapHeight )
      {
        v13 = &this->map.tiles[j * this->map.width] + i;
        if ( HIBYTE(v13->field_2) != 255
          && ((LOBYTE(v13->field_2) >> 2) & 0x3F) == a6
          && SHIBYTE(v13->field_2) >= a7
          && SHIBYTE(v13->field_2) <= a8 )
        {
          LOBYTE(v13->field_2) = 4 * a9 | v13->field_2 & 3;
          HIBYTE(v13->field_2) = a10 + HIBYTE(v13->field_2) - a7;
        }
        if ( (v13->objType & 0x7F) == a11 )
          v13->objType = a12 | v13->objType & 0x80;
        if ( v13->field_A && *(_BYTE *)(7 * v13->field_A + this->map.field_4 + 3) != 255 )
          v14 = this->map.field_4 + 7 * v13->field_A;
        else
          v14 = 0;
        while ( v14 )
        {
          if ( ((*(_BYTE *)(v14 + 2) >> 1) & 0x7F) == a6 && *(_BYTE *)(v14 + 3) >= a7 && *(_BYTE *)(v14 + 3) <= a8 )
          {
            *(_BYTE *)(v14 + 2) = 2 * a9 | *(_BYTE *)(v14 + 2) & 1;
            *(_BYTE *)(v14 + 3) = a10 + *(_BYTE *)(v14 + 3) - a7;
          }
          if ( *(_WORD *)v14 && *(_BYTE *)(7 * *(_WORD *)v14 + this->map.field_4 + 3) != 255 )
            v14 = this->map.field_4 + 7 * *(_WORD *)v14;
          else
            v14 = 0;
        }
        if ( v13->field_7 != 255
          && (((unsigned __int8)v13->field_6 >> 2) & 0x3F) == a6
          && v13->field_7 >= a7
          && v13->field_7 <= a8 )
        {
          v13->field_6 = 4 * a9 | v13->field_6 & 3;
          v13->field_7 = a10 + v13->field_7 - a7;
        }
        if ( v13->field_A && *(_BYTE *)(7 * v13->field_A + this->map.field_4 + 6) != 255 )
          v15 = this->map.field_4 + 7 * v13->field_A;
        else
          v15 = 0;
        while ( v15 )
        {
          if ( ((*(_BYTE *)(v15 + 5) >> 2) & 0x3F) == a6 && *(_BYTE *)(v15 + 6) >= a7 && *(_BYTE *)(v15 + 6) <= a8 )
          {
            *(_BYTE *)(v15 + 5) = 4 * a9 | *(_BYTE *)(v15 + 5) & 3;
            *(_BYTE *)(v15 + 6) = a10 + *(_BYTE *)(v15 + 6) - a7;
          }
          if ( *(_WORD *)v15 && *(_BYTE *)(7 * *(_WORD *)v15 + this->map.field_4 + 6) != 255 )
            v15 = this->map.field_4 + 7 * *(_WORD *)v15;
          else
            v15 = 0;
        }
      }
    }
  }
  return result;
}
