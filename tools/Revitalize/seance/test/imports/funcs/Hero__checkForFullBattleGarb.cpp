{
  Hero *thisa; // [sp+Ch] [bp-10h]@1
  signed int i; // [sp+18h] [bp-4h]@4

  thisa = this;
  if ( Hero::hasArtifact(this, ARTIFACT_BREASTPLATE_OF_ANDURAN)
    && Hero::hasArtifact(thisa, ARTIFACT_HELMET_OF_ANDURAN)
    && Hero::hasArtifact(thisa, ARTIFACT_SWORD_OF_ANDURAN) )
  {
    for ( i = 0; i < 14; ++i )
    {
      if ( thisa->artifacts[i] == ARTIFACT_BREASTPLATE_OF_ANDURAN
        || thisa->artifacts[i] == ARTIFACT_HELMET_OF_ANDURAN
        || thisa->artifacts[i] == ARTIFACT_SWORD_OF_ANDURAN )
      {
        Hero::alterPrimarySkillsForArtifact(thisa, (ARTIFACT)thisa->artifacts[i], 1);
        thisa->artifacts[i] = -1;
      }
    }
    grantArtifact(thisa, ARTIFACT_BATTLE_GARB_OF_ANDURAN, a2, -1);
    if ( *(&byte_524758 + thisa->probablyOwnerIdx) )
    {
      playSample("treasure.82m");
      display_message_window("The three Anduran artifacts magically combine into one.", 1, -1, -1, 7, 90, -1, 0, -1, 0);
    }
  }
}
