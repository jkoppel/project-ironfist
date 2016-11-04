{
  int v1; // [sp+Ch] [bp-Ch]@1
  int i; // [sp+10h] [bp-8h]@1
  int j; // [sp+10h] [bp-8h]@6
  signed int k; // [sp+10h] [bp-8h]@9
  char *v5; // [sp+14h] [bp-4h]@1

  v1 = a1;
  isRetreating = 0;
  v5 = (char *)&gameObject->players[a1];
  gameObject->couldBePlayerAlive[a1] = 1;
  ++gameObject->couldBeNumDefeatedPlayers;
  for ( i = 0; i < 144; ++i )
  {
    if ( gameObject->_8[i + 1008] == v1 )
      sub_4212E0(gameObject, i, -1);
  }
  for ( j = v5[1] - 1; j >= 0; --j )
    Hero::delete(&gameObject->heroes[v5[j + 4]], 1);
  for ( k = 0; k < 2; ++k )
  {
    if ( gameObject->relatedToHeroForHireStatus[v5[k + 12]] == 64 )
      gameObject->relatedToHeroForHireStatus[v5[k + 12]] = -1;
  }
  if ( dword_4F7494 )
  {
    if ( dword_524810[v1] )
      sub_438DE0(v1);
    else
      sub_4C3190(10, v1, 0, 0, -999, 0, 0);
  }
}
