{
  int v2; // ST14_4@1

  v2 = (signed __int64)(army::SpellCastWorkChance(this, spell) * 100.0);
  return SRandom(1, 99) <= v2;
}