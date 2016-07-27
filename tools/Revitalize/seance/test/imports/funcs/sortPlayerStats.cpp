{
  int result; // eax@2
  int tmp1; // ST14_4@6
  char tmp2; // ST20_1@6
  int i; // [sp+18h] [bp-Ch]@1
  int j; // [sp+1Ch] [bp-8h]@3

  for ( i = 0; ; ++i )
  {
    result = gameObject->numPlayers - 1;
    if ( result <= i )
      break;
    for ( j = i + 1; gameObject->numPlayers > j; ++j )
    {
      if ( playerStats[j] > playerStats[i] )
      {
        tmp1 = playerStats[i];
        playerStats[i] = playerStats[j];
        playerStats[j] = tmp1;
        tmp2 = playerIndices[i];
        playerIndices[i] = playerIndices[j];
        playerIndices[j] = tmp2;
      }
    }
  }
  return result;
}
