{
  int v3; // [sp+Ch] [bp-24h]@1
  int v4; // [sp+10h] [bp-20h]@1
  unsigned int v5; // [sp+18h] [bp-18h]@1
  unsigned int i; // [sp+1Ch] [bp-14h]@1
  unsigned int v7; // [sp+20h] [bp-10h]@1
  unsigned int v8; // [sp+24h] [bp-Ch]@1
  int v9; // [sp+28h] [bp-8h]@1
  int v10; // [sp+2Ch] [bp-4h]@4

  v3 = a2;
  v4 = a1;
  v8 = *(_DWORD *)(a2 + 8);
  v7 = bigR / v8;
  v5 = minUInt32(v8 - 1, bigD / bigR / v8);
  v9 = 0;
  for ( i = 0; v5 >= i; i += *(_DWORD *)(v3 + 4 * v9 + 28) )
    ++v9;
  v10 = i - *(_DWORD *)(v3 + 4 * v9 + 28);
  bigD -= v10 * v7;
  if ( v8 <= i )
    bigR -= v10 * v7;
  else
    bigR = v7 * (i - v10);
  while ( (unsigned int)bigR <= 0x1000000 )
  {
    bigR *= 2;
    bigD = bsGetBit(v4) + 2 * bigD;
  }
  return v9;
}