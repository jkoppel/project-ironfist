signed int __stdcall sub_458C60(int a1, int a2, signed int a3)
{
  signed int i; // [sp+1Ch] [bp-Ch]@1
  char *this; // [sp+20h] [bp-8h]@3

  for ( i = 0; curPlayer->numHeroes > i; ++i )
  {
    this = (char *)&gameObject->heroes[curPlayer->heroesOwned[i]];
    if ( Hero::hasArtifact((Hero *)this, ARTIFACT_CRYSTAL_BALL)
      && (signed int)(signed __int64)sqrt((double)((*(_DWORD *)(this + 25) - a1) * (*(_DWORD *)(this + 25) - a1)
                                                 + (*(_DWORD *)(this + 29) - a2) * (*(_DWORD *)(this + 29) - a2))) <= a3 )
      return 1;
  }
  return 0;
}
