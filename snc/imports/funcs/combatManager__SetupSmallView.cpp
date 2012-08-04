{
  combatManager *thisa; // [sp+Ch] [bp-Ch]@1

  thisa = this;
  if ( *(_DWORD *)&this->_15[104] == -1 && this->field_F557 != -1 )
    combatManager::DrawSmallView(this, 1, 1);
  if ( gbThisNetHasControl
    && thisa->playerID[thisa->currentActionSide] != -1
    && gbHumanPlayer[thisa->playerID[thisa->currentActionSide]] )
  {
    if ( *(_DWORD *)&thisa->_15[100] != thisa->currentActionSide
      || *(_DWORD *)&thisa->_15[108] != thisa->someSortOfStackIdx )
    {
      if ( *(_DWORD *)&thisa->_15[100] != -1 && *(_DWORD *)&thisa->_15[100] != thisa->currentActionSide )
      {
        if ( thisa->field_F553 != -1 )
        {
          *(_DWORD *)&thisa->_15[100] = -1;
          combatManager::DrawSmallView(thisa, 0, 1);
        }
      }
      *(_DWORD *)&thisa->_15[100] = thisa->currentActionSide;
      *(_DWORD *)&thisa->_15[108] = thisa->someSortOfStackIdx;
      combatManager::DrawSmallView(thisa, 0, 1);
    }
  }
  else
  {
    *(_DWORD *)&thisa->_15[100] = -1;
    if ( thisa->field_F553 != -1 )
      combatManager::DrawSmallView(thisa, 0, 1);
  }
}