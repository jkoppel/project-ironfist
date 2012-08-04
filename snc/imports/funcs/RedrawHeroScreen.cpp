{
  resourceManager::GetBackdrop(gpResourceManager, "herobkg.icn", gpWindowManager->screenBuffer, 1);
  heroWindow::DrawWindow(heroWin);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
}