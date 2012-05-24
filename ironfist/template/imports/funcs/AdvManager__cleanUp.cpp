{
  void *result; // eax@32
  int v2; // [sp+0h] [bp-24h]@0
  void *v3; // [sp+Ch] [bp-18h]@1
  signed int i; // [sp+20h] [bp-4h]@9
  signed int j; // [sp+20h] [bp-4h]@15
  signed int k; // [sp+20h] [bp-4h]@18
  signed int l; // [sp+20h] [bp-4h]@22
  signed int m; // [sp+20h] [bp-4h]@27

  v3 = this;
  sub_44D610(this);
  MouseManager::setSpriteIdx(mouseManager, -1);
  if ( dword_51256C && !*(_DWORD *)&useOpera && *(_DWORD *)&useCDMusic )
  {
    sub_4035A0(soundManager, 0, v2);
  }
  else
  {
    sub_4035A0(soundManager, 1, v2);
    SoundManager::couldBePlayCDTrack(soundManager, -1);
  }
  if ( *(_DWORD *)((char *)v3 + 186) )
  {
    KBFree(*(void **)((char *)v3 + 186), (int)"F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50EC80 + 22);
    *(_DWORD *)((char *)v3 + 186) = 0;
  }
  if ( dword_4F7490 <= 1 )
  {
    for ( i = 0; i < 64; ++i )
    {
      if ( *(_DWORD *)((char *)v3 + 4 * i + 206) )
        ResourceManager::reduceReferenceCountToResource(
          resourceManager,
          *(AbstractResource **)((char *)v3 + 4 * i + 206));
      *(_DWORD *)((char *)v3 + 4 * i + 206) = 0;
    }
  }
  if ( dword_4F7490 <= 0 )
  {
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 462));
    *(_DWORD *)((char *)v3 + 462) = 0;
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 466));
    *(_DWORD *)((char *)v3 + 466) = 0;
    for ( j = 0; j < 8; ++j )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 4 * j + 538));
      *(_DWORD *)((char *)v3 + 4 * j + 538) = 0;
    }
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 570));
    *(_DWORD *)((char *)v3 + 570) = 0;
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 574));
    *(_DWORD *)((char *)v3 + 574) = 0;
    for ( k = 0; k < 6; ++k )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 4 * k + 578));
      *(_DWORD *)((char *)v3 + 4 * k + 578) = 0;
      ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 4 * k + 602));
      *(_DWORD *)((char *)v3 + 4 * k + 602) = 0;
    }
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 194));
    *(_DWORD *)((char *)v3 + 194) = 0;
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 198));
    *(_DWORD *)((char *)v3 + 198) = 0;
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 202));
    *(_DWORD *)((char *)v3 + 202) = 0;
  }
  for ( l = 0; l < 28; ++l )
  {
    if ( *(_DWORD *)((char *)v3 + 4 * l + 738) )
      ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 4 * l + 738));
    *(_DWORD *)((char *)v3 + 4 * l + 738) = 0;
  }
  for ( m = 0; m < 9; ++m )
  {
    ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)((char *)v3 + 4 * m + 850));
    *(_DWORD *)((char *)v3 + 4 * m + 850) = 0;
  }
  HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)((char *)v3 + 154));
  operator delete(*(void **)((char *)v3 + 154));
  *(_DWORD *)((char *)v3 + 154) = 0;
  if ( *(_DWORD *)((char *)v3 + 158) )
    operator delete(*(void **)((char *)v3 + 158));
  *(_DWORD *)((char *)v3 + 158) = 0;
  dword_50EAA0 = 0;
  result = v3;
  *(_DWORD *)((char *)v3 + 50) = 0;
  return result;
}
