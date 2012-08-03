{
  army *thisa; // [sp+18h] [bp-28h]@1
  int v7; // [sp+1Ch] [bp-24h]@65
  int othHex; // [sp+20h] [bp-20h]@17
  hero *owningHero; // [sp+24h] [bp-1Ch]@47
  float damagePerUnit; // [sp+2Ch] [bp-14h]@2
  float damagePerUnita; // [sp+2Ch] [bp-14h]@29
  int i; // [sp+30h] [bp-10h]@2
  signed int j; // [sp+30h] [bp-10h]@19
  int baseDam; // [sp+34h] [bp-Ch]@63
  int attackDiff; // [sp+3Ch] [bp-4h]@10

  thisa = this;
  if ( targ )
  {
    damagePerUnit = 0.0;
    gbGenieHalf = 0;
    for ( i = 0; thisa->quantity > i; ++i )
    {
      if ( thisa->effectStrengths[3] )
      {
        damagePerUnit = (double)thisa->creature.max_damage + damagePerUnit;
      }
      else if ( thisa->effectStrengths[4] )
      {
        damagePerUnit = (double)thisa->creature.min_damage + damagePerUnit;
      }
      else
      {
        damagePerUnit = (double)SRandom(thisa->creature.min_damage, thisa->creature.max_damage) + damagePerUnit;
      }
    }
    attackDiff = thisa->creature.attack - (a6 + targ->creature.defense);
    if ( thisa->effectStrengths[8]
      && (targ->creatureIdx == CREATURE_GREEN_DRAGON
       || targ->creatureIdx == CREATURE_RED_DRAGON
       || targ->creatureIdx == CREATURE_BLACK_DRAGON
       || targ->creatureIdx == CREATURE_BONE_DRAGON) )
      attackDiff += 5;
    if ( gpCombatManager->hasMoat )
    {
      othHex = -1;
      if ( targ->creature.creature_flags & TWO_HEXER )
        othHex = targ->occupiedHex + ((unsigned int)(targ->facingRight - 1) < 1 ? 1 : -1);
      for ( j = 0; j < 9; ++j )
      {
        if ( moatCell[j] == targ->occupiedHex || moatCell[j] == othHex )
          attackDiff += 3;
      }
    }
    if ( attackDiff > 20 )
      attackDiff = 20;
    if ( attackDiff < -20 )
      attackDiff = -20;
    damagePerUnita = gfBattleStat[attackDiff + 20] * damagePerUnit;
    if ( thisa->creatureIdx == CREATURE_CRUSADER && HIBYTE(targ->creature.creature_flags) & ATTR_UNDEAD
      || thisa->creatureIdx == CREATURE_EARTH_ELEMENTAL && targ->creatureIdx == CREATURE_AIR_ELEMENTAL
      || thisa->creatureIdx == CREATURE_AIR_ELEMENTAL && targ->creatureIdx == CREATURE_EARTH_ELEMENTAL
      || thisa->creatureIdx == CREATURE_WATER_ELEMENTAL && targ->creatureIdx == CREATURE_FIRE_ELEMENTAL
      || thisa->creatureIdx == CREATURE_FIRE_ELEMENTAL && targ->creatureIdx == CREATURE_WATER_ELEMENTAL )
      damagePerUnita = damagePerUnita * 2.0;
    if ( thisa->luckStatus > 0 )
      damagePerUnita = damagePerUnita * 2.0;
    if ( thisa->luckStatus < 0 )
      damagePerUnita = damagePerUnita / 2.0;
    thisa->luckStatus = 0;
    if ( isRanged
      && combatManager::ShotIsThroughWall(gpCombatManager, thisa->owningSide, thisa->occupiedHex, targ->occupiedHex) )
      damagePerUnita = damagePerUnita / 2.0;
    owningHero = gpCombatManager->heroes[thisa->owningSide];
    if ( owningHero && isRanged )
      damagePerUnita = gfSSArcheryMod[owningHero->secondarySkillLevel[1]] * damagePerUnita;
    if ( thisa->creature.creature_flags & SHOOTER
      && !isRanged
      && thisa->creatureIdx != CREATURE_TITAN
      && thisa->creatureIdx != CREATURE_MAGE
      && thisa->creatureIdx != CREATURE_ARCHMAGE )
      damagePerUnita = damagePerUnita / 2.0;
    if ( isRanged && targ->effectStrengths[10] )
      damagePerUnita = damagePerUnita / 2.0;
    if ( thisa->otherBadLuckThing == 2 )
      damagePerUnita = damagePerUnita / 2.0;
    thisa->otherBadLuckThing = 0;
    if ( targ->effectStrengths[11] )
      damagePerUnita = damagePerUnita / 2.0;
    baseDam = (signed __int64)(damagePerUnita + 0.5);
    if ( thisa->creatureIdx == CREATURE_GENIE )
    {
      if ( SRandom(1, 5) == 2 )
      {
        v7 = targ->creature.hp * ((targ->quantity + 1) / 2);
        if ( baseDam < v7 )
        {
          gbGenieHalf = 1;
          baseDam = v7;
        }
      }
    }
    if ( baseDam <= 0 )
      baseDam = 1;
    if ( HIBYTE(targ->creature.creature_flags) & ATTR_MIRROR_IMAGE )
      baseDam = -1;
    *damageDone = baseDam;
    *creaturesKilled = army::Damage(targ, baseDam, SPELL_NONE);
  }
}