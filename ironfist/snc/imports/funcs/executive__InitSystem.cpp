{
  if ( gpResourceManager->vtable->initialize((baseManager *)gpResourceManager, -1) )
    ShutDown("Unable to initialize resources - possible disk problem.");
  if ( gpInputManager->vtable->initialize((baseManager *)gpInputManager, -1) )
    ShutDown("Unable to initialize input devices - possible problem with mouse or keyboard.");
  if ( giCurExe == 1 && gpSoundManager->vtable->initialize((baseManager *)gpSoundManager, -1) )
    ShutDown("Unable to initialize sound.");
  if ( executive::AddManager(this, (baseManager *)gpMouseManager, -1) )
    ShutDown("Unable to initialize mouse.");
  if ( executive::AddManager(this, (baseManager *)gpWindowManager, -1) )
    ShutDown("Unable to initialize windows - possible memory or disk error.");
  return 0;
}