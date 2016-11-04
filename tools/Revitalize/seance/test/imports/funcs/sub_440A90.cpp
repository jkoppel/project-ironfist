{
  CombatManager *thisa; // [sp+Ch] [bp-8h]@1
  CreatureStack *stack; // [sp+10h] [bp-4h]@2

  thisa = this;
  if ( !combatGraphicsOff )
  {
    stack = &this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx];
    if ( !this->field_F2B7
      || this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx].occupiedHex != this->field_F2BB )
    {
      sub_4C3FF0(this, 0, 1);
      dword_4F1CB8 = 7;
      thisa->field_F2BB = stack->occupiedHex;
      thisa->field_F2B7 = 1;
      CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
    }
    sub_442860(thisa);
  }
}
