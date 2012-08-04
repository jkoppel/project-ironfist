{
  int thisa; // [sp+Ch] [bp-14h]@1
  int thisb; // [sp+10h] [bp-10h]@1
  hero *v5; // [sp+14h] [bp-Ch]@5
  town *castle; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  castle = &gpGame->castles[(unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5)];
  thisb = (int)&gpGame->heroes[gpCurPlayer->curHeroIdx];
  advManager::DemobilizeCurrHero((advManager *)this);
  if ( castle->ownerIdx == giCurPlayer )
  {
    castle->visitingHeroIdx = gpCurPlayer->curHeroIdx;
    town::View(castle, 0);
  }
  else if ( town::HasGarrison(castle) )
  {
    if ( castle->visitingHeroIdx == -1 )
      v5 = 0;
    else
      v5 = &gpGame->heroes[castle->visitingHeroIdx];
    if ( !advManager::DoCombat(
            (void *)thisa,
            a3,
            thisb,
            (const void *)(thisb + 101),
            (int)castle,
            (int)v5,
            &castle->garrison,
            a3,
            SBYTE4(a3),
            -1,
            1) )
      game::ClaimTown(gpGame, castle->idx, giCurPlayer, 0);
  }
  else
  {
    game::ClaimTown(gpGame, castle->idx, giCurPlayer, 0);
    if ( gbGameOver )
      return;
    advManager::UpdateRadar(thisa, 1, 0);
    advManager::UpdateHeroLocators((advManager *)thisa, 1, 1);
    advManager::UpdateTownLocators((void *)thisa, 1, 1);
    castle->visitingHeroIdx = gpCurPlayer->curHeroIdx;
    town::View(castle, 0);
  }
  town::GiveSpells(castle, 0);
  hero::CheckLevel((hero *)thisb);
}