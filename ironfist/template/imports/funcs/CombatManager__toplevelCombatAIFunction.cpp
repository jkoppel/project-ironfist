{
  CombatManager *thisa; // [sp+Ch] [bp-8h]@1
  int a3; // [sp+10h] [bp-4h]@1

  thisa = this;
  a3 = sub_469FA0(this);
  if ( *(&thisa->field_353F + thisa->currentActionSide)
    || thisa->playerID[thisa->currentActionSide] != -1
    && *(&byte_524758 + thisa->playerID[thisa->currentActionSide])
    && !*(_DWORD *)&autoCombatUseSpells
    || !CombatManager::pickBestSpell(thisa, thisa->currentActionSide, a3) )
  {
    if ( sub_469FA0(thisa) )
      couldBeCreatureActionType = 4;
    else
      sub_46A8E0(thisa, thisa->currentActionSide);
  }
}
