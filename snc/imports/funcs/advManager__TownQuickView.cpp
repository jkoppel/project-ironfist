{
  const char *v5; // eax@24
  __int16 v6; // ST14_2@57
  int v7; // ebx@57
  int v8; // ST04_4@57
  int v9; // ebx@57
  ICNHeader *v10; // eax@57
  char *v11; // eax@64
  __int16 v12; // ST14_2@78
  int v13; // ebx@78
  int v14; // ST04_4@78
  int v15; // ebx@78
  ICNHeader *v16; // eax@78
  char *v17; // eax@85
  int v18; // [sp+10h] [bp-E8h]@1
  textWidget *v19; // [sp+1Ch] [bp-DCh]@87
  iconWidget *v20; // [sp+20h] [bp-D8h]@77
  textWidget *v21; // [sp+24h] [bp-D4h]@66
  iconWidget *thisa; // [sp+28h] [bp-D0h]@56
  textWidget *v23; // [sp+2Ch] [bp-CCh]@34
  heroWindow *v24; // [sp+30h] [bp-C8h]@4
  signed int v25; // [sp+34h] [bp-C4h]@41
  signed int v26; // [sp+38h] [bp-C0h]@40
  int v27; // [sp+38h] [bp-C0h]@73
  int v28; // [sp+3Ch] [bp-BCh]@48
  int v29; // [sp+40h] [bp-B8h]@48
  int v30; // [sp+40h] [bp-B8h]@73
  signed int v31; // [sp+44h] [bp-B4h]@48
  char a1[20]; // [sp+4Ch] [bp-ACh]@61
  int v33; // [sp+60h] [bp-98h]@48
  int v34; // [sp+64h] [bp-94h]@41
  int a7; // [sp+68h] [bp-90h]@56
  int v36[5]; // [sp+6Ch] [bp-8Ch]@57
  int v37; // [sp+80h] [bp-78h]@48
  int v38[5]; // [sp+84h] [bp-74h]@67
  char *content; // [sp+98h] [bp-60h]@31
  widget *guiObj; // [sp+9Ch] [bp-5Ch]@35
  __int16 v41; // [sp+A0h] [bp-58h]@1
  __int16 v42; // [sp+A4h] [bp-54h]@1
  tag_message evt; // [sp+A8h] [bp-50h]@16
  icon *res; // [sp+C4h] [bp-34h]@2
  __int16 v45; // [sp+C8h] [bp-30h]@1
  __int16 v46; // [sp+CCh] [bp-2Ch]@1
  int i; // [sp+D0h] [bp-28h]@24
  int v48; // [sp+D4h] [bp-24h]@93
  int v49; // [sp+D8h] [bp-20h]@93
  int v50; // [sp+DCh] [bp-1Ch]@11
  __int16 v51; // [sp+E0h] [bp-18h]@1
  heroWindow *window; // [sp+E4h] [bp-14h]@5
  town *v53; // [sp+E8h] [bp-10h]@2
  int v54; // [sp+ECh] [bp-Ch]@16
  __int16 v55; // [sp+F0h] [bp-8h]@1
  __int16 v56; // [sp+F4h] [bp-4h]@1

  v18 = (int)this;
  v41 = 192;
  v46 = 22;
  v45 = 32;
  v55 = 32;
  v56 = 1;
  v42 = 2;
  v51 = 8;
  if ( a2 == -1 )
    return;
  res = resourceManager::GetIcon(gpResourceManager, "mons32.icn");
  v53 = &gpGame->castles[a2];
  if ( a4 == -1 )
  {
    a4 = 328;
    a5 = 176;
  }
  v24 = (heroWindow *)operator new(68);
  if ( v24 )
    window = heroWindow::heroWindow(v24, a4, a5, "qtown1.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  if ( v53->ownerIdx != giCurPlayer && giDebugLevel < 2 )
  {
    v50 = game::getNumberOfThievesGuilds(gpGame, giCurPlayer);
    if ( v50 > 2 )
      v50 = 2;
  }
  else
  {
    v50 = 3;
  }
  if ( advManager::IsCrystalBallInEffect(v53->field_4, v53->field_5, 8) )
    v50 = 3;
  SetWinText(window, 19);
  v54 = 0;
  evt.eventCode = 512;
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 2;
  evt.payload = (void *)(v53->factionID + 9);
  if ( !(gpGame->castles[a2].buildingsBuiltFlags & 0x40) )
    evt.payload = (char *)evt.payload + 6;
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  if ( v50 != 3 || !BitTest(&gpGame->_7[72], v53->idx) )
  {
    evt.xCoordOrKeycode = 6;
    evt.yCoord = 300;
    evt.payload = (void *)4;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  if ( v53->ownerIdx == -1 )
  {
    evt.xCoordOrKeycode = 6;
    evt.yCoord = 8;
    evt.payload = (void *)4;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    ++evt.yCoord;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  else
  {
    evt.xCoordOrKeycode = 4;
    evt.yCoord = 8;
    evt.payload = (void *)(2 * gpGame->players[v53->ownerIdx].color);
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    ++evt.yCoord;
    ++evt.payload;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
  }
  v5 = GetTownName(v53->idx);
  sprintf(gText, v5);
  evt.xCoordOrKeycode = 3;
  evt.yCoord = 1;
  evt.payload = gText;
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  v54 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( v53->garrison.creatureTypes[i] != -1 )
      ++v54;
  }
  if ( v50 && v54 )
  {
    v26 = 76;
    if ( v54 < 1 )
      goto LABEL_43;
    if ( v54 <= 3 )
    {
      v26 = 98;
      v25 = v54;
      v34 = 0;
    }
    else
    {
      if ( v54 != 4 )
      {
LABEL_43:
        v25 = 2;
        v34 = 3;
        goto LABEL_48;
      }
      v25 = 2;
      v34 = 2;
    }
LABEL_48:
    v37 = 0;
    v28 = 0;
    v33 = 192 / v25;
    v29 = (192 / v25 - 32) / 2 + 22;
    v31 = 0;
    for ( i = 0; i < v25; ++i )
    {
      if ( v54 == 5 )
      {
        if ( i )
          v31 = -12;
        else
          v31 = 12;
      }
      while ( v53->garrison.creatureTypes[v28] == -1 )
        ++v28;
      a7 = v53->garrison.creatureTypes[v28];
      thisa = (iconWidget *)operator new(45);
      if ( thisa )
      {
        v6 = a7;
        v7 = v26 - GetIconEntry(res, a7)->offsetY;
        v8 = v7 - GetIconEntry(res, a7)->height + 30;
        v9 = v31 + v29 + v33 * v37 - GetIconEntry(res, a7)->offsetX;
        v10 = GetIconEntry(res, a7);
        v36[v37] = (int)iconWidget::iconWidget(
                          thisa,
                          (32 - v10->width) / 2 + (_WORD)v9 + 1,
                          v8,
                          32,
                          32,
                          "mons32.icn",
                          v6,
                          0,
                          -1,
                          16,
                          1);
      }
      else
      {
        v36[v37] = 0;
      }
      if ( !v36[v37] )
        MemError();
      *(_DWORD *)&a1[4 * v37] = BaseAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F6E8 + 214);
      if ( v50 == 3 )
      {
        sprintf(*(char **)&a1[4 * v37], "%d", v53->garrison.quantities[v28]);
      }
      else if ( v50 == 2 )
      {
        v11 = advManager::GetArmySizeName(v53->garrison.quantities[v28], 0);
        strcpy(*(char **)&a1[4 * v37], v11);
      }
      else
      {
        strcpy(*(char **)&a1[4 * v37], "???");
      }
      v21 = (textWidget *)operator new(43);
      if ( v21 )
        v38[v37] = (int)textWidget::textWidget(
                          v21,
                          (_WORD)v31 + (_WORD)v29 + v33 * (_WORD)v37 - 14,
                          v26 + 32,
                          60,
                          12,
                          *(char **)&a1[4 * v37],
                          "smalfont.fnt",
                          1,
                          -1,
                          512,
                          1);
      else
        v38[v37] = 0;
      if ( !v38[v37] )
        MemError();
      heroWindow::AddWidget(window, (widget *)v36[v37], -1);
      heroWindow::AddWidget(window, (widget *)v38[v37++], -1);
      ++v28;
    }
    if ( v34 )
    {
      v33 = 192 / v34;
      v30 = (192 / v34 - 32) / 2 + 22;
      v27 = v26 + 44;
      for ( i = v25; v34 + v25 > i; ++i )
      {
        while ( v53->garrison.creatureTypes[v28] == -1 )
          ++v28;
        a7 = v53->garrison.creatureTypes[v28];
        v20 = (iconWidget *)operator new(45);
        if ( v20 )
        {
          v12 = a7;
          v13 = v27 - GetIconEntry(res, a7)->offsetY;
          v14 = v13 - GetIconEntry(res, a7)->height + 30;
          v15 = v30 + v33 * (v37 - v25) - GetIconEntry(res, a7)->offsetX;
          v16 = GetIconEntry(res, a7);
          v36[v37] = (int)iconWidget::iconWidget(
                            v20,
                            (32 - v16->width) / 2 + (_WORD)v15 + 1,
                            v14,
                            32,
                            32,
                            "mons32.icn",
                            v12,
                            0,
                            -1,
                            16,
                            1);
        }
        else
        {
          v36[v37] = 0;
        }
        if ( !v36[v37] )
          MemError();
        *(_DWORD *)&a1[4 * v37] = BaseAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F6E8 + 264);
        if ( v50 == 3 )
        {
          sprintf(*(char **)&a1[4 * v37], "%d", v53->garrison.quantities[v28]);
        }
        else if ( v50 == 2 )
        {
          v17 = advManager::GetArmySizeName(v53->garrison.quantities[v28], 0);
          strcpy(*(char **)&a1[4 * v37], v17);
        }
        else
        {
          strcpy(*(char **)&a1[4 * v37], "???");
        }
        v19 = (textWidget *)operator new(43);
        if ( v19 )
          v38[v37] = (int)textWidget::textWidget(
                            v19,
                            (_WORD)v30 + (_WORD)v33 * (v37 - (_WORD)v25) - 14,
                            v27 + 32,
                            60,
                            12,
                            *(char **)&a1[4 * v37],
                            "smalfont.fnt",
                            1,
                            -1,
                            512,
                            1);
        else
          v38[v37] = 0;
        if ( !v38[v37] )
          MemError();
        heroWindow::AddWidget(window, (widget *)v36[v37], -1);
        heroWindow::AddWidget(window, (widget *)v38[v37++], -1);
        ++v28;
      }
    }
    goto LABEL_93;
  }
  content = (char *)BaseAlloc(0x14u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F6E8 + 131);
  if ( v50 )
    sprintf(content, "None");
  else
    sprintf(content, "Unknown");
  v23 = (textWidget *)operator new(43);
  if ( v23 )
    guiObj = (widget *)textWidget::textWidget(v23, 13, 117, 211, 12, content, "smalfont.fnt", 1, -1, 512, 1);
  else
    guiObj = 0;
  if ( !guiObj )
    MemError();
  heroWindow::AddWidget(window, guiObj, -1);
LABEL_93:
  heroWindowManager::AddWindow(gpWindowManager, window, -1, 1);
  v49 = *(_DWORD *)(v18 + 470);
  v48 = *(_DWORD *)(v18 + 474);
  *(_DWORD *)(v18 + 470) = v53->field_4 - 7;
  *(_DWORD *)(v18 + 474) = v53->field_5 - 7;
  advManager::UpdateRadar(v18, 1, 0);
  QuickViewWait();
  heroWindowManager::RemoveWindow(gpWindowManager, window);
  operator delete(window);
  *(_DWORD *)(v18 + 470) = v49;
  *(_DWORD *)(v18 + 474) = v48;
  advManager::UpdateRadar(v18, 1, 0);
  advManager::CompleteDraw((advManager *)v18, 0);
  advManager::UpdateScreen((advManager *)v18, 0, 0);
  if ( evt.eventCode == 8 && v53->ownerIdx == giCurPlayer )
    advManager::SetTownContext((advManager *)v18, v53->idx);
  resourceManager::Dispose(gpResourceManager, (resource *)res);
}