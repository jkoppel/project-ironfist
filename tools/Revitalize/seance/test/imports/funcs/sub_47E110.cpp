{
  *(_DWORD *)(this + 90) = a2;
  CreatureStack::performMeleeAttack((CreatureStack *)this, 0);
}
