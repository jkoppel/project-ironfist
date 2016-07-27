{
  int v2; // ebx@1
  int v3; // eax@2
  int v4; // ebp@3
  DWORD v5; // eax@5
  int v6; // eax@7
  int v7; // edi@7
  void *v8; // eax@15
  BOOL v9; // eax@15
  unsigned __int32 *v10; // edi@16
  signed int result; // eax@17
  LONG v12; // [sp+10h] [bp-1008h]@1
  int v13; // [sp+14h] [bp-1004h]@4
  char Buffer; // [sp+18h] [bp-1000h]@4

  v2 = 0;
  v12 = _lseek_lk(a1, 0, 1u);
  if ( v12 == -1 || (v3 = _lseek_lk(a1, 0, 2u), v3 == -1) )
  {
    result = -1;
  }
  else
  {
    v4 = a2 - v3;
    if ( a2 - v3 <= 0 )
    {
      if ( a2 - v3 < 0 )
      {
        _lseek_lk(a1, a2, 0);
        v8 = (void *)_get_osfhandle(a1);
        v9 = SetEndOfFile(v8);
        v2 = -((unsigned int)v9 < 1);
        if ( (unsigned int)v9 < 1 )
        {
          *_errno() = 13;
          v10 = __doserrno();
          *v10 = GetLastError();
        }
      }
    }
    else
    {
      memset(&Buffer, 0, 0x1000u);
      v13 = _setmode_lk(a1, 32768);
      while ( 1 )
      {
        v5 = 4096;
        if ( v4 < 4096 )
          v5 = v4;
        v6 = _write_lk(a1, &Buffer, v5);
        v7 = v6;
        if ( v6 == -1 )
          break;
        v4 -= v6;
        if ( v4 <= 0 )
          goto LABEL_13;
      }
      if ( *__doserrno() == 5 )
        *_errno() = 13;
      v2 = v7;
LABEL_13:
      _setmode_lk(a1, v13);
    }
    _lseek_lk(a1, v12, 0);
    result = v2;
  }
  return result;
}
