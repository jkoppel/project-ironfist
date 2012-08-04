{
  int v12; // edx@18
  void *thisa; // [sp+14h] [bp-70h]@1
  tag_message a2a; // [sp+18h] [bp-6Ch]@32
  void *v15; // [sp+34h] [bp-50h]@20
  void *a1; // [sp+38h] [bp-4Ch]@20
  void *v17; // [sp+3Ch] [bp-48h]@20
  void *v18; // [sp+40h] [bp-44h]@20
  void *v19; // [sp+44h] [bp-40h]@20
  int v20; // [sp+48h] [bp-3Ch]@18
  char v21; // [sp+4Ch] [bp-38h]@20
  char v22; // [sp+50h] [bp-34h]@32
  char v23; // [sp+6Ch] [bp-18h]@20
  int v24; // [sp+70h] [bp-14h]@13
  int v25; // [sp+74h] [bp-10h]@7
  int v26; // [sp+78h] [bp-Ch]@13
  int v27; // [sp+80h] [bp-4h]@4

  thisa = this;
  if ( giDebugLevel == 4 )
    return advManager::AutoResolveCombat(this, a2, a3, (int)a4, a5, a6, (int)a7, a8, a9, a10, a11);
  dword_4F7474 = 1;
  if ( a3 )
    v27 = *(_BYTE *)(a3 + 3);
  else
    v27 = -1;
  if ( a6 )
  {
    v25 = *(_BYTE *)(a6 + 3);
  }
  else if ( a5 )
  {
    v25 = *(_BYTE *)(a5 + 1);
  }
  else
  {
    v25 = -1;
  }
  if ( a10 == -1 )
    a10 = Random(1, 1000);
  advManager::DemobilizeCurrHero((advManager *)thisa);
  v26 = giCurPlayer;
  v24 = bShowIt;
  if ( v27 < 0 || v25 < 0 || !gbHumanPlayer[v25] )
    goto LABEL_36;
  if ( *(&gbThisNetHumanPlayer + v25) )
  {
    if ( !*(&gbThisNetHumanPlayer + v27) )
    {
      bShowIt = 1;
      game::TurnOffAIMusic();
      sprintf(gText, "%s's %s is under attack!", &cPlayerNames[21 * v25], &aTown_1[("Hero" - "Town") & ((a5 != 0) - 1)]);
      game::WaitForPlayer((int)gText, v25);
    }
    goto LABEL_36;
  }
  iCombatControlNetPos = giThisNetPos;
  dword_523434 = *((_BYTE *)&gbGamePosToNetPos + v25);
  advManager::SendHeroTownData(
    a2,
    SBYTE4(a2),
    a3,
    a4,
    (const void *)a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    *((_BYTE *)&gbGamePosToNetPos + v25),
    0,
    0,
    0);
  if ( gbHumanPlayer[v27] )
  {
LABEL_36:
    bShowIt = 1;
    combatManager::SetupCombat(gpCombatManager, a2, a3, (int)a4, a5, a6, (int)a7, a2, SHIDWORD(a2), a10);
    if ( giHighMemBuffer <= 2900 )
    {
      if ( giHighMemBuffer > 900 )
        gAdvDisposeLevel = 1;
    }
    else
    {
      gAdvDisposeLevel = 2;
    }
    executive::CallManager(gpExec, (baseManager *)gpCombatManager);
    mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
    gAdvDisposeLevel = 0;
    goto LABEL_41;
  }
  while ( 1 )
  {
    PollSound();
    FillBitmapArea(gpWindowManager->screenBuffer, 30, 30, 4u, 4, 0);
    v20 = advManager::CheckHandleNet((advManager *)thisa, v12);
    if ( v20 )
    {
      if ( *(_BYTE *)(v20 + 6) == 21 )
        break;
    }
    Process1WindowsMessage();
    memcpy(&v22, inputManager::GetEvent(gpInputManager, &a2a), 0x1Cu);
    advManager::CheckHandleNetPlayerWait(thisa, (int)&v22, 1);
  }
  advManager::ReceiveHeroTownData(
    v20,
    (int)&v21,
    (int)&a2,
    (int)((char *)&a2 + 4),
    &v18,
    &a1,
    &v19,
    &v17,
    &v15,
    (int)&a8,
    (int)&a9,
    (int)&a10,
    (int)&v23,
    (int)&gbRetreatWin,
    (int)&gbCombatSurrender);
  if ( a1 )
  {
    memcpy((void *)a4, a1, 0xFu);
    BaseFree(a1, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 113);
  }
  if ( v15 )
  {
    memcpy((void *)a7, v15, 0xFu);
    BaseFree(v15, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 119);
  }
  if ( v19 )
  {
    memcpy((void *)a5, v19, 0x64u);
    BaseFree(v19, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 125);
  }
  if ( v17 )
  {
    memcpy((void *)a6, v17, 0xFAu);
    BaseFree(v17, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 131);
  }
  if ( v18 )
  {
    memcpy((void *)a3, v18, 0xFAu);
    BaseFree(v18, (int)"F:\\h2xsrc\\Source\\EVENTS.CPP", word_518BF4 + 137);
  }
  gpCombatManager->winningSide = v23;
LABEL_41:
  if ( a3 )
    hero::CheckLevel((hero *)a3);
  if ( a6 )
    hero::CheckLevel((hero *)a6);
  if ( a11 )
  {
    switch ( gpCombatManager->winningSide + 1 )
    {
      case 1:
        if ( !gbRetreatWin )
          advManager::TransferArtifacts(a6, a3);
        advManager::HeroLoses((int)thisa, a6);
        break;
      case 2:
        if ( !gbRetreatWin )
          advManager::TransferArtifacts(a3, a6);
        advManager::HeroLoses((int)thisa, a3);
        break;
      case 0:
        advManager::HeroLoses((int)thisa, a3);
        advManager::HeroLoses((int)thisa, a6);
        break;
      case 4:
        break;
    }
  }
  bShowIt = v24;
  giCurPlayer = v26;
  if ( gbHumanPlayer[v26] )
  {
    SetNoDialogMenus(1);
  }
  else
  {
    game::ShowComputerScreen();
    game::TurnOnAIMusic();
    SetNoDialogMenus(0);
  }
  advManager::MobilizeCurrHero((advManager *)thisa, 0);
  if ( a11 )
    gbRetreatWin = 0;
  dword_4F7474 = 0;
  while ( gpMouseManager->cursorDisabled )
    mouseManager::ShowColorPointer(gpMouseManager);
  return gpCombatManager->winningSide;
}