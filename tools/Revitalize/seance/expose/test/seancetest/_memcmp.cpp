int __cdecl memcmp(int a1, int a2, unsigned int a3)
{
  int result; // eax@1
  int v4; // esi@2
  int v5; // edi@2
  unsigned __int8 v6; // cf@4
  unsigned __int8 v7; // cl@7
  unsigned __int8 v8; // dl@7
  char v9; // zf@10
  unsigned int v10; // ecx@10
  unsigned int v11; // ecx@14
  unsigned int v12; // edx@14
  unsigned int v13; // ecx@16
  unsigned int v14; // edx@16
  int v15; // edx@20
  int v16; // ecx@20
  int v17; // ecx@24
  int v18; // edx@24

  result = a3;
  if ( !a3 )
    return result;
  v4 = a1;
  v5 = a2;
  if ( !(((unsigned __int8)a2 | (unsigned __int8)a1) & 3) )
  {
    result = a3 & 3;
    v10 = a3 >> 2;
    v9 = a3 >> 2 == 0;
    if ( !(a3 >> 2) )
      goto LABEL_28;
    do
    {
      if ( !v10 )
        break;
      v9 = *(_DWORD *)v4 == *(_DWORD *)v5;
      v4 += 4;
      v5 += 4;
      --v10;
    }
    while ( v9 );
    if ( v9 )
    {
LABEL_28:
      if ( !result )
        return result;
      v15 = *(_DWORD *)v4;
      v16 = *(_DWORD *)v5;
      v6 = (unsigned __int8)*(_DWORD *)v4 < (unsigned __int8)*(_DWORD *)v5;
      if ( (unsigned __int8)*(_DWORD *)v4 == (unsigned __int8)*(_DWORD *)v5 )
      {
        --result;
        if ( !result )
          return result;
        v6 = BYTE1(v15) < BYTE1(v16);
        if ( BYTE1(v15) == BYTE1(v16) )
        {
          --result;
          if ( !result )
            return result;
          v17 = v16 & 0xFF0000;
          v18 = v15 & 0xFF0000;
          v6 = v18 < (unsigned int)v17;
          if ( v18 == v17 )
          {
            --result;
            return result;
          }
        }
      }
    }
    else
    {
      v11 = *(_DWORD *)(v4 - 4);
      v12 = *(_DWORD *)(v5 - 4);
      v6 = (unsigned __int8)v11 < (unsigned __int8)v12;
      if ( (_BYTE)v11 == (_BYTE)v12 )
      {
        v6 = BYTE1(v11) < BYTE1(v12);
        if ( BYTE1(v11) == BYTE1(v12) )
        {
          v13 = v11 >> 16;
          v14 = v12 >> 16;
          v6 = (unsigned __int8)v13 < (unsigned __int8)v14;
          if ( (_BYTE)v13 == (_BYTE)v14 )
            v6 = BYTE1(v13) < BYTE1(v14);
        }
      }
    }
    return -v6 - (v6 - 1);
  }
  if ( !(a3 & 1) )
  {
LABEL_6:
    while ( 1 )
    {
      v6 = *(_BYTE *)v4 < *(_BYTE *)v5;
      if ( *(_BYTE *)v4 != *(_BYTE *)v5 )
        break;
      v7 = *(_BYTE *)(v4 + 1);
      v8 = *(_BYTE *)(v5 + 1);
      v6 = v7 < v8;
      if ( v7 != v8 )
        break;
      v5 += 2;
      v4 += 2;
      result -= 2;
      if ( !result )
        return result;
    }
    return -v6 - (v6 - 1);
  }
  v6 = *(_BYTE *)a1 < *(_BYTE *)a2;
  if ( *(_BYTE *)a1 != *(_BYTE *)a2 )
    return -v6 - (v6 - 1);
  v4 = a1 + 1;
  v5 = a2 + 1;
  result = a3 - 1;
  if ( a3 != 1 )
    goto LABEL_6;
  return result;
}
