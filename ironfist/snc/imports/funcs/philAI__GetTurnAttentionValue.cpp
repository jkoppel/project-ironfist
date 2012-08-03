{
  char *result; // eax@10
  char *v2; // [sp+10h] [bp-8h]@1
  float v3; // [sp+14h] [bp-4h]@2

  v2 = &gpGame->players[a1]._4[8];
  *(_DWORD *)&gpGame->players[a1]._4[8] = 1053609165;
  *((_DWORD *)v2 + 2) = 1050253722;
  *((_DWORD *)v2 + 1) = 1050253722;
  *((_DWORD *)v2 + 3) = *(_DWORD *)v2;
  *((_DWORD *)v2 + 5) = *((_DWORD *)v2 + 2);
  *((_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
  if ( giCurTurn >= 5 )
  {
    if ( giCurTurn >= 10 )
    {
      if ( giCurTurn >= 20 )
      {
        if ( giCurTurn >= 30 )
          v3 = 0.80000001;
        else
          v3 = 1.0;
      }
      else
      {
        v3 = 1.2;
      }
    }
    else
    {
      v3 = 1.4;
    }
  }
  else
  {
    v3 = 1.6;
  }
  result = v2;
  *((float *)v2 + 5) = *((float *)v2 + 5) * v3;
  return result;
}