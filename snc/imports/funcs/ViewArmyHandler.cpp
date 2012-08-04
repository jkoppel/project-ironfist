{
  signed int v2; // [sp+18h] [bp-20h]@3
  void *evt; // [sp+20h] [bp-18h]@1
  int img2Type; // [sp+24h] [bp-14h]@9
  int img1Arg; // [sp+28h] [bp-10h]@8
  int img2Arg; // [sp+2Ch] [bp-Ch]@9

  evt = this;
  gbDismissArmy = 0;
  gbUpgradeArmy = 0;
  if ( *(_DWORD *)this != 512 || *((_DWORD *)this + 1) != 13 )
    goto LABEL_30;
  v2 = *((_DWORD *)this + 2);
  if ( v2 > 30721 )
  {
    if ( v2 == 30723 )
    {
      NormalDialog("Are you sure you want to dismiss this army?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        gbDismissArmy = 1;
        *((_DWORD *)evt + 2) = 10;
        *((_DWORD *)evt + 1) = *((_DWORD *)evt + 2);
        return 2;
      }
    }
    goto LABEL_30;
  }
  if ( v2 >= 30720 )
  {
    gpWindowManager->buttonPressedCode = *((_DWORD *)this + 2);
    *((_DWORD *)this + 2) = 10;
    *((_DWORD *)this + 1) = *((_DWORD *)this + 2);
    return 2;
  }
  if ( v2 != 500 )
  {
LABEL_30:
    if ( !gbLowMemory )
    {
      if ( KBTickCount() > glTimers )
      {
        *(_DWORD *)evt = 512;
        *((_DWORD *)evt + 1) = 4;
        *((_DWORD *)evt + 2) = 5;
        iViewArmyFrame = (iViewArmyFrame + 1) % byte_522D39;
        *((_DWORD *)evt + 6) = byte_522DB5[iViewArmyFrame];
        heroWindow::BroadcastMessage(*(heroWindow **)&gpGame->_10[612], (Event *)evt);
        *((_DWORD *)evt + 1) = 52;
        *((_DWORD *)evt + 6) = *(_DWORD *)&viewArmyBaseX + viewArmyFacingWIPXMod * byte_522CA5[iViewArmyFrame];
        heroWindow::BroadcastMessage(*(heroWindow **)&gpGame->_10[612], (Event *)evt);
        heroWindow::DrawWindow(*(heroWindow **)&gpGame->_10[612], 1, 0, 32767);
        glTimers = (signed __int64)((double)KBTickCount() + (double)dword_522CE2 * 1.35 / (double)byte_522D39);
      }
    }
    return 1;
  }
  img1Arg = 2
          * iViewArmyNumTroops
          * (gMonsterDatabase[iViewArmyUpgradeToType].cost - gMonsterDatabase[iViewArmyType].cost);
  if ( iViewArmyUpgradeToType == CREATURE_BLACK_DRAGON )
  {
    img2Type = 3;
    img2Arg = 2 * iViewArmyNumTroops;
  }
  else if ( iViewArmyUpgradeToType == CREATURE_TITAN )
  {
    img2Type = 5;
    img2Arg = 2 * iViewArmyNumTroops;
  }
  else
  {
    img2Type = -1;
    img2Arg = 0;
  }
  if ( gpCurPlayer->resources[6] < img1Arg || img2Type != -1 && gpCurPlayer->resources[img2Type] < img2Arg )
  {
    NormalDialog("You can't afford to upgrade your troops!", 1, -1, -1, 6, img1Arg, img2Type, img2Arg, -1, 0);
    goto LABEL_30;
  }
  NormalDialog(
    "Your troops can be upgraded, but it will cost you dearly.  Do you wish to upgrade them?",
    2,
    -1,
    -1,
    6,
    img1Arg,
    img2Type,
    img2Arg,
    -1,
    0);
  if ( gpWindowManager->buttonPressedCode != 30725 )
    goto LABEL_30;
  gpCurPlayer->resources[6] -= img1Arg;
  if ( img2Type != -1 )
    gpCurPlayer->resources[img2Type] -= img2Arg;
  gbUpgradeArmy = 1;
  *((_DWORD *)evt + 2) = 10;
  *((_DWORD *)evt + 1) = *((_DWORD *)evt + 2);
  return 2;
}