{
  int v3; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@1

  v3 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( (signed int)*(_WORD *)(a1 + 2 * i + 5) > 0 )
      v3 += *(_WORD *)(a1 + 2 * i + 5) * creature_table[*(_BYTE *)(i + a1)].hp;
  }
  if ( a2 )
    v3 += 500;
  return v3;
}
