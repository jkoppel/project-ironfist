{
  int v4; // ST24_4@4
  int v5; // ST28_4@4
  void *v7; // [sp+Ch] [bp-10h]@1
  signed int v8; // [sp+18h] [bp-4h]@1

  v7 = this;
  v8 = sub_419990((int)((char *)this + 25373), 0, 48);
  if ( v8 != -1 )
  {
    if ( !a4 )
      sub_4C3190(4, 0, a2, a3, -999, 0, 0);
    *((_BYTE *)v7 + v8 + 25373) = v8;
    v4 = (int)((char *)v7 + 8 * v8 + 24989);
    *((_BYTE *)v7 + 8 * v8 + 24989) = v8;
    *(_BYTE *)(v4 + 1) = a2;
    *(_BYTE *)(v4 + 2) = a3;
    *(_BYTE *)(v4 + 3) = 2;
    *(_BYTE *)(v4 + 7) = curPlayerIdx;
    v5 = *(_DWORD *)((char *)v7 + 2878) + 12 * a3 * *(_DWORD *)((char *)v7 + 2886) + 12 * a2;
    *(_BYTE *)(v4 + 4) = *(_BYTE *)(v5 + 9);
    *(_BYTE *)(v4 + 5) = *(_WORD *)(v5 + 4) >> 3;
    *(_BYTE *)(v5 + 9) = -85;
    *(_WORD *)(v5 + 4) = 8 * v8 | *(_WORD *)(v5 + 4) & 7;
  }
  return v8;
}
