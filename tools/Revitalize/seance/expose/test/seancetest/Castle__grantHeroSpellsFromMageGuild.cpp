void __thiscall Castle::grantHeroSpellsFromMageGuild(Castle *this, Hero *captain)
{
  char v2; // al@12
  Castle *thisa; // [sp+Ch] [bp-10h]@1
  signed int j; // [sp+10h] [bp-Ch]@10
  int i; // [sp+14h] [bp-8h]@8
  Hero *hero; // [sp+18h] [bp-4h]@4

  thisa = this;
  if ( captain || this->visitingHeroIdx != -1 )
  {
    if ( captain )
      hero = captain;
    else
      hero = &gameObject->heroes[this->visitingHeroIdx];
    if ( Hero::hasArtifact(hero, ARTIFACT_MAGIC_BOOK) && thisa->buildingsBuiltFlags & 1 )
    {
      for ( i = 0; hero->secondarySkillLevel[7] + 2 > i; ++i )
      {
        for ( j = 0; thisa->numSpellsOfLevel[i] > j; ++j )
        {
          v2 = Hero::getPrimarySkill(hero, PRIMARY_SKILL_KNOWLEDGE);
          Hero::learnSpell(hero, thisa->mageGuildSpells[i][j], v2);
        }
      }
    }
  }
}
