{
  int result; // eax@2

  if ( _nhandle > a1 )
    result = *(_BYTE *)(*(int *)((char *)__pioinfo + ((signed int)(a1 & 0xFFFFFFE7) >> 3)) + 36 * (a1 & 0x1F) + 4) & 0x40;
  else
    result = 0;
  return result;
}