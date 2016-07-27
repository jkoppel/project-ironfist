{
  int v1; // eax@2
  signed int result; // eax@3

  if ( uNumber > a1
    && (v1 = 36 * (a1 & 0x1F) + *(int *)((char *)dword_538E20 + ((signed int)(a1 & 0xFFFFFFE7) >> 3)),
        *(_BYTE *)(v1 + 4) & 1) )
  {
    result = *(_DWORD *)v1;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    result = -1;
  }
  return result;
}
