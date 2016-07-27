{
  char *v1; // edi@2
  int v2; // esi@2
  int v3; // eax@2
  DWORD v5; // [sp-8h] [bp-10h]@9
  void *v6; // [sp-4h] [bp-Ch]@9

  if ( a1 < uNumber )
  {
    v1 = (char *)dword_538E20 + ((signed int)(a1 & 0xFFFFFFE7) >> 3);
    v2 = 36 * (a1 & 0x1F);
    v3 = v2 + *(_DWORD *)v1;
    if ( *(_BYTE *)(v3 + 4) & 1 )
    {
      if ( *(_DWORD *)v3 != -1 )
      {
        if ( dword_520D10 == 1 )
        {
          if ( a1 )
          {
            if ( a1 == 1 )
            {
              v6 = 0;
              v5 = -11;
            }
            else
            {
              if ( a1 != 2 )
                goto LABEL_13;
              v6 = 0;
              v5 = -12;
            }
          }
          else
          {
            v6 = 0;
            v5 = -10;
          }
          SetStdHandle(v5, v6);
        }
LABEL_13:
        *(_DWORD *)(*(_DWORD *)v1 + v2) = -1;
        return 0;
      }
    }
  }
  *_errno() = 9;
  *__doserrno() = 0;
  return -1;
}
