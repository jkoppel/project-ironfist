{
  int messageType; // [sp+10h] [bp-4h]@3

  if ( *(&byte_524758 + curPlayerIdx) && sub_418E10(curPlayer) )
    messageType = 6;
  else
    messageType = GUI_MESSAGE_ADD_FLAGS;
  return HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, messageType, 1, 16392);
}
