{
  int result; // eax@2
  void *v1; // [sp+5Ch] [bp-28h]@18
  void *this; // [sp+70h] [bp-14h]@9

  if ( palette )
  {
    result = (int)palette;
    if ( palette )
      result = ((int (__thiscall *)(_DWORD))palette->vtable->cleanUp)(palette);
  }
  palette = 0;
  if ( dword_5247BC )
    result = operator delete(dword_5247BC);
  dword_5247BC = 0;
  if ( unknownGlobalObject4 )
    result = operator delete((void *)unknownGlobalObject4);
  unknownGlobalObject4 = 0;
  if ( pathfinder )
  {
    result = (int)pathfinder;
    this = pathfinder;
    if ( pathfinder )
    {
      Pathfinder::cleanUp(pathfinder);
      result = operator delete(this);
    }
  }
  pathfinder = 0;
  if ( townManager )
    result = operator delete(townManager);
  townManager = 0;
  if ( combatManager )
    result = operator delete(combatManager);
  combatManager = 0;
  if ( advManager )
    result = operator delete(advManager);
  advManager = 0;
  if ( gameObject )
  {
    result = (int)gameObject;
    v1 = gameObject;
    if ( gameObject )
    {
      sub_46F6F0((void **)&gameObject->map.tiles);
      result = operator delete(v1);
    }
  }
  gameObject = 0;
  if ( highScoreManager )
    result = operator delete(highScoreManager);
  highScoreManager = 0;
  if ( soundManager )
    result = operator delete(soundManager);
  soundManager = 0;
  if ( HeroWindowManager::instance )
    result = operator delete(HeroWindowManager::instance);
  HeroWindowManager::instance = 0;
  if ( mouseManager )
    result = operator delete(mouseManager);
  mouseManager = 0;
  if ( inputManager )
    result = operator delete(inputManager);
  inputManager = 0;
  if ( managerManager )
    result = operator delete(managerManager);
  managerManager = 0;
  if ( resourceManager )
    result = operator delete(resourceManager);
  resourceManager = 0;
  return result;
}
