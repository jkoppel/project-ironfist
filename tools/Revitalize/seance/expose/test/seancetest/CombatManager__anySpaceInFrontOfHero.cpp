bool __thiscall CombatManager::anySpaceInFrontOfHero(CombatManager *this)
{
  return (this->currentActionSide
       || this->combatGrid[14].unitOwner == -1
       || this->combatGrid[27].unitOwner == -1
       || this->combatGrid[40].unitOwner == -1)
      && (this->currentActionSide != 1
       || this->combatGrid[11].unitOwner == -1
       || this->combatGrid[24].unitOwner == -1
       || this->combatGrid[37].unitOwner == -1);
}
