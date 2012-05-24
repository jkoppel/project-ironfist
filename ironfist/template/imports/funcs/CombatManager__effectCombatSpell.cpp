{
  int v5; // ebx@0
  int v6; // eax@12
  Icon *v7; // ST84_4@135
  int v8; // ST38_4@135
  int v9; // eax@135
  int v10; // ST10_4@144
  int v11; // eax@144
  char *v12; // eax@186
  int v13; // ST80_4@186
  int v14; // [sp+14h] [bp-ACh]@111
  CombatManager *thisa; // [sp+1Ch] [bp-A4h]@1
  char *v16; // [sp+20h] [bp-A0h]@142
  char *v17; // [sp+24h] [bp-9Ch]@133
  char *v18; // [sp+28h] [bp-98h]@128
  float a7[9]; // [sp+44h] [bp-7Ch]@135
  int knownHex; // [sp+68h] [bp-58h]@97
  CreatureStack *thisb; // [sp+6Ch] [bp-54h]@88
  int oldDefense; // [sp+70h] [bp-50h]@119
  int centX; // [sp+74h] [bp-4Ch]@54
  int centY; // [sp+78h] [bp-48h]@54
  CreatureStack *stack; // [sp+7Ch] [bp-44h]@17
  int j; // [sp+84h] [bp-3Ch]@184
  STACK_MODIFYING_EFFECT effect; // [sp+8Ch] [bp-34h]@165
  int damage; // [sp+90h] [bp-30h]@122
  int owner; // [sp+94h] [bp-2Ch]@41
  char buf[8]; // [sp+98h] [bp-28h]@82
  int spellpower; // [sp+A8h] [bp-18h]@46
  sample_resource res; // [sp+ACh] [bp-14h]@9
  Spell spell; // [sp+B4h] [bp-Ch]@77
  int stackidx; // [sp+B8h] [bp-8h]@41
  int i; // [sp+BCh] [bp-4h]@182
  int hexIdxa; // [sp+CCh] [bp+Ch]@88

  thisa = this;
  if ( !isCreatureAbility )
  {
    if ( this->eagleEyeSpellLearned[1 - this->currentActionSide] == SPELL_NONE )
    {
      if ( this->heroes[1 - this->currentActionSide] )
      {
        if ( !Hero::hasSpell(this->heroes[1 - this->currentActionSide], proto_spell) )
        {
          if ( thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[11] )
          {
            if ( thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[11] + 1 >= spell_table[proto_spell].level )
            {
              v5 = thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[11];
              if ( v5 >= nextRandomInt(0, 9) )
                thisa->eagleEyeSpellLearned[1 - thisa->currentActionSide] = proto_spell;
            }
          }
        }
      }
    }
  }
  res = stru_5230F8;
  if ( thisa->field_F2B7 )
  {
    CombatManager::resetStuffHapenedToCreature(thisa);
    if ( checkHexGridIdxBounds(thisa->field_F2BB) && thisa->combatGrid[thisa->field_F2BB].unitOwner >= 0 )
    {
      v6 = 80 * thisa->combatGrid[thisa->field_F2BB].unitOwner + 4 * thisa->combatGrid[thisa->field_F2BB].stackIdx;
      ++*(signed int *)((char *)thisa->stuffHappenedToCreature[0] + v6);
    }
    thisa->field_F2B7 = 0;
    thisa->field_F2BB = -1;
    CombatManager::drawBattlefield(combatManager, 1, 1, 0, 0, 75, 1, 1);
  }
  if ( !isCreatureAbility && thisa->heroes[thisa->currentActionSide] )
    Hero::spendSpellPointsFor(thisa->heroes[thisa->currentActionSide], proto_spell);
  stack = 0;
  if ( proto_spell
    && proto_spell != SPELL_FIREBLAST
    && proto_spell != SPELL_COLD_RING
    && proto_spell != SPELL_METEOR_SHOWER
    && proto_spell != SPELL_SUMMON_EARTH_ELEMENTAL
    && proto_spell != SPELL_SUMMON_AIR_ELEMENTAL
    && proto_spell != SPELL_SUMMON_WATER_ELEMENTAL
    && proto_spell != SPELL_SUMMON_FIRE_ELEMENTAL
    && proto_spell != SPELL_MASS_BLESS
    && proto_spell != SPELL_MASS_HASTE
    && proto_spell != SPELL_EARTHQUAKE
    && proto_spell != SPELL_MASS_CURSE
    && proto_spell != SPELL_MASS_CURE
    && proto_spell != SPELL_HOLY_WORD
    && proto_spell != SPELL_HOLY_SHOUT
    && proto_spell != SPELL_DEATH_RIPPLE
    && proto_spell != SPELL_DEATH_WAVE
    && proto_spell != SPELL_MASS_SHIELD
    && proto_spell != SPELL_ARMAGEDDON
    && proto_spell != SPELL_ELEMENTAL_STORM
    && proto_spell != SPELL_MASS_DISPEL )
  {
    if ( checkHexGridIdxBounds(hexIdx) && thisa->combatGrid[hexIdx].unitOwner >= 0 )
    {
      stack = &thisa->creatures[thisa->combatGrid[hexIdx].unitOwner][thisa->combatGrid[hexIdx].stackIdx];
      owner = thisa->combatGrid[hexIdx].unitOwner;
      stackidx = thisa->combatGrid[hexIdx].stackIdx;
    }
    else
    {
      stack = NULL;
    }
  }
  else
  {
    stack = NULL;
  }
  if ( !isCreatureAbility )
    *(&thisa->field_353F + thisa->currentActionSide) = 1;
  if ( isCreatureAbility )
  {
    spellpower = 3;
  }
  else
  {
    spellpower = thisa->heroSpellpowers[thisa->currentActionSide];
    if ( Hero::hasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_ENCHANTED_HOURGLASS)
      && spell_table[proto_spell].attributes & ATTR_DURATIONED_SPELL )
      spellpower += 2;
    if ( Hero::hasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_WIZARDS_HAT)
      && spell_table[proto_spell].attributes & ATTR_DURATIONED_SPELL )
      spellpower += 10;
  }
  if ( !isCreatureAbility )
  {
    centX = -1;
    centY = -1;
    if ( stack )
    {
      centX = CreatureStack::getCenterX(stack);
      centY = CreatureStack::getCenterY(stack);
    }
    else
    {
      if ( !proto_spell
        || proto_spell == SPELL_FIREBLAST
        || proto_spell == SPELL_COLD_RING
        || proto_spell == SPELL_METEOR_SHOWER )
      {
        centX = thisa->combatGrid[hexIdx].centerX;
        centY = thisa->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
      }
    }
    if ( centX == -1 )
    {
      thisa->heroIconIdxRelated[thisa->currentActionSide] = 3;
    }
    else
    {
      if ( thisa->currentActionSide )
      {
        couldBeWandX = 610 - *(__int16 *)((char *)&word_4F4C28 + 129 * thisa->heroType[thisa->currentActionSide]);
        couldBeWandY = *(__int16 *)((char *)&word_4F4C2C + 129 * thisa->heroType[thisa->currentActionSide]) + 148;
      }
      else
      {
        couldBeWandX = *(__int16 *)((char *)&word_4F4C28 + 129 * thisa->heroType[thisa->currentActionSide]) + 30;
        couldBeWandY = *(__int16 *)((char *)&word_4F4C2C + 129 * thisa->heroType[thisa->currentActionSide]) + 183;
      }
      if ( (centX - couldBeWandX) * (thisa->currentActionSide < 1u ? 1 : -1) >= centY - couldBeWandY )
      {
        thisa->heroIconIdxRelated[thisa->currentActionSide] = 5;
      }
      else
      {
        thisa->heroIconIdxRelated[thisa->currentActionSide] = 7;
        if ( thisa->currentActionSide )
        {
          couldBeWandX = 610 - *(__int16 *)((char *)&word_4F4C2A + 129 * thisa->heroType[thisa->currentActionSide]);
          couldBeWandY = *(__int16 *)((char *)&word_4F4C2E + 129 * thisa->heroType[thisa->currentActionSide]) + 148;
        }
        else
        {
          couldBeWandX = *(__int16 *)((char *)&word_4F4C2A + 129 * thisa->heroType[thisa->currentActionSide]) + 30;
          couldBeWandY = *(__int16 *)((char *)&word_4F4C2E + 129 * thisa->heroType[thisa->currentActionSide]) + 183;
        }
      }
    }
    for ( thisa->countRelatedToSpellAnimation[thisa->currentActionSide] = 0;
          byte_4F4C30[thisa->heroType[thisa->currentActionSide]][thisa->heroIconIdxRelated[thisa->currentActionSide] + 1] > thisa->countRelatedToSpellAnimation[thisa->currentActionSide];
          ++thisa->countRelatedToSpellAnimation[thisa->currentActionSide] )
      CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
    --thisa->countRelatedToSpellAnimation[thisa->currentActionSide];
  }
  spell = proto_spell;
  if ( proto_spell == SPELL_MEDUSA_PETRIFY )
    spell = SPELL_PARALYZE;
  if ( proto_spell == SPELL_ARCHMAGI_DISPEL )
    spell = SPELL_DISPEL_MAGIC;
  if ( strlen(spell_table[spell].short_name) )
    sprintf(buf, "%s.82M", &spell_table[spell]);
  if ( isCreatureAbility || !stack || CreatureStack::rollSpellSucceeds(stack, proto_spell) )
  {
    res = playSample(buf);
    switch ( proto_spell )
    {
      case SPELL_TELEPORT:
        thisb = stack;
        hexIdxa = a5;
        sub_4A3DB0(thisa, stack->owningSide, stack->stackIdx, 1);
        thisa->combatGrid[stack->occupiedHex].unitOwner = -1;
        thisa->combatGrid[thisb->occupiedHex].stackIdx = -1;
        if ( thisa->combatGrid[thisb->occupiedHex].notPrimarySquareOfTwoHexer )
        {
          if ( thisa->combatGrid[thisb->occupiedHex].notPrimarySquareOfTwoHexer == 1 )
          {
            thisa->combatGrid[thisb->occupiedHex - 1].unitOwner = -1;
            thisa->combatGrid[thisb->occupiedHex - 1].stackIdx = -1;
          }
        }
        else
        {
          thisa->combatGrid[thisb->occupiedHex + 1].unitOwner = -1;
          thisa->combatGrid[thisb->occupiedHex + 1].stackIdx = -1;
        }
        if ( !combatGraphicsOff )
          waitForSampleToFinish(-1, res);
        if ( !combatGraphicsOff )
        {
          sprintf(globBuf, "telptin.82m");
          res = playSample(globBuf);
        }
        if ( thisb->creature.creature_flags & TWO_HEXER )
        {
          knownHex = a5;
          if ( thisb->facingRight == 1 )
          {
            if ( (knownHex = CreatureStack::getHexNeighbor(thisb, knownHex, 1), knownHex == -1)
              || thisa->combatGrid[knownHex].unitOwner != -1
              && (thisa->combatGrid[knownHex].unitOwner != owner || thisa->combatGrid[knownHex].stackIdx != stackidx)
              || thisa->combatGrid[knownHex].probablyIsBlocked )
              hexIdxa = a5 - 1;
          }
          if ( !thisb->facingRight )
          {
            if ( (knownHex = CreatureStack::getHexNeighbor(thisb, knownHex, 4), knownHex == -1)
              || thisa->combatGrid[knownHex].unitOwner != -1
              && (thisa->combatGrid[knownHex].unitOwner != owner || thisa->combatGrid[knownHex].stackIdx != stackidx)
              || thisa->combatGrid[knownHex].probablyIsBlocked )
              ++hexIdxa;
          }
          thisb->occupiedHex = hexIdxa;
          v14 = thisb->facingRight;
          if ( v14 )
          {
            if ( v14 == 1 )
            {
              thisa->combatGrid[thisb->occupiedHex].unitOwner = owner;
              thisa->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
              thisa->combatGrid[thisb->occupiedHex].notPrimarySquareOfTwoHexer = 0;
              thisa->combatGrid[thisb->occupiedHex + 1].unitOwner = owner;
              thisa->combatGrid[thisb->occupiedHex + 1].stackIdx = stackidx;
              thisa->combatGrid[thisb->occupiedHex + 1].notPrimarySquareOfTwoHexer = 1;
            }
          }
          else
          {
            thisa->combatGrid[thisb->occupiedHex].unitOwner = owner;
            thisa->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
            thisa->combatGrid[thisb->occupiedHex].notPrimarySquareOfTwoHexer = 1;
            thisa->combatGrid[thisb->occupiedHex - 1].unitOwner = owner;
            thisa->combatGrid[thisb->occupiedHex - 1].stackIdx = stackidx;
            thisa->combatGrid[thisb->occupiedHex - 1].notPrimarySquareOfTwoHexer = 0;
          }
          sub_4A3DB0(thisa, thisb->owningSide, thisb->stackIdx, 2);
        }
        else
        {
          thisb->occupiedHex = a5;
          thisa->combatGrid[thisb->occupiedHex].unitOwner = owner;
          thisa->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
          thisa->combatGrid[thisb->occupiedHex].notPrimarySquareOfTwoHexer = -1;
          sub_4A3DB0(thisa, thisb->owningSide, thisb->stackIdx, 2);
        }
        break;
      case SPELL_DISRUPTING_RAY:
        oldDefense = stack->creature.defense;
        stack->creature.defense -= 3;
        if ( stack->creature.defense < 1 )
          stack->creature.defense = 1;
        sprintf(globBuf, "The disrupting ray reduces defense by %d.", oldDefense - stack->creature.defense);
        CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
        CombatManager::doStraightRayGraphics(thisa, v5, hexIdx, proto_spell);
        sub_4A3DB0(thisa, stack->owningSide, stack->stackIdx, 0);
        break;
      case SPELL_COLD_RAY:
        sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 175.0));
        damage = 20 * spellpower;
        if ( stack->creatureIdx == CREATURE_FIRE_ELEMENTAL )
          damage *= 2;
        if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
          damage = (signed __int64)((double)damage * 0.5);
        modifySpellDamageForArtifacts(
          &damage,
          SPELL_COLD_RAY,
          thisa->heroes[thisa->currentActionSide],
          thisa->heroes[1 - thisa->currentActionSide]);
        if ( stack->quantity <= 1 )
          v18 = creatureSingularNames[stack->creatureIdx];
        else
          v18 = creaturePluralNames[stack->creatureIdx];
        sprintf(globBuf, "The cold ray does %d\n damage to the %s.", damage, v18);
        CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
        CombatManager::doStraightRayGraphics(thisa, v5, hexIdx, proto_spell);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[32].creatureEffectAnimationIdx, 0, 0);
        CreatureStack::takeDamage(stack, damage, SPELL_NONE);
        CreatureStack::doAttackAndDamageTakenAnimations(stack, -1, 1, -1, -1);
        break;
      case SPELL_CHAIN_LIGHTNING:
        CombatManager::castChainLightning(thisa, hexIdx, spellpower);
        break;
      case SPELL_MAGIC_ARROW:
        sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 100.0));
        damage = 10 * spellpower;
        modifySpellDamageForArtifacts(
          &damage,
          SPELL_MAGIC_ARROW,
          thisa->heroes[thisa->currentActionSide],
          thisa->heroes[1 - thisa->currentActionSide]);
        if ( stack->quantity <= 1 )
          v17 = creatureSingularNames[stack->creatureIdx];
        else
          v17 = creaturePluralNames[stack->creatureIdx];
        sprintf(globBuf, "The magic arrow does %d\n damage to the %s.", damage, v17);
        CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
        v7 = ResourceManager::getIconByFilename(resourceManager, "keep.icn");
        LODWORD(a7[0]) = 0x42B40000u;
        LODWORD(a7[1]) = 0x42890000u;
        LODWORD(a7[2]) = 0x42340000u;
        LODWORD(a7[3]) = 0x41A66666u;
        LODWORD(a7[4]) = 0;
        LODWORD(a7[5]) = 0xC1A66666u;
        LODWORD(a7[6]) = 0xC2340000u;
        LODWORD(a7[7]) = 0xC2890000u;
        LODWORD(a7[8]) = 0xC2B40000u;
        v8 = CreatureStack::getCenterY(stack);
        v9 = CreatureStack::getCenterX(stack);
        CombatManager::animateMagicOrGarrisonArrow(couldBeWandX, couldBeWandY, v9, v8, a7, v7);
        ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v7);
        CreatureStack::takeDamage(stack, damage, SPELL_NONE);
        CreatureStack::doAttackAndDamageTakenAnimations(stack, -1, 1, -1, -1);
        break;
      case SPELL_LIGHTNING_BOLT:
        damage = 25 * spellpower;
        if ( stack->creatureIdx == CREATURE_AIR_ELEMENTAL )
          damage *= 2;
        if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
          damage = (signed __int64)((double)damage * 0.5);
        modifySpellDamageForArtifacts(
          &damage,
          SPELL_LIGHTNING_BOLT,
          thisa->heroes[thisa->currentActionSide],
          thisa->heroes[1 - thisa->currentActionSide]);
        if ( stack->quantity <= 1 )
          v16 = creatureSingularNames[stack->creatureIdx];
        else
          v16 = creaturePluralNames[stack->creatureIdx];
        sprintf(globBuf, "The lightning bolt does %d\n damage to the %s.", damage, v16);
        CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
        v10 = CreatureStack::getCenterY(stack);
        v11 = CreatureStack::getCenterX(stack);
        CombatManager::drawBolt(
          thisa,
          1,
          couldBeWandX,
          couldBeWandY,
          v11,
          v10,
          150,
          100,
          9,
          2,
          301,
          -40,
          40,
          30,
          1,
          0,
          0,
          1);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[2].creatureEffectAnimationIdx, 0, 0);
        CreatureStack::takeDamage(stack, damage, SPELL_NONE);
        CreatureStack::doAttackAndDamageTakenAnimations(stack, -1, 1, -1, -1);
        break;
      case SPELL_MASS_CURE:
      case SPELL_MASS_HASTE:
      case SPELL_MASS_SLOW:
      case SPELL_MASS_BLESS:
      case SPELL_MASS_CURSE:
      case SPELL_HOLY_WORD:
      case SPELL_HOLY_SHOUT:
      case SPELL_MASS_DISPEL:
      case SPELL_DEATH_RIPPLE:
      case SPELL_DEATH_WAVE:
      case SPELL_MASS_SHIELD:
        CombatManager::castMassSpell(thisa, proto_spell, spellpower);
        break;
      case SPELL_MIRROR_IMAGE:
        CombatManager::castMirrorImage(thisa, hexIdx);
        break;
      case SPELL_SUMMON_EARTH_ELEMENTAL:
        CombatManager::summonElemental(thisa, CREATURE_EARTH_ELEMENTAL, spellpower);
        break;
      case SPELL_SUMMON_AIR_ELEMENTAL:
        CombatManager::summonElemental(thisa, CREATURE_AIR_ELEMENTAL, spellpower);
        break;
      case SPELL_SUMMON_FIRE_ELEMENTAL:
        CombatManager::summonElemental(thisa, CREATURE_FIRE_ELEMENTAL, spellpower);
        break;
      case SPELL_SUMMON_WATER_ELEMENTAL:
        CombatManager::summonElemental(thisa, CREATURE_WATER_ELEMENTAL, spellpower);
        break;
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_ANIMATE_DEAD:
        CombatManager::castResurrectionSpell(thisa, proto_spell, hexIdx, spellpower);
        break;
      case SPELL_CURE:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[5].creatureEffectAnimationIdx, 0, 0);
        CreatureStack::cure(stack, spellpower);
        CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
        break;
      case SPELL_SLOW:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_SLOW, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[11].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_HASTE:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, 0, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[9].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_SHIELD:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_SHIELD, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[41].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_DRAGON_SLAYER:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_DRAGON_SLAYER, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[37].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_BLESS:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_BLESS, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[14].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_STONESKIN:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_STONESKIN, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[16].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_STEELSKIN:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_STEELSKIN, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[17].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_CURSE:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_CURSE, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[18].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_BERZERKER:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_BERSERKER, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[26].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_HYPNOTIZE:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_HYPNOTIZE, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[31].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_PARALYZE:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_PARALYZE, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[30].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_ARCHMAGI_DISPEL:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::removePositiveEffects(stack);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[23].creatureEffectAnimationIdx, 0, 1);
        break;
      case SPELL_DISPEL_MAGIC:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::removePositiveEffects(stack);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[23].creatureEffectAnimationIdx, 0, 0);
        for ( effect = 0; (signed int)effect < 15; ++effect )
          CreatureStack::removeEffect(stack, effect);
        break;
      case SPELL_BLIND:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_BLIND, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[13].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_BLOOD_LUST:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CombatManager::animateCreatureColorChange(thisa, stack, CREATURE_RED);
        CreatureStack::receiveEffect(stack, EFFECT_BLOOD_LUST, 3);
        break;
      case SPELL_ANTI_MAGIC:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CreatureStack::receiveEffect(stack, EFFECT_ANTI_MAGIC, spellpower);
        CreatureStack::doEffectAnimation(stack, (unsigned __int8)spell_table[22].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_MEDUSA_PETRIFY:
        CombatManager::showGenericCastMessage(thisa, isCreatureAbility, proto_spell, stack);
        CombatManager::castMedusaPetrify(thisa, stack);
        break;
      case SPELL_COLD_RING:
        CombatManager::castElementalAOE(thisa, hexIdx, SPELL_COLD_RING);
        break;
      case SPELL_FIREBALL:
        CombatManager::castElementalAOE(thisa, hexIdx, 0);
        break;
      case SPELL_FIREBLAST:
        CombatManager::castElementalAOE(thisa, hexIdx, SPELL_FIREBLAST);
        break;
      case SPELL_METEOR_SHOWER:
        CombatManager::castMeteorShower(thisa, (unsigned __int8)v5, hexIdx);
        break;
      case SPELL_ELEMENTAL_STORM:
        CombatManager::castElementalStorm(thisa);
        break;
      case SPELL_ARMAGEDDON:
        CombatManager::castArmageddon(thisa, (unsigned __int8)v5);
        break;
      case SPELL_EARTHQUAKE:
        CombatManager::castEarthquake(thisa);
        break;
      default:
        CombatManager::castMiscEffectSpellOnHex(thisa, hexIdx);
        break;
    }
  }
  else
  {
    CreatureStack::doResistSpell(stack, proto_spell);
  }
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; thisa->numCreatures[i] > j; ++j )
    {
      v12 = (char *)thisa + 24234 * i + 1154 * j;
      v13 = (int)(v12 + 13647);
      *(_DWORD *)(v12 + 13865) = 0;
      *(_DWORD *)(v13 + 222) = *(_DWORD *)(v13 + 218);
      *(_DWORD *)(v13 + 214) = *(_DWORD *)(v13 + 222);
      *(_DWORD *)(v13 + 6) = 1;
      *(_BYTE *)v13 = 0;
      *(_DWORD *)(v13 + 154) = -1;
    }
  }
  if ( !isCreatureAbility )
  {
    ++thisa->heroIconIdxRelated[thisa->currentActionSide];
    for ( thisa->countRelatedToSpellAnimation[thisa->currentActionSide] = 0;
          byte_4F4C30[thisa->heroType[thisa->currentActionSide]][thisa->heroIconIdxRelated[thisa->currentActionSide] + 1] > thisa->countRelatedToSpellAnimation[thisa->currentActionSide];
          ++thisa->countRelatedToSpellAnimation[thisa->currentActionSide] )
      CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
    thisa->heroIconIdxRelated[thisa->currentActionSide] = 0;
    thisa->countRelatedToSpellAnimation[thisa->currentActionSide] = 0;
    CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  }
  waitForSampleToFinish(-1, res);
  sub_440A90(thisa);
}
