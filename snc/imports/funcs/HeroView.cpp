{
  int v3; // ST1C_4@1
  signed int result; // eax@12
  heroWindow *this; // [sp+1Ch] [bp-8h]@3
  mapCell *v6; // [sp+20h] [bp-4h]@9

  v3 = a1;
  gbNoDismiss = a2;
  iOrigHeroViewID = a1;
  advManager::TrimLoopingSounds(gpAdvManager, 4);
  gpHVHero = &gpGame->heroes[v3];
  dword_4F7458 = 1;
  if ( !a3 )
    heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  this = (heroWindow *)operator new(68);
  if ( this )
    heroWin = heroWindow::heroWindow(this, 0, 0, "herowind.bin");
  else
    heroWin = 0;
  if ( !heroWin )
    MemError();
  SetWinText(heroWin, 6);
  gheroWin = heroWin;
  if ( gpHVHero->couldBeHeroIdx == gpCurPlayer->curHeroIdx )
  {
    v6 = advManager::GetCell(gpAdvManager, gpHVHero->x, gpHVHero->y);
    if ( v6->objType != 170 )
    {
      gpHVHero->occupiedObjType = v6->objType;
      gpHVHero->occupiedObjVal = (unsigned __int8)((unsigned __int8)(v6->flags >> 8) >> -5);
    }
  }
  SetupHeroView();
  RedrawHeroScreen();
  heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
  heroWindowManager::DoDialog(gpWindowManager, heroWin, (int (__fastcall *)(tag_message *))HeroHandler, 0);
  heroWindowManager::FadeScreen(gpWindowManager, 1, 8, 0);
  operator delete(heroWin);
  gheroWin = 0;
  if ( gpWindowManager->buttonPressedCode == 30723 )
  {
    result = 1;
  }
  else
  {
    *(_DWORD *)&gpHVHero->field_31 = hero::CalcMobility(gpHVHero);
    dword_4F7458 = 0;
    gpHVHero = 0;
    result = 0;
  }
  return result;
}