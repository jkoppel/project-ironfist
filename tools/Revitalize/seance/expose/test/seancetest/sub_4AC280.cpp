int __cdecl sub_4AC280()
{
  int result; // eax@2
  int v1; // [sp+10h] [bp-10h]@3
  signed int v2; // [sp+14h] [bp-Ch]@1
  int i; // [sp+18h] [bp-8h]@1
  char *hero; // [sp+1Ch] [bp-4h]@3

  v2 = -1;
  dword_530734 = -1;
  for ( i = 0; ; ++i )
  {
    result = curPlayer->numHeroes;
    if ( result <= i )
      break;
    hero = (char *)&gameObject->heroes[curPlayer->heroesOwned[i]];
    v1 = getArmyStrength(&gameObject->heroes[curPlayer->heroesOwned[i]].army, (Hero *)hero, 1, 0, -1, 0);
    if ( v1 > v2 )
    {
      v2 = v1;
      dword_530734 = (unsigned __int8)hero[2];
    }
  }
  return result;
}
