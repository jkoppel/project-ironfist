{
  void *v1; // [sp+Ch] [bp-2Ch]@1
  GUIWindow *thisa; // [sp+18h] [bp-20h]@1

  v1 = this;
  dword_52FAF0 = 0;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    dword_52FAF4 = GUIWindow_constructorFromFile(thisa, 160, 33, "cspanel.bin");
  else
    dword_52FAF4 = 0;
  if ( !dword_52FAF4 )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(dword_52FAF4, 1);
  sub_47A5B0((void *)1);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_52FAF4,
    (int (__fastcall *)(InputEvent *))sub_47A7A0,
    0);
  operator delete(dword_52FAF4);
  if ( dword_52FAF0 )
    propagateSettingChanges();
  *(_DWORD *)((char *)v1 + 12919) = 0;
  CombatManager::drawBattlefield((CombatManager *)v1, 1, 0, 0, 0, 75, 1, 1);
}
