{
  int v1; // ST1C_4@1

  v1 = this;
  ArmyDisplay::paint((ArmyDisplay *)this, 1);
  HeroWindowManager::redrawRectangle(
    HeroWindowManager::instance,
    *(_DWORD *)(v1 + 28),
    *(_DWORD *)(v1 + 32),
    0x228u,
    105);
}
