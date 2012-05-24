void *__cdecl deleteManyGlobalObjects()
{
  void *result; // eax@2
  void *v1; // [sp+5Ch] [bp-28h]@18
  void *this; // [sp+70h] [bp-14h]@9

  if ( palette )
  {
    result = palette;
    if ( palette )
      result = (void *)((int (__thiscall *)(_DWORD))palette->vtable->cleanUp)(palette);
  }
  palette = 0;
  if ( dword_5247BC )
    result = (void *)operator delete(dword_5247BC);
  dword_5247BC = 0;
  if ( unknownGlobalObject4 )
    result = (void *)operator delete((void *)unknownGlobalObject4);
  unknownGlobalObject4 = 0;
  if ( pathfinder )
  {
    result = pathfinder;
    this = pathfinder;
    if ( pathfinder )
    {
      Pathfinder::cleanUp(pathfinder);
      result = (void *)operator delete(this);
    }
  }
  pathfinder = 0;
  if ( townManager )
    result = (void *)operator delete(townManager);
  townManager = 0;
  if ( combatManager )
    result = (void *)operator delete(combatManager);
  combatManager = 0;
  if ( advManager )
    result = (void *)operator delete(advManager);
  advManager = 0;
  if ( gameObject )
  {
    result = gameObject;
    v1 = gameObject;
    if ( gameObject )
    {
      callMapTilesDestructor(&gameObject->map.tiles);
      result = (void *)operator delete(v1);
    }
  }
  gameObject = 0;
  if ( highScoreManager )
    result = (void *)operator delete(highScoreManager);
  highScoreManager = 0;
  if ( soundManager )
    result = (void *)operator delete(soundManager);
  soundManager = 0;
  if ( HeroWindowManager::instance )
    result = (void *)operator delete(HeroWindowManager::instance);
  HeroWindowManager::instance = 0;
  if ( mouseManager )
    result = (void *)operator delete(mouseManager);
  mouseManager = 0;
  if ( inputManager )
    result = (void *)operator delete(inputManager);
  inputManager = 0;
  if ( managerManager )
    result = (void *)operator delete(managerManager);
  managerManager = 0;
  if ( resourceManager )
    result = (void *)operator delete(resourceManager);
  resourceManager = 0;
  return result;
}
