{
  SoundManager *result; // eax@1
  int fieldID; // [sp+10h] [bp-4h]@1

  result = sub_423E20();
  dword_524C14 = 1;
  for ( fieldID = 1; fieldID <= 6; ++fieldID )
    result = (SoundManager *)HeroWindowManager::sendMessage(
                               HeroWindowManager::instance,
                               INPUT_GUI_MESSAGE_CODE,
                               6,
                               fieldID,
                               16392);
  return result;
}
