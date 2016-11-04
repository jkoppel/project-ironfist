{
  int v2; // esi@1
  int v3; // edi@1
  int v4; // eax@1
  int v5; // eax@4
  signed int v6; // ebp@6
  int v7; // eax@6
  int v8; // eax@12
  int v9; // ebx@12
  signed int result; // eax@14
  int v11; // eax@15

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(_DWORD *)(a2 + 12);
  if ( !(v4 & 0x82) || v4 & 0x40 )
  {
    *(_DWORD *)(a2 + 12) = v4 | 0x20;
    result = -1;
  }
  else
  {
    if ( v4 & 1 )
    {
      *(_DWORD *)(a2 + 4) = 0;
      v5 = *(_DWORD *)(v2 + 12);
      if ( !(v5 & 0x10) )
      {
        *(_DWORD *)(v2 + 12) = v5 | 0x20;
        return -1;
      }
      *(_DWORD *)v2 = *(_DWORD *)(v2 + 8);
      *(_DWORD *)(v2 + 12) &= 0xFFFFFFFEu;
    }
    v6 = 0;
    v7 = *(_DWORD *)(v2 + 12) | 2;
    *(_DWORD *)(v2 + 12) = v7;
    *(_DWORD *)(v2 + 12) = v7 & 0xFFFFFFEF;
    *(_DWORD *)(v2 + 4) = 0;
    if ( !(*(_DWORD *)(v2 + 12) & 0x10C)
      && ((_UNKNOWN *)v2 != &unk_521858 && (_UNKNOWN *)v2 != &unk_521878 || !_isatty(v3)) )
      _getbuf(v2);
    if ( *(_DWORD *)(v2 + 12) & 0x108 )
    {
      v8 = *(_DWORD *)(v2 + 8);
      v9 = *(_DWORD *)v2 - v8;
      *(_DWORD *)v2 = v8 + 1;
      *(_DWORD *)(v2 + 4) = *(_DWORD *)(v2 + 24) - 1;
      if ( v9 <= 0 )
      {
        v11 = (int)&unk_520E18;
        if ( v3 != -1 )
          v11 = 36 * (v3 & 0x1F) + *(int *)((char *)&dword_538E20 + ((v3 & 0xFFFFFFE7) >> 3));
        if ( *(_BYTE *)(v11 + 4) & 0x20 )
          _lseek(v3, 0, 2u);
      }
      else
      {
        v6 = _write(v3, *(LPCVOID *)(v2 + 8), v9);
      }
      **(_BYTE **)(v2 + 8) = a1;
    }
    else
    {
      v9 = 1;
      v6 = _write(v3, &a1, 1);
    }
    if ( v6 == v9 )
    {
      result = a1;
    }
    else
    {
      result = -1;
      *(_DWORD *)(v2 + 12) |= 0x20u;
    }
  }
  return result;
}
