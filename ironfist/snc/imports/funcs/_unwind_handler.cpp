{
  signed int result; // eax@1

  result = 1;
  if ( *(_DWORD *)(a1 + 4) & 6 )
  {
    *(_DWORD *)a4 = a2;
    result = 3;
  }
  return result;
}