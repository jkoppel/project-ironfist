LPVOID __thiscall setRandomSeed(unsigned int this)
{
  randomSeed = this;
  return srand(this);
}
