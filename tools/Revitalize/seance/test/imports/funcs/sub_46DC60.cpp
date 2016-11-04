{
  int v2; // ST14_4@2
  int v3; // ST20_4@3
  int v5; // [sp+Ch] [bp-1Ch]@1
  int v6; // [sp+10h] [bp-18h]@1
  int v7; // [sp+1Ch] [bp-Ch]@1
  unsigned int v8; // [sp+24h] [bp-4h]@1

  v5 = a2;
  v6 = a1;
  v7 = 0;
  v8 = 0;
  while ( 1 )
  {
    v2 = v5--;
    if ( !v2 )
      break;
    v3 = v7 & 0x8000000;
    v7 = *(_BYTE *)v6 + 2 * v7;
    v8 += *(_BYTE *)v6;
    if ( v3 )
      ++v7;
    ++v6;
  }
  return (v8 << 16) + (v8 >> 16) + v7;
}
