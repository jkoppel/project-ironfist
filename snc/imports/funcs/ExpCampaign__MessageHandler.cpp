{
  signed int v2; // [sp+Ch] [bp-14h]@21
  int v3; // [sp+14h] [bp-Ch]@8
  void *v4; // [sp+18h] [bp-8h]@1
  int v5; // [sp+1Ch] [bp-4h]@10

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
    goto LABEL_41;
  if ( v3 == 13 )
  {
    v2 = *((_DWORD *)v4 + 2);
    if ( v2 > 30721 )
    {
      if ( v2 != 30722 )
        return 1;
      if ( !dword_53049B )
      {
        if ( !byte_53045C[dword_530493] )
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
        dword_530454 = dword_530493;
      }
    }
    else if ( v2 != 30721 && v2 != 901 )
    {
      if ( v2 == 902 )
      {
        ExpCampaign::ReplaySmacker(&xCampaign);
        heroWindow::DrawWindow(dword_530497);
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
LABEL_41:
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
        v5 = *((_DWORD *)v4 + 2) - 850;
        if ( giDebugLevel >= 1 || byte_53045C[v5] || byte_530464[v5] )
        {
          dword_530493 = *((_DWORD *)v4 + 2) - 850;
          ExpCampaign::UpdateInfo(&xCampaign, 1);
        }
        break;
      case 0x32A:
      case 0x32B:
      case 0x32C:
        if ( !dword_53049B && byte_53045C[dword_530493] )
        {
          byte_530487[dword_530493] = *((_DWORD *)v4 + 2) - 42;
          ExpCampaign::UpdateInfo(&xCampaign, 1);
        }
        break;
      default:
        return 1;
    }
  }
  return 1;
}