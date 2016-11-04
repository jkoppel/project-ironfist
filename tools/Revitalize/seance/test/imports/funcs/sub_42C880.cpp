{
  signed int i; // [sp+10h] [bp-8h]@1
  int v3; // [sp+14h] [bp-4h]@1

  v3 = 0;
  for ( i = 0; i < 48; ++i )
  {
    if ( *((_BYTE *)this + i + 25373) != -1 )
      ++v3;
  }
  return v3;
}
