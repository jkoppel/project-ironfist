{
  int v5; // esi@2
  int v6; // edi@2
  int v7; // ebx@2
  int v8; // ecx@2
  int v9; // ecx@6
  int v10; // ebx@10
  int v11; // ebx@12
  signed int v12; // ecx@13
  int v13; // ebx@15
  int v14; // ebx@17

  if ( a5 )
  {
    v5 = a4;
    v6 = a1;
    v7 = a2;
    v8 = 1;
    if ( a2 <= 0 )
      v8 = 0;
    _shift((void *)(a1 + ((unsigned int)(*(_DWORD *)a4 - 45) < 1)), v8);
  }
  else
  {
    v6 = a1;
    v7 = a2;
    v5 = a4;
  }
  v9 = v6;
  if ( *(_DWORD *)v5 == 45 )
  {
    v9 = v6 + 1;
    *(_BYTE *)v6 = 45;
  }
  if ( v7 > 0 )
  {
    *(_BYTE *)v9 = *(_BYTE *)(v9 + 1);
    ++v9;
    *(_BYTE *)v9 = byte_5211F0;
  }
  v10 = v9 + (a5 < 1u) + v7;
  *(_DWORD *)v10 = dword_4EB0F8;
  *(_WORD *)(v10 + 4) = *((_WORD *)&dword_4EB0F8 + 2);
  if ( a3 )
    *(_BYTE *)v10 = 69;
  v11 = v10 + 1;
  if ( **(_BYTE **)(v5 + 12) != 48 )
  {
    v12 = *(_DWORD *)(v5 + 4) - 1;
    if ( v12 < 0 )
    {
      v12 = -v12;
      *(_BYTE *)v11 = 45;
    }
    v13 = v11 + 1;
    if ( v12 >= 100 )
    {
      *(_BYTE *)v13 += v12 / 100;
      v12 %= 100;
    }
    v14 = v13 + 1;
    if ( v12 >= 10 )
    {
      *(_BYTE *)v14 += v12 / 10;
      v12 %= 10;
    }
    *(_BYTE *)(v14 + 1) += v12;
  }
  return v6;
}
