int __thiscall CreatureStack::getCenterX(CreatureStack *this)
{
  signed int v2; // [sp+10h] [bp-4h]@3

  if ( this->creature.creature_flags & TWO_HEXER )
  {
    if ( this->facingRight == 1 )
      v2 = 22;
    else
      v2 = -22;
  }
  else
  {
    v2 = 0;
  }
  return v2 + combatManager->combatGrid[this->occupiedHex].centerX;
}
