{
  int v1; // eax@1
  signed int result; // eax@4
  int v3; // eax@5
  signed int v4; // eax@8
  int v5; // edx@10
  int v6; // ecx@11
  int v7; // eax@11
  int v8; // eax@16
  signed int *v9; // ecx@19

  v1 = *(_DWORD *)(a1 + 12);
  if ( !(v1 & 0x83) || v1 & 0x40 )
  {
    result = -1;
  }
  else
  {
    if ( v1 & 2 )
    {
      *(_DWORD *)(a1 + 12) = v1 | 0x20;
      result = -1;
    }
    else
    {
      v3 = v1 | 1;
      *(_DWORD *)(a1 + 12) = v3;
      if ( v3 & 0x10C )
        *(_DWORD *)a1 = *(_DWORD *)(a1 + 8);
      else
        _getbuf(a1);
      v4 = _read(*(_DWORD *)(a1 + 16), *(void **)(a1 + 8), *(_DWORD *)(a1 + 24));
      *(_DWORD *)(a1 + 4) = v4;
      if ( v4 && v4 != -1 )
      {
        v5 = *(_DWORD *)(a1 + 12);
        if ( !(v5 & 0x82) )
        {
          v6 = *(_DWORD *)(a1 + 16);
          v7 = (int)&unk_520E18;
          if ( v6 != -1 )
            v7 = 36 * (v6 & 0x1F) + *(int *)((char *)dword_538E20 + ((*(_DWORD *)(a1 + 16) & 0xFFFFFFE7) >> 3));
          if ( (*(_BYTE *)(v7 + 4) & 0x82) == -126 )
            *(_DWORD *)(a1 + 12) = v5 | 0x2000;
        }
        if ( *(_DWORD *)(a1 + 24) == 512 )
        {
          v8 = *(_DWORD *)(a1 + 12);
          if ( v8 & 8 )
          {
            if ( !(BYTE1(v8) & 4) )
              *(_DWORD *)(a1 + 24) = 4096;
          }
        }
        --*(_DWORD *)(a1 + 4);
        v9 = (signed int *)(*(_DWORD *)a1)++;
        result = *(_BYTE *)v9;
      }
      else
      {
        *(_DWORD *)(a1 + 12) |= (unsigned int)v4 < 1 ? 16 : 32;
        result = -1;
        *(_DWORD *)(a1 + 4) = 0;
      }
    }
  }
  return result;
}
