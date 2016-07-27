{
  signed int result; // eax@3
  int v6; // [sp+10h] [bp-8h]@1
  int v7; // [sp+14h] [bp-4h]@5

  v6 = *(_DWORD *)(this + 2878) + 12 * a3 * *(_DWORD *)(this + 2886) + 12 * a2;
  if ( ((*(_BYTE *)(v6 + 2) >> 2) & 0x3F) != a4 || *(_BYTE *)(v6 + 3) != a5 )
  {
    if ( *(_WORD *)(v6 + 10) )
      v7 = *(_DWORD *)(this + 2882) + 7 * *(_WORD *)(v6 + 10);
    else
      v7 = 0;
    while ( v7 )
    {
      if ( ((*(_BYTE *)(v7 + 2) >> 1) & 0x7F) == a4 && *(_BYTE *)(v7 + 3) == a5 )
        return 1;
      if ( *(_WORD *)v7 )
        v7 = *(_DWORD *)(this + 2882) + 7 * *(_WORD *)v7;
      else
        v7 = 0;
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}
