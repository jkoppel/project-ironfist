{
  signed int result; // eax@7
  signed int v2; // [sp+Ch] [bp-28h]@6
  void *v3; // [sp+14h] [bp-20h]@1
  int evt; // [sp+18h] [bp-1Ch]@7
  int v5; // [sp+1Ch] [bp-18h]@7
  int v6; // [sp+20h] [bp-14h]@7
  int v7; // [sp+30h] [bp-4h]@7

  v3 = this;
  if ( !SoundManager::songPlaying(soundManager) && advManager->ready == 1 )
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
  if ( *(_DWORD *)v3 == 512 && *((_DWORD *)v3 + 1) == 13 && (v2 = *((_DWORD *)v3 + 2), v2 >= 30721 && v2 <= 30722) )
  {
    evt = 512;
    v6 = 100;
    v5 = 55;
    GUIWindow::processMessage(dword_524EA4, (Event *)&evt);
    dword_524D28 = v7;
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v3 + 2);
    *((_DWORD *)v3 + 2) = 10;
    *((_DWORD *)v3 + 1) = *((_DWORD *)v3 + 2);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
