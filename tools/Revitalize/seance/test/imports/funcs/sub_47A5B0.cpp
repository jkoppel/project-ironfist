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
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 11;
  v5 = (char *)(*(_DWORD *)&combatArmyInfoLevel + 3);
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 12;
  v5 = (char *)(*(_DWORD *)&autoCombatUseSpells + 6);
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 13;
  v5 = (char *)(*(_DWORD *)&showCombatGrid + 8);
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 14;
  v5 = (char *)(combatShadeLevel + 10);
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 15;
  v5 = (char *)(*(_DWORD *)&showCombatMouseHex + 12);
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v3 = 3;
  v4 = 20;
  v5 = off_4F6F38[*(_DWORD *)&combatSpeed];
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 21;
  v5 = off_4F6F48[*(_DWORD *)&combatArmyInfoLevel];
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 22;
  v5 = off_4F62B0[*(_DWORD *)&autoCombatUseSpells];
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 23;
  v5 = off_4F62B0[*(_DWORD *)&showCombatGrid];
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 24;
  v5 = off_4F62B0[combatShadeLevel];
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  v4 = 25;
  v5 = off_4F62B0[*(_DWORD *)&showCombatMouseHex];
  GUIWindow::processMessage(dword_52FAF4, (Event *)&evt);
  if ( !v1 )
    GUIWindow::repaintComponentsInRange(dword_52FAF4, 1, 0, 32767);
}
