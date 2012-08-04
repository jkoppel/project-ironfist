{
  signed int result; // eax@2
  signed int v2; // eax@4
  char *v3; // edi@9
  LPVOID v4; // eax@10
  int v5; // eax@12

  if ( !_isatty(*(_DWORD *)(a1 + 16)) )
    return 0;
  if ( (_UNKNOWN *)a1 == &unk_521858 )
  {
    v2 = 0;
  }
  else
  {
    if ( (_UNKNOWN *)a1 != &File )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( *(_DWORD *)(a1 + 12) & 0x10C )
  {
    result = 0;
  }
  else
  {
    v3 = (char *)&unk_521830 + 4 * v2;
    if ( *(_DWORD *)v3 || (v4 = malloc(0x1000u), (*(_DWORD *)v3 = v4) != 0) )
    {
      v5 = *(_DWORD *)v3;
      *(_DWORD *)(a1 + 8) = *(_DWORD *)v3;
      *(_DWORD *)a1 = v5;
      *(_DWORD *)(a1 + 24) = 4096;
      *(_DWORD *)(a1 + 4) = 4096;
      result = 1;
      *(_DWORD *)(a1 + 12) |= 0x1102u;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}