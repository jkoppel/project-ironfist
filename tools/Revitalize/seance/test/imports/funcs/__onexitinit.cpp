{
  void *result; // eax@3

  dword_538F2C = malloc(0x80u);
  if ( !dword_538F2C )
    _amsg_exit(24);
  *(_DWORD *)dword_538F2C = 0;
  result = dword_538F2C;
  dword_538F28 = (int)dword_538F2C;
  return result;
}
