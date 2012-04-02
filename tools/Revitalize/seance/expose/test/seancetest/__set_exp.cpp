double __cdecl _set_exp(double a1, __int16 a2)
{
  double v2; // ST00_8@1

  v2 = a1;
  WORD3(v2) = WORD3(a1) & 0x800F | 16 * (a2 + 1022);
  return v2;
}
