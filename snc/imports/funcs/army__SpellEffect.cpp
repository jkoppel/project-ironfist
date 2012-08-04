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

  fileID = MAKEFILEID(gCombatFxNames[animationIdx]);
  if ( this->animationType == ANIMATION_TYPE_TO_WINCE || this->animationType == ANIMATION_TYPE_FROM_WINCE )
    a4 = 0;
  if ( !gbNoShowCombat && gCurLoadedSpellEffect != animationIdx )
  {
    resourceManager::Dispose(gpResourceManager, (resource *)gCurLoadedSpellIcon);
    gCurLoadedSpellIcon = resourceManager::GetIcon(gpResourceManager, fileID);
    gCurLoadedSpellEffect = animationIdx;
  }
  k = 0;
  this->probablyIsNeedDrawSpellEffect = 1;
  this->field_FA = 0;
  if ( !gbNoShowCombat )
  {
    animMinOffsetY = 999;
    for ( j = 0; gCurLoadedSpellIcon->numSprites > j; ++j )
    {
      header = GetIconEntry(gCurLoadedSpellIcon, j);
      if ( header->offsetY < animMinOffsetY )
        animMinOffsetY = header->offsetY;
    }
    animBottomY = animMinOffsetY + army::GetPowBaseY(this);
    if ( animBottomY < 0 )
      this->field_FA = -animBottomY;
    if ( a4 )
    {
      v8 = 275 / this->gap_129[257];
      this->animationType = 14;
      while ( this->gap_129[257] > k )
      {
        this->animationFrame = k;
        if ( giNumPowFrames[animationIdx] <= k )
          gCurSpellEffectFrame = giNumPowFrames[animationIdx];
        else
          gCurSpellEffectFrame = k;
        animTimer = (signed __int64)((double)KBTickCount() + (double)v8 * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]);
        combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
        DelayTil(&animTimer);
        ++k;
      }
    }
    while ( giNumPowFrames[animationIdx] > k )
    {
      animTimer = (signed __int64)((double)KBTickCount() + (double)a3 * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]);
      gCurSpellEffectFrame = k;
      combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
      DelayTil(&animTimer);
      ++k;
    }
  }
  this->probablyIsNeedDrawSpellEffect = 0;
  if ( !gbNoShowCombat )
  {
    if ( a4 )
    {
      v9 = 275 / this->gap_129[258];
      this->animationType = 15;
      for ( ka = 0; this->gap_129[258] > ka; ++ka )
      {
        this->animationFrame = ka;
        animTimer = (signed __int64)((double)KBTickCount() + (double)v9 * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]);
        combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
        DelayTil(&animTimer);
      }
      this->animationType = 7;
      this->animationFrame = 0;
      combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
    }
    else
    {
      combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
    }
  }
}