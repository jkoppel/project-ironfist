{
  char v5; // al@28
  char v6; // al@29
  int v7; // ebx@36
  int v8; // ST04_4@36
  int v9; // ebx@36
  ICNHeader *v10; // eax@36
  int v11; // ebx@62
  int v12; // ST04_4@62
  ICNHeader *v13; // eax@62
  char *v14; // eax@66
  int v15; // ebx@78
  int v16; // ST04_4@78
  ICNHeader *v17; // eax@78
  char *v18; // eax@82
  textWidget *v20; // [sp+1Ch] [bp-E0h]@82
  iconWidget *v21; // [sp+20h] [bp-DCh]@77
  textWidget *v22; // [sp+24h] [bp-D8h]@66
  iconWidget *v23; // [sp+28h] [bp-D4h]@61
  textWidget *v24; // [sp+2Ch] [bp-D0h]@40
  iconWidget *thisa; // [sp+30h] [bp-CCh]@35
  heroWindow *v26; // [sp+34h] [bp-C8h]@13
  heroWindow *v27; // [sp+38h] [bp-C4h]@7
  PRIMARY_SKILL v28; // [sp+3Ch] [bp-C0h]@50
  signed int v29; // [sp+40h] [bp-BCh]@49
  int v30; // [sp+40h] [bp-BCh]@73
  int v31; // [sp+44h] [bp-B8h]@73
  int a4a; // [sp+48h] [bp-B4h]@57
  int a4b; // [sp+48h] [bp-B4h]@73
  signed int v34; // [sp+4Ch] [bp-B0h]@50
  int imgIdx; // [sp+50h] [bp-ACh]@61
  int imgIdxa; // [sp+50h] [bp-ACh]@77
  int v37; // [sp+54h] [bp-A8h]@57
  int v38; // [sp+58h] [bp-A4h]@30
  int a7; // [sp+5Ch] [bp-A0h]@34
  int v40; // [sp+60h] [bp-9Ch]@30
  tag_message evt; // [sp+6Ch] [bp-90h]@1
  __int16 v42; // [sp+88h] [bp-74h]@1
  icon *res; // [sp+8Ch] [bp-70h]@2
  __int16 v44; // [sp+90h] [bp-6Ch]@1
  __int16 v45; // [sp+94h] [bp-68h]@1
  __int16 v46; // [sp+98h] [bp-64h]@1
  __int16 v47; // [sp+9Ch] [bp-60h]@1
  char content[20]; // [sp+A0h] [bp-5Ch]@40
  PRIMARY_SKILL skill; // [sp+B4h] [bp-48h]@18
  int v50; // [sp+B8h] [bp-44h]@88
  int v51; // [sp+BCh] [bp-40h]@88
  __int16 v52; // [sp+C0h] [bp-3Ch]@1
  heroWindow *window; // [sp+C4h] [bp-38h]@8
  hero *v54; // [sp+C8h] [bp-34h]@2
  int guiObj[5]; // [sp+CCh] [bp-30h]@36
  PRIMARY_SKILL v56; // [sp+E0h] [bp-1Ch]@18
  __int16 v57; // [sp+E4h] [bp-18h]@1
  int v58[5]; // [sp+E8h] [bp-14h]@41

  v46 = 22;
  v45 = 124;
  v44 = 32;
  v57 = 32;
  v47 = 1;
  v42 = 2;
  v52 = 8;
  evt.eventCode = 512;
  if ( a2 == -1 )
    return;
  res = resourceManager::GetIcon(gpResourceManager, "mons32.icn");
  v54 = &gpGame->heroes[a2];
  if ( gpGame->heroes[a2].probablyOwnerIdx == giCurPlayer
    || *(_DWORD *)((char *)this + 886) == 1
    || advManager::IsCrystalBallInEffect(v54->x, v54->y, 8) )
  {
    if ( a4 == -1 )
    {
      a4 = 288;
      a5 = 30 * a3 + 97;
    }
    v27 = (heroWindow *)operator new(68);
    if ( v27 )
      window = heroWindow::heroWindow(v27, a4, a5, "qhero0.bin");
    else
      window = 0;
    if ( !window )
      MemError();
    SetWinText(window, 18);
  }
  else
  {
    v26 = (heroWindow *)operator new(68);
    if ( v26 )
      window = heroWindow::heroWindow(v26, a4, a5, "qhero1.bin");
    else
      window = 0;
    if ( !window )
      MemError();
  }
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 2;
  evt.payload = (void *)v54->heroID;
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 8;
  evt.payload = (void *)(2 * gpGame->players[v54->probablyOwnerIdx].color);
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  ++evt.yCoord;
  ++evt.payload;
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  sprintf(gText, "%s", v54->name);
  evt.xCoordOrKeycode = 3;
  evt.yCoord = 1;
  evt.payload = gText;
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  v56 = 0;
  for ( skill = 0; (signed int)skill < 5; ++skill )
  {
    if ( v54->army.creatureTypes[skill] != -1 )
      ++v56;
  }
  if ( v54->probablyOwnerIdx == giCurPlayer
    || *(_DWORD *)((char *)this + 886) == 1
    || advManager::IsCrystalBallInEffect(v54->x, v54->y, 8) )
  {
    for ( skill = 0; (signed int)skill < 4; ++skill )
    {
      v5 = hero::Stats(v54, skill);
      sprintf(gText, "%d", v5);
      evt.yCoord = skill + 3;
      evt.payload = gText;
      heroWindow::BroadcastMessage(window, (Event *)&evt);
    }
    v6 = hero::Stats(v54, PRIMARY_SKILL_KNOWLEDGE);
    sprintf(gText, "%d/%d", v54->spellpoints, 10 * v6);
    evt.yCoord = 7;
    evt.payload = gText;
    heroWindow::BroadcastMessage(window, (Event *)&evt);
    if ( v56 )
    {
      v38 = (160 - 32 * v56) / 2 + 22;
      v40 = 0;
      for ( skill = 0; v56 > skill; ++skill )
      {
        while ( v54->army.creatureTypes[v40] == -1 )
          ++v40;
        a7 = v54->army.creatureTypes[v40];
        if ( a7 != -1 )
        {
          thisa = (iconWidget *)operator new(45);
          if ( thisa )
          {
            v7 = 124 - GetIconEntry(res, a7)->offsetY;
            v8 = v7 - GetIconEntry(res, a7)->height + 30;
            v9 = v38 + 32 * skill - GetIconEntry(res, a7)->offsetX;
            v10 = GetIconEntry(res, a7);
            guiObj[skill] = (int)iconWidget::iconWidget(
                                   thisa,
                                   (32 - v10->width) / 2 + (_WORD)v9 + 1,
                                   v8,
                                   32,
                                   32,
                                   "mons32.icn",
                                   a7,
                                   0,
                                   -1,
                                   16,
                                   1);
          }
          else
          {
            guiObj[skill] = 0;
          }
          if ( !guiObj[skill] )
            MemError();
          *(_DWORD *)&content[4 * skill] = BaseAlloc(5u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F600 + 155);
          sprintf(*(char **)&content[4 * skill], "%d", v54->army.quantities[v40]);
          v24 = (textWidget *)operator new(43);
          if ( v24 )
            v58[skill] = (int)textWidget::textWidget(
                                v24,
                                v38 + 32 * skill,
                                156,
                                32,
                                12,
                                *(char **)&content[4 * skill],
                                "smalfont.fnt",
                                1,
                                -1,
                                512,
                                1);
          else
            v58[skill] = 0;
          if ( !v58[skill] )
            MemError();
          heroWindow::AddWidget(window, (widget *)guiObj[skill], -1);
          heroWindow::AddWidget(window, (widget *)v58[skill], -1);
        }
        ++v40;
      }
    }
    goto LABEL_88;
  }
  if ( v56 )
  {
    v29 = 73;
    if ( (signed int)v56 < 1 )
      goto LABEL_52;
    if ( (signed int)v56 <= 3 )
    {
      v29 = 95;
      v28 = v56;
      v34 = 0;
    }
    else
    {
      if ( v56 != 4 )
      {
LABEL_52:
        v28 = 2;
        v34 = 3;
        goto LABEL_57;
      }
      v28 = 2;
      v34 = 2;
    }
LABEL_57:
    v37 = 0;
    a4a = 160 / v28;
    for ( skill = 0; v28 > skill; ++skill )
    {
      while ( v54->army.creatureTypes[v37] == -1 )
        ++v37;
      imgIdx = v54->army.creatureTypes[v37];
      v23 = (iconWidget *)operator new(45);
      if ( v23 )
      {
        v11 = v29 - GetIconEntry(res, imgIdx)->offsetY;
        v12 = v11 - GetIconEntry(res, imgIdx)->height + 30;
        LOWORD(v11) = (160 / v28 - 32) / 2 + 22 + a4a * (_WORD)skill - GetIconEntry(res, imgIdx)->offsetX;
        v13 = GetIconEntry(res, imgIdx);
        guiObj[skill] = (int)iconWidget::iconWidget(
                               v23,
                               (32 - v13->width) / 2 + (_WORD)v11 + 1,
                               v12,
                               32,
                               32,
                               "mons32.icn",
                               imgIdx,
                               0,
                               -1,
                               16,
                               1);
      }
      else
      {
        guiObj[skill] = 0;
      }
      if ( !guiObj[skill] )
        MemError();
      *(_DWORD *)&content[4 * skill] = BaseAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F600 + 227);
      v14 = advManager::GetArmySizeName(v54->army.quantities[v37], 0);
      strcpy(*(char **)&content[4 * skill], v14);
      v22 = (textWidget *)operator new(43);
      if ( v22 )
        v58[skill] = (int)textWidget::textWidget(
                            v22,
                            a4a * (_WORD)skill + 22,
                            v29 + 32,
                            a4a,
                            12,
                            *(char **)&content[4 * skill],
                            "smalfont.fnt",
                            1,
                            -1,
                            512,
                            1);
      else
        v58[skill] = 0;
      if ( !v58[skill] )
        MemError();
      heroWindow::AddWidget(window, (widget *)guiObj[skill], -1);
      heroWindow::AddWidget(window, (widget *)v58[skill], -1);
      ++v37;
    }
    if ( v34 )
    {
      a4b = 160 / v34;
      v31 = (160 / v34 - 32) / 2 + 22;
      v30 = v29 + 44;
      for ( skill = v28; v34 + v28 > skill; ++skill )
      {
        while ( v54->army.creatureTypes[v37] == -1 )
          ++v37;
        imgIdxa = v54->army.creatureTypes[v37];
        v21 = (iconWidget *)operator new(45);
        if ( v21 )
        {
          v15 = v30 - GetIconEntry(res, imgIdxa)->offsetY;
          v16 = v15 - GetIconEntry(res, imgIdxa)->height + 36;
          LOWORD(v15) = (_WORD)v31 + (_WORD)a4b * (skill - 2) - GetIconEntry(res, imgIdxa)->offsetX;
          v17 = GetIconEntry(res, imgIdxa);
          guiObj[skill] = (int)iconWidget::iconWidget(
                                 v21,
                                 (32 - v17->width) / 2 + (_WORD)v15 + 1,
                                 v16,
                                 32,
                                 32,
                                 "mons32.icn",
                                 imgIdxa,
                                 0,
                                 -1,
                                 16,
                                 1);
        }
        else
        {
          guiObj[skill] = 0;
        }
        if ( !guiObj[skill] )
          MemError();
        *(_DWORD *)&content[4 * skill] = BaseAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F600 + 270);
        v18 = advManager::GetArmySizeName(v54->army.quantities[v37], 0);
        strcpy(*(char **)&content[4 * skill], v18);
        v20 = (textWidget *)operator new(43);
        if ( v20 )
          v58[skill] = (int)textWidget::textWidget(
                              v20,
                              (_WORD)a4b * (skill - 2) + 22,
                              v30 + 38,
                              a4b,
                              12,
                              *(char **)&content[4 * skill],
                              "smalfont.fnt",
                              1,
                              -1,
                              512,
                              1);
        else
          v58[skill] = 0;
        if ( !v58[skill] )
          MemError();
        heroWindow::AddWidget(window, (widget *)guiObj[skill], -1);
        heroWindow::AddWidget(window, (widget *)v58[skill], -1);
        ++v37;
      }
    }
  }
LABEL_88:
  v51 = *(_DWORD *)((char *)this + 470);
  v50 = *(_DWORD *)((char *)this + 474);
  *(_DWORD *)((char *)this + 470) = v54->x - 7;
  *(_DWORD *)((char *)this + 474) = v54->y - 7;
  advManager::UpdateRadar((int)this, 1, 0);
  heroWindowManager::AddWindow(gpWindowManager, window, -1, 1);
  QuickViewWait();
  heroWindowManager::RemoveWindow(gpWindowManager, window);
  operator delete(window);
  *(_DWORD *)((char *)this + 470) = v51;
  *(_DWORD *)((char *)this + 474) = v50;
  advManager::UpdateRadar((int)this, 1, 0);
  advManager::CompleteDraw((advManager *)this, 0);
  advManager::UpdateScreen((advManager *)this, 0, 0);
  if ( evt.eventCode == 8 && v54->probablyOwnerIdx == giCurPlayer )
    advManager::SetHeroContext((advManager *)this, v54->couldBeHeroIdx, 0);
  resourceManager::Dispose(gpResourceManager, (resource *)res);
}