{
  int i; // [sp+10h] [bp-8h]@1
  int j; // [sp+10h] [bp-8h]@6
  signed int k; // [sp+10h] [bp-8h]@9
  playerData *player; // [sp+14h] [bp-4h]@1

  gbRetreatWin = 0;
  player = &gpGame->players[playerNo];
  gpGame->couldBePlayerAlive[playerNo] = 1;
  ++gpGame->couldBeNumDefeatedPlayers;
  for ( i = 0; i < 144; ++i )
  {
    if ( gpGame->_8[i + 1008] == playerNo )
      game::ClaimMine(gpGame, i, -1);
  }
  for ( j = player->numHeroes - 1; j >= 0; --j )
    hero::Deallocate(&gpGame->heroes[player->heroesOwned[j]], 1);
  for ( k = 0; k < 2; ++k )
  {
    if ( gpGame->relatedToHeroForHireStatus[player->heroesForPurchase[k]] == 64 )
      gpGame->relatedToHeroForHireStatus[player->heroesForPurchase[k]] = -1;
  }
  if ( gbRemoteOn )
  {
    if ( gbHumanPlayer[playerNo] )
      HandleRemoteDeadPlayerExit(playerNo);
    else
      SendMapChange(10, playerNo, 0, 0, -999, 0, 0);
  }
}