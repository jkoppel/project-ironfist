CombatManager *__thiscall CombatManager::informLostBattle(CombatManager *this)
{
  CombatManager *result; // eax@36
  CombatManager *v2; // [sp+Ch] [bp-68h]@1
  GUIWindow *thisa; // [sp+18h] [bp-5Ch]@16
  char v4; // [sp+1Ch] [bp-58h]@12
  int evt; // [sp+50h] [bp-24h]@33
  int v6; // [sp+54h] [bp-20h]@33
  int v7; // [sp+58h] [bp-1Ch]@33
  char *v8; // [sp+68h] [bp-Ch]@33
  int v9; // [sp+6Ch] [bp-8h]@1
  bool side; // [sp+70h] [bp-4h]@3

  v2 = this;
  v9 = 0;
  if ( this->playerID[0] == curPlayerIdx && *(&byte_524758 + this->playerID[0]) )
  {
    side = 0;
  }
  else
  {
    if ( this->playerID[1] == curPlayerIdx && *(&byte_524758 + this->playerID[1]) )
      side = 1;
    else
      side = this->playerID[0] == -1 || !*(&byte_524758 + this->playerID[0]);
  }
  dword_524C90 = 1;
  if ( isSurrendering )
  {
    sprintf(&v4, "cmbtsurr.icn");
    dword_524C70 = 4;
  }
  else
  {
    if ( isRetreating )
    {
      sprintf(&v4, "cmbtfle1.icn");
      dword_524C70 = 3;
    }
    else
    {
      sprintf(&v4, "cmbtlos1.icn");
      dword_524C70 = 2;
    }
  }
  thisa = (GUIWindow *)operator new(68);
  if ( thisa )
    v2->combatEndWindow = GUIWindow_constructorFromFile(thisa, 143, 10, "wincmbt.bin");
  else
    v2->combatEndWindow = 0;
  if ( !v2->combatEndWindow )
    fatalOutOfMemoryError();
  if ( v2->heroes[side] )
  {
    if ( isSurrendering )
    {
      sprintf(globBuf, off_4F6878, v2->heroes[side]->name);
    }
    else
    {
      if ( isRetreating )
        sprintf(globBuf, off_4F687C, v2->heroes[side]->name);
      else
        sprintf(globBuf, off_4F6880, v2->heroes[side]->name);
    }
  }
  else
  {
    if ( isSurrendering )
    {
      sprintf(globBuf, off_4F6884);
    }
    else
    {
      if ( isRetreating )
        sprintf(globBuf, off_4F6888);
      else
        sprintf(globBuf, off_4F688C);
    }
  }
  evt = 512;
  v6 = 9;
  v7 = 200;
  v8 = &v4;
  GUIWindow::processMessage(v2->combatEndWindow, (Event *)&evt);
  v7 = 201;
  v8 = &v4;
  GUIWindow::processMessage(v2->combatEndWindow, (Event *)&evt);
  evt = 512;
  v6 = 3;
  v7 = 101;
  v8 = globBuf;
  GUIWindow::processMessage(v2->combatEndWindow, (Event *)&evt);
  CombatManager::addCasualtyInfoToWindow(v2, v2->combatEndWindow);
  if ( dword_4F7494 && !dword_523ED4 )
    dword_4F1CB4 = getTickCount() + 15000;
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    v2->combatEndWindow,
    (int (__fastcall *)(InputEvent *))sub_43DE80,
    0);
  dword_4F1CB4 = 0;
  operator delete(v2->combatEndWindow);
  result = v2;
  v2->combatEndWindow = NULL;
  return result;
}
