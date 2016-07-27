{
  char result; // al@2
  Hero *this; // [sp+Ch] [bp-Ch]@1
  char skillLevel; // [sp+10h] [bp-8h]@1
  char skillLevela; // [sp+10h] [bp-8h]@11
  char v6; // [sp+14h] [bp-4h]@1

  this = ecx0;
  v6 = 0;
  skillLevel = ecx0->secondarySkillLevel[skill];
  if ( skill == SECONDARY_SKILL_NECROMANCY )
  {
    if ( skillLevel )
    {
      if ( Hero::hasArtifact(ecx0, ARTIFACT_SPADE_OF_NECROMANCY) )
        v6 = 1;
      if ( this->factionID == FACTION_NECROMANCER )
        v6 += GameInfo::ownedNecromancyShrines(gameObject, this->probablyOwnerIdx);
      if ( v6 > 6 )
        v6 = 6;
      skillLevela = skillLevel + v6;
      if ( skillLevela > 9 )
        skillLevela = 9;
      result = skillLevela;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = ecx0->secondarySkillLevel[skill];
  }
  return result;
}
