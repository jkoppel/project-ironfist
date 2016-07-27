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
  TextWidget *v19; // [sp+1Ch] [bp-DCh]@87
  GUIIcon *v20; // [sp+20h] [bp-D8h]@77
  TextWidget *v21; // [sp+24h] [bp-D4h]@66
  GUIIcon *thisa; // [sp+28h] [bp-D0h]@56
  TextWidget *v23; // [sp+2Ch] [bp-CCh]@34
  GUIWindow *v24; // [sp+30h] [bp-C8h]@4
  signed int v25; // [sp+34h] [bp-C4h]@41
  signed int v26; // [sp+38h] [bp-C0h]@40
  int v27; // [sp+38h] [bp-C0h]@73
  int v28; // [sp+3Ch] [bp-BCh]@48
  int v29; // [sp+40h] [bp-B8h]@48
  int v30; // [sp+40h] [bp-B8h]@73
  signed int v31; // [sp+44h] [bp-B4h]@48
  char v32[20]; // [sp+4Ch] [bp-ACh]@61
  int v33; // [sp+60h] [bp-98h]@48
  int v34; // [sp+64h] [bp-94h]@41
  int a7; // [sp+68h] [bp-90h]@56
  int v36[5]; // [sp+6Ch] [bp-8Ch]@57
  int v37; // [sp+80h] [bp-78h]@48
  int v38[5]; // [sp+84h] [bp-74h]@67
  char *content; // [sp+98h] [bp-60h]@31
  AbstractGUIComponent *guiObj; // [sp+9Ch] [bp-5Ch]@35
  __int16 v41; // [sp+A0h] [bp-58h]@1
  __int16 v42; // [sp+A4h] [bp-54h]@1
  InputEvent evt; // [sp+A8h] [bp-50h]@16
  Icon *res; // [sp+C4h] [bp-34h]@2
  __int16 v45; // [sp+C8h] [bp-30h]@1
  __int16 v46; // [sp+CCh] [bp-2Ch]@1
  int i; // [sp+D0h] [bp-28h]@24
  int v48; // [sp+D4h] [bp-24h]@93
  int v49; // [sp+D8h] [bp-20h]@93
  int v50; // [sp+DCh] [bp-1Ch]@11
  __int16 v51; // [sp+E0h] [bp-18h]@1
  GUIWindow *window; // [sp+E4h] [bp-14h]@5
  Castle *v53; // [sp+E8h] [bp-10h]@2
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
  res = ResourceManager::getIconByFilename(resourceManager, "mons32.icn");
  v53 = &gameObject->castles[a2];
  if ( a4 == -1 )
  {
    a4 = 328;
    a5 = 176;
  }
  v24 = (GUIWindow *)operator new(0x44u);
  if ( v24 )
    window = GUIWindow_constructorFromFile(v24, a4, a5, "qtown1.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  if ( v53->ownerIdx != curPlayerIdx && debugLogLevel < 2 )
  {
    v50 = GameInfo::getNumberOfThievesGuilds(gameObject, curPlayerIdx);
    if ( v50 > 2 )
      v50 = 2;
  }
  else
  {
    v50 = 3;
  }
  if ( sub_458C60(v53->field_4, v53->field_5, 8) )
    v50 = 3;
  setOptionsScreenTitles(window, 19);
  v54 = 0;
  evt.eventCode = 512;
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 2;
  evt.payload = (void *)(v53->factionID + 9);
  if ( !(gameObject->castles[a2].buildingsBuiltFlags & 0x40) )
    evt.payload = (char *)evt.payload + 6;
  GUIWindow::processMessage(window, (Event *)&evt);
  if ( v50 != 3 || !sub_4D05D8((int)&gameObject->_7[72], v53->idx) )
  {
    evt.xCoordOrKeycode = 6;
    evt.yCoord = 300;
    evt.payload = (void *)4;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
  if ( v53->ownerIdx == -1 )
  {
    evt.xCoordOrKeycode = 6;
    evt.yCoord = 8;
    evt.payload = (void *)4;
    GUIWindow::processMessage(window, (Event *)&evt);
    ++evt.yCoord;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
  else
  {
    evt.xCoordOrKeycode = 4;
    evt.yCoord = 8;
    evt.payload = (void *)(2 * gameObject->players[v53->ownerIdx].color);
    GUIWindow::processMessage(window, (Event *)&evt);
    ++evt.yCoord;
    ++evt.payload;
    GUIWindow::processMessage(window, (Event *)&evt);
  }
  v5 = getCastleName(v53->idx);
  sprintf(globBuf, v5);
  evt.xCoordOrKeycode = 3;
  evt.yCoord = 1;
  evt.payload = globBuf;
  GUIWindow::processMessage(window, (Event *)&evt);
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
      thisa = (GUIIcon *)operator new(0x2Du);
      if ( thisa )
      {
        v6 = a7;
        v7 = v26 - getNthHeader(res, a7)->offsetY;
        v8 = v7 - getNthHeader(res, a7)->height + 30;
        v9 = v31 + v29 + v33 * v37 - getNthHeader(res, a7)->offsetX;
        v10 = getNthHeader(res, a7);
        v36[v37] = (int)GUIIcon_constructor(
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
        fatalOutOfMemoryError();
      *(_DWORD *)&v32[4 * v37] = KBAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F6E8 + 214);
      if ( v50 == 3 )
      {
        sprintf(*(char **)&v32[4 * v37], "%d", v53->garrison.quantities[v28]);
      }
      else
      {
        if ( v50 == 2 )
        {
          v11 = sub_44F960(v53->garrison.quantities[v28], 0);
          strcpy(*(char **)&v32[4 * v37], v11);
        }
        else
        {
          strcpy(*(char **)&v32[4 * v37], "???");
        }
      }
      v21 = (TextWidget *)operator new(0x2Bu);
      if ( v21 )
        v38[v37] = (int)TextWidget_constructor(
                          v21,
                          (_WORD)v31 + (_WORD)v29 + v33 * (_WORD)v37 - 14,
                          v26 + 32,
                          60,
                          12,
                          *(char **)&v32[4 * v37],
                          "smalfont.fnt",
                          1,
                          -1,
                          512,
                          1);
      else
        v38[v37] = 0;
      if ( !v38[v37] )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(window, (AbstractGUIComponent *)v36[v37], -1);
      GUIWindow::insertElement(window, (AbstractGUIComponent *)v38[v37++], -1);
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
        v20 = (GUIIcon *)operator new(0x2Du);
        if ( v20 )
        {
          v12 = a7;
          v13 = v27 - getNthHeader(res, a7)->offsetY;
          v14 = v13 - getNthHeader(res, a7)->height + 30;
          v15 = v30 + v33 * (v37 - v25) - getNthHeader(res, a7)->offsetX;
          v16 = getNthHeader(res, a7);
          v36[v37] = (int)GUIIcon_constructor(
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
          fatalOutOfMemoryError();
        *(_DWORD *)&v32[4 * v37] = KBAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F6E8 + 264);
        if ( v50 == 3 )
        {
          sprintf(*(char **)&v32[4 * v37], "%d", v53->garrison.quantities[v28]);
        }
        else
        {
          if ( v50 == 2 )
          {
            v17 = sub_44F960(v53->garrison.quantities[v28], 0);
            strcpy(*(char **)&v32[4 * v37], v17);
          }
          else
          {
            strcpy(*(char **)&v32[4 * v37], "???");
          }
        }
        v19 = (TextWidget *)operator new(0x2Bu);
        if ( v19 )
          v38[v37] = (int)TextWidget_constructor(
                            v19,
                            (_WORD)v30 + (_WORD)v33 * (v37 - (_WORD)v25) - 14,
                            v27 + 32,
                            60,
                            12,
                            *(char **)&v32[4 * v37],
                            "smalfont.fnt",
                            1,
                            -1,
                            512,
                            1);
        else
          v38[v37] = 0;
        if ( !v38[v37] )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(window, (AbstractGUIComponent *)v36[v37], -1);
        GUIWindow::insertElement(window, (AbstractGUIComponent *)v38[v37++], -1);
        ++v28;
      }
    }
    goto LABEL_93;
  }
  content = (char *)KBAlloc(0x14u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F6E8 + 131);
  if ( v50 )
    sprintf(content, "None");
  else
    sprintf(content, "Unknown");
  v23 = (TextWidget *)operator new(0x2Bu);
  if ( v23 )
    guiObj = (AbstractGUIComponent *)TextWidget_constructor(
                                       v23,
                                       13,
                                       117,
                                       211,
                                       12,
                                       content,
                                       "smalfont.fnt",
                                       1,
                                       -1,
                                       512,
                                       1);
  else
    guiObj = 0;
  if ( !guiObj )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(window, guiObj, -1);
LABEL_93:
  HeroWindowManager::addWindow(HeroWindowManager::instance, window, -1, 1);
  v49 = *(_DWORD *)(v18 + 470);
  v48 = *(_DWORD *)(v18 + 474);
  *(_DWORD *)(v18 + 470) = v53->field_4 - 7;
  *(_DWORD *)(v18 + 474) = v53->field_5 - 7;
  sub_44AA80(v18, 1, 0);
  waitForMouseRelease();
  HeroWindowManager::removeWindow(HeroWindowManager::instance, window);
  operator delete(window);
  *(_DWORD *)(v18 + 470) = v49;
  *(_DWORD *)(v18 + 474) = v48;
  sub_44AA80(v18, 1, 0);
  sub_448110((AdvManager *)v18, 0);
  sub_447A00((void *)v18, 0, 0);
  if ( evt.eventCode == 8 && v53->ownerIdx == curPlayerIdx )
    sub_4509F0((AdvManager *)v18, v53->idx);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
}
