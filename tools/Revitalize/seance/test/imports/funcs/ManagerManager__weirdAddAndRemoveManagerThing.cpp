{
  int numMgrs; // esi@1
  ManagerManager *thisa; // edi@1
  AbstractManager *cur; // ecx@1
  int i; // eax@2
  int j; // edx@13
  AbstractManager *v7; // ecx@14
  AbstractManager *v8; // eax@14
  AbstractManager *v9; // ebx@14
  ManagerManager othMgrMgr; // [sp+Ch] [bp-100h]@1
  AbstractManager *mgrs[20]; // [sp+1Ch] [bp-F0h]@3
  AbstractManager *prevs[20]; // [sp+6Ch] [bp-A0h]@3
  AbstractManager *nexts[20]; // [sp+BCh] [bp-50h]@3

  numMgrs = 0;
  thisa = this;
  othMgrMgr.firstManager = 0;
  othMgrMgr.lastManager = 0;
  othMgrMgr.currentManager = 0;
  cur = this->firstManager;
  othMgrMgr.field_C = 0;
  if ( cur )
  {
    i = 0;
    do
    {
      mgrs[i] = cur;
      prevs[i] = cur->prev;
      cur = cur->next;
      nexts[i] = cur;
      ++i;
      ++numMgrs;
    }
    while ( cur );
  }
  if ( ManagerManager::addManager(thisa, a2, -1) )
    terminate("Can't add manager!");
  if ( ManagerManager::addManager(&othMgrMgr, (AbstractManager *)mouseManager, -1) )
    terminate("Can't add manager!");
  if ( ManagerManager::addManager(&othMgrMgr, (AbstractManager *)HeroWindowManager::instance, -1) )
    terminate("Can't add manager!");
  if ( ManagerManager::addManager(&othMgrMgr, a2, -1) )
    terminate("Can't add manager!");
  ManagerManager::sendInputToManagers(&othMgrMgr);
  ManagerManager__removeManager(thisa, a2);
  if ( numMgrs > 0 )
  {
    j = 0;
    do
    {
      v7 = mgrs[j];
      v8 = prevs[j];
      v9 = nexts[j];
      ++j;
      --numMgrs;
      v7->prev = v8;
      v7->next = v9;
    }
    while ( numMgrs );
  }
  return othMgrMgr.field_C;
}
