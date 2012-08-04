{
  signed int v2; // eax@4
  int v3; // edx@14
  int v4; // edx@14
  signed int v5; // eax@25
  signed int v6; // eax@58
  int v7; // eax@58
  void *v8; // [sp+1Ch] [bp-148h]@1
  tag_message a2a; // [sp+24h] [bp-140h]@30
  int this; // [sp+40h] [bp-124h]@7
  int v11; // [sp+44h] [bp-120h]@79
  void *v12; // [sp+48h] [bp-11Ch]@14
  int v13; // [sp+4Ch] [bp-118h]@2
  int v14; // [sp+50h] [bp-114h]@7
  int v15; // [sp+54h] [bp-110h]@2
  tag_message v16; // [sp+58h] [bp-10Ch]@30
  int v17; // [sp+74h] [bp-F0h]@2
  int v18; // [sp+78h] [bp-ECh]@7
  int v19; // [sp+7Ch] [bp-E8h]@12
  tag_message evt; // [sp+80h] [bp-E4h]@12
  int v21; // [sp+9Ch] [bp-C8h]@12
  int i; // [sp+A0h] [bp-C4h]@72
  int v23; // [sp+A4h] [bp-C0h]@58
  int v24; // [sp+A8h] [bp-BCh]@12
  int v25; // [sp+ACh] [bp-B8h]@2
  heroWindow *window; // [sp+B0h] [bp-B4h]@8
  int v27; // [sp+B4h] [bp-B0h]@42
  char a1a; // [sp+B8h] [bp-ACh]@12
  char v29[151]; // [sp+B9h] [bp-ABh]@67
  int v30; // [sp+150h] [bp-14h]@12
  int v31; // [sp+154h] [bp-10h]@12
  int v32; // [sp+158h] [bp-Ch]@12
  int v33; // [sp+15Ch] [bp-8h]@12
  int v34; // [sp+160h] [bp-4h]@2

  v8 = a2;
  if ( !gbRemoteOn )
    return;
  v34 = 120;
  v13 = 1;
  v17 = 20;
  v15 = 54;
  v25 = 0;
  if ( a1 )
  {
    if ( (signed int)a2 < 0 )
    {
      sprintf(gText, a1);
      gText[120] = 0;
      AddNetBoxLine(gText, 6);
    }
    else
    {
      sprintf(gText, "%s:  %s", (char *)&gsNetPlayerInfo + 34 * (_DWORD)a2 + 4, a1);
      gText[120] = 0;
      v2 = NetPosToGamePos(v8);
      AddNetBoxLine(gText, gpGame->players[v2].color);
    }
    v25 = KBTickCount();
  }
  v18 = 0;
  v14 = bShowIt;
  bShowIt = 1;
  gbMoveShown = 0;
  this = (int)operator new(68);
  if ( this )
    window = heroWindow::heroWindow((heroWindow *)this, 0, 411, "netbox.bin");
  else
    window = 0;
  if ( !window )
    MemError();
  evt.eventCode = 512;
  evt.xCoordOrKeycode = 3;
  evt.yCoord = 1;
  evt.payload = cNetBoxLine;
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 2;
  evt.payload = &cNetBoxLine[140];
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 3;
  evt.payload = &cNetBoxLine[280];
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 4;
  evt.payload = &cNetBoxLine[420];
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.xCoordOrKeycode = 4;
  evt.yCoord = 20;
  evt.payload = (void *)(cNetBoxColor + 1);
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 21;
  evt.payload = (void *)(byte_524C41 + 1);
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 22;
  evt.payload = (void *)(byte_524C42 + 1);
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 23;
  evt.payload = (void *)(byte_524C43 + 1);
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  evt.yCoord = 24;
  evt.payload = (void *)(gpGame->players[NetPosToGamePos((void *)giThisNetPos)].color + 1);
  heroWindow::BroadcastMessage(window, (Event *)&evt);
  heroWindowManager::AddWindow(gpWindowManager, window, -1, 1);
  v30 = 0;
  v31 = 0;
  v32 = 1;
  v33 = 0;
  v19 = 0;
  v24 = 1;
  v21 = 0;
  strcpy(&a1a, byte_50D8C4);
  inputManager::SetKeyCodeType(gpInputManager, 0);
  while ( !v31 )
  {
    PollSound();
    v12 = GetRemoteData(0, v3);
    if ( v12 )
    {
      if ( *((_BYTE *)v12 + 5) == 3 )
      {
        v12 = GetRemoteData(1, v4);
        if ( *((_BYTE *)v12 + 6) == 41 )
        {
          dword_4F1CC0 = 1;
          if ( gpAdvManager->ready == 1 )
          {
            bShowIt = v14;
            advManager::ProcessIncomingGroupMapChange(gpAdvManager, (char *)v12 + 9);
            bShowIt = 1;
            v21 = 1;
          }
          dword_4F1CC0 = 0;
          v32 = 1;
        }
      }
      else if ( *((_BYTE *)v12 + 5) == 2 )
      {
        if ( *((_BYTE *)v12 + 6) == 11 )
        {
          v12 = GetRemoteData(1, v4);
          sprintf(gText, "%s:  %s", (char *)&gsNetPlayerInfo + 34 * *(_BYTE *)v12 + 4, (char *)v12 + 9);
          v5 = NetPosToGamePos((void *)*(_BYTE *)v12);
          AddNetBoxLine(gText, gpGame->players[v5].color);
          v24 = 1;
          if ( v25 )
            v25 = KBTickCount();
        }
        else
        {
          AddNetBoxLine("[ Incoming data, must exit... ]", 6);
          v24 = 1;
          v30 = 1;
        }
      }
      else
      {
        v12 = GetRemoteData(1, v4);
      }
    }
    Process1WindowsMessage();
    memcpy(&v16, inputManager::GetEvent(gpInputManager, &a2a), sizeof(v16));
    if ( v16.eventCode == 1 )
    {
      v25 = 0;
      if ( v16.xCoordOrKeycode <= 27 )
      {
        if ( v16.xCoordOrKeycode == 27 )
          goto LABEL_32;
        if ( v16.xCoordOrKeycode == 10 )
        {
          v19 = 1;
          goto LABEL_54;
        }
LABEL_37:
        if ( LOBYTE(v16.xCoordOrKeycode) >= 0x20u )
        {
          if ( LOBYTE(v16.xCoordOrKeycode) <= 0x7Fu )
          {
            if ( v18 < 93 )
            {
              if ( v16.xCoordOrKeycode )
              {
                *(&a1a + v18) = 0;
                v27 = font::LineWidth(smallFont, &a1a);
                if ( v27 + 50 < 602 )
                {
                  *(&a1a + v18++) = LOBYTE(v16.xCoordOrKeycode);
                  v32 = 1;
                  v33 = 0;
                }
              }
            }
          }
        }
        goto LABEL_54;
      }
      if ( v16.xCoordOrKeycode != 127 )
      {
        if ( v16.xCoordOrKeycode == 0x3B00 )
        {
LABEL_32:
          v31 = 1;
          goto LABEL_54;
        }
        goto LABEL_37;
      }
      if ( v18 > 0 )
        --v18;
      v32 = 1;
      v33 = 1;
    }
LABEL_54:
    if ( !v32 && KBTickCount() > glTimers )
    {
      v33 = 1 - v33;
      v32 = 1;
    }
    if ( v19 )
    {
      v19 = 0;
      *(&a1a + v18) = 0;
      v6 = NetPosToGamePos((void *)giThisNetPos);
      AddNetBoxLine(&a1a, gpGame->players[v6].color);
      v7 = strlen((int)&a1a);
      v23 = TransmitRemoteData(&a1a, 127, v7 + 1, 11, 1, 1, -1);
      if ( !v23 )
        ShutDown(0);
      v18 = 0;
      strcpy(&a1a, byte_50D8F0);
      v32 = 1;
      v24 = 1;
    }
    if ( v24 )
    {
      v24 = 0;
      evt.eventCode = 512;
      evt.xCoordOrKeycode = 3;
      evt.yCoord = 1;
      evt.payload = cNetBoxLine;
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.yCoord = 2;
      evt.payload = &cNetBoxLine[140];
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.yCoord = 3;
      evt.payload = &cNetBoxLine[280];
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.yCoord = 4;
      evt.payload = &cNetBoxLine[420];
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.xCoordOrKeycode = 4;
      evt.yCoord = 20;
      evt.payload = (void *)(cNetBoxColor + 1);
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.yCoord = 21;
      evt.payload = (void *)(byte_524C41 + 1);
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.yCoord = 22;
      evt.payload = (void *)(byte_524C42 + 1);
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      evt.yCoord = 23;
      evt.payload = (void *)(byte_524C43 + 1);
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      heroWindow::DrawWindow(window);
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 411, 0x27Fu, 68);
    }
    if ( v32 )
    {
      v32 = 0;
      glTimers = KBTickCount() + 360;
      if ( v33 )
        *(&a1a + v18) = 95;
      else
        *(&a1a + v18) = 31;
      v29[v18] = 0;
      evt.eventCode = 512;
      evt.xCoordOrKeycode = 3;
      evt.yCoord = 5;
      evt.payload = &a1a;
      heroWindow::BroadcastMessage(window, (Event *)&evt);
      heroWindow::DrawWindow(window);
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 465, 0x27Fu, 12);
    }
    if ( v25 && KBTickCount() > v25 + 6000 )
      v31 = 1;
    if ( v30 )
    {
      for ( i = 0; i < 20; ++i )
      {
        PollSound();
        DelayMilli(75);
      }
      v31 = 1;
    }
  }
  inputManager::SetKeyCodeType(gpInputManager, 1);
  if ( v21 && gbMoveShown )
  {
    gbDrawWindowBackground = 0;
    heroWindowManager::RemoveWindow(gpWindowManager, window);
    gbDrawWindowBackground = 1;
    v11 = bShowIt;
    bShowIt = 1;
    advManager::RedrawAdvScreen(gpAdvManager, 1, 0);
    bShowIt = v11;
  }
  else
  {
    heroWindowManager::RemoveWindow(gpWindowManager, window);
  }
  bShowIt = v14;
}