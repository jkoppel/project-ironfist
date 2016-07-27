{
  int v3; // [sp+Ch] [bp-4h]@1

  v3 = (int)this;
  if ( dword_524C14 )
  {
    ResourceManager::dumpImageToScreen(resourceManager, "advbord.icn", HeroWindowManager::instance->screenBuffer, 1);
    if ( a3 )
    {
      KBFree(*(void **)(v3 + 186), (int)"F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F7C0 + 9);
      *(_DWORD *)(v3 + 186) = 0;
    }
    sub_4563A0(v3);
    AdvManager::heroSelectionGUIStuff((AdvManager *)v3, 0, 0);
    sub_44D170((void *)v3, 0, 0);
    sub_44D440((void *)v3, 1, 0, 0);
    GUIWindow::repaint(*(GUIWindow **)(v3 + 154), 0);
    if ( a2 )
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
    sub_44AA80(v3, a2, 0);
    sub_447C20((AdvManager *)v3, *(_DWORD *)(v3 + 470), *(_DWORD *)(v3 + 474), 0, 1);
    if ( a2 )
      sub_447A00((void *)v3, 0, 0);
  }
}
