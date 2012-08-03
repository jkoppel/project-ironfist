{
  int v1; // eax@24
  int v2; // eax@36
  void *v3; // [sp+Ch] [bp-44h]@1
  iconWidget *v4; // [sp+18h] [bp-38h]@15
  heroWindow *thisa; // [sp+1Ch] [bp-34h]@10
  int evt; // [sp+20h] [bp-30h]@1
  int v7; // [sp+24h] [bp-2Ch]@30
  int v8; // [sp+28h] [bp-28h]@30
  char *v9; // [sp+38h] [bp-18h]@30
  int j; // [sp+3Ch] [bp-14h]@4
  int i; // [sp+40h] [bp-10h]@1
  char v12[8]; // [sp+44h] [bp-Ch]@20
  int v13; // [sp+4Ch] [bp-4h]@20

  v3 = this;
  giOverviewReturnAction = -1;
  giOverviewReturnActionExtra = -1;
  evt = 512;
  advManager::TrimLoopingSounds(gpAdvManager, 4);
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  for ( i = 0; i < 3; ++i )
    textWidgetTitle[i] = 0;
  textWidgetDynamic = BaseAlloc(0x2BC0u, "F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 17);
  iconWidgetDynamic = BaseAlloc(0x2BC0u, "F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 18);
  for ( j = 0; j < 4; ++j )
  {
    for ( i = 0; i < 70; ++i )
    {
      *((_DWORD *)textWidgetDynamic + 70 * j + i) = 0;
      *((_DWORD *)iconWidgetDynamic + 70 * j + i) = 0;
    }
  }
  iLastDynamicType = -1;
  iLastDynamicTop = -1;
  giOverviewItems[0] = gpCurPlayer->numHeroes;
  dword_52520C = gpCurPlayer->numCastles;
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  resourceManager::GetBackdrop(gpResourceManager, "overback.icn", gpWindowManager->screenBuffer, 1);
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    overWin = heroWindow::heroWindow(thisa, 0, 0, "overwind.bin");
  else
    overWin = 0;
  if ( !overWin )
    MemError();
  SetWinText(overWin, 9);
  v4 = (iconWidget *)operator new(45);
  if ( v4 )
    OVScrollKnob = (widget *)iconWidget::iconWidget(v4, 629, 18, 8, 17, "scrollcn.icn", 4, 0, 111, 16, 1);
  else
    OVScrollKnob = 0;
  if ( !OVScrollKnob )
    MemError();
  heroWindow::AddWidget(overWin, OVScrollKnob, -1);
  game::SetupResources();
  memset(v12, 0, 7u);
  v13 = 0;
  for ( i = 0; i < 144; ++i )
  {
    if ( *((_BYTE *)v3 + i + 24742) == giCurPlayer )
    {
      if ( (signed int)*((_BYTE *)v3 + 7 * i + 23736) > 6 )
      {
        if ( *((_BYTE *)v3 + 7 * i + 23736) == 100 )
          ++v13;
      }
      else
      {
        v1 = *((_BYTE *)v3 + 7 * i + 23736);
        ++v12[v1];
      }
    }
  }
  for ( i = 0; i < 7; ++i )
  {
    v7 = 3;
    v9 = gText;
    sprintf(gText, "%d", v12[i]);
    v8 = i + 20;
    heroWindow::BroadcastMessage(overWin, (Event *)&evt);
  }
  for ( i = 4; i > 0; --i )
  {
    if ( v13 < i )
    {
      v7 = 6;
      v8 = i + 49;
      v9 = (char *)4;
      heroWindow::BroadcastMessage(overWin, (Event *)&evt);
    }
  }
  game::SetupResources();
  v7 = 3;
  v8 = 40;
  v9 = gText;
  v2 = game::ComputeDailyGold((game *)v3, giCurPlayer);
  sprintf(gText, "%d", v2);
  heroWindow::BroadcastMessage(overWin, (Event *)&evt);
  game::SetupNewOverviewType(v3, giOverviewType, 0);
  heroWindowManager::DoDialog(gpWindowManager, overWin, (int (__fastcall *)(tag_message *))OverviewHandler, 1);
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  operator delete(overWin);
  overWin = 0;
  BaseFree(textWidgetDynamic, (int)"F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 104);
  BaseFree(iconWidgetDynamic, (int)"F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 105);
  textWidgetDynamic = 0;
  iconWidgetDynamic = 0;
}