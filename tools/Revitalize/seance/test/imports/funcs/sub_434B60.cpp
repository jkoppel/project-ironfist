{
  signed int i; // [sp+10h] [bp-4h]@1

  stru_5230F8.file = 0;
  stru_5230F8.sample = 0;
  dword_523408 = -1;
  dword_524234 = 0;
  isSurrendering = 0;
  *(_DWORD *)&gameObject->_10[616] = 0;
  strcpy(gameObject->_5, "brokena.mp2");
  gameObject->_5[20] = 0;
  dword_523F1C = 0;
  strcpy(byte_524240, byte_50D7B0);
  strcpy(&byte_524240[140], byte_50D7B4);
  strcpy(&byte_524240[280], byte_50D7B8);
  strcpy(&byte_524240[420], byte_50D7BC);
  byte_524C40 = 6;
  byte_524C41 = 6;
  byte_524C42 = 6;
  byte_524C43 = 6;
  dword_524784 = 0;
  dword_5249EC = 0;
  *(_DWORD *)&dword_5240A4 = 0;
  for ( i = 0; i < 10; ++i )
    *(&animationFrameSwitchTime + i) = 0;
  if ( debug_mode )
  {
    dfltMenu = LoadMenuA(hInstance, "mnuDflt");
    combatMenu = LoadMenuA(hInstance, "mnuCmbt");
    adventureMenu = LoadMenuA(hInstance, "mnuAdvD");
    townMenu = LoadMenuA(hInstance, "mnuTownD");
  }
  else
  {
    dfltMenu = LoadMenuA(hInstance, "mnuDflt");
    combatMenu = LoadMenuA(hInstance, "mnuCmbt");
    adventureMenu = LoadMenuA(hInstance, "mnuAdv");
    townMenu = LoadMenuA(hInstance, "mnuTown");
  }
}
