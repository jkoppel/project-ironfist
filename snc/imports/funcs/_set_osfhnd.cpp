{
  char *v2; // edi@2
  unsigned int v3; // esi@2
  HANDLE v4; // ebx@8

  if ( a1 < _nhandle )
  {
    v2 = (char *)__pioinfo + ((signed int)(a1 & 0xFFFFFFE7) >> 3);
    v3 = 36 * (a1 & 0x1F);
    if ( *(_DWORD *)(*(_DWORD *)v2 + v3) == -1 )
    {
      if ( __app_type == 1 )
      {
        if ( a1 )
        {
          if ( a1 == 1 )
          {
            v4 = hHandle;
            SetStdHandle(0xFFFFFFF5u, hHandle);
          }
          else
          {
            if ( a1 != 2 )
              goto LABEL_11;
            v4 = hHandle;
            SetStdHandle(0xFFFFFFF4u, hHandle);
          }
        }
        else
        {
          v4 = hHandle;
          SetStdHandle(0xFFFFFFF6u, hHandle);
        }
LABEL_12:
        *(_DWORD *)(*(_DWORD *)v2 + v3) = v4;
        return 0;
      }
LABEL_11:
      v4 = hHandle;
      goto LABEL_12;
    }
  }
  *_errno() = 9;
  *__doserrno() = 0;
  return -1;
}