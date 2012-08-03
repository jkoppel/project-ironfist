{
  signed int i; // [sp+18h] [bp-4h]@4

  if ( hero::HasArtifact(this, ARTIFACT_BREASTPLATE_OF_ANDURAN)
    && hero::HasArtifact(this, ARTIFACT_HELMET_OF_ANDURAN)
    && hero::HasArtifact(this, ARTIFACT_SWORD_OF_ANDURAN) )
  {
    for ( i = 0; i < 14; ++i )
    {
      if ( this->artifacts[i] == ARTIFACT_BREASTPLATE_OF_ANDURAN
        || this->artifacts[i] == ARTIFACT_HELMET_OF_ANDURAN
        || this->artifacts[i] == ARTIFACT_SWORD_OF_ANDURAN )
      {
        GiveTakeArtifactStat(this, (ARTIFACT)this->artifacts[i], 1);
        this->artifacts[i] = -1;
      }
    }
    GiveArtifact(this, ARTIFACT_BATTLE_GARB_OF_ANDURAN, a2, -1);
    if ( *(&gbThisNetHumanPlayer + this->probablyOwnerIdx) )
    {
      LoadPlaySample("treasure.82m");
      NormalDialog("The three Anduran artifacts magically combine into one.", 1, -1, -1, 7, 90, -1, 0, -1, 0);
    }
  }
}