int __thiscall sub_4BDB00(void *this, int a2)
{
  signed int v2; // eax@11
  char v3; // al@11
  void *v5; // [sp+Ch] [bp-2Ch]@1
  GUIWindow *thisa; // [sp+10h] [bp-28h]@1
  int evt; // [sp+14h] [bp-24h]@6
  int v8; // [sp+18h] [bp-20h]@6
  int v9; // [sp+1Ch] [bp-1Ch]@6
  char *v10; // [sp+2Ch] [bp-Ch]@6
  int a2a; // [sp+30h] [bp-8h]@8
  int i; // [sp+34h] [bp-4h]@6

  v5 = this;
  sub_4BDA80((int)this);
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    *(_DWORD *)((char *)v5 + 54) = GUIWindow_constructorFromFile(thisa, 0, 0, "swapwin.bin");
  else
    *(_DWORD *)((char *)v5 + 54) = 0;
  if ( !*(_DWORD *)((char *)v5 + 54) )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(*(GUIWindow **)((char *)v5 + 54), 21);
  evt = 512;
  v8 = 9;
  sprintf(globBuf, "port%04d.icn", *(_BYTE *)(*(_DWORD *)((char *)v5 + 62) + 24));
  v9 = 65;
  v10 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v5 + 54), (Event *)&evt);
  sprintf(globBuf, "port%04d.icn", *(_BYTE *)(*(_DWORD *)((char *)v5 + 66) + 24));
  v9 = 66;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v5 + 54), (Event *)&evt);
  v8 = 3;
  sprintf(globBuf, "%s meets %s", *(_DWORD *)((char *)v5 + 62) + 10, *(_DWORD *)((char *)v5 + 66) + 10);
  v10 = globBuf;
  v9 = 77;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v5 + 54), (Event *)&evt);
  for ( i = 0; i < 2; ++i )
  {
    for ( a2a = 0; a2a < 8; ++a2a )
    {
      if ( *(_DWORD *)(*(_DWORD *)((char *)v5 + 4 * i + 62) + 144) <= a2a )
      {
        v8 = 6;
        v9 = a2a + 8 * i + 200;
        v10 = (char *)4;
        GUIWindow::processMessage(*(GUIWindow **)((char *)v5 + 54), (Event *)&evt);
      }
      else
      {
        v8 = 4;
        v9 = a2a + 8 * i + 200;
        v10 = (char *)sub_498B10(*(Hero **)((char *)v5 + 4 * i + 62), a2a);
        GUIWindow::processMessage(*(GUIWindow **)((char *)v5 + 54), (Event *)&evt);
        v8 = 3;
        v9 = a2a + 8 * i + 216;
        v10 = globBuf;
        v2 = sub_498B10(*(Hero **)((char *)v5 + 4 * i + 62), a2a);
        v3 = Hero::getSecondarySkillLevelWithBonii(*(Hero **)((char *)v5 + 4 * i + 62), (SECONDARY_SKILL)v2);
        sprintf(globBuf, "%d", v3);
        GUIWindow::processMessage(*(GUIWindow **)((char *)v5 + 54), (Event *)&evt);
      }
    }
  }
  evt = 512;
  v8 = 6;
  v10 = (char *)2;
  v9 = 1;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v9 = 2;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v9 = 3;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v9 = 4;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v9 = 5;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  v9 = 6;
  GUIWindow::processMessage(advManager->adventureScreen, (Event *)&evt);
  sub_4BF170(v5);
  HeroWindowManager::addWindow(HeroWindowManager::instance, *(GUIWindow **)((char *)v5 + 54), -1, 1);
  changeMenu(adventureMenu);
  dword_4F2E74 = 2;
  *(_DWORD *)((char *)v5 + 58) = ResourceManager::getIconByFilename(resourceManager, "swapbtn.icn");
  dword_4F2E74 = -1;
  MouseManager::setSpriteIdx(mouseManager, 0);
  *((_DWORD *)v5 + 3) = 256;
  *((_DWORD *)v5 + 4) = a2;
  *(_DWORD *)((char *)v5 + 50) = 1;
  strcpy((char *)v5 + 20, "swapManager");
  return 0;
}
