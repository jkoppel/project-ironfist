{
  int v0; // eax@49
  int v2; // [sp+Ch] [bp-5Ch]@45
  int v3; // [sp+10h] [bp-58h]@32
  signed int v4; // [sp+14h] [bp-54h]@25
  heroWindow *v5; // [sp+30h] [bp-38h]@40
  heroWindow *v6; // [sp+38h] [bp-30h]@27
  heroWindow *this; // [sp+40h] [bp-28h]@18
  int evt; // [sp+44h] [bp-24h]@24
  int v9; // [sp+48h] [bp-20h]@24
  int v10; // [sp+4Ch] [bp-1Ch]@24
  int v11; // [sp+5Ch] [bp-Ch]@24
  int window; // [sp+60h] [bp-8h]@19
  int v13; // [sp+64h] [bp-4h]@1

  LogStr("Setup 0");
  v13 = 1;
  xIsPlayingExpansionCampaign = 0;
  LOBYTE(xIsExpansionMap) = 0;
  gbInCampaign = 0;
  *(_DWORD *)gbCampaignSideChoice = 0;
  iMPExtendedType = 10;
  iMPBaseType = 10;
  iLastMsgNumHumanPlayers = 1;
  gbWaitForRemoteReceive = 0;
  gbDirectConnect = 0;
  gbInSetupDialog = 1;
  if ( giMenuCommand == -1 )
  {
    this = (heroWindow *)operator new(68);
    if ( this )
      window = (int)heroWindow::heroWindow(this, 405, 8, "stpnewgm.bin");
    else
      window = 0;
    if ( !window )
      MemError();
    if ( gbNoCDRom )
    {
      evt = 512;
      v9 = 5;
      v11 = 4096;
      v10 = 1;
      heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
      v10 = 2;
      heroWindow::BroadcastMessage((heroWindow *)window, (Event *)&evt);
    }
    heroWindowManager::DoDialog(
      gpWindowManager,
      (heroWindow *)window,
      (int (__fastcall *)(tag_message *))SetupGameHandler,
      0);
    operator delete((void *)window);
    v4 = LOWORD(gpWindowManager->buttonPressedCode);
    if ( v4 <= 30721 )
    {
      if ( v4 == 30721 )
      {
        v13 = 0;
        goto LABEL_69;
      }
      if ( v4 != 1 )
      {
        if ( v4 == 2 )
        {
          if ( (unsigned __int8)giSetupGameType == 1 )
          {
            v6 = (heroWindow *)operator new(68);
            if ( v6 )
              window = (int)heroWindow::heroWindow(v6, 405, 8, "x_loadcm.bin");
            else
              window = 0;
            if ( !window )
              MemError();
            heroWindowManager::DoDialog(
              gpWindowManager,
              (heroWindow *)window,
              (int (__fastcall *)(tag_message *))ExpLoadCampaignHandler,
              0);
            operator delete((void *)window);
            v3 = LOWORD(gpWindowManager->buttonPressedCode);
            switch ( v3 )
            {
              case 1:
                gbInCampaign = 1;
                break;
              case 2:
                xIsPlayingExpansionCampaign = 1;
                LOBYTE(xIsExpansionMap) = 1;
                break;
              case 30721:
                v13 = 0;
                goto LABEL_69;
            }
          }
          else
          {
            v5 = (heroWindow *)operator new(68);
            if ( v5 )
              window = (int)heroWindow::heroWindow(v5, 405, 8, "x_loadcm.bin");
            else
              window = 0;
            if ( !window )
              MemError();
            heroWindowManager::DoDialog(
              gpWindowManager,
              (heroWindow *)window,
              (int (__fastcall *)(tag_message *))ExpLoadCampaignHandler,
              0);
            operator delete((void *)window);
            v2 = LOWORD(gpWindowManager->buttonPressedCode);
            switch ( v2 )
            {
              case 1:
                gbInCampaign = 1;
                if ( !game::SetupCampaignGame() )
                {
                  v13 = 0;
                  goto LABEL_69;
                }
                break;
              case 2:
                xIsPlayingExpansionCampaign = 1;
                LOBYTE(xIsExpansionMap) = 1;
                v0 = ExpCampaign::Choose();
                ExpCampaign::InitNewCampaign((int)&xCampaign, v0);
                break;
              case 30721:
                v13 = 0;
                goto LABEL_69;
            }
          }
        }
        else if ( v4 == 3 && !game::SetupMultiPlayerGame() )
        {
          v13 = 0;
          goto LABEL_69;
        }
      }
    }
    LogStr(" Setup 1");
    if ( iMPBaseType == 1 || !iMPBaseType )
    {
      LogStr(" Setup 2");
      RemoteMain((void *)iMPExtendedType);
      LogStr(" Setup 3");
      if ( iMPExtendedType == 2 || iMPExtendedType == 4 )
        gbWaitForRemoteReceive = 1;
    }
  }
  else
  {
    switch ( giMenuCommand )
    {
      case 40110:
      case 40127:
        iLastMsgNumHumanPlayers = 2;
        iMPBaseType = 2;
        break;
      case 40111:
      case 40128:
        iLastMsgNumHumanPlayers = 3;
        iMPBaseType = 2;
        break;
      case 40112:
      case 40129:
        iLastMsgNumHumanPlayers = 4;
        iMPBaseType = 2;
        break;
      case 40114:
      case 40131:
        iMPBaseType = 1;
        iMPExtendedType = 1;
        goto LABEL_12;
      case 40115:
      case 40132:
        iMPBaseType = 1;
        iMPExtendedType = 2;
        goto LABEL_12;
      case 40117:
      case 40134:
        iMPBaseType = 0;
        iMPExtendedType = 3;
        goto LABEL_12;
      case 40118:
      case 40135:
        iMPBaseType = 0;
        iMPExtendedType = 4;
        goto LABEL_12;
      case 40120:
      case 40137:
        iMPBaseType = 0;
        iMPExtendedType = 3;
        gbDirectConnect = 1;
        goto LABEL_12;
      case 40121:
      case 40138:
        iMPBaseType = 0;
        iMPExtendedType = 4;
        gbDirectConnect = 1;
LABEL_12:
        LogStr("Setup 0a");
        RemoteMain((void *)iMPExtendedType);
        if ( iMPExtendedType == 2 || iMPExtendedType == 4 )
          gbWaitForRemoteReceive = 1;
        break;
      case 40102:
      case 40123:
        break;
    }
    giMenuCommand = -1;
    v13 = 1;
  }
LABEL_69:
  gbInSetupDialog = 0;
  return v13;
}