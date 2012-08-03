{
  int result; // eax@1
  void *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  result = *(&gbThisNetHumanPlayer + giCurPlayer);
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    result = gpCurPlayer->curHeroIdx;
    if ( result != -1 )
    {
      result = game::IsMobile(gpGame, gpCurPlayer->curHeroIdx);
      if ( !result )
      {
        advManager::ShowRoute(thisa, 1, 0, 0);
        advManager::UpdateHeroLocators((advManager *)thisa, 1, 1);
        result = advManager::CheckDimNextHeroBut();
      }
    }
  }
  return result;
}