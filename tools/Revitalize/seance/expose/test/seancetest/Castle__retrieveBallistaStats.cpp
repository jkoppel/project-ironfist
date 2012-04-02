void __thiscall Castle::retrieveBallistaStats(Castle *this, int *numArchers, int *attack)
{
  signed int i; // [sp+10h] [bp-4h]@1
  signed int j; // [sp+10h] [bp-4h]@6

  *attack = this->mageGuildLevel;
  *numArchers = 0;
  for ( i = 19; i <= 30; ++i )
  {
    if ( (1 << i) & this->buildingsBuiltFlags )
      ++*numArchers;
  }
  for ( j = 0; j <= 15; ++j )
  {
    if ( (1 << j) & this->buildingsBuiltFlags )
      ++*numArchers;
  }
}
