// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_79<st0>(double a1<st1>, double a2<st0>)
{
  double *v3; // ST10_4@1
  int v4; // eax@1
  double result; // st7@1
  double v6; // [sp+14h] [bp-78h]@1

  _ESI = &v6;
  v3 = &v6;
  __asm { fsave   byte ptr [esi+8] }
  v4 = _powhlp(a2, a1, &v6);
  __asm { frstor  byte ptr [esi+8] }
  result = v6;
  if ( v4 )
    unknown_libname_107();
  return result;
}
