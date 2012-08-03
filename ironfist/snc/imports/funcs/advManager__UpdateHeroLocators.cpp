{
  int a2a; // [sp+20h] [bp-4h]@2

  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    for ( a2a = 0; a2a < 4; ++a2a )
      advManager::UpdateHeroLocator(this, a2a, 0, 0);
    if ( gpCurPlayer->numHeroes >= 5 )
      this->heroScrollbarKnob->offsetY = (signed __int64)((double)gpCurPlayer->field_3
                                                        * (73.0
                                                         / (double)((signed int)gpCurPlayer->numHeroes - 4))
                                                        + 195.0);
    else
      this->heroScrollbarKnob->offsetY = 232;
    if ( a2 )
      heroWindow::DrawWindow(this->adventureScreen, a3);
  }
}