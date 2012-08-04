{
  signed int i; // [sp+10h] [bp-4h]@1

  NULL_SAMPLE2.file = 0;
  NULL_SAMPLE2.sample = 0;
  gGameCommand = -1;
  gPalette = 0;
  gbCombatSurrender = 0;
  *(_DWORD *)&gpGame->_10[616] = 0;
  strcpy(gpGame->_5, "brokena.mp2");
  gpGame->_5[20] = 0;
  gbInNewGameSetup = 0;
  strcpy(cNetBoxLine, byte_50D7B0);
  strcpy(&cNetBoxLine[140], byte_50D7B4);
  strcpy(&cNetBoxLine[280], byte_50D7B8);
  strcpy(&cNetBoxLine[420], byte_50D7BC);
  cNetBoxColor = 6;
  byte_524C41 = 6;
  byte_524C42 = 6;
  byte_524C43 = 6;
  ppMapExtra = 0;
  pwSizeOfMapExtra = 0;
  *(_DWORD *)&iMaxMapExtra = 0;
  for ( i = 0; i < 10; ++i )
    *(&glTimers + i) = 0;
  if ( gbCheatMenus )
  {
    hmnuDflt = LoadMenuA(hInstApp, "mnuDflt");
    hmnuCmbt = LoadMenuA(hInstApp, "mnuCmbt");
    hmnuAdv = LoadMenuA(hInstApp, "mnuAdvD");
    hmnuTown = LoadMenuA(hInstApp, "mnuTownD");
  }
  else
  {
    hmnuDflt = LoadMenuA(hInstApp, "mnuDflt");
    hmnuCmbt = LoadMenuA(hInstApp, "mnuCmbt");
    hmnuAdv = LoadMenuA(hInstApp, "mnuAdv");
    hmnuTown = LoadMenuA(hInstApp, "mnuTown");
  }
}