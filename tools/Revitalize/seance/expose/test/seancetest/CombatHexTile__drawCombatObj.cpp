void __thiscall CombatHexTile::drawCombatObj(CombatHexTile *this)
{
  Icon::drawToScreenAndSetRectBounds(
    combatManager->combatObjIcons[this->combatObjIdx],
    this->centerX,
    this->occupyingCreatureBottomY,
    0,
    &this->drawingBounds,
    0,
    0,
    0,
    0);
}
