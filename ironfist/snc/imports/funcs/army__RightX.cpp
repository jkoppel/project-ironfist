{
  int width; // ebx@2
  int result; // eax@2
  army *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->facingRight == 1 )
  {
    width = GetIconEntry(this->creatureIcon, this->gap_129[389])->width;
    result = GetIconEntry(thisa->creatureIcon, thisa->gap_129[389])->offsetX
           + width
           + gpCombatManager->combatGrid[thisa->occupiedHex].centerX;
  }
  else
  {
    result = gpCombatManager->combatGrid[this->occupiedHex].centerX
           - GetIconEntry(this->creatureIcon, this->gap_129[389])->offsetX;
  }
  return result;
}