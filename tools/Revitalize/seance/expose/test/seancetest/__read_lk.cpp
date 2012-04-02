signed int __cdecl _read_lk(int a1, unsigned int lpBuffer, DWORD nNumberOfBytesToRead)
{
  void *v3; // edx@1
  DWORD v4; // ecx@1
  char *v5; // ebp@2
  int v6; // ebx@2
  int v7; // eax@2
  char v8; // al@4
  int v9; // eax@5
  unsigned __int32 v10; // eax@7
  signed int result; // eax@8
  int v12; // ecx@12
  int v13; // eax@12
  char v14; // cl@12
  char v15; // cl@15
  LPVOID v16; // edi@17
  unsigned int v17; // esi@17
  char v18; // al@18
  int v19; // edx@25
  int v20; // eax@41
  char Buffer; // [sp+13h] [bp-Dh]@25
  DWORD v22; // [sp+14h] [bp-Ch]@1
  DWORD NumberOfBytesRead; // [sp+18h] [bp-8h]@6
  char *v24; // [sp+1Ch] [bp-4h]@17

  v3 = (void *)lpBuffer;
  v4 = nNumberOfBytesToRead;
  v22 = 0;
  if ( !nNumberOfBytesToRead )
    return 0;
  v5 = (char *)&dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3);
  v6 = 36 * (a1 & 0x1F);
  v7 = v6 + *(_DWORD *)v5;
  if ( *(_BYTE *)(v7 + 4) & 2 )
    return 0;
  if ( *(_BYTE *)(v7 + 4) & 0x48 )
  {
    v8 = *(_BYTE *)(v7 + 5);
    if ( v8 != 10 )
    {
      *(_BYTE *)lpBuffer = v8;
      v3 = (void *)(lpBuffer + 1);
      v4 = nNumberOfBytesToRead - 1;
      v9 = *(_DWORD *)v5;
      v22 = 1;
      *(_BYTE *)(v9 + v6 + 5) = 10;
    }
  }
  if ( !ReadFile(*(HANDLE *)(*(_DWORD *)v5 + v6), v3, v4, &NumberOfBytesRead, 0) )
  {
    v10 = GetLastError();
    if ( v10 == 5 )
    {
      *_errno() = 9;
      *__doserrno() = v10;
      result = -1;
    }
    else
    {
      if ( v10 == 109 )
      {
        result = 0;
      }
      else
      {
        _dosmaperr(v10);
        result = -1;
      }
    }
    return result;
  }
  v12 = *(_DWORD *)v5;
  v22 += NumberOfBytesRead;
  v13 = v12 + v6 + 4;
  v14 = *(_BYTE *)v13;
  if ( !(*(_BYTE *)v13 & 0x80) )
    return v22;
  if ( NumberOfBytesRead && *(_BYTE *)lpBuffer == 10 )
    v15 = v14 | 4;
  else
    v15 = v14 & 0xFB;
  v16 = (LPVOID)lpBuffer;
  *(_BYTE *)v13 = v15;
  v17 = lpBuffer;
  v24 = (char *)(lpBuffer + v22);
  if ( v17 >= v17 + v22 )
    return (signed int)((char *)v16 - lpBuffer);
  while ( 1 )
  {
    v18 = *(_BYTE *)v17;
    if ( *(_BYTE *)v17 == 26 )
      break;
    if ( v18 != 13 )
    {
      ++v17;
      *(_BYTE *)v16 = v18;
LABEL_38:
      ++v16;
      goto LABEL_39;
    }
    if ( (unsigned int)(v24 - 1) > v17 )
    {
      if ( *(_BYTE *)(v17 + 1) == 10 )
      {
        v17 += 2;
        *(_BYTE *)v16 = 10;
      }
      else
      {
        ++v17;
        *(_BYTE *)v16 = 13;
      }
      goto LABEL_38;
    }
    ++v17;
    v19 = *(_DWORD *)v5;
    v22 = 0;
    if ( !ReadFile(*(HANDLE *)(v19 + v6), &Buffer, 1u, &NumberOfBytesRead, 0) )
      v22 = GetLastError();
    if ( v22 || !NumberOfBytesRead )
    {
LABEL_37:
      *(_BYTE *)v16 = 13;
      goto LABEL_38;
    }
    if ( *(_BYTE *)(*(_DWORD *)v5 + v6 + 4) & 0x48 )
    {
      if ( Buffer == 10 )
      {
        *(_BYTE *)v16 = 10;
        goto LABEL_38;
      }
      *(_BYTE *)v16++ = 13;
      *(_BYTE *)(*(_DWORD *)v5 + v6 + 5) = Buffer;
    }
    else
    {
      if ( (LPVOID)lpBuffer == v16 && Buffer == 10 )
      {
        *(_BYTE *)v16 = 10;
        goto LABEL_38;
      }
      _lseek_lk(a1, -1, 1u);
      if ( Buffer != 10 )
        goto LABEL_37;
    }
LABEL_39:
    if ( (unsigned int)v24 <= v17 )
      return (signed int)((char *)v16 - lpBuffer);
  }
  v20 = *(_DWORD *)v5 + v6 + 4;
  if ( !(*(_BYTE *)v20 & 0x40) )
    *(_BYTE *)v20 |= 2u;
  return (signed int)((char *)v16 - lpBuffer);
}
