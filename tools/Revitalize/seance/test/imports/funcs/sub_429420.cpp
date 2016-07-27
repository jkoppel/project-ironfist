{
  char v0; // [sp+10h] [bp-8h]@2
  int fieldID; // [sp+14h] [bp-4h]@2

  if ( *(_DWORD *)&blackoutComputer )
  {
    v0 = *(&byte_524758 + curPlayerIdx);
    *(&byte_524758 + curPlayerIdx) = 1;
    for ( fieldID = 1; fieldID <= 6; ++fieldID )
      HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, fieldID, 16392);
    dword_4F7470 = 1;
    sub_448110(advManager, 1);
    AdvManager::heroSelectionGUIStuff(advManager, 1, 1);
    sub_44D170(advManager, 1, 1);
    sub_44D440(advManager, 1, 1, 1);
    sub_447A00(advManager, 0, 1);
    dword_4F7470 = 0;
    *(&byte_524758 + curPlayerIdx) = v0;
  }
  sub_429510();
}
