{
  const CHAR *v0; // edi@1
  BOOL v1; // esi@4
  BOOL v2; // ebp@4
  LPVOID v3; // eax@4
  const CHAR *v4; // ecx@8
  signed int v5; // eax@8
  char *v6; // ebx@13
  char v7; // dl@14
  signed int v8; // eax@15
  BOOL v9; // ecx@19
  signed int v10; // eax@19
  int v11; // eax@21
  char *v12; // ebx@23
  char v13; // dl@24
  signed int v14; // eax@25
  int v15; // edx@26
  signed int result; // eax@33
  BOOL lpWideCharStr; // [sp+10h] [bp-18h]@1
  struct _cpinfo CPInfo; // [sp+14h] [bp-14h]@10

  v0 = 0;
  lpWideCharStr = 0;
  if ( !Locale )
  {
    _pctype = &_ctype[1];
    off_520FE4 = &_ctype[1];
    free((BOOL)dword_521B34);
    free((BOOL)dword_521B38);
    result = 0;
    dword_521B34 = 0;
    dword_521B38 = 0;
    return result;
  }
  if ( !__lc_codepage && __getlocaleinfo(0, (unsigned __int16)word_521B4C, 0xBu, (int)&__lc_codepage) )
  {
    v1 = CPInfo.MaxCharSize;
    v2 = CPInfo.MaxCharSize;
LABEL_35:
    free(v1);
    free(v2);
    free((BOOL)v0);
    free(lpWideCharStr);
    return 1;
  }
  v1 = (BOOL)malloc(0x202u);
  v2 = (BOOL)malloc(0x202u);
  v0 = (const CHAR *)malloc(0x101u);
  v3 = malloc(0x202u);
  lpWideCharStr = (BOOL)v3;
  if ( !v1 )
    goto LABEL_35;
  if ( !v2 )
    goto LABEL_35;
  if ( !v0 )
    goto LABEL_35;
  if ( !v3 )
    goto LABEL_35;
  v4 = v0;
  v5 = 0;
  do
    *v4++ = v5++;
  while ( v5 < 256 );
  if ( !GetCPInfo(__lc_codepage, &CPInfo) || CPInfo.MaxCharSize > 2 )
    goto LABEL_35;
  __mb_cur_max = (unsigned __int16)CPInfo.MaxCharSize;
  if ( (signed int)(unsigned __int16)CPInfo.MaxCharSize > 1 )
  {
    v6 = (char *)CPInfo.LeadByte;
    if ( CPInfo.LeadByte[0] )
    {
      do
      {
        v7 = v6[1];
        if ( !v7 )
          break;
        v8 = (unsigned __int8)*v6;
        if ( (unsigned __int8)v7 >= v8 )
        {
          do
            v0[v8++] = 0;
          while ( (unsigned __int8)v6[1] >= v8 );
        }
        v6 += 2;
      }
      while ( *v6 );
    }
  }
  if ( !__crtGetStringTypeA(1u, v0, 256, (LPWORD)(v1 + 2), 0, 0) )
    goto LABEL_35;
  *(_WORD *)v1 = 0;
  v9 = lpWideCharStr;
  v10 = 0;
  do
  {
    *(_WORD *)v9 = v10;
    v9 += 2;
    ++v10;
  }
  while ( v10 < 256 );
  __crtGetStringTypeW(1u, (LPCWSTR)lpWideCharStr, 256, (WORD *)(v2 + 2), 0, 0);
  if ( !v11 )
    goto LABEL_35;
  *(_WORD *)v2 = 0;
  if ( __mb_cur_max > 1 )
  {
    v12 = (char *)CPInfo.LeadByte;
    if ( CPInfo.LeadByte[0] )
    {
      do
      {
        v13 = v12[1];
        if ( !v13 )
          break;
        v14 = (unsigned __int8)*v12;
        if ( (unsigned __int8)v13 >= v14 )
        {
          v15 = v1 + 2 * v14 + 2;
          do
          {
            *(_WORD *)v15 = -32768;
            v15 += 2;
            ++v14;
          }
          while ( (unsigned __int8)v12[1] >= v14 );
        }
        v12 += 2;
      }
      while ( *v12 );
    }
  }
  _pctype = (unsigned __int16 *)(v1 + 2);
  off_520FE4 = (void *)(v2 + 2);
  if ( dword_521B34 )
    free((BOOL)dword_521B34);
  dword_521B34 = (void *)v1;
  if ( dword_521B38 )
    free((BOOL)dword_521B38);
  dword_521B38 = (void *)v2;
  free((BOOL)v0);
  free(lpWideCharStr);
  return 0;
}