{
  signed int result; // eax@2
  int v4; // [sp+10h] [bp-8h]@1
  int v5; // [sp+14h] [bp-4h]@4

  v4 = *(_DWORD *)(this + 2878) + 12 * a3 * *(_DWORD *)(this + 2886) + 12 * a2;
  if ( (*(_BYTE *)(v4 + 6) >> 1) & 1 )
  {
    result = 1;
  }
  else
  {
    if ( *(_WORD *)(v4 + 10) )
      v5 = *(_DWORD *)(this + 2882) + 7 * *(_WORD *)(v4 + 10);
    else
      v5 = 0;
    while ( v5 )
    {
      if ( (*(_BYTE *)(v5 + 5) >> 1) & 1 )
        return 1;
      if ( *(_WORD *)v5 )
        v5 = *(_DWORD *)(this + 2882) + 7 * *(_WORD *)v5;
      else
        v5 = 0;
    }
    result = 0;
  }
  return result;
}
