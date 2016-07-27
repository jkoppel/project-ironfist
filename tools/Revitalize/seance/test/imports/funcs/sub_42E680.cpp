{
  int result; // eax@2
  int playerIdx; // [sp+Ch] [bp-10h]@1
  signed int k; // [sp+10h] [bp-Ch]@7
  signed int i; // [sp+14h] [bp-8h]@3
  signed int j; // [sp+18h] [bp-4h]@5

  for ( playerIdx = 0; ; ++playerIdx )
  {
    result = gameObject->numPlayers;
    if ( result <= playerIdx )
      break;
    for ( i = 0; gameObject->players[playerIdx].numHeroes > i; ++i )
    {
      for ( j = 0; gameObject->numPlayers > j; ++j )
      {
        for ( k = 0; k < 2; ++k )
        {
          if ( gameObject->players[j].heroesForPurchase[k] == *(&gameObject->players[0].heroesOwned[284 * playerIdx]
                                                              + i
                                                              - playerIdx) )
            gameObject->players[j].heroesForPurchase[k] = GameInfo::getRandomHeroFromHeroPool(
                                                            gameObject,
                                                            playerIdx,
                                                            -1,
                                                            0);
        }
      }
    }
  }
  return result;
}
