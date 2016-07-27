{
  int result; // eax@12
  int v5; // ebx@24
  char playerMask; // [sp+1Ch] [bp-18h]@1
  int row; // [sp+20h] [bp-14h]@11
  int rowa[2]; // [sp+20h] [bp-14h]@20
  int col; // [sp+24h] [bp-10h]@13
  int v10; // [sp+30h] [bp-4h]@8

  playerMask = 1 << playerIdx;
  if ( !dword_524810[playerIdx] )
  {
    if ( dword_532C54 <= 40 )
    {
      if ( dword_532C54 <= 20 )
        ++radius;
      else
        radius += 2;
    }
    else
    {
      radius += 3;
    }
  }
  if ( radius < 5 )
    v10 = 2;
  else
    v10 = 3;
  if ( radius < 10 )
  {
    for ( rowa[0] = y - radius; ; ++rowa[0] )
    {
      result = y + radius;
      if ( y + radius < rowa[0] )
        break;
      for ( rowa[1] = x - radius; radius + x >= rowa[1]; ++rowa[1] )
      {
        v5 = radius + radius - abs(y - rowa[0]);
        if ( v10 <= v5 - abs(x - rowa[1]) && *(_QWORD *)rowa >= 0i64 && mapWidth > rowa[1] && rowa[0] < mapHeight )
          *(&tileExplored[rowa[1]] + rowa[0] * mapWidth) |= playerMask;
      }
    }
  }
  else
  {
    for ( row = 0; ; ++row )
    {
      result = mapHeight;
      if ( row >= mapHeight )
        break;
      for ( col = 0; mapWidth > col; ++col )
      {
        if ( (signed int)(signed __int64)sqrt((double)((y - row) * (y - row) + (x - col) * (x - col))) < radius )
          *(&tileExplored[col] + row * mapWidth) |= playerMask;
      }
    }
  }
  return result;
}
