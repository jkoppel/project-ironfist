void __cdecl fix_grouping_0(int a1)
{
  int v1; // edx@1
  char v2; // al@2
  int v3; // eax@7

  v1 = a1;
  while ( *(_BYTE *)v1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *(_BYTE *)v1;
        if ( *(_BYTE *)v1 < 48 || v2 > 57 )
          break;
        *(_BYTE *)v1++ = v2 - 48;
        if ( !*(_BYTE *)v1 )
          return;
      }
      if ( v2 == 59 )
        break;
      ++v1;
      if ( !*(_BYTE *)v1 )
        return;
    }
    v3 = v1;
    do
    {
      *(_BYTE *)v3 = *(_BYTE *)(v3 + 1);
      ++v3;
    }
    while ( *(_BYTE *)v3 );
  }
}
