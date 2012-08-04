{
  int v2; // edx@1
  char v3; // al@2
  int v4; // eax@7

  v2 = LODWORD(a1);
  while ( *(_BYTE *)v2 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v3 = *(_BYTE *)v2;
        if ( *(_BYTE *)v2 < 48 || v3 > 57 )
          break;
        *(_BYTE *)v2++ = v3 - 48;
        if ( !*(_BYTE *)v2 )
          return;
      }
      if ( v3 == 59 )
        break;
      ++v2;
      if ( !*(_BYTE *)v2 )
        return;
    }
    v4 = v2;
    do
    {
      *(_BYTE *)v4 = *(_BYTE *)(v4 + 1);
      ++v4;
    }
    while ( *(_BYTE *)v4 );
  }
}