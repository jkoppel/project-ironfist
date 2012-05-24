{
  double result; // st7@4
  CreatureStack *thisa; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+10h] [bp-10h]@141
  int ressurectionStrength; // [sp+14h] [bp-Ch]@125
  signed int hasEffect; // [sp+18h] [bp-8h]@7
  CREATE_STACK_CONSTANTS i; // [sp+1Ch] [bp-4h]@7

  thisa = this;
  if ( HIBYTE(this->creature.creature_flags) & ATTR_MIRROR_IMAGE
    && (spell == SPELL_MIRROR_IMAGE || spell == SPELL_ANTI_MAGIC) )
    return 0.0;
  if ( spell == SPELL_DISPEL_MAGIC || spell == SPELL_MASS_DISPEL )
  {
    hasEffect = 0;
    for ( i = 0; i < NUM_EFFECTS; ++i )
    {
      if ( this->effectStrengths[i] )
      {
        hasEffect = 1;
        break;
      }
    }
    if ( !hasEffect )
      return 0.0;
  }
  if ( this->effectStrengths[12]
    || this->creature.creature_flags & 0x10
    && spell != 7
    && spell != SPELL_RESURRECT_TRUE
    && spell != SPELL_ANIMATE_DEAD
    || this->dead
    || this->creatureIdx == CREATURE_GREEN_DRAGON
    || this->creatureIdx == CREATURE_RED_DRAGON
    || this->creatureIdx == CREATURE_BLACK_DRAGON )
    return 0.0;
  if ( spell == SPELL_MIRROR_IMAGE && this->mirrorIdx != -1 )
    return 0.0;
  if ( (spell == SPELL_RESURRECT || spell == SPELL_RESURRECT_TRUE)
    && (HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD || this->initialQuantity == this->quantity) )
    return 0.0;
  if ( spell == SPELL_ANIMATE_DEAD
    && (!(HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD) || this->initialQuantity == this->quantity) )
    return 0.0;
  if ( (spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT) && !(HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD) )
    return 0.0;
  if ( (spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE) && HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD )
    return 0.0;
  if ( this->creatureIdx == CREATURE_PHOENIX
    && (!spell
     || spell == SPELL_FIREBLAST
     || spell == SPELL_LIGHTNING_BOLT
     || spell == SPELL_CHAIN_LIGHTNING
     || spell == SPELL_COLD_RAY
     || spell == SPELL_COLD_RING
     || spell == SPELL_ELEMENTAL_STORM) )
    return 0.0;
  if ( this->creatureIdx == CREATURE_CRUSADER && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE) )
    return 0.0;
  if ( (HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD
     || this->creatureIdx == CREATURE_EARTH_ELEMENTAL
     || this->creatureIdx == CREATURE_AIR_ELEMENTAL
     || this->creatureIdx == CREATURE_FIRE_ELEMENTAL
     || this->creatureIdx == CREATURE_WATER_ELEMENTAL
     || this->creatureIdx == CREATURE_GIANT
     || this->creatureIdx == CREATURE_TITAN)
    && (spell == SPELL_BERZERKER || spell == SPELL_HYPNOTIZE || spell == SPELL_PARALYZE || spell == SPELL_BLIND) )
    return 0.0;
  if ( HIBYTE(this->creature.creature_flags) & ATTR_UNDEAD
    && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE || spell == SPELL_BLESS || spell == SPELL_MASS_BLESS) )
    return 0.0;
  if ( this->creatureIdx == CREATURE_EARTH_ELEMENTAL
    && (spell == SPELL_LIGHTNING_BOLT || spell == SPELL_CHAIN_LIGHTNING || spell == SPELL_METEOR_SHOWER) )
    return 0.0;
  if ( this->creatureIdx == CREATURE_AIR_ELEMENTAL && spell == SPELL_METEOR_SHOWER )
    return 0.0;
  if ( this->creatureIdx == CREATURE_FIRE_ELEMENTAL && (!spell || spell == SPELL_FIREBLAST) )
    return 0.0;
  if ( this->creatureIdx == CREATURE_WATER_ELEMENTAL && (spell == SPELL_COLD_RAY || spell == SPELL_COLD_RING) )
    return 0.0;
  if ( !combatManager->heroes[this->owningSide] )
    goto LABEL_168;
  if ( Hero::hasArtifact(combatManager->heroes[this->owningSide], ARTIFACT_HOLY_PENDANT)
    && (spell == SPELL_CURSE || spell == SPELL_MASS_CURSE) )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_PENDANT_OF_FREE_WILL)
    && spell == SPELL_HYPNOTIZE )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_PENDANT_OF_LIFE)
    && (spell == SPELL_DEATH_RIPPLE || spell == SPELL_DEATH_WAVE) )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_SERENITY_PENDANT)
    && spell == SPELL_BERZERKER )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_SEEING_EYE_PENDANT) && spell == SPELL_BLIND )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_KINETIC_PENDANT) && spell == SPELL_PARALYZE )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_PENDANT_OF_DEATH)
    && (spell == SPELL_HOLY_WORD || spell == SPELL_HOLY_SHOUT) )
    return 0.0;
  if ( Hero::hasArtifact(combatManager->heroes[thisa->owningSide], ARTIFACT_WAND_OF_NEGATION)
    && (spell == SPELL_DISPEL_MAGIC || spell == SPELL_MASS_DISPEL || spell == SPELL_ARCHMAGI_DISPEL) )
  {
    result = 0.0;
  }
  else
  {
LABEL_168:
    if ( thisa->quantity || spell != SPELL_RESURRECT && spell != SPELL_RESURRECT_TRUE && spell != SPELL_ANIMATE_DEAD )
      goto LABEL_169;
    ressurectionStrength = 50 * combatManager->heroSpellpowers[combatManager->currentActionSide];
    if ( combatManager->heroes[combatManager->currentActionSide]
      && Hero::hasArtifact(combatManager->heroes[combatManager->currentActionSide], ARTIFACT_ANKH) )
      ressurectionStrength *= 2;
    if ( thisa->creature.hp <= ressurectionStrength )
    {
LABEL_169:
      if ( spell != SPELL_ARCHMAGI_DISPEL
        || thisa->effectStrengths[0]
        || thisa->effectStrengths[3]
        || thisa->effectStrengths[8]
        || thisa->effectStrengths[9]
        || thisa->effectStrengths[10]
        || thisa->effectStrengths[12]
        || thisa->effectStrengths[13]
        || thisa->effectStrengths[14] )
      {
        if ( spell != SPELL_HYPNOTIZE )
          goto LABEL_170;
        v4 = 25
           * Hero::getPrimarySkill(combatManager->heroes[combatManager->currentActionSide], PRIMARY_SKILL_SPELLPOWER);
        if ( Hero::hasArtifact(combatManager->heroes[combatManager->currentActionSide], ARTIFACT_GOLD_WATCH) )
          v4 *= 2;
        if ( thisa->quantity * thisa->creature.hp <= v4 )
        {
LABEL_170:
          if ( thisa->creatureIdx != CREATURE_DWARF && thisa->creatureIdx != CREATURE_BATTLE_DWARF
            || spell == SPELL_TELEPORT
            || spell == SPELL_CURE
            || spell == SPELL_MASS_CURE
            || spell == SPELL_RESURRECT
            || spell == SPELL_RESURRECT_TRUE
            || spell == SPELL_HASTE
            || spell == SPELL_MASS_HASTE
            || spell == SPELL_BLESS
            || spell == SPELL_MASS_BLESS
            || spell == SPELL_STONESKIN
            || spell == SPELL_STEELSKIN
            || spell == SPELL_ANTI_MAGIC
            || spell == SPELL_DRAGON_SLAYER
            || spell == SPELL_BLOOD_LUST
            || spell == 40
            || spell == 41
            || spell == 42 )
            result = 1.0;
          else
            result = 0.75;
        }
        else
        {
          result = 0.0;
        }
      }
      else
      {
        result = 0.0;
      }
    }
    else
    {
      result = 0.0;
    }
  }
  return result;
}
