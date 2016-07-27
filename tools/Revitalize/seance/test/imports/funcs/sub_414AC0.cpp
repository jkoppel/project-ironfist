{
  int v4; // eax@18
  int v5; // eax@21
  const char *v6; // eax@58
  const char *v7; // eax@64
  int v8; // eax@85
  const char *v9; // eax@88
  ICNHeader *v10; // eax@110
  int v11; // eax@111
  __int16 v12; // ST14_2@119
  __int16 v13; // ST08_2@119
  __int16 v14; // ST04_2@119
  __int16 v15; // bx@119
  ICNHeader *v16; // eax@119
  bool result; // eax@138
  void *v18; // [sp+Ch] [bp-14Ch]@1
  GUIIcon *thisa; // [sp+18h] [bp-140h]@118
  TextWidget *v20; // [sp+1Ch] [bp-13Ch]@113
  TextWidget *v21; // [sp+20h] [bp-138h]@89
  GUIWindow *v22; // [sp+24h] [bp-134h]@79
  int v23; // [sp+2Ch] [bp-12Ch]@59
  int v24; // [sp+30h] [bp-128h]@59
  void *content; // [sp+34h] [bp-124h]@1
  int v26[7]; // [sp+3Ch] [bp-11Ch]@114
  char v27[28]; // [sp+58h] [bp-100h]@113
  int v28[7]; // [sp+74h] [bp-E4h]@119
  int n[4]; // [sp+90h] [bp-C8h]@105
  int v30; // [sp+A0h] [bp-B8h]@45
  int evt; // [sp+A4h] [bp-B4h]@84
  int v32; // [sp+A8h] [bp-B0h]@84
  int v33; // [sp+ACh] [bp-ACh]@84
  int v34; // [sp+BCh] [bp-9Ch]@84
  int v35; // [sp+C0h] [bp-98h]@45
  int v36; // [sp+C4h] [bp-94h]@111
  __int16 v37; // [sp+C8h] [bp-90h]@45
  __int16 v38; // [sp+CCh] [bp-8Ch]@45
  int j; // [sp+D0h] [bp-88h]@94
  int v40; // [sp+D4h] [bp-84h]@97
  __int16 y[2]; // [sp+D8h] [bp-80h]@96
  int v42; // [sp+DCh] [bp-7Ch]@70
  char v43[8]; // [sp+E0h] [bp-78h]@3
  int v44; // [sp+E8h] [bp-70h]@1
  __int16 v45; // [sp+ECh] [bp-6Ch]@45
  int i; // [sp+F0h] [bp-68h]@1
  int v47; // [sp+F4h] [bp-64h]@111
  int v48; // [sp+F8h] [bp-60h]@45
  GUIWindow *a2a; // [sp+FCh] [bp-5Ch]@80
  char v50; // [sp+100h] [bp-58h]@84
  int v51; // [sp+110h] [bp-48h]@100
  __int16 v52; // [sp+114h] [bp-44h]@45
  int v53; // [sp+118h] [bp-40h]@70
  int v54; // [sp+11Ch] [bp-3Ch]@70
  Icon *res; // [sp+120h] [bp-38h]@94
  __int16 v56; // [sp+124h] [bp-34h]@45
  int v57; // [sp+128h] [bp-30h]@75
  int v58; // [sp+12Ch] [bp-2Ch]@1
  int v59; // [sp+130h] [bp-28h]@111
  int v60; // [sp+134h] [bp-24h]@45
  int v61; // [sp+138h] [bp-20h]@4
  __int16 v62; // [sp+13Ch] [bp-1Ch]@45
  __int16 width[2]; // [sp+140h] [bp-18h]@113
  __int16 v64[8]; // [sp+144h] [bp-14h]@3
  AbstractGUIComponent *guiObj; // [sp+154h] [bp-4h]@90

  v18 = this;
  v58 = 0;
  v44 = 0;
  content = KBAlloc(0x190u, "F:\\h2xsrc\\Source\\TOWNMGR.CPP", word_4EEF50 + 8);
  for ( i = 0; i < 7; ++i )
  {
    v64[i] = -1;
    v43[i] = LOBYTE(v64[i]);
  }
  v61 = -1;
  if ( a2 >= 19 && a2 <= 30 )
    v61 = a2 - 19;
  if ( a2 != 2 || *(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3) != 5 )
  {
    if ( a2 )
    {
      if ( a2 == 13 )
      {
        for ( i = 0; i < 7; ++i )
        {
          if ( *((_DWORD *)&unique_structures + 7 * townManager->castle->factionID + i) > 0 )
          {
            v43[v44] = i;
            v64[v44++] = *((_DWORD *)&unique_structures + 7 * townManager->castle->factionID + i);
          }
        }
      }
      else
      {
        if ( a2 > 15 )
        {
          for ( i = 0; i < 7; ++i )
          {
            if ( *(&dwellings_table[12 * (signed int)townManager->castle->factionID].wood + 7 * v61 + i) > 0 )
            {
              v43[v44] = i;
              v64[v44++] = *(&dwellings_table[12 * (signed int)townManager->castle->factionID].wood + 7 * v61 + i);
            }
          }
        }
        else
        {
          for ( i = 0; i < 7; ++i )
          {
            if ( *((_DWORD *)&general_structures + 7 * a2 + i) > 0 )
            {
              v43[v44] = i;
              v64[v44++] = *((_DWORD *)&general_structures + 7 * a2 + i);
            }
          }
        }
      }
    }
    else
    {
      v58 = townManager->castle->mageGuildLevel;
      for ( i = 0; i < 7; ++i )
      {
        v4 = v58 + 1;
        if ( v58 + 1 >= 5 )
          v4 = 5;
        if ( *(&dword_4F3DD8[7 * v4] + i) > 0 )
        {
          v43[v44] = i;
          v5 = v58 + 1;
          if ( v58 + 1 >= 5 )
            v5 = 5;
          v64[v44++] = *(&dword_4F3DD8[7 * v5] + i);
        }
      }
    }
  }
  else
  {
    for ( i = 0; i < 7; ++i )
    {
      if ( *((_DWORD *)&dword_51AC78 + i) > 0 )
      {
        v43[v44] = i;
        v64[v44++] = *((_DWORD *)&dword_51AC78 + i);
      }
    }
  }
  v62 = 40;
  v37 = 32;
  v56 = 289;
  v45 = 0;
  v52 = 2;
  v38 = 3;
  v35 = 0;
  v60 = 0;
  v30 = 0;
  v48 = 0;
  for ( i = 0; i < 7; ++i )
  {
    if ( v43[i] != -1 )
      ++v60;
  }
  if ( v60 > 4 )
  {
    switch ( v60 )
    {
      case 5:
        v30 = 2;
        v48 = 3;
        break;
      case 6:
        v30 = 3;
        v48 = 3;
        break;
      case 7:
        v30 = 3;
        v48 = 4;
        break;
    }
  }
  else
  {
    v30 = v60;
  }
  v6 = buildingDescription(*(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3), a2, 0);
  sprintf((char *)content, v6);
  if ( v61 >= 0 )
  {
    v24 = 0;
    v23 = *(&dword_4F4A68[12 * *(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3)] + v61);
    for ( i = 0; i < 32; ++i )
    {
      if ( (1 << i) & v23 )
      {
        if ( !v24 )
          strcat((char *)content, "\n\nRequires:");
        ++v24;
        strcat((char *)content, L"\n");
        v7 = buildingName(*(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3), i);
        strcat((char *)content, v7);
      }
    }
    if ( *(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3) == 5
      && a2 == 28
      && (signed int)*(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 28) <= 2 )
      strcat((char *)content, "\nLevel 2 Mage Guild");
  }
  strcat((char *)content, "\n ");
  v53 = Font::numLinesNeededToDisplay(bigFont, (const char *)content, 240);
  v42 = 151;
  v54 = 16 * v53 + 151;
  if ( v60 > 4 )
    v54 += 88;
  else
    v54 += 44;
  if ( !a4 )
    v54 += 39;
  v57 = (v54 - 69) / 45;
  if ( v57 < 3 )
    v57 = 3;
  if ( v57 > 6 )
    v57 = 6;
  sprintf(globBuf, "buybuil%d.bin", v57);
  v22 = (GUIWindow *)operator new(0x44u);
  if ( v22 )
    a2a = GUIWindow_constructorFromFile(v22, 158, 16, globBuf);
  else
    a2a = 0;
  if ( !a2a )
    fatalOutOfMemoryError();
  evt = 512;
  v32 = 9;
  v33 = 2;
  sprintf(&v50, "cstl%s.icn", faction_short_names[*(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3)]);
  v34 = (int)&v50;
  GUIWindow::processMessage(a2a, (Event *)&evt);
  v32 = 4;
  v33 = 2;
  v34 = a2;
  GUIWindow::processMessage(a2a, (Event *)&evt);
  if ( a2 )
  {
    v9 = buildingName(*(_BYTE *)(*(_DWORD *)((char *)v18 + 54) + 3), a2);
    strcpy(globBuf, v9);
  }
  else
  {
    v8 = v58 + 1;
    if ( v58 + 1 >= 5 )
      v8 = 5;
    sprintf(globBuf, "Mage Guild, Level %d", v8);
  }
  v32 = 3;
  v33 = 3;
  v34 = (int)globBuf;
  GUIWindow::processMessage(a2a, (Event *)&evt);
  v21 = (TextWidget *)operator new(0x2Bu);
  if ( v21 )
    guiObj = (AbstractGUIComponent *)TextWidget_constructor(
                                       v21,
                                       43,
                                       v42 + 24,
                                       240,
                                       16 * v53,
                                       (char *)content,
                                       "bigfont.fnt",
                                       1,
                                       -1,
                                       8,
                                       1);
  else
    guiObj = 0;
  if ( !guiObj )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(a2a, guiObj, -1);
  v35 = 0;
  res = ResourceManager::getIconByFilename(resourceManager, "resource.icn");
  for ( j = 0; j < 2; ++j )
  {
    *(_DWORD *)y = v42 + 16 * v53 + 44 * j + 12;
    if ( j )
      v40 = v48;
    else
      v40 = v30;
    if ( v40 > 0 )
    {
      v51 = 0;
      v44 = v35;
      for ( i = 0; i < 4; ++i )
      {
        if ( i >= v40 )
        {
          n[i] = -1;
        }
        else
        {
          while ( v43[v44] == -1 )
            ++v44;
          n[i] = v43[v44++];
        }
      }
      for ( i = 0; i < v40; ++i )
      {
        v10 = getNthHeader(res, n[i]);
        v51 += v10->width;
      }
      v47 = (256 - v51) / (v40 + 1);
      v11 = (256 - v51) / (v40 + 1);
      v36 = v11 + 32;
      v59 = v11 + 32;
      for ( i = 0; i < v40; ++i )
      {
        *(_DWORD *)width = getNthHeader(res, n[i])->width;
        *(_DWORD *)&v27[4 * v35] = KBAlloc(0xAu, "F:\\h2xsrc\\Source\\TOWNMGR.CPP", word_4EEF50 + 296);
        sprintf(*(char **)&v27[4 * v35], "%d", v64[v35]);
        v20 = (TextWidget *)operator new(0x2Bu);
        if ( v20 )
          v26[v35] = (int)TextWidget_constructor(
                            v20,
                            v59,
                            y[0] + 35,
                            width[0],
                            12,
                            *(char **)&v27[4 * v35],
                            "smalfont.fnt",
                            1,
                            -1,
                            8,
                            1);
        else
          v26[v35] = 0;
        if ( !v26[v35] )
          fatalOutOfMemoryError();
        thisa = (GUIIcon *)operator new(0x2Du);
        if ( thisa )
        {
          v12 = v43[v35];
          v13 = width[0];
          v14 = y[0];
          v15 = v59;
          v16 = getNthHeader(res, n[i]);
          v28[v35] = (int)GUIIcon_constructor(
                            thisa,
                            v15 - v16->offsetX,
                            v14,
                            v13,
                            12,
                            "resource.icn",
                            v12,
                            0,
                            -1,
                            16,
                            1);
        }
        else
        {
          v28[v35] = 0;
        }
        if ( !v28[v35] )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(a2a, (AbstractGUIComponent *)v26[v35], -1);
        GUIWindow::insertElement(a2a, (AbstractGUIComponent *)v28[v35++], -1);
        v59 += *(_DWORD *)width + v47;
      }
    }
  }
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
  if ( !a4 )
    HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 30720, 16392);
  *(_DWORD *)((char *)v18 + 350) = -1;
  if ( a4 )
  {
    v32 = 6;
    v34 = 6;
    v33 = 30722;
    GUIWindow::processMessage(a2a, (Event *)&evt);
    v32 = 6;
    v34 = 6;
    v33 = 30721;
    GUIWindow::processMessage(a2a, (Event *)&evt);
    v32 = 6;
    v34 = 6;
    v33 = 0;
    GUIWindow::processMessage(a2a, (Event *)&evt);
    HeroWindowManager::addWindow(HeroWindowManager::instance, a2a, -1, 1);
    waitForMouseRelease();
    HeroWindowManager::removeWindow(HeroWindowManager::instance, a2a);
  }
  else
  {
    if ( a3 )
    {
      v32 = 6;
      v33 = 30722;
      v34 = 2;
      GUIWindow::processMessage(a2a, (Event *)&evt);
      v32 = 5;
      v33 = 30722;
      v34 = 4096;
      GUIWindow::processMessage(a2a, (Event *)&evt);
    }
    HeroWindowManager::displayWindow(HeroWindowManager::instance, a2a, sub_432E90, 0);
    if ( HeroWindowManager::instance->buttonPressedCode == 30722 )
    {
      *(_DWORD *)((char *)v18 + 350) = a2;
      for ( i = 0; i < v60; ++i )
        curPlayer->resources[v43[i]] -= v64[i];
    }
  }
  if ( !a4 )
    HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
  operator delete(a2a);
  if ( a4 )
    result = 0;
  else
    result = HeroWindowManager::instance->buttonPressedCode == 30722;
  return result;
}
