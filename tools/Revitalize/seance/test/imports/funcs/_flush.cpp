{
  signed int v1; // edi@1
  const void *v2; // eax@3
  int v3; // eax@5
  signed int result; // eax@8

  v1 = 0;
  if ( (*(_DWORD *)(a1 + 12) & 3) == 2 )
  {
    if ( *(_DWORD *)(a1 + 12) & 0x108 )
    {
      v2 = *(const void **)(a1 + 8);
      if ( *(_DWORD *)a1 - (signed int)v2 > 0 )
      {
        if ( _write(*(_DWORD *)(a1 + 16), v2, *(_DWORD *)a1 - (_DWORD)v2) == *(_DWORD *)a1 - (_DWORD)v2 )
        {
          v3 = *(_DWORD *)(a1 + 12);
          if ( v3 & 0x80 )
            *(_DWORD *)(a1 + 12) = v3 & 0xFFFFFFFD;
        }
        else
        {
          *(_DWORD *)(a1 + 12) |= 0x20u;
          v1 = -1;
        }
      }
    }
  }
  *(_DWORD *)a1 = *(_DWORD *)(a1 + 8);
  result = v1;
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
