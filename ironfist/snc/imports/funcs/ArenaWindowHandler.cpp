{
  signed int v2; // [sp+Ch] [bp-38h]@21
  signed int v3; // [sp+10h] [bp-34h]@16
  int v4; // [sp+14h] [bp-30h]@14
  void *v5; // [sp+18h] [bp-2Ch]@1

  v5 = this;
  if ( !soundManager::MusicPlaying(gpSoundManager) && gpAdvManager->ready == 1 )
    soundManager::SwitchAmbientMusic(
      gpSoundManager,
      (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
  if ( giDialogTimeout && KBTickCount() > giDialogTimeout )
  {
    *(_DWORD *)v5 = 512;
    gpWindowManager->buttonPressedCode = *((_DWORD *)v5 + 2);
    *((_DWORD *)v5 + 2) = 10;
    *((_DWORD *)v5 + 1) = *((_DWORD *)v5 + 2);
    giDialogTimeout = 0;
    return 2;
  }
  if ( *(_DWORD *)v5 == 1 )
  {
    if ( *((_DWORD *)v5 + 1) == 15 )
    {
      ++choice;
      if ( choice >= 3 )
        choice = 0;
      UpdateArenaIcons();
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
          choice = *((_DWORD *)v5 + 2) - 100;
          NormalDialog(gStatDesc[choice], 4, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      return 1;
    }
    v2 = *((_DWORD *)v5 + 2);
    if ( v2 >= 100 )
    {
      if ( v2 <= 102 )
      {
        choice = *((_DWORD *)v5 + 2) - 100;
        UpdateArenaIcons();
      }
      else if ( v2 == 30722 )
      {
        gpWindowManager->buttonPressedCode = *((_DWORD *)v5 + 2);
        *((_DWORD *)v5 + 2) = 10;
        *((_DWORD *)v5 + 1) = *((_DWORD *)v5 + 2);
        giDialogTimeout = 0;
        return 2;
      }
    }
  }
  return 1;
}