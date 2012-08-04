{
  signed int v2; // ST38_4@84
  signed int v3; // ST34_4@96
  int v4; // ecx@119
  int v5; // ecx@125
  int a2a; // [sp+Ch] [bp-1C4h]@1
  int a1a; // [sp+10h] [bp-1C0h]@1
  char a2b; // [sp+1Ch] [bp-1B4h]@264
  int k; // [sp+30h] [bp-1A0h]@250
  int v10; // [sp+34h] [bp-19Ch]@240
  int v11; // [sp+38h] [bp-198h]@240
  int v12; // [sp+3Ch] [bp-194h]@200
  int v13; // [sp+40h] [bp-190h]@187
  int hasDwarfTown; // [sp+44h] [bp-18Ch]@170
  char v15; // [sp+48h] [bp-188h]@161
  int v16; // [sp+ACh] [bp-124h]@135
  hero *this; // [sp+B0h] [bp-120h]@140
  hero *v18; // [sp+B4h] [bp-11Ch]@125
  hero *v19; // [sp+B8h] [bp-118h]@119
  int v20; // [sp+BCh] [bp-114h]@101
  int goldAmt; // [sp+C0h] [bp-110h]@101
  town *v22; // [sp+C4h] [bp-10Ch]@96
  town *v23; // [sp+C8h] [bp-108h]@84
  int v24; // [sp+CCh] [bp-104h]@52
  int v25; // [sp+D0h] [bp-100h]@52
  int v26; // [sp+D4h] [bp-FCh]@33
  int v27; // [sp+D8h] [bp-F8h]@5
  int j; // [sp+DCh] [bp-F4h]@138
  int v29; // [sp+E0h] [bp-F0h]@33
  int v30; // [sp+E4h] [bp-ECh]@41
  int i; // [sp+1B0h] [bp-20h]@5
  int v32; // [sp+1B4h] [bp-1Ch]@33
  int v33; // [sp+1B8h] [bp-18h]@5
  int v34; // [sp+1BCh] [bp-14h]@41
  int v35; // [sp+1C0h] [bp-10h]@33
  playerData *player; // [sp+1C4h] [bp-Ch]@8
  int v37; // [sp+1C8h] [bp-8h]@33
  int v38; // [sp+1CCh] [bp-4h]@41

  a2a = a2;
  a1a = a1;
  if ( gbThisNetGotAdventureControl && !gbInNewGameSetup && !gbGameOver && !dword_50D2C0 )
  {
    dword_50D2C0 = 1;
    v33 = gbRemoteOn;
    v27 = 0;
    for ( i = 0; gpGame->numPlayers > i; ++i )
    {
      if ( !gpGame->couldBePlayerAlive[i] )
      {
        player = &gpGame->players[i];
        if ( (gpGame->players[i].numHeroes || player->numCastles)
          && (!xIsPlayingExpansionCampaign || !ExpCampaign::IsSpecialLossCondition((int)&xCampaign, i)) )
        {
          if ( player->numCastles )
          {
            player->field_43 = -1;
          }
          else if ( player->field_43 == -1 )
          {
            if ( *(&gbThisNetHumanPlayer + i) && i == giCurPlayer )
            {
              sprintf(
                gText,
                "%s, you have lost your last town.  If you do not conquer another town in the next week, you will be eliminated.",
                &cPlayerNames[21 * i]);
              NormalDialog(gText, 1, -1, -1, 9, gpGame->players[(char)i].color, -1, 0, -1, 0);
            }
            player->field_43 = 7;
          }
          else if ( !player->field_43 )
          {
            PlayerDead(i);
            if ( *(&gbThisNetHumanPlayer + i) && i == giCurPlayer )
            {
              if ( !v27 )
              {
                v27 = 1;
                sprintf(
                  gText,
                  "%s, your heroes abandon you, and you are banished from this land.",
                  &cPlayerNames[21 * i]);
              }
            }
            else
            {
              sprintf(
                gText,
                "%s's heroes have abandoned him, and he is banished from this land.",
                &cPlayerNames[21 * i]);
            }
            NormalDialog(gText, 1, -1, -1, 9, gpGame->players[(char)i].color, -1, 0, -1, 0);
          }
        }
        else
        {
          PlayerDead(i);
          if ( i == giThisGamePos )
          {
            v27 = 1;
            sprintf(gText, "You have been eliminated from the game!!!");
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          else
          {
            sprintf(gText, "%s has been vanquished!", &cPlayerNames[21 * i]);
            NormalDialog(gText, 1, -1, -1, 9, gpGame->players[(char)i].color, -1, -1, -1, 5000);
          }
        }
      }
    }
    v29 = 0;
    v32 = 0;
    v35 = 0;
    v26 = 0;
    v37 = 0;
    for ( i = 0; gpGame->numPlayers > i; ++i )
    {
      if ( !gpGame->couldBePlayerAlive[i] )
      {
        ++v29;
        v32 = i;
        if ( *(&gbThisNetHumanPlayer + i) )
          ++v37;
        if ( gbHumanPlayer[i] )
        {
          ++v35;
          v26 = i;
        }
      }
    }
    v30 = 0;
    v38 = 0;
    v34 = 1;
    if ( gpGame->winConditionType && !gpGame->field_2C8 || gbInCampaign && gpGame->field_2 == 1 && gpGame->field_4 == 6 )
      v34 = 0;
    if ( gpGame->winConditionType == 4
      && gpGame->winConditionArgument != 99
      && (!gbInCampaign || gpGame->field_2 != 1 || gpGame->field_4 != 6) )
    {
      v24 = 0;
      v25 = 0;
      for ( i = 0; gpGame->numPlayers > i; ++i )
      {
        if ( !gpGame->couldBePlayerAlive[i] )
        {
          if ( gpGame->players[i].color >= (signed int)*(_WORD *)&gpGame->_3[3] )
            ++v25;
          else
            ++v24;
        }
      }
      if ( v24 )
      {
        if ( !v25 )
        {
          for ( i = 0; gpGame->numPlayers > i; ++i )
          {
            if ( *(&gbThisNetHumanPlayer + i)
              && !gpGame->couldBePlayerAlive[i]
              && gpGame->players[i].color < (signed int)*(_WORD *)&gpGame->_3[3] )
              v30 = 1;
          }
        }
      }
      else
      {
        for ( i = 0; gpGame->numPlayers > i; ++i )
        {
          if ( *(&gbThisNetHumanPlayer + i)
            && !gpGame->couldBePlayerAlive[i]
            && gpGame->players[i].color >= (signed int)*(_WORD *)&gpGame->_3[3] )
            v30 = 1;
        }
      }
      if ( !v24 || !v25 )
      {
        if ( !v30 )
          v38 = 1;
        if ( !v27 && v30 )
        {
          v27 = 1;
          sprintf(gText, "The enemy is beaten.  Your side has triumphed!");
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gpGame->winConditionType == 1 )
    {
      v2 = game::GetTownId(gpGame, gpGame->winConditionArgument, *(_WORD *)&gpGame->field_2D5);
      v23 = &gpGame->castles[v2];
      if ( gpGame->castles[v2].ownerIdx != -1 )
      {
        if ( gbHumanPlayer[v23->ownerIdx] || gpGame->field_2C7 )
        {
          if ( *(&gbThisNetHumanPlayer + v23->ownerIdx) )
            v30 = 1;
          else
            v38 = 1;
          if ( !v27 )
          {
            v27 = 1;
            if ( v30 )
              sprintf(gText, "You captured %s!  You are victorious.", v23->name);
            else
              sprintf(gText, "The enemy has captured %s!  They are triumphant.", v23->name);
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
      }
    }
    if ( gpGame->_2[0] == 1 )
    {
      v3 = game::GetTownId(gpGame, *(_WORD *)&gpGame->_2[1], *(_WORD *)&gpGame->_3[1]);
      v22 = &gpGame->castles[v3];
      if ( gpGame->castles[v3].ownerIdx == -1 || !gbHumanPlayer[v22->ownerIdx] )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(gText, "%s has fallen!  All is lost.", v22->name);
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gpGame->winConditionType == 5 )
    {
      goldAmt = 0;
      v20 = -1;
      for ( i = 0; gpGame->numPlayers > i; ++i )
      {
        if ( (gbHumanPlayer[i] || gpGame->field_2C7)
          && gpGame->players[i].resources[6] >= 1000 * gpGame->winConditionArgument
          && gpGame->players[i].resources[6] >= goldAmt )
        {
          goldAmt = gpGame->players[i].resources[6];
          v20 = i;
        }
        if ( v20 != -1 )
        {
          if ( *(&gbThisNetHumanPlayer + v20) )
            v30 = 1;
          else
            v38 = 1;
          if ( !v27 )
          {
            v27 = 1;
            if ( v30 )
              sprintf(
                gText,
                "You have built up over %d gold in your treasury.  All enemies bow before your wealth and power.",
                goldAmt);
            else
              sprintf(
                gText,
                "The enemy has built up over %d gold in his treasury.  You must bow done in defeat before his wealth and power.",
                goldAmt);
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
      }
    }
    if ( gpGame->winConditionType == 2 )
    {
      v4 = gpGame->winConditionArgument;
      v19 = &gpGame->heroes[v4];
      if ( gpGame->heroes[v4].probablyOwnerIdx < 0 || v19->probablyOwnerIdx >= 6 || gbHumanPlayer[v19->probablyOwnerIdx] )
      {
        v30 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(gText, "You have captured the enemy hero %s!  Your quest is complete.", v19->name);
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gpGame->_2[0] == 2 )
    {
      v5 = *(_WORD *)&gpGame->_2[1];
      v18 = &gpGame->heroes[v5];
      if ( gpGame->heroes[v5].probablyOwnerIdx < 0
        || v18->probablyOwnerIdx >= 6
        || !gbHumanPlayer[v18->probablyOwnerIdx] )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(gText, "You have lost the hero %s.  Your quest is over.", v18->name);
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gpGame->_2[0] == 3 )
    {
      if ( gpGame->day + 7 * (gpGame->week - 1) + 28 * (gpGame->month - 1) > *(_WORD *)&gpGame->_2[1] )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(gText, "You have failed to complete your quest in time.  All is lost.");
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gpGame->winConditionType == 3 )
    {
      v16 = -1;
      for ( i = 0; gpGame->numPlayers > i; ++i )
      {
        if ( !gpGame->couldBePlayerAlive[i] )
        {
          for ( j = 0; gpGame->players[i].numHeroes > j; ++j )
          {
            this = &gpGame->heroes[gpGame->players[i].heroesOwned[j]];
            if ( gpGame->winConditionArgument <= 0 )
            {
              if ( hero::HasArtifact(this, 0)
                || hero::HasArtifact(this, ARTIFACT_ULTIMATE_SWORD_OF_DOMINION)
                || hero::HasArtifact(this, ARTIFACT_ULTIMATE_CLOAK_OF_PROTECTION)
                || hero::HasArtifact(this, ARTIFACT_ULTIMATE_WAND_OF_MAGIC)
                || hero::HasArtifact(this, ARTIFACT_ULTIMATE_SHIELD)
                || hero::HasArtifact(this, ARTIFACT_ULTIMATE_STAFF)
                || hero::HasArtifact(this, ARTIFACT_ULTIMATE_CROWN)
                || hero::HasArtifact(this, ARTIFACT_GOLDEN_GOOSE) )
                v16 = i;
            }
            else if ( hero::HasArtifact(this, (ARTIFACT)(gpGame->winConditionArgument - 1)) )
            {
              v16 = i;
            }
          }
        }
      }
      if ( v16 != -1 )
      {
        if ( *(&gbThisNetHumanPlayer + v16) )
          v30 = 1;
        else
          v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          if ( gpGame->winConditionArgument )
            sprintf(&v15, dword_4F55F4[gpGame->winConditionArgument]);
          else
            sprintf(&v15, "Ultimate Artifact");
          if ( v30 )
            sprintf(gText, "You have found the %s.  Your quest is complete.", &v15);
          else
            sprintf(gText, "The enemy has found the %s.  Your quest is a failure.", &v15);
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gbInCampaign && !gpGame->field_2 && gpGame->field_4 == 2 )
    {
      hasDwarfTown = 0;
      for ( i = 0; gpGame->players[0].numCastles > i; ++i )
      {
        if ( gpGame->castles[gpGame->players[0].castlesOwned[i]].factionID == FACTION_SORCERESS )
          hasDwarfTown = 1;
      }
      if ( !hasDwarfTown )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(gText, "All the dwarf towns have fallen.  This is a disastrous defeat!  You have lost.");
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gbInCampaign )
    {
      if ( gpGame->field_2 == 1 )
      {
        if ( gpGame->field_4 == 6 )
        {
          if ( a2a )
          {
            v30 = 1;
            if ( !v27 )
            {
              v27 = 1;
              sprintf(gText, "Dragon city has fallen!  You are now the Master of the Dragons.");
              NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
          }
        }
      }
    }
    if ( gbInCampaign && !gpGame->field_2 && gpGame->field_4 == 8 )
    {
      v13 = 0;
      for ( i = 0; i < 54; ++i )
      {
        if ( gpGame->heroes[i].heroID == 54
          && gpGame->heroes[i].probablyOwnerIdx >= 0
          && gpGame->heroes[i].probablyOwnerIdx <= 5 )
          v13 = 1;
      }
      if ( !v13 )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(gText, "Roland has been captured!  All is lost.");
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gbInCampaign && !gpGame->field_2 && gpGame->field_4 == 8 )
    {
      v12 = 0;
      for ( i = 0; gpGame->numPlayers > i; ++i )
      {
        if ( !gpGame->couldBePlayerAlive[i] && gpGame->players[i].color && gpGame->players[i].color != 3 )
          v12 = 1;
      }
      if ( !v12 )
      {
        v30 = 1;
        if ( !v27 )
        {
          if ( v30 )
          {
            v27 = 1;
            sprintf(gText, "The enemy is beaten.  Your side has triumphed!");
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
      }
    }
    if ( v38 )
    {
      gbGameOver = 1;
      giEndSequence = 0;
    }
    if ( v30 )
    {
      gbGameOver = 1;
      giEndSequence = 1;
    }
    if ( v29 == 1 || !v35 || v35 == 1 && !*(&gbThisNetHumanPlayer + v26) )
    {
      if ( v35 == 1 && *(&gbThisNetHumanPlayer + v26) )
      {
        if ( v34 )
        {
          gbGameOver = 1;
          giEndSequence = 1;
        }
      }
      else
      {
        gbGameOver = 1;
        giEndSequence = 0;
      }
    }
    if ( v33 && !v37 )
    {
      gbGameOver = 1;
      giEndSequence = 0;
    }
    if ( a1a == 1 )
    {
      v30 = 1;
      gbGameOver = 1;
      giEndSequence = 1;
    }
    if ( a1a == 2 )
    {
      v38 = 1;
      gbGameOver = 1;
      giEndSequence = 0;
    }
    if ( giEndSequence == 1 && gbGameOver )
      v30 = 1;
    if ( !giEndSequence && gbGameOver )
      v38 = 1;
    if ( gbInCampaign && v30 )
    {
      v11 = gpGame->day + 7 * (gpGame->week - 1) + 28 * (gpGame->month - 1);
      gpGame->_1[203] = 1;
      *(&gpGame->_1[12 * gpGame->field_2] + gpGame->field_4) = 1;
      *((_WORD *)&gpGame->_1[24 * gpGame->field_2 + 72] + gpGame->field_4) = v11;
      *(_WORD *)&gpGame->_1[181] = *((_WORD *)&gpGame->_1[24 * gpGame->field_2 + 24] + gpGame->field_4)
                                 + *((_WORD *)&gpGame->_1[24 * gpGame->field_2 + 72] + gpGame->field_4);
      v10 = -1;
      if ( !gpGame->field_2 && gpGame->field_4 == 6 )
        v10 = 99;
      if ( gpGame->field_2 == 1 && gpGame->field_4 == 9 )
        v10 = 99;
      if ( v10 != -1 )
      {
        for ( i = 0; i < 5; ++i )
        {
          *(_WORD *)&gpGame->_1[2 * i + 183] = -1;
          *(_WORD *)&gpGame->_1[2 * i + 193] = 0;
        }
        for ( k = 0;
              gpGame->players[0].numHeroes > k
           && v10 != 99
           && gpGame->heroes[gpGame->players[0].heroesOwned[k]].heroID != v10;
              ++k )
          ;
        if ( gpGame->players[0].numHeroes == k )
        {
          *(_WORD *)&gpGame->_1[183] = 0;
          *(_WORD *)&gpGame->_1[193] = 1;
        }
        else
        {
          for ( i = 0; i < 5; ++i )
          {
            *(_WORD *)&gpGame->_1[2 * i + 183] = gpGame->heroes[gpGame->players[0].heroesOwned[k]].army.creatureTypes[i];
            *(_WORD *)&gpGame->_1[2 * i + 193] = gpGame->heroes[gpGame->players[0].heroesOwned[k]].army.quantities[i];
          }
        }
      }
      if ( gpGame->field_4 != 10 && (gpGame->field_4 != 9 || gpGame->field_2) )
      {
        sprintf(&a2b, "%s%c_%02d", "WIN_", (unsigned int)gpGame->field_2 < 1 ? 71 : 69, gpGame->field_4 + 1);
        game::SaveGame(gpGame, &a2b, 1, 0);
      }
    }
    else if ( xIsPlayingExpansionCampaign && v30 )
    {
      ExpCampaign::Autosave((signed int)&xCampaign);
    }
    dword_50D2C0 = 0;
  }
}