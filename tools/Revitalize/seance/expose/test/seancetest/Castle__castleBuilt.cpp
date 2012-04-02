int __thiscall Castle::castleBuilt(Castle *this)
{
  Castle *v1; // ST38_4@1

  v1 = this;
  sub_4270A0(
    gameObject,
    this->field_4 - 5,
    this->field_5 - 3,
    this->field_4 + 2,
    this->field_5 + 1,
    35,
    16,
    255,
    35,
    0,
    35,
    35);
  return sub_4270A0(
           gameObject,
           v1->field_4 - 5,
           v1->field_5 - 3,
           v1->field_4 + 2,
           v1->field_5 + 1,
           37,
           16,
           255,
           37,
           0,
           35,
           35);
}
