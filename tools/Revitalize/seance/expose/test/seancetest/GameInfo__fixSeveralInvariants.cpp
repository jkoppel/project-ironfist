void __thiscall GameInfo::fixSeveralInvariants(GameInfo *this)
{
  GameInfo *thisa; // [sp+Ch] [bp-28h]@1
  MapTile *v2; // [sp+18h] [bp-1Ch]@25
  signed int i; // [sp+1Ch] [bp-18h]@5
  signed int j; // [sp+1Ch] [bp-18h]@12
  signed int k; // [sp+1Ch] [bp-18h]@44
  signed int l; // [sp+1Ch] [bp-18h]@53
  signed int playerIdx; // [sp+20h] [bp-14h]@1
  int playerIdxa; // [sp+20h] [bp-14h]@9
  signed int playerIdxb; // [sp+20h] [bp-14h]@42
  signed int playerIdxc; // [sp+20h] [bp-14h]@51
  signed int sumSomething; // [sp+24h] [bp-10h]@1
  int row; // [sp+28h] [bp-Ch]@23
  int col; // [sp+2Ch] [bp-8h]@21
  Hero *v14; // [sp+30h] [bp-4h]@27

  thisa = this;
  sumSomething = 0;
  for ( playerIdx = 0; this->numPlayers > playerIdx; ++playerIdx )
  {
    if ( !this->couldBePlayerAlive[playerIdx] )
    {
      sumSomething += this->players[playerIdx].numHeroes;
      for ( i = 0; this->players[playerIdx].numHeroes > i; ++i )
        ;
    }
  }
  for ( playerIdxa = 0; thisa->numPlayers > playerIdxa; ++playerIdxa )
  {
    if ( !thisa->couldBePlayerAlive[playerIdxa] )
    {
      for ( j = 0; j < 2; ++j )
      {
        if ( thisa->relatedToHeroForHireStatus[*(&thisa->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa)] >= 0
          && thisa->relatedToHeroForHireStatus[*(&thisa->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa)] <= 5
          || sumSomething < 40
          && thisa->relatedToHeroForHireStatus[*(&thisa->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa)] == -1 )
        {
          *(&thisa->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa) = GameInfo::getRandomHeroFromHeroPool(
                                                                                         thisa,
                                                                                         playerIdxa,
                                                                                         -1,
                                                                                         0);
          thisa->relatedToHeroForHireStatus[*(&thisa->players[0].heroesForPurchase[284 * playerIdxa] + j - playerIdxa)] = 64;
        }
      }
    }
  }
  for ( col = 0; col < mapWidth; ++col )
  {
    for ( row = 0; row < mapHeight; ++row )
    {
      v2 = AdvManager::getTile(advManager, col, row);
      if ( v2->objType == 170 )
      {
        if ( (signed int)(unsigned __int8)((unsigned __int8)(v2->flags >> 8) >> -5) >= 54 )
        {
          v2->objType = 0;
        }
        else
        {
          v14 = &thisa->heroes[(unsigned __int8)((unsigned __int8)(v2->flags >> 8) >> -5)];
          if ( thisa->heroes[(unsigned __int8)((unsigned __int8)(v2->flags >> 8) >> -5)].x != col
            || thisa->heroes[(unsigned __int8)((unsigned __int8)(v2->flags >> 8) >> -5)].y != row )
          {
            v2->objType = 0;
            v2->flags &= 7u;
          }
          if ( v14->probablyOwnerIdx < 0 || v14->probablyOwnerIdx >= 6 )
          {
            if ( *(_WORD *)&v14->_4[12] == 163 )
              gameObject->castles[*(_WORD *)&v14->_4[14]].visitingHeroIdx = -1;
            if ( v14->x != col || v14->y != row )
            {
              v2->objType = 0;
              v2->flags &= 7u;
            }
            else
            {
              sub_42CC90(v14->x, v14->y, *(_WORD *)&v14->_4[12], *(_WORD *)&v14->_4[14], 0, 1);
            }
          }
        }
      }
    }
  }
  for ( playerIdxb = 0; playerIdxb < 54; ++playerIdxb )
  {
    for ( k = 0; k < 5; ++k )
    {
      if ( thisa->heroes[playerIdxb].army.creatureTypes[k] == -1 || thisa->heroes[playerIdxb].army.quantities[k] < 0 )
        thisa->heroes[playerIdxb].army.quantities[k] = 0;
    }
  }
  for ( playerIdxc = 0; playerIdxc < 72; ++playerIdxc )
  {
    for ( l = 0; l < 5; ++l )
    {
      if ( thisa->castles[playerIdxc].garrison.creatureTypes[l] == -1
        || thisa->castles[playerIdxc].garrison.quantities[l] < 0 )
        thisa->castles[playerIdxc].garrison.quantities[l] = 0;
    }
  }
}
