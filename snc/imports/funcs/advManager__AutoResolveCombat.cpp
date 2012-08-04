{
  void *thisa; // [sp+10h] [bp-24h]@1
  int v13; // [sp+14h] [bp-20h]@1
  tag_message v14; // [sp+18h] [bp-1Ch]@1

  thisa = this;
  gbNoShowCombat = 1;
  v13 = bShowIt;
  bShowIt = 0;
  mouseManager::SetPointer(gpMouseManager, 0);
  gpMouseManager->field_7E = 1;
  v14.eventCode = 0;
  advManager::DemobilizeCurrHero((advManager *)thisa);
  combatManager::SetupCombat(gpCombatManager, a2, a3, a4, a5, a6, a7, a2, SHIDWORD(a2), a10);
  combatManager::InitNonVisualVars(gpCombatManager);
  gpCombatManager->notHandlingInputEvent = 1;
  while ( !gpCombatManager->field_F357 )
    gpCombatManager->vtable->handleInput((baseManager *)gpCombatManager, &v14);
  gbNoShowCombat = 0;
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
  bShowIt = v13;
  if ( gbHumanPlayer[giCurPlayer] )
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
  gpMouseManager->field_7E = 0;
  return gpCombatManager->winningSide;
}