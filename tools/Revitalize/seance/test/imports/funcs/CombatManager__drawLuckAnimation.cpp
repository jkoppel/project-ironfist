{
  CombatManager *thisa; // [sp+Ch] [bp-18h]@1
  CreatureStack *stack; // [sp+10h] [bp-14h]@1
  int centX; // [sp+14h] [bp-10h]@1
  signed int startY; // [sp+18h] [bp-Ch]@3
  signed int startX; // [sp+1Ch] [bp-8h]@5
  int destY; // [sp+20h] [bp-4h]@1

  thisa = this;
  stack = &this->creatures[side][stackIdx];
  centX = CreatureStack::getCenterX(&this->creatures[side][stackIdx]);
  destY = thisa->combatGrid[stack->occupiedHex].occupyingCreatureBottomY
        - (getNthHeader(stack->creatureIcon, stack->form.animationFrameToImgIdx[7][0])->height
         + 5);
  if ( destY < 75 )
    destY = 75;
  startY = 0;
  if ( stack->facingRight == 1 )
  {
    if ( centX >= 480 )
      startX = centX - 150 - destY / 2;
    else
      startX = destY / 2 + centX + 150;
  }
  else
  {
    if ( centX <= 200 )
      startX = destY / 2 + centX + 150;
    else
      startX = centX - 150 - destY / 2;
  }
  if ( destY < 140 )
  {
    if ( side )
      startX = 639;
    else
      startX = 0;
    startY = destY + 75;
  }
  if ( startX < 0 )
    startX = 0;
  if ( startX > 639 )
    startX = 639;
  return CombatManager::drawBolt(
           thisa,
           0,
           startX,
           startY,
           centX,
           destY,
           0,
           0,
           15,
           15,
           (((centX >= startX) - 1) & 0xFFFFFFFD) + 303,
           40,
           40,
           10,
           1,
           1,
           30,
           0);
}
