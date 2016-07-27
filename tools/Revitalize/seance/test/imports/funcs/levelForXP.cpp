{
  signed int i; // [sp+18h] [bp-Ch]@1
  signed int nextLevel; // [sp+18h] [bp-Ch]@6
  signed int v4; // [sp+1Ch] [bp-8h]@6
  signed int v5; // [sp+20h] [bp-4h]@6

  for ( i = 1; i <= 12; ++i )
  {
    if ( experienceForLevelTable[i] > a1 )
      return i - 1;
  }
  v5 = (signed __int64)((double)((signed int)experienceForLevelTable[12] - (signed int)experienceForLevelTable[11]) * 1.2);
  v4 = v5 + experienceForLevelTable[12];
  nextLevel = 13;
  while ( v4 < a1 )
  {
    v5 = (signed __int64)((double)v5 * 1.2);
    v4 += v5;
    ++nextLevel;
  }
  return nextLevel - 1;
}
