{
  signed int v1; // ST74_4@1
  signed int v2; // ecx@1
  int result; // eax@5
  int v4; // [sp+Ch] [bp-54h]@1
  GUIIcon *v5; // [sp+10h] [bp-50h]@58
  TextWidget *v6; // [sp+14h] [bp-4Ch]@53
  GUIIcon *v7; // [sp+18h] [bp-48h]@42
  TextWidget *thisa; // [sp+1Ch] [bp-44h]@34
  GUIIcon *v9; // [sp+20h] [bp-40h]@28
  GUIIcon *v10; // [sp+24h] [bp-3Ch]@23
  GUIIcon *v11; // [sp+28h] [bp-38h]@18
  GUIIcon *v12; // [sp+2Ch] [bp-34h]@12
  GUIIcon *v13; // [sp+30h] [bp-30h]@7
  void *content; // [sp+34h] [bp-2Ch]@34
  void *contenta; // [sp+34h] [bp-2Ch]@47
  signed __int16 v16; // [sp+38h] [bp-28h]@40
  signed int v17; // [sp+3Ch] [bp-24h]@49
  signed __int16 v18; // [sp+40h] [bp-20h]@1
  int v19; // [sp+44h] [bp-1Ch]@1
  AbstractGUIComponent *guiObj; // [sp+48h] [bp-18h]@8
  AbstractGUIComponent *guiObja; // [sp+48h] [bp-18h]@13
  AbstractGUIComponent *guiObjb; // [sp+48h] [bp-18h]@19
  AbstractGUIComponent *guiObjc; // [sp+48h] [bp-18h]@24
  AbstractGUIComponent *guiObjd; // [sp+48h] [bp-18h]@29
  AbstractGUIComponent *guiObje; // [sp+48h] [bp-18h]@43
  AbstractGUIComponent *guiObjf; // [sp+48h] [bp-18h]@59
  signed int i; // [sp+50h] [bp-10h]@4
  int v28; // [sp+54h] [bp-Ch]@1
  AbstractGUIComponent *v29; // [sp+58h] [bp-8h]@35
  AbstractGUIComponent *v30; // [sp+58h] [bp-8h]@54

  v4 = this;
  v1 = 372 - 62 * *(_BYTE *)(this + 707);
  v2 = *(_BYTE *)(this + 707) + 1;
  v28 = v1 / v2 + 24;
  v19 = v1 / v2 + 62;
  v18 = 0;
  if ( dword_5235D4 > 1 && dword_524778 != 2 )
    v18 = -14;
  for ( i = 0; ; ++i )
  {
    result = v4;
    if ( *(_BYTE *)(v4 + 707) <= i )
      break;
    if ( dword_5235D4 > 1 )
    {
      v13 = (GUIIcon *)operator new(0x2Du);
      if ( v13 )
        guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                           v13,
                                           (_WORD)v28 + i * (_WORD)v19 + 13,
                                           v18 + 343,
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
      GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObj, -1);
      v12 = (GUIIcon *)operator new(0x2Du);
      if ( v12 )
        guiObja = (AbstractGUIComponent *)GUIIcon_constructor(
                                            v12,
                                            (_WORD)v28 + i * (_WORD)v19 + 16,
                                            v18 + 340,
                                            62,
                                            26,
                                            "ngextra.icn",
                                            0,
                                            0,
                                            i + 48,
                                            16,
                                            1);
      else
        guiObja = 0;
      if ( !guiObja )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObja, -1);
    }
    v11 = (GUIIcon *)operator new(0x2Du);
    if ( v11 )
      guiObjb = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v11,
                                          (_WORD)v28 + i * (_WORD)v19 + 11,
                                          197,
                                          68,
                                          (((dword_5235D4 <= 1) - 1) & 0x11) + 47,
                                          "ngextra.icn",
                                          (((dword_5235D4 <= 1) - 1) & 0xFFED) + 79,
                                          0,
                                          i + 6,
                                          16,
                                          1);
    else
      guiObjb = 0;
    if ( !guiObjb )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObjb, -1);
    v10 = (GUIIcon *)operator new(0x2Du);
    if ( v10 )
      guiObjc = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v10,
                                          (_WORD)v28 + i * (_WORD)v19 + 13,
                                          191,
                                          68,
                                          (((dword_5235D4 <= 1) - 1) & 0xD) + 51,
                                          "ngextra.icn",
                                          (((dword_5235D4 <= 1) - 1) & 0xFFEF) + 80,
                                          0,
                                          i + 18,
                                          16,
                                          1);
    else
      guiObjc = 0;
    if ( !guiObjc )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObjc, -1);
    v9 = (GUIIcon *)operator new(0x2Du);
    if ( v9 )
      guiObjd = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v9,
                                          (_WORD)v28 + i * (_WORD)v19 + 16,
                                          194,
                                          62,
                                          58,
                                          "ngextra.icn",
                                          (((dword_5235D4 <= 1) - 1) & 0x18) + 3,
                                          0,
                                          i + 12,
                                          16,
                                          1);
    else
      guiObjd = 0;
    if ( !guiObjd )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObjd, -1);
    if ( dword_5235D4 > 1 )
    {
      content = KBAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511304 + 80);
      sprintf((char *)content, L" ");
      thisa = (TextWidget *)operator new(0x2Bu);
      if ( thisa )
        v29 = (AbstractGUIComponent *)TextWidget_constructor(
                                        thisa,
                                        (_WORD)v28 + i * (_WORD)v19 + 19,
                                        240,
                                        56,
                                        9,
                                        (char *)content,
                                        "smalfont.fnt",
                                        1,
                                        i + 24,
                                        512,
                                        1);
      else
        v29 = 0;
      if ( !v29 )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), v29, -1);
    }
    v16 = 0;
    if ( dword_5235D4 == 1 )
      v16 = -14;
    v7 = (GUIIcon *)operator new(0x2Du);
    if ( v7 )
      guiObje = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v7,
                                          (_WORD)v28 + i * (_WORD)v19 + 11,
                                          v16 + v18 + 277,
                                          64,
                                          47,
                                          "ngextra.icn",
                                          61,
                                          0,
                                          i + 30,
                                          16,
                                          1);
    else
      guiObje = 0;
    if ( !guiObje )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObje, -1);
    contenta = KBAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511304 + 112);
    sprintf((char *)contenta, L"A");
    if ( (signed int)*(_BYTE *)(v4 + 707) < 5 )
    {
      v17 = 26;
    }
    else
    {
      if ( (signed int)*(_BYTE *)(v4 + 707) < 6 )
        v17 = 16;
      else
        v17 = 0;
    }
    v6 = (TextWidget *)operator new(0x2Bu);
    if ( v6 )
      v30 = (AbstractGUIComponent *)TextWidget_constructor(
                                      v6,
                                      (_WORD)v28 + i * (_WORD)v19 + 15 - v17 / 2,
                                      v16 + v18 + 322,
                                      v17 + 64,
                                      12,
                                      (char *)contenta,
                                      "smalfont.fnt",
                                      1,
                                      i + 78,
                                      512,
                                      1);
    else
      v30 = 0;
    if ( !v30 )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), v30, -1);
    v5 = (GUIIcon *)operator new(0x2Du);
    if ( v5 )
      guiObjf = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v5,
                                          (_WORD)v28 + i * (_WORD)v19 + 16,
                                          v16 + v18 + 274,
                                          62,
                                          45,
                                          "ngextra.icn",
                                          51,
                                          0,
                                          i + 36,
                                          16,
                                          1);
    else
      guiObjf = 0;
    if ( !guiObjf )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v4 + 25496), guiObjf, -1);
  }
  return result;
}
