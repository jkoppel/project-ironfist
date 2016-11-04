{
  int v2; // ecx@1
  __int16 v3; // fps@1
  float v4; // ST1C_4@2
  char v5; // c0@1
  float v7; // [sp+18h] [bp-8h]@1

  v7 = a2;
  HIWORD(v2) = 0;
  UNDEF(v3);
  if ( v5 )
  {
    LOWORD(v2) = *(_WORD *)(a1 + 194);
    v4 = (double)(*(_DWORD *)(a1 + 150) * v2 - *(_DWORD *)(a1 + 162));
    v7 = v4;
  }
  if ( *(_BYTE *)(a1 + 208) & 4 )
    v7 = v7 * 1.3;
  if ( *(_BYTE *)(a1 + 208) & 2 )
    v7 = v7 * 1.3;
  return (double)(*(_WORD *)(a1 + 194) + 100) * v7 / 100.0;
}
