{
  int result; // eax@9
  Hero *thisa; // [sp+10h] [bp-10h]@1
  int numCombat; // [sp+14h] [bp-Ch]@1
  Spell i; // [sp+18h] [bp-8h]@1
  int numAdventure; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  numCombat = 0;
  numAdventure = 0;
  for ( i = 0; (signed int)i < 65; ++i )
  {
    if ( Hero::hasSpell(thisa, i) )
    {
      if ( spell_table[i].attributes & ATTR_COMBAT_SPELL )
        ++numCombat;
      else
        ++numAdventure;
    }
  }
  if ( type )
  {
    if ( type == SPELL_CATEGORY_ADVENTURE )
    {
      result = numAdventure;
    }
    else
    {
      if ( type == SPELL_CATEGORY_ALL )
        result = numAdventure + numCombat;
      else
        result = 0;
    }
  }
  else
  {
    result = numCombat;
  }
  return result;
}
