{
  RecruitManager *this; // [sp+18h] [bp-28h]@1
  AbstractManager *a2a; // [sp+3Ch] [bp-4h]@2

  this = (RecruitManager *)operator new(0x7Eu);
  if ( this )
    a2a = (AbstractManager *)RecruitManager_constructor(this, (ArmyInfo *)(a1 + 101), a2, a3);
  else
    a2a = 0;
  if ( !a2a )
    fatalOutOfMemoryError();
  ManagerManager::weirdAddAndRemoveManagerThing(managerManager, a2a);
  return operator delete(a2a);
}
