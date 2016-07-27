{
  if ( level )
  {
    if ( this->secondarySkillLevel[skill] )
      this->secondarySkillLevel[skill] = level;
    else
      Hero::learnSecondarySkill(this, skill, level);
  }
  else
  {
    Hero::unlearnSecondarySkill(this, skill, 3);
  }
}
