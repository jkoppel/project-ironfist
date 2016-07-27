{
  void *v3; // eax@1
  signed int result; // eax@2
  DWORD v5; // eax@3
  char v6; // zf@3
  signed int v7; // edi@3
  unsigned __int32 v8; // eax@3

  v3 = (void *)_get_osfhandle(a1);
  if ( v3 == (void *)-1 )
  {
    *_errno() = 9;
    result = -1;
  }
  else
  {
    v5 = SetFilePointer(v3, lDistanceToMove, 0, dwMoveMethod);
    v6 = v5 == -1;
    v7 = v5;
    v8 = 0;
    if ( v6 )
      v8 = GetLastError();
    if ( v8 )
    {
      _dosmaperr(v8);
      result = -1;
    }
    else
    {
      *(_BYTE *)(*(int *)((char *)&dword_538E20 + ((a1 & 0xFFFFFFE7) >> 3)) + 36 * (a1 & 0x1F) + 4) &= 0xFDu;
      result = v7;
    }
  }
  return result;
}
