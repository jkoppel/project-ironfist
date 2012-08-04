{
  int result; // eax@2
  int v1; // [sp+10h] [bp-10h]@3
  signed int v2; // [sp+14h] [bp-Ch]@1
  int i; // [sp+18h] [bp-8h]@1
  char *hro; // [sp+1Ch] [bp-4h]@3

  v2 = -1;
  iAlphaMale = -1;
  for ( i = 0; ; ++i )
  {
    result = gpCurPlayer->numHeroes;
    if ( result <= i )
      break;
    hro = (char *)&gpGame->heroes[gpCurPlayer->heroesOwned[i]];
    v1 = philAI::FightValueOfStack(&gpGame->heroes[gpCurPlayer->heroesOwned[i]].army, (hero *)hro, 1, 0, -1, 0);
    if ( v1 > v2 )
    {
      v2 = v1;
      iAlphaMale = (unsigned __int8)hro[2];
    }
  }
  return result;
}