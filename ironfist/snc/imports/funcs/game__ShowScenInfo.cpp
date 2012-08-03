{
  signed int v1; // eax@6
  int v3; // [sp+Ch] [bp-84h]@1
  iconWidget *v4; // [sp+18h] [bp-78h]@59
  textWidget *v5; // [sp+1Ch] [bp-74h]@54
  iconWidget *v6; // [sp+20h] [bp-70h]@43
  textWidget *v7; // [sp+24h] [bp-6Ch]@37
  iconWidget *v8; // [sp+28h] [bp-68h]@31
  iconWidget *v9; // [sp+2Ch] [bp-64h]@26
  iconWidget *v10; // [sp+30h] [bp-60h]@20
  iconWidget *thisa; // [sp+34h] [bp-5Ch]@15
  heroWindow *v12; // [sp+38h] [bp-58h]@1
  char *content; // [sp+3Ch] [bp-54h]@37
  char *contenta; // [sp+3Ch] [bp-54h]@48
  signed int v15; // [sp+44h] [bp-4Ch]@50
  int evt; // [sp+48h] [bp-48h]@6
  int v17; // [sp+4Ch] [bp-44h]@6
  int v18; // [sp+50h] [bp-40h]@6
  int v19; // [sp+60h] [bp-30h]@6
  int v20; // [sp+64h] [bp-2Ch]@12
  int v21; // [sp+68h] [bp-28h]@12
  widget *guiObj; // [sp+6Ch] [bp-24h]@12
  int v23; // [sp+70h] [bp-20h]@12
  int i; // [sp+74h] [bp-1Ch]@12
  int v25; // [sp+78h] [bp-18h]@6
  int v26; // [sp+7Ch] [bp-14h]@12
  textWidget *v27; // [sp+80h] [bp-10h]@12
  int v28; // [sp+84h] [bp-Ch]@12
  bool v29; // [sp+88h] [bp-8h]@78
  heroWindow *a2; // [sp+8Ch] [bp-4h]@2

  v3 = (int)this;
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  v12 = (heroWindow *)operator new(68);
  if ( v12 )
    a2 = heroWindow::heroWindow(v12, 90, 4, "sceninfo.bin");
  else
    a2 = 0;
  if ( !a2 )
    MemError();
  SetWinText(a2, 23);
  evt = 512;
  v17 = 3;
  v18 = 64;
  v19 = v3 + 739;
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  v18 = 200;
  v19 = (int)cDifficulty[*(_BYTE *)(v3 + 685)];
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  v18 = 201;
  v19 = (int)cDifficulty[*(_BYTE *)(v3 + 1125)];
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  v1 = game::CalcDifficultyRating(v3);
  sprintf(gText, "%d", v1);
  strcat(gText, L"%");
  v18 = 202;
  v19 = (int)gText;
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
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
  v19 = (int)cMapSize[v25];
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  v18 = 204;
  v19 = v3 + 799;
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  game::GetVictoryConditionText(v3, gText);
  v18 = 205;
  v19 = (int)gText;
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  game::GetLossConditionText(v3, gText);
  v18 = 206;
  v19 = (int)gText;
  heroWindow::BroadcastMessage(a2, (Event *)&evt);
  guiObj = 0;
  v27 = 0;
  v23 = 372 - 62 * *(_BYTE *)(v3 + 707);
  v28 = v23 / (*(_BYTE *)(v3 + 707) + 1);
  v26 = v28 + 24;
  v21 = v28 + 62;
  v20 = 0;
  for ( i = 0; *(_BYTE *)(v3 + 707) > i; ++i )
  {
    if ( iLastMsgNumHumanPlayers > 1 )
    {
      thisa = (iconWidget *)operator new(45);
      if ( thisa )
        guiObj = (widget *)iconWidget::iconWidget(
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
        MemError();
      heroWindow::AddWidget(a2, guiObj, -1);
      v10 = (iconWidget *)operator new(45);
      if ( v10 )
        guiObj = (widget *)iconWidget::iconWidget(
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
        MemError();
      heroWindow::AddWidget(a2, guiObj, -1);
    }
    v9 = (iconWidget *)operator new(45);
    if ( v9 )
      guiObj = (widget *)iconWidget::iconWidget(
                           v9,
                           (_WORD)v26 + i * (_WORD)v21 + 11,
                           163,
                           68,
                           iLastMsgNumHumanPlayers <= 1 ? 47 : 64,
                           "ngextra.icn",
                           iLastMsgNumHumanPlayers <= 1 ? 79 : 60,
                           0,
                           i + 6,
                           16,
                           1);
    else
      guiObj = 0;
    if ( !guiObj )
      MemError();
    heroWindow::AddWidget(a2, guiObj, -1);
    v8 = (iconWidget *)operator new(45);
    if ( v8 )
      guiObj = (widget *)iconWidget::iconWidget(
                           v8,
                           (_WORD)v26 + i * (_WORD)v21 + 16,
                           160,
                           62,
                           58,
                           "ngextra.icn",
                           iLastMsgNumHumanPlayers <= 1 ? 3 : 27,
                           0,
                           i + 12,
                           16,
                           1);
    else
      guiObj = 0;
    if ( !guiObj )
      MemError();
    heroWindow::AddWidget(a2, guiObj, -1);
    if ( iLastMsgNumHumanPlayers > 1 )
    {
      content = (char *)BaseAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511448 + 114);
      sprintf(content, L" ");
      v7 = (textWidget *)operator new(43);
      if ( v7 )
        v27 = textWidget::textWidget(
                v7,
                (_WORD)v26 + i * (_WORD)v21 + 19,
                206,
                56,
                9,
                content,
                "smalfont.fnt",
                1,
                i + 24,
                512,
                1);
      else
        v27 = 0;
      if ( !v27 )
        MemError();
      heroWindow::AddWidget(a2, (widget *)v27, -1);
    }
    v6 = (iconWidget *)operator new(45);
    if ( v6 )
      guiObj = (widget *)iconWidget::iconWidget(
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
      MemError();
    heroWindow::AddWidget(a2, guiObj, -1);
    contenta = (char *)BaseAlloc(2u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_511448 + 146);
    sprintf(contenta, L"A");
    if ( (signed int)*(_BYTE *)(v3 + 707) < 5 )
    {
      v15 = 26;
    }
    else if ( (signed int)*(_BYTE *)(v3 + 707) < 6 )
    {
      v15 = 16;
    }
    else
    {
      v15 = 0;
    }
    v5 = (textWidget *)operator new(43);
    if ( v5 )
      v27 = textWidget::textWidget(
              v5,
              (_WORD)v26 + i * (_WORD)v21 + 15 - v15 / 2,
              v20 + 288,
              v15 + 64,
              12,
              contenta,
              "smalfont.fnt",
              1,
              i + 78,
              512,
              1);
    else
      v27 = 0;
    if ( !v27 )
      MemError();
    heroWindow::AddWidget(a2, (widget *)v27, -1);
    v4 = (iconWidget *)operator new(45);
    if ( v4 )
      guiObj = (widget *)iconWidget::iconWidget(
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
      MemError();
    heroWindow::AddWidget(a2, guiObj, -1);
  }
  for ( i = 0; *(_BYTE *)(v3 + 707) > i; ++i )
  {
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
    {
      sprintf(gText, byte_511520);
    }
    else if ( strlen((int)&cPlayerNames[21 * *(_BYTE *)(i + v3 + 1119)]) )
    {
      sprintf(gText, &cPlayerNames[21 * *(_BYTE *)(i + v3 + 1119)]);
    }
    else
    {
      sprintf(gText, "Player %d", *(_BYTE *)(i + v3 + 1119) + 1);
    }
    v17 = 3;
    v18 = i + 24;
    v19 = (int)gText;
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    if ( *(_BYTE *)(v3 + 1145) == i )
      v17 = 5;
    else
      v17 = 6;
    v18 = i + 18;
    v19 = 4;
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    v29 = !*(_BYTE *)(i + v3 + 1139) && (iLastMsgNumHumanPlayers <= 1 || *(_BYTE *)(i + v3 + 1119) == 10);
    v17 = 4;
    v18 = i + 12;
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
      v19 = ((unsigned int)v29 < 1 ? 3 : 15) + *(_BYTE *)(i + v3 + 1101);
    else
      v19 = ((unsigned int)v29 < 1 ? 9 : 21) + *(_BYTE *)(i + v3 + 1101);
    if ( iLastMsgNumHumanPlayers > 1 )
      v19 += 24;
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    if ( v29 )
      v17 = 6;
    else
      v17 = 5;
    v19 = 2;
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    v17 = 4;
    v18 = i + 48;
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
      v19 = 78;
    else
      v19 = *(_BYTE *)(i + v3 + 1107);
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    if ( *(_BYTE *)(i + v3 + 1119) == 10 )
      v17 = 6;
    else
      v17 = 5;
    v19 = 2;
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    v17 = 4;
    v18 = i + 36;
    v19 = ((unsigned int)v29 < 1 ? 51 : 70) + *(_BYTE *)(i + v3 + 1113);
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
    sprintf(gText, (&gAlignmentNames)[4 * *(_BYTE *)(i + v3 + 1113)]);
    v17 = 3;
    v18 = i + 78;
    v19 = (int)gText;
    heroWindow::BroadcastMessage(a2, (Event *)&evt);
  }
  heroWindowManager::DoDialog(gpWindowManager, a2, EventWindowHandler, 0);
  return operator delete(a2);
}