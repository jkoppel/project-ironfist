{
  void *v3; // [sp+Ch] [bp-Ch]@1
  signed int v4; // [sp+10h] [bp-8h]@1
  signed int i; // [sp+14h] [bp-4h]@2
  int j; // [sp+14h] [bp-4h]@7
  int k; // [sp+14h] [bp-4h]@12

  v3 = this;
  v4 = -1;
  if ( curPlayer->_1[0] != -1 )
  {
    for ( i = 0; curPlayer->numHeroes > i; ++i )
    {
      if ( curPlayer->heroesOwned[i] == curPlayer->_1[0] )
        v4 = i;
    }
  }
  for ( j = v4 + 1; curPlayer->numHeroes > j; ++j )
  {
    if ( sub_419790(gameObject, curPlayer->heroesOwned[j]) )
      return *((_BYTE *)v3 + j + 4);
  }
  for ( k = 0; v4 + 1 > k; ++k )
  {
    if ( sub_419790(gameObject, curPlayer->heroesOwned[k]) )
      return *((_BYTE *)v3 + k + 4);
  }
  return -1;
}
