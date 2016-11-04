{
  signed int v3; // ST38_4@1
  int v4; // ST3C_4@1
  double v5; // st7@1
  float v6; // ST48_4@1
  float v7; // ST44_4@1
  int result; // eax@6
  void *v9; // [sp+1Ch] [bp-24h]@1
  unsigned int castleIdx; // [sp+20h] [bp-20h]@9
  signed int j; // [sp+24h] [bp-1Ch]@13
  unsigned int k; // [sp+28h] [bp-18h]@0
  signed int v13; // [sp+2Ch] [bp-14h]@1
  int v14; // [sp+2Ch] [bp-14h]@3
  int i; // [sp+34h] [bp-Ch]@7

  v9 = this;
  v3 = getNumVisitedObelisks(a2);
  v4 = 48 - *((_BYTE *)v9 + 2898);
  v5 = (double)getNumVisitedObelisks(a2) / (double)*((_BYTE *)v9 + 2898);
  v6 = v5;
  v7 = (v5 * v6 + v6) / 2.0;
  v13 = (signed __int64)((double)v4 * v7 + (double)v3);
  if ( getNumVisitedObelisks(a2) == *((_BYTE *)v9 + 2898) )
    v13 = 48;
  v14 = *((_BYTE *)v9 + 283 * a2 + 1199) + v13;
  if ( v14 > 48 )
    v14 = 48;
  if ( a3 )
  {
    result = v14;
  }
  else
  {
    memset(&unk_523420, 0, 6u);
    setRandomSeed(3 * *((_BYTE *)v9 + 283 * a2 + 1351) + *((_BYTE *)v9 + 283 * a2 + 1180));
    for ( i = 0; i < v14; ++i )
    {
      for ( castleIdx = 0;
            (signed int)castleIdx < 48 && sub_4D05D8((int)&unk_523420, castleIdx);
            castleIdx += nextRandomInt(1, 5) )
        ;
      for ( j = 0; ; ++j )
      {
        if ( j < 100 )
        {
          k = nextRandomInt(0, 47);
          if ( sub_4D05D8((int)&unk_523420, k) )
            continue;
        }
        break;
      }
      if ( j >= 100 )
      {
        for ( k = 0; (signed int)k < 48 && sub_4D05D8((int)&unk_523420, k); ++k )
          ;
      }
      if ( (signed int)k >= 48 )
        k = 0;
      if ( (signed int)castleIdx >= 48 )
        sub_4D0606(&unk_523420, k);
      else
        sub_4D0606(&unk_523420, castleIdx);
    }
    result = v14;
  }
  return result;
}
