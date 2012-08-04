{
  void *result; // eax@2
  void *v1; // [sp+5Ch] [bp-28h]@18
  void *this; // [sp+70h] [bp-14h]@9

  if ( gpBufferPalette )
  {
    result = gpBufferPalette;
    if ( gpBufferPalette )
      result = (void *)((int (__thiscall *)(_DWORD))gpBufferPalette->vtable->cleanUp)(gpBufferPalette);
  }
  gpBufferPalette = 0;
  if ( gpMonGroup )
    result = (void *)operator delete(gpMonGroup);
  gpMonGroup = 0;
  if ( gpPhilAI )
    result = (void *)operator delete((void *)gpPhilAI);
  gpPhilAI = 0;
  if ( gpSearchArray )
  {
    result = gpSearchArray;
    this = gpSearchArray;
    if ( gpSearchArray )
    {
      searchArray::_searchArray(gpSearchArray);
      result = (void *)operator delete(this);
    }
  }
  gpSearchArray = 0;
  if ( gpTownManager )
    result = (void *)operator delete(gpTownManager);
  gpTownManager = 0;
  if ( gpCombatManager )
    result = (void *)operator delete(gpCombatManager);
  gpCombatManager = 0;
  if ( gpAdvManager )
    result = (void *)operator delete(gpAdvManager);
  gpAdvManager = 0;
  if ( gpGame )
  {
    result = gpGame;
    v1 = gpGame;
    if ( gpGame )
    {
      fullMap::_fullMap(&gpGame->map.tiles);
      result = (void *)operator delete(v1);
    }
  }
  gpGame = 0;
  if ( gpHighScoreManager )
    result = (void *)operator delete(gpHighScoreManager);
  gpHighScoreManager = 0;
  if ( gpSoundManager )
    result = (void *)operator delete(gpSoundManager);
  gpSoundManager = 0;
  if ( gpWindowManager )
    result = (void *)operator delete(gpWindowManager);
  gpWindowManager = 0;
  if ( gpMouseManager )
    result = (void *)operator delete(gpMouseManager);
  gpMouseManager = 0;
  if ( gpInputManager )
    result = (void *)operator delete(gpInputManager);
  gpInputManager = 0;
  if ( gpExec )
    result = (void *)operator delete(gpExec);
  gpExec = 0;
  if ( gpResourceManager )
    result = (void *)operator delete(gpResourceManager);
  gpResourceManager = 0;
  return result;
}