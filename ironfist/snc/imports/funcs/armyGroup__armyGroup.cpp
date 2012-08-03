{
  armyGroup *thisa; // ST18_4@1

  thisa = this;
  memset(this, 0xFFu, 5u);
  memset(thisa->quantities, 0, 0xAu);
  return thisa;
}