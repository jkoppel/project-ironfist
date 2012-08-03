{
  char *v1; // ST2C_4@31
  int v3; // [sp+24h] [bp-1Ch]@30
  char *v4; // [sp+28h] [bp-18h]@1
  char *thisa; // [sp+2Ch] [bp-14h]@0
  char *v6; // [sp+30h] [bp-10h]@3
  signed int i; // [sp+38h] [bp-8h]@12
  signed int j; // [sp+38h] [bp-8h]@34
  signed int l; // [sp+38h] [bp-8h]@57
  signed int k; // [sp+3Ch] [bp-4h]@46

  v4 = (char *)&xCampaignChoices
     + 120 * *(_DWORD *)this
     + 15 * *(_DWORD *)(this + 4)
     + 5 * *(_BYTE *)(*(_DWORD *)(this + 4) + this + 55);
  memset(&gpGame->_3[375], 0, 0x41u);
  sprintf(gpGame->_5, "CAMP%d_%02d.HXC", *(_DWORD *)this + 1, *(_DWORD *)(this + 4) + 1);
  gpGame->_5[20] = 0;
  if ( !*(_DWORD *)(this + 4) )
    *(_WORD *)(this + 28) = 0;
  strcpy(gMapName, gpGame->_5);
  GetMapHeader((int)gpGame->_5, &gpGame->_1[676]);
  game::LoadGame(gpGame, "origdata.bin", 1, 0);
  game::InitNewGame((int)gpGame, 0);
  gpGame->difficulty = *(&byte_512C20[8 * *(_DWORD *)this] + *(_DWORD *)(this + 4));
  gpGame->numPlayers = gpGame->_1[702];
  game::NewMap(gpGame, gMapName);
  v6 = (char *)gpGame->players;
  switch ( *v4 )
  {
    case 0:
      *(_DWORD *)&v6[4 * *(_WORD *)(v4 + 1) + 143] += *(_WORD *)(v4 + 3);
      break;
    case 1:
      if ( gpGame->players[0].numHeroes > 0 )
        GiveArtifact(&gpGame->heroes[gpGame->players[0].heroesOwned[0]], (ARTIFACT)*(_WORD *)(v4 + 1), 0, -1);
      break;
    case 2:
      if ( gpGame->players[0].numHeroes > 0 )
        gpGame->heroes[gpGame->players[0].heroesOwned[0]].spellsLearned[*(_WORD *)(v4 + 1)] = 1;
      break;
    case 3:
      if ( gpGame->players[0].numHeroes > 0 )
      {
        for ( i = 0; gpGame->players[0].numHeroes > i; ++i )
        {
          thisa = (char *)&gpGame->heroes[v6[i + 4]];
          if ( *(_DWORD *)this != 3 || *(_DWORD *)(this + 4) != 3 )
          {
            if ( *(_DWORD *)this != 3 || *(_DWORD *)(this + 4) != 2 || gpGame->heroes[v6[i + 4]].heroID == 67 )
              break;
          }
          else if ( gpGame->heroes[v6[i + 4]].heroID == 65 )
          {
            break;
          }
        }
        hero::SetSS((hero *)thisa, *(_WORD *)(v4 + 1), *(_WORD *)(v4 + 3));
      }
      break;
    case 4:
      if ( gpGame->players[0].numHeroes > 0 )
        armyGroup::Add(
          &gpGame->heroes[gpGame->players[0].heroesOwned[0]].army,
          *(_WORD *)(v4 + 1),
          *(_WORD *)(v4 + 3),
          -1);
      break;
    case 5:
      gpGame->players[0]._3[0] = v4[1];
      break;
    case 6:
      v3 = gbInNewGameSetup;
      gbInNewGameSetup = 1;
      if ( gpGame->players[0].numHeroes > 0 )
      {
        v1 = (char *)&gpGame->heroes[gpGame->players[0].heroesOwned[0]];
        *(_DWORD *)(v1 + 57) += *(_WORD *)(v4 + 1);
        hero::CheckLevel(&gpGame->heroes[v6[4]]);
      }
      gbInNewGameSetup = v3;
      break;
    case 9:
      if ( gpGame->players[0].numHeroes > 0 )
      {
        for ( j = 0; ; ++j )
        {
          if ( gpGame->players[0].numHeroes > j )
          {
            thisa = (char *)&gpGame->heroes[v6[j + 4]];
            if ( *(_DWORD *)this == 3 )
            {
              if ( *(_DWORD *)(this + 4) == 2 && gpGame->heroes[v6[j + 4]].heroID != 67 )
                continue;
            }
          }
          break;
        }
        thisa[*(_WORD *)(v4 + 1) + 63] += *(_WORD *)(v4 + 3);
      }
      break;
    case 0xA:
      if ( gpGame->players[0].numHeroes > 0 )
        GiveArtifact(&gpGame->heroes[gpGame->players[0].heroesOwned[0]], ARTIFACT_SPELL_SCROLL, 0, *(_WORD *)(v4 + 1));
      break;
    case 7:
      break;
  }
  for ( k = 0; k < 11; ++k )
  {
    if ( *(_BYTE *)(k + this + 44) )
    {
      switch ( k )
      {
        case 1:
          if ( v6[1] > 0 )
            GiveArtifact(&gpGame->heroes[v6[4]], ARTIFACT_BREASTPLATE_OF_ANDURAN, 0, -1);
          break;
        case 3:
          if ( v6[1] > 0 )
            GiveArtifact(&gpGame->heroes[v6[4]], ARTIFACT_HELMET_OF_ANDURAN, 0, -1);
          break;
        case 4:
          for ( l = 0; l < 54; ++l )
          {
            if ( gpGame->heroes[l].heroID == 61 )
              hero::Deallocate(&gpGame->heroes[l], 0);
          }
          break;
        case 5:
          if ( v6[1] > 0 )
            GiveArtifact(&gpGame->heroes[v6[4]], ARTIFACT_BATTLE_GARB_OF_ANDURAN, 0, -1);
          break;
        case 8:
          if ( v6[1] > 0 )
            GiveArtifact(&gpGame->heroes[v6[4]], ARTIFACT_LEGENDARY_SCEPTER, 0, -1);
          break;
        case 9:
          if ( v6[1] > 0 )
            gpGame->heroes[v6[4]].spellsLearned[61] = 1;
          break;
        case 10:
          if ( v6[1] > 0 )
            GiveArtifact(&gpGame->heroes[v6[4]], ARTIFACT_SPHERE_OF_NEGATION, 0, -1);
          break;
        case 0:
        case 2:
        case 6:
        case 7:
          continue;
      }
    }
  }
  gbRetreatWin = 1;
}