void __thiscall CombatManager::clearHitByHydraAttack(CombatManager *this)
{
  signed int j; // [sp+10h] [bp-8h]@3
  signed int i; // [sp+14h] [bp-4h]@1

  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < 20; ++j )
      this->creatures[i][j].hitByHydraAttack = 0;
  }
}
