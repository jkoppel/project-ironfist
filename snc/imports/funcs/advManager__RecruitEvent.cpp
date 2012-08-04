{
  recruitUnit *thisa; // [sp+18h] [bp-2Ch]@1
  int quantityAvailable; // [sp+38h] [bp-Ch]@1
  recruitUnit *a2a; // [sp+40h] [bp-4h]@2

  LOWORD(quantityAvailable) = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
  thisa = (recruitUnit *)operator new(sizeof(recruitUnit));
  if ( thisa )
    a2a = recruitUnit::recruitUnit(thisa, &hro->army, creature, (int)&quantityAvailable);
  else
    a2a = 0;
  if ( !a2a )
    MemError();
  executive::DoDialog(gpExec, (baseManager *)a2a);
  operator delete(a2a);
  loc->flags = loc->flags & 7 | 8 * quantityAvailable;
}