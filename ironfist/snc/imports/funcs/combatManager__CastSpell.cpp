{
  int v5; // ebx@0
  double v6; // st6@0
  int v7; // eax@12
  icon *v8; // ST84_4@135
  int v9; // ST38_4@135
  int v10; // eax@135
  int v11; // ST10_4@144
  int v12; // eax@144
  char *v13; // eax@186
  int v14; // ST80_4@186
  int v15; // [sp+14h] [bp-ACh]@111
  combatManager *thisa; // [sp+1Ch] [bp-A4h]@1
  char *v17; // [sp+20h] [bp-A0h]@142
  char *v18; // [sp+24h] [bp-9Ch]@133
  char *v19; // [sp+28h] [bp-98h]@128
  float a7[9]; // [sp+44h] [bp-7Ch]@135
  int knownHex; // [sp+68h] [bp-58h]@97
  army *thisb; // [sp+6Ch] [bp-54h]@88
  int oldDefense; // [sp+70h] [bp-50h]@119
  int centX; // [sp+74h] [bp-4Ch]@54
  int centY; // [sp+78h] [bp-48h]@54
  army *stack; // [sp+7Ch] [bp-44h]@17
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
        if ( !hero::HasSpell(this->heroes[1 - this->currentActionSide], proto_spell) )
        {
          if ( thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[11] )
          {
            if ( thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[11] + 1 >= gsSpellInfo[proto_spell].level )
            {
              v5 = thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[11];
              if ( v5 >= SRandom(0, 9) )
                thisa->eagleEyeSpellLearned[1 - thisa->currentActionSide] = proto_spell;
            }
          }
        }
      }
    }
  }
  res = NULL_SAMPLE2;
  if ( thisa->field_F2B7 )
  {
    combatManager::ResetLimitCreature(thisa);
    if ( ValidHex(thisa->field_F2BB) && thisa->combatGrid[thisa->field_F2BB].unitOwner >= 0 )
    {
      v7 = 80 * thisa->combatGrid[thisa->field_F2BB].unitOwner + 4 * thisa->combatGrid[thisa->field_F2BB].stackIdx;
      ++*(signed int *)((char *)thisa->stuffHappenedToCreature[0] + v7);
    }
    thisa->field_F2B7 = 0;
    thisa->field_F2BB = -1;
    combatManager::DrawFrame(gpCombatManager, 1, 1, 0, 0, 75, 1, 1);
  }
  if ( !isCreatureAbility && thisa->heroes[thisa->currentActionSide] )
    hero::UseSpell(thisa->heroes[thisa->currentActionSide], proto_spell);
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
    if ( ValidHex(hexIdx) && thisa->combatGrid[hexIdx].unitOwner >= 0 )
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
    if ( hero::HasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_ENCHANTED_HOURGLASS)
      && gsSpellInfo[proto_spell].attributes & ATTR_DURATIONED_SPELL )
      spellpower += 2;
    if ( hero::HasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_WIZARDS_HAT)
      && gsSpellInfo[proto_spell].attributes & ATTR_DURATIONED_SPELL )
      spellpower += 10;
  }
  if ( !isCreatureAbility )
  {
    centX = -1;
    centY = -1;
    if ( stack )
    {
      centX = army::MidX(stack);
      centY = army::MidY(stack);
    }
    else if ( proto_spell == SPELL_FIREBALL
  || proto_spell == SPELL_FIREBLAST
  || proto_spell == SPELL_COLD_RING
  || proto_spell == SPELL_METEOR_SHOWER )
    {
      centX = thisa->combatGrid[hexIdx].centerX;
      centY = thisa->combatGrid[hexIdx].occupyingCreatureBottomY - 17;
    }
    if ( centX == -1 )
    {
      thisa->heroIconIdxRelated[thisa->currentActionSide] = 3;
    }
    else
    {
      if ( thisa->currentActionSide )
      {
        castX = 610 - *(__int16 *)((char *)&sCmbtHero + 129 * thisa->heroType[thisa->currentActionSide]);
        castY = *(__int16 *)((char *)&word_4F4C2C + 129 * thisa->heroType[thisa->currentActionSide]) + 148;
      }
      else
      {
        castX = *(__int16 *)((char *)&sCmbtHero + 129 * thisa->heroType[thisa->currentActionSide]) + 30;
        castY = *(__int16 *)((char *)&word_4F4C2C + 129 * thisa->heroType[thisa->currentActionSide]) + 183;
      }
      if ( (centX - castX) * (thisa->currentActionSide < 1u ? 1 : -1) >= centY - castY )
      {
        thisa->heroIconIdxRelated[thisa->currentActionSide] = 5;
      }
      else
      {
        thisa->heroIconIdxRelated[thisa->currentActionSide] = 7;
        if ( thisa->currentActionSide )
        {
          castX = 610 - *(__int16 *)((char *)&word_4F4C2A + 129 * thisa->heroType[thisa->currentActionSide]);
          castY = *(__int16 *)((char *)&word_4F4C2E + 129 * thisa->heroType[thisa->currentActionSide]) + 148;
        }
        else
        {
          castX = *(__int16 *)((char *)&word_4F4C2A + 129 * thisa->heroType[thisa->currentActionSide]) + 30;
          castY = *(__int16 *)((char *)&word_4F4C2E + 129 * thisa->heroType[thisa->currentActionSide]) + 183;
        }
      }
    }
    for ( thisa->countRelatedToSpellAnimation[thisa->currentActionSide] = 0;
          byte_4F4C30[thisa->heroType[thisa->currentActionSide]][thisa->heroIconIdxRelated[thisa->currentActionSide] + 1] > thisa->countRelatedToSpellAnimation[thisa->currentActionSide];
          ++thisa->countRelatedToSpellAnimation[thisa->currentActionSide] )
      combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
    --thisa->countRelatedToSpellAnimation[thisa->currentActionSide];
  }
  spell = proto_spell;
  if ( proto_spell == SPELL_MEDUSA_PETRIFY )
    spell = SPELL_PARALYZE;
  if ( proto_spell == SPELL_ARCHMAGI_DISPEL )
    spell = SPELL_DISPEL_MAGIC;
  if ( strlen((int)&gsSpellInfo[spell]) )
    sprintf(buf, "%s.82M", &gsSpellInfo[spell]);
  if ( isCreatureAbility || !stack || army::SpellCastWorks(stack, proto_spell) )
  {
    res = LoadPlaySample(buf);
    switch ( proto_spell )
    {
      case SPELL_TELEPORT:
        thisb = stack;
        hexIdxa = a5;
        combatManager::RippleCreature(thisa, stack->owningSide, stack->stackIdx, 1);
        thisa->combatGrid[stack->occupiedHex].unitOwner = -1;
        thisa->combatGrid[thisb->occupiedHex].stackIdx = -1;
        if ( thisa->combatGrid[thisb->occupiedHex].isOccupierNonPrimaryHex )
        {
          if ( thisa->combatGrid[thisb->occupiedHex].isOccupierNonPrimaryHex == 1 )
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
        if ( !gbNoShowCombat )
          WaitEndSample(-1, res);
        if ( !gbNoShowCombat )
        {
          sprintf(gText, "telptin.82m");
          res = LoadPlaySample(gText);
        }
        if ( thisb->creature.creature_flags & TWO_HEXER )
        {
          knownHex = a5;
          if ( thisb->facingRight == 1 )
          {
            if ( (knownHex = army::GetAdjacentCellIndex(thisb, knownHex, 1), knownHex == -1)
              || thisa->combatGrid[knownHex].unitOwner != -1
              && (thisa->combatGrid[knownHex].unitOwner != owner || thisa->combatGrid[knownHex].stackIdx != stackidx)
              || thisa->combatGrid[knownHex].isBlocked )
              hexIdxa = a5 - 1;
          }
          if ( !thisb->facingRight )
          {
            if ( (knownHex = army::GetAdjacentCellIndex(thisb, knownHex, 4), knownHex == -1)
              || thisa->combatGrid[knownHex].unitOwner != -1
              && (thisa->combatGrid[knownHex].unitOwner != owner || thisa->combatGrid[knownHex].stackIdx != stackidx)
              || thisa->combatGrid[knownHex].isBlocked )
              ++hexIdxa;
          }
          thisb->occupiedHex = hexIdxa;
          v15 = thisb->facingRight;
          if ( v15 )
          {
            if ( v15 == 1 )
            {
              thisa->combatGrid[thisb->occupiedHex].unitOwner = owner;
              thisa->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
              thisa->combatGrid[thisb->occupiedHex].isOccupierNonPrimaryHex = 0;
              thisa->combatGrid[thisb->occupiedHex + 1].unitOwner = owner;
              thisa->combatGrid[thisb->occupiedHex + 1].stackIdx = stackidx;
              thisa->combatGrid[thisb->occupiedHex + 1].isOccupierNonPrimaryHex = 1;
            }
          }
          else
          {
            thisa->combatGrid[thisb->occupiedHex].unitOwner = owner;
            thisa->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
            thisa->combatGrid[thisb->occupiedHex].isOccupierNonPrimaryHex = 1;
            thisa->combatGrid[thisb->occupiedHex - 1].unitOwner = owner;
            thisa->combatGrid[thisb->occupiedHex - 1].stackIdx = stackidx;
            thisa->combatGrid[thisb->occupiedHex - 1].isOccupierNonPrimaryHex = 0;
          }
          combatManager::RippleCreature(thisa, thisb->owningSide, thisb->stackIdx, 2);
        }
        else
        {
          thisb->occupiedHex = a5;
          thisa->combatGrid[thisb->occupiedHex].unitOwner = owner;
          thisa->combatGrid[thisb->occupiedHex].stackIdx = stackidx;
          thisa->combatGrid[thisb->occupiedHex].isOccupierNonPrimaryHex = -1;
          combatManager::RippleCreature(thisa, thisb->owningSide, thisb->stackIdx, 2);
        }
        break;
      case SPELL_DISRUPTING_RAY:
        oldDefense = stack->creature.defense;
        stack->creature.defense -= 3;
        if ( stack->creature.defense < 1 )
          stack->creature.defense = 1;
        sprintf(gText, "The disrupting ray reduces defense by %d.", oldDefense - stack->creature.defense);
        combatManager::CombatMessage(thisa, gText, 1, 1, 0);
        combatManager::DoBlast(thisa, v5, hexIdx, proto_spell);
        combatManager::RippleCreature(thisa, stack->owningSide, stack->stackIdx, 0);
        break;
      case SPELL_COLD_RAY:
        DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 175.0));
        damage = 20 * spellpower;
        if ( stack->creatureIdx == CREATURE_FIRE_ELEMENTAL )
          damage *= 2;
        if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
          damage = (signed __int64)((double)damage * 0.5);
        combatManager::ModifyDamageForArtifacts(
          &damage,
          SPELL_COLD_RAY,
          thisa->heroes[thisa->currentActionSide],
          thisa->heroes[1 - thisa->currentActionSide]);
        if ( stack->quantity <= 1 )
          v19 = gArmyNames[stack->creatureIdx];
        else
          v19 = gArmyNamesPlural[stack->creatureIdx];
        sprintf(gText, "The cold ray does %d\n damage to the %s.", damage, v19);
        combatManager::CombatMessage(thisa, gText, 1, 1, 0);
        combatManager::DoBlast(thisa, v5, hexIdx, proto_spell);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[32].creatureEffectAnimationIdx, 0, 0);
        army::Damage(stack, damage, SPELL_NONE);
        army::PowEffect(stack, -1, 1, -1, -1);
        break;
      case SPELL_CHAIN_LIGHTNING:
        combatManager::ChainLightning(thisa, hexIdx, spellpower);
        break;
      case SPELL_MAGIC_ARROW:
        DelayMilli((signed __int64)(gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 100.0));
        damage = 10 * spellpower;
        combatManager::ModifyDamageForArtifacts(
          &damage,
          SPELL_MAGIC_ARROW,
          thisa->heroes[thisa->currentActionSide],
          thisa->heroes[1 - thisa->currentActionSide]);
        if ( stack->quantity <= 1 )
          v18 = gArmyNames[stack->creatureIdx];
        else
          v18 = gArmyNamesPlural[stack->creatureIdx];
        sprintf(gText, "The magic arrow does %d\n damage to the %s.", damage, v18);
        combatManager::CombatMessage(thisa, gText, 1, 1, 0);
        v8 = resourceManager::GetIcon(gpResourceManager, "keep.icn");
        LODWORD(a7[0]) = 0x42B40000u;
        LODWORD(a7[1]) = 0x42890000u;
        LODWORD(a7[2]) = 0x42340000u;
        LODWORD(a7[3]) = 0x41A66666u;
        LODWORD(a7[4]) = 0;
        LODWORD(a7[5]) = 0xC1A66666u;
        LODWORD(a7[6]) = 0xC2340000u;
        LODWORD(a7[7]) = 0xC2890000u;
        LODWORD(a7[8]) = 0xC2B40000u;
        v9 = army::MidY(stack);
        v10 = army::MidX(stack);
        combatManager::ShootMissile(castX, castY, v10, v9, a7, v8);
        resourceManager::Dispose(gpResourceManager, (resource *)v8);
        army::Damage(stack, damage, SPELL_NONE);
        army::PowEffect(stack, -1, 1, -1, -1);
        break;
      case SPELL_LIGHTNING_BOLT:
        damage = 25 * spellpower;
        if ( stack->creatureIdx == CREATURE_AIR_ELEMENTAL )
          damage *= 2;
        if ( stack->creatureIdx == CREATURE_IRON_GOLEM || stack->creatureIdx == CREATURE_STEEL_GOLEM )
          damage = (signed __int64)((double)damage * 0.5);
        combatManager::ModifyDamageForArtifacts(
          &damage,
          SPELL_LIGHTNING_BOLT,
          thisa->heroes[thisa->currentActionSide],
          thisa->heroes[1 - thisa->currentActionSide]);
        if ( stack->quantity <= 1 )
          v17 = gArmyNames[stack->creatureIdx];
        else
          v17 = gArmyNamesPlural[stack->creatureIdx];
        sprintf(gText, "The lightning bolt does %d\n damage to the %s.", damage, v17);
        combatManager::CombatMessage(thisa, gText, 1, 1, 0);
        v11 = army::MidY(stack);
        v12 = army::MidX(stack);
        combatManager::DoBolt(
          thisa,
          (unsigned __int8)v5,
          v6,
          1,
          castX,
          castY,
          v12,
          v11,
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
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[2].creatureEffectAnimationIdx, 0, 0);
        army::Damage(stack, damage, SPELL_NONE);
        army::PowEffect(stack, -1, 1, -1, -1);
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
        combatManager::CastMassSpell(thisa, proto_spell, spellpower);
        break;
      case SPELL_MIRROR_IMAGE:
        combatManager::MirrorImage(thisa, hexIdx);
        break;
      case SPELL_SUMMON_EARTH_ELEMENTAL:
        combatManager::SummonElemental(thisa, CREATURE_EARTH_ELEMENTAL, spellpower);
        break;
      case SPELL_SUMMON_AIR_ELEMENTAL:
        combatManager::SummonElemental(thisa, CREATURE_AIR_ELEMENTAL, spellpower);
        break;
      case SPELL_SUMMON_FIRE_ELEMENTAL:
        combatManager::SummonElemental(thisa, CREATURE_FIRE_ELEMENTAL, spellpower);
        break;
      case SPELL_SUMMON_WATER_ELEMENTAL:
        combatManager::SummonElemental(thisa, CREATURE_WATER_ELEMENTAL, spellpower);
        break;
      case SPELL_RESURRECT:
      case SPELL_RESURRECT_TRUE:
      case SPELL_ANIMATE_DEAD:
        combatManager::Resurrect(thisa, proto_spell, hexIdx, spellpower);
        break;
      case SPELL_CURE:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[5].creatureEffectAnimationIdx, 0, 0);
        army::Cure(stack, spellpower);
        combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
        break;
      case SPELL_SLOW:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_SLOW, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[11].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_HASTE:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, 0, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[9].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_SHIELD:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_SHIELD, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[41].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_DRAGON_SLAYER:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_DRAGON_SLAYER, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[37].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_BLESS:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_BLESS, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[14].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_STONESKIN:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_STONESKIN, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[16].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_STEELSKIN:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_STEELSKIN, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[17].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_CURSE:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_CURSE, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[18].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_BERZERKER:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_BERSERKER, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[26].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_HYPNOTIZE:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_HYPNOTIZE, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[31].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_PARALYZE:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_PARALYZE, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[30].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_ARCHMAGI_DISPEL:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::DispelGood(stack);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[23].creatureEffectAnimationIdx, 0, 1);
        break;
      case SPELL_DISPEL_MAGIC:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::DispelGood(stack);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[23].creatureEffectAnimationIdx, 0, 0);
        for ( effect = 0; (signed int)effect < 15; ++effect )
          army::CancelIndividualSpell(stack, effect);
        break;
      case SPELL_BLIND:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_BLIND, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[13].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_BLOOD_LUST:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        combatManager::BloodLustEffect(thisa, stack, CREATURE_RED);
        army::SetSpellInfluence(stack, EFFECT_BLOOD_LUST, 3);
        break;
      case SPELL_ANTI_MAGIC:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        army::SetSpellInfluence(stack, EFFECT_ANTI_MAGIC, spellpower);
        army::SpellEffect(stack, (unsigned __int8)gsSpellInfo[22].creatureEffectAnimationIdx, 0, 0);
        break;
      case SPELL_MEDUSA_PETRIFY:
        combatManager::ShowSpellMessage(thisa, isCreatureAbility, proto_spell, stack);
        combatManager::TurnToStone(thisa, stack);
        break;
      case SPELL_COLD_RING:
        combatManager::Fireball(thisa, hexIdx, SPELL_COLD_RING);
        break;
      case SPELL_FIREBALL:
        combatManager::Fireball(thisa, hexIdx, 0);
        break;
      case SPELL_FIREBLAST:
        combatManager::Fireball(thisa, hexIdx, SPELL_FIREBLAST);
        break;
      case SPELL_METEOR_SHOWER:
        combatManager::MeteorShower(thisa, (unsigned __int8)v5, hexIdx);
        break;
      case SPELL_ELEMENTAL_STORM:
        combatManager::ElementalStorm(thisa);
        break;
      case SPELL_ARMAGEDDON:
        combatManager::Armageddon(thisa, (unsigned __int8)v5);
        break;
      case SPELL_EARTHQUAKE:
        combatManager::Earthquake(thisa);
        break;
      default:
        combatManager::DefaultSpell(thisa, hexIdx);
        break;
    }
  }
  else
  {
    combatManager::ShowSpellCastFailure(stack, proto_spell);
  }
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; thisa->numCreatures[i] > j; ++j )
    {
      v13 = (char *)thisa + 24234 * i + 1154 * j;
      v14 = (int)(v13 + 13647);
      *(_DWORD *)(v13 + 13865) = 0;
      *(_DWORD *)(v14 + 222) = *(_DWORD *)(v14 + 218);
      *(_DWORD *)(v14 + 214) = *(_DWORD *)(v14 + 222);
      *(_DWORD *)(v14 + 6) = 1;
      *(_BYTE *)v14 = 0;
      *(_DWORD *)(v14 + 154) = -1;
    }
  }
  if ( !isCreatureAbility )
  {
    ++thisa->heroIconIdxRelated[thisa->currentActionSide];
    for ( thisa->countRelatedToSpellAnimation[thisa->currentActionSide] = 0;
          byte_4F4C30[thisa->heroType[thisa->currentActionSide]][thisa->heroIconIdxRelated[thisa->currentActionSide] + 1] > thisa->countRelatedToSpellAnimation[thisa->currentActionSide];
          ++thisa->countRelatedToSpellAnimation[thisa->currentActionSide] )
      combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
    thisa->heroIconIdxRelated[thisa->currentActionSide] = 0;
    thisa->countRelatedToSpellAnimation[thisa->currentActionSide] = 0;
    combatManager::DrawFrame(thisa, 1, 0, 0, 0, 75, 1, 1);
  }
  WaitEndSample(-1, res);
  combatManager::CheckChangeSelector(thisa);
}