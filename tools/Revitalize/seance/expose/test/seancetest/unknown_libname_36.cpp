// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_36<st0>(int a1<ebp>, long double a2<st0>)
{
  __int16 v2; // fps@1
  double result; // st7@1
  char v4; // c2@1

  result = sin(a2);
  UNDEF(v2);
  if ( v4 )
  {
    *(_BYTE *)(a1 - 144) = 5;
    unknown_libname_106();
  }
  return result;
}
