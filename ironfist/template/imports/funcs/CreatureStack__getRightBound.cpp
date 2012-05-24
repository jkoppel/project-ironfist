{
  int width; // ebx@2
  int result; // eax@2
  CreatureStack *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->facingRight == 1 )
  {
    width = getNthHeader(this->creatureIcon, this->form.animationFrameToImgIdx[7][0])->width;
    result = getNthHeader(thisa->creatureIcon, thisa->form.animationFrameToImgIdx[7][0])->offsetX
           + width
           + combatManager->combatGrid[thisa->occupiedHex].centerX;
  }
  else
  {
    result = combatManager->combatGrid[this->occupiedHex].centerX
           - getNthHeader(this->creatureIcon, this->form.animationFrameToImgIdx[7][0])->offsetX;
  }
  return result;
}
