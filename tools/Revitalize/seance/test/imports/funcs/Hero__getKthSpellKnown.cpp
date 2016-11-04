{
  Hero *thisa; // [sp+Ch] [bp-Ch]@1
  int i; // [sp+10h] [bp-8h]@1
  int v6; // [sp+14h] [bp-4h]@1

  thisa = this;
  v6 = 0;
  for ( i = 0; i < 65; ++i )
  {
    if ( Hero::hasSpell(thisa, (Spell)i) )
    {
      if ( type == ATTR_COMBAT_SPELL
        || !type && spell_table[i].attributes & ATTR_COMBAT_SPELL
        || type == 1 && !(spell_table[i].attributes & ATTR_COMBAT_SPELL) )
        ++v6;
      if ( k == v6 )
        return i;
    }
  }
  return -1;
}
