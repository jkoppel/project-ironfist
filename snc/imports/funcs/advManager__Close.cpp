{
  void *result; // eax@32
  int v2; // [sp+0h] [bp-24h]@0
  void *thisa; // [sp+Ch] [bp-18h]@1
  signed int i; // [sp+20h] [bp-4h]@9
  signed int j; // [sp+20h] [bp-4h]@15
  signed int k; // [sp+20h] [bp-4h]@18
  signed int l; // [sp+20h] [bp-4h]@22
  signed int m; // [sp+20h] [bp-4h]@27

  thisa = this;
  advManager::ClearBottomView((advManager *)this);
  mouseManager::SetPointer(gpMouseManager, -1);
  if ( bEnteringTown && !*(_DWORD *)&useOpera && *(_DWORD *)&useCDMusic )
  {
    soundManager::StopAllSamples(gpSoundManager, 0, v2);
  }
  else
  {
    soundManager::StopAllSamples(gpSoundManager, 1, v2);
    soundManager::SwitchAmbientMusic(gpSoundManager, -1);
  }
  if ( *(_DWORD *)((char *)thisa + 186) )
  {
    BaseFree(*(void **)((char *)thisa + 186), (int)"F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50EC80 + 22);
    *(_DWORD *)((char *)thisa + 186) = 0;
  }
  if ( gAdvDisposeLevel <= 1 )
  {
    for ( i = 0; i < 64; ++i )
    {
      if ( *(_DWORD *)((char *)thisa + 4 * i + 206) )
        resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * i + 206));
      *(_DWORD *)((char *)thisa + 4 * i + 206) = 0;
    }
  }
  if ( gAdvDisposeLevel <= 0 )
  {
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 462));
    *(_DWORD *)((char *)thisa + 462) = 0;
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 466));
    *(_DWORD *)((char *)thisa + 466) = 0;
    for ( j = 0; j < 8; ++j )
    {
      resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * j + 538));
      *(_DWORD *)((char *)thisa + 4 * j + 538) = 0;
    }
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 570));
    *(_DWORD *)((char *)thisa + 570) = 0;
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 574));
    *(_DWORD *)((char *)thisa + 574) = 0;
    for ( k = 0; k < 6; ++k )
    {
      resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * k + 578));
      *(_DWORD *)((char *)thisa + 4 * k + 578) = 0;
      resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * k + 602));
      *(_DWORD *)((char *)thisa + 4 * k + 602) = 0;
    }
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 194));
    *(_DWORD *)((char *)thisa + 194) = 0;
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 198));
    *(_DWORD *)((char *)thisa + 198) = 0;
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 202));
    *(_DWORD *)((char *)thisa + 202) = 0;
  }
  for ( l = 0; l < 28; ++l )
  {
    if ( *(_DWORD *)((char *)thisa + 4 * l + 738) )
      resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * l + 738));
    *(_DWORD *)((char *)thisa + 4 * l + 738) = 0;
  }
  for ( m = 0; m < 9; ++m )
  {
    resourceManager::Dispose(gpResourceManager, *(resource **)((char *)thisa + 4 * m + 850));
    *(_DWORD *)((char *)thisa + 4 * m + 850) = 0;
  }
  heroWindowManager::RemoveWindow(gpWindowManager, *(heroWindow **)((char *)thisa + 154));
  operator delete(*(void **)((char *)thisa + 154));
  *(_DWORD *)((char *)thisa + 154) = 0;
  if ( *(_DWORD *)((char *)thisa + 158) )
    operator delete(*(void **)((char *)thisa + 158));
  *(_DWORD *)((char *)thisa + 158) = 0;
  iCurBottomView = 0;
  result = thisa;
  *(_DWORD *)((char *)thisa + 50) = 0;
  return result;
}