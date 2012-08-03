{
  int v1; // ST10_4@1
  __int16 result; // ax@1

  v1 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  result = *(_WORD *)(a1 + 4) & 7 | 8 * (v1 | (unsigned __int16)(8 * xPasswordStringsIndex[v1]));
  *(_WORD *)(a1 + 4) = result;
  return result;
}