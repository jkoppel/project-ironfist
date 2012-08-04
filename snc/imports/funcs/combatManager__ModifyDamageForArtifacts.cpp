{
  if ( thisHero )
  {
    if ( hero::HasArtifact(thisHero, ARTIFACT_EVERCOLD_ICICLE) && (spell == SPELL_COLD_RAY || spell == SPELL_COLD_RING) )
      *damage = (signed __int64)((double)*damage * 1.5);
    if ( hero::HasArtifact(thisHero, ARTIFACT_EVERHOT_LAVA_ROCK)
      && (spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST) )
      *damage = (signed __int64)((double)*damage * 1.5);
    if ( hero::HasArtifact(thisHero, ARTIFACT_LIGHTNING_ROD)
      && (spell == SPELL_LIGHTNING_BOLT || spell == SPELL_CHAIN_LIGHTNING) )
      *damage = (signed __int64)((double)*damage * 1.5);
  }
  if ( enemyHero )
  {
    if ( hero::HasArtifact(enemyHero, ARTIFACT_ICE_CLOAK) && (spell == SPELL_COLD_RAY || spell == SPELL_COLD_RING) )
      *damage = (signed __int64)((double)*damage * 0.5);
    if ( hero::HasArtifact(enemyHero, ARTIFACT_FIRE_CLOAK) && (spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST) )
      *damage = (signed __int64)((double)*damage * 0.5);
    if ( hero::HasArtifact(enemyHero, ARTIFACT_LIGHTNING_HELM)
      && (spell == SPELL_LIGHTNING_BOLT || spell == SPELL_CHAIN_LIGHTNING) )
      *damage = (signed __int64)((double)*damage * 0.5);
    if ( hero::HasArtifact(enemyHero, ARTIFACT_HEART_OF_FIRE) )
    {
      if ( spell != SPELL_COLD_RAY && spell != SPELL_COLD_RING )
      {
        if ( spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST )
          *damage = (signed __int64)((double)*damage * 0.5);
      }
      else
      {
        *damage *= 2;
      }
    }
    if ( hero::HasArtifact(enemyHero, ARTIFACT_HEART_OF_ICE) )
    {
      if ( spell != SPELL_COLD_RAY && spell != SPELL_COLD_RING )
      {
        if ( spell == SPELL_FIREBALL || spell == SPELL_FIREBLAST )
          *damage *= 2;
      }
      else
      {
        *damage = (signed __int64)((double)*damage * 0.5);
      }
    }
  }
}