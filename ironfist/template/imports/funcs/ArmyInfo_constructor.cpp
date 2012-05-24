{
  ArmyInfo *thisa; // ST18_4@1

  thisa = this;
  memset(this, -1, 5u);
  memset(thisa->quantities, 0, 0xAu);
  return thisa;
}
