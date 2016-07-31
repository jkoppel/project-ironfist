{
  char result; // al@7
  int v9; // eax@14
  int v10; // ST1C_4@14
  int v11; // eax@27
  int v12; // ST1C_4@27
  char v13; // [sp+10h] [bp-10h]@2
  int v14; // [sp+14h] [bp-Ch]@9
  int v15; // [sp+14h] [bp-Ch]@22
  int j; // [sp+1Ch] [bp-4h]@7
  int i; // [sp+1Ch] [bp-4h]@20

  if ( a6 == 255 )
    v13 = 0;
  else
    v13 = a5;
  if ( a7 )
  {
    if ( *(_BYTE *)(a2 + 7) == 255 || ((*(_BYTE *)(a2 + 6) >> 2) & 0x3F) == a5 )
    {
      *(_BYTE *)(a2 + 6) &= 0xFEu;
      *(_BYTE *)(a2 + 6) &= 0xFDu;
      *(_BYTE *)(a2 + 6) = 4 * v13 | *(_BYTE *)(a2 + 6) & 3;
      result = a6;
      *(_BYTE *)(a2 + 7) = a6;
    }
    else
    {
      result = a2;
      for ( i = *(_WORD *)(a2 + 10); i; i = *(_WORD *)v15 )
      {
        v15 = this->field_4 - i + 8 * i;
        if ( *(_BYTE *)(v15 + 6) == 255 || ((*(_BYTE *)(v15 + 5) >> 2) & 0x3F) == a5 )
        {
          *(_BYTE *)(v15 + 5) &= 0xFEu;
          *(_BYTE *)(v15 + 5) &= 0xFDu;
          *(_BYTE *)(v15 + 5) = 4 * v13 | *(_BYTE *)(v15 + 5) & 3;
          result = a6;
          *(_BYTE *)(v15 + 6) = a6;
          break;
        }
        result = LOBYTE(this->field_4) - i + 8 * i;
      }
      if ( !i )
      {
        v11 = sub_46FA00(this, a3, a4);
        v12 = v11;
        *(_BYTE *)(v11 + 5) = 4 * v13 | *(_BYTE *)(v11 + 5) & 3;
        result = a6;
        *(_BYTE *)(v12 + 6) = a6;
      }
    }
  }
  else
  {
    if ( *(_BYTE *)(a2 + 3) == 255 || ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == a5 )
    {
      *(_BYTE *)(a2 + 2) &= 0xFEu;
      *(_WORD *)(a2 + 4) &= 0xFFFEu;
      *(_WORD *)(a2 + 4) &= 0xFFFDu;
      *(_WORD *)(a2 + 4) &= 0xFFFBu;
      *(_BYTE *)(a2 + 2) = 4 * v13 | *(_BYTE *)(a2 + 2) & 3;
      result = a6;
      *(_BYTE *)(a2 + 3) = a6;
    }
    else
    {
      result = a2;
      for ( j = *(_WORD *)(a2 + 10); j; j = *(_WORD *)v14 )
      {
        v14 = this->field_4 - j + 8 * j;
        if ( *(_BYTE *)(v14 + 3) == 255 || ((*(_BYTE *)(v14 + 2) >> 1) & 0x7F) == a5 )
        {
          *(_BYTE *)(v14 + 2) &= 0xFEu;
          *(_BYTE *)(v14 + 4) &= 0xFEu;
          *(_BYTE *)(v14 + 4) &= 0xFDu;
          *(_BYTE *)(v14 + 4) &= 0xFBu;
          *(_BYTE *)(v14 + 2) = 2 * v13 | *(_BYTE *)(v14 + 2) & 1;
          result = a6;
          *(_BYTE *)(v14 + 3) = a6;
          break;
        }
        result = LOBYTE(this->field_4) - j + 8 * j;
      }
      if ( !j )
      {
        v9 = sub_46FBE0((int)this, a3, a4);
        v10 = v9;
        *(_BYTE *)(v9 + 2) = 2 * v13 | *(_BYTE *)(v9 + 2) & 1;
        result = a6;
        *(_BYTE *)(v10 + 3) = a6;
      }
    }
  }
  return result;
}
