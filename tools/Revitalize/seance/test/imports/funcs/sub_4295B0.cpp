{
  if ( dword_52473C && dword_5235D4 > 1 && !dword_4F7494 )
  {
    MouseManager::setSpriteIdx(mouseManager, 0);
    dword_4F7470 = 1;
    dword_524798 = getTickCount() + 9999999;
    if ( *(&byte_524758 + curPlayerIdx) )
      dword_52405C = 1;
    else
      dword_52405C = 0;
    soundManager->field_688 = 1;
    SoundManager::couldBePlayCDTrack(soundManager, 21);
    sub_448110(advManager, 1);
    AdvManager::heroSelectionGUIStuff(advManager, 1, 1);
    sub_44D170(advManager, 1, 1);
    sub_447A00(advManager, 0, 1);
    sub_429510();
    dword_4F7470 = 0;
    display_message_window((char *)a1, 1, -1, -1, 9, gameObject->players[a2].color, -1, 0, -1, 0);
    SoundManager::couldBePlayCDTrack(soundManager, -1);
  }
}
