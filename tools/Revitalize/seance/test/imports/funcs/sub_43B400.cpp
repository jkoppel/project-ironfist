{
  bool result; // eax@2

  if ( a2 == -2 )
    result = 1;
  else
    result = a2 != -1
          && mapWidth - 1 != a2 % 13
          && a2 % 13
          && (!this->combatGrid[a2].probablyIsBlocked
           || combatManager->isCastleBattle
           && (a2 == 58 || a2 == 59)
           && (combatManager->drawBridgePosition != 4
            || combatManager->currentActionSide == 1
            && combatManager->combatGrid[58].unitOwner == -1
            && !combatManager->combatGrid[58].numCorpses))
          && (this->combatGrid[a2].unitOwner == -1
           || this->combatGrid[a2].unitOwner == this->otherCurrentSideThing
           && this->combatGrid[a2].stackIdx == this->someSortOfStackIdx);
  return result;
}
