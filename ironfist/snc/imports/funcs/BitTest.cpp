{
  return (*(_DWORD *)&bits[i >> 3] & (1 << (i & 7))) != 0;
}