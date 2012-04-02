signed int __stdcall sub_4AB290(int a1)
{
  signed int result; // eax@2
  signed int v2; // [sp+18h] [bp-24h]@1
  int v3; // [sp+1Ch] [bp-20h]@16
  int v4; // [sp+20h] [bp-1Ch]@1
  int v5; // [sp+24h] [bp-18h]@1
  int row; // [sp+28h] [bp-14h]@6
  int col; // [sp+2Ch] [bp-10h]@6
  int v8; // [sp+30h] [bp-Ch]@16
  int v9; // [sp+34h] [bp-8h]@1
  int i; // [sp+38h] [bp-4h]@3

  v9 = -1;
  v5 = dword_5305C0;
  v4 = dword_5306D8;
  dword_5305C0 = 1065353216;
  dword_5306D8 = 1065353216;
  v2 = 100;
  if ( (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, dword_51D5BC->x, dword_51D5BC->y) + 9) & 0x7F) == 36 )
  {
    result = 0;
  }
  else
  {
    for ( i = 0; i < 8; ++i )
    {
      if ( sub_4C1CB0((int)advManager, (int)dword_51D5BC, i) )
      {
        col = dword_51D5BC->x + byte_4F1DC0[4 * i];
        row = dword_51D5BC->y + byte_4F1DC1[4 * i];
        if ( *(_BYTE *)(usedToCheckForBoatByCastle(
                          advManager,
                          dword_51D5BC->x + byte_4F1DC0[4 * i],
                          dword_51D5BC->y + byte_4F1DC1[4 * i])
                      + 9) & 0x80 )
        {
          if ( !(*(&tileExplored[col] + row * mapWidth) & 0x80)
            && (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) & 0x7F) != 36
            && (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) & 0x7F) != 39
            && (*(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) != 163
             || gameObject->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(usedToCheckForBoatByCastle(
                                                                                     advManager,
                                                                                     col,
                                                                                     row)
                                                                                 + 4) >> 8) >> -5)].ownerIdx != curPlayerIdx
             || *(_WORD *)&dword_51D5BC->_2[3] != dword_532C54) )
          {
            if ( *(_BYTE *)(usedToCheckForBoatByCastle(advManager, col, row) + 9) != 170
              || gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(usedToCheckForBoatByCastle(
                                                                                     advManager,
                                                                                     col,
                                                                                     row)
                                                                                 + 4) >> 8) >> -5)].probablyOwnerIdx != curPlayerIdx
              || *(_WORD *)&dword_51D5BC->_2[0] != dword_532C54 )
            {
              v3 = aiHandleObject(__PAIR__(row, col), 2, (int)&v8);
              if ( v8 > 80 )
              {
                if ( v2 < v3 )
                {
                  v2 = v3;
                  v9 = i;
                }
              }
            }
          }
        }
      }
    }
    dword_5305C0 = v5;
    dword_5306D8 = v4;
    if ( v9 == -1 )
    {
      result = 0;
    }
    else
    {
      *(_DWORD *)a1 = v9;
      result = 1;
    }
  }
  return result;
}
