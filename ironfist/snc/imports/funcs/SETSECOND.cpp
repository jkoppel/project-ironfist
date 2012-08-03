{
  int result; // eax@1

  result = (a2 << 16) | *((_DWORD *)words + a1) & 0xFF00FFFF;
  *((_DWORD *)words + a1) = result;
  return result;
}