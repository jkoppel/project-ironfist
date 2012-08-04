{
  int v3; // eax@34
  townManager *thisa; // [sp+Ch] [bp-13Ch]@1
  iconWidget *v5; // [sp+10h] [bp-138h]@136
  iconWidget *this; // [sp+14h] [bp-134h]@127
  iconWidget *v7; // [sp+18h] [bp-130h]@113
  int evt; // [sp+20h] [bp-128h]@25
  int v9; // [sp+24h] [bp-124h]@25
  int v10; // [sp+28h] [bp-120h]@27
  char *v11; // [sp+38h] [bp-110h]@27
  char v12; // [sp+3Ch] [bp-10Ch]@70
  int v13; // [sp+104h] [bp-44h]@41
  int v14; // [sp+108h] [bp-40h]@109
  __int16 v15; // [sp+10Ch] [bp-3Ch]@1
  __int16 v16; // [sp+110h] [bp-38h]@1
  int i; // [sp+114h] [bp-34h]@1
  char v18; // [sp+118h] [bp-30h]@28
  int v19; // [sp+128h] [bp-20h]@108
  int j; // [sp+12Ch] [bp-1Ch]@109
  widget *guiObj; // [sp+130h] [bp-18h]@114
  int v22; // [sp+134h] [bp-14h]@108
  int k; // [sp+138h] [bp-10h]@111
  int v24; // [sp+13Ch] [bp-Ch]@108
  int v25; // [sp+140h] [bp-8h]@108
  unsigned int v26; // [sp+144h] [bp-4h]@59

  thisa = ecx0;
  casWin = window;
  v16 = 11;
  v15 = 12;
  for ( i = 0; i < 18; ++i )
  {
    castleSlotsUse[i] = castleSlotsBase[i];
    if ( (signed int)(unsigned __int8)castleSlotsBase[i] >= 20
      && (signed int)(unsigned __int8)castleSlotsBase[i] <= 24
      && ((1 << castleSlotsBase[i]) & ecx0->castle->buildingsBuiltFlags
       || (1 << (castleSlotsBase[i] + 5)) & ecx0->castle->buildingsBuiltFlags
       || (unsigned __int8)castleSlotsBase[i] == 24
       && ecx0->castle->factionID == 3
       && BYTE3(ecx0->castle->buildingsBuiltFlags) & 0x40)
      && (1 << (castleSlotsBase[i] + 5)) & gTownEligibleBuildMask[ecx0->castle->factionID] )
    {
      if ( (unsigned __int8)castleSlotsBase[i] == 24
        && ecx0->castle->factionID == 3
        && (BYTE3(ecx0->castle->buildingsBuiltFlags) & 0x20 || BYTE3(ecx0->castle->buildingsBuiltFlags) & 0x40) )
        castleSlotsUse[i] = 30;
      else
        castleSlotsUse[i] = castleSlotsBase[i] + 5;
    }
  }
  ecx0->field_156 = 0;
  ecx0->field_152 = ecx0->field_156;
  for ( i = 0; i < 18; ++i )
  {
    if ( CanBuy((int)&thisa->castle->idx, (unsigned __int8)castleSlotsUse[i]) )
      thisa->field_152 |= 1 << castleSlotsUse[i];
    if ( CanBuild((unsigned int *)thisa->castle, (unsigned __int8)castleSlotsUse[i]) )
      thisa->field_156 |= 1 << castleSlotsUse[i];
  }
  evt = 512;
  v9 = 4;
  for ( i = 0; i < 18; ++i )
  {
    v10 = i + 700;
    v11 = (char *)(unsigned __int8)castleSlotsUse[i];
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  v9 = 9;
  sprintf(&v18, "cstl%s.icn", cHeroTypeShortName[thisa->castle->factionID]);
  v11 = &v18;
  for ( i = 0; i < 18; ++i )
  {
    v10 = i + 700;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  v9 = 3;
  for ( i = 0; i < 18; ++i )
  {
    v10 = i + 600;
    if ( castleSlotsUse[i] )
    {
      v11 = GetBuildingName(thisa->castle->factionID, (unsigned __int8)castleSlotsUse[i]);
    }
    else
    {
      v3 = thisa->castle->mageGuildLevel + 1;
      if ( v3 >= 5 )
        v3 = 5;
      sprintf(gText, "Mage Guild, Level %d", v3);
      v11 = gText;
    }
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  for ( i = 0; i < 18; ++i )
  {
    v13 = -1;
    if ( (1 << castleSlotsUse[i]) & thisa->castle->buildingsBuiltFlags
      && (castleSlotsUse[i] || thisa->castle->mageGuildLevel == 5) )
    {
      v13 = 11;
    }
    else if ( (1 << castleSlotsUse[i]) & thisa->field_156 )
    {
      if ( !((1 << castleSlotsUse[i]) & thisa->field_152) )
        v13 = 13;
    }
    else
    {
      v13 = 12;
    }
    if ( v13 == -1 )
    {
      v9 = 6;
      v11 = (char *)4;
      v10 = i + 800;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    }
    else
    {
      v9 = 5;
      v10 = i + 800;
      v11 = (char *)4;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
      v9 = 4;
      v11 = (char *)v13;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    }
    if ( v13 == 11 )
    {
      v9 = 6;
      v11 = (char *)4;
      v10 = i + 400;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    }
    else
    {
      v9 = 5;
      v11 = (char *)4;
      v10 = i + 400;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
      v9 = 4;
      if ( v13 == -1 )
        v11 = (char *)1;
      else
        v11 = (char *)2;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    }
  }
  v26 = thisa->castle->buildingsBuiltFlags & 0x8000;
  if ( v26 )
    v9 = 6;
  else
    v9 = 5;
  v10 = 1101;
  v11 = (char *)6;
  heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  v9 = 4;
  v10 = 1100;
  v11 = (char *)(v26 != 0);
  heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  sprintf(gText, "CSTLCAP%c.ICN", cHeroTypeInitial[thisa->castle->factionID]);
  v9 = 9;
  v10 = 1100;
  v11 = gText;
  heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  if ( v26 )
    v9 = 5;
  else
    v9 = 6;
  v10 = 1106;
  v11 = (char *)4;
  heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  if ( v26 )
  {
    v9 = 4;
    v10 = 1106;
    v11 = (char *)gpCurPlayer->color;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  v13 = -1;
  if ( v26 )
  {
    v9 = 3;
    v11 = gText;
    sprintf(gText, byte_4EDCF0);
    for ( i = 0; i < 4; ++i )
    {
      sprintf(&v12, "%s\n", gStatNames[i]);
      strcat(gText, &v12);
    }
    v10 = 1104;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    sprintf(gText, byte_4EDCF8);
    for ( i = 0; i < 4; ++i )
    {
      sprintf(&v12, "%d\n", *(&captainStats[4 * thisa->castle->factionID] + i));
      strcat(gText, &v12);
    }
    v10 = 1105;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    if ( thisa->castle->_2[0] )
      v9 = 6;
    else
      v9 = 5;
    v10 = 213;
    v11 = (char *)4;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    if ( thisa->castle->_2[0] )
      v9 = 5;
    else
      v9 = 6;
    v10 = 215;
    v11 = (char *)4;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  else
  {
    if ( CanBuild((unsigned int *)thisa->castle, 15) )
    {
      if ( !CanBuy((int)&thisa->castle->idx, 15) )
        v13 = 13;
    }
    else
    {
      v13 = 12;
    }
    if ( CanBuild((unsigned int *)thisa->castle, 15) )
      thisa->field_156 |= 0x8000u;
    if ( CanBuy((int)&thisa->castle->idx, 15) )
      thisa->field_152 |= 0x8000u;
  }
  if ( v13 == -1 )
    v9 = 6;
  else
    v9 = 5;
  v10 = 1102;
  v11 = (char *)4;
  heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  if ( v13 != -1 )
  {
    v9 = 4;
    v11 = (char *)v13;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  if ( gpCurPlayer->resources[6] >= gHeroGoldCost )
  {
    if ( gpCurPlayer->numHeroes != 8 && thisa->castle->visitingHeroIdx == -1 )
    {
      if ( thisa->field_14E )
        v13 = 11;
      else
        v13 = -1;
    }
    else
    {
      v13 = 12;
    }
  }
  else
  {
    v13 = 13;
  }
  for ( i = 0; i < 2; ++i )
  {
    v11 = (char *)4;
    v10 = i + 902;
    if ( v13 == -1 )
    {
      v9 = 6;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    }
    else
    {
      v9 = 5;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
      v9 = 4;
      v11 = (char *)v13;
      heroWindow::BroadcastMessage(casWin, (Event *)&evt);
    }
    v9 = 9;
    sprintf(&v18, "port%04d.icn", gpGame->heroes[gpCurPlayer->heroesForPurchase[i]].heroID);
    v11 = &v18;
    v10 = i + 900;
    heroWindow::BroadcastMessage(casWin, (Event *)&evt);
  }
  v25 = 458;
  v24 = 0;
  v22 = 2
      * (5
       * (unsigned __int8)giGroundToTerrain[*(&gpGame->map.tiles[thisa->castle->field_4].tileType
                                            + 6 * gpGame->map.width * thisa->castle->field_5)]
       - 5);
  v19 = 32 * thisa->castle->factionID;
  if ( !a3 )
  {
    v14 = 0;
    for ( j = 5; j <= 6; ++j )
    {
      for ( k = 4; k <= 8; ++k )
      {
        v7 = (iconWidget *)operator new(45);
        if ( v7 )
          guiObj = (widget *)iconWidget::iconWidget(
                               v7,
                               32 * (k - 4) + 458,
                               32 * (j - 2),
                               32,
                               32,
                               "objntwba.icn",
                               v14 + v22,
                               0,
                               -1,
                               16,
                               1);
        else
          guiObj = 0;
        if ( !guiObj )
          MemError();
        heroWindow::AddWidget(casWin, guiObj, -1);
        ++v14;
      }
    }
    v14 = 0;
    for ( j = 2; j <= 5; ++j )
    {
      for ( k = 4; k <= 8; ++k )
      {
        if ( j != 2 || k == 6 )
        {
          this = (iconWidget *)operator new(45);
          if ( this )
            guiObj = (widget *)iconWidget::iconWidget(
                                 this,
                                 32 * (k - 4) + 458,
                                 32 * (j - 2),
                                 32,
                                 32,
                                 "objntown.icn",
                                 v14 + v19,
                                 0,
                                 -1,
                                 16,
                                 1);
          else
            guiObj = 0;
          if ( !guiObj )
            MemError();
          heroWindow::AddWidget(casWin, guiObj, -1);
          ++v14;
        }
      }
    }
    if ( !xIsExpansionMap && thisa->castle->factionID == 5 )
    {
      v5 = (iconWidget *)operator new(45);
      if ( v5 )
        guiObj = (widget *)iconWidget::iconWidget(v5, 149, 157, 137, 72, "caslxtra.icn", 0, 0, -1, 16, 1);
      else
        guiObj = 0;
      if ( !guiObj )
        MemError();
      heroWindow::AddWidget(casWin, guiObj, -1);
    }
  }
}