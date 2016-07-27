{
  CombatManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  this->field_F2C3 = -1;
  this->field_F2CB = -99;
  this->field_F2CB = -99;
  if ( combatManager->ready == 1 )
    MouseManager::setSpriteIdx(mouseManager, 6);
  sub_440A90(thisa);
  if ( dword_4F7494
    && *(_QWORD *)&thisa->playerID[0] >= 0i64
    && dword_524810[thisa->playerID[1]]
    && (dword_524810[thisa->playerID[0]] || !dword_524810[thisa->playerID[0]] && thisa->playerID[1]) )
    dword_524C60 = thisa->playerID[thisa->currentActionSide] == -1
                || !dword_524810[thisa->playerID[thisa->currentActionSide]]
                || *(&byte_524758 + thisa->playerID[thisa->currentActionSide]);
  else
    dword_524C60 = 1;
  *(_DWORD *)&thisa->_15[104] = -1;
  sub_442860(thisa);
  sub_440ED0(thisa);
}
