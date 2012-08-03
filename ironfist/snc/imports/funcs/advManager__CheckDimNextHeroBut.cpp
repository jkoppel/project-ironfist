{
  int messageType; // [sp+10h] [bp-4h]@3

  if ( *(&gbThisNetHumanPlayer + giCurPlayer) && playerData::HasMobileHero(gpCurPlayer) )
    messageType = 6;
  else
    messageType = GUI_MESSAGE_ADD_FLAGS;
  return heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, messageType, 1, 16392);
}