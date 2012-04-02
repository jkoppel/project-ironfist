void __cdecl sub_497920()
{
  ResourceManager::dumpImageToScreen(resourceManager, "herobkg.icn", HeroWindowManager::instance->screenBuffer, 1);
  GUIWindow::repaintAndUpdateScreen(heroWindow);
  HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x280u, 480);
}
