{
  signed int j; // [sp+10h] [bp-Ch]@5
  signed int i; // [sp+14h] [bp-8h]@1
  char v2; // [sp+18h] [bp-4h]@3

  for ( i = 0; i < 8; ++i )
  {
    v2 = 0;
    while ( !v2 )
    {
      xPasswordStringsIndex[i] = Random(0, 210);
      v2 = 1;
      for ( j = 0; j < i; ++j )
      {
        if ( xPasswordStringsIndex[j] == xPasswordStringsIndex[i] )
          v2 = 0;
      }
    }
  }
}