{
  if ( a1->isCastleBattle
    && !a1->drawBridgePosition
    && a1->combatGrid[58].unitOwner == -1
    && !a1->combatGrid[58].numCorpses
    && a1->combatGrid[59].unitOwner == -1 )
  {
    if ( !a1->combatGrid[59].numCorpses )
      CombatManager::animateDrawbridgeClosing(a1);
  }
}
