{
  ManagerManager *thisa; // esi@1
  AbstractManager *cur; // eax@1
  AbstractManager *next; // edi@2

  thisa = this;
  unknown_libname_5();
  soundManager->vtable->cleanUp((AbstractManager *)soundManager);
  cur = thisa->firstManager;
  if ( thisa->firstManager )
  {
    do
    {
      next = cur->next;
      if ( (AbstractManager *)HeroWindowManager::instance != cur && (AbstractManager *)mouseManager != cur )
        ManagerManager__removeManager(thisa, cur);
      cur = next;
    }
    while ( next );
  }
  if ( HeroWindowManager::instance->ready == 1 )
    ManagerManager__removeManager(thisa, (AbstractManager *)HeroWindowManager::instance);
  if ( mouseManager->ready == 1 )
    ManagerManager__removeManager(thisa, (AbstractManager *)mouseManager);
  inputManager->vtable->cleanUp((AbstractManager *)inputManager);
  ((void (*)(void))resourceManager->vtable->cleanUp)();
}
