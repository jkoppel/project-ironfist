{
  double v2; // ST00_8@1

  v2 = a1;
  WORD3(v2) = WORD3(a1) & 0x800F | 16 * (a2 + 1022);
  return v2;
}