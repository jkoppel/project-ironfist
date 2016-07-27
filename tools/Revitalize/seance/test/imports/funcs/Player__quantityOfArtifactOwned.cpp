{
  signed int i; // [sp+10h] [bp-Ch]@1
  signed int j; // [sp+14h] [bp-8h]@3
  int count; // [sp+18h] [bp-4h]@1

  count = 0;
  for ( i = 0; this->numHeroes > i; ++i )
  {
    for ( j = 0; j < 14; ++j )
    {
      if ( gameObject->heroes[this->heroesOwned[i]].artifacts[j] == artifact )
        ++count;
    }
  }
  return count;
}
