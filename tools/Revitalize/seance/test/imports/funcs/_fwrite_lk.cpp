{
  unsigned int v4; // ebp@1
  int v6; // eax@8
  int v7; // edx@9
  int v8; // esi@15
  signed int v9; // eax@17
  int v10; // [sp+10h] [bp-Ch]@1
  const void *v11; // [sp+14h] [bp-8h]@1
  int v12; // [sp+18h] [bp-4h]@4

  v11 = a1;
  v10 = a3 * a2;
  v4 = a3 * a2;
  if ( !(a3 * a2) )
    return 0;
  if ( *(_DWORD *)(a4 + 12) & 0x10C )
    v12 = *(_DWORD *)(a4 + 24);
  else
    v12 = 4096;
  if ( !v10 )
    return a3;
  while ( 1 )
  {
    if ( *(_DWORD *)(a4 + 12) & 0x108 )
    {
      v6 = *(_DWORD *)(a4 + 4);
      if ( v6 )
      {
        v7 = v4;
        if ( v4 >= v6 )
          v7 = *(_DWORD *)(a4 + 4);
        v4 -= v7;
        memcpy(*(void **)a4, v11, v7);
        *(_DWORD *)(a4 + 4) -= v7;
        *(_DWORD *)a4 += v7;
        v11 = (char *)v11 + v7;
        goto LABEL_23;
      }
    }
    if ( v12 > v4 )
      break;
    if ( *(_DWORD *)(a4 + 12) & 0x108 && _flush(a4) )
      return (v10 - v4) / a2;
    v8 = v4;
    if ( v12 )
      v8 = v4 - v4 % v12;
    v9 = _write(*(_DWORD *)(a4 + 16), v11, v8);
    if ( v9 == -1 )
    {
      *(_DWORD *)(a4 + 12) |= 0x20u;
      return (v10 - v4) / a2;
    }
    v4 -= v9;
    v11 = (char *)v11 + v9;
    if ( v9 < (unsigned int)v8 )
    {
      *(_DWORD *)(a4 + 12) |= 0x20u;
      return (v10 - v4) / a2;
    }
LABEL_23:
    if ( !v4 )
      return a3;
  }
  if ( _flsbuf(*(_BYTE *)v11, a4) != -1 )
  {
    --v4;
    v11 = (char *)v11 + 1;
    v12 = *(_DWORD *)(a4 + 24);
    if ( v12 <= 0 )
      v12 = 1;
    goto LABEL_23;
  }
  return (v10 - v4) / a2;
}
