{
  signed int v4; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@2
  int j; // [sp+14h] [bp-4h]@7
  int k; // [sp+14h] [bp-4h]@12

  v4 = -1;
  if ( gpCurPlayer->curHeroIdx != -1 )
  {
    for ( i = 0; gpCurPlayer->numHeroes > i; ++i )
    {
      if ( gpCurPlayer->heroesOwned[i] == gpCurPlayer->curHeroIdx )
        v4 = i;
    }
  }
  for ( j = v4 + 1; gpCurPlayer->numHeroes > j; ++j )
  {
    if ( game::IsMobile(gpGame, gpCurPlayer->heroesOwned[j]) )
      return this->heroesOwned[j];
  }
  for ( k = 0; v4 + 1 > k; ++k )
  {
    if ( game::IsMobile(gpGame, gpCurPlayer->heroesOwned[k]) )
      return this->heroesOwned[k];
  }
  return -1;
}