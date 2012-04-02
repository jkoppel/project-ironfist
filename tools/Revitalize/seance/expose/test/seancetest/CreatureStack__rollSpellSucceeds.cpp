bool __thiscall CreatureStack::rollSpellSucceeds(CreatureStack *this, Spell spell)
{
  int v2; // ST14_4@1

  v2 = (signed __int64)(CreatureStack::getSpellSuccessChance(this, spell) * 100.0);
  return nextRandomInt(1, 99) <= v2;
}
