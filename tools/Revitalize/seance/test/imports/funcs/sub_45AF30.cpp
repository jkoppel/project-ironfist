{
  int v2; // [sp+Ch] [bp-1F0h]@24
  int v3; // [sp+10h] [bp-1ECh]@10
  int v4; // [sp+14h] [bp-1E8h]@1
  GUIWindow *v5; // [sp+28h] [bp-1D4h]@75
  GUIWindow *v6; // [sp+2Ch] [bp-1D0h]@71
  GUIWindow *v7; // [sp+30h] [bp-1CCh]@67
  GUIWindow *v8; // [sp+38h] [bp-1C4h]@31
  GUIWindow *thisa; // [sp+40h] [bp-1BCh]@5
  char v10; // [sp+44h] [bp-1B8h]@61
  int v11; // [sp+B8h] [bp-144h]@61
  char v12; // [sp+BCh] [bp-140h]@63
  int evt; // [sp+1BCh] [bp-40h]@34
  int v14; // [sp+1C0h] [bp-3Ch]@34
  int v15; // [sp+1C4h] [bp-38h]@34
  int v16; // [sp+1D4h] [bp-28h]@34
  int v17; // [sp+1D8h] [bp-24h]@21
  int v18; // [sp+1DCh] [bp-20h]@21
  void *v19; // [sp+1E0h] [bp-1Ch]@22
  GUIWindow *window; // [sp+1E4h] [bp-18h]@6
  int v21; // [sp+1E8h] [bp-14h]@56
  int i; // [sp+1ECh] [bp-10h]@17
  bool v23; // [sp+1F0h] [bp-Ch]@1
  char v24; // [sp+1F4h] [bp-8h]@38
  int v25; // [sp+1F8h] [bp-4h]@38

  v4 = this;
  v23 = 1;
  *(_DWORD *)(this + 25496) = 0;
  if ( (!dword_4F7494 || !dword_523F14) && (!dword_4F7494 || !byte_51AC64) )
  {
    thisa = (GUIWindow *)operator new(0x44u);
    if ( thisa )
      window = GUIWindow_constructorFromFile(thisa, 405, 8, "x_mapmnu.bin");
    else
      window = 0;
    if ( !window )
      fatalOutOfMemoryError();
    HeroWindowManager::displayWindow(
      HeroWindowManager::instance,
      window,
      (int (__fastcall *)(InputEvent *))sub_4BC5E0,
      0);
    operator delete(window);
    v3 = LOWORD(HeroWindowManager::instance->buttonPressedCode);
    switch ( v3 )
    {
      case 1:
        LOBYTE(inExpansion) = 0;
        break;
      case 2:
        LOBYTE(inExpansion) = 1;
        break;
      case 30721:
        return 0;
    }
  }
  sub_45AEA0();
  animationFrameSwitchTime = 0;
  for ( i = 0; i < 3; ++i )
  {
    (&dword_524F28)[4 * i] = (char *)KBAlloc(0x65u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 45);
    strcpy((&dword_524F28)[4 * i], byte_5111B0);
  }
  dword_524F34 = (char *)KBAlloc(0x69u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 48);
  dword_524F3C = (char *)KBAlloc(0x69u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 49);
  strcpy(dword_524F34, byte_5111F4);
  strcpy(dword_524F3C, byte_5111F8);
  dword_524F20 = 0;
  dword_524F38 = ResourceManager::getIconByFilename(resourceManager, "ngextra.icn");
  if ( dword_523F08 )
  {
    v17 = 0;
    v18 = 0;
    do
    {
      do
      {
        do
        {
          yieldToGlobalUpdater();
          v19 = sub_46E3F0(1);
        }
        while ( !v19 );
      }
      while ( *((_BYTE *)v19 + 5) != 2 );
      v2 = *((_BYTE *)v19 + 6);
      if ( v2 == 52 )
      {
        memset((void *)(v4 + 681), 0, 0x1A4u);
        memcpy((void *)(v4 + 681), (char *)v19 + 9, 0x74u);
        v17 = 1;
      }
      else
      {
        if ( v2 == 55 )
        {
          memcpy(&dword_526CE0, (char *)v19 + 9, 0xCCu);
          sub_45AEA0();
          v18 = 1;
        }
      }
    }
    while ( !v18 || !v17 );
    v8 = (GUIWindow *)operator new(0x44u);
    if ( v8 )
      *(_DWORD *)(v4 + 25496) = GUIWindow_constructorFromFile(v8, 190, 4, "ngmp.bin");
    else
      *(_DWORD *)(v4 + 25496) = 0;
    sub_45AA00(v4, (const void *)(v4 + 681));
    sub_45BB00(v4);
    sub_45C180(v4);
    evt = 512;
    v15 = 54;
    v14 = 5;
    v16 = 4096;
    GUIWindow::processMessage(*(GUIWindow **)(v4 + 25496), (Event *)&evt);
    v14 = 6;
    v16 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v4 + 25496), (Event *)&evt);
    v15 = 30722;
    v14 = 5;
    v16 = 4096;
    GUIWindow::processMessage(*(GUIWindow **)(v4 + 25496), (Event *)&evt);
    v14 = 6;
    v16 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v4 + 25496), (Event *)&evt);
    v15 = 30721;
    v14 = 5;
    v16 = 4096;
    GUIWindow::processMessage(*(GUIWindow **)(v4 + 25496), (Event *)&evt);
    v14 = 6;
    v16 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v4 + 25496), (Event *)&evt);
    dword_5110CC = 0;
    HeroWindowManager::displayWindow(
      HeroWindowManager::instance,
      *(GUIWindow **)(v4 + 25496),
      (int (__fastcall *)(InputEvent *))sub_45C720,
      0);
    operator delete(*(void **)(v4 + 25496));
    v23 = HeroWindowManager::instance->buttonPressedCode != 30721;
  }
  else
  {
    while ( 1 )
    {
      v24 = 0;
      v25 = sub_4C91C0((const char *)(v4 + 1126), 46);
      if ( v25 )
      {
        if ( sub_48C5F0((int *)v25, (int *)".MX2") && inExpansion )
          v24 = 1;
        if ( sub_48C5F0((int *)v25, (int *)".MP2") && !inExpansion )
          v24 = 1;
      }
      if ( !v24 )
      {
        if ( inExpansion )
          strcpy(gameObject->_5, "arrax.mx2");
        else
          strcpy(gameObject->_5, "brokena.mp2");
        *(_BYTE *)(v4 + 1146) = 0;
        *(_BYTE *)(v4 + 1147) = dword_5235D4;
      }
      if ( dword_5235D4 > 3 && !_strcmpi(gameObject->_5, "brokena.mp2") )
        strcpy(gameObject->_5, "slugfest.mp2");
      if ( dword_5235D4 > 1 && !_strcmpi(gameObject->_5, "arrax.mx2") )
        strcpy(gameObject->_5, "fullhse.mx2");
      strcpy(byte_524740, (const char *)(v4 + 1126));
      v21 = sub_40B430(v4 + 1126, (void *)(v4 + 681));
      if ( v21 )
      {
        if ( *(_BYTE *)(v4 + 708) <= dword_5235D4 && *(_BYTE *)(v4 + 709) >= dword_5235D4 )
          break;
      }
      sub_45A7A0(gameObject);
    }
    if ( dword_4F7494 )
    {
      memcpy(&v10, &gameObject->_1[676], 0x74u);
      v11 = sub_46E1D0(&v10, 127, 0x74u, 52, 1, 1, -1);
      if ( !v11 )
        terminate(0);
      memcpy(&v12, &dword_526CE0, 0xCCu);
      v11 = sub_46E1D0(&v12, 127, 0xCCu, 55, 1, 1, -1);
      if ( !v11 )
        terminate(0);
    }
    sub_41B5F0((void *)v4, "origdata.bin", 1, 0);
    if ( dword_5235D4 <= 1 )
    {
      v5 = (GUIWindow *)operator new(0x44u);
      if ( v5 )
        *(_DWORD *)(v4 + 25496) = GUIWindow_constructorFromFile(v5, 190, 33, "ngsp.bin");
      else
        *(_DWORD *)(v4 + 25496) = 0;
    }
    else
    {
      if ( dword_524778 == 2 )
      {
        v7 = (GUIWindow *)operator new(0x44u);
        if ( v7 )
          *(_DWORD *)(v4 + 25496) = GUIWindow_constructorFromFile(v7, 190, 4, "nghs.bin");
        else
          *(_DWORD *)(v4 + 25496) = 0;
      }
      else
      {
        v6 = (GUIWindow *)operator new(0x44u);
        if ( v6 )
          *(_DWORD *)(v4 + 25496) = GUIWindow_constructorFromFile(v6, 190, 4, "ngmp.bin");
        else
          *(_DWORD *)(v4 + 25496) = 0;
      }
    }
    if ( !*(_DWORD *)(v4 + 25496) )
      fatalOutOfMemoryError();
    setOptionsScreenTitles(*(GUIWindow **)(v4 + 25496), 7);
    sub_45AA00(v4, 0);
    sub_45BB00(v4);
    sub_45C180(v4);
    dword_524F24 = 0;
    dword_5110CC = 0;
    HeroWindowManager::displayWindow(
      HeroWindowManager::instance,
      *(GUIWindow **)(v4 + 25496),
      (int (__fastcall *)(InputEvent *))sub_45C720,
      0);
    operator delete(*(void **)(v4 + 25496));
    if ( HeroWindowManager::instance->buttonPressedCode == 30721 )
    {
      v23 = 0;
    }
    else
    {
      *(_BYTE *)(v4 + 1166) = *(_BYTE *)(v4 + 707);
      sub_41C580((void *)v4, byte_524740);
    }
  }
  for ( i = 0; i < 3; ++i )
    KBFree((&dword_524F28)[4 * i], (int)"F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 286);
  KBFree(dword_524F34, (int)"F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 288);
  KBFree(dword_524F3C, (int)"F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 289);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)dword_524F38);
  return v23;
}
