// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_99<st0>(int a1<ebp>, double a2<st1>, double a3<st0>)
{
  double v3; // st6@1

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( *(_BYTE *)(a1 - 151) & 0x40 )
    *(_BYTE *)(a1 - 144) = 7;
  else
    *(_BYTE *)(a1 - 144) = 1;
  return a3 + v3;
}
