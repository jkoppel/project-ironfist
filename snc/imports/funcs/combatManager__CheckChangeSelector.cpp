{
  int v1; // edx@2
  combatManager *thisa; // [sp+Ch] [bp-8h]@1
  army *stack; // [sp+10h] [bp-4h]@2

  thisa = this;
  if ( !gbNoShowCombat )
  {
    v1 = this->someSortOfStackIdx;
    stack = &this->creatures[this->otherCurrentSideThing][v1];
    if ( !this->field_F2B7 || this->creatures[this->otherCurrentSideThing][v1].occupiedHex != this->field_F2BB )
    {
      combatManager::UpdateGrid(this, v1, 0, 1);
      giNewMonsterCycleFrame = 7;
      thisa->field_F2BB = stack->occupiedHex;
      thisa->field_F2B7 = 1;
      combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
    }
    combatManager::SetupSmallView(thisa);
  }
}