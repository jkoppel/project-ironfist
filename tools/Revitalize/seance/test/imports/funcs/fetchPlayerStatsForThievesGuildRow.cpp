{
  int *playerAmt; // [sp+10h] [bp-28h]@1
  int rowa; // [sp+14h] [bp-24h]@1
  Castle *this; // [sp+18h] [bp-20h]@41
  int v6; // [sp+1Ch] [bp-1Ch]@36
  int numTowns; // [sp+20h] [bp-18h]@4
  int numCastles; // [sp+24h] [bp-14h]@4
  signed int l; // [sp+28h] [bp-10h]@28
  signed int m; // [sp+28h] [bp-10h]@36
  signed int n; // [sp+28h] [bp-10h]@39
  signed int i; // [sp+2Ch] [bp-Ch]@7
  signed int j; // [sp+2Ch] [bp-Ch]@14
  signed int k; // [sp+2Ch] [bp-Ch]@26
  signed int playerIdx; // [sp+30h] [bp-8h]@1
  Hero *hero; // [sp+34h] [bp-4h]@28

  playerAmt = playerStats;
  rowa = row;
  for ( playerIdx = 0; gameObject->numPlayers > playerIdx; ++playerIdx )
  {
    numTowns = 0;
    numCastles = 0;
    playerIndices[playerIdx] = playerIdx;
    if ( gameObject->couldBePlayerAlive[playerIdx] )
    {
      playerAmt[playerIdx] = -1;
    }
    else
    {
      switch ( rowa )
      {
        case 0:
          for ( i = 0; i < 72; ++i )
          {
            if ( gameObject->castles[i].ownerIdx == playerIdx )
            {
              if ( gameObject->castles[i].buildingsBuiltFlags & 0x20 )
                ++numTowns;
            }
          }
          playerAmt[playerIdx] = numTowns;
          break;
        case 1:
          for ( j = 0; j < 72; ++j )
          {
            if ( gameObject->castles[j].ownerIdx == playerIdx && gameObject->castles[j].buildingsBuiltFlags & 0x40 )
              ++numCastles;
          }
          playerAmt[playerIdx] = numCastles;
          break;
        case 2:
          playerAmt[playerIdx] = gameObject->players[playerIdx].numHeroes;
          break;
        case 3:
          playerAmt[playerIdx] = gameObject->players[playerIdx].resources[6];
          break;
        case 4:
          playerAmt[playerIdx] = gameObject->players[playerIdx].resources[0]
                               + gameObject->players[playerIdx].resources[2];
          break;
        case 5:
          playerAmt[playerIdx] = gameObject->players[playerIdx].resources[4]
                               + gameObject->players[playerIdx].resources[3]
                               + gameObject->players[playerIdx].resources[1]
                               + gameObject->players[playerIdx].resources[5];
          break;
        case 6:
          playerAmt[playerIdx] = getNumVisitedObelisks(playerIdx);
          break;
        case 7:
          playerAmt[playerIdx] = 0;
          for ( k = 0; gameObject->players[playerIdx].numHeroes > k; ++k )
          {
            hero = &gameObject->heroes[gameObject->players[playerIdx].heroesOwned[k]];
            for ( l = 0; l < 14; ++l )
            {
              if ( hero->artifacts[l] != -1 && hero->artifacts[l] != ARTIFACT_MAGIC_BOOK )
                ++playerAmt[playerIdx];
            }
          }
          break;
        case 8:
          v6 = 0;
          for ( m = 0; gameObject->players[playerIdx].numHeroes > m; ++m )
            v6 += getArmyStrength(
                    &gameObject->heroes[*(&gameObject->players[0].heroesOwned[284 * playerIdx] + m - playerIdx)].army,
                    &gameObject->heroes[*(&gameObject->players[0].heroesOwned[284 * playerIdx] + m - playerIdx)],
                    0,
                    0,
                    0,
                    0);
          for ( n = 0; gameObject->players[playerIdx].numCastles > n; ++n )
          {
            this = &gameObject->castles[*(&gameObject->players[0].castlesOwned[284 * playerIdx] + n - playerIdx)];
            if ( Castle::hasGarrison(&gameObject->castles[*(&gameObject->players[0].castlesOwned[284 * playerIdx]
                                                          + n
                                                          - playerIdx)]) )
              v6 += getArmyStrength(&this->garrison, 0, 0, 0, 0, 0);
          }
          playerAmt[playerIdx] = v6;
          break;
        case 9:
          playerAmt[playerIdx] = GameInfo::computePlayerIncome(gameObject, playerIdx);
          break;
        default:
          continue;
      }
    }
  }
}
