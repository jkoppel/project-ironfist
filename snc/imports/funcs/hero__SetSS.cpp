{
  if ( level )
  {
    if ( this->secondarySkillLevel[skill] )
      this->secondarySkillLevel[skill] = level;
    else
      hero::GiveSS(this, skill, level);
  }
  else
  {
    hero::TakeSS(this, skill, 3);
  }
}