char *__stdcall sub_4AE470(int a1)
{
  char *result; // eax@8
  signed int i; // [sp+10h] [bp-10h]@2
  signed int v3; // [sp+18h] [bp-8h]@1
  int v4; // [sp+1Ch] [bp-4h]@1

  v4 = 0;
  v3 = -1;
  if ( sub_418E10(curPlayer) )
  {
    for ( i = 0; curPlayer->numHeroes > i; ++i )
    {
      if ( *(_DWORD *)&gameObject->heroes[*(&gameObject->players[0].heroesOwned[284 * a1] + i - a1)]._4[20] > v4 )
      {
        v4 = *(_DWORD *)&gameObject->heroes[*(&gameObject->players[0].heroesOwned[284 * a1] + i - a1)]._4[20];
        v3 = i;
      }
    }
  }
  if ( v3 < 0 )
  {
    gameObject->players[a1]._1[0] = -1;
    result = 0;
  }
  else
  {
    result = (char *)&gameObject->heroes[*(&gameObject->players[0].heroesOwned[284 * a1] + v3 - a1)];
  }
  return result;
}
