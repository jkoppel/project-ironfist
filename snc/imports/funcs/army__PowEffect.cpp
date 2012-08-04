{
  int tmp1; // eax@35
  int tmp2; // eax@37
  int tmp3; // eax@39
  int tmp4; // eax@43
  int tmp5; // eax@45
  int tmp6; // eax@47
  int v11; // eax@70
  int v12; // eax@72
  int v13; // eax@74
  int v14; // eax@76
  int v15; // eax@79
  int v16; // eax@81
  signed int v17; // eax@83
  signed int v18; // eax@85
  army *thisa; // [sp+1Ch] [bp-48h]@1
  ICNHeader *animICNHeader; // [sp+20h] [bp-44h]@70
  int maxAnyCreatureAnimLen; // [sp+24h] [bp-40h]@45
  int maxAnyCreatureAnimLena; // [sp+24h] [bp-40h]@47
  signed int i; // [sp+28h] [bp-3Ch]@10
  signed int k; // [sp+28h] [bp-3Ch]@25
  signed int m; // [sp+28h] [bp-3Ch]@51
  signed int jj; // [sp+28h] [bp-3Ch]@88
  signed int mm; // [sp+28h] [bp-3Ch]@110
  signed int i1; // [sp+28h] [bp-3Ch]@161
  signed int i3; // [sp+28h] [bp-3Ch]@173
  signed int i5; // [sp+28h] [bp-3Ch]@210
  signed int i7; // [sp+28h] [bp-3Ch]@220
  signed int i9; // [sp+28h] [bp-3Ch]@229
  int fromAnimLen; // [sp+2Ch] [bp-38h]@1
  int maxOneWayAnimLen; // [sp+30h] [bp-34h]@1
  army *othstack; // [sp+38h] [bp-2Ch]@29
  army *thisc; // [sp+38h] [bp-2Ch]@92
  army *thisd; // [sp+38h] [bp-2Ch]@114
  char *thise; // [sp+38h] [bp-2Ch]@165
  char *thisf; // [sp+38h] [bp-2Ch]@177
  army *thisg; // [sp+38h] [bp-2Ch]@224
  signed int v41; // [sp+3Ch] [bp-28h]@171
  int j; // [sp+40h] [bp-24h]@12
  int l; // [sp+40h] [bp-24h]@27
  int n; // [sp+40h] [bp-24h]@53
  signed int ii; // [sp+40h] [bp-24h]@68
  int kk; // [sp+40h] [bp-24h]@90
  int nn; // [sp+40h] [bp-24h]@112
  int i2; // [sp+40h] [bp-24h]@163
  int i4; // [sp+40h] [bp-24h]@175
  int i6; // [sp+40h] [bp-24h]@212
  int i8; // [sp+40h] [bp-24h]@222
  int i10; // [sp+40h] [bp-24h]@231
  signed int doCreatureEffect; // [sp+44h] [bp-20h]@1
  int ll; // [sp+48h] [bp-1Ch]@108
  int oneWayAnimLen; // [sp+4Ch] [bp-18h]@1
  int maxToAnimLen; // [sp+50h] [bp-14h]@1
  int maxFromAnimLen; // [sp+54h] [bp-10h]@1
  int toAnimLen; // [sp+58h] [bp-Ch]@1
  signed int specialCaseOverlapWeirdness; // [sp+5Ch] [bp-8h]@1
  int creatureEffectNumFrames; // [sp+60h] [bp-4h]@1
  int maxAnimLen; // [sp+60h] [bp-4h]@49

  thisa = this;
  maxToAnimLen = 0;
  maxFromAnimLen = 0;
  maxOneWayAnimLen = 0;
  creatureEffectNumFrames = 0;
  toAnimLen = 0;
  fromAnimLen = 0;
  oneWayAnimLen = 0;
  doCreatureEffect = 0;
  specialCaseOverlapWeirdness = 1;
  if ( this->creatureIdx == CREATURE_PALADIN || this->creatureIdx == CREATURE_CRUSADER )
    specialCaseOverlapWeirdness = 0;
  if ( this->creatureIdx == CREATURE_DWARF || this->creatureIdx == CREATURE_BATTLE_DWARF )
    specialCaseOverlapWeirdness = 2;
  if ( a4 == -1 )
  {
    if ( animIdx != -1 )
    {
      for ( i = 0; i < 2; ++i )
      {
        for ( j = 0; gpCombatManager->numCreatures[i] > j; ++j )
        {
          if ( gpCombatManager->creatures[i][j].probablyIsNeedDrawSpellEffect )
            doCreatureEffect = 1;
        }
      }
    }
  }
  else
  {
    doCreatureEffect = 1;
  }
  if ( !gbNoShowCombat && animIdx != -1 && doCreatureEffect && animIdx != gCurLoadedSpellEffect )
  {
    resourceManager::Dispose(gpResourceManager, (resource *)gCurLoadedSpellIcon);
    gCurLoadedSpellIcon = resourceManager::GetIcon(gpResourceManager, gCombatFxNames[animIdx]);
    gCurLoadedSpellEffect = animIdx;
  }
  if ( doCreatureEffect )
    creatureEffectNumFrames = giNumPowFrames[gCurLoadedSpellEffect];
  for ( k = 0; k < 2; ++k )
  {
    for ( l = 0; gpCombatManager->numCreatures[k] > l; ++l )
    {
      othstack = &gpCombatManager->creatures[k][l];
      if ( gpCombatManager->creatures[k][l].mightBeIsAttacking )
      {
        toAnimLen = othstack->gap_129[thisa->mightBeAttackAnimIdx + 243];
        fromAnimLen = othstack->gap_129[thisa->mightBeAttackAnimIdx + 244] + 1;
      }
      else if ( gpCombatManager->creatures[k][l].dead )
      {
        oneWayAnimLen = gpCombatManager->creatures[k][l].gap_129[256];
      }
      else if ( gpCombatManager->creatures[k][l].damageTakenDuringSomeTimePeriod )
      {
        oneWayAnimLen = gpCombatManager->creatures[k][l].gap_129[258]
                      + gpCombatManager->creatures[k][l].gap_129[257]
                      + 1;
      }
      tmp1 = maxToAnimLen;
      if ( maxToAnimLen <= toAnimLen )
        tmp1 = toAnimLen;
      maxToAnimLen = tmp1;
      tmp2 = maxFromAnimLen;
      if ( maxFromAnimLen <= fromAnimLen )
        tmp2 = fromAnimLen;
      maxFromAnimLen = tmp2;
      tmp3 = maxOneWayAnimLen;
      if ( maxOneWayAnimLen <= oneWayAnimLen )
        tmp3 = oneWayAnimLen;
      maxOneWayAnimLen = tmp3;
    }
  }
  tmp4 = maxOneWayAnimLen + maxToAnimLen - specialCaseOverlapWeirdness;
  if ( tmp4 <= maxFromAnimLen + maxToAnimLen )
    tmp4 = maxFromAnimLen + maxToAnimLen;
  maxAnyCreatureAnimLen = tmp4;
  tmp5 = maxOneWayAnimLen;
  if ( maxOneWayAnimLen <= maxAnyCreatureAnimLen )
    tmp5 = maxAnyCreatureAnimLen;
  maxAnyCreatureAnimLena = tmp5;
  tmp6 = creatureEffectNumFrames;
  if ( creatureEffectNumFrames <= maxAnyCreatureAnimLena )
    tmp6 = maxAnyCreatureAnimLena;
  maxAnimLen = tmp6;
  if ( a3 )
    combatManager::ResetLimitCreature(gpCombatManager);
  for ( m = 0; m < 2; ++m )
  {
    for ( n = 0; gpCombatManager->numCreatures[m] > n; ++n )
    {
      gpCombatManager->creatures[m][n].animatingRangedAttack = gpCombatManager->creatures[m][n].animationType == ANIMATION_TYPE_RANGED_ATTACK_UPWARDS
                                                            || gpCombatManager->creatures[m][n].animationType == ANIMATION_TYPE_RANGED_ATTACK_FORWARDS
                                                            || gpCombatManager->creatures[m][n].animationType == ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS;
      if ( (gpCombatManager->creatures[m][n].damageTakenDuringSomeTimePeriod
         || gpCombatManager->creatures[m][n].mightBeIsAttacking
         || gpCombatManager->creatures[m][n].animatingRangedAttack)
        && !gpCombatManager->stuffHappenedToCreature[m][n] )
        ++gpCombatManager->stuffHappenedToCreature[m][n];
    }
  }
  combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
  if ( a4 != -1 )
  {
    for ( ii = 0; gCurLoadedSpellIcon->numSprites > ii; ++ii )
    {
      animICNHeader = &gCurLoadedSpellIcon->headersAndImageData[ii];
      v11 = a4 + animICNHeader->offsetX;
      if ( v11 >= giMinExtentX )
        v11 = giMinExtentX;
      giMinExtentX = v11;
      v12 = a5 + animICNHeader->offsetY;
      if ( v12 >= giMinExtentY )
        v12 = giMinExtentY;
      giMinExtentY = v12;
      v13 = a4 + animICNHeader->offsetX + animICNHeader->width - 1;
      if ( v13 <= giMaxExtentX )
        v13 = giMaxExtentX;
      giMaxExtentX = v13;
      v14 = a5 + animICNHeader->height + animICNHeader->offsetY - 1;
      if ( v14 <= giMaxExtentY )
        v14 = giMaxExtentY;
      giMaxExtentY = v14;
    }
    v15 = giMinExtentX;
    if ( giMinExtentX <= 0 )
      v15 = 0;
    giMinExtentX = v15;
    v16 = giMinExtentY;
    if ( giMinExtentY <= 0 )
      v16 = 0;
    giMinExtentY = v16;
    v17 = giMaxExtentX;
    if ( giMaxExtentX >= 639 )
      v17 = 639;
    giMaxExtentX = v17;
    v18 = giMaxExtentY;
    if ( giMaxExtentY >= 442 )
      v18 = 442;
    giMaxExtentY = v18;
  }
  for ( jj = 0; jj < 2; ++jj )
  {
    for ( kk = 0; gpCombatManager->numCreatures[jj] > kk; ++kk )
    {
      thisc = &gpCombatManager->creatures[jj][kk];
      gpCombatManager->creatures[jj][kk].field_3 = -1;
      thisc->field_4 = -1;
      *(_DWORD *)&thisc->effectStrengths[15] = 0;
      if ( thisc->damageTakenDuringSomeTimePeriod || thisc->mightBeIsAttacking )
      {
        if ( thisc->mightBeIsAttacking )
        {
          thisc->field_3 = thisa->mightBeAttackAnimIdx;
          thisc->field_4 = thisa->mightBeAttackAnimIdx + 1;
        }
        else if ( thisc->dead )
        {
          thisc->field_3 = ANIMATION_TYPE_DYING;
        }
        else
        {
          thisc->field_3 = ANIMATION_TYPE_TO_WINCE;
          thisc->field_4 = ANIMATION_TYPE_FROM_WINCE;
        }
        if ( thisc->field_3 == 13 )
          thisc->field_5 = thisc->gap_129[256];
        else
          thisc->field_5 = thisc->gap_129[thisc->field_3 + 243] + thisc->gap_129[thisc->field_3 + 244];
        if ( thisc->field_3 == thisc->animationType )
          --thisc->field_5;
        if ( thisa->field_6 < 2 )
          thisa->field_6 = 2;
      }
    }
  }
  for ( ll = 0; maxAnimLen > ll; ++ll )
  {
    for ( mm = 0; mm < 2; ++mm )
    {
      for ( nn = 0; gpCombatManager->numCreatures[mm] > nn; ++nn )
      {
        thisd = &gpCombatManager->creatures[mm][nn];
        if ( gpCombatManager->creatures[mm][nn].animatingRangedAttack )
        {
          if ( gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_RANGED_ATTACK_UPWARDS
            && gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_RANGED_ATTACK_FORWARDS
            && gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS )
          {
            if ( gpCombatManager->creatures[mm][nn].animationType != ANIMATION_TYPE_STANDING )
            {
              if ( gpCombatManager->creatures[mm][nn].gap_129[gpCombatManager->creatures[mm][nn].animationType + 243] <= gpCombatManager->creatures[mm][nn].animationFrame + 1 )
              {
                gpCombatManager->creatures[mm][nn].animationType = ANIMATION_TYPE_STANDING;
                thisd->animationFrame = 0;
              }
              else
              {
                ++gpCombatManager->creatures[mm][nn].animationFrame;
              }
            }
          }
          else
          {
            ++gpCombatManager->creatures[mm][nn].animationType;
            thisd->animationFrame = 0;
          }
        }
        if ( thisd->field_3 != -1
          && !*(_DWORD *)&thisd->effectStrengths[15]
          && (thisd->mightBeIsAttacking
           || thisd->field_5 >= maxAnimLen - ll - 1
           || maxToAnimLen && maxToAnimLen - 1 <= ll
           || !maxToAnimLen
           && thisd->animationType != 15
           && (thisd->animationType != 14 || thisd->gap_129[thisd->animationType + 243] > thisd->animationFrame + 1)) )
        {
          if ( thisd->field_3 == thisd->animationType || thisd->field_4 == thisd->animationType )
          {
            if ( thisd->gap_129[thisd->animationType + 243] <= thisd->animationFrame + 1 )
            {
              if ( thisd->field_4 == thisd->animationType || thisd->field_4 == -1 )
              {
                if ( thisd->animationType != 7 && thisd->animationType != 13 )
                {
                  thisd->animationType = 7;
                  thisd->animationFrame = 0;
                  *(_DWORD *)&thisd->effectStrengths[15] = 1;
                }
              }
              else
              {
                thisd->animationType = thisd->field_4;
                thisd->animationFrame = 0;
              }
            }
            else
            {
              ++thisd->animationFrame;
            }
          }
          else
          {
            if ( !gbNoShowCombat && thisd->field_3 == 14 )
              soundManager::MemorySample(gpSoundManager, gpCombatManager->creatures[mm][nn].combatSounds[2]);
            if ( !gbNoShowCombat && thisd->field_3 == 13 )
              soundManager::MemorySample(gpSoundManager, gpCombatManager->creatures[mm][nn].combatSounds[4]);
            thisd->animationType = thisd->field_3;
            thisd->animationFrame = 0;
          }
        }
      }
    }
    glTimers = (signed __int64)((double)KBTickCount() + (double)120 * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]);
    if ( doCreatureEffect && giNumPowFrames[gCurLoadedSpellEffect] > ll )
      gCurSpellEffectFrame = ll;
    combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 0, 75, 1, 1);
    if ( a4 != -1 && giNumPowFrames[gCurLoadedSpellEffect] > ll )
      icon::CombatClipDrawToBuffer(
        gCurLoadedSpellIcon,
        a4,
        a5 + thisa->field_FA,
        gCurSpellEffectFrame,
        &thisa->effectAnimationBounds,
        0,
        0,
        0,
        0);
    heroWindowManager::UpdateScreenRegion(
      gpWindowManager,
      giMinExtentX,
      giMinExtentY,
      giMaxExtentX - giMinExtentX + 1,
      giMaxExtentY - giMinExtentY + 1);
  }
  if ( !gbNoShowCombat )
    army::WaitSample(1);
  for ( i1 = 0; i1 < 2; ++i1 )
  {
    for ( i2 = 0; gpCombatManager->numCreatures[i1] > i2; ++i2 )
    {
      thise = (char *)&gpCombatManager->creatures[i1][i2];
      if ( gpCombatManager->creatures[i1][i2].damageTakenDuringSomeTimePeriod
        && gpCombatManager->creatures[i1][i2].spellEnemyCreatureAbilityIsCasting != -1
        && gpCombatManager->creatures[i1][i2].spellEnemyCreatureAbilityIsCasting != 101 )
      {
        combatManager::CastSpell(
          gpCombatManager,
          (Spell)gpCombatManager->creatures[i1][i2].spellEnemyCreatureAbilityIsCasting,
          gpCombatManager->creatures[i1][i2].occupiedHex,
          1,
          -1);
        *(_DWORD *)(thise + 226) = -1;
      }
    }
  }
  v41 = 1;
  while ( v41 )
  {
    v41 = 0;
    for ( i3 = 0; i3 < 2; ++i3 )
    {
      for ( i4 = 0; gpCombatManager->numCreatures[i3] > i4; ++i4 )
      {
        thisf = (char *)&gpCombatManager->creatures[i3][i4];
        if ( gpCombatManager->creatures[i3][i4].animationType != 14
          && gpCombatManager->creatures[i3][i4].animationType != 16
          && gpCombatManager->creatures[i3][i4].animationType != 20
          && gpCombatManager->creatures[i3][i4].animationType != 24
          && gpCombatManager->creatures[i3][i4].animationType != 18
          && gpCombatManager->creatures[i3][i4].animationType != 22
          && gpCombatManager->creatures[i3][i4].animationType != 26
          && gpCombatManager->creatures[i3][i4].animationType != 28
          && gpCombatManager->creatures[i3][i4].animationType != 30
          && gpCombatManager->creatures[i3][i4].animationType != 32 )
        {
          if ( gpCombatManager->creatures[i3][i4].animationType == 13
            || gpCombatManager->creatures[i3][i4].animationType == 15
            || gpCombatManager->creatures[i3][i4].animationType == 17
            || gpCombatManager->creatures[i3][i4].animationType == 21
            || gpCombatManager->creatures[i3][i4].animationType == 25
            || gpCombatManager->creatures[i3][i4].animationType == 19
            || gpCombatManager->creatures[i3][i4].animationType == 23
            || gpCombatManager->creatures[i3][i4].animationType == 27
            || gpCombatManager->creatures[i3][i4].animationType == 29
            || gpCombatManager->creatures[i3][i4].animationType == 31
            || gpCombatManager->creatures[i3][i4].animationType == 33 )
          {
            if ( gpCombatManager->creatures[i3][i4].gap_129[gpCombatManager->creatures[i3][i4].animationType + 243] <= gpCombatManager->creatures[i3][i4].animationFrame + 1 )
            {
              if ( gpCombatManager->creatures[i3][i4].animationType != 13 )
              {
                gpCombatManager->creatures[i3][i4].animationType = 7;
                *(_DWORD *)(thisf + 130) = 0;
                v41 = 1;
              }
            }
            else
            {
              ++gpCombatManager->creatures[i3][i4].animationFrame;
              v41 = 1;
            }
          }
        }
        else
        {
          ++gpCombatManager->creatures[i3][i4].animationType;
          *(_DWORD *)(thisf + 130) = 0;
          v41 = 1;
        }
      }
    }
    if ( v41 )
    {
      glTimers = (signed __int64)((double)KBTickCount() + (double)120 * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]);
      combatManager::DrawFrame(gpCombatManager, 1, 1, 0, 0, 75, 1, 1);
    }
  }
  if ( a3 )
    combatManager::ResetLimitCreature(gpCombatManager);
  memset(gpCombatManager->field_F577, 0, 0x28u);
  gpCombatManager->field_F59F = 0;
  for ( i5 = 0; i5 < 2; ++i5 )
  {
    for ( i6 = 0; gpCombatManager->numCreatures[i5] > i6; ++i6 )
    {
      if ( gpCombatManager->creatures[i5][i6].dead )
        army::ProcessDeath(&gpCombatManager->creatures[i5][i6], 0);
    }
  }
  if ( gpCombatManager->field_F59F )
    combatManager::MakeCreaturesVanish(gpCombatManager);
  for ( i7 = 0; i7 < 2; ++i7 )
  {
    for ( i8 = 0; gpCombatManager->numCreatures[i7] > i8; ++i8 )
    {
      thisg = &gpCombatManager->creatures[i7][i8];
      if ( gpCombatManager->creatures[i7][i8].damageTakenDuringSomeTimePeriod
        && gpCombatManager->creatures[i7][i8].spellEnemyCreatureAbilityIsCasting == 101 )
      {
        combatManager::CastSpell(
          gpCombatManager,
          (Spell)gpCombatManager->creatures[i7][i8].spellEnemyCreatureAbilityIsCasting,
          gpCombatManager->creatures[i7][i8].occupiedHex,
          1,
          -1);
        thisg->spellEnemyCreatureAbilityIsCasting = -1;
      }
      thisg->probablyIsNeedDrawSpellEffect = 0;
      thisg->damageTakenDuringSomeTimePeriod = 0;
      thisg->hasTakenLosses = 0;
      thisg->field_6 = 1;
      thisg->mightBeIsAttacking = 0;
      thisg->previousQuantity = -1;
    }
  }
  combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
  for ( i9 = 0; i9 < 2; ++i9 )
  {
    for ( i10 = 0; gpCombatManager->numCreatures[i9] > i10; ++i10 )
      army::WaitSample(2);
  }
}