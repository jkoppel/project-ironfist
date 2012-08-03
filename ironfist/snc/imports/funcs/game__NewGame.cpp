{
  int v2; // edx@22
  int v3; // eax@49
  int v4; // eax@52
  int v5; // [sp+Ch] [bp-1F0h]@24
  int v6; // [sp+10h] [bp-1ECh]@10
  heroWindow *v8; // [sp+28h] [bp-1D4h]@73
  heroWindow *v9; // [sp+2Ch] [bp-1D0h]@69
  heroWindow *v10; // [sp+30h] [bp-1CCh]@65
  heroWindow *v11; // [sp+38h] [bp-1C4h]@31
  heroWindow *thisa; // [sp+40h] [bp-1BCh]@5
  char v13; // [sp+44h] [bp-1B8h]@59
  int v14; // [sp+B8h] [bp-144h]@59
  char v15; // [sp+BCh] [bp-140h]@61
  int evt; // [sp+1BCh] [bp-40h]@34
  int v17; // [sp+1C0h] [bp-3Ch]@34
  int v18; // [sp+1C4h] [bp-38h]@34
  int v19; // [sp+1D4h] [bp-28h]@34
  int v20; // [sp+1D8h] [bp-24h]@21
  int v21; // [sp+1DCh] [bp-20h]@21
  void *v22; // [sp+1E0h] [bp-1Ch]@22
  heroWindow *window; // [sp+1E4h] [bp-18h]@6
  int v24; // [sp+1E8h] [bp-14h]@54
  int i; // [sp+1ECh] [bp-10h]@17
  bool v26; // [sp+1F0h] [bp-Ch]@1
  char v27; // [sp+1F4h] [bp-8h]@36
  int v28; // [sp+1F8h] [bp-4h]@36

  v26 = 1;
  *(_DWORD *)&this->_10[27] = 0;
  if ( (!gbRemoteOn || !giThisNetPos) && (!gbRemoteOn || !xNetHasOldPlayers) )
  {
    thisa = (heroWindow *)operator new(68);
    if ( thisa )
      window = heroWindow::heroWindow(thisa, 405, 8, "x_mapmnu.bin");
    else
      window = 0;
    if ( !window )
      MemError();
    heroWindowManager::DoDialog(gpWindowManager, window, (int (__fastcall *)(tag_message *))ExpStdGameHandler, 0);
    operator delete(window);
    v6 = LOWORD(gpWindowManager->buttonPressedCode);
    switch ( v6 )
    {
      case 1:
        LOBYTE(xIsExpansionMap) = 0;
        break;
      case 2:
        LOBYTE(xIsExpansionMap) = 1;
        break;
      case 30721:
        return 0;
    }
  }
  game::SetupNetPlayerNames();
  glTimers = 0;
  for ( i = 0; i < 3; ++i )
  {
    (&cTextReceivedBuffer)[4 * i] = (char *)BaseAlloc(0x65u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 45);
    strcpy((&cTextReceivedBuffer)[4 * i], byte_5111B0);
  }
  cNGKPCore = (char *)BaseAlloc(0x69u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 48);
  cNGKPDisplay = (char *)BaseAlloc(0x69u, "F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 49);
  strcpy(cNGKPCore, byte_5111F4);
  strcpy(cNGKPDisplay, byte_5111F8);
  NGKPcursorIndex = 0;
  NGKPBkg = resourceManager::GetIcon(gpResourceManager, "ngextra.icn");
  if ( gbWaitForRemoteReceive )
  {
    v20 = 0;
    v21 = 0;
    do
    {
      do
      {
        do
        {
          PollSound();
          v22 = GetRemoteData(1, v2);
        }
        while ( !v22 );
      }
      while ( *((_BYTE *)v22 + 5) != 2 );
      v5 = *((_BYTE *)v22 + 6);
      if ( v5 == 52 )
      {
        memset(&this->_1[676], 0, 0x1A4u);
        memcpy(&this->_1[676], (char *)v22 + 9, 0x74u);
        v20 = 1;
      }
      else if ( v5 == 55 )
      {
        memcpy(&gsNetPlayerInfo, (char *)v22 + 9, 0xCCu);
        game::SetupNetPlayerNames();
        v21 = 1;
      }
    }
    while ( !v21 || !v20 );
    v11 = (heroWindow *)operator new(68);
    if ( v11 )
      *(_DWORD *)&this->_10[27] = heroWindow::heroWindow(v11, 190, 4, "ngmp.bin");
    else
      *(_DWORD *)&this->_10[27] = 0;
    game::InitNewGame((int)this, &this->_1[676]);
    game::InitNewGameWindow((int)this);
    game::UpdateNewGameWindow((int)this);
    evt = 512;
    v18 = 54;
    v17 = 5;
    v19 = 4096;
    heroWindow::BroadcastMessage(*(heroWindow **)&this->_10[27], (Event *)&evt);
    v17 = 6;
    v19 = 2;
    heroWindow::BroadcastMessage(*(heroWindow **)&this->_10[27], (Event *)&evt);
    v18 = 30722;
    v17 = 5;
    v19 = 4096;
    heroWindow::BroadcastMessage(*(heroWindow **)&this->_10[27], (Event *)&evt);
    v17 = 6;
    v19 = 2;
    heroWindow::BroadcastMessage(*(heroWindow **)&this->_10[27], (Event *)&evt);
    v18 = 30721;
    v17 = 5;
    v19 = 4096;
    heroWindow::BroadcastMessage(*(heroWindow **)&this->_10[27], (Event *)&evt);
    v17 = 6;
    v19 = 2;
    heroWindow::BroadcastMessage(*(heroWindow **)&this->_10[27], (Event *)&evt);
    gbNewGameDialogOver = 0;
    heroWindowManager::DoDialog(
      gpWindowManager,
      *(heroWindow **)&this->_10[27],
      (int (__fastcall *)(tag_message *))NewGameHandler,
      0);
    operator delete(*(void **)&this->_10[27]);
    v26 = gpWindowManager->buttonPressedCode != 30721;
  }
  else
  {
    while ( 1 )
    {
      v27 = 0;
      v28 = FindLastToken(this->_5, 46);
      if ( v28 )
      {
        if ( StrEqNoCase((int *)v28, (int *)".MX2") && xIsExpansionMap )
          v27 = 1;
        if ( StrEqNoCase((int *)v28, (int *)".MP2") && !xIsExpansionMap )
          v27 = 1;
      }
      if ( !v27 )
      {
        if ( xIsExpansionMap )
          strcpy(gpGame->_5, "arrax.mx2");
        else
          strcpy(gpGame->_5, "brokena.mp2");
        this->_5[20] = 0;
        this->_5[21] = iLastMsgNumHumanPlayers;
      }
      if ( iLastMsgNumHumanPlayers > 3 )
      {
        LOBYTE(v3) = stricmp(gpGame->_5, "brokena.mp2");
        if ( !v3 )
          strcpy(gpGame->_5, "slugfest.mp2");
      }
      if ( iLastMsgNumHumanPlayers > 1 )
      {
        LOBYTE(v4) = stricmp(gpGame->_5, "arrax.mx2");
        if ( !v4 )
          strcpy(gpGame->_5, "fullhse.mx2");
      }
      strcpy(gMapName, this->_5);
      v24 = GetMapHeader((int)this->_5, &this->_1[676]);
      if ( v24 )
      {
        if ( this->_1[703] <= iLastMsgNumHumanPlayers && this->_1[704] >= iLastMsgNumHumanPlayers )
          break;
      }
      game::GetMap(gpGame);
    }
    if ( gbRemoteOn )
    {
      memcpy(&v13, &gpGame->_1[676], 0x74u);
      v14 = TransmitRemoteData(&v13, 127, 0x74u, 52, 1, 1, -1);
      if ( !v14 )
        ShutDown(0);
      memcpy(&v15, &gsNetPlayerInfo, 0xCCu);
      v14 = TransmitRemoteData(&v15, 127, 0xCCu, 55, 1, 1, -1);
      if ( !v14 )
        ShutDown(0);
    }
    game::LoadGame(this, "origdata.bin", 1, 0);
    if ( iLastMsgNumHumanPlayers <= 1 )
    {
      v8 = (heroWindow *)operator new(68);
      if ( v8 )
        *(_DWORD *)&this->_10[27] = heroWindow::heroWindow(v8, 190, 33, "ngsp.bin");
      else
        *(_DWORD *)&this->_10[27] = 0;
    }
    else if ( iMPBaseType == 2 )
    {
      v10 = (heroWindow *)operator new(68);
      if ( v10 )
        *(_DWORD *)&this->_10[27] = heroWindow::heroWindow(v10, 190, 4, "nghs.bin");
      else
        *(_DWORD *)&this->_10[27] = 0;
    }
    else
    {
      v9 = (heroWindow *)operator new(68);
      if ( v9 )
        *(_DWORD *)&this->_10[27] = heroWindow::heroWindow(v9, 190, 4, "ngmp.bin");
      else
        *(_DWORD *)&this->_10[27] = 0;
    }
    if ( !*(_DWORD *)&this->_10[27] )
      MemError();
    SetWinText(*(heroWindow **)&this->_10[27], 7);
    game::InitNewGame((int)this, 0);
    game::InitNewGameWindow((int)this);
    game::UpdateNewGameWindow((int)this);
    gbNewGameShadowHidden = 0;
    gbNewGameDialogOver = 0;
    heroWindowManager::DoDialog(
      gpWindowManager,
      *(heroWindow **)&this->_10[27],
      (int (__fastcall *)(tag_message *))NewGameHandler,
      0);
    operator delete(*(void **)&this->_10[27]);
    if ( gpWindowManager->buttonPressedCode == 30721 )
    {
      v26 = 0;
    }
    else
    {
      this->numPlayers = this->_1[702];
      game::NewMap(this, gMapName);
    }
  }
  for ( i = 0; i < 3; ++i )
    BaseFree((&cTextReceivedBuffer)[4 * i], (int)"F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 286);
  BaseFree(cNGKPCore, (int)"F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 288);
  BaseFree(cNGKPDisplay, (int)"F:\\h2xsrc\\Source\\Newgame.cpp", word_51117C + 289);
  resourceManager::Dispose(gpResourceManager, (resource *)NGKPBkg);
  return v26;
}