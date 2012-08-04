{
  char v0; // [sp+10h] [bp-8h]@2
  int fieldID; // [sp+14h] [bp-4h]@2

  if ( *(_DWORD *)&blackoutComputer )
  {
    v0 = *(&gbThisNetHumanPlayer + giCurPlayer);
    *(&gbThisNetHumanPlayer + giCurPlayer) = 1;
    for ( fieldID = 1; fieldID <= 6; ++fieldID )
      heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 5, fieldID, 16392);
    gbAllBlack = 1;
    advManager::CompleteDraw(gpAdvManager, 1);
    advManager::UpdateHeroLocators(gpAdvManager, 1, 1);
    advManager::UpdateTownLocators(gpAdvManager, 1, 1);
    advManager::UpdBottomView(gpAdvManager, 1, 1, 1);
    advManager::UpdateScreen(gpAdvManager, 0, 1);
    gbAllBlack = 0;
    *(&gbThisNetHumanPlayer + giCurPlayer) = v0;
  }
  game::ShowHeroesLogo();
}