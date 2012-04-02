void __thiscall ArmyInfo::deleteStack(ArmyInfo *this, int idx)
{
  this->creatureTypes[idx] = -1;
  this->quantities[idx] = 0;
}
