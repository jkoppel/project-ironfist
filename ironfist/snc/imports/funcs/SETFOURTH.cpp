{
  int result; // eax@1

  result = a2 | *((_DWORD *)words + a1) & 0xFFFFFF00;
  *((_DWORD *)words + a1) = result;
  return result;
}