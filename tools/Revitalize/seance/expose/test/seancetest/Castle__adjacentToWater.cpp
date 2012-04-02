bool __thiscall Castle::adjacentToWater(Castle *this)
{
  return LOBYTE(this->field_6) != 255;
}
