{
  char result; // al@3
  int v2; // ebx@21
  int v3; // ebx@21
  int v4; // ebx@24
  int v5; // ebx@24
  int v6; // [sp+Ch] [bp-1Ch]@1
  int v7; // [sp+10h] [bp-18h]@10
  int v8; // [sp+14h] [bp-14h]@10
  signed int v9; // [sp+18h] [bp-10h]@10
  int i; // [sp+1Ch] [bp-Ch]@19
  int j; // [sp+1Ch] [bp-Ch]@22
  int v12; // [sp+20h] [bp-8h]@4
  int v13; // [sp+24h] [bp-4h]@1

  v6 = a1;
  v13 = game::SetupPuzzlePieces(gpGame, a1, 1);
  if ( v13 >= 8 && gpGame->_10[26] != -1 )
  {
    v12 = 4 * v13 - 32;
    if ( v12 > 100 )
      v12 = 100;
    if ( v12 < 1 )
      LOBYTE(v12) = 1;
    gpGame->players[v6].field_40 = v12;
    if ( gpGame->players[v6].field_40 < Random(1, 100) )
    {
      v8 = -1;
      v7 = -1;
      v9 = 0;
      while ( v8 < 0
           || v8 >= MAP_WIDTH
           || v7 < 0
           || v7 >= MAP_HEIGHT
           || *(&gpGame->map.tiles[v8].objType + 12 * v7 * gpGame->map.width)
           || *((_BYTE *)&gpGame->map.tiles[v8].field_2 + 12 * v7 * gpGame->map.width + 1) != 255
           || *(&gpGame->map.tiles[v8].field_7 + 12 * v7 * gpGame->map.width) != 255
           || !giGroundToTerrain[*(&gpGame->map.tiles[v7 * gpGame->map.width].tileType + 6 * v8)] )
      {
        ++v9;
        for ( i = 0; !i; i = v3 - Random(0, 2) )
        {
          v2 = 3 - Random(0, 2);
          v3 = v2 - Random(0, 2);
        }
        v8 = i + gpGame->_10[24];
        for ( j = 0; !j; j = v5 - Random(0, 2) )
        {
          v4 = 3 - Random(0, 2);
          v5 = v4 - Random(0, 2);
        }
        v7 = j + gpGame->_10[25];
        if ( v9 >= 200 )
        {
          LOBYTE(v8) = gpGame->_10[24];
          LOBYTE(v7) = gpGame->_10[25];
          break;
        }
      }
      LOBYTE(gpGame->players[v6].field_41) = v8;
      result = v7;
      HIBYTE(gpGame->players[v6].field_41) = v7;
    }
    else
    {
      LOBYTE(gpGame->players[v6].field_41) = gpGame->_10[24];
      result = gpGame->_10[25];
      HIBYTE(gpGame->players[v6].field_41) = result;
    }
  }
  else
  {
    gpGame->players[v6].field_40 = 0;
    LOBYTE(gpGame->players[v6].field_41) = -1;
    result = 27 * v6;
    HIBYTE(gpGame->players[v6].field_41) = -1;
  }
  return result;
}