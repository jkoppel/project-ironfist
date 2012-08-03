{
  char v2; // al@12
  town *thisa; // [sp+Ch] [bp-10h]@1
  signed int j; // [sp+10h] [bp-Ch]@10
  int i; // [sp+14h] [bp-8h]@8
  hero *hro; // [sp+18h] [bp-4h]@4

  if ( captain || this->visitingHeroIdx != -1 )
    {
      if ( captain )
        hro = captain;
      else
        hro = &gpGame->heroes[this->visitingHeroIdx];
      if ( hro->HasArtifact(ARTIFACT_MAGIC_BOOK) && this->buildingsBuiltFlags & 1 )
        {
          for ( i = 0; hro->secondarySkillLevel[7] + 2 > i; ++i )
            {
              for ( j = 0; this->numSpellsOfLevel[i] > j; ++j )
                {
                  v2 = hro->Stats(PRIMARY_SKILL_KNOWLEDGE);
                  hro->AddSpell(this->mageGuildSpells[i][j], v2);
                }
            }
        }
    }
}
