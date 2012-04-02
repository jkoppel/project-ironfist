int __thiscall CreatureStack::getLeftBound(CreatureStack *this)
{
  int result; // eax@2
  int v2; // ebx@3
  int v3; // esi@3
  CreatureStack *v4; // [sp+Ch] [bp-4h]@1

  v4 = this;
  if ( this->facingRight == 1 )
  {
    result = combatManager->combatGrid[this->occupiedHex].centerX
           + getNthHeader(this->creatureIcon, this->form.animationFrameToImgIdx[7][0])->offsetX;
  }
  else
  {
    v2 = combatManager->combatGrid[this->occupiedHex].centerX;
    v3 = getNthHeader(this->creatureIcon, this->form.animationFrameToImgIdx[7][0])->width;
    result = v2 - (getNthHeader(v4->creatureIcon, v4->form.animationFrameToImgIdx[7][0])->offsetX + v3);
  }
  return result;
}
