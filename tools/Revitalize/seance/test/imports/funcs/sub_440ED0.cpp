{
  CombatManager *thisa; // [sp+Ch] [bp-28h]@1
  InputEvent a2; // [sp+10h] [bp-24h]@5
  int y; // [sp+2Ch] [bp-8h]@5
  int x; // [sp+30h] [bp-4h]@5

  thisa = this;
  if ( !combatGraphicsOff )
  {
    if ( dword_524C60
      && this->playerID[this->currentActionSide] >= 0
      && dword_524810[this->playerID[this->currentActionSide]] )
    {
      this->field_F2C3 = -1;
      sub_4C3300(this, 0);
      retrieveVirtualCursorCoordinates(&x, &y);
      a2.eventCode = INPUT_MOUSEMOVE_EVENT_CODE;
      a2.altXCoord = x;
      a2.xCoordOrKeycode = x;
      a2.altYCoord = y;
      a2.yCoord = y;
      sub_43C500(thisa, &a2);
    }
    else
    {
      MouseManager::setSpriteIdx(mouseManager, 6);
    }
  }
}
