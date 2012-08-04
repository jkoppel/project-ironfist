{
  int v2; // eax@1
  int result; // eax@1

  v2 = *((_DWORD *)words + a1);
  result = (a2 << 24) | v2 & 0xFFFFFF;
  *((_DWORD *)words + a1) = result;
  return result;
}