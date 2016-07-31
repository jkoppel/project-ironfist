{
  int result; // eax@3
  int i; // [sp+10h] [bp-4h]@2

  if ( dword_5235D4 > 1 )
  {
    for ( i = 0; ; ++i )
    {
      result = i;
      if ( dword_5235D4 <= i )
        break;
      if ( dword_524778 != 2 )
        strcpy(&dword_5235E0[21 * i], (const char *)&dword_526CE0 + 34 * i + 4);
    }
  }
  return result;
}
