{
  signed int v2; // ebx@1
  __int16 v3; // dx@1
  int v4; // ecx@1
  int v5; // ecx@1
  unsigned int v6; // ebp@1
  signed __int16 v7; // si@3
  int result; // eax@4
  int v9; // ecx@9
  unsigned int v10; // ebx@10

  v2 = -2147483648;
  v3 = *(_WORD *)(a2 + 6) & 0x8000;
  v4 = *(_DWORD *)(a2 + 4);
  v5 = v4 & 0xFFFFF;
  v6 = *(_DWORD *)a2;
  if ( (unsigned __int16)(*(_WORD *)(a2 + 6) & 0x7FF0) >> 4 )
  {
    if ( (unsigned __int16)(*(_WORD *)(a2 + 6) & 0x7FF0) >> 4 == 2047 )
      v7 = 32767;
    else
      v7 = ((unsigned __int16)(*(_WORD *)(a2 + 6) & 0x7FF0) >> 4) + 15360;
  }
  else
  {
    result = 0;
    if ( !v5 && !v6 )
    {
      *(_WORD *)(a1 + 8) = 0;
      *(_DWORD *)(a1 + 4) = 0;
      *(_DWORD *)a1 = 0;
      return result;
    }
    v7 = 15361;
    v2 = 0;
  }
  result = v6 >> 21;
  v9 = v2 | (v6 >> 21) | (v5 << 11);
  *(_DWORD *)a1 = v6 << 11;
  *(_DWORD *)(a1 + 4) = v9;
  if ( !(v9 & 0x80000000) )
  {
    do
    {
      --v7;
      result = 2 * *(_DWORD *)a1;
      v10 = 2 * *(_DWORD *)(a1 + 4) | ((*(_DWORD *)a1 & 0x80000000u) >> 31);
      *(_DWORD *)a1 = result;
      *(_DWORD *)(a1 + 4) = v10;
    }
    while ( !(v10 & 0x80000000) );
  }
  *(_WORD *)(a1 + 8) = v3 | v7;
  return result;
}
