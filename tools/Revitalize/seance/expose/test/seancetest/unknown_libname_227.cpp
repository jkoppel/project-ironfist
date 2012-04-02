// Microsoft VisualC 2-8/net runtime
// local variable allocation has failed!
void __fastcall unknown_libname_227(int a1, char a2, _BYTE a3[12], int a4, int a5, int a6, _BYTE a7[12])
{
  int v7; // eax@8
  int v8; // ebx@8
  unsigned __int8 v9; // cf@8
  int v10; // ebx@8
  int v11; // ecx@11
  double v12; // st7@11
  __int16 v13; // fps@11
  double v14; // st6@11
  char v15; // c0@12
  char v16; // c2@12
  char v17; // c3@12

  if ( !((*(_DWORD *)&a3[6] ^ 0x700) & 0x700)
    && byte_52238C[((*(_DWORD *)&a3[6] ^ 0x700u) >> 11) & 0xF]
    && (*(_DWORD *)&a3[6] & 0x7FFF0000) != 2147418112
    && *(_DWORD *)&a7[6] & 0x7FFF0000
    && (*(_DWORD *)&a7[6] & 0x7FFF0000) != 2147418112
    && !(2 * *(_DWORD *)&a7[4])
    && !(2 * *(_DWORD *)&a3[4]) )
  {
    v7 = (*(_WORD *)&a3[8] & 0x7FFF) + 63;
    v8 = *(_WORD *)&a7[8] & 0x7FFF;
    v9 = v8 < (unsigned int)v7;
    v10 = v8 - v7;
    if ( v9 | v10 == 0 )
    {
      while ( (*(_WORD *)&a7[8] & 0x7FFF) - ((*(_WORD *)&a3[8] & 0x7FFF) + 10) >= 0 )
        ;
    }
    else
    {
      v11 = ((a7[8] - a3[8]) & 0x3F | 0x20) + 1;
      v12 = fabs(*(long double *)a3);
      v14 = fabs(*(long double *)a7);
      UNDEF(v13);
      do
      {
        v15 = v14 < v12;
        v16 = 0;
        v17 = v14 == v12;
        if ( !(v13 & 0x100) )
          v14 = v14 - v12;
        UNDEF(v13);
        v12 = v12 * dbl_5223BC;
        --v11;
      }
      while ( v11 );
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
