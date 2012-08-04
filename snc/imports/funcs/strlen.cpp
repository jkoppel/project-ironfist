{
  int v1; // ecx@1
  char v2; // al@2
  int v3; // eax@4
  int v4; // eax@5

  v1 = a1;
  if ( !(a1 & 3) )
    goto LABEL_4;
  do
  {
    v2 = *(_BYTE *)v1++;
    if ( !v2 )
      return v1 - 1 - a1;
  }
  while ( v1 & 3 );
  while ( 1 )
  {
    do
    {
LABEL_4:
      v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
      v1 += 4;
    }
    while ( !(v3 & 0x81010100) );
    v4 = *(_DWORD *)(v1 - 4);
    if ( !(_BYTE)v4 )
      break;
    if ( !BYTE1(v4) )
      return v1 - 3 - a1;
    if ( !(v4 & 0xFF0000) )
      return v1 - 2 - a1;
    if ( !(v4 & 0xFF000000) )
      return v1 - 1 - a1;
  }
  return v1 - 4 - a1;
}