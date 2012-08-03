{
  int v2; // ecx@1
  char v3; // bl@1
  int v4; // edx@1
  char v5; // bl@2

  v2 = *(int *)((char *)__pioinfo + ((a1 & 0xFFFFFFE7) >> 3)) + 36 * (a1 & 0x1F) + 4;
  v3 = *(_BYTE *)v2;
  v4 = *(_BYTE *)v2 & 0x80;
  if ( a2 == 32768 )
  {
    v5 = v3 & 0x7F;
LABEL_5:
    *(_BYTE *)v2 = v5;
    return (unsigned int)v4 < 1 ? 32768 : 16384;
  }
  if ( a2 == 16384 )
  {
    v5 = v3 | 0x80;
    goto LABEL_5;
  }
  *_errno() = 22;
  return -1;
}