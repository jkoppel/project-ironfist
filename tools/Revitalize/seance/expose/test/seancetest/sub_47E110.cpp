void __thiscall sub_47E110(int this, int a2)
{
  *(_DWORD *)(this + 90) = a2;
  CreatureStack::performMeleeAttack((CreatureStack *)this, 0);
}
