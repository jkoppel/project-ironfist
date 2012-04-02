void __thiscall sub_4BD680(CombatHexTile *this, int a2, int a3)
{
  if ( this->unitOwner != -1 && (a2 == 100 || combatManager->creatures[this->unitOwner][this->stackIdx].field_6 == a2) )
  {
    if ( dword_4F7488
      && this->unitOwner == combatManager->otherCurrentSideThing
      && this->stackIdx == combatManager->someSortOfStackIdx )
      dword_4F748C = 1;
    if ( combatManager->creatures[this->unitOwner][this->stackIdx].facingRight != this->notPrimarySquareOfTwoHexer )
      CreatureStack::draw(
        &combatManager->creatures[this->unitOwner][this->stackIdx],
        this->centerX,
        this->occupyingCreatureBottomY,
        a3);
  }
}
