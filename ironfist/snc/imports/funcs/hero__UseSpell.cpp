{
  hero *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( a2 != -1 )
  {
    this->spellpoints -= GetManaCost(a2, this);
    if ( thisa->spellpoints < 0 )
      thisa->spellpoints = 0;
    if ( gpAdvManager->ready == 1 )
    {
      if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
        advManager::UpdateHeroLocator(gpAdvManager, -1, 1, 1);
    }
  }
}