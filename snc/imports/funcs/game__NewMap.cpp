{
  int v2; // eax@105
  int v3; // ST74_4@110
  int v4; // ST6C_4@110
  mapCell *v5; // ST34_4@110
  int v6; // ebx@116
  int v7; // ebx@116
  int v8; // ebx@126
  int v9; // ebx@137
  int v10; // ebx@137
  int v11; // ecx@158
  int v12; // ecx@164
  double v14; // [sp+14h] [bp-68h]@151
  int v15; // [sp+1Ch] [bp-60h]@133
  int v16; // [sp+20h] [bp-5Ch]@130
  int v17; // [sp+2Ch] [bp-50h]@171
  char *v18; // [sp+30h] [bp-4Ch]@0
  char v19; // [sp+34h] [bp-48h]@0
  signed int v20; // [sp+38h] [bp-44h]@76
  signed int v21; // [sp+38h] [bp-44h]@90
  signed int k; // [sp+3Ch] [bp-40h]@78
  signed int l; // [sp+3Ch] [bp-40h]@95
  signed int v24; // [sp+44h] [bp-38h]@53
  int v25; // [sp+4Ch] [bp-30h]@7
  signed int faction; // [sp+50h] [bp-2Ch]@87
  int v27; // [sp+54h] [bp-28h]@42
  signed int j; // [sp+54h] [bp-28h]@57
  signed int m; // [sp+54h] [bp-28h]@108
  int v30; // [sp+54h] [bp-28h]@116
  signed int n; // [sp+54h] [bp-28h]@148
  signed int ii; // [sp+54h] [bp-28h]@188
  signed int playerIdx; // [sp+58h] [bp-24h]@7
  signed int playerIdxa; // [sp+58h] [bp-24h]@15
  signed int playerIdxb; // [sp+58h] [bp-24h]@20
  signed int playerIdxc; // [sp+58h] [bp-24h]@23
  signed int playerIdxd; // [sp+58h] [bp-24h]@26
  signed int playerIdxe; // [sp+58h] [bp-24h]@29
  signed int playerIdxf; // [sp+58h] [bp-24h]@32
  signed int playerIdxg; // [sp+58h] [bp-24h]@35
  signed int playerIdxh; // [sp+58h] [bp-24h]@42
  signed int playerIdxi; // [sp+58h] [bp-24h]@51
  int playerIdxj; // [sp+58h] [bp-24h]@69
  signed int playerIdxk; // [sp+58h] [bp-24h]@106
  int playerIdxl; // [sp+58h] [bp-24h]@116
  signed int playerIdxm; // [sp+58h] [bp-24h]@144
  signed int playerIdxn; // [sp+58h] [bp-24h]@169
  signed int v48; // [sp+60h] [bp-1Ch]@116
  int v49; // [sp+64h] [bp-18h]@158
  int v50; // [sp+64h] [bp-18h]@164
  int v51; // [sp+68h] [bp-14h]@7
  int v52; // [sp+6Ch] [bp-10h]@1
  signed int i; // [sp+74h] [bp-8h]@55
  int v54; // [sp+78h] [bp-4h]@116

  v52 = FindLastToken(gMapName, 46);
  if ( v52 && StrEqNoCase((int *)(v52 + 1), (int *)"MX2") )
    LOBYTE(xIsExpansionMap) = 1;
  if ( xIsExpansionMap )
    gTownEligibleBuildMask[5] |= 4u;
  else
    gTownEligibleBuildMask[5] &= 0xFFFFFFFBu;
  gbInNewGameSetup = 1;
  giCurPlayer = 0;
  gpCurPlayer = gpGame->players;
  giCurPlayerBit = 1;
  giCurWatchPlayerBit = 1;
  giCurWatchPlayer = 0;
  v51 = Random(0, 5);
  v25 = iLastMsgNumHumanPlayers;
  for ( playerIdx = 0; playerIdx < 6; ++playerIdx )
  {
    if ( gpGame->_1[702] > playerIdx )
    {
      if ( this->_4[playerIdx + 6] == 10 )
        gbSetupGamePosToRealGamePos[playerIdx] = v25++;
      else
        gbSetupGamePosToRealGamePos[playerIdx] = this->_4[playerIdx + 6];
    }
    else
    {
      gbSetupGamePosToRealGamePos[playerIdx] = -1;
    }
  }
  for ( playerIdxa = 0; playerIdxa < 6; ++playerIdxa )
  {
    this->players[playerIdxa].color = -1;
    gcColorToPlayerPos[playerIdxa] = -1;
    gcColorToSetupPos[playerIdxa] = -1;
    if ( gpGame->_4[playerIdxa] == 7 )
      gpGame->_4[playerIdxa] = v51;
    v51 = (v51 + 1) % 6;
  }
  for ( playerIdxb = 0; this->numPlayers > playerIdxb; ++playerIdxb )
    gcColorToSetupPos[this->_3[playerIdxb + 375]] = playerIdxb;
  for ( playerIdxc = 0; this->numPlayers > playerIdxc; ++playerIdxc )
    this->players[gbSetupGamePosToRealGamePos[playerIdxc]].color = this->_3[playerIdxc + 375];
  for ( playerIdxd = 0; this->numPlayers > playerIdxd; ++playerIdxd )
    gcColorToPlayerPos[this->players[playerIdxd].color] = playerIdxd;
  for ( playerIdxe = 0; this->numPlayers > playerIdxe; ++playerIdxe )
  {
    this->players[playerIdxe].numCastles = 0;
    HIBYTE(this->players[playerIdxe].field_45) = 0;
    LOBYTE(this->players[playerIdxe].field_45) = -1;
    this->players[playerIdxe].numHeroes = 0;
    this->players[playerIdxe].field_3 = 0;
    this->players[playerIdxe].curHeroIdx = -1;
  }
  game::RandomizeHeroPool(this);
  strcpy(gMapName, (char *)a2);
  game::LoadMap(this, (int)gMapName);
  game::InitRandomArtifacts((int)this);
  game::ProcessRandomObjects(this);
  game::ProcessMapExtra(this);
  game::SetupTowns(this);
  game::InitializePasswords();
  for ( playerIdxf = 0; playerIdxf < 6; ++playerIdxf )
    this->players[playerIdxf]._4[1] = 0;
  game::RandomizeEvents(this);
  game::ProcessOnMapHeroes(this);
  this->couldBeNumDefeatedPlayers = 0;
  for ( playerIdxg = this->numPlayers; playerIdxg < 6; ++playerIdxg )
    this->couldBePlayerAlive[playerIdxg] = 1;
  if ( this->winConditionType == 4 || this->winConditionType == 2 )
  {
    this->field_2C7 = 1;
    this->field_2C8 = 0;
  }
  if ( this->winConditionType == 4 )
  {
    v27 = 0;
    for ( playerIdxh = 0; playerIdxh < 6; ++playerIdxh )
    {
      if ( this->_1[playerIdxh + 684] )
        ++v27;
      if ( this->winConditionArgument + 1 == v27 )
      {
        *(_WORD *)&this->_3[3] = playerIdxh;
        playerIdxh = 99;
      }
    }
  }
  if ( this->winConditionType == 3 )
    this->field_2C7 = 1;
  for ( playerIdxi = 0; this->numPlayers > playerIdxi; ++playerIdxi )
  {
    this->players[playerIdxi].field_40 = 0;
    LOBYTE(this->players[playerIdxi].field_41) = -1;
    HIBYTE(this->players[playerIdxi].field_41) = -1;
    v24 = -1;
    if ( !this->_2[3] && this->players[playerIdxi].numCastles > 0 )
    {
      for ( i = 0; i < 2; ++i )
      {
        for ( j = 0; this->players[playerIdxi].numCastles > j; ++j )
        {
          if ( v24 == -1
            && this->castles[this->players[playerIdxi].castlesOwned[j]].visitingHeroIdx == -1
            && (this->castles[this->players[playerIdxi].castlesOwned[j]].buildingsBuiltFlags & 0x40 || i == 1) )
            v24 = j;
        }
      }
    }
    if ( v24 != -1 )
    {
      *(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi) = game::GetNewHeroId(this, playerIdxi, this->castles[this->players[playerIdxi].castlesOwned[v24]].factionID, 0);
      this->relatedToHeroForHireStatus[*(&this->players[0].heroesOwned[284 * playerIdxi]
                                       + this->players[playerIdxi].numHeroes
                                       - playerIdxi)] = playerIdxi;
      this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi)].probablyOwnerIdx = playerIdxi;
      this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi)].x = this->castles[this->players[playerIdxi].castlesOwned[v24]].field_4;
      this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes - playerIdxi)].y = this->castles[this->players[playerIdxi].castlesOwned[v24]].field_5;
      this->castles[this->players[playerIdxi].castlesOwned[v24]].visitingHeroIdx = *(&this->players[0].heroesOwned[284 * playerIdxi]
                                                                                   + this->players[playerIdxi].numHeroes
                                                                                   - playerIdxi);
      game::SetVisibility(
        this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes
                                                                       - playerIdxi)].x,
        this->heroes[*(&this->players[0].heroesOwned[284 * playerIdxi] + this->players[playerIdxi].numHeroes
                                                                       - playerIdxi)].y,
        playerIdxi,
        giVisRange[this->heroes[this->players[playerIdxi].heroesOwned[0]].secondarySkillLevel[3]]);
      ++this->players[playerIdxi].numHeroes;
    }
  }
  for ( playerIdxj = 0; this->numPlayers > playerIdxj; ++playerIdxj )
  {
    if ( playerIdxj || !gbInCampaign || !this->_1[122] && !this->_1[127] )
      goto LABEL_195;
    v20 = this->_1[122] ? 2 : 5;
    for ( k = 0; k < 54 && (this->heroes[k].factionID != v20 || this->relatedToHeroForHireStatus[k] != -1); ++k )
      ;
    if ( k < 54 )
    {
      if ( this->_1[122] )
      {
        this->heroes[k].experience += 5000;
        hero::CheckLevel(&this->heroes[k]);
        strcpy(this->heroes[k].name, "Sister Eliza");
        this->heroes[k].heroID = 56;
      }
      else
      {
        this->heroes[k].experience += 5000;
        hero::CheckLevel(&this->heroes[k]);
        strcpy(this->heroes[k].name, "Brother Brax");
        this->heroes[k].heroID = 59;
      }
      this->players[0].heroesForPurchase[0] = k;
      this->relatedToHeroForHireStatus[this->players[0].heroesForPurchase[0]] = 64;
      faction = this->heroes[k].factionID;
    }
    else
    {
LABEL_195:
      if ( !xIsPlayingExpansionCampaign || playerIdxj )
        goto LABEL_196;
      v21 = -1;
      if ( ExpCampaign::HasAward(&xCampaign, 6) )
      {
        v21 = 4;
        v18 = ExpCampaign::JosephName((int)&xCampaign);
        v19 = 64;
      }
      else if ( ExpCampaign::HasAward(&xCampaign, 7) )
      {
        v21 = 1;
        v18 = ExpCampaign::IvanName((int)&xCampaign);
        v19 = 63;
      }
      if ( v21 == -1 )
        goto LABEL_196;
      for ( l = 0; l < 54 && (this->heroes[l].factionID != v21 || this->relatedToHeroForHireStatus[l] != -1); ++l )
        ;
      if ( l >= 54 )
      {
LABEL_196:
        faction = Random(0, 5);
        if ( this->_4[gcColorToSetupPos[this->players[playerIdxj].color]] < 6 )
          faction = this->_4[gcColorToSetupPos[this->players[playerIdxj].color]];
        this->players[playerIdxj].heroesForPurchase[0] = game::GetNewHeroId(this, playerIdxj, faction, 0);
        this->relatedToHeroForHireStatus[this->players[playerIdxj].heroesForPurchase[0]] = 64;
      }
      else
      {
        this->heroes[l].experience = 5000;
        hero::CheckLevel(&this->heroes[l]);
        strcpy(this->heroes[l].name, v18);
        this->heroes[l].heroID = v19;
        this->players[0].heroesForPurchase[0] = l;
        this->relatedToHeroForHireStatus[this->players[0].heroesForPurchase[0]] = 64;
        faction = this->heroes[l].factionID;
      }
    }
    v2 = Random(1, 5);
    this->players[playerIdxj].heroesForPurchase[1] = game::GetNewHeroId(this, playerIdxj, (faction + v2) % 6, 0);
    this->relatedToHeroForHireStatus[this->players[playerIdxj].heroesForPurchase[1]] = 64;
  }
  for ( playerIdxk = 0; this->numPlayers > playerIdxk; ++playerIdxk )
  {
    for ( m = 0; this->players[playerIdxk].numHeroes > m; ++m )
    {
      v3 = this->heroes[this->players[playerIdxk].heroesOwned[m]].x;
      v4 = this->heroes[this->players[playerIdxk].heroesOwned[m]].y;
      this->heroes[this->players[playerIdxk].heroesOwned[m]].occupiedObjType = *(&this->map.tiles[v3].objType
                                                                               + 12 * v4 * this->map.width);
      this->heroes[this->players[playerIdxk].heroesOwned[m]].occupiedObjVal = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[v3].flags + 6 * v4 * this->map.width) >> 8) >> -5);
      *(&this->map.tiles[v3].objType + 12 * v4 * this->map.width) = -86;
      v5 = &this->map.tiles[v4 * this->map.width] + v3;
      v5->flags = v5->flags & 7 | 8 * this->players[playerIdxk].heroesOwned[m];
    }
    if ( this->players[playerIdxk].numHeroes <= 0 )
    {
      if ( this->players[playerIdxk].numCastles > 0 )
        LOBYTE(this->players[playerIdxk].field_45) = this->players[playerIdxk].castlesOwned[0];
    }
    else
    {
      this->players[playerIdxk].curHeroIdx = this->players[playerIdxk].heroesOwned[0];
    }
  }
  playerIdxl = -1;
  v30 = -1;
  v48 = 0;
  v6 = Random(1, 30);
  v7 = Random(1, 20) + v6;
  v54 = Random(1, 20) + v7;
  while ( 1 )
  {
    if ( playerIdxl >= 9 )
    {
      if ( v30 >= 9 )
      {
        if ( MAP_WIDTH - 10 >= playerIdxl )
        {
          if ( MAP_HEIGHT - 10 >= v30 )
          {
            if ( *((_BYTE *)&this->map.tiles[playerIdxl].field_2 + 12 * v30 * this->map.width + 1) == 255 )
            {
              if ( *(&this->map.tiles[playerIdxl].field_7 + 12 * v30 * this->map.width) == 255 )
              {
                if ( giGroundToTerrain[*(&this->map.tiles[v30 * this->map.width].tileType + 6 * playerIdxl)] )
                {
                  if ( iLastMsgNumHumanPlayers != 1 )
                    break;
                  if ( v48 >= 200 )
                    break;
                  v8 = abs(v30 - this->heroes[this->players[0].heroesOwned[0]].y);
                  if ( abs(playerIdxl - this->heroes[this->players[0].heroesOwned[0]].x) + v8 > v54 )
                    break;
                }
              }
            }
          }
        }
      }
    }
    if ( v48 >= 400 || giUABaseX <= 0 )
    {
      playerIdxl = Random(9, MAP_WIDTH - 10);
      v30 = Random(9, MAP_HEIGHT - 10);
    }
    else
    {
      if ( giUARadius )
        v16 = Random(-giUARadius, giUARadius);
      else
        v16 = 0;
      playerIdxl = v16 + giUABaseX;
      if ( giUARadius )
        v15 = Random(-giUARadius, giUARadius);
      else
        v15 = 0;
      v30 = v15 + giUABaseY;
    }
    v9 = Random(1, 30);
    v10 = Random(1, 20) + v9;
    v54 = Random(1, 20) + v10;
    ++v48;
  }
  this->_10[24] = playerIdxl;
  this->_10[25] = v30;
  this->_10[26] = Random(0, 7);
  if ( gbInCampaign && (!this->field_2 && this->field_4 == 7 || this->field_2 == 1 && this->field_4 == 8) )
    this->_10[26] = 6;
  for ( playerIdxm = 0; this->numPlayers > playerIdxm; ++playerIdxm )
  {
    if ( gbHumanPlayer[playerIdxm] )
    {
      this->players[playerIdxm].personality = 3;
      memcpy(this->players[playerIdxm].resources, (char *)&unk_4F1E00 + 28 * this->difficulty, 0x1Cu);
      if ( this->playerHandicap[playerIdxm] )
      {
        for ( n = 0; n < 7; ++n )
        {
          if ( this->playerHandicap[playerIdxm] == 1 )
            v14 = 0.85;
          else
            v14 = 0.7;
          this->players[playerIdxm].resources[n] = (signed __int64)((double)this->players[playerIdxm].resources[n] * v14);
        }
      }
    }
    else
    {
      this->players[playerIdxm].personality = Random(0, 2);
      memcpy(this->players[playerIdxm].resources, (char *)&unk_4F1E90 + 28 * this->difficulty, 0x1Cu);
    }
  }
  game::SetupAdjacentMons();
  if ( this->_2[0] == 2 )
  {
    v49 = *(_WORD *)&this->_2[1];
    v11 = *(_WORD *)&this->_3[1];
    *(_WORD *)&this->_2[1] = 0;
    if ( *(&this->map.tiles[v49].objType + 12 * v11 * this->map.width) == 170 )
    {
      *(_WORD *)&this->_2[1] = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[v49].flags
                                                                   + 6 * v11 * this->map.width) >> 8) >> -5);
    }
    else if ( *(&this->map.tiles[v49].objType + 12 * (v11 - 1) * this->map.width) == 170 )
    {
      *(_WORD *)&this->_2[1] = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[v49].flags
                                                                   + 6 * (v11 - 1) * this->map.width) >> 8) >> -5);
    }
    else
    {
      this->_2[0] = 0;
    }
  }
  if ( this->winConditionType == 2 )
  {
    v50 = this->winConditionArgument;
    v12 = *(_WORD *)&this->field_2D5;
    this->winConditionArgument = 0;
    if ( *(&this->map.tiles[v50].objType + 12 * v12 * this->map.width) == 170 )
    {
      this->winConditionArgument = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[v50].flags
                                                                       + 6 * v12 * this->map.width) >> 8) >> -5);
    }
    else if ( *(&this->map.tiles[v50].objType + 12 * (v12 - 1) * this->map.width) == 170 )
    {
      this->winConditionArgument = (unsigned __int8)((unsigned __int8)(*(&this->map.tiles[v50].flags
                                                                       + 6 * (v12 - 1) * this->map.width) >> 8) >> -5);
    }
    else
    {
      this->winConditionType = 0;
    }
  }
  for ( playerIdxn = 0; this->numPlayers > playerIdxn; ++playerIdxn )
  {
    v17 = 0;
    if ( this->_4[gcColorToSetupPos[this->players[playerIdxn].color]] < 0
      || this->_4[gcColorToSetupPos[this->players[playerIdxn].color]] >= 6 )
    {
      if ( this->players[playerIdxn].numCastles )
      {
        v17 = gpGame->castles[this->players[playerIdxn].castlesOwned[0]].factionID;
      }
      else if ( this->players[playerIdxn].numHeroes )
      {
        v17 = gpGame->heroes[this->players[playerIdxn].heroesOwned[0]].factionID;
      }
    }
    else
    {
      v17 = this->_4[gcColorToSetupPos[this->players[playerIdxn].color]];
    }
    this->players[playerIdxn]._4[0] = v17 == 1 || v17 == 3 || v17 == 5;
    if ( gbInCampaign && !playerIdxn )
      this->players[0]._4[0] = this->field_2 == 1;
    for ( ii = 0; gpGame->players[playerIdxn].numCastles > ii; ++ii )
      town::GiveSpells(&gpGame->castles[gpGame->players[playerIdxn].castlesOwned[ii]], 0);
    gpGame->players[playerIdxn]._2 = gpGame->players[playerIdxn].numHeroes;
  }
  philAI::GetGameAIVars(gpPhilAI);
  gbInNewGameSetup = 0;
  game::SetupNewRumour(this);
  advManager::CheckSetEvilInterface(gpAdvManager, 0, -1);
}