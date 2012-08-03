{
  signed int result; // eax@2
  mapCell *v2; // [sp+10h] [bp-1Ch]@7
  int v3; // [sp+14h] [bp-18h]@0
  int i; // [sp+18h] [bp-14h]@3
  int row; // [sp+1Ch] [bp-10h]@3
  int col; // [sp+20h] [bp-Ch]@3
  int v7; // [sp+24h] [bp-8h]@0
  signed int v8; // [sp+28h] [bp-4h]@3

  if ( *(_DWORD *)(a1 + 53) >= 75 )
  {
    v8 = -1;
    col = *(_DWORD *)(a1 + 25);
    row = *(_DWORD *)(a1 + 29);
    for ( i = gpSearchArray->field_8 - 1; i >= 1; --i )
    {
      col += normalDirTable[4 * *((_BYTE *)&gpSearchArray->field_2418 + i)];
      row += byte_4F1DC1[4 * *((_BYTE *)&gpSearchArray->field_2418 + i)];
      if ( abs(col - *(_DWORD *)(a1 + 25)) <= 7 )
      {
        if ( abs(row - *(_DWORD *)(a1 + 29)) <= 7 )
        {
          v2 = advManager::GetCell(gpAdvManager, col, row);
          if ( !(v2->objType & 0x80) )
          {
            if ( !(v2->field_8 & 8) )
            {
              v8 = col;
              v7 = row;
              v3 = gpSearchArray->field_8 - i;
            }
          }
        }
      }
    }
    if ( v8 != -1 && v3 > 5 )
    {
      philAI::DimensionDoorTo(__PAIR__(v7, v8));
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}