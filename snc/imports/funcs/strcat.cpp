{
  char *v2; // ecx@1
  char v3; // al@2
  int v4; // eax@4
  int v5; // eax@5
  int v6; // edi@9
  char *v7; // ecx@13
  int v8; // edx@14
  int v9; // eax@18
  char *result; // eax@23

  v2 = a1;
  if ( !((unsigned __int8)a1 & 3) )
    goto LABEL_4;
  do
  {
    v3 = *v2++;
    if ( !v3 )
    {
LABEL_9:
      v6 = (int)(v2 - 1);
      goto LABEL_13;
    }
  }
  while ( (unsigned __int8)v2 & 3 );
  while ( 1 )
  {
    do
    {
LABEL_4:
      v4 = (*(_DWORD *)v2 + 2130640639) ^ ~*(_DWORD *)v2;
      v2 += 4;
    }
    while ( !(v4 & 0x81010100) );
    v5 = *((_DWORD *)v2 - 1);
    if ( !(_BYTE)v5 )
      break;
    if ( !BYTE1(v5) )
    {
      v6 = (int)(v2 - 3);
      goto LABEL_13;
    }
    if ( !(v5 & 0xFF0000) )
    {
      v6 = (int)(v2 - 2);
      goto LABEL_13;
    }
    if ( !(v5 & 0xFF000000) )
      goto LABEL_9;
  }
  v6 = (int)(v2 - 4);
LABEL_13:
  v7 = a2;
  if ( !((unsigned __int8)a2 & 3) )
    goto LABEL_18;
  while ( 1 )
  {
    LOBYTE(v8) = *v7++;
    if ( !(_BYTE)v8 )
      break;
    *(_BYTE *)v6++ = v8;
    if ( !((unsigned __int8)v7 & 3) )
    {
      while ( 1 )
      {
LABEL_18:
        v9 = (*(_DWORD *)v7 + 2130640639) ^ ~*(_DWORD *)v7;
        v8 = *(_DWORD *)v7;
        v7 += 4;
        if ( v9 & 0x81010100 )
        {
          if ( !(_BYTE)v8 )
            goto LABEL_26;
          if ( !BYTE1(v8) )
          {
            *(_WORD *)v6 = v8;
            return a1;
          }
          if ( !(v8 & 0xFF0000) )
          {
            *(_WORD *)v6 = v8;
            result = a1;
            *(_BYTE *)(v6 + 2) = 0;
            return result;
          }
          if ( !(v8 & 0xFF000000) )
          {
            *(_DWORD *)v6 = v8;
            return a1;
          }
        }
        *(_DWORD *)v6 = v8;
        v6 += 4;
      }
    }
  }
LABEL_26:
  *(_BYTE *)v6 = v8;
  return a1;
}