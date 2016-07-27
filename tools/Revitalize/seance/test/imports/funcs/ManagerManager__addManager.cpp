{
  ManagerManager *thisa; // edi@1
  signed int result; // eax@2
  int idx; // ebx@3
  AbstractManager *prevLastMan; // eax@4
  AbstractManager *last; // eax@9
  AbstractManager *cur; // ecx@9
  AbstractManager *v9; // eax@13
  AbstractManager *v10; // eax@15

  thisa = this;
  if ( !mgr )
    return 3;
  idx = argIdx;
  if ( argIdx == -1 )
  {
    prevLastMan = this->lastManager;
    idx = 0;
    if ( prevLastMan )
      idx = prevLastMan->idx + 1;
  }
  if ( !mgr->ready && ((int (__thiscall *)(_DWORD))mgr->vtable->initialize)(mgr) )
    return 3;
  last = thisa->lastManager;
  cur = thisa->lastManager;
  if ( !cur )
    goto LABEL_23;
  do
  {
    if ( cur->idx <= idx )
      break;
    cur = cur->prev;
  }
  while ( cur );
  if ( cur )
  {
    if ( !cur->next )
    {
      mgr->next = 0;
      mgr->prev = last;
      thisa->lastManager->next = mgr;
      result = 0;
      thisa->lastManager = mgr;
      return result;
    }
    mgr->prev = cur;
    mgr->next = cur->next;
    cur->next->prev = mgr;
    cur->next = mgr;
  }
  else
  {
LABEL_23:
    v9 = thisa->firstManager;
    mgr->prev = 0;
    mgr->next = v9;
    if ( thisa->firstManager )
      thisa->firstManager->prev = mgr;
    v10 = thisa->lastManager;
    thisa->firstManager = mgr;
    if ( !v10 )
    {
      result = 0;
      thisa->lastManager = mgr;
      return result;
    }
  }
  return 0;
}
