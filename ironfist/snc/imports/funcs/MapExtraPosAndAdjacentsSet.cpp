{
  signed int result; // eax@2
  int j; // [sp+14h] [bp-8h]@9
  int i; // [sp+18h] [bp-4h]@3

  if ( *(&mapExtra[a1] + a2 * MAP_WIDTH) & a3 )
  {
    result = 1;
  }
  else
  {
    for ( i = a1 - 1; a1 + 1 >= i; ++i )
    {
      if ( i >= 0 && i < MAP_WIDTH )
      {
        for ( j = a2 - 1; a2 + 1 >= j; ++j )
        {
          if ( j >= 0 && j < MAP_HEIGHT && (unsigned __int8)(*(&mapExtra[i] + j * MAP_WIDTH) & a3) )
            return 1;
        }
      }
    }
    result = 0;
  }
  return result;
}