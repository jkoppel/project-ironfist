signed int __cdecl ungetc_0(int a1, int a2)
{
  int v2; // eax@2
  signed int result; // eax@9
  int v4; // eax@11
  int v5; // eax@12
  int v6; // eax@14
  int v7; // eax@15

  if ( a1 != -1 && ((v2 = *(_DWORD *)(a2 + 12), v2 & 1) || v2 & 0x80 && !(v2 & 2)) )
  {
    if ( !*(_DWORD *)(a2 + 8) )
      _getbuf(a2);
    if ( *(_DWORD *)(a2 + 8) == *(_DWORD *)a2 )
    {
      if ( *(_DWORD *)(a2 + 4) )
        return -1;
      ++*(_DWORD *)a2;
    }
    v4 = *(_DWORD *)a2;
    if ( *(_BYTE *)(a2 + 12) & 0x40 )
    {
      v5 = v4 - 1;
      *(_DWORD *)a2 = v5;
      if ( *(_BYTE *)v5 != (_BYTE)a1 )
      {
        *(_DWORD *)a2 = v5 + 1;
        return -1;
      }
    }
    else
    {
      v6 = v4 - 1;
      *(_DWORD *)a2 = v6;
      *(_BYTE *)v6 = a1;
    }
    ++*(_DWORD *)(a2 + 4);
    v7 = *(_DWORD *)(a2 + 12) & 0xFFFFFFEF;
    *(_DWORD *)(a2 + 12) = v7;
    *(_DWORD *)(a2 + 12) = v7 | 1;
    result = (unsigned __int8)a1;
  }
  else
  {
    result = -1;
  }
  return result;
}
