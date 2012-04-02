signed int __stdcall sub_4AC120(int a1)
{
  signed int result; // eax@2
  int v2; // [sp+10h] [bp-1Ch]@7
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
    for ( i = pathfinder->field_8 - 1; i >= 1; --i )
    {
      col += byte_4F1DC0[4 * *((_BYTE *)&pathfinder->field_2418 + i)];
      row += byte_4F1DC1[4 * *((_BYTE *)&pathfinder->field_2418 + i)];
      if ( abs(col - *(_DWORD *)(a1 + 25)) <= 7 )
      {
        if ( abs(row - *(_DWORD *)(a1 + 29)) <= 7 )
        {
          v2 = usedToCheckForBoatByCastle(advManager, col, row);
          if ( !(*(_BYTE *)(v2 + 9) & 0x80) )
          {
            if ( !(*(_BYTE *)(v2 + 8) & 8) )
            {
              v8 = col;
              v7 = row;
              v3 = pathfinder->field_8 - i;
            }
          }
        }
      }
    }
    if ( v8 != -1 && v3 > 5 )
    {
      sub_4ABCA0(__PAIR__(v7, v8));
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
