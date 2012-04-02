// Microsoft VisualC 2-8/net runtime
int __usercall unknown_libname_39<eax>(__int16 a1<cx>, int a2<ebp>, double a3<st1>, long double a4<st0>)
{
  double v4; // qt0@2
  long double v5; // st6@2
  long double v6; // st7@2
  double v7; // st7@3
  char v8; // ch@3
  double v9; // st6@3
  double v10; // qt1@11
  long double v11; // st6@11

  *(_BYTE *)(a2 - 144) = -2;
  if ( HIBYTE(a1) )
  {
    if ( !unknown_libname_75() )
      return unknown_libname_105();
    v10 = a3;
    v11 = a4;
    v6 = v10;
    v5 = fabs(v11);
  }
  else
  {
    v4 = a3;
    v5 = a4;
    v6 = v4;
  }
  v7 = __FYL2X__(v5, v6);
  unknown_libname_74();
  v9 = v5 + 1.0;
  if ( *(_BYTE *)(a2 - 159) & 1 )
  {
    if ( dword_520B2C == 1 )
      unknown_libname_210(v7);
    else
      v9 = 1.0 / v9;
  }
  if ( v8 )
    v9 = -v9;
  return unknown_libname_90(v9);
}
