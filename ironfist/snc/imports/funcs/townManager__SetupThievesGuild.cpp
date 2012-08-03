{
  int result; // eax@38
  int v3; // ST24_4@61
  int v4; // eax@61
  char v5; // al@66
  int v6; // ST24_4@67
  int v7; // eax@67
  int v8; // ST24_4@72
  int v9; // eax@72
  iconWidget *v10; // [sp+10h] [bp-1ACh]@97
  textWidget *v11; // [sp+14h] [bp-1A8h]@72
  textWidget *v12; // [sp+18h] [bp-1A4h]@67
  textWidget *v13; // [sp+1Ch] [bp-1A0h]@61
  iconWidget *v14; // [sp+20h] [bp-19Ch]@53
  iconWidget *v15; // [sp+24h] [bp-198h]@48
  iconWidget *this; // [sp+28h] [bp-194h]@29
  signed int v17; // [sp+2Ch] [bp-190h]@23
  int v18; // [sp+30h] [bp-18Ch]@27
  int v19; // [sp+34h] [bp-188h]@20
  int v20; // [sp+38h] [bp-184h]@20
  char *a1; // [sp+44h] [bp-178h]@61
  char *a1a; // [sp+44h] [bp-178h]@67
  char *a1b; // [sp+44h] [bp-178h]@72
  char v24; // [sp+48h] [bp-174h]@66
  GUIMessage evt; // [sp+110h] [bp-ACh]@14
  __int16 v26; // [sp+12Ch] [bp-90h]@1
  __int16 v27; // [sp+130h] [bp-8Ch]@1
  int k; // [sp+134h] [bp-88h]@78
  char playerIndices[8]; // [sp+138h] [bp-84h]@20
  int row; // [sp+140h] [bp-7Ch]@18
  PRIMARY_SKILL skill; // [sp+144h] [bp-78h]@42
  textWidget *v32; // [sp+148h] [bp-74h]@62
  PRIMARY_SKILL v33; // [sp+14Ch] [bp-70h]@42
  __int16 v34; // [sp+154h] [bp-68h]@1
  int j; // [sp+158h] [bp-64h]@20
  int numRows; // [sp+15Ch] [bp-60h]@4
  __int16 v37; // [sp+160h] [bp-5Ch]@1
  __int16 v38; // [sp+164h] [bp-58h]@1
  int i; // [sp+168h] [bp-54h]@12
  __int16 v40; // [sp+16Ch] [bp-50h]@1
  int v41; // [sp+170h] [bp-4Ch]@76
  hero *hro; // [sp+174h] [bp-48h]@44
  __int16 v43; // [sp+178h] [bp-44h]@1
  int v44; // [sp+17Ch] [bp-40h]@44
  __int16 v45; // [sp+180h] [bp-3Ch]@1
  __int16 v46; // [sp+184h] [bp-38h]@1
  widget *guiObj; // [sp+188h] [bp-34h]@30
  __int16 v48; // [sp+18Ch] [bp-30h]@1
  int a7; // [sp+190h] [bp-2Ch]@76
  __int16 v50; // [sp+194h] [bp-28h]@1
  town *v51; // [sp+198h] [bp-24h]@78
  __int16 v52; // [sp+19Ch] [bp-20h]@1
  int playerStats[6]; // [sp+1A0h] [bp-1Ch]@20
  int v54; // [sp+1B8h] [bp-4h]@42

  v37 = 258;
  v26 = 68;
  v27 = 27;
  v50 = 22;
  v45 = 18;
  v52 = 22;
  v46 = 72;
  v34 = 800;
  v38 = 900;
  v48 = 300;
  v40 = 339;
  v43 = 397;
  if ( strength == -1 )
    strength = game::getNumberOfThievesGuilds(gpGame, giCurPlayer);
  if ( strength < 5 )
  {
    switch ( strength )
    {
      case 4:
        numRows = 9;
        break;
      case 3:
        numRows = 7;
        break;
      case 2:
        numRows = 5;
        break;
      default:
        numRows = 3;
        break;
    }
  }
  else
  {
    numRows = 10;
  }
  for ( i = gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers; i < 6; ++i )
  {
    evt.eventCode = INPUT_GUI_MESSAGE_CODE;
    evt.messageType = 6;
    evt.fieldID = i + 800;
    evt.payload = (void *)4;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    evt.fieldID = i + 900;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  for ( i = gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers; i < 6; ++i )
  {
    evt.eventCode = 512;
    evt.messageType = 6;
    evt.fieldID = i + 900;
    evt.payload = (void *)4;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  for ( row = 0; row < numRows; ++row )
  {
    GetCategoryStats(row, playerStats, playerIndices);
    SortStats(playerStats, playerIndices);
    v20 = 0;
    v19 = 0;
    for ( j = 0; j < 6 && gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers != v20; ++j )
    {
      v17 = 1;
      while ( gpGame->numPlayers > v19 + 1 && playerStats[v19 + 1] == playerStats[v19] )
      {
        ++v17;
        ++v19;
      }
      v18 = 68 * j + 258 - (9 * v17 - 9);
      for ( i = v20; v19 >= i; ++i )
      {
        this = (iconWidget *)operator new(45);
        if ( this )
          guiObj = (widget *)iconWidget::iconWidget(
                               this,
                               v18 + 18 * (i - (_WORD)v20),
                               24 * row + 27,
                               18,
                               22,
                               "townwind.icn",
                               gpGame->players[playerIndices[i]].color + 22,
                               0,
                               -1,
                               16,
                               1);
        else
          guiObj = 0;
        if ( !guiObj )
          MemError();
        heroWindow::AddWidget(window, guiObj, -1);
      }
      ++v19;
      v20 = v19;
    }
  }
  j = 0;
  for ( i = 0; ; ++i )
  {
    result = gpGame->numPlayers - gpGame->couldBeNumDefeatedPlayers;
    if ( result <= i )
      break;
    while ( gpGame->couldBePlayerAlive[j] )
      ++j;
    sprintf(gText, (&gColors)[4 * gpGame->players[j].color]);
    gText[0] -= 32;
    evt.eventCode = 512;
    evt.messageType = 3;
    evt.fieldID = i + 900;
    evt.payload = gText;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    if ( strength >= 1 )
    {
      v33 = -1;
      v54 = 0;
      for ( skill = 0; gpGame->players[j].numHeroes > (signed int)skill; ++skill )
      {
        hro = &gpGame->heroes[gpGame->players[j].heroesOwned[skill]];
        v44 = philAI::FightValueOfStack(&hro->army, hro, 0, 0, 0, 0);
        if ( v44 > v54 )
        {
          v54 = v44;
          v33 = skill;
        }
      }
      if ( v33 != -1 )
      {
        v15 = (iconWidget *)operator new(45);
        if ( v15 )
          guiObj = (widget *)iconWidget::iconWidget(v15, 68 * i + 246, 301, 0, 0, "locators.icn", 22, 0, -1, 16, 1);
        else
          guiObj = 0;
        if ( !guiObj )
          MemError();
        heroWindow::AddWidget(window, guiObj, -1);
        v14 = (iconWidget *)operator new(45);
        if ( v14 )
          guiObj = (widget *)iconWidget::iconWidget(
                               v14,
                               68 * i + 237,
                               300,
                               0,
                               0,
                               "miniport.icn",
                               gpGame->heroes[gpGame->players[j].heroesOwned[v33]].heroID,
                               0,
                               -1,
                               16,
                               1);
        else
          guiObj = 0;
        if ( !guiObj )
          MemError();
        heroWindow::AddWidget(window, guiObj, -1);
      }
      if ( strength >= 2 )
      {
        if ( v33 != -1 )
        {
          hro = &gpGame->heroes[gpGame->players[j].heroesOwned[v33]];
          sprintf(gText, "Att.\nDef.\nPower\nKnowl.");
          v3 = word_4EF178 + 190;
          v4 = strlen((int)gText);
          a1 = (char *)BaseAlloc(v4 + 1, "F:\\h2xsrc\\Source\\TOWNMGR.CPP", v3);
          strcpy(a1, gText);
          v13 = (textWidget *)operator new(43);
          if ( v13 )
            v32 = textWidget::textWidget(v13, 68 * i + 239, 339, 40, 48, a1, "smalfont.fnt", 1, -1, 512, 0);
          else
            v32 = 0;
          heroWindow::AddWidget(window, (widget *)v32, -1);
          sprintf(gText, byte_4EF1F4);
          for ( skill = 0; (signed int)skill < 4; ++skill )
          {
            v5 = hero::Stats(hro, skill);
            sprintf(&v24, "%d\n", v5);
            strcat(gText, &v24);
          }
          v6 = word_4EF178 + 216;
          v7 = strlen((int)gText);
          a1a = (char *)BaseAlloc(v7 + 1, "F:\\h2xsrc\\Source\\TOWNMGR.CPP", v6);
          strcpy(a1a, gText);
          v12 = (textWidget *)operator new(43);
          if ( v12 )
            v32 = textWidget::textWidget(v12, 68 * i + 284, 339, 15, 48, a1a, "smalfont.fnt", 1, -1, 512, 0);
          else
            v32 = 0;
          heroWindow::AddWidget(window, (widget *)v32, -1);
        }
        if ( strength >= 3 )
        {
          strcpy(gText, personality_types[gpGame->players[j].personality]);
          v8 = word_4EF178 + 240;
          v9 = strlen((int)gText);
          a1b = (char *)BaseAlloc(v9 + 1, "F:\\h2xsrc\\Source\\TOWNMGR.CPP", v8);
          strcpy(a1b, gText);
          v11 = (textWidget *)operator new(43);
          v32 = v11 ? textWidget::textWidget(v11, 68 * i + 227, 397, 74, 16, a1b, "smalfont.fnt", 1, -1, 8, 1) : 0;
          heroWindow::AddWidget(window, (widget *)v32, -1);
          if ( strength >= 4 )
          {
            a7 = -1;
            v41 = 0;
            for ( skill = 0; gpGame->players[j].numCastles > (signed int)skill; ++skill )
            {
              v51 = &gpGame->castles[gpGame->players[j].castlesOwned[skill]];
              for ( k = 0; k < 5; ++k )
              {
                if ( v51->garrison.creatureTypes[k] != -1
                  && v51->garrison.quantities[k] > 0
                  && gMonsterDatabase[v51->garrison.creatureTypes[k]].fight_value > v41 )
                {
                  a7 = v51->garrison.creatureTypes[k];
                  v41 = gMonsterDatabase[v51->garrison.creatureTypes[k]].fight_value;
                }
              }
            }
            for ( skill = 0; gpGame->players[j].numHeroes > (signed int)skill; ++skill )
            {
              hro = &gpGame->heroes[gpGame->players[j].heroesOwned[skill]];
              for ( k = 0; k < 5; ++k )
              {
                if ( hro->army.creatureTypes[k] != -1
                  && hro->army.quantities[k] > 0
                  && gMonsterDatabase[hro->army.creatureTypes[k]].fight_value > v41 )
                {
                  a7 = hro->army.creatureTypes[k];
                  v41 = gMonsterDatabase[hro->army.creatureTypes[k]].fight_value;
                }
              }
            }
            if ( a7 != -1 )
            {
              v10 = (iconWidget *)operator new(45);
              if ( v10 )
                guiObj = (widget *)iconWidget::iconWidget(
                                     v10,
                                     68 * i + 244,
                                     418,
                                     40,
                                     34,
                                     "mons32.icn",
                                     a7,
                                     0,
                                     -1,
                                     17,
                                     1);
              else
                guiObj = 0;
              if ( !guiObj )
                MemError();
              heroWindow::AddWidget(window, guiObj, -1);
            }
          }
        }
      }
    }
    ++j;
  }
  return result;
}