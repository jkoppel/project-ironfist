void __thiscall CreatureStack::doEffectAnimation(CreatureStack *this, int animationIdx, signed int a3, int a4)
{
  int animBottomY; // [sp+28h] [bp-20h]@13
  ICNHeader *header; // [sp+2Ch] [bp-1Ch]@10
  signed int animMinOffsetY; // [sp+30h] [bp-18h]@8
  int v8; // [sp+34h] [bp-14h]@16
  int v9; // [sp+34h] [bp-14h]@26
  int k; // [sp+3Ch] [bp-Ch]@7
  int ka; // [sp+3Ch] [bp-Ch]@26
  int j; // [sp+40h] [bp-8h]@8
  int fileID; // [sp+44h] [bp-4h]@1

  fileID = computeFileID(creatureEffectAnimations[animationIdx]);
  if ( this->animationType == ANIMATION_TYPE_TO_WINCE || this->animationType == ANIMATION_TYPE_FROM_WINCE )
    a4 = 0;
  if ( !combatGraphicsOff && nextCreatureEffectAnimationIdx != animationIdx )
  {
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)nextCreatureEffectAnimation);
    nextCreatureEffectAnimation = ResourceManager::getIconByFileID(resourceManager, fileID);
    nextCreatureEffectAnimationIdx = animationIdx;
  }
  k = 0;
  this->probablyIsNeedDrawSpellEffect = 1;
  this->field_FA = 0;
  if ( !combatGraphicsOff )
  {
    animMinOffsetY = 999;
    for ( j = 0; nextCreatureEffectAnimation->numSprites > j; ++j )
    {
      header = getNthHeader(nextCreatureEffectAnimation, j);
      if ( header->offsetY < animMinOffsetY )
        animMinOffsetY = header->offsetY;
    }
    animBottomY = animMinOffsetY + CreatureStack::getNextEffectAnimationBottomY(this);
    if ( animBottomY < 0 )
      this->field_FA = -animBottomY;
    if ( a4 )
    {
      v8 = 275 / this->form.animationLengths[14];
      this->animationType = 14;
      while ( this->form.animationLengths[14] > k )
      {
        this->animationFrame = k;
        if ( spellEffectAnimNumFrames[animationIdx] <= k )
          spellEffectAnimImgIdx = spellEffectAnimNumFrames[animationIdx];
        else
          spellEffectAnimImgIdx = k;
        animTimer = (signed __int64)((double)getTickCount()
                                   + (double)v8 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
        CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
        sleepUntilPointer(&animTimer);
        ++k;
      }
    }
    while ( spellEffectAnimNumFrames[animationIdx] > k )
    {
      animTimer = (signed __int64)((double)getTickCount() + (double)a3 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
      spellEffectAnimImgIdx = k;
      CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
      sleepUntilPointer(&animTimer);
      ++k;
    }
  }
  this->probablyIsNeedDrawSpellEffect = 0;
  if ( !combatGraphicsOff )
  {
    if ( a4 )
    {
      v9 = 275 / this->form.animationLengths[15];
      this->animationType = 15;
      for ( ka = 0; this->form.animationLengths[15] > ka; ++ka )
      {
        this->animationFrame = ka;
        animTimer = (signed __int64)((double)getTickCount()
                                   + (double)v9 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
        CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
        sleepUntilPointer(&animTimer);
      }
      this->animationType = 7;
      this->animationFrame = 0;
      CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    }
    else
    {
      CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    }
  }
}
