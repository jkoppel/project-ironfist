{
  signed int v2; // [sp+Ch] [bp-38h]@21
  signed int v3; // [sp+10h] [bp-34h]@16
  int v4; // [sp+14h] [bp-30h]@14
  void *v5; // [sp+18h] [bp-2Ch]@1

  v5 = this;
  if ( !SoundManager::songPlaying(soundManager) && advManager->ready == 1 )
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
  if ( dword_4F1CB4 && getTickCount() > dword_4F1CB4 )
  {
    *(_DWORD *)v5 = 512;
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v5 + 2);
    *((_DWORD *)v5 + 2) = 10;
    *((_DWORD *)v5 + 1) = *((_DWORD *)v5 + 2);
    dword_4F1CB4 = 0;
    return 2;
  }
  if ( *(_DWORD *)v5 == 1 )
  {
    if ( *((_DWORD *)v5 + 1) == 15 )
    {
      ++dword_52523C;
      if ( dword_52523C >= 3 )
        dword_52523C = 0;
      sub_463D00();
    }
    return 1;
  }
  if ( *(_DWORD *)v5 == 512 )
  {
    v4 = *((_DWORD *)v5 + 1);
    if ( v4 == 12 )
      goto LABEL_15;
    if ( v4 != 13 )
    {
      if ( v4 != 14 )
        return 1;
LABEL_15:
      if ( *((_BYTE *)v5 + 13) & 2 )
      {
        v3 = *((_DWORD *)v5 + 2);
        if ( v3 >= 100 && v3 <= 102 )
        {
          dword_52523C = *((_DWORD *)v5 + 2) - 100;
          display_message_window(primary_skill_descriptions[dword_52523C], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      return 1;
    }
    v2 = *((_DWORD *)v5 + 2);
    if ( v2 >= 100 )
    {
      if ( v2 <= 102 )
      {
        dword_52523C = *((_DWORD *)v5 + 2) - 100;
        sub_463D00();
      }
      else
      {
        if ( v2 == 30722 )
        {
          HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v5 + 2);
          *((_DWORD *)v5 + 2) = 10;
          *((_DWORD *)v5 + 1) = *((_DWORD *)v5 + 2);
          dword_4F1CB4 = 0;
          return 2;
        }
      }
    }
  }
  return 1;
}
