{
  bool result; // eax@2
  int facingRight; // [sp+Ch] [bp-18h]@16
  CreatureStack *thisa; // [sp+10h] [bp-14h]@1
  signed int othNeighbAvail; // [sp+14h] [bp-10h]@25
  int othNeighb; // [sp+18h] [bp-Ch]@16
  signed int neighbAvail; // [sp+1Ch] [bp-8h]@5
  int neighb; // [sp+20h] [bp-4h]@3

  thisa = this;
  if ( !checkHexGridIdxBounds(hexIdx) )
    return 0;
  neighb = CreatureStack::getHexNeighbor(thisa, hexIdx, neighborIdx);
  if ( !checkHexGridIdxBounds(neighb) )
    return 0;
  neighbAvail = 0;
  if ( combatManager->combatGrid[neighb].unitOwner == -1
    && (!combatManager->combatGrid[neighb].probablyIsBlocked
     || combatManager->isCastleBattle
     && (neighb == 58 || neighb == 59)
     && (combatManager->drawBridgePosition != MOAT_CLOSED
      || combatManager->currentActionSide == 1
      && combatManager->combatGrid[58].unitOwner == -1
      && !combatManager->combatGrid[58].numCorpses)) )
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
        othNeighb = CreatureStack::getHexNeighbor(thisa, neighb, 1);
      }
    }
    else
    {
      if ( neighborIdx == 1 )
        return neighbAvail;
      othNeighb = CreatureStack::getHexNeighbor(thisa, neighb, 4);
    }
    othNeighbAvail = 0;
    if ( checkHexGridIdxBounds(othNeighb)
      && combatManager->combatGrid[othNeighb].unitOwner == -1
      && (!combatManager->combatGrid[othNeighb].probablyIsBlocked
       || combatManager->isCastleBattle
       && (othNeighb == 58 || othNeighb == 59)
       && (combatManager->drawBridgePosition != 4
        || combatManager->currentActionSide == 1
        && combatManager->combatGrid[58].unitOwner == -1
        && !combatManager->combatGrid[58].numCorpses)) )
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
