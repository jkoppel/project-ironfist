{
  int i; // [sp+10h] [bp-4h]@1

  for ( i = a2; a2 + a3 > i; ++i )
  {
    if ( *(_BYTE *)(i + a1) == -1 )
      return i;
  }
  return -1;
}
