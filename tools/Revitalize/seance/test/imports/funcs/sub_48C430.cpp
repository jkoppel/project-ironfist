{
  void *v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+18h] [bp-8h]@1
  int a2a; // [sp+1Ch] [bp-4h]@2

  v3 = this;
  v4 = (int)operator new(0x5Au);
  if ( v4 )
    a2a = SwapManager_constructor(v4, a2, a3);
  else
    a2a = 0;
  if ( !a2a )
    fatalOutOfMemoryError();
  ManagerManager::weirdAddAndRemoveManagerThing(managerManager, (AbstractManager *)a2a);
  operator delete((void *)a2a);
  sub_4506B0(v3, 1, 0);
}
