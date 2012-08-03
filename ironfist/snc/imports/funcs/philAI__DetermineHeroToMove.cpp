{
  char *result; // eax@8
  signed int i; // [sp+10h] [bp-10h]@2
  signed int v3; // [sp+18h] [bp-8h]@1
  int v4; // [sp+1Ch] [bp-4h]@1

  v4 = 0;
  v3 = -1;
  if ( playerData::HasMobileHero(gpCurPlayer) )
  {
    for ( i = 0; gpCurPlayer->numHeroes > i; ++i )
    {
      if ( *(_DWORD *)&gpGame->heroes[*(&gpGame->players[0].heroesOwned[284 * a1] + i - a1)].field_35 > v4 )
      {
        v4 = *(_DWORD *)&gpGame->heroes[*(&gpGame->players[0].heroesOwned[284 * a1] + i - a1)].field_35;
        v3 = i;
      }
    }
  }
  if ( v3 < 0 )
  {
    gpGame->players[a1].curHeroIdx = -1;
    result = 0;
  }
  else
  {
    result = (char *)&gpGame->heroes[*(&gpGame->players[0].heroesOwned[284 * a1] + v3 - a1)];
  }
  return result;
}