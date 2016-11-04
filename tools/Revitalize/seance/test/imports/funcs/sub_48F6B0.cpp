{
  int result; // eax@1
  int v2; // [sp+10h] [bp-24h]@3
  signed int i; // [sp+18h] [bp-1Ch]@3
  signed int v4; // [sp+30h] [bp-4h]@3

  result = *(_BYTE *)(a1 + 3);
  if ( dword_524810[result] )
  {
    result = unseededNextRand(1, 3);
    if ( result == 1 )
    {
      v2 = 99999999;
      v4 = -1;
      for ( i = 0; i < 5; ++i )
      {
        if ( (signed int)*(_WORD *)(a1 + 2 * i + 106) > 0 )
        {
          if ( v2 > *(_WORD *)(a1 + 2 * i + 106) * creature_table[*(_BYTE *)(i + a1 + 101)].fight_value )
          {
            v2 = *(_WORD *)(a1 + 2 * i + 106) * creature_table[*(_BYTE *)(i + a1 + 101)].fight_value;
            v4 = i;
          }
        }
      }
      if ( ArmyInfo::getNumStacks((ArmyInfo *)(a1 + 101)) <= 1 )
      {
        result = *(_WORD *)(a1 + 2 * v4 + 106);
        if ( result > 1 )
        {
          result = v4;
          *(_WORD *)(a1 + 2 * result + 106) >>= 1;
        }
      }
      else
      {
        *(_WORD *)(a1 + 2 * v4 + 106) >>= 1;
        result = *(_WORD *)(a1 + 2 * v4 + 106);
        if ( !*(_WORD *)(a1 + 2 * v4 + 106) )
        {
          result = v4;
          *(_BYTE *)(v4 + a1 + 101) = -1;
        }
      }
    }
  }
  return result;
}
