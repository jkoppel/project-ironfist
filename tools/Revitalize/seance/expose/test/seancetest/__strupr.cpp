LPCSTR __cdecl _strupr(LPCSTR lpMultiByteStr)
{
  const char *v1; // ebp@1
  LPCSTR j; // eax@2
  const CHAR v3; // cl@3
  LPCSTR result; // eax@7
  LPCSTR i; // eax@15
  const CHAR v6; // cl@16
  size_t v7; // eax@21
  int v8; // esi@21
  signed int v9; // [sp+10h] [bp-4h]@9

  v1 = 0;
  if ( Locale )
  {
    if ( dword_538E18 )
    {
      _lock(19);
      v9 = 1;
    }
    else
    {
      v9 = 0;
      ++dword_538E1C;
    }
    if ( Locale )
    {
      v7 = __crtLCMapStringA(Locale, 0x200u, lpMultiByteStr, -1, 0, 0, 0);
      v8 = v7;
      if ( v7 )
      {
        v1 = (const char *)malloc(v7);
        if ( v1 )
        {
          if ( __crtLCMapStringA(Locale, 0x200u, lpMultiByteStr, -1, (LPWSTR)v1, v8, 0) )
            strcpy((char *)lpMultiByteStr, v1);
        }
      }
      if ( v9 )
        _unlock(19);
      else
        --dword_538E1C;
      free((void *)v1);
      result = lpMultiByteStr;
    }
    else
    {
      if ( v9 )
        _unlock(19);
      else
        --dword_538E1C;
      for ( i = lpMultiByteStr; *i; ++i )
      {
        v6 = *i;
        if ( *i >= 97 && v6 <= 122 )
          *i = v6 - 32;
      }
      result = lpMultiByteStr;
    }
  }
  else
  {
    for ( j = lpMultiByteStr; *j; ++j )
    {
      v3 = *j;
      if ( *j >= 97 )
      {
        if ( v3 <= 122 )
          *j = v3 - 32;
      }
    }
    result = lpMultiByteStr;
  }
  return result;
}
