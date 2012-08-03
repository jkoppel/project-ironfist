{
  int result; // eax@1

  result = (a2 << 8) | *((_DWORD *)words + a1) & 0xFFFF00FF;
  *((_DWORD *)words + a1) = result;
  return result;
}