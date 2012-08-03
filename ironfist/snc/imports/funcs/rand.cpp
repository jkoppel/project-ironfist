{
  LPVOID v0; // eax@1
  int v1; // ecx@1

  v0 = _getptd();
  v1 = 214013 * *((_DWORD *)v0 + 5) + 2531011;
  *((_DWORD *)v0 + 5) = v1;
  return (v1 & 0x7FFF0000u) >> 16;
}