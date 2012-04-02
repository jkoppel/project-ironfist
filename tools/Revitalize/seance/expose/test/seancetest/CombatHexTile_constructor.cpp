CombatHexTile *__thiscall CombatHexTile_constructor(CombatHexTile *this)
{
  this->combatObjIdx = -1;
  this->probablyIsBlocked = 0;
  this->unitOwner = -1;
  this->stackIdx = 0;
  this->notPrimarySquareOfTwoHexer = -1;
  this->numCorpses = 0;
  return this;
}
