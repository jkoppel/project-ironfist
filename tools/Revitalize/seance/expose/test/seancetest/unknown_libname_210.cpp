// Microsoft VisualC 2-8/net runtime
int __usercall unknown_libname_210<eax>(int a1<eax>, double a2<st1>, double a3<st0>)
{
  int v3; // ST2C_4@1
  _TBYTE v5; // [sp+0h] [bp-30h]@0
  _TBYTE v6; // [sp+Ch] [bp-24h]@0

  v3 = a1;
  *(double *)&v6 = a2;
  *(double *)&v5 = a3;
  unknown_libname_111(v5, v6);
  return v3;
}
