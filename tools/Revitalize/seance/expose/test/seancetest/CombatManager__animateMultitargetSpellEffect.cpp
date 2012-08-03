void __thiscall CombatManager::animateMultitargetSpellEffect(CombatManager *this, char (*stackAffected)[2][20], int animIdx, int isDamageSpell)
{
  CombatManager *thisa; // [sp+Ch] [bp-28h]@1
  signed int i; // [sp+14h] [bp-20h]@3
  signed int l; // [sp+14h] [bp-20h]@26
  signed int n; // [sp+14h] [bp-20h]@47
  signed int kk; // [sp+14h] [bp-20h]@55
  signed int mm; // [sp+14h] [bp-20h]@71
  signed int highestFromFrameIdx; // [sp+1Ch] [bp-18h]@1
  signed int v11; // [sp+20h] [bp-14h]@71
  int k; // [sp+24h] [bp-10h]@24
  int jj; // [sp+24h] [bp-10h]@53
  int highestToFrameIdx; // [sp+28h] [bp-Ch]@1
  int j; // [sp+2Ch] [bp-8h]@5
  int m; // [sp+2Ch] [bp-8h]@28
  int ii; // [sp+2Ch] [bp-8h]@49
  int ll; // [sp+2Ch] [bp-8h]@57
  int nn; // [sp+2Ch] [bp-8h]@73
  int fileID; // [sp+30h] [bp-4h]@1

  thisa = this;
  fileID = computeFileID(creatureEffectAnimations[animIdx]);
  highestToFrameIdx = spellEffectAnimNumFrames[animIdx] - 1;
  highestFromFrameIdx = 0;
  if ( nextCreatureEffectAnimationIdx != animIdx )
  {
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)nextCreatureEffectAnimation);
    nextCreatureEffectAnimation = ResourceManager::getIconByFileID(resourceManager, fileID);
    nextCreatureEffectAnimationIdx = animIdx;
  }
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; thisa->numCreatures[i] > j; ++j )
    {
      if ( (*stackAffected)[i][j] )
        thisa->creatures[i][j].probablyIsNeedDrawSpellEffect = 1;
      if ( isDamageSpell
        && (*stackAffected)[i][j]
        && thisa->creatures[i][j].animationType != ANIMATION_TYPE_TO_WINCE
        && thisa->creatures[i][j].animationType != ANIMATION_TYPE_FROM_WINCE )
      {
        if ( thisa->creatures[i][j].quantity )
        {
          if ( thisa->creatures[i][j].form.animationLengths[14] > highestToFrameIdx )
            highestToFrameIdx = thisa->creatures[i][j].form.animationLengths[14];
          if ( thisa->creatures[i][j].form.animationLengths[15] > highestFromFrameIdx )
            highestFromFrameIdx = thisa->creatures[i][j].form.animationLengths[15];
          SoundManager::playSample(soundManager, thisa->creatures[i][j].combatSounds[2]);
        }
        else
        {
          if ( thisa->creatures[i][j].form.animationLengths[13] > highestToFrameIdx )
            highestToFrameIdx = thisa->creatures[i][j].form.animationLengths[13];
          SoundManager::playSample(soundManager, thisa->creatures[i][j].combatSounds[4]);
        }
      }
    }
  }
  for ( k = 0; highestToFrameIdx > k; ++k )
  {
    for ( l = 0; l < 2; ++l )
    {
      for ( m = 0; thisa->numCreatures[l] > m; ++m )
      {
        thisa->creatures[l][m].field_FA = 0;
        if ( isDamageSpell && (*stackAffected)[l][m] )
        {
          if ( thisa->creatures[l][m].quantity )
          {
            if ( thisa->creatures[l][m].animationType == ANIMATION_TYPE_TO_WINCE )
            {
              if ( thisa->creatures[l][m].form.animationLengths[thisa->creatures[l][m].animationType] > thisa->creatures[l][m].animationFrame + 1 )
                ++thisa->creatures[l][m].animationFrame;
            }
            else
            {
              thisa->creatures[l][m].animationType = ANIMATION_TYPE_TO_WINCE;
              thisa->creatures[l][m].animationFrame = 0;
            }
          }
          else
          {
            if ( thisa->creatures[l][m].animationType == ANIMATION_TYPE_DYING )
            {
              if ( thisa->creatures[l][m].form.animationLengths[thisa->creatures[l][m].animationType] > thisa->creatures[l][m].animationFrame + 1 )
                ++thisa->creatures[l][m].animationFrame;
            }
            else
            {
              thisa->creatures[l][m].animationType = ANIMATION_TYPE_DYING;
              thisa->creatures[l][m].animationFrame = 0;
            }
          }
        }
        if ( spellEffectAnimNumFrames[animIdx] > k + 1 )
          spellEffectAnimImgIdx = k;
      }
    }
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 110, 1, 1);
  }
  for ( n = 0; n < 2; ++n )
  {
    for ( ii = 0; thisa->numCreatures[n] > ii; ++ii )
      thisa->creatures[n][ii].probablyIsNeedDrawSpellEffect = 0;
  }
  for ( jj = 0; highestFromFrameIdx + 1 > jj; ++jj )
  {
    for ( kk = 0; kk < 2; ++kk )
    {
      for ( ll = 0; thisa->numCreatures[kk] > ll; ++ll )
      {
        if ( isDamageSpell && (*stackAffected)[kk][ll] && thisa->creatures[kk][ll].animationType != 7 )
        {
          if ( thisa->creatures[kk][ll].animationType == ANIMATION_TYPE_TO_WINCE )
          {
            thisa->creatures[kk][ll].animationType = ANIMATION_TYPE_FROM_WINCE;
            thisa->creatures[kk][ll].animationFrame = 0;
          }
          else
          {
            if ( thisa->creatures[kk][ll].form.animationLengths[thisa->creatures[kk][ll].animationType] <= thisa->creatures[kk][ll].animationFrame + 1 )
            {
              if ( thisa->creatures[kk][ll].animationType != ANIMATION_TYPE_DYING )
              {
                thisa->creatures[kk][ll].animationType = ANIMATION_TYPE_STANDING;
                thisa->creatures[kk][ll].animationFrame = 0;
              }
            }
            else
            {
              ++thisa->creatures[kk][ll].animationFrame;
            }
          }
        }
      }
    }
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 110, 1, 1);
  }
  v11 = 0;
  memset(thisa->field_F577, 0, 0x28u);
  thisa->field_F59F = 0;
  for ( mm = 0; mm < 2; ++mm )
  {
    for ( nn = 0; thisa->numCreatures[mm] > nn; ++nn )
    {
      if ( (*stackAffected)[mm][nn] && !thisa->creatures[mm][nn].quantity )
      {
        CreatureStack::die(&thisa->creatures[mm][nn], 0);
        v11 = 1;
      }
    }
  }
  if ( v11 )
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  if ( thisa->field_F59F )
    sub_4796F0(thisa);
}
