signed int __thiscall CombatManager::getCorpseStackIdx(CombatManager *this, int side, Spell spell, int hexIdx)
{
  signed int result; // eax@4
  CombatManager *thisa; // [sp+Ch] [bp-Ch]@1
  int i; // [sp+14h] [bp-4h]@6

  thisa = this;
  if ( this->combatGrid[hexIdx].unitOwner == -1 )
  {
    for ( i = this->combatGrid[hexIdx].numCorpses - 1; i >= 0; --i )
    {
      if ( *(&thisa->combatGrid[0].corpseOwners[99 * hexIdx] + i - hexIdx) != -1
        && (*(&thisa->combatGrid[0].field_33[99 * hexIdx] + i - hexIdx) || thisa->combatGrid[hexIdx + 1].unitOwner == -1)
        && (*(&thisa->combatGrid[0].field_33[99 * hexIdx] + i - hexIdx) != 1
         || thisa->combatGrid[hexIdx - 1].unitOwner == -1)
        && *(&thisa->combatGrid[0].corpseOwners[99 * hexIdx] + i - hexIdx) == side
        && CreatureStack::getSpellSuccessChance(
             &thisa->creatures[*(&thisa->combatGrid[0].corpseOwners[99 * hexIdx] + i - hexIdx)][*(&thisa->combatGrid[0].corpseStackIndices[99 * hexIdx]
                                                                                                + i
                                                                                                - hexIdx)],
             spell) > 0.0 )
        return *(&thisa->combatGrid[0].corpseStackIndices[99 * hexIdx] + i - hexIdx);
    }
    result = -1;
  }
  else
  {
    if ( this->combatGrid[hexIdx].unitOwner != side
      || CreatureStack::getSpellSuccessChance(
           &this->creatures[this->combatGrid[hexIdx].unitOwner][this->combatGrid[hexIdx].stackIdx],
           spell) <= 0.0 )
      result = -1;
    else
      result = thisa->combatGrid[hexIdx].stackIdx;
  }
  return result;
}
