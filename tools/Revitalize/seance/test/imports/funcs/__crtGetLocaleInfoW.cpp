{
  int result; // eax@1
  int (__stdcall *v6)(LCID, LCTYPE, LPWSTR, int); // esi@2
  UINT v7; // edi@11
  DWORD v8; // eax@13
  int v9; // ebp@13
  int v10; // esi@15
  int v11; // edi@19

  result = dword_5226EC;
  if ( dword_5226EC )
  {
    v6 = GetLocaleInfoW;
  }
  else
  {
    v6 = GetLocaleInfoW;
    if ( GetLocaleInfoW(0, 1u, 0, 0) )
    {
      result = 1;
    }
    else
    {
      if ( !GetLocaleInfoA(0, 1u, 0, 0) )
        return 0;
      result = 2;
    }
  }
  dword_5226EC = result;
  if ( result == 1 )
    return v6(Locale, LCType, lpWideCharStr, cchWideChar);
  dword_5226EC = result;
  if ( result == 2 )
  {
    v7 = CodePage;
    if ( !CodePage )
      v7 = ::CodePage;
    v8 = GetLocaleInfoA(Locale, LCType, 0, 0);
    v9 = v8;
    if ( !v8 )
      return 0;
    v10 = malloc(v8);
    if ( !v10 )
      return 0;
    if ( !GetLocaleInfoA(Locale, LCType, (LPSTR)v10, v9) )
      goto LABEL_20;
    if ( cchWideChar )
    {
      v11 = MultiByteToWideChar(v7, 1u, (LPCSTR)v10, -1, lpWideCharStr, cchWideChar);
      if ( !v11 )
        goto LABEL_20;
    }
    else
    {
      v11 = MultiByteToWideChar(v7, 1u, (LPCSTR)v10, -1, 0, 0);
      if ( !v11 )
      {
LABEL_20:
        free(v10);
        return 0;
      }
    }
    free(v10);
    result = v11;
  }
  return result;
}
