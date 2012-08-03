{
  combatManager *thisa; // [sp+Ch] [bp-28h]@1
  tag_message a2; // [sp+10h] [bp-24h]@5
  int y; // [sp+2Ch] [bp-8h]@5
  int x; // [sp+30h] [bp-4h]@5

  thisa = this;
  if ( !gbNoShowCombat )
  {
    if ( gbThisNetHasControl
      && this->playerID[this->currentActionSide] >= 0
      && gbHumanPlayer[this->playerID[this->currentActionSide]] )
    {
      this->field_F2C3 = -1;
      combatManager::ClearCombatMessages(this, 0);
      mouseManager::MouseCoords(&x, &y);
      a2.eventCode = INPUT_MOUSEMOVE_EVENT_CODE;
      a2.altXCoord = x;
      a2.xCoordOrKeycode = x;
      a2.altYCoord = y;
      a2.yCoord = y;
      combatManager::ProcessCombatMsg(thisa, &a2);
    }
    else
    {
      mouseManager::SetPointer(gpMouseManager, 6);
    }
  }
}