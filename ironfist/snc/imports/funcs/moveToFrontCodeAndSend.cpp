{
  char v2; // ST18_1@11
  void *v3; // [sp+10h] [bp-11Ch]@1
  unsigned __int8 v4; // [sp+14h] [bp-118h]@9
  signed int v5; // [sp+1Ch] [bp-110h]@9
  signed int i; // [sp+20h] [bp-10Ch]@4
  int j; // [sp+20h] [bp-10Ch]@7
  char v8[256]; // [sp+24h] [bp-108h]@6
  unsigned __int8 v9; // [sp+124h] [bp-8h]@9
  int v10; // [sp+128h] [bp-4h]@1

  v3 = a1;
  v10 = 0;
  if ( a2 )
    putInt32(a1, -(origPtr + 1));
  else
    putInt32(a1, origPtr + 1);
  initModels();
  for ( i = 0; i <= 255; ++i )
    v8[i] = i;
  for ( j = 0; last >= j; ++j )
  {
    v4 = *((_DWORD *)words + NORMALISELO(*((_DWORD *)zptr + j) - 1)) >> 24;
    v5 = 0;
    v9 = v8[0];
    while ( v9 != v4 )
    {
      ++v5;
      v2 = v9;
      v9 = v8[v5];
      v8[v5] = v2;
    }
    v8[0] = v9;
    if ( v5 )
    {
      sendZeroes(v3, v10);
      v10 = 0;
      sendMTFVal(v3, v5);
    }
    else
    {
      ++v10;
    }
  }
  sendZeroes(v3, v10);
  sendMTFVal(v3, 259);
}