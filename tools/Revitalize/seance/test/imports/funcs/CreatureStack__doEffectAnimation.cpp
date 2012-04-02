{
  CreatureStack *thisa; // [sp+24h] [bp-24h]@1
  int animBottomY; // [sp+28h] [bp-20h]@13
  ICNHeader *header; // [sp+2Ch] [bp-1Ch]@10
  signed int animMinOffsetY; // [sp+30h] [bp-18h]@8
  int v8; // [sp+34h] [bp-14h]@16
  int v9; // [sp+34h] [bp-14h]@26
  int k; // [sp+3Ch] [bp-Ch]@7
  int ka; // [sp+3Ch] [bp-Ch]@26
  int j; // [sp+40h] [bp-8h]@8
  int fileID; // [sp+44h] [bp-4h]@1

  thisa = this;
  fileID = computeFileID(creatureEffectAnimations[animationIdx]);
  if ( thisa->animationType == ANIMATION_TYPE_TO_WINCE || thisa->animationType == ANIMATION_TYPE_FROM_WINCE )
    a4 = 0;
  if ( !combatGraphicsOff && nextCreatureEffectAnimationIdx != animationIdx )
  {
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)nextCreatureEffectAnimation);
    nextCreatureEffectAnimation = ResourceManager::getIconByFileID(resourceManager, fileID);
    nextCreatureEffectAnimationIdx = animationIdx;
  }
  k = 0;
  thisa->probablyIsNeedDrawSpellEffect = 1;
  thisa->field_FA = 0;
  if ( !combatGraphicsOff )
  {
    animMinOffsetY = 999;
    for ( j = 0; nextCreatureEffectAnimation->numSprites > j; ++j )
    {
      header = getNthHeader(nextCreatureEffectAnimation, j);
      if ( header->offsetY < animMinOffsetY )
        animMinOffsetY = header->offsetY;
    }
    animBottomY = animMinOffsetY + CreatureStack::getNextEffectAnimationBottomY(thisa);
    if ( animBottomY < 0 )
      thisa->field_FA = -animBottomY;
    if ( a4 )
    {
      v8 = 275 / thisa->form.animationLengths[14];
      thisa->animationType = 14;
      while ( thisa->form.animationLengths[14] > k )
      {
        thisa->animationFrame = k;
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
  thisa->probablyIsNeedDrawSpellEffect = 0;
  if ( !combatGraphicsOff )
  {
    if ( a4 )
    {
      v9 = 275 / thisa->form.animationLengths[15];
      thisa->animationType = 15;
      for ( ka = 0; thisa->form.animationLengths[15] > ka; ++ka )
      {
        thisa->animationFrame = ka;
        animTimer = (signed __int64)((double)getTickCount()
                                   + (double)v9 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
        CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
        sleepUntilPointer(&animTimer);
      }
      thisa->animationType = 7;
      thisa->animationFrame = 0;
      CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    }
    else
    {
      CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
    }
  }
}
