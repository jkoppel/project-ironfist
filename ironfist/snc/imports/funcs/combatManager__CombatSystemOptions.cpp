{
  void *v1; // [sp+Ch] [bp-2Ch]@1
  heroWindow *thisa; // [sp+18h] [bp-20h]@1

  v1 = this;
  bCPrefsChanged = 0;
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    CSPanel = heroWindow::heroWindow(thisa, 160, 33, "cspanel.bin");
  else
    CSPanel = 0;
  if ( !CSPanel )
    MemError();
  SetWinText(CSPanel, 1);
  UpdateCombatSystemOptions((void *)1);
  heroWindowManager::DoDialog(
    gpWindowManager,
    CSPanel,
    (int (__fastcall *)(tag_message *))CombatSystemOptionsHandler,
    0);
  operator delete(CSPanel);
  if ( bCPrefsChanged )
    WritePrefs();
  *(_DWORD *)((char *)v1 + 12919) = 0;
  combatManager::DrawFrame((combatManager *)v1, 1, 0, 0, 0, 75, 1, 1);
}