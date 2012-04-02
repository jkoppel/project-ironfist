void __thiscall setRandomSeed(unsigned int this)
{
  randomSeed = this;
  srand(this);
}
