{
  Player *thisa; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  thisa = this;
  for ( i = 0; thisa->numHeroes > i; ++i )
  {
    if ( sub_419790(gameObject, thisa->heroesOwned[i]) )
      return 1;
  }
  return 0;
}
