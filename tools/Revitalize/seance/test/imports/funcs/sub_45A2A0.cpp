{
  int result; // eax@2
  int v2; // [sp+0h] [bp-314h]@0
  int xa; // [sp+Ch] [bp-308h]@1
  int v4; // [sp+10h] [bp-304h]@3
  char v5; // [sp+14h] [bp-300h]@3

  xa = x;
  dword_5304C8 = -1;
  if ( dword_4F1CBC )
  {
    result = 0;
  }
  else
  {
    dword_4F3088 = 1;
    dword_524EC4 = 0;
    dword_50FED8 = 1;
    memcpy(&v5, palette->contents, 0x300u);
    v4 = HeroWindowManager::instance->field_56;
    HeroWindowManager::instance->field_56 = 0;
    if ( xa != 67 )
    {
      soundManager->field_688 = 1;
      SoundManager::otherPlayTrack(soundManager, -1, 0, -1, v2);
    }
    if ( *(_DWORD *)&slowVideo == 3 )
    {
      *(_DWORD *)&slowVideo = 0;
      propagateSettingChanges();
      byte_524EC0 = 37;
      dword_510BE8 = 1;
      playH2Intro();
      dword_510BE8 = 0;
      if ( (unsigned int)(dword_524EE4 + dword_524ED0) >= 0x7D0 || (unsigned int)dword_524EE8 >= 0x514 || dword_4F74A8 )
      {
        *(_DWORD *)&slowVideo = 1;
        propagateSettingChanges();
      }
      logSmackSummary((int *)smackSummaryBuf);
    }
    byte_524EC0 = xa;
    playH2Intro();
    memcpy(palette->contents, &v5, 0x300u);
    HeroWindowManager::instance->field_56 = v4;
    dword_4F3088 = 0;
    dword_50FED8 = 0;
    result = dword_524EC4;
  }
  return result;
}
