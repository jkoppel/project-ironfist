{
  char *v2; // eax@1

  LOBYTE(v2) = *(&gbThisNetHumanPlayer + giCurPlayer);
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    v2 = (char *)gpCurPlayer->curHeroIdx;
    if ( v2 != (char *)-1 )
    {
      v2 = (char *)&gpGame->heroes[gpCurPlayer->curHeroIdx];
      if ( giSeedingValid )
      {
        if ( !giFullySeeded )
          LOBYTE(v2) = searchArray::SeedPosition(
                         gpSearchArray,
                         gpGame->heroes[gpCurPlayer->curHeroIdx].x,
                         gpGame->heroes[gpCurPlayer->curHeroIdx].y,
                         *(_DWORD *)(this + 638),
                         59999,
                         *(_DWORD *)(this + 634) == 6,
                         0,
                         *(_DWORD *)&gpGame->heroes[gpCurPlayer->curHeroIdx].field_35,
                         gpGame->heroes[gpCurPlayer->curHeroIdx].secondarySkillLevel[0],
                         a2,
                         1,
                         1);
      }
      else
      {
        LOBYTE(v2) = searchArray::SeedPosition(
                       gpSearchArray,
                       gpGame->heroes[gpCurPlayer->curHeroIdx].x,
                       gpGame->heroes[gpCurPlayer->curHeroIdx].y,
                       *(_DWORD *)(this + 638),
                       59999,
                       *(_DWORD *)(this + 634) == 6,
                       0,
                       *(_DWORD *)&gpGame->heroes[gpCurPlayer->curHeroIdx].field_35,
                       gpGame->heroes[gpCurPlayer->curHeroIdx].secondarySkillLevel[0],
                       a2,
                       0,
                       1);
      }
    }
  }
  return (char)v2;
}