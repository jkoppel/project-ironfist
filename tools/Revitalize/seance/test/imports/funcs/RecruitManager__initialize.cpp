{
  int v2; // eax@7
  int v4; // [sp+Ch] [bp-10h]@1
  GUIWindow *thisa; // [sp+10h] [bp-Ch]@1
  int v6; // [sp+14h] [bp-8h]@6

  v4 = (int)this;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    *(_DWORD *)(v4 + 82) = GUIWindow_constructorFromFile(
                             thisa,
                             143,
                             16,
                             &aRecruit0_bin[("recruit1.bin" - "recruit0.bin") & ((*(_DWORD *)(v4 + 70) == -1) - 1)]);
  else
    *(_DWORD *)(v4 + 82) = 0;
  if ( !*(_DWORD *)(v4 + 82) )
    fatalOutOfMemoryError();
  *(_DWORD *)(v4 + 122) = 0;
  *(_DWORD *)(v4 + 114) = 0;
  *(_DWORD *)(v4 + 118) = 0;
  configureRecruitWindow(
    *(GUIWindow **)(v4 + 82),
    *(_DWORD *)(v4 + 58),
    *(_DWORD *)(v4 + 66),
    *(_DWORD *)(v4 + 70),
    *(_DWORD *)(v4 + 74),
    **(_WORD **)(v4 + 106));
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  sub_4085C0(v4);
  HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 30720, 16392);
  HeroWindowManager::addWindow(HeroWindowManager::instance, *(GUIWindow **)(v4 + 82), -1, 1);
  v6 = curPlayer->resources[6] / *(_DWORD *)(v4 + 66);
  if ( *(_DWORD *)(v4 + 70) == -1 )
  {
    *(_DWORD *)(v4 + 110) = v6;
  }
  else
  {
    v2 = curPlayer->resources[6] / *(_DWORD *)(v4 + 66);
    if ( v6 >= curPlayer->resources[*(_DWORD *)(v4 + 70)] / *(_DWORD *)(v4 + 74) )
      v2 = curPlayer->resources[*(_DWORD *)(v4 + 70)] / *(_DWORD *)(v4 + 74);
    *(_DWORD *)(v4 + 110) = v2;
  }
  if ( (signed int)**(_WORD **)(v4 + 106) < *(_DWORD *)(v4 + 110) )
    *(_DWORD *)(v4 + 110) = **(_WORD **)(v4 + 106);
  *(_DWORD *)(v4 + 98) = 0;
  *(_DWORD *)(v4 + 102) = 0;
  if ( !**(_WORD **)(v4 + 106) )
  {
    HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 6, 30722, 2);
    HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 30722, 16392);
  }
  menu = globalMenu1;
  changeMenu(dfltMenu);
  *(_DWORD *)(v4 + 12) = 16384;
  *(_DWORD *)(v4 + 16) = a2;
  *(_DWORD *)(v4 + 50) = 1;
  strcpy((char *)(v4 + 20), "recruitManager");
  return 0;
}
