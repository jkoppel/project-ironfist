{
  int v2; // edx@1
  int v3; // ecx@1
  unsigned int v4; // eax@2
  unsigned __int8 v5; // cf@2
  unsigned int v6; // eax@6
  __int16 v8; // ax@16

  v2 = a1;
  v3 = a2;
  if ( !(a1 & 3) )
  {
LABEL_2:
    while ( 1 )
    {
      v4 = *(_DWORD *)v2;
      v5 = (unsigned __int8)*(_DWORD *)v2 < *(_BYTE *)v3;
      if ( (unsigned __int8)*(_DWORD *)v2 != *(_BYTE *)v3 )
        break;
      if ( !(_BYTE)v4 )
        return 0;
      v5 = BYTE1(v4) < *(_BYTE *)(v3 + 1);
      if ( BYTE1(v4) != *(_BYTE *)(v3 + 1) )
        break;
      if ( !BYTE1(v4) )
        return 0;
      v6 = v4 >> 16;
      v5 = (unsigned __int8)v6 < *(_BYTE *)(v3 + 2);
      if ( (_BYTE)v6 != *(_BYTE *)(v3 + 2) )
        break;
      if ( !(_BYTE)v6 )
        return 0;
      v5 = BYTE1(v6) < *(_BYTE *)(v3 + 3);
      if ( BYTE1(v6) != *(_BYTE *)(v3 + 3) )
        break;
      v3 += 4;
      v2 += 4;
      if ( !BYTE1(v6) )
        return 0;
    }
    return -2 * v5 + 1;
  }
  if ( a1 & 1 )
  {
    v2 = a1 + 1;
    v5 = *(_BYTE *)a1 < *(_BYTE *)a2;
    if ( *(_BYTE *)a1 != *(_BYTE *)a2 )
      return -2 * v5 + 1;
    v3 = a2 + 1;
    if ( !*(_BYTE *)a1 )
      return 0;
    if ( !(v2 & 2) )
      goto LABEL_2;
  }
  v8 = *(_WORD *)v2;
  v2 += 2;
  v5 = (unsigned __int8)v8 < *(_BYTE *)v3;
  if ( (_BYTE)v8 != *(_BYTE *)v3 )
    return -2 * v5 + 1;
  if ( !(_BYTE)v8 )
    return 0;
  v5 = HIBYTE(v8) < *(_BYTE *)(v3 + 1);
  if ( HIBYTE(v8) == *(_BYTE *)(v3 + 1) )
  {
    if ( HIBYTE(v8) )
    {
      v3 += 2;
      goto LABEL_2;
    }
    return 0;
  }
  return -2 * v5 + 1;
}