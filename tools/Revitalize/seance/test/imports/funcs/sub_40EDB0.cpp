{
  GUIIcon *v3; // [sp+18h] [bp-24h]@6
  GUIWindow *thisa; // [sp+1Ch] [bp-20h]@1

  dword_522C24 = (int)this;
  dword_522BF8 = a2;
  dword_522C10 = 0;
  dword_522C08 = 159;
  dword_522C0C = 23;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    dword_522C28 = GUIWindow_constructorFromFile(thisa, dword_522C08, dword_522C0C, "tradpost.bin");
  else
    dword_522C28 = 0;
  if ( !dword_522C28 )
    fatalOutOfMemoryError();
  dword_522C00 = -1;
  dword_522C1C = -1;
  dword_522C14 = 0;
  v3 = (GUIIcon *)operator new(0x2Du);
  if ( v3 )
    globGuiObj = (AbstractGUIComponent *)GUIIcon_constructor(v3, 67, 204, 17, 8, "tradpost.icn", 2, 0, 31, 16, 1);
  else
    globGuiObj = 0;
  if ( !globGuiObj )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(dword_522C28, globGuiObj, -1);
  market_related(0);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_522C28,
    (int (__fastcall *)(InputEvent *))tradingPostCallback,
    0);
  return operator delete(dword_522C28);
}
