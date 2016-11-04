{
  Hero *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( a2 != -1 )
  {
    this->spellpoints -= getSpellCost(a2, this);
    if ( thisa->spellpoints < 0 )
      thisa->spellpoints = 0;
    if ( advManager->ready == 1 )
    {
      if ( *(&byte_524758 + curPlayerIdx) )
        AdvManager::involvesSettingPointBars(advManager, -1, 1, 1);
    }
  }
}
