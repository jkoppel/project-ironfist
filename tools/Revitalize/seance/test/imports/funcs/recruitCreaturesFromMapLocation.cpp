{
  unsigned __int16 result; // ax@6
  RecruitManager *this; // [sp+18h] [bp-2Ch]@1
  int quantityAvailable; // [sp+38h] [bp-Ch]@1
  RecruitManager *a2a; // [sp+40h] [bp-4h]@2

  LOWORD(quantityAvailable) = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
  this = (RecruitManager *)operator new(sizeof(RecruitManager));
  if ( this )
    a2a = RecruitManager_constructor(this, &hero->army, creature, (int)&quantityAvailable);
  else
    a2a = 0;
  if ( !a2a )
    fatalOutOfMemoryError();
  ManagerManager::weirdAddAndRemoveManagerThing(managerManager, (AbstractManager *)a2a);
  operator delete(a2a);
  result = loc->flags & 7 | 8 * quantityAvailable;
  loc->flags = result;
  return result;
}
