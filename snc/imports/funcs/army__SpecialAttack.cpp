{
  int v1; // ebx@0
  double v2; // st6@0
  int v3; // eax@12
  int v4; // ST64_4@42
  army *thisa; // [sp+3Ch] [bp-1B0h]@1
  char *v6; // [sp+40h] [bp-1ACh]@132
  char *v7; // [sp+44h] [bp-1A8h]@127
  char *v8; // [sp+48h] [bp-1A4h]@124
  bitmap *thisb; // [sp+54h] [bp-198h]@55
  int v10; // [sp+58h] [bp-194h]@0
  army *targ; // [sp+5Ch] [bp-190h]@113
  int v12; // [sp+60h] [bp-18Ch]@16
  float v13; // [sp+64h] [bp-188h]@24
  char v14; // [sp+68h] [bp-184h]@103
  int v15; // [sp+6Ch] [bp-180h]@20
  int startY; // [sp+70h] [bp-17Ch]@49
  int v17; // [sp+74h] [bp-178h]@46
  int damageDone; // [sp+78h] [bp-174h]@1
  int v19; // [sp+7Ch] [bp-170h]@18
  int v20; // [sp+80h] [bp-16Ch]@43
  signed int startX; // [sp+84h] [bp-168h]@47
  int v22; // [sp+88h] [bp-164h]@46
  int creaturesKilled; // [sp+8Ch] [bp-160h]@1
  int v24; // [sp+90h] [bp-15Ch]@43
  int offsetY; // [sp+94h] [bp-158h]@46
  signed int i; // [sp+98h] [bp-154h]@25
  int offsetX; // [sp+9Ch] [bp-150h]@46
  bitmap *bmp; // [sp+A0h] [bp-14Ch]@56
  int v29; // [sp+A4h] [bp-148h]@43
  int y; // [sp+A8h] [bp-144h]@58
  int v31; // [sp+ACh] [bp-140h]@1
  army *target; // [sp+B0h] [bp-13Ch]@1
  float v33; // [sp+B4h] [bp-138h]@25
  int v34; // [sp+B8h] [bp-134h]@49
  int x; // [sp+BCh] [bp-130h]@58
  char v36; // [sp+C0h] [bp-12Ch]@1
  int v37; // [sp+C4h] [bp-128h]@43
  signed int endY; // [sp+C8h] [bp-124h]@49
  int v39; // [sp+CCh] [bp-120h]@53
  int v40; // [sp+D0h] [bp-11Ch]@55
  int v41; // [sp+D4h] [bp-118h]@12
  int v42; // [sp+D8h] [bp-114h]@33
  signed int endX; // [sp+DCh] [bp-110h]@49
  int v44; // [sp+E0h] [bp-10Ch]@49
  int v45; // [sp+E4h] [bp-108h]@53
  int v46; // [sp+E8h] [bp-104h]@55
  char v47; // [sp+ECh] [bp-100h]@1
  char v48; // [sp+F0h] [bp-FCh]@1
  int v49; // [sp+F4h] [bp-F8h]@49
  int animIdx; // [sp+F8h] [bp-F4h]@103
  int a5; // [sp+FCh] [bp-F0h]@103
  char v52; // [sp+100h] [bp-ECh]@1
  char v53; // [sp+104h] [bp-E8h]@18
  int v54; // [sp+108h] [bp-E4h]@49
  int v55; // [sp+10Ch] [bp-E0h]@58
  int a4; // [sp+110h] [bp-DCh]@103
  char a1; // [sp+114h] [bp-D8h]@135
  int v58; // [sp+1DCh] [bp-10h]@18
  int v59; // [sp+1E0h] [bp-Ch]@12
  int spriteIdx; // [sp+1E4h] [bp-8h]@22
  int v61; // [sp+1E8h] [bp-4h]@58

  thisa = this;
  damageDone = 0;
  creaturesKilled = 0;
  v31 = this->facingRight;
  this->field_125 = 0;
  target = &gpCombatManager->creatures[thisa->targetOwner][thisa->targetStackIdx];
  v47 = target->occupiedHex % 13;
  v36 = target->occupiedHex / 13;
  v52 = this->occupiedHex % 13;
  v48 = this->occupiedHex / 13;
  v31 = this->facingRight;
  this->facingRight = v47 > v52 || !(v48 & 1) && v47 == v52;
  if ( this->facingRight != v31 )
  {
    if ( this->creature.creature_flags & TWO_HEXER )
    {
      if ( this->facingRight == 1 )
        --this->occupiedHex;
      else
        ++this->occupiedHex;
    }
    combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
  }
  army::CheckLuck(thisa);
  soundManager::MemorySample(gpSoundManager, thisa->combatSounds[3]);
  combatManager::ResetLimitCreature(gpCombatManager);
  v3 = 80 * thisa->owningSide + 4 * thisa->stackIdx;
  ++*(signed int *)((char *)gpCombatManager->stuffHappenedToCreature[0] + v3);
  combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
  v59 = army::MidX(target);
  v41 = army::MidY(target);
  if ( thisa->creatureIdx == CREATURE_LICH || thisa->creatureIdx == CREATURE_POWER_LICH )
  {
    v59 = gpCombatManager->combatGrid[target->occupiedHex].centerX;
    v41 = gpCombatManager->combatGrid[target->occupiedHex].occupyingCreatureBottomY - 17;
  }
  if ( thisa->facingRight == 1 )
    v12 = *(_WORD *)&thisa->gap_129[178] + gpCombatManager->combatGrid[thisa->occupiedHex].centerX;
  else
    v12 = gpCombatManager->combatGrid[thisa->occupiedHex].centerX - *(_WORD *)&thisa->gap_129[178];
  v58 = *(_WORD *)&thisa->gap_129[180] + gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY;
  v19 = v59 - v12;
  v53 = 0;
  if ( v59 - v12 < 0 )
  {
    v53 = 1;
    v19 = -v19;
  }
  v15 = v41 - v58;
  if ( v19 )
  {
    v2 = (double)v19;
    v33 = (double)-v15 / v2;
    atan();
    v13 = v33 * 180.0 / 3.14159;
    for ( i = 1;
          thisa->gap_129[186] > i
       && (*(float *)&thisa->gap_129[4 * i + 183] + *(float *)&thisa->gap_129[4 * i + 187]) / 2.0 >= v13;
          ++i )
      ;
    if ( thisa->gap_129[186] <= i )
      spriteIdx = thisa->gap_129[186] - 1;
    else
      spriteIdx = i - 1;
  }
  else
  {
    if ( v15 <= 0 )
      spriteIdx = 0;
    else
      spriteIdx = thisa->gap_129[186] - 1;
    v13 = (double)(v15 <= 0 ? 90 : -90);
  }
  if ( v13 <= 25.0 )
  {
    if ( v13 <= -25.0 )
    {
      thisa->animationType = 32;
      v42 = 2;
    }
    else
    {
      thisa->animationType = 30;
      v42 = 1;
    }
  }
  else
  {
    thisa->animationType = 28;
    v42 = 0;
  }
  for ( thisa->animationFrame = 0;
        thisa->gap_129[thisa->animationType + 243] > thisa->animationFrame;
        ++thisa->animationFrame )
  {
    if ( thisa->gap_129[thisa->animationType + 243] - 1 == thisa->animationFrame )
      combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 0, 75, 1, 1);
    else
      combatManager::DrawFrame(gpCombatManager, 1, 1, 0, 0, 75, 1, 1);
    v4 = KBTickCount();
    v2 = (double)*(signed int *)&thisa->gap_129[166]
       * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]
       / (double)thisa->gap_129[thisa->animationType + 243];
    glTimers = (signed __int64)((double)v4 + v2);
  }
  thisa->animationFrame = thisa->gap_129[thisa->animationType + 243] - 1;
  v29 = 25;
  v20 = 25;
  v37 = 31;
  v24 = 25;
  if ( thisa->creatureIdx == CREATURE_LICH || thisa->creatureIdx == CREATURE_POWER_LICH )
  {
    v37 = 26;
    v24 = 7;
    v29 = 10;
    v20 = 10;
  }
  v22 = 0;
  offsetX = 639;
  v17 = 0;
  offsetY = 479;
  if ( thisa->facingRight == 1 )
    startX = gpCombatManager->combatGrid[thisa->occupiedHex].centerX + *(_WORD *)&thisa->gap_129[4 * v42 + 174];
  else
    startX = gpCombatManager->combatGrid[thisa->occupiedHex].centerX - *(_WORD *)&thisa->gap_129[4 * v42 + 174];
  startY = gpCombatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY
         + *(_WORD *)&thisa->gap_129[4 * v42 + 176];
  endX = army::MidX(target);
  endY = army::MidY(target);
  v44 = endX - startX;
  v49 = endY - startY;
  v34 = (signed __int64)sqrt((double)(v49 * v49 + (endX - startX) * (endX - startX)));
  v54 = (v34 + (v37 >> 1)) / v37;
  if ( thisa->creatureIdx != CREATURE_MAGE && thisa->creatureIdx != CREATURE_ARCHMAGE )
  {
    if ( v54 <= 1 )
    {
      v45 = v44;
      v39 = v49;
    }
    else
    {
      v45 = v44 / (v54 - 1);
      v39 = v49 / (v54 - 1);
    }
    v46 = startX;
    v40 = startY;
    thisb = (bitmap *)operator new(26);
    if ( thisb )
      bmp = bitmap::bitmap(thisb, 33, 2 * v29, 2 * v20);
    else
      bmp = 0;
    bitmap::GrabBitmapCareful(bmp, gpWindowManager->screenBuffer, v46 - v29, v40 - v20);
    v61 = v46;
    v55 = v40;
    x = 0;
    y = 0;
    for ( i = 0; i < v54; ++i )
    {
      if ( v61 - v29 < offsetX )
        offsetX = v61 - v29;
      if ( offsetX < 0 )
        offsetX = 0;
      if ( v29 + v61 > v22 )
        v22 = v29 + v61;
      if ( v22 > 639 )
        v22 = 639;
      if ( v55 - v20 < offsetY )
        offsetY = v55 - v20;
      if ( offsetY < 0 )
        offsetY = 0;
      if ( v20 + v55 > v17 )
        v17 = v20 + v55;
      if ( v17 > 442 )
        v17 = 442;
      if ( i )
      {
        bitmap::DrawToBufferCareful(bmp, x, y);
      }
      else
      {
        if ( giMinExtentX > offsetX )
          giMinExtentX = offsetX;
        if ( v22 > giMaxExtentX )
          giMaxExtentX = v22;
        if ( offsetY < giMinExtentY )
          giMinExtentY = offsetY;
        if ( v17 > giMaxExtentY )
          giMaxExtentY = v17;
      }
      x = v46 - v29;
      if ( v46 - v29 < 0 )
        x = 0;
      if ( x + bmp->width > 640 )
        x = 640 - bmp->width;
      y = v40 - v20;
      if ( v40 - v20 < 0 )
        y = 0;
      if ( y + bmp->height > 640 )
        y = 640 - bmp->height;
      bitmap::GrabBitmapCareful(bmp, gpWindowManager->screenBuffer, x, y);
      icon::DrawToBuffer(thisa->missileIcon, v46, v40, spriteIdx, v53);
      if ( i )
      {
        DelayTil(&glTimers);
        heroWindowManager::UpdateScreenRegion(gpWindowManager, offsetX, offsetY, v22 - offsetX + 1, v17 - offsetY + 1);
      }
      else
      {
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          giMinExtentX,
          giMinExtentY,
          giMaxExtentX - giMinExtentX + 1,
          giMaxExtentY - giMinExtentY + 1);
      }
      glTimers = (signed __int64)((double)KBTickCount() + (double)v24 * gfCombatSpeedMod[*(_DWORD *)&combatSpeed]);
      v61 = v46;
      v55 = v40;
      v46 += v45;
      v40 += v39;
      offsetX = v46 - v29;
      v22 = v29 + v46;
      offsetY = v40 - v20;
      v17 = v20 + v40;
    }
    bitmap::DrawToBuffer(bmp, x, y);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, v61 - v29, v55 - v20, 2 * v29, 2 * v20);
    if ( bmp )
      ((void (__thiscall *)(bitmap *))bmp->vtable->cleanUp)(bmp);
  }
  else
  {
    heroWindowManager::UpdateScreenRegion(
      gpWindowManager,
      giMinExtentX,
      giMinExtentY,
      giMaxExtentX - giMinExtentX + 1,
      giMaxExtentY - giMinExtentY + 1);
    DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 115.0));
    combatManager::DoBolt(
      gpCombatManager,
      v1,
      v2,
      1,
      startX,
      startY,
      endX,
      endY,
      0,
      0,
      5,
      4,
      302,
      0,
      0,
      v34 / 15 + 15,
      1,
      0,
      10,
      0);
  }
  if ( !gpCombatManager->heroes[thisa->owningSide]
    || !hero::HasArtifact(gpCombatManager->heroes[thisa->owningSide], ARTIFACT_AMMO_CART) )
    --thisa->creature.shots;
  v14 = thisa->creature.attack;
  animIdx = -1;
  a4 = -1;
  a5 = -1;
  if ( thisa->creatureIdx != CREATURE_LICH && thisa->creatureIdx != CREATURE_POWER_LICH )
  {
    army::DamageEnemy(thisa, target, &damageDone, &creaturesKilled, 1, 0);
  }
  else
  {
    combatManager::ClearEffects();
    for ( i = 0; i < 7; ++i )
    {
      if ( i >= 6 )
        v10 = target->occupiedHex;
      else
        v10 = army::GetAdjacentCellIndex(target, target->occupiedHex, i);
      if ( v10 != -1 )
      {
        if ( gpCombatManager->combatGrid[v10].unitOwner != -1 )
        {
          targ = &gpCombatManager->creatures[gpCombatManager->combatGrid[v10].unitOwner][gpCombatManager->combatGrid[v10].stackIdx];
          if ( !gArmyEffected[gpCombatManager->creatures[gpCombatManager->combatGrid[v10].unitOwner][gpCombatManager->combatGrid[v10].stackIdx].owningSide][gpCombatManager->creatures[gpCombatManager->combatGrid[v10].unitOwner][gpCombatManager->combatGrid[v10].stackIdx].stackIdx] )
          {
            if ( target != targ || i == 6 )
            {
              gArmyEffected[gpCombatManager->creatures[gpCombatManager->combatGrid[v10].unitOwner][gpCombatManager->combatGrid[v10].stackIdx].owningSide][gpCombatManager->creatures[gpCombatManager->combatGrid[v10].unitOwner][gpCombatManager->combatGrid[v10].stackIdx].stackIdx] = 1;
              army::DamageEnemy(thisa, targ, &damageDone, &creaturesKilled, 1, 0);
            }
          }
        }
      }
    }
    thisa->field_FA = 0;
    animIdx = 20;
    a4 = gpCombatManager->combatGrid[v10].centerX;
    a5 = gpCombatManager->combatGrid[v10].occupyingCreatureBottomY - 17;
    soundManager::MemorySample(gpSoundManager, thisa->combatSounds[5]);
  }
  thisa->creature.attack = v14;
  if ( creaturesKilled <= 0 )
  {
    if ( thisa->quantity <= 1 )
      v6 = gArmyNames[thisa->creatureIdx];
    else
      v6 = gArmyNamesPlural[thisa->creatureIdx];
    sprintf(gText, "%s %s %d %s.", v6, &aDo_0[("does" - "do") & ((thisa->quantity > 1) - 1)], damageDone, "damage");
    gText[0] -= 32;
  }
  else if ( damageDone == -1 )
  {
    sprintf(gText, "The mirror image is destroyed!");
  }
  else
  {
    if ( creaturesKilled <= 1 )
      v8 = gArmyNames[target->creatureIdx];
    else
      v8 = gArmyNamesPlural[target->creatureIdx];
    if ( thisa->quantity <= 1 )
      v7 = gArmyNames[thisa->creatureIdx];
    else
      v7 = gArmyNamesPlural[thisa->creatureIdx];
    sprintf(
      gText,
      "%s %s %d %s.\n%d %s %s.",
      v7,
      &aDo[("does" - "do") & ((thisa->quantity > 1) - 1)],
      damageDone,
      "damage",
      creaturesKilled,
      v8,
      &aPerish_0[("perishes" - "perish") & ((creaturesKilled > 1) - 1)]);
    gText[0] -= 32;
  }
  strcpy(&a1, gText);
  if ( thisa->creatureIdx == CREATURE_ARCHMAGE
    && SRandom(1, 100) < 20
    && target
    && army::SpellCastWorks(target, SPELL_ARCHMAGI_DISPEL) )
    target->spellEnemyCreatureAbilityIsCasting = SPELL_ARCHMAGI_DISPEL;
  army::PowEffect(thisa, animIdx, 0, a4, a5);
  combatManager::CombatMessage(gpCombatManager, &a1, 1, 1, 0);
  army::WaitSample(3);
  if ( thisa->facingRight != v31 )
  {
    if ( thisa->creature.creature_flags & 1 )
    {
      if ( thisa->facingRight == 1 )
        ++thisa->occupiedHex;
      else
        --thisa->occupiedHex;
    }
    thisa->facingRight = v31;
  }
  if ( !bSecondAttack
    && (thisa->creatureIdx == CREATURE_ELF
     || thisa->creatureIdx == CREATURE_GRAND_ELF
     || thisa->creatureIdx == CREATURE_RANGER)
    && target->quantity > 0 )
  {
    bSecondAttack = 1;
    army::SpecialAttack(thisa);
    bSecondAttack = 0;
  }
  if ( thisa->effectStrengths[5] || thisa->effectStrengths[7] )
  {
    army::CancelSpellType(thisa, CREATURE_TOOK_TURN_EVENT_CODE);
    combatManager::DrawFrame(gpCombatManager, 1, 0, 0, 0, 75, 1, 1);
  }
}