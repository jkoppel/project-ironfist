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
  int v19; // [sp+10h] [bp-ECh]@1
  TextWidget *v20; // [sp+1Ch] [bp-E0h]@82
  GUIIcon *v21; // [sp+20h] [bp-DCh]@77
  TextWidget *v22; // [sp+24h] [bp-D8h]@66
  GUIIcon *v23; // [sp+28h] [bp-D4h]@61
  TextWidget *v24; // [sp+2Ch] [bp-D0h]@40
  GUIIcon *thisa; // [sp+30h] [bp-CCh]@35
  GUIWindow *v26; // [sp+34h] [bp-C8h]@13
  GUIWindow *v27; // [sp+38h] [bp-C4h]@7
  PRIMARY_SKILL v28; // [sp+3Ch] [bp-C0h]@50
  signed int v29; // [sp+40h] [bp-BCh]@49
  int v30; // [sp+40h] [bp-BCh]@73
  int a4a; // [sp+48h] [bp-B4h]@57
  int a4b; // [sp+48h] [bp-B4h]@73
  signed int v33; // [sp+4Ch] [bp-B0h]@50
  int imgIdx; // [sp+50h] [bp-ACh]@61
  int imgIdxa; // [sp+50h] [bp-ACh]@77
  int v36; // [sp+54h] [bp-A8h]@57
  int v37; // [sp+58h] [bp-A4h]@30
  int a7; // [sp+5Ch] [bp-A0h]@34
  int v39; // [sp+60h] [bp-9Ch]@30
  InputEvent evt; // [sp+6Ch] [bp-90h]@1
  __int16 v41; // [sp+88h] [bp-74h]@1
  Icon *res; // [sp+8Ch] [bp-70h]@2
  __int16 v43; // [sp+90h] [bp-6Ch]@1
  __int16 v44; // [sp+94h] [bp-68h]@1
  __int16 v45; // [sp+98h] [bp-64h]@1
  __int16 v46; // [sp+9Ch] [bp-60h]@1
  char content[20]; // [sp+A0h] [bp-5Ch]@40
  PRIMARY_SKILL skill; // [sp+B4h] [bp-48h]@18
  int v49; // [sp+B8h] [bp-44h]@88
  int v50; // [sp+BCh] [bp-40h]@88
  __int16 v51; // [sp+C0h] [bp-3Ch]@1
  GUIWindow *window; // [sp+C4h] [bp-38h]@8
  Hero *v53; // [sp+C8h] [bp-34h]@2
  int guiObj[5]; // [sp+CCh] [bp-30h]@36
  PRIMARY_SKILL v55; // [sp+E0h] [bp-1Ch]@18
  __int16 v56; // [sp+E4h] [bp-18h]@1
  int v57[5]; // [sp+E8h] [bp-14h]@41

  v19 = (int)this;
  v45 = 22;
  v44 = 124;
  v43 = 32;
  v56 = 32;
  v46 = 1;
  v41 = 2;
  v51 = 8;
  evt.eventCode = 512;
  if ( a2 == -1 )
    return;
  res = ResourceManager::getIconByFilename(resourceManager, "mons32.icn");
  v53 = &gameObject->heroes[a2];
  if ( gameObject->heroes[a2].probablyOwnerIdx == curPlayerIdx
    || *(_DWORD *)(v19 + 886) == 1
    || sub_458C60(v53->x, v53->y, 8) )
  {
    if ( a4 == -1 )
    {
      a4 = 288;
      a5 = 30 * a3 + 97;
    }
    v27 = (GUIWindow *)operator new(0x44u);
    if ( v27 )
      window = GUIWindow_constructorFromFile(v27, a4, a5, "qhero0.bin");
    else
      window = 0;
    if ( !window )
      fatalOutOfMemoryError();
    setOptionsScreenTitles(window, 18);
  }
  else
  {
    v26 = (GUIWindow *)operator new(0x44u);
    if ( v26 )
      window = GUIWindow_constructorFromFile(v26, a4, a5, "qhero1.bin");
    else
      window = 0;
    if ( !window )
      fatalOutOfMemoryError();
  }
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 2;
  evt.payload = (void *)v53->heroID;
  GUIWindow::processMessage(window, (Event *)&evt);
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 8;
  evt.payload = (void *)(2 * gameObject->players[v53->probablyOwnerIdx].color);
  GUIWindow::processMessage(window, (Event *)&evt);
  ++evt.yCoord;
  ++evt.payload;
  GUIWindow::processMessage(window, (Event *)&evt);
  sprintf(globBuf, "%s", v53->name);
  evt.xCoordOrKeycode = 3;
  evt.yCoord = 1;
  evt.payload = globBuf;
  GUIWindow::processMessage(window, (Event *)&evt);
  v55 = 0;
  for ( skill = 0; (signed int)skill < 5; ++skill )
  {
    if ( v53->army.creatureTypes[skill] != -1 )
      ++v55;
  }
  if ( v53->probablyOwnerIdx == curPlayerIdx || *(_DWORD *)(v19 + 886) == 1 || sub_458C60(v53->x, v53->y, 8) )
  {
    for ( skill = 0; (signed int)skill < 4; ++skill )
    {
      v5 = Hero::getPrimarySkill(v53, skill);
      sprintf(globBuf, "%d", v5);
      evt.yCoord = skill + 3;
      evt.payload = globBuf;
      GUIWindow::processMessage(window, (Event *)&evt);
    }
    v6 = Hero::getPrimarySkill(v53, PRIMARY_SKILL_KNOWLEDGE);
    sprintf(globBuf, "%d/%d", v53->spellpoints, 10 * v6);
    evt.yCoord = 7;
    evt.payload = globBuf;
    GUIWindow::processMessage(window, (Event *)&evt);
    if ( v55 )
    {
      v37 = (160 - 32 * v55) / 2 + 22;
      v39 = 0;
      for ( skill = 0; v55 > skill; ++skill )
      {
        while ( v53->army.creatureTypes[v39] == -1 )
          ++v39;
        a7 = v53->army.creatureTypes[v39];
        if ( a7 != -1 )
        {
          thisa = (GUIIcon *)operator new(0x2Du);
          if ( thisa )
          {
            v7 = 124 - getNthHeader(res, a7)->offsetY;
            v8 = v7 - getNthHeader(res, a7)->height + 30;
            v9 = v37 + 32 * skill - getNthHeader(res, a7)->offsetX;
            v10 = getNthHeader(res, a7);
            guiObj[skill] = (int)GUIIcon_constructor(
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
            fatalOutOfMemoryError();
          *(_DWORD *)&content[4 * skill] = KBAlloc(5u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F600 + 155);
          sprintf(*(char **)&content[4 * skill], "%d", v53->army.quantities[v39]);
          v24 = (TextWidget *)operator new(0x2Bu);
          if ( v24 )
            v57[skill] = (int)TextWidget_constructor(
                                v24,
                                v37 + 32 * skill,
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
            v57[skill] = 0;
          if ( !v57[skill] )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(window, (AbstractGUIComponent *)guiObj[skill], -1);
          GUIWindow::insertElement(window, (AbstractGUIComponent *)v57[skill], -1);
        }
        ++v39;
      }
    }
    goto LABEL_88;
  }
  if ( v55 )
  {
    v29 = 73;
    if ( (signed int)v55 < 1 )
      goto LABEL_52;
    if ( (signed int)v55 <= 3 )
    {
      v29 = 95;
      v28 = v55;
      v33 = 0;
    }
    else
    {
      if ( v55 != 4 )
      {
LABEL_52:
        v28 = 2;
        v33 = 3;
        goto LABEL_57;
      }
      v28 = 2;
      v33 = 2;
    }
LABEL_57:
    v36 = 0;
    a4a = 160 / v28;
    for ( skill = 0; v28 > skill; ++skill )
    {
      while ( v53->army.creatureTypes[v36] == -1 )
        ++v36;
      imgIdx = v53->army.creatureTypes[v36];
      v23 = (GUIIcon *)operator new(0x2Du);
      if ( v23 )
      {
        v11 = v29 - getNthHeader(res, imgIdx)->offsetY;
        v12 = v11 - getNthHeader(res, imgIdx)->height + 30;
        LOWORD(v11) = (160 / v28 - 32) / 2 + 22 + a4a * (_WORD)skill - getNthHeader(res, imgIdx)->offsetX;
        v13 = getNthHeader(res, imgIdx);
        guiObj[skill] = (int)GUIIcon_constructor(
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
        fatalOutOfMemoryError();
      *(_DWORD *)&content[4 * skill] = KBAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F600 + 227);
      v14 = sub_44F960(v53->army.quantities[v36], 0);
      strcpy(*(char **)&content[4 * skill], v14);
      v22 = (TextWidget *)operator new(0x2Bu);
      if ( v22 )
        v57[skill] = (int)TextWidget_constructor(
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
        v57[skill] = 0;
      if ( !v57[skill] )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(window, (AbstractGUIComponent *)guiObj[skill], -1);
      GUIWindow::insertElement(window, (AbstractGUIComponent *)v57[skill], -1);
      ++v36;
    }
    if ( v33 )
    {
      a4b = 160 / v33;
      v30 = v29 + 44;
      for ( skill = v28; v33 + v28 > skill; ++skill )
      {
        while ( v53->army.creatureTypes[v36] == -1 )
          ++v36;
        imgIdxa = v53->army.creatureTypes[v36];
        v21 = (GUIIcon *)operator new(0x2Du);
        if ( v21 )
        {
          v15 = v30 - getNthHeader(res, imgIdxa)->offsetY;
          v16 = v15 - getNthHeader(res, imgIdxa)->height + 36;
          LOWORD(v15) = (160 / v33 - 32) / 2 + 22 + (_WORD)a4b * (skill - 2) - getNthHeader(res, imgIdxa)->offsetX;
          v17 = getNthHeader(res, imgIdxa);
          guiObj[skill] = (int)GUIIcon_constructor(
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
          fatalOutOfMemoryError();
        *(_DWORD *)&content[4 * skill] = KBAlloc(0xFu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F600 + 270);
        v18 = sub_44F960(v53->army.quantities[v36], 0);
        strcpy(*(char **)&content[4 * skill], v18);
        v20 = (TextWidget *)operator new(0x2Bu);
        if ( v20 )
          v57[skill] = (int)TextWidget_constructor(
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
          v57[skill] = 0;
        if ( !v57[skill] )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(window, (AbstractGUIComponent *)guiObj[skill], -1);
        GUIWindow::insertElement(window, (AbstractGUIComponent *)v57[skill], -1);
        ++v36;
      }
    }
  }
LABEL_88:
  v50 = *(_DWORD *)(v19 + 470);
  v49 = *(_DWORD *)(v19 + 474);
  *(_DWORD *)(v19 + 470) = v53->x - 7;
  *(_DWORD *)(v19 + 474) = v53->y - 7;
  sub_44AA80(v19, 1, 0);
  HeroWindowManager::addWindow(HeroWindowManager::instance, window, -1, 1);
  waitForMouseRelease();
  HeroWindowManager::removeWindow(HeroWindowManager::instance, window);
  operator delete(window);
  *(_DWORD *)(v19 + 470) = v50;
  *(_DWORD *)(v19 + 474) = v49;
  sub_44AA80(v19, 1, 0);
  sub_448110((AdvManager *)v19, 0);
  sub_447A00((void *)v19, 0, 0);
  if ( evt.eventCode == 8 && v53->probablyOwnerIdx == curPlayerIdx )
    sub_450C10((void *)v19, v53->field_2, 0);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
}
