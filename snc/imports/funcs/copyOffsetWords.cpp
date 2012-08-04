{
  int result; // eax@3
  signed int i; // [sp+Ch] [bp-4h]@1

  for ( i = 0; i < 16; ++i )
  {
    result = *((_DWORD *)words + i);
    *((_DWORD *)words + i + lastPP) = result;
  }
  return result;
}