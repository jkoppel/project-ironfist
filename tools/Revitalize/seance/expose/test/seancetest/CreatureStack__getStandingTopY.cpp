int __thiscall CreatureStack::getStandingTopY(CreatureStack *this)
{
  return combatManager->combatGrid[this->occupiedHex].occupyingCreatureBottomY
       - getNthHeader(this->creatureIcon, this->form.animationFrameToImgIdx[7][0])->height;
}
