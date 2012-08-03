{
  int result; // eax@9
  signed int j; // [sp+14h] [bp-4h]@2
  signed int i; // [sp+14h] [bp-4h]@6

  if ( a4 )
  {
    *(_DWORD *)(a1 + 8) = a3 * a4;
    for ( i = 1; i <= a3; ++i )
      *(_DWORD *)(a1 + 4 * i + 28) = a4;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = a3;
    for ( j = 1; j <= a3; ++j )
      *(_DWORD *)(a1 + 4 * j + 28) = 1;
  }
  *(_DWORD *)(a1 + 12) = a3;
  *(_DWORD *)(a1 + 16) = a4;
  *(_DWORD *)(a1 + 20) = a5;
  *(_DWORD *)(a1 + 24) = a2;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 4 * a3 + 32) = 0;
  result = a1;
  *(_DWORD *)a1 = 0;
  return result;
}