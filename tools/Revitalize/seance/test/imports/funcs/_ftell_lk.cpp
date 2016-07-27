{
  __int32 v1; // eax@3
  __int32 v2; // edi@3
  int v4; // ebx@5
  unsigned int v5; // edx@7
  unsigned int v6; // ecx@7
  int v7; // eax@18
  int v8; // ebx@20
  int v9; // ebp@20
  unsigned int v10; // eax@22
  int i; // ecx@22
  int v12; // eax@29
  int v13; // [sp+10h] [bp-Ch]@1
  int v14; // [sp+14h] [bp-8h]@7
  int v15; // [sp+18h] [bp-4h]@7

  v13 = *(_DWORD *)(a1 + 16);
  if ( *(_DWORD *)(a1 + 4) < 0 )
    *(_DWORD *)(a1 + 4) = 0;
  v1 = _lseek(v13, 0, 1);
  v2 = v1;
  if ( v1 < 0 )
    return -1;
  v4 = *(_DWORD *)(a1 + 12);
  if ( !(v4 & 0x108) )
    return v1 - *(_DWORD *)(a1 + 4);
  v5 = *(_DWORD *)a1;
  v6 = *(_DWORD *)(a1 + 8);
  v14 = *(_DWORD *)a1 - v6;
  v15 = *(_DWORD *)a1 - v6;
  if ( v4 & 3 )
  {
    if ( *(_BYTE *)(*(int *)((char *)&dword_538E20 + ((v13 & 0xFFFFFFE7) >> 3)) + 36 * (v13 & 0x1F) + 4) & 0x80
      && v6 < v5 )
    {
      do
      {
        if ( *(_BYTE *)v6 == 10 )
          ++v15;
        ++v6;
      }
      while ( v6 < v5 );
    }
  }
  else
  {
    if ( !(v4 & 0x80) )
    {
      *_errno() = 22;
      return -1;
    }
  }
  if ( !v1 )
    return v15;
  if ( v4 & 1 )
  {
    v7 = *(_DWORD *)(a1 + 4);
    if ( !v7 )
    {
      v15 = 0;
      return v2 + v15;
    }
    v8 = v7 + v14;
    v9 = 36 * (v13 & 0x1F);
    if ( *(_BYTE *)(*(int *)((char *)&dword_538E20 + ((v13 & 0xFFFFFFE7) >> 3)) + v9 + 4) & 0x80 )
    {
      if ( _lseek(v13, 0, 2) == v2 )
      {
        v10 = *(_DWORD *)(a1 + 8);
        for ( i = v10 + v8; i > v10; ++v10 )
        {
          if ( *(_BYTE *)v10 == 10 )
            ++v8;
        }
        if ( !(*(_BYTE *)(a1 + 13) & 0x20) )
          goto LABEL_34;
      }
      else
      {
        _lseek(v13, v2, 0);
        if ( (unsigned int)v8 > 0x200 || (v12 = *(_DWORD *)(a1 + 12), !(v12 & 8)) || (v8 = 512, BYTE1(v12) & 4) )
          v8 = *(_DWORD *)(a1 + 24);
        if ( !(*(_BYTE *)(*(int *)((char *)&dword_538E20 + ((v13 & 0xFFFFFFE7) >> 3)) + v9 + 4) & 4) )
          goto LABEL_34;
      }
      ++v8;
    }
LABEL_34:
    v2 -= v8;
  }
  return v2 + v15;
}
