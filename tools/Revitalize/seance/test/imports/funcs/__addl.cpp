{
  signed int result; // eax@1
  int v4; // esi@1

  result = 0;
  v4 = a1 + a2;
  if ( a1 > a1 + a2 || a2 > v4 )
    result = 1;
  *(_DWORD *)a3 = v4;
  return result;
}
