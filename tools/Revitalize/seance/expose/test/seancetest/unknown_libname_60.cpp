// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_60<st0>(int a1<ebp>)
{
  int v1; // eax@1
  char v2; // ch@1
  char v3; // cl@1
  double result; // st7@2

  v1 = unknown_libname_75();
  if ( v3 )
  {
    *(_BYTE *)(a1 - 144) = 2;
    result = maxlongdouble1;
    if ( v1 == 1 && v2 )
      result = -(double)maxlongdouble1;
  }
  else
  {
    result = 0.0;
    if ( v1 == 1 )
    {
      if ( v2 )
        result = -0.0;
    }
  }
  return result;
}
