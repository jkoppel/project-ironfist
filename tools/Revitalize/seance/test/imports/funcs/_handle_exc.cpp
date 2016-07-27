{
  int v3; // edi@1
  int v4; // eax@9
  signed int v5; // ebp@30
  int v6; // ecx@33
  signed int v7; // edx@35
  int v8; // eax@38
  double v10; // [sp+10h] [bp-Ch]@33
  int v11; // [sp+18h] [bp-4h]@33

  v3 = a1 & 0x1F;
  if ( a1 & 8 && a3 & 1 )
  {
    v3 &= 0xFFFFFFF7u;
    _set_statfp(1);
  }
  else
  {
    if ( a1 & 4 && a3 & 4 )
    {
      v3 &= 0xFFFFFFFBu;
      _set_statfp(4);
    }
    else
    {
      if ( a1 & 1 && a3 & 8 )
      {
        _set_statfp(8);
        v4 = a3 & 0xC00;
        if ( (unsigned int)v4 > 0x400 )
        {
          if ( v4 == 2048 )
          {
            if ( *(double *)a2 <= 0.0 )
            {
              v3 &= 0xFFFFFFFEu;
              *(double *)a2 = -maxdouble4;
            }
            else
            {
              v3 &= 0xFFFFFFFEu;
              *(_QWORD *)a2 = *(_QWORD *)&maxdouble3;
            }
          }
          else
          {
            if ( v4 == 3072 )
            {
              if ( *(double *)a2 <= 0.0 )
              {
                v3 &= 0xFFFFFFFEu;
                *(double *)a2 = -maxdouble4;
              }
              else
              {
                v3 &= 0xFFFFFFFEu;
                *(_QWORD *)a2 = *(_QWORD *)&maxdouble4;
              }
            }
            else
            {
              v3 &= 0xFFFFFFFEu;
            }
          }
        }
        else
        {
          if ( v4 == 1024 )
          {
            if ( *(double *)a2 <= 0.0 )
            {
              v3 &= 0xFFFFFFFEu;
              *(double *)a2 = -maxdouble3;
            }
            else
            {
              v3 &= 0xFFFFFFFEu;
              *(_QWORD *)a2 = *(_QWORD *)&maxdouble4;
            }
          }
          else
          {
            if ( a3 & 0xC00 )
            {
              v3 &= 0xFFFFFFFEu;
            }
            else
            {
              if ( *(double *)a2 <= 0.0 )
              {
                v3 &= 0xFFFFFFFEu;
                *(double *)a2 = -maxdouble3;
              }
              else
              {
                v3 &= 0xFFFFFFFEu;
                *(_QWORD *)a2 = *(_QWORD *)&maxdouble3;
              }
            }
          }
        }
      }
      else
      {
        if ( a1 & 2 && a3 & 0x10 )
        {
          v5 = 0;
          if ( a1 & 0x10 )
            v5 = 1;
          if ( *(_DWORD *)a2 | *(_DWORD *)(a2 + 4) & 0x7FFFFFFF )
          {
            v10 = _decomp(*(double *)a2, &v11);
            v6 = v11 - 1536;
            if ( v11 - 1536 >= -1074 )
            {
              v7 = 1;
              if ( v10 >= 0.0 )
                v7 = 0;
              WORD3(v10) = BYTE6(v10) & 0xF;
              BYTE6(v10) |= 0x10u;
              if ( v6 < -1021 )
              {
                v8 = -1021 - v6;
                do
                {
                  if ( LOBYTE(v10) & 1 && !v5 )
                    v5 = 1;
                  LODWORD(v10) >>= 1;
                  if ( BYTE4(v10) & 1 )
                    LODWORD(v10) |= 0x80000000u;
                  HIDWORD(v10) >>= 1;
                  --v8;
                }
                while ( v8 );
              }
              if ( v7 )
                v10 = -v10;
            }
            else
            {
              v5 = 1;
              v10 = 0.0;
            }
            *(double *)a2 = v10;
          }
          else
          {
            v5 = 1;
          }
          if ( v5 )
            _set_statfp(16);
          v3 &= 0xFFFFFFFDu;
        }
      }
    }
  }
  if ( a1 & 0x10 && a3 & 0x20 )
  {
    v3 &= 0xFFFFFFEFu;
    _set_statfp(32);
  }
  return (unsigned int)v3 < 1;
}
