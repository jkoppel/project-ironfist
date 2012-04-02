// Microsoft VisualC 2-8/net runtime
double __cdecl unknown_libname_111(_TBYTE a1, _TBYTE a2)
{
  double v2; // st7@1
  double v3; // st6@1
  int v4; // eax@3
  double result; // st7@4

  v2 = a2;
  v3 = a1;
  while ( !__CFADD__(DWORD1(a1), DWORD1(a1)) )
  {
    if ( !*(_QWORD *)&a1 || WORD4(a1) & 0x7FFF )
      return v2 / v3;
    if ( WORD4(a2) & 0x7FFF )
    {
      if ( (WORD4(a2) & 0x7FFF) == 32767 || !__CFADD__(DWORD1(a2), DWORD1(a2)) )
        return v2 / v3;
    }
    else
    {
      if ( __CFADD__(DWORD1(a2), DWORD1(a2)) )
        return v2 / v3;
    }
    *(double *)&a1 = v3 * flt_522388;
    v2 = a2;
  }
  v4 = 2 * DWORD1(a1) ^ 0xE000000;
  if ( v4 & 0xE000000 )
    return v2 / v3;
  if ( !byte_522370[(unsigned int)v4 >> 28] )
    return v2 / v3;
  if ( !(WORD4(a1) & 0x7FFF) || (WORD4(a1) & 0x7FFF) == 32767 )
    return v2 / v3;
  if ( (WORD4(a2) & 0x7FFF) == 1 )
    result = v2 * flt_522384 / (v3 * flt_522384);
  else
    result = v2 * flt_522380 / (v3 * flt_522380);
  return result;
}
