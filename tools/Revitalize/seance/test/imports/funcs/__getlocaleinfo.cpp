{
  const char *v4; // edi@2
  signed int v5; // ebx@2
  DWORD v6; // eax@2
  DWORD v7; // eax@4
  int v8; // ebp@4
  size_t v9; // ebp@7
  int v10; // eax@7
  signed int result; // eax@10
  CHAR *v12; // edi@17
  CHAR v13; // al@18
  int v14; // eax@19
  __int16 v15; // ax@20
  CHAR MultiByteStr; // [sp+10h] [bp-80h]@2

  if ( a1 == 1 )
  {
    v4 = &MultiByteStr;
    v5 = 0;
    v6 = __crtGetLocaleInfoA(Locale, LCType, &MultiByteStr, 128, 0);
    if ( (v6
       || GetLastError() == 122
       && (v7 = __crtGetLocaleInfoA(Locale, LCType, 0, 0, 0), (v8 = v7) != 0)
       && (v4 = (const char *)malloc(v7)) != 0
       && (v5 = 1, (v6 = __crtGetLocaleInfoA(Locale, LCType, (LPSTR)v4, v8, 0)) != 0))
      && (v9 = v6, v10 = malloc(v6), (*(_DWORD *)a4 = v10) != 0) )
    {
      strncpy((char *)v10, v4, v9);
      if ( v5 )
        free((BOOL)v4);
      result = 0;
    }
    else
    {
      if ( v5 )
        free((BOOL)v4);
      result = -1;
    }
  }
  else
  {
    if ( a1 )
    {
      result = -1;
    }
    else
    {
      if ( __crtGetLocaleInfoW(Locale, LCType, &WideCharStr, 4, 0) )
      {
        v12 = (CHAR *)&WideCharStr;
        *(_BYTE *)a4 = 0;
        do
        {
          v13 = *v12;
          MultiByteStr = *v12;
          if ( cchMultiByte <= 1 )
          {
            v15 = *((_WORD *)off_520FE0 + (unsigned __int8)v13);
            v14 = v15 & 4;
          }
          else
          {
            v14 = _isctype((unsigned __int8)MultiByteStr, 4);
          }
          if ( !v14 )
            break;
          v12 += 2;
          *(_BYTE *)a4 = 10 * *(_BYTE *)a4 + MultiByteStr - 48;
        }
        while ( (unsigned int)v12 < (unsigned int)&unk_537D58 );
        result = 0;
      }
      else
      {
        result = -1;
      }
    }
  }
  return result;
}
