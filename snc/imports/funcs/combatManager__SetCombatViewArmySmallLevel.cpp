{
  *(_DWORD *)&combatArmyInfoLevel = level;
  combatManager::DrawFrame(this, 1, 0, 0, 0, 75, 1, 1);
  WritePrefs();
}