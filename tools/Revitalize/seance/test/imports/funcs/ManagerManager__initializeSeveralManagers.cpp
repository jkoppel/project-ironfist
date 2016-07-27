{
  ManagerManager *thisa; // esi@1

  thisa = this;
  if ( resourceManager->vtable->initialize((AbstractManager *)resourceManager, -1) )
    terminate("Unable to initialize resources - possible disk problem.");
  if ( inputManager->vtable->initialize((AbstractManager *)inputManager, -1) )
    terminate("Unable to initialize input devices - possible problem with mouse or keyboard.");
  if ( gameOrEditorIdx == 1 && soundManager->vtable->initialize((AbstractManager *)soundManager, -1) )
    terminate("Unable to initialize sound.");
  if ( ManagerManager::addManager(thisa, (AbstractManager *)mouseManager, -1) )
    terminate("Unable to initialize mouse.");
  if ( ManagerManager::addManager(thisa, (AbstractManager *)HeroWindowManager::instance, -1) )
    terminate("Unable to initialize windows - possible memory or disk error.");
  return 0;
}
