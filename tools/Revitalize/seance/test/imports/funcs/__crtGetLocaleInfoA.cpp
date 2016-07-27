{
  int result; // eax@1
  int (__stdcall *v6)(LCID, LCTYPE, LPSTR, int); // esi@2
  UINT v7; // edi@11
  int v8; // ebp@13
  int v9; // esi@15
  int v10; // edi@19

  result = dword_5226F0;
  if ( dword_5226F0 )
  {
    v6 = GetLocaleInfoA;
  }
  else
  {
    v6 = GetLocaleInfoA;
    if ( GetLocaleInfoA(0, 1u, 0, 0) )
    {
      result = 2;
    }
    else
    {
      if ( !GetLocaleInfoW(0, 1u, 0, 0) )
        return 0;
      result = 1;
    }
  }
  dword_5226F0 = result;
  if ( result == 2 )
    return v6(Locale, LCType, lpMultiByteStr, cchMultiByte);
  dword_5226F0 = result;
  if ( result == 1 )
  {
    v7 = CodePage;
    if ( !CodePage )
      v7 = ::CodePage;
    v8 = GetLocaleInfoW(Locale, LCType, 0, 0);
    if ( !v8 )
      return 0;
    v9 = malloc(2 * v8);
    if ( !v9 )
      return 0;
    if ( !GetLocaleInfoW(Locale, LCType, (LPWSTR)v9, v8) )
      goto LABEL_20;
    if ( cchMultiByte )
    {
      v10 = WideCharToMultiByte(v7, 0x220u, (LPCWSTR)v9, -1, lpMultiByteStr, cchMultiByte, 0, 0);
      if ( !v10 )
        goto LABEL_20;
    }
    else
    {
      v10 = WideCharToMultiByte(v7, 0x220u, (LPCWSTR)v9, -1, 0, 0, 0, 0);
      if ( !v10 )
      {
LABEL_20:
        free(v9);
        return 0;
      }
    }
    free(v9);
    result = v10;
  }
  return result;
}
