{
  combatManager *result; // eax@36
  combatManager *v2; // [sp+Ch] [bp-68h]@1
  heroWindow *thisa; // [sp+18h] [bp-5Ch]@16
  char v4; // [sp+1Ch] [bp-58h]@12
  int evt; // [sp+50h] [bp-24h]@33
  int v6; // [sp+54h] [bp-20h]@33
  int v7; // [sp+58h] [bp-1Ch]@33
  char *v8; // [sp+68h] [bp-Ch]@33
  int v9; // [sp+6Ch] [bp-8h]@1
  bool side; // [sp+70h] [bp-4h]@3

  v2 = this;
  v9 = 0;
  if ( this->playerID[0] == giCurPlayer && *(&gbThisNetHumanPlayer + this->playerID[0]) )
  {
    side = 0;
  }
  else if ( this->playerID[1] == giCurPlayer && *(&gbThisNetHumanPlayer + this->playerID[1]) )
  {
    side = 1;
  }
  else
  {
    side = this->playerID[0] == -1 || !*(&gbThisNetHumanPlayer + this->playerID[0]);
  }
  dword_524C90 = 1;
  if ( gbCombatSurrender )
  {
    sprintf(&v4, "cmbtsurr.icn");
    gbWhichAnimationPlaying = 4;
  }
  else if ( gbRetreatWin )
  {
    sprintf(&v4, "cmbtfle1.icn");
    gbWhichAnimationPlaying = 3;
  }
  else
  {
    sprintf(&v4, "cmbtlos1.icn");
    gbWhichAnimationPlaying = 2;
  }
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    v2->combatEndWindow = heroWindow::heroWindow(thisa, 143, 10, "wincmbt.bin");
  else
    v2->combatEndWindow = 0;
  if ( !v2->combatEndWindow )
    MemError();
  if ( v2->heroes[side] )
  {
    if ( gbCombatSurrender )
    {
      sprintf(gText, off_4F6878, v2->heroes[side]->name);
    }
    else if ( gbRetreatWin )
    {
      sprintf(gText, off_4F687C, v2->heroes[side]->name);
    }
    else
    {
      sprintf(gText, off_4F6880, v2->heroes[side]->name);
    }
  }
  else if ( gbCombatSurrender )
  {
    sprintf(gText, off_4F6884);
  }
  else if ( gbRetreatWin )
  {
    sprintf(gText, off_4F6888);
  }
  else
  {
    sprintf(gText, off_4F688C);
  }
  evt = 512;
  v6 = 9;
  v7 = 200;
  v8 = &v4;
  heroWindow::BroadcastMessage(v2->combatEndWindow, (Event *)&evt);
  v7 = 201;
  v8 = &v4;
  heroWindow::BroadcastMessage(v2->combatEndWindow, (Event *)&evt);
  evt = 512;
  v6 = 3;
  v7 = 101;
  v8 = gText;
  heroWindow::BroadcastMessage(v2->combatEndWindow, (Event *)&evt);
  combatManager::ShowDeadArmies(v2, v2->combatEndWindow);
  if ( gbRemoteOn && !gbThisNetGotAdventureControl )
    giDialogTimeout = KBTickCount() + 15000;
  heroWindowManager::DoDialog(
    gpWindowManager,
    v2->combatEndWindow,
    (int (__fastcall *)(tag_message *))WinCombatHandler,
    0);
  giDialogTimeout = 0;
  operator delete(v2->combatEndWindow);
  result = v2;
  v2->combatEndWindow = NULL;
  return result;
}