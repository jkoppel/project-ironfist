{
  char tmpType; // ST10_1@1
  __int16 tmpQuant; // ST10_2@1

  tmpType = this->creatureTypes[idx];
  this->creatureTypes[idx] = oth->creatureTypes[othIdx];
  oth->creatureTypes[othIdx] = tmpType;
  tmpQuant = this->quantities[idx];
  this->quantities[idx] = oth->quantities[othIdx];
  oth->quantities[othIdx] = tmpQuant;
}