{
  signed int i; // [sp+10h] [bp-4h]@1

  this->creatureIcon = 0;
  this->occupiedHex = 0;
  for ( i = 0; i < 7; ++i )
    this->combatSounds[i] = 0;
  this->field_11D = 1;
  this->targetOwner = -1;
  this->targetStackIdx = -1;
  this->targetNeighborIdx = -1;
  this->field_5E = 0;
  this->targetHex = 0;
  this->field_125 = 0;
  LODWORD(this->field_4E) = 1;
  this->yDrawOffset = 0;
  this->xDrawOffset = 0;
  return (int)this;
}
