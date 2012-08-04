{
  int v7; // [sp+Ch] [bp-Ch]@1
  advManager *thisa; // [sp+10h] [bp-8h]@1
  int resource2Amt; // [sp+14h] [bp-4h]@12

  thisa = this;
  v7 = (unsigned __int8)((unsigned __int8)(a3->flags >> 8) >> -5);
  if ( v7 == 2 )
  {
    if ( !advManager::CombatMonsterEvent(this, h, CREATURE_ZOMBIE, 6, a3, a5, a6, 0, a5, a6, 49, 4, 2, -1, 0, 0) )
    {
      advManager::EventWindow(-1, 1, a4, 6, 500, -1, 0, -1);
      advManager::GiveResource(thisa, h, 6, 500);
      hero::CheckLevel(h);
      return 1;
    }
    return 0;
  }
  if ( v7 == 3 )
  {
    if ( !advManager::CombatMonsterEvent(
            this,
            h,
            CREATURE_MUTANT_ZOMBIE,
            15,
            a3,
            a5,
            a6,
            0,
            a5,
            a6,
            49,
            10,
            2,
            -1,
            0,
            0) )
    {
      advManager::EventWindow(-1, 1, a4, 6, 1000, -1, 0, -1);
      advManager::GiveResource(thisa, h, 6, 1000);
      hero::CheckLevel(h);
      return 1;
    }
    return 0;
  }
  if ( v7 == 4 )
  {
    if ( !advManager::CombatMonsterEvent(
            this,
            h,
            CREATURE_MUTANT_ZOMBIE,
            30,
            a3,
            a5,
            a6,
            0,
            a5,
            a6,
            49,
            20,
            2,
            -1,
            0,
            0) )
    {
      advManager::EventWindow(-1, 1, a4, 6, 3000, -1, 0, -1);
      advManager::GiveResource(thisa, h, 6, 3000);
      hero::CheckLevel(h);
      return 1;
    }
    return 0;
  }
  if ( advManager::CombatMonsterEvent(this, h, CREATURE_MUTANT_ZOMBIE, 60, a3, a5, a6, 0, a5, a6, 49, 40, 2, -1, 0, 0) )
    return 0;
  resource2Amt = advManager::GiveRandomArtifact(thisa, h);
  if ( resource2Amt == -1 )
    advManager::EventWindow(-1, 1, a4, 6, 1000, -1, 0, -1);
  else
    advManager::EventWindow(-1, 1, a4, 6, 1000, 7, resource2Amt, -1);
  advManager::GiveResource(thisa, h, 6, 1000);
  hero::CheckLevel(h);
  return 1;
}