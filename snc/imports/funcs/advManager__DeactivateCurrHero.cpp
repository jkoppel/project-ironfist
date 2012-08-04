{
  playerData *result; // eax@1

  advManager::DemobilizeCurrHero(this);
  result = gpCurPlayer;
  gpCurPlayer->curHeroIdx = -1;
  return result;
}