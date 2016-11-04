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
  Hero *this; // [sp+B0h] [bp-120h]@140
  Hero *v18; // [sp+B4h] [bp-11Ch]@125
  Hero *v19; // [sp+B8h] [bp-118h]@119
  int v20; // [sp+BCh] [bp-114h]@101
  int goldAmt; // [sp+C0h] [bp-110h]@101
  Castle *v22; // [sp+C4h] [bp-10Ch]@96
  Castle *v23; // [sp+C8h] [bp-108h]@84
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
  Player *player; // [sp+1C4h] [bp-Ch]@8
  int v37; // [sp+1C8h] [bp-8h]@33
  int v38; // [sp+1CCh] [bp-4h]@41

  a2a = a2;
  a1a = a1;
  if ( dword_523ED4 && !dword_523F1C && !dword_4EF268 && !dword_50D2C0 )
  {
    dword_50D2C0 = 1;
    v33 = dword_4F7494;
    v27 = 0;
    for ( i = 0; gameObject->numPlayers > i; ++i )
    {
      if ( !gameObject->couldBePlayerAlive[i] )
      {
        player = &gameObject->players[i];
        if ( (gameObject->players[i].numHeroes || player->numCastles)
          && (!byte_5304A0 || !sub_4729F0((int)&unk_530450, i)) )
        {
          if ( player->numCastles )
          {
            player->field_43 = -1;
          }
          else
          {
            if ( player->field_43 == -1 )
            {
              if ( *(&byte_524758 + i) && i == curPlayerIdx )
              {
                sprintf(
                  globBuf,
                  "%s, you have lost your last town.  If you do not conquer another town in the next week, you will be eliminated.",
                  &dword_5235E0[21 * i]);
                display_message_window(globBuf, 1, -1, -1, 9, gameObject->players[(char)i].color, -1, 0, -1, 0);
              }
              player->field_43 = 7;
            }
            else
            {
              if ( !player->field_43 )
              {
                sub_432EB0(i);
                if ( *(&byte_524758 + i) && i == curPlayerIdx )
                {
                  if ( !v27 )
                  {
                    v27 = 1;
                    sprintf(
                      globBuf,
                      "%s, your heroes abandon you, and you are banished from this land.",
                      &dword_5235E0[21 * i]);
                  }
                }
                else
                {
                  sprintf(
                    globBuf,
                    "%s's heroes have abandoned him, and he is banished from this land.",
                    &dword_5235E0[21 * i]);
                }
                display_message_window(globBuf, 1, -1, -1, 9, gameObject->players[(char)i].color, -1, 0, -1, 0);
              }
            }
          }
        }
        else
        {
          sub_432EB0(i);
          if ( i == dword_524730 )
          {
            v27 = 1;
            sprintf(globBuf, "You have been eliminated from the game!!!");
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          else
          {
            sprintf(globBuf, "%s has been vanquished!", &dword_5235E0[21 * i]);
            display_message_window(globBuf, 1, -1, -1, 9, gameObject->players[(char)i].color, -1, -1, -1, 5000);
          }
        }
      }
    }
    v29 = 0;
    v32 = 0;
    v35 = 0;
    v26 = 0;
    v37 = 0;
    for ( i = 0; gameObject->numPlayers > i; ++i )
    {
      if ( !gameObject->couldBePlayerAlive[i] )
      {
        ++v29;
        v32 = i;
        if ( *(&byte_524758 + i) )
          ++v37;
        if ( dword_524810[i] )
        {
          ++v35;
          v26 = i;
        }
      }
    }
    v30 = 0;
    v38 = 0;
    v34 = 1;
    if ( gameObject->winConditionType && !gameObject->field_2C8
      || loadOrNewGameSelected && gameObject->field_2 == 1 && gameObject->field_4 == 6 )
      v34 = 0;
    if ( gameObject->winConditionType == 4
      && gameObject->winConditionArgument != 99
      && (!loadOrNewGameSelected || gameObject->field_2 != 1 || gameObject->field_4 != 6) )
    {
      v24 = 0;
      v25 = 0;
      for ( i = 0; gameObject->numPlayers > i; ++i )
      {
        if ( !gameObject->couldBePlayerAlive[i] )
        {
          if ( gameObject->players[i].color >= (signed int)*(_WORD *)&gameObject->_3[3] )
            ++v25;
          else
            ++v24;
        }
      }
      if ( v24 )
      {
        if ( !v25 )
        {
          for ( i = 0; gameObject->numPlayers > i; ++i )
          {
            if ( *(&byte_524758 + i)
              && !gameObject->couldBePlayerAlive[i]
              && gameObject->players[i].color < (signed int)*(_WORD *)&gameObject->_3[3] )
              v30 = 1;
          }
        }
      }
      else
      {
        for ( i = 0; gameObject->numPlayers > i; ++i )
        {
          if ( *(&byte_524758 + i)
            && !gameObject->couldBePlayerAlive[i]
            && gameObject->players[i].color >= (signed int)*(_WORD *)&gameObject->_3[3] )
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
          sprintf(globBuf, "The enemy is beaten.  Your side has triumphed!");
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gameObject->winConditionType == 1 )
    {
      v2 = sub_419C90(gameObject, gameObject->winConditionArgument, *(_WORD *)&gameObject->field_2D5);
      v23 = &gameObject->castles[v2];
      if ( gameObject->castles[v2].ownerIdx != -1 )
      {
        if ( dword_524810[v23->ownerIdx] || gameObject->field_2C7 )
        {
          if ( *(&byte_524758 + v23->ownerIdx) )
            v30 = 1;
          else
            v38 = 1;
          if ( !v27 )
          {
            v27 = 1;
            if ( v30 )
              sprintf(globBuf, "You captured %s!  You are victorious.", v23->name);
            else
              sprintf(globBuf, "The enemy has captured %s!  They are triumphant.", v23->name);
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
      }
    }
    if ( gameObject->_2[0] == 1 )
    {
      v3 = sub_419C90(gameObject, *(_WORD *)&gameObject->_2[1], *(_WORD *)&gameObject->_3[1]);
      v22 = &gameObject->castles[v3];
      if ( gameObject->castles[v3].ownerIdx == -1 || !dword_524810[v22->ownerIdx] )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(globBuf, "%s has fallen!  All is lost.", v22->name);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gameObject->winConditionType == 5 )
    {
      goldAmt = 0;
      v20 = -1;
      for ( i = 0; gameObject->numPlayers > i; ++i )
      {
        if ( (dword_524810[i] || gameObject->field_2C7)
          && gameObject->players[i].resources[6] >= 1000 * gameObject->winConditionArgument
          && gameObject->players[i].resources[6] >= goldAmt )
        {
          goldAmt = gameObject->players[i].resources[6];
          v20 = i;
        }
        if ( v20 != -1 )
        {
          if ( *(&byte_524758 + v20) )
            v30 = 1;
          else
            v38 = 1;
          if ( !v27 )
          {
            v27 = 1;
            if ( v30 )
              sprintf(
                globBuf,
                "You have built up over %d gold in your treasury.  All enemies bow before your wealth and power.",
                goldAmt);
            else
              sprintf(
                globBuf,
                "The enemy has built up over %d gold in his treasury.  You must bow done in defeat before his wealth and power.",
                goldAmt);
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
      }
    }
    if ( gameObject->winConditionType == 2 )
    {
      v4 = gameObject->winConditionArgument;
      v19 = &gameObject->heroes[v4];
      if ( gameObject->heroes[v4].probablyOwnerIdx < 0
        || v19->probablyOwnerIdx >= 6
        || dword_524810[v19->probablyOwnerIdx] )
      {
        v30 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(globBuf, "You have captured the enemy hero %s!  Your quest is complete.", v19->name);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gameObject->_2[0] == 2 )
    {
      v5 = *(_WORD *)&gameObject->_2[1];
      v18 = &gameObject->heroes[v5];
      if ( gameObject->heroes[v5].probablyOwnerIdx < 0
        || v18->probablyOwnerIdx >= 6
        || !dword_524810[v18->probablyOwnerIdx] )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(globBuf, "You have lost the hero %s.  Your quest is over.", v18->name);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gameObject->_2[0] == 3 )
    {
      if ( gameObject->day + 7 * (gameObject->week - 1) + 28 * (gameObject->month - 1) > *(_WORD *)&gameObject->_2[1] )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(globBuf, "You have failed to complete your quest in time.  All is lost.");
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( gameObject->winConditionType == 3 )
    {
      v16 = -1;
      for ( i = 0; gameObject->numPlayers > i; ++i )
      {
        if ( !gameObject->couldBePlayerAlive[i] )
        {
          for ( j = 0; gameObject->players[i].numHeroes > j; ++j )
          {
            this = &gameObject->heroes[gameObject->players[i].heroesOwned[j]];
            if ( gameObject->winConditionArgument <= 0 )
            {
              if ( Hero::hasArtifact(this, 0)
                || Hero::hasArtifact(this, ARTIFACT_ULTIMATE_SWORD_OF_DOMINION)
                || Hero::hasArtifact(this, ARTIFACT_ULTIMATE_CLOAK_OF_PROTECTION)
                || Hero::hasArtifact(this, ARTIFACT_ULTIMATE_WAND_OF_MAGIC)
                || Hero::hasArtifact(this, ARTIFACT_ULTIMATE_SHIELD)
                || Hero::hasArtifact(this, ARTIFACT_ULTIMATE_STAFF)
                || Hero::hasArtifact(this, ARTIFACT_ULTIMATE_CROWN)
                || Hero::hasArtifact(this, ARTIFACT_GOLDEN_GOOSE) )
                v16 = i;
            }
            else
            {
              if ( Hero::hasArtifact(this, (ARTIFACT)(gameObject->winConditionArgument - 1)) )
                v16 = i;
            }
          }
        }
      }
      if ( v16 != -1 )
      {
        if ( *(&byte_524758 + v16) )
          v30 = 1;
        else
          v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          if ( gameObject->winConditionArgument )
            sprintf(&v15, unk_4F55F4[gameObject->winConditionArgument]);
          else
            sprintf(&v15, "Ultimate Artifact");
          if ( v30 )
            sprintf(globBuf, "You have found the %s.  Your quest is complete.", &v15);
          else
            sprintf(globBuf, "The enemy has found the %s.  Your quest is a failure.", &v15);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( loadOrNewGameSelected && !gameObject->field_2 && gameObject->field_4 == 2 )
    {
      hasDwarfTown = 0;
      for ( i = 0; gameObject->players[0].numCastles > i; ++i )
      {
        if ( gameObject->castles[gameObject->players[0].castlesOwned[i]].factionID == FACTION_SORCERESS )
          hasDwarfTown = 1;
      }
      if ( !hasDwarfTown )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(globBuf, "All the dwarf towns have fallen.  This is a disastrous defeat!  You have lost.");
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( loadOrNewGameSelected )
    {
      if ( gameObject->field_2 == 1 )
      {
        if ( gameObject->field_4 == 6 )
        {
          if ( a2a )
          {
            v30 = 1;
            if ( !v27 )
            {
              v27 = 1;
              sprintf(globBuf, "Dragon city has fallen!  You are now the Master of the Dragons.");
              display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            }
          }
        }
      }
    }
    if ( loadOrNewGameSelected && !gameObject->field_2 && gameObject->field_4 == 8 )
    {
      v13 = 0;
      for ( i = 0; i < 54; ++i )
      {
        if ( gameObject->heroes[i].heroID == 54
          && gameObject->heroes[i].probablyOwnerIdx >= 0
          && gameObject->heroes[i].probablyOwnerIdx <= 5 )
          v13 = 1;
      }
      if ( !v13 )
      {
        v38 = 1;
        if ( !v27 )
        {
          v27 = 1;
          sprintf(globBuf, "Roland has been captured!  All is lost.");
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
    }
    if ( loadOrNewGameSelected && !gameObject->field_2 && gameObject->field_4 == 8 )
    {
      v12 = 0;
      for ( i = 0; gameObject->numPlayers > i; ++i )
      {
        if ( !gameObject->couldBePlayerAlive[i] && gameObject->players[i].color && gameObject->players[i].color != 3 )
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
            sprintf(globBuf, "The enemy is beaten.  Your side has triumphed!");
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          }
        }
      }
    }
    if ( v38 )
    {
      dword_4EF268 = 1;
      dword_522FF8 = 0;
    }
    if ( v30 )
    {
      dword_4EF268 = 1;
      dword_522FF8 = 1;
    }
    if ( v29 == 1 || !v35 || v35 == 1 && !*(&byte_524758 + v26) )
    {
      if ( v35 == 1 && *(&byte_524758 + v26) )
      {
        if ( v34 )
        {
          dword_4EF268 = 1;
          dword_522FF8 = 1;
        }
      }
      else
      {
        dword_4EF268 = 1;
        dword_522FF8 = 0;
      }
    }
    if ( v33 && !v37 )
    {
      dword_4EF268 = 1;
      dword_522FF8 = 0;
    }
    if ( a1a == 1 )
    {
      v30 = 1;
      dword_4EF268 = 1;
      dword_522FF8 = 1;
    }
    if ( a1a == 2 )
    {
      v38 = 1;
      dword_4EF268 = 1;
      dword_522FF8 = 0;
    }
    if ( dword_522FF8 == 1 && dword_4EF268 )
      v30 = 1;
    if ( !dword_522FF8 && dword_4EF268 )
      v38 = 1;
    if ( loadOrNewGameSelected && v30 )
    {
      v11 = gameObject->day + 7 * (gameObject->week - 1) + 28 * (gameObject->month - 1);
      gameObject->_1[203] = 1;
      *(&gameObject->_1[12 * gameObject->field_2] + gameObject->field_4) = 1;
      *((_WORD *)&gameObject->_1[24 * gameObject->field_2 + 72] + gameObject->field_4) = v11;
      *(_WORD *)&gameObject->_1[181] = *((_WORD *)&gameObject->_1[24 * gameObject->field_2 + 24] + gameObject->field_4)
                                     + *((_WORD *)&gameObject->_1[24 * gameObject->field_2 + 72] + gameObject->field_4);
      v10 = -1;
      if ( !gameObject->field_2 && gameObject->field_4 == 6 )
        v10 = 99;
      if ( gameObject->field_2 == 1 && gameObject->field_4 == 9 )
        v10 = 99;
      if ( v10 != -1 )
      {
        for ( i = 0; i < 5; ++i )
        {
          *(_WORD *)&gameObject->_1[2 * i + 183] = -1;
          *(_WORD *)&gameObject->_1[2 * i + 193] = 0;
        }
        for ( k = 0;
              gameObject->players[0].numHeroes > k
           && v10 != 99
           && gameObject->heroes[gameObject->players[0].heroesOwned[k]].heroID != v10;
              ++k )
          ;
        if ( gameObject->players[0].numHeroes == k )
        {
          *(_WORD *)&gameObject->_1[183] = 0;
          *(_WORD *)&gameObject->_1[193] = 1;
        }
        else
        {
          for ( i = 0; i < 5; ++i )
          {
            *(_WORD *)&gameObject->_1[2 * i + 183] = gameObject->heroes[gameObject->players[0].heroesOwned[k]].army.creatureTypes[i];
            *(_WORD *)&gameObject->_1[2 * i + 193] = gameObject->heroes[gameObject->players[0].heroesOwned[k]].army.quantities[i];
          }
        }
      }
      if ( gameObject->field_4 != 10 && (gameObject->field_4 != 9 || gameObject->field_2) )
      {
        sprintf(&a2b, "%s%c_%02d", "WIN_", (unsigned int)gameObject->field_2 < 1 ? 71 : 69, gameObject->field_4 + 1);
        GameInfo::saveGame(gameObject, &a2b, 1, 0);
      }
    }
    else
    {
      if ( byte_5304A0 && v30 )
        sub_4727B0((signed int)&unk_530450);
    }
    dword_50D2C0 = 0;
  }
}
