// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_96<st0>(int a1<ebp>, double a2<st0>)
{
  double result; // st7@1

  *(double *)(a1 - 158) = a2;
  result = *(double *)(a1 - 158);
  if ( *(_BYTE *)(a1 - 151) & 0x40 )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
    result = result + dbl_521AD4;
  }
  return result;
}
