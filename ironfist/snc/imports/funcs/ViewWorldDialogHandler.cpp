{
  signed int v2; // [sp+1Ch] [bp-8Ch]@57
  int v3; // [sp+24h] [bp-84h]@4
  void *v4; // [sp+28h] [bp-80h]@1
  char v5; // [sp+2Ch] [bp-7Ch]@36
  tag_message a2; // [sp+48h] [bp-60h]@31
  int v7; // [sp+64h] [bp-44h]@21
  int v8; // [sp+68h] [bp-40h]@21
  int v9; // [sp+6Ch] [bp-3Ch]@29
  float v10; // [sp+88h] [bp-20h]@14
  int v11; // [sp+8Ch] [bp-1Ch]@31
  int v12; // [sp+90h] [bp-18h]@38
  int v13; // [sp+94h] [bp-14h]@42

  v4 = this;
  if ( !soundManager::MusicPlaying(gpSoundManager) )
    soundManager::SwitchAmbientMusic(
      gpSoundManager,
      (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
  if ( *(_DWORD *)v4 != 512 )
    return 1;
  v3 = *((_DWORD *)v4 + 1);
  if ( v3 == 12 )
  {
    if ( *((_DWORD *)v4 + 2) == 9
      && (giViewWorldScale != 12 || MAP_WIDTH > 36)
      && (giViewWorldScale != 6 || MAP_WIDTH > 72)
      && (giViewWorldScale != 4 || MAP_WIDTH > 108) )
    {
      switch ( MAP_HEIGHT )
      {
        case 36:
          v10 = 4.0;
          break;
        case 72:
          v10 = 2.0;
          break;
        case 108:
          v10 = 1.3333;
          break;
        default:
          v10 = 1.0;
          break;
      }
      v8 = *((_DWORD *)v4 + 4);
      v7 = *((_DWORD *)v4 + 5);
      v8 = (signed __int64)((double)(v8 - 480) / v10);
      v7 = (signed __int64)((double)(v7 - 16) / v10);
      iVWMapOriginX = v8 - iVWCenterOffset;
      iVWMapOriginY = v7 - iVWCenterOffset;
      if ( v8 - iVWCenterOffset < 0 )
        iVWMapOriginX = 0;
      if ( iVWMapOriginY < 0 )
        iVWMapOriginY = 0;
      if ( iVWViewableCells + iVWMapOriginX >= MAP_WIDTH )
        iVWMapOriginY = MAP_WIDTH - iVWViewableCells;
      if ( iVWMapOriginY + iVWViewableCells >= MAP_HEIGHT )
        iVWMapOriginY = MAP_HEIGHT - iVWViewableCells;
      advManager::UpdateRadar((int)gpAdvManager, 1, 0);
      advManager::VWCompleteDraw(gpAdvManager);
      v9 = 0;
      while ( v9 != 16 )
      {
        Process1WindowsMessage();
        memcpy(&v9, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
        memcpy(&v11, &v9, 0x1Cu);
        while ( v9 != 16 && v9 )
        {
          if ( v9 == 4 )
            memcpy(&v11, &v9, 0x1Cu);
          Process1WindowsMessage();
          memcpy(&v9, inputManager::GetEvent(gpInputManager, (tag_message *)&v5), 0x1Cu);
        }
        if ( v11 == 4 )
        {
          if ( v12 < 480 )
            v12 = 480;
          if ( v12 >= 624 )
            v12 = 2 * MAP_WIDTH + 479;
          if ( v13 < 16 )
            v13 = 16;
          if ( v13 >= 160 )
            v13 = 2 * MAP_HEIGHT + 15;
          (*(void (__thiscall **)(mouseManager *))(LODWORD(gpMouseManager->vtable) + 8))(gpMouseManager);
          v8 = (signed __int64)((double)(v12 - 480) / v10);
          v7 = (signed __int64)((double)(v13 - 16) / v10);
          iVWMapOriginX = v8 - iVWCenterOffset;
          iVWMapOriginY = v7 - iVWCenterOffset;
          if ( v8 - iVWCenterOffset < 0 )
            iVWMapOriginX = 0;
          if ( iVWMapOriginY < 0 )
            iVWMapOriginY = 0;
          if ( iVWViewableCells + iVWMapOriginX >= MAP_WIDTH )
            iVWMapOriginX = MAP_WIDTH - iVWViewableCells;
          if ( iVWMapOriginY + iVWViewableCells >= MAP_HEIGHT )
            iVWMapOriginY = MAP_HEIGHT - iVWViewableCells;
          advManager::UpdateRadar((int)gpAdvManager, 1, 0);
          advManager::VWCompleteDraw(gpAdvManager);
          v11 = 0;
        }
      }
    }
    return 1;
  }
  if ( v3 == 13 )
  {
    v2 = *((_DWORD *)v4 + 2);
    if ( v2 > 30723 )
    {
      if ( v2 < 30725 || v2 > 30726 )
        return 1;
    }
    else if ( v2 < 30720 )
    {
      if ( v2 == 2 )
      {
        advManager::VWCleanup();
        if ( giViewWorldScale == 12 )
        {
          giViewWorldScale = 6;
        }
        else if ( giViewWorldScale == 6 )
        {
          giViewWorldScale = 4;
        }
        else
        {
          giViewWorldScale = 12;
        }
        advManager::VWInit(gpAdvManager, iVWCenterOffset + iVWMapOriginX, iVWMapOriginY + iVWCenterOffset);
        advManager::VWCompleteDraw(gpAdvManager);
      }
      return 1;
    }
    gpWindowManager->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    return 2;
  }
  return 1;
}