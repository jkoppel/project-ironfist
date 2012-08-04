{
  recruitUnit *this; // [sp+18h] [bp-28h]@1
  baseManager *a2a; // [sp+3Ch] [bp-4h]@2

  this = (recruitUnit *)operator new(126);
  if ( this )
    a2a = (baseManager *)recruitUnit::recruitUnit(this, (armyGroup *)(a1 + 101), a2, a3);
  else
    a2a = 0;
  if ( !a2a )
    MemError();
  executive::DoDialog(gpExec, a2a);
  return operator delete(a2a);
}