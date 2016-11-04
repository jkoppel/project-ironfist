{
  signed int result; // eax@2
  signed int idx; // [sp+Ch] [bp-8h]@1

  idx = neighborIdx;
  if ( hexIdx == -1 )
  {
    result = -1;
  }
  else
  {
    if ( neighborIdx == 6 )
    {
      idx = 5;
    }
    else
    {
      if ( neighborIdx == 7 )
        idx = 3;
    }
    result = combatManager->hexNeighbors[hexIdx][idx];
  }
  return result;
}
