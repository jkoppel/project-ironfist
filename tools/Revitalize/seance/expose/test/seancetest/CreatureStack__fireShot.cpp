void __thiscall CreatureStack::fireShot(CreatureStack *this)
{
  int v1; // eax@12
  CreatureStack *thisa; // [sp+3Ch] [bp-1B0h]@1
  char *v3; // [sp+40h] [bp-1ACh]@132
  char *v4; // [sp+44h] [bp-1A8h]@127
  char *v5; // [sp+48h] [bp-1A4h]@124
  Bitmap *thisb; // [sp+54h] [bp-198h]@55
  int v7; // [sp+58h] [bp-194h]@0
  CreatureStack *targ; // [sp+5Ch] [bp-190h]@113
  int v9; // [sp+60h] [bp-18Ch]@16
  float v10; // [sp+64h] [bp-188h]@24
  char v11; // [sp+68h] [bp-184h]@103
  int v12; // [sp+6Ch] [bp-180h]@20
  int startY; // [sp+70h] [bp-17Ch]@49
  int v14; // [sp+74h] [bp-178h]@46
  int damageDone; // [sp+78h] [bp-174h]@1
  int v16; // [sp+7Ch] [bp-170h]@18
  int v17; // [sp+80h] [bp-16Ch]@43
  signed int startX; // [sp+84h] [bp-168h]@47
  int v19; // [sp+88h] [bp-164h]@46
  int creaturesKilled; // [sp+8Ch] [bp-160h]@1
  int v21; // [sp+90h] [bp-15Ch]@43
  int offsetY; // [sp+94h] [bp-158h]@46
  signed int hexIdx; // [sp+98h] [bp-154h]@25
  int offsetX; // [sp+9Ch] [bp-150h]@46
  Bitmap *bmp; // [sp+A0h] [bp-14Ch]@56
  int v26; // [sp+A4h] [bp-148h]@43
  int y; // [sp+A8h] [bp-144h]@58
  int v28; // [sp+ACh] [bp-140h]@1
  CreatureStack *target; // [sp+B0h] [bp-13Ch]@1
  float v30; // [sp+B4h] [bp-138h]@25
  int v31; // [sp+B8h] [bp-134h]@49
  int x; // [sp+BCh] [bp-130h]@58
  char v33; // [sp+C0h] [bp-12Ch]@1
  int v34; // [sp+C4h] [bp-128h]@43
  signed int endY; // [sp+C8h] [bp-124h]@49
  int v36; // [sp+CCh] [bp-120h]@53
  int v37; // [sp+D0h] [bp-11Ch]@55
  int v38; // [sp+D4h] [bp-118h]@12
  int v39; // [sp+D8h] [bp-114h]@33
  signed int endX; // [sp+DCh] [bp-110h]@49
  int v41; // [sp+E0h] [bp-10Ch]@49
  int v42; // [sp+E4h] [bp-108h]@53
  int v43; // [sp+E8h] [bp-104h]@55
  char v44; // [sp+ECh] [bp-100h]@1
  char v45; // [sp+F0h] [bp-FCh]@1
  int v46; // [sp+F4h] [bp-F8h]@49
  int animIdx; // [sp+F8h] [bp-F4h]@103
  int a5; // [sp+FCh] [bp-F0h]@103
  char v49; // [sp+100h] [bp-ECh]@1
  char v50; // [sp+104h] [bp-E8h]@18
  int v51; // [sp+108h] [bp-E4h]@49
  int v52; // [sp+10Ch] [bp-E0h]@58
  int a4; // [sp+110h] [bp-DCh]@103
  char message; // [sp+114h] [bp-D8h]@135
  int v55; // [sp+1DCh] [bp-10h]@18
  int v56; // [sp+1E0h] [bp-Ch]@12
  int spriteIdx; // [sp+1E4h] [bp-8h]@22
  int v58; // [sp+1E8h] [bp-4h]@58

  thisa = this;
  damageDone = 0;
  creaturesKilled = 0;
  v28 = this->facingRight;
  this->field_125 = 0;
  target = &combatManager->creatures[thisa->targetOwner][thisa->targetStackIdx];
  v44 = target->occupiedHex % 13;
  v33 = target->occupiedHex / 13;
  v49 = this->occupiedHex % 13;
  v45 = this->occupiedHex / 13;
  v28 = this->facingRight;
  this->facingRight = v44 > v49 || !(v45 & 1) && v44 == v49;
  if ( this->facingRight != v28 )
  {
    if ( this->creature.creature_flags & TWO_HEXER )
    {
      if ( this->facingRight == 1 )
        --this->occupiedHex;
      else
        ++this->occupiedHex;
    }
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
  }
  CreatureStack::rollAndHandleLuck(thisa);
  SoundManager::playSample(soundManager, thisa->combatSounds[3]);
  CombatManager::resetStuffHapenedToCreature(combatManager);
  v1 = 80 * thisa->owningSide + 4 * thisa->stackIdx;
  ++*(signed int *)((char *)combatManager->stuffHappenedToCreature[0] + v1);
  CombatManager::drawBattlefield(combatManager, 0, 1, 0, 1, 75, 1, 1);
  v56 = CreatureStack::getCenterX(target);
  v38 = CreatureStack::getCenterY(target);
  if ( thisa->creatureIdx == CREATURE_LICH || thisa->creatureIdx == CREATURE_POWER_LICH )
  {
    v56 = combatManager->combatGrid[target->occupiedHex].centerX;
    v38 = combatManager->combatGrid[target->occupiedHex].occupyingCreatureBottomY - 17;
  }
  if ( thisa->facingRight == 1 )
    v9 = *(_WORD *)&thisa->form.field_AA[8] + combatManager->combatGrid[thisa->occupiedHex].centerX;
  else
    v9 = combatManager->combatGrid[thisa->occupiedHex].centerX - *(_WORD *)&thisa->form.field_AA[8];
  v55 = *(_WORD *)&thisa->form.field_AA[10] + combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY;
  v16 = v56 - v9;
  v50 = 0;
  if ( v56 - v9 < 0 )
  {
    v50 = 1;
    v16 = -v16;
  }
  v12 = v38 - v55;
  if ( v16 )
  {
    v30 = (double)-v12 / (double)v16;
    v10 = atan(v30) * 180.0 / 3.14159;
    for ( hexIdx = 1;
          thisa->form.field_AA[16] > hexIdx
       && (*(float *)&thisa->form.field_AA[4 * hexIdx + 13] + *(float *)&thisa->form.field_AA[4 * hexIdx + 17]) / 2.0 >= v10;
          ++hexIdx )
      ;
    if ( thisa->form.field_AA[16] <= hexIdx )
      spriteIdx = thisa->form.field_AA[16] - 1;
    else
      spriteIdx = hexIdx - 1;
  }
  else
  {
    if ( v12 <= 0 )
      spriteIdx = 0;
    else
      spriteIdx = thisa->form.field_AA[16] - 1;
    v10 = (double)((((v12 <= 0) - 1) & 0xFFFFFF4C) + 90);
  }
  if ( v10 <= 25.0 )
  {
    if ( v10 <= -25.0 )
    {
      thisa->animationType = 32;
      v39 = 2;
    }
    else
    {
      thisa->animationType = 30;
      v39 = 1;
    }
  }
  else
  {
    thisa->animationType = 28;
    v39 = 0;
  }
  for ( thisa->animationFrame = 0;
        thisa->form.animationLengths[thisa->animationType] > thisa->animationFrame;
        ++thisa->animationFrame )
  {
    if ( thisa->form.animationLengths[thisa->animationType] - 1 == thisa->animationFrame )
      CombatManager::drawBattlefield(combatManager, 0, 1, 0, 0, 75, 1, 1);
    else
      CombatManager::drawBattlefield(combatManager, 1, 1, 0, 0, 75, 1, 1);
    animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                              + (double)thisa->form.field_A6
                                              * combatSpeedPercentages[*(_DWORD *)&combatSpeed]
                                              / (double)thisa->form.animationLengths[thisa->animationType]);
  }
  thisa->animationFrame = thisa->form.animationLengths[thisa->animationType] - 1;
  v26 = 25;
  v17 = 25;
  v34 = 31;
  v21 = 25;
  if ( thisa->creatureIdx == CREATURE_LICH || thisa->creatureIdx == CREATURE_POWER_LICH )
  {
    v34 = 26;
    v21 = 7;
    v26 = 10;
    v17 = 10;
  }
  v19 = 0;
  offsetX = 639;
  v14 = 0;
  offsetY = 479;
  if ( thisa->facingRight == 1 )
    startX = combatManager->combatGrid[thisa->occupiedHex].centerX + *(_WORD *)&thisa->form.field_AA[4 * v39 + 4];
  else
    startX = combatManager->combatGrid[thisa->occupiedHex].centerX - *(_WORD *)&thisa->form.field_AA[4 * v39 + 4];
  startY = combatManager->combatGrid[thisa->occupiedHex].occupyingCreatureBottomY
         + *(_WORD *)&thisa->form.field_AA[4 * v39 + 6];
  endX = CreatureStack::getCenterX(target);
  endY = CreatureStack::getCenterY(target);
  v41 = endX - startX;
  v46 = endY - startY;
  v31 = (signed __int64)sqrt((double)(v46 * v46 + (endX - startX) * (endX - startX)));
  v51 = (v31 + (v34 >> 1)) / v34;
  if ( thisa->creatureIdx != CREATURE_MAGE && thisa->creatureIdx != CREATURE_ARCHMAGE )
  {
    if ( v51 <= 1 )
    {
      v42 = v41;
      v36 = v46;
    }
    else
    {
      v42 = v41 / (v51 - 1);
      v36 = v46 / (v51 - 1);
    }
    v43 = startX;
    v37 = startY;
    thisb = (Bitmap *)operator new(0x1Au);
    if ( thisb )
      bmp = Bitmap_constructor(thisb, 33, 2 * v26, 2 * v17);
    else
      bmp = 0;
    Bitmap::copyFromAllowOOB(bmp, HeroWindowManager::instance->screenBuffer, v43 - v26, v37 - v17);
    v58 = v43;
    v52 = v37;
    x = 0;
    y = 0;
    for ( hexIdx = 0; hexIdx < v51; ++hexIdx )
    {
      if ( v58 - v26 < offsetX )
        offsetX = v58 - v26;
      if ( offsetX < 0 )
        offsetX = 0;
      if ( v26 + v58 > v19 )
        v19 = v26 + v58;
      if ( v19 > 639 )
        v19 = 639;
      if ( v52 - v17 < offsetY )
        offsetY = v52 - v17;
      if ( offsetY < 0 )
        offsetY = 0;
      if ( v17 + v52 > v14 )
        v14 = v17 + v52;
      if ( v14 > 442 )
        v14 = 442;
      if ( hexIdx )
      {
        Bitmap::blitToScreenBufAt(bmp, x, y);
      }
      else
      {
        if ( combatScreenRedrawRectLeft > offsetX )
          combatScreenRedrawRectLeft = offsetX;
        if ( v19 > combatScreenRedrawRectRight )
          combatScreenRedrawRectRight = v19;
        if ( offsetY < combatScreenRedrawRectTop )
          combatScreenRedrawRectTop = offsetY;
        if ( v14 > combatScreenRedrawRectBot )
          combatScreenRedrawRectBot = v14;
      }
      x = v43 - v26;
      if ( v43 - v26 < 0 )
        x = 0;
      if ( x + bmp->width > 640 )
        x = 640 - bmp->width;
      y = v37 - v17;
      if ( v37 - v17 < 0 )
        y = 0;
      if ( y + bmp->height > 640 )
        y = 640 - bmp->height;
      Bitmap::copyFromAllowOOB(bmp, HeroWindowManager::instance->screenBuffer, x, y);
      Icon::drawToScreen(thisa->missileIcon, v43, v37, spriteIdx, v50);
      if ( hexIdx )
      {
        sleepUntilPointer(&animationFrameSwitchTime);
        HeroWindowManager::redrawRectangle(
          HeroWindowManager::instance,
          offsetX,
          offsetY,
          v19 - offsetX + 1,
          v14 - offsetY + 1);
      }
      else
      {
        HeroWindowManager::redrawRectangle(
          HeroWindowManager::instance,
          combatScreenRedrawRectLeft,
          combatScreenRedrawRectTop,
          combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
          combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
      }
      animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                + (double)v21 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
      v58 = v43;
      v52 = v37;
      v43 += v42;
      v37 += v36;
      offsetX = v43 - v26;
      v19 = v26 + v43;
      offsetY = v37 - v17;
      v14 = v17 + v37;
    }
    Bitmap::drawToScreenBuffer(bmp, x, y);
    HeroWindowManager::redrawRectangle(HeroWindowManager::instance, v58 - v26, v52 - v17, 2 * v26, 2 * v17);
    if ( bmp )
      ((void (__thiscall *)(Bitmap *))bmp->vtable->cleanUp)(bmp);
  }
  else
  {
    HeroWindowManager::redrawRectangle(
      HeroWindowManager::instance,
      combatScreenRedrawRectLeft,
      combatScreenRedrawRectTop,
      combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
      combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
    sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 115.0));
    CombatManager::drawBolt(
      combatManager,
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
      v31 / 15 + 15,
      1,
      0,
      10,
      0);
  }
  if ( !combatManager->heroes[thisa->owningSide]
    || !Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_AMMO_CART) )
    --thisa->creature.shots;
  v11 = thisa->creature.attack;
  animIdx = -1;
  a4 = -1;
  a5 = -1;
  if ( thisa->creatureIdx != CREATURE_LICH && thisa->creatureIdx != CREATURE_POWER_LICH )
  {
    CreatureStack::dealDamage(thisa, target, &damageDone, &creaturesKilled, 1, 0);
  }
  else
  {
    zero_out_stack_affected_list();
    for ( hexIdx = 0; hexIdx < 7; ++hexIdx )
    {
      if ( hexIdx >= 6 )
        v7 = target->occupiedHex;
      else
        v7 = CreatureStack::getHexNeighbor(target, target->occupiedHex, hexIdx);
      if ( v7 != -1 )
      {
        if ( combatManager->combatGrid[v7].unitOwner != -1 )
        {
          targ = &combatManager->creatures[combatManager->combatGrid[v7].unitOwner][combatManager->combatGrid[v7].stackIdx];
          if ( !stack_affected_by_aoe[combatManager->creatures[combatManager->combatGrid[v7].unitOwner][combatManager->combatGrid[v7].stackIdx].owningSide][combatManager->creatures[combatManager->combatGrid[v7].unitOwner][combatManager->combatGrid[v7].stackIdx].stackIdx] )
          {
            if ( target != targ || hexIdx == 6 )
            {
              stack_affected_by_aoe[combatManager->creatures[combatManager->combatGrid[v7].unitOwner][combatManager->combatGrid[v7].stackIdx].owningSide][combatManager->creatures[combatManager->combatGrid[v7].unitOwner][combatManager->combatGrid[v7].stackIdx].stackIdx] = 1;
              CreatureStack::dealDamage(thisa, targ, &damageDone, &creaturesKilled, 1, 0);
            }
          }
        }
      }
    }
    thisa->field_FA = 0;
    animIdx = 20;
    a4 = combatManager->combatGrid[v7].centerX;
    a5 = combatManager->combatGrid[v7].occupyingCreatureBottomY - 17;
    SoundManager::playSample(soundManager, thisa->combatSounds[5]);
  }
  thisa->creature.attack = v11;
  if ( creaturesKilled <= 0 )
  {
    if ( thisa->quantity <= 1 )
      v3 = creatureSingularNames[thisa->creatureIdx];
    else
      v3 = creaturePluralNames[thisa->creatureIdx];
    sprintf(globBuf, "%s %s %d %s.", v3, &aDo_0[("does" - "do") & ((thisa->quantity > 1) - 1)], damageDone, "damage");
    globBuf[0] -= 32;
  }
  else
  {
    if ( damageDone == -1 )
    {
      sprintf(globBuf, "The mirror image is destroyed!");
    }
    else
    {
      if ( creaturesKilled <= 1 )
        v5 = creatureSingularNames[target->creatureIdx];
      else
        v5 = creaturePluralNames[target->creatureIdx];
      if ( thisa->quantity <= 1 )
        v4 = creatureSingularNames[thisa->creatureIdx];
      else
        v4 = creaturePluralNames[thisa->creatureIdx];
      sprintf(
        globBuf,
        "%s %s %d %s.\n%d %s %s.",
        v4,
        &aDo[("does" - "do") & ((thisa->quantity > 1) - 1)],
        damageDone,
        "damage",
        creaturesKilled,
        v5,
        &aPerish_0[("perishes" - "perish") & ((creaturesKilled > 1) - 1)]);
      globBuf[0] -= 32;
    }
  }
  strcpy(&message, globBuf);
  if ( thisa->creatureIdx == CREATURE_ARCHMAGE
    && nextRandomInt(1, 100) < 20
    && target
    && CreatureStack::rollSpellSucceeds(target, SPELL_ARCHMAGI_DISPEL) )
    target->spellEnemyCreatureAbilityIsCasting = SPELL_ARCHMAGI_DISPEL;
  CreatureStack::doAttackAndDamageTakenAnimations(thisa, animIdx, 0, a4, a5);
  CombatManager::displayCombatMessage(combatManager, &message, 1, 1, 0);
  doNothing3(3);
  if ( thisa->facingRight != v28 )
  {
    if ( thisa->creature.creature_flags & 1 )
    {
      if ( thisa->facingRight == 1 )
        ++thisa->occupiedHex;
      else
        --thisa->occupiedHex;
    }
    thisa->facingRight = v28;
  }
  if ( !firingSecondShot
    && (thisa->creatureIdx == CREATURE_ELF
     || thisa->creatureIdx == CREATURE_GRAND_ELF
     || thisa->creatureIdx == CREATURE_RANGER)
    && target->quantity > 0 )
  {
    firingSecondShot = 1;
    CreatureStack::fireShot(thisa);
    firingSecondShot = 0;
  }
  if ( thisa->effectStrengths[5] || thisa->effectStrengths[7] )
  {
    CreatureStack::handleCreatureEvent(thisa, CREATURE_TOOK_TURN_EVENT_CODE);
    CombatManager::drawBattlefield(combatManager, 1, 0, 0, 0, 75, 1, 1);
  }
}
