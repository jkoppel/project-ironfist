{
  int v6; // [sp+Ch] [bp-Ch]@1
  int resource2Amt; // [sp+14h] [bp-4h]@12

  v6 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a3 + 4) >> 8) >> -5);
  if ( v6 == 2 )
  {
    if ( !sub_48E820((AdvManager *)this, a2, 48, 6, a3, a5, 0, a5, 49, 4, 2, -1, 0, 0) )
    {
      showMessageWindowForEvent(-1, 1, a4, 6, 500, -1, 0, -1);
      grantResource((Hero *)a2, 6, 500);
      Hero::checkForLevelUp((Hero *)a2);
      return 1;
    }
    return 0;
  }
  if ( v6 == 3 )
  {
    if ( !sub_48E820((AdvManager *)this, a2, 49, 15, a3, a5, 0, a5, 49, 10, 2, -1, 0, 0) )
    {
      showMessageWindowForEvent(-1, 1, a4, 6, 1000, -1, 0, -1);
      grantResource((Hero *)a2, 6, 1000);
      Hero::checkForLevelUp((Hero *)a2);
      return 1;
    }
    return 0;
  }
  if ( v6 == 4 )
  {
    if ( !sub_48E820((AdvManager *)this, a2, 49, 30, a3, a5, 0, a5, 49, 20, 2, -1, 0, 0) )
    {
      showMessageWindowForEvent(-1, 1, a4, 6, 3000, -1, 0, -1);
      grantResource((Hero *)a2, 6, 3000);
      Hero::checkForLevelUp((Hero *)a2);
      return 1;
    }
    return 0;
  }
  if ( sub_48E820((AdvManager *)this, a2, 49, 60, a3, a5, 0, a5, 49, 40, 2, -1, 0, 0) )
    return 0;
  resource2Amt = Hero::acquireRandomArtifact((Hero *)a2);
  if ( resource2Amt == -1 )
    showMessageWindowForEvent(-1, 1, a4, 6, 1000, -1, 0, -1);
  else
    showMessageWindowForEvent(-1, 1, a4, 6, 1000, 7, resource2Amt, -1);
  grantResource((Hero *)a2, 6, 1000);
  Hero::checkForLevelUp((Hero *)a2);
  return 1;
}
