{
  int oldLevel; // [sp+10h] [bp-4h]@1

  oldLevel = this->secondarySkillLevel[skill];
  if ( this->secondarySkillLevel[skill] )
  {
    this->secondarySkillLevel[skill] += levels;
  }
  else
  {
    if ( this->numSecSkillsKnown < 8 )
    {
      this->secondarySkillLevel[skill] = levels;
      ++this->numSecSkillsKnown;
      this->ordinalSkillWasLearned[skill] = LOBYTE(this->numSecSkillsKnown);
    }
  }
  if ( this->secondarySkillLevel[skill] > 3 )
    this->secondarySkillLevel[skill] = 3;
  return this->secondarySkillLevel[skill] - oldLevel;
}
