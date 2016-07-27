{
  int result; // eax@2

  if ( uNumber > a1 )
    result = *(_BYTE *)(*(int *)((char *)dword_538E20 + ((signed int)(a1 & 0xFFFFFFE7) >> 3)) + 36 * (a1 & 0x1F) + 4) & 0x40;
  else
    result = 0;
  return result;
}
