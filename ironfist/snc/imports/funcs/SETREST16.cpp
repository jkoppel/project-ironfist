{
  int result; // eax@1

  result = a2 | *((_DWORD *)words + a1) & 0xFFFF0000;
  *((_DWORD *)words + a1) = result;
  return result;
}