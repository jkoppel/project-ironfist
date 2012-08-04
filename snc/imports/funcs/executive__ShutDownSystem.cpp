{
  executive *thisa; // esi@1
  baseManager *cur; // eax@1
  baseManager *next; // edi@2

  thisa = this;
  EarlyShutDownSystem();
  gpSoundManager->vtable->cleanUp((baseManager *)gpSoundManager);
  cur = thisa->firstManager;
  if ( thisa->firstManager )
  {
    do
    {
      next = cur->next;
      if ( (baseManager *)gpWindowManager != cur && (baseManager *)gpMouseManager != cur )
        executive::RemoveManager(thisa, cur);
      cur = next;
    }
    while ( next );
  }
  if ( gpWindowManager->ready == 1 )
    executive::RemoveManager(thisa, (baseManager *)gpWindowManager);
  if ( gpMouseManager->ready == 1 )
    executive::RemoveManager(thisa, (baseManager *)gpMouseManager);
  gpInputManager->vtable->cleanUp((baseManager *)gpInputManager);
  ((void (*)(void))gpResourceManager->vtable->cleanUp)();
}