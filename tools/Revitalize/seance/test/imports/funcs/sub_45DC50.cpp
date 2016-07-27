{
  signed int v1; // eax@6
  int v3; // [sp+Ch] [bp-84h]@1
  GUIIcon *v4; // [sp+18h] [bp-78h]@59
  TextWidget *v5; // [sp+1Ch] [bp-74h]@54
  GUIIcon *v6; // [sp+20h] [bp-70h]@43
  TextWidget *v7; // [sp+24h] [bp-6Ch]@37
  GUIIcon *v8; // [sp+28h] [bp-68h]@31
  GUIIcon *v9; // [sp+2Ch] [bp-64h]@26
  GUIIcon *v10; // [sp+30h] [bp-60h]@20
  GUIIcon *thisa; // [sp+34h] [bp-5Ch]@15
  GUIWindow *v12; // [sp+38h] [bp-58h]@1
  void *content; // [sp+3Ch] [bp-54h]@37
  void *contenta; // [sp+3Ch] [bp-54h]@48
  signed int v15; // [sp+44h] [bp-4Ch]@50
  int evt; // [sp+48h] [bp-48h]@6
  int v17; // [sp+4Ch] [bp-44h]@6
  int v18; // [sp+50h] [bp-40h]@6
  int v19; // [sp+60h] [bp-30h]@6
  int v20; // [sp+64h] [bp-2Ch]@12
  int v21; // [sp+68h] [bp-28h]@12
  AbstractGUIComponent *guiObj; // [sp+6Ch] [bp-24h]@12
  int v23; // [sp+70h] [bp-20h]@12
  int i; // [sp+74h] [bp-1Ch]@12
  int v25; // [sp+78h] [bp-18h]@6
  int v26; // [sp+7Ch] [bp-14h]@12
  TextWidget *v27; // [sp+80h] [bp-10h]@12
  int v28; // [sp+84h] [bp-Ch]@12
  bool v29; // [sp+88h] [bp-8h]@78
  GUIWindow *a2; // [sp+8Ch] [bp-4h]@2

  v3 = (int)this;
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  v12 = (GUIWindow *)operator new(0x44u);
  if ( v12 )
    a2 = GUIWindow_constructorFromFile(v12, 90, 4, "sceninfo.bin");
  else
    a2 = 0;
  if ( !a2 )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(a2, 23);
  evt = 512;
  v17 = 3;
  v18 = 64;
  v19 = v3 + 739;
  GUIWindow::processMessage(a2, (Event *)&evt);
  v18 = 200;
  v19 = (int)off_4F6928[*(_BYTE *)(v3 + 685)];
  GUIWindow::processMessage(a2, (Event *)&evt);
  v18 = 201;
  v19 = (int)off_4F6928[*(_BYTE *)(v3 + 1125)];
  GUIWindow::processMessage(a2, (Event *)&evt);
  v1 = sub_42C980(v3);
  sprintf(globBuf, "%d", v1);
  strcat(globBuf, L"%");
  v18 = 202;
  v19 = (int)globBuf;
  GUIWindow::processMessage(a2, (Event *)&evt);
  v25 = 0;
  switch ( *(_BYTE *)(v3 + 687) )
  {
    case 0x48:
      v25 = 1;
      break;
    case 0x6C:
      v25 = 2;
      break;
    case 0x90:
      v25 = 3;
      break;
  }
  v18 = 203;
  v19 = (int)off_4F6918[v25];
  GUIWindow::processMessage(a2, (Event *)&evt);
  v18 = 204;
  v19 = v3 + 799;
  GUIWindow::processMessage(a2, (Event *)&evt);
  sub_45E9A0(v3, globBuf);
  v18 = 205;
  v19 = (int)globBuf;
  GUIWindow::processMessage(a2, (Event *)&evt);
  sub_45E7D0(v3, globBuf);
  v18 = 206;
  v19 = (int)globBuf;
  GUIWindow::processMessage(a2, (Event *)&evt);
  guiObj = 0;
  v27 = 0;
  v23 = 372 - 62 * *(_BYTE *)(v3 + 707);
  v28 = v23 / (*(_BYTE *)(v3 + 707) + 1);
  v26 = v28 + 24;
  v21 = v28 + 62;
  v20 = 0;
  for ( i = 0; *(_BYTE *)(v3 + 707) > i; ++i )
  {
    if ( dword_5235D4 > 1 )
    {
      thisa = (GUIIcon *)operator new(0x2Du);
      if ( thisa )
        guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                           thisa,
                                           (_WORD)v26 + i * (_WORD)v21 + 13,
                                           v20 + 309,
                                           64,
                                           28,
                                           "ngextra.icn",
                                           59,
                                           0,
                                           i + 42,
                                           16,
                                           1);
      else
        guiObj = 0;
      if ( !guiObj )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(a2, guiObj, -1);
      v10 = (GUIIcon *)operator new(0x2Du);
      if ( v10 )
        guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                           v10,
                                           (_WORD)v26 + i * (_WORD)v21 + 16,
                                           v20 + 306,
                                           62,
                                           26,
                                           "ngextra.icn",
                                           0,
                                           0,
                                           i + 48,
                                           16,
                                           1);
      else
        guiObj = 0;
      if ( !guiObj )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(a2, guiObj, -1);
    }
    v9 = (GUIIcon *)operator new(0x2Du);
    if ( v9 )
      guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                         v9,
                                         (_WORD)v26 + i * (_WORD)v21 + 11,
                                         163,
                                         68,
                                         (((dword_5235D4 <= 1) - 1) & 0x11) + 47,
                                         "ngextra.icn",
                                         (((dword_5235D4 <= 1) - 1) & 0xFFED) + 79,
                                         0,
                                         i + 6,
                                         16,
                                         1);
    else
      guiObj = 0;
    if ( !guiObj )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(a2, guiObj, -1);
    v8 = (GUIIcon *)operator new(0x2Du);
    if ( v8 )
      guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                         v8,
                                         (_WORD)v26 + i * (_WORD)v21 + 16,
                                         160,
                                         62,
                                         58,
                                         "ngextra.icn",
                                         (((dword_5235D4 <= 1) - 1) & 0x18) + 3,
                                         0,
                                         i + 12,
                                         16,
                                         1);
    else
      guiObj = 0;
    if ( !guiObj )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(a2, guiObj, -1);
    if ( dword_5235D4 > 1 )
    {
      content = KBAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511448 + 114);
      sprintf((char *)content, L" ");
      v7 = (TextWidget *)operator new(0x2Bu);
      if ( v7 )
        v27 = TextWidget_constructor(
                v7,
                (_WORD)v26 + i * (_WORD)v21 + 19,
                206,
                56,
                9,
                (char *)content,
                "smalfont.fnt",
                1,
                i + 24,
                512,
                1);
      else
        v27 = 0;
      if ( !v27 )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(a2, (AbstractGUIComponent *)v27, -1);
    }
    v6 = (GUIIcon *)operator new(0x2Du);
    if ( v6 )
      guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                         v6,
                                         (_WORD)v26 + i * (_WORD)v21 + 11,
                                         v20 + 243,
                                         64,
                                         47,
                                         "ngextra.icn",
                                         61,
                                         0,
                                         i + 30,
                                         16,
                                         1);
    else
      guiObj = 0;
    if ( !guiObj )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(a2, guiObj, -1);
    contenta = KBAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511448 + 146);
    sprintf((char *)contenta, L"A");
    if ( (signed int)*(_BYTE *)(v3 + 707) < 5 )
    {
      v15 = 26;
    }
    else
    {
      if ( (signed int)*(_BYTE *)(v3 + 707) < 6 )
        v15 = 16;
      else
        v15 = 0;
    }
    v5 = (TextWidget *)operator new(0x2Bu);
    if ( v5 )
      v27 = TextWidget_constructor(
              v5,
              (_WORD)v26 + i * (_WORD)v21 + 15 - v15 / 2,
              v20 + 288,
              v15 + 64,
              12,
              (char *)contenta,
              "smalfont.fnt",
              1,
              i + 78,
              512,
              1);
    else
      v27 = 0;
    if ( !v27 )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(a2, (AbstractGUIComponent *)v27, -1);
    v4 = (GUIIcon *)operator new(0x2Du);
    if ( v4 )
      guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                         v4,
                                         (_WORD)v26 + i * (_WORD)v21 + 16,
                                         v20 + 240,
                                         62,
                                         45,
                                         "ngextra.icn",
                                         51,
                                         0,
                                         i + 36,
                                         16,
                                         1);
    else
      guiObj = 0;
    if ( !guiObj )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(a2, guiObj, -1);
  }
  for ( i = 0; *(_BYTE *)(v3 + 707) > i; ++i )
  {
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
    {
      sprintf(globBuf, byte_511520);
    }
    else
    {
      if ( strlen(&dword_5235E0[21 * *(_BYTE *)(i + v3 + 1119)]) )
        sprintf(globBuf, &dword_5235E0[21 * *(_BYTE *)(i + v3 + 1119)]);
      else
        sprintf(globBuf, "Player %d", *(_BYTE *)(i + v3 + 1119) + 1);
    }
    v17 = 3;
    v18 = i + 24;
    v19 = (int)globBuf;
    GUIWindow::processMessage(a2, (Event *)&evt);
    if ( *(_BYTE *)(v3 + 1145) == i )
      v17 = 5;
    else
      v17 = 6;
    v18 = i + 18;
    v19 = 4;
    GUIWindow::processMessage(a2, (Event *)&evt);
    v29 = !*(_BYTE *)(i + v3 + 1139) && (dword_5235D4 <= 1 || *(_BYTE *)(i + v3 + 1119) == 10);
    v17 = 4;
    v18 = i + 12;
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
      v19 = ((unsigned int)v29 < 1 ? 3 : 15) + *(_BYTE *)(i + v3 + 1101);
    else
      v19 = ((unsigned int)v29 < 1 ? 9 : 21) + *(_BYTE *)(i + v3 + 1101);
    if ( dword_5235D4 > 1 )
      v19 += 24;
    GUIWindow::processMessage(a2, (Event *)&evt);
    if ( v29 )
      v17 = 6;
    else
      v17 = 5;
    v19 = 2;
    GUIWindow::processMessage(a2, (Event *)&evt);
    v17 = 4;
    v18 = i + 48;
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
      v19 = 78;
    else
      v19 = *(_BYTE *)(i + v3 + 1107);
    GUIWindow::processMessage(a2, (Event *)&evt);
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
      v17 = 6;
    else
      v17 = 5;
    v19 = 2;
    GUIWindow::processMessage(a2, (Event *)&evt);
    v17 = 4;
    v18 = i + 36;
    v19 = ((unsigned int)v29 < 1 ? 51 : 70) + *(_BYTE *)(i + v3 + 1113);
    GUIWindow::processMessage(a2, (Event *)&evt);
    sprintf(globBuf, (&off_4F5AF8)[4 * *(_BYTE *)(i + v3 + 1113)]);
    v17 = 3;
    v18 = i + 78;
    v19 = (int)globBuf;
    GUIWindow::processMessage(a2, (Event *)&evt);
  }
  HeroWindowManager::displayWindow(HeroWindowManager::instance, a2, sub_432A10, 0);
  return operator delete(a2);
}
