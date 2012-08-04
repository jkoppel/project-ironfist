{
  if ( this->unitOwner != -1 && (a2 == 100 || gpCombatManager->creatures[this->unitOwner][this->stackIdx].field_6 == a2) )
  {
    if ( gbLimitToExtent
      && this->unitOwner == gpCombatManager->otherCurrentSideThing
      && this->stackIdx == gpCombatManager->someSortOfStackIdx )
      gbCurrArmyDrawn = 1;
    if ( gpCombatManager->creatures[this->unitOwner][this->stackIdx].facingRight != this->isOccupierNonPrimaryHex )
      army::DrawToBuffer(
        &gpCombatManager->creatures[this->unitOwner][this->stackIdx],
        this->centerX,
        this->occupyingCreatureBottomY,
        a3);
  }
}