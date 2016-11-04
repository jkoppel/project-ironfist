{
  void (__stdcall *v6)(DWORD, LPCWSTR, int, LPWORD); // esi@2
  int v7; // edi@11
  UINT v8; // ebp@11
  size_t v9; // eax@13
  int v10; // ebx@13
  const CHAR *v11; // esi@14
  LCID v12; // ecx@17
  int v13; // ebp@19
  BOOL v14; // eax@19
  int v15; // edx@19
  char v16; // zf@19
  WORD CharType[2]; // [sp+10h] [bp-4h]@2

  if ( dword_522360 )
  {
    v6 = GetStringTypeW;
  }
  else
  {
    v6 = GetStringTypeW;
    if ( GetStringTypeW(1u, &byte_4EB148, 1, CharType) )
    {
      dword_522360 = 1;
    }
    else
    {
      if ( !GetStringTypeA(0, 1u, SrcStr, 1, CharType) )
        return;
      dword_522360 = 2;
    }
  }
  if ( dword_522360 == 1 )
  {
    v6(dwInfoType, lpWideCharStr, cchWideChar, lpCharType);
  }
  else
  {
    if ( dword_522360 == 2 )
    {
      v7 = 0;
      v8 = CodePage;
      *(_DWORD *)CharType = 0;
      if ( !CodePage )
        v8 = ::CodePage;
      v9 = WideCharToMultiByte(v8, 0x220u, lpWideCharStr, cchWideChar, 0, 0, 0, 0);
      v10 = v9;
      if ( v9 )
      {
        v11 = (const CHAR *)calloc(1u, v9);
        if ( v11 )
        {
          if ( WideCharToMultiByte(v8, 0x220u, lpWideCharStr, cchWideChar, (LPSTR)v11, v10, 0, 0) )
          {
            v7 = malloc(2 * v10 + 2);
            if ( v7 )
            {
              v12 = Locale;
              if ( !Locale )
                v12 = ::Locale;
              v13 = v7 + 2 * cchWideChar;
              *(_WORD *)v13 = -1;
              *(_WORD *)(v13 - 2) = -1;
              v14 = GetStringTypeA(v12, dwInfoType, v11, v10, (LPWORD)v7);
              v16 = *(_WORD *)(v13 - 2) == -1;
              *(_DWORD *)CharType = v14;
              if ( v16 || *(_WORD *)v13 != -1 )
                *(_DWORD *)CharType = 0;
              else
                memcpy_0(lpCharType, v15, lpCharType, (const void *)v7, 2 * cchWideChar);
            }
          }
          free((BOOL)v11);
          free(v7);
        }
      }
    }
  }
}
