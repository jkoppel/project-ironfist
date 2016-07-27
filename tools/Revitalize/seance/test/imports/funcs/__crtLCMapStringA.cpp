{
  int result; // eax@1
  int (__stdcall *v8)(LCID, DWORD, LPCSTR, int, LPSTR, int); // esi@2
  int v9; // edi@8
  int v10; // esi@13
  int v11; // ebp@15
  int v12; // ebx@17
  int v13; // edi@20

  result = dword_520FB0;
  if ( dword_520FB0 )
  {
    v8 = LCMapStringA;
  }
  else
  {
    v8 = LCMapStringA;
    if ( LCMapStringA(0, 0x100u, SrcStr, 1, 0, 0) )
    {
      result = 2;
    }
    else
    {
      if ( !LCMapStringW(0, 0x100u, &byte_4EB148, 1, 0, 0) )
        return 0;
      result = 1;
    }
  }
  v9 = cchMultiByte;
  dword_520FB0 = result;
  if ( cchMultiByte > 0 )
  {
    v9 = strncnt(lpMultiByteStr, cchMultiByte);
    result = dword_520FB0;
  }
  dword_520FB0 = result;
  if ( result == 2 )
    return v8(Locale, dwMapFlags, lpMultiByteStr, v9, lpDestStr, cchDest);
  dword_520FB0 = result;
  if ( result == 1 )
  {
    v10 = 0;
    if ( !CodePage )
      CodePage = ::CodePage;
    v11 = MultiByteToWideChar(CodePage, 9u, lpMultiByteStr, v9, 0, 0);
    if ( !v11 )
      return 0;
    v12 = malloc(2 * v11);
    if ( !v12 )
      return 0;
    if ( !MultiByteToWideChar(CodePage, 1u, lpMultiByteStr, v9, (LPWSTR)v12, v11) )
      goto LABEL_25;
    v13 = LCMapStringW(Locale, dwMapFlags, (LPCWSTR)v12, v11, 0, 0);
    if ( !v13 )
      goto LABEL_25;
    if ( BYTE1(dwMapFlags) & 4 )
    {
      if ( cchDest
        && (cchDest < v13 || !LCMapStringW(Locale, dwMapFlags, (LPCWSTR)v12, v11, (LPWSTR)lpDestStr, cchDest)) )
        goto LABEL_25;
LABEL_33:
      free(v12);
      free(v10);
      return v13;
    }
    v10 = malloc(2 * v13);
    if ( !v10 || !LCMapStringW(Locale, dwMapFlags, (LPCWSTR)v12, v11, (LPWSTR)v10, v13) )
      goto LABEL_25;
    if ( cchDest )
    {
      v13 = WideCharToMultiByte(CodePage, 0x220u, (LPCWSTR)v10, v13, lpDestStr, cchDest, 0, 0);
      if ( v13 )
        goto LABEL_33;
    }
    else
    {
      v13 = WideCharToMultiByte(CodePage, 0x220u, (LPCWSTR)v10, v13, 0, 0, 0, 0);
      if ( v13 )
        goto LABEL_33;
    }
LABEL_25:
    free(v12);
    free(v10);
    result = 0;
  }
  return result;
}
