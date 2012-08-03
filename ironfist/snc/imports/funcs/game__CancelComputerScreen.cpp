{
  int fieldID; // [sp+10h] [bp-4h]@1

  game::TurnOffAIMusic();
  bShowIt = 1;
  for ( fieldID = 1; fieldID <= 6; ++fieldID )
    heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 6, fieldID, 16392);
}