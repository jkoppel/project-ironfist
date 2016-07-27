{
  TownManager *thisa; // [sp+Ch] [bp-8h]@1
  int i; // [sp+10h] [bp-4h]@1

  thisa = this;
  yieldToGlobalUpdater();
  Icon::drawToScreen(thisa->couldBeBackground, 0, 0, 0, 0);
  yieldToGlobalUpdater();
  for ( i = 0; thisa->curBuilding > i; ++i )
  {
    BuildingDisplay::paint(thisa->buildingDisplays[i], a3);
    yieldToGlobalUpdater();
  }
  GUIWindow::repaintComponentsInRange(thisa->townScreen, 0, 136, 137);
  yieldToGlobalUpdater();
  if ( a2 )
    renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, 0, 0, 0x280u, 256, 0, 0);
  yieldToGlobalUpdater();
}
