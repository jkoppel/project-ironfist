{
  int thisa; // [sp+Ch] [bp-4h]@1

  thisa = (int)this;
  if ( bShowIt )
  {
    resourceManager::GetBackdrop(gpResourceManager, "advbord.icn", gpWindowManager->screenBuffer, 1);
    if ( a3 )
    {
      BaseFree(*(void **)(thisa + 186), (int)"F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F7C0 + 9);
      *(_DWORD *)(thisa + 186) = 0;
    }
    advManager::SaveAdventureBorder(thisa);
    advManager::UpdateHeroLocators((advManager *)thisa, 0, 0);
    advManager::UpdateTownLocators((void *)thisa, 0, 0);
    advManager::UpdBottomView((advManager *)thisa, 1, 0, 0);
    heroWindow::DrawWindow(*(heroWindow **)(thisa + 154), 0);
    if ( a2 )
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x280u, 480);
    advManager::UpdateRadar(thisa, a2, 0);
    advManager::CompleteDraw((advManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0, 1);
    if ( a2 )
      advManager::UpdateScreen((advManager *)thisa, 0, 0);
  }
}