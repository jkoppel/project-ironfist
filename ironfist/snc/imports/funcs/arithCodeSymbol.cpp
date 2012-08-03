{
  int v3; // [sp+18h] [bp-14h]@4
  unsigned int v4; // [sp+20h] [bp-Ch]@1
  signed int i; // [sp+24h] [bp-8h]@1
  int v6; // [sp+28h] [bp-4h]@1

  v4 = *(_DWORD *)(a2 + 8);
  v6 = 0;
  for ( i = 1; a3 > i; ++i )
    v6 += *(_DWORD *)(a2 + 4 * i + 28);
  v3 = v6 + *(_DWORD *)(a2 + 4 * a3 + 28);
  bigL += v6 * (bigR / v4);
  if ( v4 <= v3 )
    bigR -= v6 * (bigR / v4);
  else
    bigR = bigR / v4 * (v3 - v6);
  arithCodeRenormalise_Encode(a1);
  if ( (unsigned int)bitsOutstanding > 0x1DCD6500 )
    panic();
}