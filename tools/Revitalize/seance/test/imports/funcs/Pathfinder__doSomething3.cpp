{
  Pathfinder *v6; // ebp@1
  int v7; // eax@1
  int v8; // ecx@2
  int result; // eax@2
  char v10; // al@19
  char v11; // al@24
  char v12; // al@43

  *(_DWORD *)a4 = 0;
  v6 = this;
  *(_DWORD *)(a4 + 4) = 0;
  v7 = usedToCheckForBoatByCastle(advManager, a2, SHIDWORD(a2));
  dword_526B8C = 0;
  dword_526B9C = v7;
  do
  {
    v8 = a2 + byte_4F1DC0[4 * dword_526B8C];
    result = HIDWORD(a2) + byte_4F1DC1[4 * dword_526B8C];
    dword_526B88 = v8;
    ::a3 = result;
    if ( v8 < 0
      || (result = v8, mapWidth <= v8)
      || (result = ::a3, ::a3 < 0)
      || (result = mapHeight, ::a3 >= mapHeight)
      || (result = usedToCheckForBoatByCastle(advManager, dword_526B88, ::a3),
          dword_526B80 = result,
          *(_BYTE *)(result + 8) & 8)
      || dword_524810[curPlayerIdx]
      && (result = dword_526B88 + ::a3 * mapWidth, !(tileExplored[result] & (unsigned __int8)byte_532C5C)) )
    {
LABEL_49:
      dword_526C18 = -1;
      goto LABEL_50;
    }
    if ( *(_BYTE *)(dword_526B80 + 9) & 0x80 )
    {
      if ( a5 )
      {
        *(_BYTE *)(dword_526B8C + a4) = 1;
      }
      else
      {
        result = dword_526B88;
        if ( *(_DWORD *)&v6->_1[0] != dword_526B88 )
          goto LABEL_49;
        result = ::a3;
        if ( *(_DWORD *)&v6->_1[4] != ::a3 )
          goto LABEL_49;
      }
    }
    dword_526C18 = (unsigned __int8)tileToTerrainType[*(_WORD *)dword_526B80];
    if ( dword_526C18 )
    {
      if ( a6 )
      {
        result = dword_526B80;
        if ( *(_BYTE *)(dword_526B80 + 9) != 28 )
          goto LABEL_49;
      }
    }
    else
    {
      result = dword_526B80;
      if ( a6 )
      {
        if ( *(_BYTE *)(dword_526B80 + 9) == -85 )
          goto LABEL_49;
        if ( !tileToTerrainType[*(_WORD *)dword_526B9C] )
        {
          v10 = byte_4F1DC0[4 * dword_526B8C];
          if ( v10 )
          {
            if ( byte_4F1DC1[4 * dword_526B8C] )
            {
              result = usedToCheckForBoatByCastle(advManager, a2 + v10, SHIDWORD(a2));
              if ( tileToTerrainType[*(_WORD *)result] )
                goto LABEL_49;
              result = usedToCheckForBoatByCastle(advManager, a2, HIDWORD(a2) + byte_4F1DC1[4 * dword_526B8C]);
              if ( tileToTerrainType[*(_WORD *)result] )
                goto LABEL_49;
            }
          }
        }
      }
      else
      {
        v11 = *(_BYTE *)(dword_526B80 + 9);
        if ( v11 != -86 && v11 != -85 && v11 != -96 )
          goto LABEL_49;
      }
    }
    result = 1 << dword_526B8C;
    if ( (1 << dword_526B8C) & 0x83 )
    {
      if ( *(_BYTE *)(dword_526B9C + 3) != -1 )
      {
        if ( (*(_BYTE *)(dword_526B9C + 2) & 0xFC) != -68 )
        {
          result = dword_526B9C;
          if ( !(*(_BYTE *)(dword_526B9C + 8) & 0x80) )
            goto LABEL_49;
        }
      }
      result = dword_526B80;
      if ( *(_BYTE *)(dword_526B80 + 7) != -1 )
      {
        result = usedToCheckForBoatByCastle(advManager, dword_526B88, ::a3 + 1);
        if ( *(_BYTE *)(result + 3) != -1 )
        {
          if ( (*(_BYTE *)(result + 2) & 0xFC) != -68 && !(*(_BYTE *)(result + 8) & 0x80) )
            goto LABEL_49;
        }
      }
    }
    else
    {
      if ( result & 0x38 )
      {
        if ( *(_BYTE *)(dword_526B80 + 3) != -1 )
        {
          if ( (*(_BYTE *)(dword_526B80 + 2) & 0xFC) != -68 )
          {
            result = dword_526B80;
            if ( !(*(_BYTE *)(dword_526B80 + 8) & 0x80) )
            {
              v12 = *(_BYTE *)(dword_526B80 + 9);
              if ( !(v12 & 0x80) )
                goto LABEL_49;
              dword_526B84 = result & 0x7F;
              if ( !sub_458D40(dword_526B80) )
                goto LABEL_49;
            }
          }
        }
        result = dword_526B9C;
        if ( *(_BYTE *)(dword_526B9C + 7) != -1 )
        {
          result = usedToCheckForBoatByCastle(advManager, a2, HIDWORD(a2) + 1);
          if ( *(_BYTE *)(result + 3) != -1 )
          {
            if ( (*(_BYTE *)(result + 2) & 0xFC) != -68 && !(*(_BYTE *)(result + 8) & 0x80) )
              goto LABEL_49;
          }
        }
      }
    }
LABEL_50:
    LOBYTE(result) = dword_526C18;
    *(_BYTE *)(dword_526B8C++ + a3) = dword_526C18;
  }
  while ( dword_526B8C < 8 );
  return result;
}
