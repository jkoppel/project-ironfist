{
  int result; // eax@2
  signed int v2; // [sp+18h] [bp-Ch]@3
  int exp; // [sp+1Ch] [bp-8h]@3
  signed int v4; // [sp+20h] [bp-4h]@3

  if ( level > 12 )
  {
    v2 = 13;
    v4 = (signed __int64)((double)((signed int)experienceForLevelTable[12] - (signed int)experienceForLevelTable[11])
                        * 1.2);
    exp = v4 + experienceForLevelTable[12];
    while ( v2 < level )
    {
      v4 = (signed __int64)((double)v4 * 1.2);
      exp += v4;
      ++v2;
    }
    result = exp;
  }
  else
  {
    result = experienceForLevelTable[level];
  }
  return result;
}
