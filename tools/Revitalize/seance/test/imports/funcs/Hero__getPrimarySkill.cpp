{
  char result; // al@3

  if ( skill != PRIMARY_SKILL_SPELLPOWER || this->primarySkills[2] >= 1 )
    result = this->primarySkills[skill];
  else
    result = 1;
  return result;
}
