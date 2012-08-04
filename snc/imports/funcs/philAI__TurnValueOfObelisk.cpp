{
  double result; // st7@4
  int v2; // eax@7
  signed int v3; // [sp+24h] [bp-Ch]@1
  char *v4; // [sp+2Ch] [bp-4h]@1

  v4 = &gpGame->players[a1]._4[8];
  v3 = gArtifactBaseRV[gpGame->_10[26]];
  if ( gpGame->winConditionType == 3 )
    v3 *= 2;
  if ( gpGame->_10[26] == -1 )
  {
    result = 0.0;
  }
  else
  {
    *(_DWORD *)&gpGame->players[a1]._4[88] = 48 * (v3 / 110) / gpGame->numObelisks;
    if ( gpCurPlayer->personality == 2 )
      *((_DWORD *)v4 + 20) = (signed __int64)((double)*((signed int *)v4 + 20) * 1.4);
    v2 = game::SetupPuzzlePieces(gpGame, giCurPlayer, 1);
    *((_DWORD *)v4 + 20) = (signed __int64)((1.5 - (double)abs(48 - v2) / 48.0) * (double)*((signed int *)v4 + 20));
    *((_DWORD *)v4 + 20) = (signed __int64)((*((float *)v4 + 5) + 0.66) * (double)*((signed int *)v4 + 20));
    result = (double)*((signed int *)v4 + 20);
  }
  return result;
}