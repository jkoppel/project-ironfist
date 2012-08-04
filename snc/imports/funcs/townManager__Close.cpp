{
  townManager *thisa; // [sp+Ch] [bp-Ch]@1

  thisa = this;
  townManager::UnloadTown(this);
  if ( thisa->townScreen )
  {
    heroWindowManager::RemoveWindow(gpWindowManager, thisa->townScreen);
    operator delete(thisa->townScreen);
  }
  thisa->townScreen = 0;
  if ( *(_DWORD *)&useOpera || !*(_DWORD *)&useCDMusic )
    soundManager::SwitchAmbientMusic(gpSoundManager, -1);
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  mouseManager::SetPointer(gpMouseManager, -1);
  thisa->ready = 0;
  thisa->castle->buildingsBuiltFlags &= 0xFFF8BFFFu;
}