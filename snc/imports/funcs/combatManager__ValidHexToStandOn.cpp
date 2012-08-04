{
  bool result; // eax@2

  if ( a2 == -2 )
    result = 1;
  else
    result = a2 != -1
          && MAP_WIDTH - 1 != a2 % 13
          && a2 % 13
          && (!this->combatGrid[a2].isBlocked
           || gpCombatManager->isCastleBattle
           && (a2 == 58 || a2 == 59)
           && (gpCombatManager->drawBridgePosition != 4
            || gpCombatManager->currentActionSide == 1
            && gpCombatManager->combatGrid[58].unitOwner == -1
            && !gpCombatManager->combatGrid[58].numCorpses))
          && (this->combatGrid[a2].unitOwner == -1
           || this->combatGrid[a2].unitOwner == this->otherCurrentSideThing
           && this->combatGrid[a2].stackIdx == this->someSortOfStackIdx);
  return result;
}