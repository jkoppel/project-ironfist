{
  ManagerManager *thisa; // edi@1
  AbstractManager *prev; // ecx@2
  AbstractManager *v4; // eax@5
  AbstractManager *next; // eax@7

  thisa = this;
  if ( mgr )
  {
    mgr->vtable->cleanUp(mgr);
    prev = mgr->prev;
    if ( prev )
    {
      next = mgr->next;
      prev->next = next;
      if ( next )
        next->prev = prev;
      else
        thisa->lastManager = prev;
      mgr->prev = 0;
      mgr->next = 0;
    }
    else
    {
      if ( thisa->firstManager == thisa->lastManager )
      {
        thisa->lastManager = 0;
        thisa->firstManager = 0;
      }
      else
      {
        v4 = mgr->next;
        thisa->firstManager = v4;
        v4->prev = 0;
      }
      mgr->prev = 0;
      mgr->next = 0;
    }
  }
}
