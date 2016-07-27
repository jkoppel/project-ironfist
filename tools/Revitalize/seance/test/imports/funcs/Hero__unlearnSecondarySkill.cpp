{
  signed int i; // [sp+10h] [bp-8h]@5
  int oldLevel; // [sp+14h] [bp-4h]@1

  oldLevel = this->secondarySkillLevel[skill];
  if ( this->secondarySkillLevel[skill] )
  {
    this->secondarySkillLevel[skill] -= levelsLost;
    if ( this->secondarySkillLevel[skill] < 0 )
      this->secondarySkillLevel[skill] = 0;
    if ( !this->secondarySkillLevel[skill] )
    {
      for ( i = 0; i < 14; ++i )
      {
        if ( this->ordinalSkillWasLearned[i] > this->ordinalSkillWasLearned[skill] )
          --this->ordinalSkillWasLearned[i];
      }
      this->ordinalSkillWasLearned[skill] = 0;
      --this->numSecSkillsKnown;
    }
  }
  return oldLevel - this->secondarySkillLevel[skill];
}
