{
  int result; // eax@2
  int playerIdx; // [sp+Ch] [bp-10h]@1
  signed int k; // [sp+10h] [bp-Ch]@7
  signed int i; // [sp+14h] [bp-8h]@3
  signed int j; // [sp+18h] [bp-4h]@5

  for ( playerIdx = 0; ; ++playerIdx )
  {
    result = gpGame->numPlayers;
    if ( result <= playerIdx )
      break;
    for ( i = 0; gpGame->players[playerIdx].numHeroes > i; ++i )
    {
      for ( j = 0; gpGame->numPlayers > j; ++j )
      {
        for ( k = 0; k < 2; ++k )
        {
          if ( gpGame->players[j].heroesForPurchase[k] == *(&gpGame->players[0].heroesOwned[284 * playerIdx]
                                                          + i
                                                          - playerIdx) )
            gpGame->players[j].heroesForPurchase[k] = game::GetNewHeroId(gpGame, playerIdx, -1, 0);
        }
      }
    }
  }
  return result;
}