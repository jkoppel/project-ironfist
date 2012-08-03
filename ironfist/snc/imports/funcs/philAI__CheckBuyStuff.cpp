{
  void *thisa; // [sp+10h] [bp-20h]@1
  int v2; // [sp+14h] [bp-1Ch]@33
  int v3; // [sp+18h] [bp-18h]@33
  int v4; // [sp+1Ch] [bp-14h]@36
  int v5; // [sp+20h] [bp-10h]@38
  town *v6; // [sp+24h] [bp-Ch]@5
  int v7; // [sp+28h] [bp-8h]@1
  int v8; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  v7 = 0;
  v8 = 0;
  game::CheckHeroConsistency(gpGame);
  if ( gpCurPlayer->resources[6] >= 200 && (gpCurPlayer->resources[6] >= 2500 || gpCurPlayer->numHeroes) )
  {
    LogInt((int)"CheckBuy Start", gpCurPlayer->resources[6], -999, -999, -999, -999, -999, -999);
    v6 = 0;
    if ( giBuildShipyard[giCurPlayer] < 0 )
    {
      if ( giBuildBoat[giCurPlayer] >= 0 )
        v6 = &gpGame->castles[giBuildBoat[giCurPlayer]];
    }
    else
    {
      v6 = &gpGame->castles[giBuildShipyard[giCurPlayer]];
    }
    if ( giBuildShipyard[giCurPlayer] < 0 )
    {
      if ( giBuildBoat[giCurPlayer] >= 0 )
        v6 = &gpGame->castles[giBuildBoat[giCurPlayer]];
    }
    else
    {
      v6 = &gpGame->castles[giBuildShipyard[giCurPlayer]];
    }
    if ( v6 && v6->ownerIdx != giCurPlayer )
    {
      giBuildShipyard[giCurPlayer] = -1;
      giBuildBoat[giCurPlayer] = giBuildShipyard[giCurPlayer];
      v6 = 0;
    }
    if ( giBuildShipyard[giCurPlayer] >= 0 )
    {
      if ( CanBuy((int)v6, 3) && CanBuild((unsigned int *)v6, 3) )
      {
        philAI::BuildBuilding((signed int)v6, 3);
        giBuildShipyard[giCurPlayer] = -1;
      }
      else
      {
        gpCurPlayer->resources[6] -= 2000;
        gpCurPlayer->resources[0] -= 20;
      }
    }
    if ( giBuildBoat[giCurPlayer] >= 0 )
    {
      if ( v6->buildingsBuiltFlags & 8 && gpCurPlayer->resources[6] >= 1000 && gpCurPlayer->resources[0] >= 10 )
      {
        if ( game::GetBoatsBuilt(gpGame) < 48
          && !advManager::GetCell(gpAdvManager, LOBYTE(v6->field_6), HIBYTE(v6->field_6))->objType
          && game::CreateBoat(gpGame, LOBYTE(v6->field_6), HIBYTE(v6->field_6), 0) != -1 )
        {
          gpCurPlayer->resources[6] -= 1000;
          gpCurPlayer->resources[0] -= 10;
        }
        giBuildBoat[giCurPlayer] = -1;
      }
      else
      {
        gpCurPlayer->resources[6] -= 1000;
        gpCurPlayer->resources[0] -= 10;
      }
    }
    philAI::CheckForCreatureUpgrades();
    philAI::DoAllHeroInteractions((int)thisa);
    while ( !v7 )
    {
      philAI::GetBestBHC(thisa, giCurPlayer, (int)&v2);
      if ( v3 >= 0 && philAI::CanBuyBHC((int)&v2) )
      {
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            philAI::BuildHero(v2, v4);
          }
          else if ( v3 == 2 )
          {
            philAI::BuildCreature(v2, v4, v5);
          }
        }
        else
        {
          philAI::BuildBuilding(v2, v4);
        }
        v8 = 1;
      }
      else
      {
        v7 = 1;
      }
    }
    if ( giBuildShipyard[giCurPlayer] >= 0 )
    {
      gpCurPlayer->resources[6] += 2000;
      gpCurPlayer->resources[0] += 20;
    }
    if ( giBuildBoat[giCurPlayer] >= 0 )
    {
      gpCurPlayer->resources[6] += 1000;
      gpCurPlayer->resources[0] += 10;
    }
    philAI::DoAllHeroInteractions((int)thisa);
    LogInt((int)"CheckBuy End  ", gpCurPlayer->resources[6], -999, -999, -999, -999, -999, -999);
  }
}