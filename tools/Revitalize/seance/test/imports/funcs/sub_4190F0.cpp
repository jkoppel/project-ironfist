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
  v13 = sub_419500(gameObject, a1, 1);
  if ( v13 >= 8 && gameObject->_10[26] != -1 )
  {
    v12 = 4 * v13 - 32;
    if ( v12 > 100 )
      v12 = 100;
    if ( v12 < 1 )
      LOBYTE(v12) = 1;
    gameObject->players[v6].field_40 = v12;
    if ( gameObject->players[v6].field_40 < unseededNextRand(1, 100) )
    {
      v8 = -1;
      v7 = -1;
      v9 = 0;
      while ( v8 < 0
           || v8 >= mapWidth
           || v7 < 0
           || v7 >= mapHeight
           || *(&gameObject->map.tiles[v8].objType + 12 * v7 * gameObject->map.width)
           || *((_BYTE *)&gameObject->map.tiles[v8].field_2 + 12 * v7 * gameObject->map.width + 1) != 255
           || *(&gameObject->map.tiles[v8].field_7 + 12 * v7 * gameObject->map.width) != 255
           || !tileToTerrainType[*(&gameObject->map.tiles[v7 * gameObject->map.width].tileType + 6 * v8)] )
      {
        ++v9;
        for ( i = 0; !i; i = v3 - unseededNextRand(0, 2) )
        {
          v2 = 3 - unseededNextRand(0, 2);
          v3 = v2 - unseededNextRand(0, 2);
        }
        v8 = i + gameObject->_10[24];
        for ( j = 0; !j; j = v5 - unseededNextRand(0, 2) )
        {
          v4 = 3 - unseededNextRand(0, 2);
          v5 = v4 - unseededNextRand(0, 2);
        }
        v7 = j + gameObject->_10[25];
        if ( v9 >= 200 )
        {
          LOBYTE(v8) = gameObject->_10[24];
          LOBYTE(v7) = gameObject->_10[25];
          break;
        }
      }
      LOBYTE(gameObject->players[v6].field_41) = v8;
      result = v7;
      HIBYTE(gameObject->players[v6].field_41) = v7;
    }
    else
    {
      LOBYTE(gameObject->players[v6].field_41) = gameObject->_10[24];
      result = gameObject->_10[25];
      HIBYTE(gameObject->players[v6].field_41) = result;
    }
  }
  else
  {
    gameObject->players[v6].field_40 = 0;
    LOBYTE(gameObject->players[v6].field_41) = -1;
    result = 27 * v6;
    HIBYTE(gameObject->players[v6].field_41) = -1;
  }
  return result;
}
