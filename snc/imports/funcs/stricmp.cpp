{
  char *v2; // esi@1
  char *v3; // edi@1
  char result; // al@2
  char v5; // ah@4
  unsigned __int8 v6; // ah@5
  char v7; // t0@5
  int v8; // eax@11
  int v9; // ebx@11
  int v10; // ST04_4@14
  char v11; // bl@16
  signed int v12; // [sp+0h] [bp-10h]@9

  v2 = a2;
  v3 = a1;
  if ( *((_DWORD *)&__lc_handle + 2) )
  {
    if ( dword_538E18 > 0 )
    {
      _lock(19);
      v12 = 1;
    }
    else
    {
      ++dword_538E1C;
      v12 = 0;
    }
    v8 = 255;
    v9 = 0;
    while ( (_BYTE)v8 )
    {
      LOBYTE(v8) = *v2++;
      LOBYTE(v9) = *v3++;
      if ( (_BYTE)v8 != (_BYTE)v9 )
      {
        v10 = v8;
        v9 = _tolower_lk(v9);
        v8 = _tolower_lk(v10);
        if ( (_BYTE)v9 != (_BYTE)v8 )
        {
          v8 = -((unsigned __int8)v9 < (unsigned __int8)v8) - (((unsigned __int8)v9 < (unsigned __int8)v8) - 1);
          break;
        }
      }
    }
    v11 = v8;
    if ( v12 )
      _unlock(19);
    else
      --dword_538E1C;
    result = v11;
  }
  else
  {
    result = -1;
    while ( result )
    {
      result = *v2++;
      v5 = *v3++;
      if ( v5 != result )
      {
        v7 = v5;
        v6 = ((unsigned __int8)(result - 65) < 0x1Au ? 0x20 : 0) + result - 65 + 65;
        result = ((unsigned __int8)(v7 - 65) < 0x1Au ? 0x20 : 0) + v7 - 65 + 65;
        if ( result != v6 )
          return -(result < v6) - ((result < v6) - 1);
      }
    }
  }
  return result;
}