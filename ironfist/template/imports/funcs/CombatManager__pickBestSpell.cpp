{
  signed int result; // eax@2
  CombatManager *thisa; // [sp+10h] [bp-20h]@1
  int potCasts; // [sp+14h] [bp-1Ch]@30
  Spell bestSpell; // [sp+18h] [bp-18h]@1
  int value; // [sp+1Ch] [bp-14h]@30
  Spell j; // [sp+20h] [bp-10h]@3
  int targetForBestSpell; // [sp+24h] [bp-Ch]@1
  int target; // [sp+28h] [bp-8h]@30
  int maxValue; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  maxValue = 0;
  bestSpell = -1;
  targetForBestSpell = -1;
  if ( this->heroes[i] )
  {
    for ( j = 0; (signed int)j < 2; ++j )
    {
      if ( thisa->heroes[j] && Hero::hasArtifact(thisa->heroes[j], ARTIFACT_SPHERE_OF_NEGATION) )
        return 0;
    }
    for ( j = 0; (signed int)j < 65; ++j )
    {
      if ( Hero::hasSpell(thisa->heroes[i], j)
        && spell_table[j].attributes & ATTR_COMBAT_SPELL
        && getSpellCost(j, thisa->heroes[i]) <= thisa->heroes[i]->spellpoints
        && (!a3
         || !j
         || j == SPELL_FIREBLAST
         || j == SPELL_LIGHTNING_BOLT
         || j == SPELL_CHAIN_LIGHTNING
         || j == SPELL_HOLY_WORD
         || j == SPELL_HOLY_SHOUT
         || j == SPELL_MAGIC_ARROW
         || j == SPELL_ARMAGEDDON
         || j == SPELL_ELEMENTAL_STORM
         || j == SPELL_METEOR_SHOWER
         || j == SPELL_COLD_RAY
         || j == SPELL_COLD_RING
         || j == SPELL_DEATH_RIPPLE
         || j == SPELL_DEATH_WAVE) )
      {
        CombatManager::getHeuristicForSpell(thisa, j, &value, &target);
        potCasts = thisa->heroes[i]->spellpoints / getSpellCost(j, thisa->heroes[i]);
        if ( potCasts > 10 )
          potCasts = 10;
        value = (signed __int64)((double)value * flt_4F2A08[potCasts]);
        if ( value > maxValue )
        {
          maxValue = value;
          bestSpell = j;
          targetForBestSpell = target;
        }
      }
    }
    if ( maxValue <= 0 )
    {
      result = 0;
    }
    else
    {
      couldBeCreatureActionType = 1;
      spellForAIToCast = bestSpell;
      notTargetForAISpell = targetForBestSpell;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
