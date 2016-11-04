{
  signed int result; // eax@2
  int j; // [sp+14h] [bp-8h]@9
  int i; // [sp+18h] [bp-4h]@3

  if ( *(&tileExplored[a1] + a2 * mapWidth) & a3 )
  {
    result = 1;
  }
  else
  {
    for ( i = a1 - 1; a1 + 1 >= i; ++i )
    {
      if ( i >= 0 && i < mapWidth )
      {
        for ( j = a2 - 1; a2 + 1 >= j; ++j )
        {
          if ( j >= 0 && j < mapHeight && (unsigned __int8)(*(&tileExplored[i] + j * mapWidth) & a3) )
            return 1;
        }
      }
    }
    result = 0;
  }
  return result;
}
