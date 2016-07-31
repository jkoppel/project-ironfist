{
  int v6; // [sp+Ch] [bp-Ch]@1
  int resource2Amt; // [sp+14h] [bp-4h]@12

  v6 = (unsigned __int8)((unsigned __int8)(a3->flags >> 8) >> -5);
  if ( v6 == 2 )
  {
    if ( !sub_48E820(this, (int)hero, 59, 10, (int)a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
    {
      sprintf(globBuf, "%s", a4);
      showMessageWindowForEvent(-1, 1, globBuf, 6, 1000, -1, 0, -1);
      grantResource(hero, 6, 1000);
      Hero::checkForLevelUp(hero);
      return 1;
    }
    return 0;
  }
  if ( v6 == 3 )
  {
    if ( !sub_48E820(this, (int)hero, 59, 15, (int)a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
    {
      sprintf(globBuf, "%s", a4);
      showMessageWindowForEvent(-1, 1, globBuf, 6, 2000, -1, 0, -1);
      grantResource(hero, 6, 2000);
      Hero::checkForLevelUp(hero);
      return 1;
    }
    return 0;
  }
  if ( v6 == 4 )
  {
    if ( !sub_48E820(this, (int)hero, 59, 25, (int)a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
    {
      sprintf(globBuf, "%s", a4);
      showMessageWindowForEvent(-1, 1, globBuf, 6, 5000, -1, 0, -1);
      grantResource(hero, 6, 5000);
      Hero::checkForLevelUp(hero);
      return 1;
    }
    return 0;
  }
  if ( sub_48E820(this, (int)hero, 59, 50, (int)a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
    return 0;
  resource2Amt = Hero::acquireRandomArtifact(hero);
  sprintf(globBuf, "%s", a4);
  if ( resource2Amt == -1 )
    showMessageWindowForEvent(-1, 1, globBuf, 6, 2000, -1, 0, -1);
  else
    showMessageWindowForEvent(-1, 1, globBuf, 6, 2000, 7, resource2Amt, -1);
  grantResource(hero, 6, 2000);
  Hero::checkForLevelUp(hero);
  return 1;
}
