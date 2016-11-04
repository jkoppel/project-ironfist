{
  int v3; // [sp+Ch] [bp-44h]@1
  GUIIcon *v4; // [sp+18h] [bp-38h]@14
  GUIIcon *v5; // [sp+1Ch] [bp-34h]@8
  GUIWindow *thisa; // [sp+20h] [bp-30h]@1
  AbstractGUIComponent *v7; // [sp+24h] [bp-2Ch]@15
  int evt; // [sp+28h] [bp-28h]@19
  int v9; // [sp+2Ch] [bp-24h]@20
  int v10; // [sp+30h] [bp-20h]@20
  int v11; // [sp+40h] [bp-10h]@20
  int v12; // [sp+44h] [bp-Ch]@1
  int i; // [sp+48h] [bp-8h]@6
  AbstractGUIComponent *guiObj; // [sp+4Ch] [bp-4h]@6

  v3 = this;
  *(_DWORD *)(this + 75) = a2;
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  sub_4CEA00(mouseManager);
  v12 = useEvilBorders;
  useEvilBorders = 1;
  *(_DWORD *)(v3 + 67) = *(_DWORD *)(v3 + 4);
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    *(_DWORD *)(v3 + 71) = GUIWindow_constructorFromFile(thisa, 0, 0, "x_camp.bin");
  else
    *(_DWORD *)(v3 + 71) = 0;
  if ( !*(_DWORD *)(v3 + 71) )
    fatalOutOfMemoryError();
  guiObj = 0;
  for ( i = 0; *(_DWORD *)(v3 + 8) > i; ++i )
  {
    v5 = (GUIIcon *)operator new(0x2Du);
    if ( v5 )
      guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                         v5,
                                         *(&dword_512930[16 * *(_DWORD *)v3] + 2 * i),
                                         *(&dword_512934[16 * *(_DWORD *)v3] + 2 * i),
                                         41,
                                         41,
                                         "x_cmpext.icn",
                                         0,
                                         0,
                                         i + 850,
                                         16,
                                         1);
    else
      guiObj = 0;
    if ( !guiObj )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)(v3 + 71), guiObj, -1);
  }
  v4 = (GUIIcon *)operator new(0x2Du);
  if ( v4 )
    v7 = (AbstractGUIComponent *)GUIIcon_constructor(
                                   v4,
                                   24,
                                   25,
                                   376,
                                   49,
                                   "x_cmpext.icn",
                                   *(_WORD *)v3 + 15,
                                   0,
                                   -1,
                                   16,
                                   1);
  else
    v7 = 0;
  if ( !v7 )
    fatalOutOfMemoryError();
  GUIWindow::insertElement(*(GUIWindow **)(v3 + 71), v7, -1);
  evt = 512;
  if ( !a2 )
  {
    v9 = 6;
    v10 = 901;
    v11 = 6;
    GUIWindow::processMessage(*(GUIWindow **)(v3 + 71), (Event *)&evt);
  }
  if ( dword_4F74A8 )
  {
    v9 = 6;
    v10 = 902;
    v11 = 6;
    GUIWindow::processMessage(*(GUIWindow **)(v3 + 71), (Event *)&evt);
  }
  SoundManager::couldBePlayCDTrack(soundManager, 24);
  sub_471130((void *)v3, 0);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    *(GUIWindow **)(v3 + 71),
    (int (__fastcall *)(InputEvent *))sub_472480,
    0);
  operator delete(*(void **)(v3 + 71));
  useEvilBorders = v12;
  if ( HeroWindowManager::instance->buttonPressedCode == 901 )
  {
    display_message_window("Are you sure you want to restart this scenario?", 2, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      sub_470620(v3);
      advManager->field_A2 = 0;
      dword_52405C = 0;
      sub_4C7C60(HeroWindowManager::instance, 1, 8, dword_524234);
      sub_4557F0(advManager);
      sub_4506B0(advManager, 1, 0);
      sub_4C7C60(HeroWindowManager::instance, 0, 8, dword_524234);
    }
  }
}
