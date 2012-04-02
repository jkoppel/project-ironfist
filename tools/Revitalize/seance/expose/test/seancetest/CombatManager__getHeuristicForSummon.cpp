int __thiscall CombatManager::getHeuristicForSummon(CombatManager *this, int hex, Spell spell)
{
  signed __int64 v3; // qax@12
  CombatManager *thisa; // [sp+1Ch] [bp-18h]@1
  float durationModifier; // [sp+20h] [bp-14h]@22
  float chance; // [sp+24h] [bp-10h]@1
  int v8; // [sp+28h] [bp-Ch]@20
  CREATURES creature; // [sp+2Ch] [bp-8h]@14

  thisa = this;
  chance = 1.0;
  if ( (spell == SPELL_SUMMON_EARTH_ELEMENTAL
     || spell == SPELL_SUMMON_AIR_ELEMENTAL
     || spell == SPELL_SUMMON_FIRE_ELEMENTAL
     || spell == SPELL_SUMMON_WATER_ELEMENTAL)
    && this->heroes[this->currentActionSide] )
    Hero::hasArtifact(this->heroes[this->currentActionSide], ARTIFACT_BOOK_OF_ELEMENTS);
  if ( spell != SPELL_SUMMON_EARTH_ELEMENTAL
    && spell != SPELL_SUMMON_AIR_ELEMENTAL
    && spell != SPELL_SUMMON_FIRE_ELEMENTAL
    && spell != SPELL_SUMMON_WATER_ELEMENTAL
    || CombatManager::anySpaceInFrontOfHero(thisa) )
  {
    switch ( spell )
    {
      case SPELL_SUMMON_EARTH_ELEMENTAL:
        creature = CREATURE_EARTH_ELEMENTAL;
        break;
      case SPELL_SUMMON_AIR_ELEMENTAL:
        creature = CREATURE_AIR_ELEMENTAL;
        break;
      case SPELL_SUMMON_FIRE_ELEMENTAL:
        creature = CREATURE_FIRE_ELEMENTAL;
        break;
      case SPELL_SUMMON_WATER_ELEMENTAL:
        creature = CREATURE_WATER_ELEMENTAL;
        break;
      default:
        chance = CreatureStack::getSpellSuccessChance(
                   &thisa->creatures[thisa->combatGrid[hex].unitOwner][thisa->combatGrid[hex].stackIdx],
                   SPELL_MIRROR_IMAGE);
        creature = thisa->creatures[thisa->combatGrid[hex].unitOwner][thisa->combatGrid[hex].stackIdx].creatureIdx;
        break;
    }
    v8 = creature * creature_table[creature].fight_value;
    if ( spell == SPELL_MIRROR_IMAGE )
    {
      if ( thisa->heroSpellpowers[thisa->currentActionSide] == 1 )
      {
        durationModifier = 0.16;
      }
      else
      {
        if ( thisa->heroSpellpowers[thisa->currentActionSide] == 2 )
          durationModifier = 0.2;
        else
          durationModifier = 0.22;
      }
      v8 = (signed __int64)((double)v8 * durationModifier);
      if ( creature_table[creature].creature_flags & SHOOTER )
        v8 = (signed __int64)((double)v8 * 1.4);
    }
    v3 = (signed __int64)((double)v8 * chance);
  }
  else
  {
    LODWORD(v3) = 0;
  }
  return v3;
}
