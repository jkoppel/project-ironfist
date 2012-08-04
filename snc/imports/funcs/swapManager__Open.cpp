{
  signed int v2; // eax@11
  char v3; // al@11
  void *v5; // [sp+Ch] [bp-2Ch]@1
  heroWindow *thisa; // [sp+10h] [bp-28h]@1
  int evt; // [sp+14h] [bp-24h]@6
  int v8; // [sp+18h] [bp-20h]@6
  int v9; // [sp+1Ch] [bp-1Ch]@6
  char *v10; // [sp+2Ch] [bp-Ch]@6
  int a2a; // [sp+30h] [bp-8h]@8
  int i; // [sp+34h] [bp-4h]@6

  v5 = this;
  swapManager::Reset((int)this);
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    *(_DWORD *)((char *)v5 + 54) = heroWindow::heroWindow(thisa, 0, 0, "swapwin.bin");
  else
    *(_DWORD *)((char *)v5 + 54) = 0;
  if ( !*(_DWORD *)((char *)v5 + 54) )
    MemError();
  SetWinText(*(heroWindow **)((char *)v5 + 54), 21);
  evt = 512;
  v8 = 9;
  sprintf(gText, "port%04d.icn", *(_BYTE *)(*(_DWORD *)((char *)v5 + 62) + 24));
  v9 = 65;
  v10 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v5 + 54), (Event *)&evt);
  sprintf(gText, "port%04d.icn", *(_BYTE *)(*(_DWORD *)((char *)v5 + 66) + 24));
  v9 = 66;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v5 + 54), (Event *)&evt);
  v8 = 3;
  sprintf(gText, "%s meets %s", *(_DWORD *)((char *)v5 + 62) + 10, *(_DWORD *)((char *)v5 + 66) + 10);
  v10 = gText;
  v9 = 77;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v5 + 54), (Event *)&evt);
  for ( i = 0; i < 2; ++i )
  {
    for ( a2a = 0; a2a < 8; ++a2a )
    {
      if ( *(_DWORD *)(*(_DWORD *)((char *)v5 + 4 * i + 62) + 144) <= a2a )
      {
        v8 = 6;
        v9 = a2a + 8 * i + 200;
        v10 = (char *)4;
        heroWindow::BroadcastMessage(*(heroWindow **)((char *)v5 + 54), (Event *)&evt);
      }
      else
      {
        v8 = 4;
        v9 = a2a + 8 * i + 200;
        v10 = (char *)hero::GetNthSS(*(hero **)((char *)v5 + 4 * i + 62), a2a);
        heroWindow::BroadcastMessage(*(heroWindow **)((char *)v5 + 54), (Event *)&evt);
        v8 = 3;
        v9 = a2a + 8 * i + 216;
        v10 = gText;
        v2 = hero::GetNthSS(*(hero **)((char *)v5 + 4 * i + 62), a2a);
        v3 = hero::GetSSLevel(*(hero **)((char *)v5 + 4 * i + 62), (SECONDARY_SKILL)v2);
        sprintf(gText, "%d", v3);
        heroWindow::BroadcastMessage(*(heroWindow **)((char *)v5 + 54), (Event *)&evt);
      }
    }
  }
  evt = 512;
  v8 = 6;
  v10 = (char *)2;
  v9 = 1;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v9 = 2;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v9 = 3;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v9 = 4;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v9 = 5;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  v9 = 6;
  heroWindow::BroadcastMessage(gpAdvManager->adventureScreen, (Event *)&evt);
  swapManager::Update(v5);
  heroWindowManager::AddWindow(gpWindowManager, *(heroWindow **)((char *)v5 + 54), -1, 1);
  KBChangeMenu(hmnuAdv);
  giMonoIconSkip = 2;
  *(_DWORD *)((char *)v5 + 58) = resourceManager::GetIcon(gpResourceManager, "swapbtn.icn");
  giMonoIconSkip = -1;
  mouseManager::SetPointer(gpMouseManager, 0);
  *((_DWORD *)v5 + 3) = 256;
  *((_DWORD *)v5 + 4) = a2;
  *(_DWORD *)((char *)v5 + 50) = 1;
  strcpy((char *)v5 + 20, "swapManager");
  return 0;
}