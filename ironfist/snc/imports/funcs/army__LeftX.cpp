{
  int result; // eax@2
  int v2; // ebx@3
  int v3; // esi@3
  army *v4; // [sp+Ch] [bp-4h]@1

  v4 = this;
  if ( this->facingRight == 1 )
  {
    result = gpCombatManager->combatGrid[this->occupiedHex].centerX
           + GetIconEntry(this->creatureIcon, this->gap_129[389])->offsetX;
  }
  else
  {
    v2 = gpCombatManager->combatGrid[this->occupiedHex].centerX;
    v3 = GetIconEntry(this->creatureIcon, this->gap_129[389])->width;
    result = v2 - (GetIconEntry(v4->creatureIcon, v4->gap_129[389])->offsetX + v3);
  }
  return result;
}