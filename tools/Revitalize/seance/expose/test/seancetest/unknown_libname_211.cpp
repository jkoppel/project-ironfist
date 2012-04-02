// Microsoft VisualC 2-8/net runtime
// local variable allocation has failed!
void __fastcall unknown_libname_211(int a1, char a2, _BYTE a3[12], int a4, int a5, int a6, _BYTE a7[12])
{
  int v7; // ecx@11
  double v8; // st7@11
  __int16 v9; // fps@11
  double v10; // st6@11
  char v11; // c0@12
  char v12; // c2@12
  char v13; // c3@12

  if ( !((*(_DWORD *)&a3[6] ^ 0x700) & 0x700)
    && byte_52238C[((*(_DWORD *)&a3[6] ^ 0x700u) >> 11) & 0xF]
    && (*(_DWORD *)&a3[6] & 0x7FFF0000) != 2147418112
    && *(_DWORD *)&a7[6] & 0x7FFF0000
    && (*(_DWORD *)&a7[6] & 0x7FFF0000) != 2147418112
    && !(2 * *(_DWORD *)&a7[4])
    && !(2 * *(_DWORD *)&a3[4]) )
  {
    if ( (*(_WORD *)&a7[8] & 0x7FFFu) > (*(_WORD *)&a3[8] & 0x7FFFu) + 63 )
    {
      v7 = ((a7[8] - a3[8]) & 0x3F | 0x20) + 1;
      v8 = fabs(*(long double *)a3);
      v10 = fabs(*(long double *)a7);
      UNDEF(v9);
      do
      {
        v11 = v10 < v8;
        v12 = 0;
        v13 = v10 == v8;
        if ( !(v9 & 0x100) )
          v10 = v10 - v8;
        UNDEF(v9);
        v8 = v8 * dbl_5223BC;
        --v7;
      }
      while ( v7 );
    }
    else
    {
      while ( (*(_WORD *)&a7[8] & 0x7FFF) - ((*(_WORD *)&a3[8] & 0x7FFF) + 10) >= 0 )
        ;
    }
  }
  if ( a2 & 3 )
  {
    __asm
    {
      fnstenv [esp+28h+var_28]
      fldenv  [esp+28h+var_28]
    }
  }
}
