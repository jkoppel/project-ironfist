{
  Hero *a2a; // [sp+Ch] [bp-Ch]@1
  int v4; // [sp+10h] [bp-8h]@1
  signed int v5; // [sp+14h] [bp-4h]@1

  a2a = a2;
  v4 = spell;
  v5 = spell_table[spell].cost;
  if ( a2 )
  {
    if ( Hero::hasArtifact(a2, ARTIFACT_EVIL_EYE) && (v4 == SPELL_CURSE || v4 == SPELL_MASS_CURSE) )
      v5 >>= 1;
    if ( Hero::hasArtifact(a2a, ARTIFACT_SKULLCAP)
      && (v4 == SPELL_BERZERKER || v4 == SPELL_HYPNOTIZE || v4 == SPELL_PARALYZE || v4 == SPELL_BLIND) )
      v5 >>= 1;
    if ( Hero::hasArtifact(a2a, ARTIFACT_SNAKE_RING) && (v4 == SPELL_BLESS || v4 == SPELL_MASS_BLESS) )
      v5 >>= 1;
    if ( Hero::hasArtifact(a2a, ARTIFACT_ELEMENTAL_RING)
      && (v4 == SPELL_SUMMON_EARTH_ELEMENTAL
       || v4 == SPELL_SUMMON_AIR_ELEMENTAL
       || v4 == SPELL_SUMMON_FIRE_ELEMENTAL
       || v4 == SPELL_SUMMON_WATER_ELEMENTAL) )
      v5 >>= 1;
  }
  return v5;
}
