{
  int numMgrs; // esi@1
  executive *thisa; // edi@1
  baseManager *cur; // ecx@1
  int i; // eax@2
  int j; // edx@13
  baseManager *v7; // ecx@14
  baseManager *v8; // eax@14
  baseManager *v9; // ebx@14
  executive othMgrMgr; // [sp+Ch] [bp-100h]@1
  baseManager *mgrs[20]; // [sp+1Ch] [bp-F0h]@3
  baseManager *prevs[20]; // [sp+6Ch] [bp-A0h]@3
  baseManager *nexts[20]; // [sp+BCh] [bp-50h]@3

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
  if ( executive::AddManager(thisa, a2, -1) )
    ShutDown("Can't add manager!");
  if ( executive::AddManager(&othMgrMgr, (baseManager *)gpMouseManager, -1) )
    ShutDown("Can't add manager!");
  if ( executive::AddManager(&othMgrMgr, (baseManager *)gpWindowManager, -1) )
    ShutDown("Can't add manager!");
  if ( executive::AddManager(&othMgrMgr, a2, -1) )
    ShutDown("Can't add manager!");
  executive::MainLoop(&othMgrMgr);
  executive::RemoveManager(thisa, a2);
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