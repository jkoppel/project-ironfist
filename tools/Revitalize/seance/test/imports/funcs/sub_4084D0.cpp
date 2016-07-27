{
  int v1; // [sp+Ch] [bp-Ch]@1

  v1 = this;
  HeroWindowManager::removeWindow(HeroWindowManager::instance, *(GUIWindow **)(this + 82));
  operator delete(*(void **)(v1 + 82));
  if ( *(_DWORD *)(v1 + 102) )
    display_message_window("There is no room in the garrison for this army.", 1, 177, 100, -1, 0, -1, 0, -1, 0);
  HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
  if ( *(_DWORD *)(v1 + 54) == 35 && *(_DWORD *)(v1 + 98) && *(_DWORD *)(v1 + 78) )
  {
    sub_4148D0((int)townManager);
    Bankbox::refreshCaptions(townManager->bankbox, 1);
  }
  *(_DWORD *)(v1 + 50) = 0;
  changeMenu(menu);
}
