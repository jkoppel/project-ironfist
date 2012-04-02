int __thiscall sub_4BDAD0(int this)
{
  GUIWindow::repaint(*(GUIWindow **)(this + 54), 0);
  HeroWindowManager::drawWindowsFromBufferWithWinG(HeroWindowManager::instance);
  return 0;
}
