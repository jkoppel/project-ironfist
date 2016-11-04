{
  int v4; // ecx@1
  char *v5; // ebx@2
  int v6; // ebp@2
  char *v7; // eax@3
  int v8; // edi@5
  int v9; // eax@7
  void *v10; // ST00_4@8
  int v11; // edi@8
  void *v12; // ST00_4@11
  void *v13; // edi@11
  int v14; // esi@11
  int v15; // esi@13

  v4 = *(_DWORD *)(a3 + 4) - 1;
  if ( a4 )
  {
    v5 = a1;
    v6 = a2;
    if ( a2 == v4 )
    {
      v7 = &a1[(unsigned int)(*(_DWORD *)a3 - 45) < 1] + v4;
      *v7 = 48;
      v7[1] = 0;
    }
  }
  else
  {
    v5 = a1;
    v6 = a2;
  }
  v8 = (int)v5;
  if ( *(_DWORD *)a3 == 45 )
  {
    v8 = (int)(v5 + 1);
    *v5 = 45;
  }
  v9 = *(_DWORD *)(a3 + 4);
  if ( v9 > 0 )
  {
    v11 = v9 + v8;
  }
  else
  {
    v10 = (void *)v8;
    v11 = v8 + 1;
    _shift(v10, 1);
    *(_BYTE *)(v11 - 1) = 48;
  }
  if ( v6 > 0 )
  {
    v12 = (void *)v11;
    v13 = (void *)(v11 + 1);
    _shift(v12, 1);
    *((_BYTE *)v13 - 1) = byte_5211F0;
    v14 = *(_DWORD *)(a3 + 4);
    if ( v14 < 0 )
    {
      if ( a4 )
      {
        v15 = -v14;
      }
      else
      {
        v15 = -v14;
        if ( v15 >= v6 )
          v15 = v6;
      }
      _shift(v13, v15);
      memset(v13, 0x30u, v15);
    }
  }
  return v5;
}
