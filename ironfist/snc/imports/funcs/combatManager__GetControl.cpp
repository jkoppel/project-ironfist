{
  combatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  this->field_F2C3 = -1;
  this->field_F2CB = -99;
  this->field_F2CB = -99;
  if ( gpCombatManager->ready == 1 )
    mouseManager::SetPointer(gpMouseManager, 6);
  combatManager::CheckChangeSelector(thisa);
  if ( gbRemoteOn
    && *(_QWORD *)&thisa->playerID[0] >= 0i64
    && gbHumanPlayer[thisa->playerID[1]]
    && (gbHumanPlayer[thisa->playerID[0]] || !gbHumanPlayer[thisa->playerID[0]] && thisa->playerID[1]) )
    gbThisNetHasControl = thisa->playerID[thisa->currentActionSide] == -1
                       || !gbHumanPlayer[thisa->playerID[thisa->currentActionSide]]
                       || *(&gbThisNetHumanPlayer + thisa->playerID[thisa->currentActionSide]);
  else
    gbThisNetHasControl = 1;
  *(_DWORD *)&thisa->_15[104] = -1;
  combatManager::SetupSmallView(thisa);
  combatManager::ResetMouse(thisa);
}