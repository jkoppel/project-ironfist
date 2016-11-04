{
  int v3; // ST34_4@2
  char v4; // al@2
  Hero *thisa; // [sp+Ch] [bp-Ch]@1
  int v7; // [sp+10h] [bp-8h]@1

  thisa = this;
  v7 = Hero::getSecondarySkillLevelWithBonii(this, skill) - this->secondarySkillLevel[skill];
  if ( v7 <= 0 )
  {
    sprintf(globBuf, (&dwellingNames[3 * skill + 71])[4 * thisa->secondarySkillLevel[skill]]);
  }
  else
  {
    v3 = secondarySkillLevels[thisa->secondarySkillLevel[skill]];
    v4 = Hero::getSecondarySkillLevelWithBonii(thisa, skill);
    sprintf(
      globBuf,
      "{%s Necromancy (+%d)}\n\n%s Necromancy (+%d) allows %d percent of the creatures killed in combat to be brought back from the dead as Skeletons.",
      v3,
      v7,
      v3,
      v7,
      10 * v4);
  }
  return display_message_window(
           globBuf,
           a3 < 1 ? 1 : 4,
           -1,
           -1,
           17,
           3 * skill + thisa->secondarySkillLevel[skill] - 1,
           -1,
           0,
           -1,
           0);
}
