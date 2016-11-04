{
  BOOL result; // eax@1
  BOOL (__stdcall *v7)(LCID, DWORD, LPCSTR, int, LPWORD); // esi@2
  LCID v8; // edx@9
  BOOL v9; // ebx@13
  WCHAR *v10; // esi@13
  UINT v11; // edi@13
  size_t v12; // eax@15
  int v13; // ebp@15
  int v14; // eax@17
  WORD CharType; // [sp+12h] [bp-2h]@2

  result = dword_522364;
  if ( dword_522364 )
  {
    v7 = GetStringTypeA;
  }
  else
  {
    v7 = GetStringTypeA;
    if ( GetStringTypeA(0, 1u, SrcStr, 1, &CharType) )
    {
      result = 2;
    }
    else
    {
      if ( !GetStringTypeW(1u, &byte_4EB148, 1, &CharType) )
        return 0;
      result = 1;
    }
  }
  dword_522364 = result;
  if ( result == 2 )
  {
    v8 = Locale;
    if ( !Locale )
      v8 = ::Locale;
    result = v7(v8, dwInfoType, lpMultiByteStr, cchMultiByte, lpCharType);
  }
  else
  {
    dword_522364 = result;
    if ( result == 1 )
    {
      v9 = 0;
      v10 = 0;
      v11 = CodePage;
      if ( !CodePage )
        v11 = ::CodePage;
      v12 = MultiByteToWideChar(v11, 9u, lpMultiByteStr, cchMultiByte, 0, 0);
      v13 = v12;
      if ( v12 )
      {
        v10 = (WCHAR *)calloc(2u, v12);
        if ( v10 )
        {
          v14 = MultiByteToWideChar(v11, 1u, lpMultiByteStr, cchMultiByte, v10, v13);
          if ( v14 )
            v9 = GetStringTypeW(dwInfoType, v10, v14, lpCharType);
        }
      }
      free((BOOL)v10);
      result = v9;
    }
  }
  return result;
}
