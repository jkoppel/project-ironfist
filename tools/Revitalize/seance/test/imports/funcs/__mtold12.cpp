{
  signed __int16 v3; // di@1
  int v4; // ebx@1
  int v5; // ebp@2
  int v6; // edx@3
  int v7; // eax@3
  int v8; // ecx@3
  int result; // eax@3
  int v10; // eax@5
  int v11; // ecx@5
  unsigned int v12; // ebx@5
  int v13; // edx@5
  int v14; // [sp+10h] [bp-Ch]@3
  int v15; // [sp+14h] [bp-8h]@3
  int v16; // [sp+18h] [bp-4h]@3

  v3 = 16462;
  v4 = a2;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  if ( a2 )
  {
    v5 = a1;
    do
    {
      v6 = *(_DWORD *)(a3 + 4);
      v14 = *(_DWORD *)a3;
      v7 = *(_DWORD *)(a3 + 8);
      v15 = v6;
      v16 = v7;
      __shl_12(a3);
      --v4;
      ++v5;
      __shl_12(a3);
      __add_12(a3, (int)&v14);
      __shl_12(a3);
      v8 = *(_BYTE *)(v5 - 1);
      v15 = 0;
      v16 = 0;
      v14 = v8;
      result = __add_12(a3, (int)&v14);
    }
    while ( v4 );
  }
  if ( !*(_DWORD *)(a3 + 8) )
  {
    do
    {
      v3 -= 16;
      v10 = *(_DWORD *)a3;
      v11 = *(_DWORD *)(a3 + 4) >> 16;
      v12 = *(_DWORD *)a3;
      v13 = *(_DWORD *)(a3 + 4) << 16;
      *(_DWORD *)(a3 + 8) = v11;
      result = v10 << 16;
      *(_DWORD *)(a3 + 4) = (v12 >> 16) | v13;
      *(_DWORD *)a3 = result;
    }
    while ( !v11 );
  }
  for ( ; !(*(_BYTE *)(a3 + 9) & 0x80); result = __shl_12(a3) )
    --v3;
  *(_WORD *)(a3 + 10) = v3;
  return result;
}
