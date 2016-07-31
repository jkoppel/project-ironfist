{
  int v1; // eax@24
  int v2; // eax@36
  void *v3; // [sp+Ch] [bp-44h]@1
  GUIIcon *v4; // [sp+18h] [bp-38h]@15
  GUIWindow *thisa; // [sp+1Ch] [bp-34h]@10
  int evt; // [sp+20h] [bp-30h]@1
  int v7; // [sp+24h] [bp-2Ch]@30
  int v8; // [sp+28h] [bp-28h]@30
  char *v9; // [sp+38h] [bp-18h]@30
  int j; // [sp+3Ch] [bp-14h]@4
  int i; // [sp+40h] [bp-10h]@1
  char v12[8]; // [sp+44h] [bp-Ch]@20
  int v13; // [sp+4Ch] [bp-4h]@20

  v3 = this;
  dword_524238 = -1;
  dword_5247B4 = -1;
  evt = 512;
  sub_456000(advManager, 4);
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  for ( i = 0; i < 3; ++i )
    dword_525218[i] = 0;
  dword_511E5C = KBAlloc(0x2BC0u, "F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 17);
  dword_511E60 = KBAlloc(0x2BC0u, "F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 18);
  for ( j = 0; j < 4; ++j )
  {
    for ( i = 0; i < 70; ++i )
    {
      *((_DWORD *)dword_511E5C + 70 * j + i) = 0;
      *((_DWORD *)dword_511E60 + 70 * j + i) = 0;
    }
  }
  dword_525214 = -1;
  dword_525210 = -1;
  dword_525208[0] = curPlayer->numHeroes;
  dword_52520C = curPlayer->numCastles;
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  ResourceManager::dumpImageToScreen(resourceManager, "overback.icn", HeroWindowManager::instance->screenBuffer, 1);
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    dword_511E58 = GUIWindow_constructorFromFile(thisa, 0, 0, "overwind.bin");
  else
    dword_511E58 = 0;
  if ( !dword_511E58 )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(dword_511E58, 9);
  v4 = (GUIIcon *)operator new(0x2Du);
  if ( v4 )
    dword_511E70 = (AbstractGUIComponent *)GUIIcon_constructor(v4, 629, 18, 8, 17, "scrollcn.icn", 4, 0, 111, 16, 1);
  else
    dword_511E70 = 0;
  if ( !dword_511E70 )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(dword_511E58, dword_511E70, -1);
  sub_4624F0();
  memset(v12, 0, 7u);
  v13 = 0;
  for ( i = 0; i < 144; ++i )
  {
    if ( *((_BYTE *)v3 + i + 24742) == curPlayerIdx )
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
    v9 = globBuf;
    sprintf(globBuf, "%d", v12[i]);
    v8 = i + 20;
    GUIWindow::processMessage(dword_511E58, (Event *)&evt);
  }
  for ( i = 4; i > 0; --i )
  {
    if ( v13 < i )
    {
      v7 = 6;
      v8 = i + 49;
      v9 = (char *)4;
      GUIWindow::processMessage(dword_511E58, (Event *)&evt);
    }
  }
  sub_4624F0();
  v7 = 3;
  v8 = 40;
  v9 = globBuf;
  v2 = GameInfo::computePlayerIncome((GameInfo *)v3, curPlayerIdx);
  sprintf(globBuf, "%d", v2);
  GUIWindow::processMessage(dword_511E58, (Event *)&evt);
  sub_462190(v3, dword_511E64, 0);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_511E58,
    (int (__fastcall *)(InputEvent *))sub_462D50,
    1);
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  operator delete(dword_511E58);
  dword_511E58 = 0;
  KBFree(dword_511E5C, (int)"F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 104);
  KBFree(dword_511E60, (int)"F:\\h2xsrc\\Source\\Overview.cpp", word_512108 + 105);
  dword_511E5C = 0;
  dword_511E60 = 0;
}
