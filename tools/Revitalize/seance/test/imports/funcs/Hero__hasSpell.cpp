{
  bool result; // eax@2
  Hero *thisa; // [sp+Ch] [bp-8h]@1
  HERO_CONSTANTS i; // [sp+10h] [bp-4h]@5

  thisa = this;
  if ( Hero::hasArtifact(this, ARTIFACT_MAGIC_BOOK) )
  {
    if ( thisa->spellsLearned[a2] )
    {
      result = 1;
    }
    else
    {
      for ( i = 0; i < MAX_ARTIFACTS; ++i )
      {
        if ( thisa->artifacts[i] == ARTIFACT_SPELL_SCROLL && thisa->scrollSpell[i] == a2 )
          return 1;
      }
      result = Hero::hasArtifact(thisa, ARTIFACT_BATTLE_GARB_OF_ANDURAN) && a2 == SPELL_TOWN_PORTAL;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
