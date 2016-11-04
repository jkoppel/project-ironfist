{
  int v0; // esi@1
  signed int v1; // ebp@7
  LPBYTE v2; // edi@7
  HANDLE *v3; // ebx@7
  _UNKNOWN *v4; // esi@10
  int v5; // eax@11
  signed int i; // esi@17
  int v7; // ecx@21
  signed int v8; // esi@23
  int v9; // edi@23
  int v10; // ebx@24
  DWORD v11; // eax@25
  HANDLE v12; // eax@27
  HANDLE v13; // ebp@27
  DWORD v14; // eax@28
  int v15; // eax@29
  struct _STARTUPINFOA StartupInfo; // [sp+10h] [bp-44h]@5

  v0 = malloc(0x480u);
  if ( !v0 )
    _amsg_exit(27);
  dword_538E20 = v0;
  for ( uNumber = 32; dword_538E20 + 1152 > (unsigned int)v0; *(_DWORD *)(v0 - 28) = 0 )
  {
    *(_BYTE *)(v0 + 4) = 0;
    v0 += 36;
    *(_DWORD *)(v0 - 36) = -1;
    *(_BYTE *)(v0 - 31) = 10;
  }
  GetStartupInfoA(&StartupInfo);
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v1 = *(_DWORD *)StartupInfo.lpReserved2;
    v2 = StartupInfo.lpReserved2 + 4;
    v3 = (HANDLE *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( *(_DWORD *)StartupInfo.lpReserved2 >= 2048 )
      v1 = 2048;
    if ( v1 > (signed int)uNumber )
    {
      v4 = &unk_538E24;
      while ( 1 )
      {
        v5 = malloc(0x480u);
        if ( !v5 )
          break;
        *(_DWORD *)v4 = v5;
        uNumber += 32;
        if ( v5 + 1152 > (unsigned int)v5 )
        {
          do
          {
            *(_BYTE *)(v5 + 4) = 0;
            v5 += 36;
            *(_DWORD *)(v5 - 36) = -1;
            *(_BYTE *)(v5 - 31) = 10;
            *(_DWORD *)(v5 - 28) = 0;
          }
          while ( *(_DWORD *)v4 + 1152 > (unsigned int)v5 );
        }
        v4 = (char *)v4 + 4;
        if ( v1 <= (signed int)uNumber )
          goto LABEL_17;
      }
      v1 = uNumber;
    }
LABEL_17:
    for ( i = 0; v1 > i; ++v3 )
    {
      if ( *v3 != (HANDLE)-1 && *v2 & 1 && GetFileType(*v3) )
      {
        v7 = *(int *)((char *)&dword_538E20 + ((i & 0xFFFFFFE7) >> 3)) + 36 * (i & 0x1F);
        *(_DWORD *)v7 = *v3;
        *(_BYTE *)(v7 + 4) = *v2;
      }
      ++i;
      ++v2;
    }
  }
  v8 = 0;
  v9 = 0;
  do
  {
    v10 = v8 + dword_538E20;
    if ( *(_DWORD *)(v8 + dword_538E20) == -1 )
    {
      v11 = -10;
      *(_BYTE *)(v10 + 4) = -127;
      if ( v8 )
        v11 = ((unsigned int)(v9 - 1) < 1) - 12;
      v12 = GetStdHandle(v11);
      v13 = v12;
      if ( v12 != (HANDLE)-1 && (v14 = GetFileType(v12)) != 0 )
      {
        v15 = (unsigned __int8)v14;
        *(_DWORD *)v10 = v13;
        if ( v15 == 2 )
        {
          *(_BYTE *)(v10 + 4) |= 0x40u;
        }
        else
        {
          if ( v15 == 3 )
            *(_BYTE *)(v10 + 4) |= 8u;
        }
      }
      else
      {
        *(_BYTE *)(v10 + 4) |= 0x40u;
      }
    }
    else
    {
      *(_BYTE *)(v10 + 4) |= 0x80u;
    }
    v8 += 36;
    ++v9;
  }
  while ( v8 < 108 );
  return LockResource(uNumber);
}
