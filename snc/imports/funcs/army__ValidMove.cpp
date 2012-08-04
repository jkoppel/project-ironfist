{
  bool result; // eax@2
  int facingRight; // [sp+Ch] [bp-18h]@16
  army *thisa; // [sp+10h] [bp-14h]@1
  signed int othNeighbAvail; // [sp+14h] [bp-10h]@25
  int othNeighb; // [sp+18h] [bp-Ch]@16
  signed int neighbAvail; // [sp+1Ch] [bp-8h]@5
  int neighb; // [sp+20h] [bp-4h]@3

  thisa = this;
  if ( !ValidHex(hexIdx) )
    return 0;
  neighb = army::GetAdjacentCellIndex(thisa, hexIdx, neighborIdx);
  if ( !ValidHex(neighb) )
    return 0;
  neighbAvail = 0;
  if ( gpCombatManager->combatGrid[neighb].unitOwner == -1
    && (!gpCombatManager->combatGrid[neighb].isBlocked
     || gpCombatManager->isCastleBattle
     && (neighb == 58 || neighb == 59)
     && (gpCombatManager->drawBridgePosition != MOAT_CLOSED
      || gpCombatManager->currentActionSide == 1
      && gpCombatManager->combatGrid[58].unitOwner == -1
      && !gpCombatManager->combatGrid[58].numCorpses)) )
    neighbAvail = 1;
  if ( thisa->creature.creature_flags & TWO_HEXER )
  {
    othNeighb = -1;
    facingRight = thisa->facingRight;
    if ( facingRight )
    {
      if ( facingRight == 1 )
      {
        if ( neighborIdx == 4 )
          return neighbAvail;
        othNeighb = army::GetAdjacentCellIndex(thisa, neighb, 1);
      }
    }
    else
    {
      if ( neighborIdx == 1 )
        return neighbAvail;
      othNeighb = army::GetAdjacentCellIndex(thisa, neighb, 4);
    }
    othNeighbAvail = 0;
    if ( ValidHex(othNeighb)
      && gpCombatManager->combatGrid[othNeighb].unitOwner == -1
      && (!gpCombatManager->combatGrid[othNeighb].isBlocked
       || gpCombatManager->isCastleBattle
       && (othNeighb == 58 || othNeighb == 59)
       && (gpCombatManager->drawBridgePosition != 4
        || gpCombatManager->currentActionSide == 1
        && gpCombatManager->combatGrid[58].unitOwner == -1
        && !gpCombatManager->combatGrid[58].numCorpses)) )
      othNeighbAvail = 1;
    if ( neighborIdx != 1 && neighborIdx != 4 )
      result = neighbAvail == 1 && othNeighbAvail == 1;
    else
      result = othNeighbAvail;
  }
  else
  {
    result = neighbAvail;
  }
  return result;
}