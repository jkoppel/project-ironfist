{
  town *thisa; // [sp+Ch] [bp-8h]@1

  thisa = this;
  bEnteringTown = 1;
  if ( giHighMemBuffer + 1300 <= 2900 )
  {
    if ( giHighMemBuffer + 1300 > 800 )
      gAdvDisposeLevel = 1;
  }
  else
  {
    gAdvDisposeLevel = 2;
  }
  gpTownManager->castle = this;
  if ( !a2 )
    heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  executive::CallManager(gpExec, (baseManager *)gpTownManager);
  if ( thisa->visitingHeroIdx != -1 )
    advManager::SetHeroContext(gpAdvManager, thisa->visitingHeroIdx, 0);
  gAdvDisposeLevel = 0;
  bEnteringTown = 0;
}