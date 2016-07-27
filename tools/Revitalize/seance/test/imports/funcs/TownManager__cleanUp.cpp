{
  TownManager *thisa; // [sp+Ch] [bp-Ch]@1

  thisa = this;
  TownManager::reset(this);
  if ( thisa->townScreen )
  {
    HeroWindowManager::removeWindow(HeroWindowManager::instance, thisa->townScreen);
    operator delete(thisa->townScreen);
  }
  thisa->townScreen = 0;
  if ( *(_DWORD *)&useOpera || !*(_DWORD *)&useCDMusic )
    SoundManager::couldBePlayCDTrack(soundManager, -1);
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  MouseManager::setSpriteIdx(mouseManager, -1);
  thisa->ready = 0;
  thisa->castle->buildingsBuiltFlags &= 0xFFF8BFFFu;
}
