int __thiscall CreatureStack::getCenterY(CreatureStack *this)
{
  return combatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY
       - (getNthHeader(this->creatureIcon, this->form.animationFrameToImgIdx[7][0])->height >> 1);
}
