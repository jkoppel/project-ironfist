{
  int v6; // ebx@1
  int v7; // edx@1
  int v8; // ebp@1
  int v9; // eax@3
  int v10; // eax@5
  int v11; // ebp@7
  heroWindow *v12; // eax@7
  const char *v13; // edi@12
  int v14; // esi@16
  int v15; // ecx@16
  int evt; // [sp+10h] [bp-9Ch]@12
  int v17; // [sp+14h] [bp-98h]@12
  int v18; // [sp+18h] [bp-94h]@12
  char *v19; // [sp+28h] [bp-84h]@12
  char *msg; // [sp+2Ch] [bp-80h]@1
  signed int protoCategory; // [sp+30h] [bp-7Ch]@1
  int spriteIdx; // [sp+34h] [bp-78h]@1
  char filename; // [sp+38h] [bp-74h]@7
  char v24; // [sp+48h] [bp-64h]@14
  int v25; // [sp+B8h] [bp+Ch]@14

  msg = (char *)a1;
  v6 = a2;
  v7 = gpMouseManager->spriteIdx;
  v8 = gpMouseManager->cursorDisabled;
  protoCategory = gpMouseManager->cursorCategory;
  spriteIdx = v7;
  if ( v8 )
  {
    do
      mouseManager::ShowColorPointer(gpMouseManager);
    while ( gpMouseManager->cursorDisabled );
  }
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  cDEDest = (char *)v6;
  iDEMaxLen = a3;
  strcpy((char *)v6, (const char *)&unk_51F104);
  v9 = 16 * font::LineLength(bigFont, msg, 240);
  if ( a5 )
    v9 += 39;
  v10 = (v9 + 15) / 45;
  if ( v10 > 6 )
    v10 = 6;
  v11 = 45 * v10 - (a5 < 1 ? 0 : 0x1E) + 95;
  sprintf(&filename, "evntwin%d.bin", v10);
  v12 = (heroWindow *)operator new(68);
  if ( v12 )
    DataEntryWin = heroWindow::heroWindow(v12, 177, 20, &filename);
  else
    DataEntryWin = 0;
  if ( !DataEntryWin )
    MemError();
  v19 = msg;
  evt = 512;
  v17 = 3;
  v18 = 1;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  v13 = a4;
  if ( !a4 )
    v13 = (const char *)&unk_51F118;
  strcpy(&v24, v13);
  v19 = &v24;
  v18 = 10;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  strcpy((char *)v6, &v24);
  v17 = 6;
  v19 = (char *)6;
  evt = 512;
  v18 = 30721;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  v18 = 30727;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  v18 = 30728;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  v18 = 30725;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  v18 = 30726;
  heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  if ( !v25 )
  {
    v18 = 30722;
    heroWindow::BroadcastMessage((heroWindow *)DataEntryWin, (Event *)&evt);
  }
  v14 = 0;
  v15 = (int)operator new(78);
  if ( v15 )
    v14 = textEntryWidget::textEntryWidget(
            v15,
            35,
            v11,
            251,
            20,
            a3,
            v6,
            "bigfont.fnt",
            0,
            "buybuild.icn",
            3,
            10,
            0,
            4,
            10,
            3);
  if ( !v14 )
    MemError();
  inBoxX = 213;
  inBoxY = v11 + 23;
  heroWindow::AddWidget((heroWindow *)DataEntryWin, (widget *)v14, -1);
  if ( a6 )
  {
    bDataEntryTime = 0;
    gbAllowTextEntryEscape = 0;
  }
  else
  {
    bDataEntryTime = 2;
  }
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)DataEntryWin,
    (int (__fastcall *)(tag_message *))DataEntryWindowHandler,
    0);
  operator delete(DataEntryWin);
  mouseManager::SetPointer(gpMouseManager, byte_51F138, spriteIdx, protoCategory);
  gbAllowTextEntryEscape = 1;
}