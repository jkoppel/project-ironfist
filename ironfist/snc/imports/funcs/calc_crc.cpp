{
  int v3; // ST10_4@1
  int result; // eax@1

  v3 = a1;
  result = calc_crc_long(a2, a3);
  *(_WORD *)v3 = result;
  return result;
}