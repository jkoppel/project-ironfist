{
  char *v1; // ebx@2
  int v2; // edi@2
  unsigned __int32 v3; // edi@4
  void *v4; // eax@4

  if ( a1 < uNumber )
  {
    v1 = (char *)dword_538E20 + ((signed int)(a1 & 0xFFFFFFE7) >> 3);
    v2 = 36 * (a1 & 0x1F);
    if ( *(_BYTE *)(*(_DWORD *)v1 + v2 + 4) & 1 )
    {
      _lock_fhandle(a1);
      if ( *(_BYTE *)(*(_DWORD *)v1 + v2 + 4) & 1 )
      {
        v3 = 0;
        v4 = (void *)_get_osfhandle(a1);
        if ( !FlushFileBuffers(v4) )
          v3 = GetLastError();
        if ( !v3 )
          goto LABEL_9;
        *__doserrno() = v3;
      }
      v3 = -1;
      *_errno() = 9;
LABEL_9:
      _unlock_fhandle(a1);
      return v3;
    }
  }
  *_errno() = 9;
  return -1;
}
