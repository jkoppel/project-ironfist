{
  int v6; // [sp+Ch] [bp-Ch]@1
  int thisa; // [sp+10h] [bp-8h]@1

  thisa = this;
  v6 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a3 + 4) >> 8) >> -5);
  switch ( v6 )
  {
    case 2:
      if ( !advManager::CombatMonsterEvent(
              (advManager *)this,
              (hero *)a2,
              CREATURE_SKELETON,
              25,
              (mapCell *)a3,
              a5,
              SHIDWORD(a5),
              0,
              a5,
              SHIDWORD(a5),
              -1,
              0,
              0,
              -1,
              0,
              0) )
      {
        advManager::EventWindow(-1, 1, a4, 6, 500, -1, 0, -1);
        advManager::GiveResource((advManager *)thisa, (hero *)a2, 6, 500);
        hero::CheckLevel((hero *)a2);
        return 1;
      }
      break;
    case 3:
      if ( !advManager::CombatMonsterEvent(
              (advManager *)this,
              (hero *)a2,
              CREATURE_SKELETON,
              50,
              (mapCell *)a3,
              a5,
              SHIDWORD(a5),
              0,
              a5,
              SHIDWORD(a5),
              -1,
              0,
              0,
              -1,
              0,
              0) )
      {
        advManager::EventWindow(-1, 1, a4, 6, 1000, -1, 0, -1);
        advManager::GiveResource((advManager *)thisa, (hero *)a2, 6, 1000);
        hero::CheckLevel((hero *)a2);
        return 1;
      }
      break;
    case 4:
      if ( !advManager::CombatMonsterEvent(
              (advManager *)this,
              (hero *)a2,
              CREATURE_SKELETON,
              100,
              (mapCell *)a3,
              a5,
              SHIDWORD(a5),
              0,
              a5,
              SHIDWORD(a5),
              -1,
              0,
              0,
              -1,
              0,
              0) )
      {
        advManager::EventWindow(-1, 1, a4, 6, 2000, -1, 0, -1);
        advManager::GiveResource((advManager *)thisa, (hero *)a2, 6, 2000);
        hero::CheckLevel((hero *)a2);
        return 1;
      }
      break;
    default:
      if ( !advManager::CombatMonsterEvent(
              (advManager *)this,
              (hero *)a2,
              CREATURE_SKELETON,
              200,
              (mapCell *)a3,
              a5,
              SHIDWORD(a5),
              0,
              a5,
              SHIDWORD(a5),
              -1,
              0,
              0,
              -1,
              0,
              0) )
      {
        advManager::EventWindow(-1, 1, a4, 6, 5000, -1, 0, -1);
        advManager::GiveResource((advManager *)thisa, (hero *)a2, 6, 5000);
        hero::CheckLevel((hero *)a2);
        return 1;
      }
      break;
  }
  return 0;
}