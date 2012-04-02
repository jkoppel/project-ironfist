int __thiscall sub_4BD7F0(CombatHexTile *this, int a2)
{
  int result; // eax@1
  CombatHexTile *thisa; // [sp+Ch] [bp-18h]@1
  int v6; // [sp+10h] [bp-14h]@8
  int v7; // [sp+14h] [bp-10h]@4
  int row; // [sp+1Ch] [bp-8h]@1

  thisa = this;
  Icon::drawToScreenAndSetRectBounds(
    combatManager->combatScreenIcons[5],
    this->centerX + 28,
    thisa->occupyingCreatureBottomY,
    a2,
    &thisa->drawingBounds,
    1,
    0,
    0,
    0);
  result = (thisa->occupyingCreatureBottomY - 139) / 42;
  row = (thisa->occupyingCreatureBottomY - 139) / 42;
  if ( row != 4 )
  {
    if ( row & 1 )
    {
      v7 = thisa->centerX + 28;
      result = Icon::drawToScreenAndSetRectBounds(
                 combatManager->combatScreenIcons[5],
                 v7,
                 thisa->occupyingCreatureBottomY,
                 9,
                 &thisa->drawingBounds,
                 1,
                 0,
                 0,
                 0);
    }
    else
    {
      v6 = thisa->centerX;
      result = Icon::drawToScreenAndSetRectBounds(
                 combatManager->combatScreenIcons[5],
                 v6,
                 thisa->occupyingCreatureBottomY,
                 9,
                 &thisa->drawingBounds,
                 0,
                 0,
                 0,
                 0);
    }
  }
  return result;
}
