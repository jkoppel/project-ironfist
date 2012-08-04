{
  void *v2; // [sp+18h] [bp-54h]@1
  int v3; // [sp+1Ch] [bp-50h]@22
  char v4; // [sp+20h] [bp-4Ch]@21
  int v5; // [sp+48h] [bp-24h]@22
  int evt; // [sp+4Ch] [bp-20h]@21
  int v7; // [sp+50h] [bp-1Ch]@21
  int v8; // [sp+54h] [bp-18h]@25
  char *v9; // [sp+64h] [bp-8h]@21
  int v10; // [sp+68h] [bp-4h]@1

  v2 = this;
  v10 = 90;
  if ( giDialogTimeout && KBTickCount() > giDialogTimeout )
  {
    *(_DWORD *)v2 = 512;
    gpWindowManager->buttonPressedCode = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = 10;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 2);
    giDialogTimeout = 0;
    return 2;
  }
  if ( *(_DWORD *)v2 != 512 || *((_DWORD *)v2 + 1) != 13 || *((_DWORD *)v2 + 2) != 30720 )
    goto LABEL_20;
  if ( dword_524C90 )
    goto LABEL_15;
  if ( iCurTransferArtifact + 1 >= iMaxTransferArtifacts )
  {
    if ( *(_DWORD *)&giSkeletonsCreated && !bSkeletonsShown )
    {
      bSkeletonsShown = 1;
      combatManager::ClearWinLoseBottom(gpCombatManager, gpCombatManager->combatEndWindow);
      combatManager::ShowSkeletons(gpCombatManager, (int)&gpCombatManager->combatEndWindow->idx);
      goto LABEL_20;
    }
    if ( gpCombatManager->eagleEyeSpellLearned[gpCombatManager->winningSide] != -1 )
    {
      combatManager::ClearWinLoseBottom(gpCombatManager, gpCombatManager->combatEndWindow);
      combatManager::ShowEagleEyeSpell((int)gpCombatManager, (int)&gpCombatManager->combatEndWindow->idx);
      gpCombatManager->eagleEyeSpellLearned[gpCombatManager->winningSide] = -1;
      goto LABEL_20;
    }
LABEL_15:
    gpWindowManager->buttonPressedCode = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = 10;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 2);
    return 2;
  }
  combatManager::ClearWinLoseBottom(gpCombatManager, gpCombatManager->combatEndWindow);
  ++iCurTransferArtifact;
  combatManager::ShowWinLoseArtifact(
    gpCombatManager,
    (int)&gpCombatManager->combatEndWindow->idx,
    iTransferArtifacts[iCurTransferArtifact]);
LABEL_20:
  if ( KBTickCount() > glTimers )
  {
    evt = 512;
    v7 = 9;
    v9 = &v4;
    ++giWinCmbtFrame;
    switch ( gbWhichAnimationPlaying )
    {
      case 1:
        v3 = giWinCmbtFrame % 20 + 1;
        v5 = 99;
        break;
      case 3:
        if ( giWinCmbtFrame == 43 )
        {
          sprintf(&v4, "cmbtfle2.icn");
          v8 = 200;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
        }
        if ( giWinCmbtFrame == 69 )
        {
          sprintf(&v4, "cmbtfle3.icn");
          v8 = 200;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
        }
        if ( giWinCmbtFrame >= 43 )
        {
          if ( giWinCmbtFrame >= 69 )
          {
            v3 = giWinCmbtFrame - 68;
            if ( giWinCmbtFrame - 68 > 25 )
              v3 = 25;
          }
          else
          {
            v3 = giWinCmbtFrame - 42;
          }
        }
        else
        {
          v3 = giWinCmbtFrame + 1;
        }
        v5 = 40;
        break;
      case 4:
        v3 = giWinCmbtFrame % 20 + 1;
        v5 = 99;
        break;
      default:
        if ( giWinCmbtFrame == 30 )
        {
          sprintf(&v4, "cmbtlos2.icn");
          v8 = 200;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
        }
        if ( giWinCmbtFrame == 59 )
        {
          sprintf(&v4, "cmbtlos3.icn");
          v8 = 200;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)&evt);
        }
        if ( giWinCmbtFrame >= 30 )
        {
          if ( giWinCmbtFrame >= 59 )
          {
            if ( giWinCmbtFrame == 80 )
              giWinCmbtFrame = 59;
            v3 = giWinCmbtFrame - 58;
            v5 = 100;
          }
          else
          {
            v3 = giWinCmbtFrame - 29;
            v5 = 50;
          }
        }
        else
        {
          v3 = giWinCmbtFrame + 1;
          v5 = 50;
        }
        break;
    }
    *(_DWORD *)v2 = 512;
    *((_DWORD *)v2 + 1) = 4;
    *((_DWORD *)v2 + 2) = 201;
    *((_DWORD *)v2 + 6) = v3;
    heroWindow::BroadcastMessage(gpCombatManager->combatEndWindow, (Event *)v2);
    heroWindow::DrawWindow(gpCombatManager->combatEndWindow, 1, 0, 32767);
    glTimers = KBTickCount() + v5;
  }
  return 1;
}