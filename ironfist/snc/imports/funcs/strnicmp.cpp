{
  int v3; // ecx@1
  unsigned __int8 *v4; // esi@2
  unsigned __int8 *v5; // edi@2
  unsigned __int8 v6; // ah@3
  unsigned __int8 v7; // al@3
  char v8; // cf@11
  int v9; // eax@19
  int v10; // ebx@19
  int v11; // ST04_4@22
  char v12; // cf@22
  int v13; // ebx@29
  int v15; // [sp-4h] [bp-14h]@22
  signed int v16; // [sp+0h] [bp-10h]@17

  v3 = a3;
  if ( a3 )
  {
    v4 = a1;
    v5 = a2;
    if ( *((_DWORD *)&__lc_handle + 2) )
    {
      if ( dword_538E18 > 0 )
      {
        _lock(19);
        v16 = 1;
        v3 = a3;
      }
      else
      {
        ++dword_538E1C;
        v16 = 0;
      }
      v9 = 0;
      v10 = 0;
      do
      {
        LOBYTE(v9) = *v4;
        LOBYTE(v10) = *v5;
        if ( !v9 || !v10 )
          break;
        ++v4;
        ++v5;
        v15 = v3;
        v11 = v9;
        v10 = _tolower_lk(v10);
        v9 = _tolower_lk(v11);
        v12 = v9 < (unsigned int)v10;
        if ( v9 != v10 )
          goto LABEL_25;
        v3 = v15 - 1;
      }
      while ( v15 != 1 );
      v3 = 0;
      v12 = v9 < (unsigned int)v10;
      if ( v9 == v10 )
        goto LABEL_27;
LABEL_25:
      v3 = -1;
      if ( !v12 )
        v3 = 1;
LABEL_27:
      if ( v16 )
      {
        v13 = v3;
        _unlock(19);
        v3 = v13;
      }
      else
      {
        --dword_538E1C;
      }
    }
    else
    {
      do
      {
        v6 = *v4;
        v7 = *v5;
        if ( !*v4 || !v7 )
          break;
        ++v4;
        ++v5;
        if ( v6 >= 0x41u && v6 <= 0x5Au )
          v6 += 32;
        if ( v7 >= 0x41u && v7 <= 0x5Au )
          v7 += 32;
        v8 = v6 < v7;
        if ( v6 != v7 )
          goto LABEL_14;
        --v3;
      }
      while ( v3 );
      v3 = 0;
      v8 = v6 < v7;
      if ( v6 == v7 )
        return v3;
LABEL_14:
      v3 = -1;
      if ( !v8 )
        v3 = 1;
    }
  }
  return v3;
}