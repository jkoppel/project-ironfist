{
  int v6; // [sp+Ch] [bp-Ch]@1
  advManager *this; // [sp+10h] [bp-8h]@1
  int resource2Amt; // [sp+14h] [bp-4h]@12

  this = ecx0;
  v6 = (unsigned __int8)((unsigned __int8)(a5->flags >> 8) >> -5);
  if ( v6 == 2 )
  {
    if ( !advManager::CombatMonsterEvent(
            ecx0,
            hro,
            CREATURE_GHOST,
            10,
            a5,
            a8,
            SHIDWORD(a8),
            0,
            a8,
            SHIDWORD(a8),
            -1,
            0,
            0,
            -1,
            0,
            0) )
    {
      sprintf(gText, "%s", a4);
      advManager::EventWindow(-1, 1, gText, 6, 1000, -1, 0, -1);
      advManager::GiveResource(this, hro, 6, 1000);
      hero::CheckLevel(hro);
      return 1;
    }
    return 0;
  }
  if ( v6 == 3 )
  {
    if ( !advManager::CombatMonsterEvent(
            ecx0,
            hro,
            CREATURE_GHOST,
            15,
            a5,
            a8,
            SHIDWORD(a8),
            0,
            a8,
            SHIDWORD(a8),
            -1,
            0,
            0,
            -1,
            0,
            0) )
    {
      sprintf(gText, "%s", a4);
      advManager::EventWindow(-1, 1, gText, 6, 2000, -1, 0, -1);
      advManager::GiveResource(this, hro, 6, 2000);
      hero::CheckLevel(hro);
      return 1;
    }
    return 0;
  }
  if ( v6 == 4 )
  {
    if ( !advManager::CombatMonsterEvent(
            ecx0,
            hro,
            CREATURE_GHOST,
            25,
            a5,
            a8,
            SHIDWORD(a8),
            0,
            a8,
            SHIDWORD(a8),
            -1,
            0,
            0,
            -1,
            0,
            0) )
    {
      sprintf(gText, "%s", a4);
      advManager::EventWindow(-1, 1, gText, 6, 5000, -1, 0, -1);
      advManager::GiveResource(this, hro, 6, 5000);
      hero::CheckLevel(hro);
      return 1;
    }
    return 0;
  }
  if ( advManager::CombatMonsterEvent(
         ecx0,
         hro,
         CREATURE_GHOST,
         50,
         a5,
         a8,
         SHIDWORD(a8),
         0,
         a8,
         SHIDWORD(a8),
         -1,
         0,
         0,
         -1,
         0,
         0) )
    return 0;
  resource2Amt = advManager::GiveRandomArtifact(this, hro);
  sprintf(gText, "%s", a4);
  if ( resource2Amt == -1 )
    advManager::EventWindow(-1, 1, gText, 6, 2000, -1, 0, -1);
  else
    advManager::EventWindow(-1, 1, gText, 6, 2000, 7, resource2Amt, -1);
  advManager::GiveResource(this, hro, 6, 2000);
  hero::CheckLevel(hro);
  return 1;
}