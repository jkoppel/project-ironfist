signed int _sopen(const char *lpFileName, int a2, int a3, ...)
{
  char v3; // bl@4
  int v4; // eax@7
  int v6; // eax@21
  DWORD v7; // ebp@41
  int v8; // edi@52
  HANDLE v9; // eax@54
  void *v10; // ebp@54
  unsigned __int32 v11; // eax@55
  DWORD v12; // eax@56
  unsigned __int32 v13; // eax@57
  char v14; // bl@62
  char *v15; // ebp@62
  int v16; // edx@62
  int v17; // ebx@65
  char v18; // [sp+13h] [bp-19h]@68
  DWORD dwShareMode; // [sp+14h] [bp-18h]@17
  DWORD dwDesiredAccess; // [sp+18h] [bp-14h]@11
  DWORD dwCreationDisposition; // [sp+1Ch] [bp-10h]@36
  struct _SECURITY_ATTRIBUTES SecurityAttributes; // [sp+20h] [bp-Ch]@1

  va_start(va, a3);
  SecurityAttributes.lpSecurityDescriptor = 0;
  SecurityAttributes.bInheritHandle = 0;
  SecurityAttributes.nLength = 12;
  if ( !(a2 & 0x80) )
    SecurityAttributes.bInheritHandle = 1;
  if ( a2 & 0x8000 )
  {
    v3 = 0;
  }
  else
  {
    v3 = -128;
    if ( !(a2 & 0x4000) )
      v3 = (((unsigned int)(dword_521824 - 32768) < 1) - 1) & 0x80;
  }
  v4 = a2 & 3;
  if ( a2 & 3 )
  {
    if ( v4 == 1 )
    {
      dwDesiredAccess = 1073741824;
    }
    else
    {
      if ( v4 != 2 )
      {
        *_errno() = 22;
        *__doserrno() = 0;
        return -1;
      }
      dwDesiredAccess = -1073741824;
    }
  }
  else
  {
    dwDesiredAccess = -2147483648;
  }
  if ( (unsigned int)(a3 - 16) > 0x30 )
  {
LABEL_16:
    *_errno() = 22;
    *__doserrno() = 0;
    return -1;
  }
  switch ( a3 )
  {
    default:
      goto LABEL_16;
    case 16:
      dwShareMode = 0;
      break;
    case 32:
      dwShareMode = 1;
      break;
    case 48:
      dwShareMode = 2;
      break;
    case 64:
      dwShareMode = 3;
      break;
  }
  v6 = a2 & 0x700;
  if ( v6 > 256 )
  {
    if ( v6 <= 768 )
    {
      if ( v6 == 768 )
      {
        dwCreationDisposition = 2;
        goto LABEL_41;
      }
      if ( v6 != 512 )
        goto LABEL_35;
      goto LABEL_38;
    }
    if ( v6 > 1280 )
    {
      if ( v6 == 1536 )
      {
LABEL_38:
        dwCreationDisposition = 5;
        goto LABEL_41;
      }
      if ( v6 != 1792 )
      {
LABEL_35:
        *_errno() = 22;
        *__doserrno() = 0;
        return -1;
      }
    }
    else
    {
      if ( v6 != 1280 )
      {
        if ( v6 != 1024 )
          goto LABEL_35;
        goto LABEL_36;
      }
    }
    dwCreationDisposition = 1;
    goto LABEL_41;
  }
  if ( v6 == 256 )
  {
    dwCreationDisposition = 4;
    goto LABEL_41;
  }
  if ( a2 & 0x700 )
    goto LABEL_35;
LABEL_36:
  dwCreationDisposition = 3;
LABEL_41:
  v7 = 128;
  if ( a2 & 0x100 && !(*(int *)va & ~dword_520B40 & 0x80) )
    v7 = 1;
  if ( a2 & 0x40 )
  {
    dwDesiredAccess |= 0x10000u;
    v7 |= 0x4000000u;
  }
  if ( a2 & 0x1000 )
    v7 |= 0x100u;
  if ( a2 & 0x20 )
  {
    v7 |= 0x8000000u;
  }
  else
  {
    if ( a2 & 0x10 )
      v7 |= 0x10000000u;
  }
  v8 = _alloc_osfhnd();
  if ( v8 == -1 )
  {
    *_errno() = 24;
    *__doserrno() = 0;
    return -1;
  }
  v9 = CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, &SecurityAttributes, dwCreationDisposition, v7, 0);
  v10 = v9;
  if ( v9 == (HANDLE)-1 )
  {
    v11 = GetLastError();
    _dosmaperr(v11);
    _unlock_fhandle(v8);
    return -1;
  }
  v12 = GetFileType(v9);
  if ( !v12 )
  {
    CloseHandle(v10);
    v13 = GetLastError();
    _dosmaperr(v13);
    _unlock_fhandle(v8);
    return -1;
  }
  if ( v12 == 2 )
  {
    v3 |= 0x40u;
  }
  else
  {
    if ( v12 == 3 )
      v3 |= 8u;
  }
  v14 = v3 | 1;
  _set_osfhnd(v8, v10);
  v15 = (char *)&dword_538E20 + ((v8 & 0xFFFFFFE7) >> 3);
  v16 = *(_DWORD *)v15;
  dwDesiredAccess = 36 * (v8 & 0x1F);
  *(_BYTE *)(v16 + dwDesiredAccess + 4) = v14;
  LOBYTE(dwShareMode) = v14 & 0x48;
  if ( !(v14 & 0x48) && v14 & 0x80 && a2 & 2 )
  {
    v17 = _lseek_lk(v8, -1, 2u);
    if ( v17 == -1 )
    {
      if ( *__doserrno() != 131 )
      {
        _close(v8);
        _unlock_fhandle(v8);
        return -1;
      }
    }
    else
    {
      v18 = 0;
      if ( !_read_lk(v8, (unsigned int)&v18, 1u) && v18 == 26 && _chsize_lk(v8, v17) == -1 )
      {
        _close(v8);
        _unlock_fhandle(v8);
        return -1;
      }
      if ( _lseek_lk(v8, 0, 0) == -1 )
      {
        _close(v8);
        _unlock_fhandle(v8);
        return -1;
      }
    }
  }
  if ( !(_BYTE)dwShareMode )
  {
    if ( a2 & 8 )
      *(_BYTE *)(*(_DWORD *)v15 + dwDesiredAccess + 4) |= 0x20u;
  }
  _unlock_fhandle(v8);
  return v8;
}
