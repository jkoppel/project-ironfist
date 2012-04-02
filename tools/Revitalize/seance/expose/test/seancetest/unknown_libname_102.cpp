// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_102<st0>(int a1<ebp>, double a2<st1>, double a3<st0>)
{
  double v3; // st6@1
  double v4; // qt0@2
  double v5; // st6@2

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( *(_BYTE *)(a1 - 151) & 0x40
    && (v4 = v3, v5 = a3, a3 = v4, *(double *)(a1 - 158) = v5, v3 = *(double *)(a1 - 158), *(_BYTE *)(a1 - 151) & 0x40) )
    *(_BYTE *)(a1 - 144) = 7;
  else
    *(_BYTE *)(a1 - 144) = 1;
  return a3 + v3;
}
