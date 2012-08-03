{
  signed int v1; // ST74_4@1
  signed int v2; // ecx@1
  int result; // eax@5
  int v4; // [sp+Ch] [bp-54h]@1
  iconWidget *v5; // [sp+10h] [bp-50h]@58
  textWidget *v6; // [sp+14h] [bp-4Ch]@53
  iconWidget *v7; // [sp+18h] [bp-48h]@42
  textWidget *thisa; // [sp+1Ch] [bp-44h]@34
  iconWidget *v9; // [sp+20h] [bp-40h]@28
  iconWidget *v10; // [sp+24h] [bp-3Ch]@23
  iconWidget *v11; // [sp+28h] [bp-38h]@18
  iconWidget *v12; // [sp+2Ch] [bp-34h]@12
  iconWidget *v13; // [sp+30h] [bp-30h]@7
  char *content; // [sp+34h] [bp-2Ch]@34
  char *contenta; // [sp+34h] [bp-2Ch]@47
  signed __int16 v16; // [sp+38h] [bp-28h]@40
  signed int v17; // [sp+3Ch] [bp-24h]@49
  signed __int16 v18; // [sp+40h] [bp-20h]@1
  int v19; // [sp+44h] [bp-1Ch]@1
  widget *guiObj; // [sp+48h] [bp-18h]@8
  widget *guiObja; // [sp+48h] [bp-18h]@13
  widget *guiObjb; // [sp+48h] [bp-18h]@19
  widget *guiObjc; // [sp+48h] [bp-18h]@24
  widget *guiObjd; // [sp+48h] [bp-18h]@29
  widget *guiObje; // [sp+48h] [bp-18h]@43
  widget *guiObjf; // [sp+48h] [bp-18h]@59
  signed int i; // [sp+50h] [bp-10h]@4
  int v28; // [sp+54h] [bp-Ch]@1
  widget *v29; // [sp+58h] [bp-8h]@35
  widget *v30; // [sp+58h] [bp-8h]@54

  v4 = this;
  v1 = 372 - 62 * *(_BYTE *)(this + 707);
  v2 = *(_BYTE *)(this + 707) + 1;
  v28 = v1 / v2 + 24;
  v19 = v1 / v2 + 62;
  v18 = 0;
  if ( iLastMsgNumHumanPlayers > 1 && iMPBaseType != 2 )
    v18 = -14;
  for ( i = 0; ; ++i )
  {
    result = v4;
    if ( *(_BYTE *)(v4 + 707) <= i )
      break;
    if ( iLastMsgNumHumanPlayers > 1 )
    {
      v13 = (iconWidget *)operator new(45);
      if ( v13 )
        guiObj = (widget *)iconWidget::iconWidget(
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
        MemError();
      heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObj, -1);
      v12 = (iconWidget *)operator new(45);
      if ( v12 )
        guiObja = (widget *)iconWidget::iconWidget(
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
        MemError();
      heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObja, -1);
    }
    v11 = (iconWidget *)operator new(45);
    if ( v11 )
      guiObjb = (widget *)iconWidget::iconWidget(
                            v11,
                            (_WORD)v28 + i * (_WORD)v19 + 11,
                            197,
                            68,
                            iLastMsgNumHumanPlayers <= 1 ? 47 : 64,
                            "ngextra.icn",
                            iLastMsgNumHumanPlayers <= 1 ? 79 : 60,
                            0,
                            i + 6,
                            16,
                            1);
    else
      guiObjb = 0;
    if ( !guiObjb )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObjb, -1);
    v10 = (iconWidget *)operator new(45);
    if ( v10 )
      guiObjc = (widget *)iconWidget::iconWidget(
                            v10,
                            (_WORD)v28 + i * (_WORD)v19 + 13,
                            191,
                            68,
                            iLastMsgNumHumanPlayers <= 1 ? 51 : 64,
                            "ngextra.icn",
                            iLastMsgNumHumanPlayers <= 1 ? 80 : 63,
                            0,
                            i + 18,
                            16,
                            1);
    else
      guiObjc = 0;
    if ( !guiObjc )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObjc, -1);
    v9 = (iconWidget *)operator new(45);
    if ( v9 )
      guiObjd = (widget *)iconWidget::iconWidget(
                            v9,
                            (_WORD)v28 + i * (_WORD)v19 + 16,
                            194,
                            62,
                            58,
                            "ngextra.icn",
                            iLastMsgNumHumanPlayers <= 1 ? 3 : 27,
                            0,
                            i + 12,
                            16,
                            1);
    else
      guiObjd = 0;
    if ( !guiObjd )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObjd, -1);
    if ( iLastMsgNumHumanPlayers > 1 )
    {
      content = (char *)BaseAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511304 + 80);
      sprintf(content, L" ");
      thisa = (textWidget *)operator new(43);
      if ( thisa )
        v29 = (widget *)textWidget::textWidget(
                          thisa,
                          (_WORD)v28 + i * (_WORD)v19 + 19,
                          240,
                          56,
                          9,
                          content,
                          "smalfont.fnt",
                          1,
                          i + 24,
                          512,
                          1);
      else
        v29 = 0;
      if ( !v29 )
        MemError();
      heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), v29, -1);
    }
    v16 = 0;
    if ( iLastMsgNumHumanPlayers == 1 )
      v16 = -14;
    v7 = (iconWidget *)operator new(45);
    if ( v7 )
      guiObje = (widget *)iconWidget::iconWidget(
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
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObje, -1);
    contenta = (char *)BaseAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511304 + 112);
    sprintf(contenta, L"A");
    if ( (signed int)*(_BYTE *)(v4 + 707) < 5 )
    {
      v17 = 26;
    }
    else if ( (signed int)*(_BYTE *)(v4 + 707) < 6 )
    {
      v17 = 16;
    }
    else
    {
      v17 = 0;
    }
    v6 = (textWidget *)operator new(43);
    if ( v6 )
      v30 = (widget *)textWidget::textWidget(
                        v6,
                        (_WORD)v28 + i * (_WORD)v19 + 15 - v17 / 2,
                        v16 + v18 + 322,
                        v17 + 64,
                        12,
                        contenta,
                        "smalfont.fnt",
                        1,
                        i + 78,
                        512,
                        1);
    else
      v30 = 0;
    if ( !v30 )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), v30, -1);
    v5 = (iconWidget *)operator new(45);
    if ( v5 )
      guiObjf = (widget *)iconWidget::iconWidget(
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
      MemError();
    heroWindow::AddWidget(*(heroWindow **)(v4 + 25496), guiObjf, -1);
  }
  return result;
}