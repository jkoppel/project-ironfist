int __cdecl fix_grouping(int a1)
{
  int result; // eax@1
  char v2; // cl@2
  int v3; // edx@7

  result = a1;
  while ( *(_BYTE *)result )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *(_BYTE *)result;
        if ( *(_BYTE *)result < 48 || v2 > 57 )
          break;
        *(_BYTE *)result++ = v2 - 48;
        if ( !*(_BYTE *)result )
          return result;
      }
      if ( v2 == 59 )
        break;
      ++result;
      if ( !*(_BYTE *)result )
        return result;
    }
    v3 = result;
    do
    {
      *(_BYTE *)v3 = *(_BYTE *)(v3 + 1);
      ++v3;
    }
    while ( *(_BYTE *)v3 );
  }
  return result;
}
