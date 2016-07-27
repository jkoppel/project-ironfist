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
  if ( dword_4F1CB4 && getTickCount() > dword_4F1CB4 )
  {
    *(_DWORD *)v2 = 512;
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = 10;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 2);
    dword_4F1CB4 = 0;
    return 2;
  }
  if ( *(_DWORD *)v2 != 512 || *((_DWORD *)v2 + 1) != 13 || *((_DWORD *)v2 + 2) != 30720 )
    goto LABEL_20;
  if ( dword_524C90 )
    goto LABEL_15;
  if ( dword_524C8C + 1 >= numStolenArtifacts )
  {
    if ( *(_DWORD *)&skeletonsToRaise && !dword_524C6C )
    {
      dword_524C6C = 1;
      sub_43E400(combatManager, combatManager->combatEndWindow);
      sub_43E7B0(combatManager, (int)&combatManager->combatEndWindow->idx);
      goto LABEL_20;
    }
    if ( combatManager->eagleEyeSpellLearned[combatManager->winningSide] != -1 )
    {
      sub_43E400(combatManager, combatManager->combatEndWindow);
      sub_43E9F0((int)combatManager, (int)&combatManager->combatEndWindow->idx);
      combatManager->eagleEyeSpellLearned[combatManager->winningSide] = -1;
      goto LABEL_20;
    }
LABEL_15:
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = 10;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 2);
    return 2;
  }
  sub_43E400(combatManager, combatManager->combatEndWindow);
  ++dword_524C8C;
  sub_43E510(combatManager, (int)&combatManager->combatEndWindow->idx, stolenArtifacts[dword_524C8C]);
LABEL_20:
  if ( getTickCount() > animationFrameSwitchTime )
  {
    evt = 512;
    v7 = 9;
    v9 = &v4;
    ++dword_524C88;
    switch ( dword_524C70 )
    {
      case 1:
        v3 = dword_524C88 % 20 + 1;
        v5 = 99;
        break;
      case 3:
        if ( dword_524C88 == 43 )
        {
          sprintf(&v4, "cmbtfle2.icn");
          v8 = 200;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
        }
        if ( dword_524C88 == 69 )
        {
          sprintf(&v4, "cmbtfle3.icn");
          v8 = 200;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
        }
        if ( dword_524C88 >= 43 )
        {
          if ( dword_524C88 >= 69 )
          {
            v3 = dword_524C88 - 68;
            if ( dword_524C88 - 68 > 25 )
              v3 = 25;
          }
          else
          {
            v3 = dword_524C88 - 42;
          }
        }
        else
        {
          v3 = dword_524C88 + 1;
        }
        v5 = 40;
        break;
      case 4:
        v3 = dword_524C88 % 20 + 1;
        v5 = 99;
        break;
      default:
        if ( dword_524C88 == 30 )
        {
          sprintf(&v4, "cmbtlos2.icn");
          v8 = 200;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
        }
        if ( dword_524C88 == 59 )
        {
          sprintf(&v4, "cmbtlos3.icn");
          v8 = 200;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
          v8 = 201;
          GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)&evt);
        }
        if ( dword_524C88 >= 30 )
        {
          if ( dword_524C88 >= 59 )
          {
            if ( dword_524C88 == 80 )
              dword_524C88 = 59;
            v3 = dword_524C88 - 58;
            v5 = 100;
          }
          else
          {
            v3 = dword_524C88 - 29;
            v5 = 50;
          }
        }
        else
        {
          v3 = dword_524C88 + 1;
          v5 = 50;
        }
        break;
    }
    *(_DWORD *)v2 = 512;
    *((_DWORD *)v2 + 1) = 4;
    *((_DWORD *)v2 + 2) = 201;
    *((_DWORD *)v2 + 6) = v3;
    GUIWindow::processMessage(combatManager->combatEndWindow, (Event *)v2);
    GUIWindow::repaintComponentsInRange(combatManager->combatEndWindow, 1, 0, 32767);
    animationFrameSwitchTime = getTickCount() + v5;
  }
  return 1;
}
