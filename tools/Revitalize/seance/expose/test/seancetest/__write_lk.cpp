int __cdecl _write_lk(int a1, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite)
{
  int v3; // ebx@1
  int result; // eax@2
  int v5; // eax@3
  int v6; // ecx@5
  LPCVOID v7; // edi@6
  char *v8; // esi@8
  char v9; // al@10
  DWORD v10; // esi@13
  unsigned __int32 v11; // [sp+10h] [bp-418h]@6
  DWORD NumberOfBytesWritten; // [sp+14h] [bp-414h]@13
  int *v13; // [sp+18h] [bp-410h]@3
  int v14; // [sp+1Ch] [bp-40Ch]@3
  int v15; // [sp+20h] [bp-408h]@1
  char Buffer; // [sp+24h] [bp-404h]@8

  v3 = 0;
  v15 = 0;
  if ( nNumberOfBytesToWrite )
  {
    v13 = (int *)((char *)&dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3));
    v5 = *(int *)((char *)&dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3));
    v14 = 36 * (a1 & 0x1F);
    if ( *(_BYTE *)(v5 + v14 + 4) & 0x20 )
      _lseek_lk(a1, 0, 2u);
    v6 = *v13 + v14;
    if ( *(_BYTE *)(v6 + 4) & 0x80 )
    {
      v11 = 0;
      v7 = lpBuffer;
      while ( v7 - lpBuffer < nNumberOfBytesToWrite )
      {
        v8 = &Buffer;
        do
        {
          if ( v7 - lpBuffer >= nNumberOfBytesToWrite )
            break;
          v9 = *(_BYTE *)v7++;
          if ( v9 == 10 )
          {
            *v8 = 13;
            ++v3;
            ++v8;
          }
          *v8++ = v9;
        }
        while ( (signed int)(v8 - &Buffer) < 1024 );
        v10 = v8 - &Buffer;
        if ( !WriteFile(*(HANDLE *)(*v13 + v14), &Buffer, v10, &NumberOfBytesWritten, 0) )
          goto LABEL_18;
        v15 += NumberOfBytesWritten;
        if ( (signed int)v10 > (signed int)NumberOfBytesWritten )
          break;
      }
    }
    else
    {
      if ( WriteFile(*(HANDLE *)v6, lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0) )
      {
        v11 = 0;
        v15 = NumberOfBytesWritten;
      }
      else
      {
LABEL_18:
        v11 = GetLastError();
      }
    }
    if ( v15 )
    {
      result = v15 - v3;
    }
    else
    {
      if ( v11 )
      {
        if ( v11 == 5 )
        {
          *_errno() = 9;
          *__doserrno() = 5;
          result = -1;
        }
        else
        {
          _dosmaperr(v11);
          result = -1;
        }
      }
      else
      {
        if ( *(_BYTE *)(*v13 + v14 + 4) & 0x40 && *(_BYTE *)lpBuffer == 26 )
        {
          result = 0;
        }
        else
        {
          *_errno() = 28;
          *__doserrno() = 0;
          result = -1;
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
