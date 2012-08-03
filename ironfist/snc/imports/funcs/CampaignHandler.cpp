{
  signed int v2; // [sp+Ch] [bp-1Ch]@28
  int v3; // [sp+14h] [bp-14h]@8
  void *v4; // [sp+18h] [bp-10h]@1
  char v5; // [sp+1Ch] [bp-Ch]@19
  char v6; // [sp+20h] [bp-8h]@14
  int v7; // [sp+24h] [bp-4h]@10
  signed int i; // [sp+24h] [bp-4h]@33

  v4 = this;
  if ( !soundManager::MusicPlaying(gpSoundManager) && gpAdvManager->ready == 1 )
    soundManager::SwitchAmbientMusic(
      gpSoundManager,
      (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
  if ( giDialogTimeout && KBTickCount() > giDialogTimeout )
  {
    *(_DWORD *)v4 = 512;
    gpWindowManager->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    giDialogTimeout = 0;
    return 2;
  }
  if ( *(_DWORD *)v4 != 512 )
    return 1;
  v3 = *((_DWORD *)v4 + 1);
  if ( v3 == 12 )
    goto LABEL_54;
  if ( v3 == 13 )
  {
    v2 = *((_DWORD *)v4 + 2);
    if ( v2 > 30721 )
    {
      if ( v2 != 30722 )
        return 1;
      if ( !bCampaignViewOnly )
      {
        if ( !*(&gpGame->_1[12 * iCurViewSide + 157] + iCurViewMap) )
        {
          NormalDialog(
            "The currently selected map is not a valid choice for your next scenario.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          return 1;
        }
        if ( iCurViewMap == 11 )
        {
          gpGame->field_4 = 4;
          gpGame->field_2 = 1 - gpGame->field_2;
          *(&gpGame->_1[12 * gpGame->field_4 + 157] + gpGame->field_2) = 1;
          *((_WORD *)&gpGame->_1[24 * gpGame->field_2 + 24] + gpGame->field_4) = *(_WORD *)&gpGame->_1[181];
          *(&gpGame->_1[12 * gpGame->field_2 + 133] + gpGame->field_4) = gpGame->_1[12 * (1 - gpGame->field_2) + 144];
          for ( i = 0; i < 12; ++i )
            gpGame->_1[i + 121] = 0;
        }
        else
        {
          gpGame->field_4 = iCurViewMap;
          gpGame->field_2 = iCurViewSide;
        }
      }
    }
    else if ( v2 != 30721 && v2 != 901 )
    {
      if ( v2 == 902 )
      {
        game::PlayPreScenarioSmacker((int)gpGame, iCurViewSide, iCurViewMap);
        heroWindow::DrawWindow(campWin);
      }
      return 1;
    }
    gpWindowManager->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    giDialogTimeout = 0;
    return 2;
  }
  if ( v3 == 14 )
  {
LABEL_54:
    switch ( *((_DWORD *)v4 + 2) )
    {
      case 0x352:
      case 0x353:
      case 0x354:
      case 0x355:
      case 0x356:
      case 0x357:
      case 0x358:
      case 0x359:
      case 0x35A:
      case 0x35B:
      case 0x35C:
      case 0x35D:
        v7 = *((_DWORD *)v4 + 2) - 850;
        if ( giDebugLevel >= 1
          || *(&gpGame->_1[12 * iCurViewSide + 157] + v7)
          || v7 < 11
          && (v7 < 4 ? (v6 = gpGame->field_3) : (v6 = gpGame->field_2), *(&gpGame->_1[12 * (unsigned __int8)v6] + v7)) )
        {
          iCurViewMap = *((_DWORD *)v4 + 2) - 850;
          if ( v7 < 4 )
            v5 = gpGame->field_3;
          else
            v5 = gpGame->field_2;
          iCurViewSide = (unsigned __int8)v5;
          game::CampaignInfoUpdate(gpGame, 1);
        }
        break;
      case 0x32A:
      case 0x32B:
      case 0x32C:
        if ( !bCampaignViewOnly && *(&gpGame->_1[12 * iCurViewSide + 157] + iCurViewMap) )
        {
          *(&gpGame->_1[12 * iCurViewSide + 133] + iCurViewMap) = *((_BYTE *)v4 + 8) - 42;
          game::CampaignInfoUpdate(gpGame, 1);
        }
        break;
      default:
        return 1;
    }
  }
  return 1;
}