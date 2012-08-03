{
  void *v1; // ST18_4@1
  int evt; // [sp+10h] [bp-1Ch]@1
  int v3; // [sp+14h] [bp-18h]@1
  int v4; // [sp+18h] [bp-14h]@1
  char *v5; // [sp+28h] [bp-4h]@1

  v1 = this;
  evt = 512;
  v3 = 4;
  v4 = 10;
  v5 = *(char **)&combatSpeed;
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 11;
  v5 = (char *)(*(_DWORD *)&combatArmyInfoLevel + 3);
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 12;
  v5 = (char *)(*(_DWORD *)&autoCombatUseSpells + 6);
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 13;
  v5 = (char *)(*(_DWORD *)&showCombatGrid + 8);
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 14;
  v5 = (char *)(combatShadeLevel + 10);
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 15;
  v5 = (char *)(*(_DWORD *)&showCombatMouseHex + 12);
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v3 = 3;
  v4 = 20;
  v5 = combatSpeedText[*(_DWORD *)&combatSpeed];
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 21;
  v5 = combatMiniInfoText[*(_DWORD *)&combatArmyInfoLevel];
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 22;
  v5 = onOffText[*(_DWORD *)&autoCombatUseSpells];
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 23;
  v5 = onOffText[*(_DWORD *)&showCombatGrid];
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 24;
  v5 = onOffText[combatShadeLevel];
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  v4 = 25;
  v5 = onOffText[*(_DWORD *)&showCombatMouseHex];
  heroWindow::BroadcastMessage(CSPanel, (Event *)&evt);
  if ( !v1 )
    heroWindow::DrawWindow(CSPanel, 1, 0, 32767);
}