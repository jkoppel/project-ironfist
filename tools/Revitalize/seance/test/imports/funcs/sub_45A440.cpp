{
  int v3; // [sp+Ch] [bp-Ch]@1
  int v4; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  for ( i = 0; i < 4; ++i )
  {
    if ( sub_45A4B0(v4, v3, (int)&a1cc[4 * i]) )
      return i;
  }
  return -1;
}
