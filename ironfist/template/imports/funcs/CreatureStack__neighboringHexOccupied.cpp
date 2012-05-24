{
  int v7; // [sp+10h] [bp-10h]@8
  CreatureStack *thisa; // [sp+14h] [bp-Ch]@1
  int neighborOwner; // [sp+18h] [bp-8h]@27
  int v10; // [sp+1Ch] [bp-4h]@3

  thisa = this;
  if ( !checkHexGridIdxBounds(knownHex) )
    return 0;
  v10 = knownHex;
  if ( thisa->creature.creature_flags & TWO_HEXER )
  {
    if ( neighborIdx == 6 )
    {
      *neighbor = CreatureStack::getHexNeighbor(thisa, knownHex, thisa->facingRight < 1u ? 5 : 0);
    }
    else
    {
      if ( neighborIdx == 7 )
      {
        *neighbor = CreatureStack::getHexNeighbor(thisa, knownHex, (thisa->facingRight < 1u) + 2);
      }
      else
      {
        v7 = thisa->facingRight;
        if ( v7 )
        {
          if ( v7 == 1 && neighborIdx <= 2 )
            v10 = CreatureStack::getHexNeighbor(thisa, knownHex, 1);
        }
        else
        {
          if ( neighborIdx >= 3 )
            v10 = CreatureStack::getHexNeighbor(thisa, knownHex, 4);
        }
        if ( v10 == -1 )
          return 0;
        *neighbor = CreatureStack::getHexNeighbor(thisa, v10, neighborIdx);
      }
    }
  }
  else
  {
    *neighbor = CreatureStack::getHexNeighbor(thisa, knownHex, neighborIdx);
  }
  if ( !checkHexGridIdxBounds(*neighbor) )
    return 0;
  if ( a5 != -1 && *neighbor != a5 )
    return 0;
  neighborOwner = combatManager->combatGrid[*neighbor].unitOwner;
  if ( focusLevel )
  {
    if ( focusLevel == 1 )
    {
      if ( 1 - combatManager->currentActionSide == neighborOwner )
        return 1;
    }
    else
    {
      if ( focusLevel == 2 && neighborOwner != -1 )
        return 1;
    }
  }
  else
  {
    if ( thisa->targetOwner == neighborOwner && combatManager->combatGrid[*neighbor].stackIdx == thisa->targetStackIdx )
      return 1;
  }
  return 0;
}
