{
  int v3; // ebx@9
  int v4; // ebx@18
  int v5; // [sp+Ch] [bp-10h]@1
  int v6; // [sp+10h] [bp-Ch]@1
  int j; // [sp+14h] [bp-8h]@6
  int i; // [sp+18h] [bp-4h]@4
  signed int k; // [sp+18h] [bp-4h]@15

  v5 = a2;
  v6 = a1;
  if ( a2 != -1 && a3 != -1 )
  {
    for ( i = 0; i < MAP_WIDTH; ++i )
    {
      for ( j = 0; j < MAP_HEIGHT; ++j )
      {
        if ( v6 )
        {
          v3 = abs(a3 - j);
          if ( abs(v5 - i) + v3 < 10 )
            *((_WORD *)gaiHeroStrategicRVOfPos + i + MAP_WIDTH * j) = -32001;
        }
        else
        {
          *((_WORD *)gaiHeroStrategicRVOfPos + i + MAP_WIDTH * j) = -32001;
          *((_WORD *)gaiHeroEventStratRVOfPos + i + MAP_WIDTH * j) = -32001;
        }
      }
    }
    *((_WORD *)gaiHeroEventStratRVOfPos + v5 + a3 * MAP_WIDTH) = -32001;
    for ( k = 0; k < 54; ++k )
    {
      if ( v6 )
      {
        v4 = abs(a3 - gpGame->heroes[k].x);
        if ( abs(v5 - gpGame->heroes[k].x) + v4 >= 10 )
          continue;
      }
      gaiHeroLiveChance[k] = -32001;
    }
  }
}