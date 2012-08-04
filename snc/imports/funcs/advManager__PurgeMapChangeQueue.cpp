{
  int result; // eax@3
  signed int i; // [sp+10h] [bp-4h]@1
  signed int j; // [sp+10h] [bp-4h]@4

  for ( i = 0; i < 196; ++i )
  {
    result = 5 * i;
    *((_BYTE *)&sMapChangeQueue + 11 * i) = 0;
  }
  for ( j = 0; j < 4; ++j )
  {
    result = 5 * j;
    sMapChangeLastFew[11 * j] = 0;
  }
  return result;
}