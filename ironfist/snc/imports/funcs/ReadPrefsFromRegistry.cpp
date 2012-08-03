{
  int v0; // ecx@8
  DWORD cbData; // [sp+Ch] [bp-D4h]@2
  HKEY hKey; // [sp+10h] [bp-D0h]@1
  DWORD Type; // [sp+14h] [bp-CCh]@2
  const CHAR SubKey; // [sp+18h] [bp-C8h]@1
  char v5; // [sp+7Ch] [bp-64h]@1

  strcpy(&v5, (const char *)&unk_51E728);
  strcpy((char *)&SubKey, "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0");
  hKey = 0;
  if ( !RegCreateKeyA(HKEY_LOCAL_MACHINE, &SubKey, &hKey) )
  {
    cbData = 4;
    if ( RegQueryValueExA(hKey, "Music Volume", 0, &Type, &Data, &cbData) )
    {
      *(&gConfig + 412) = 0;
      memset(&gConfig, 0, 0x19Cu);
      *(&gConfig + 412) = 0;
      strcpy((char *)&unk_5248BC, "AUTO");
      strcpy((char *)&unk_5248C9, "AUTO");
      *(_DWORD *)&useCDMusic = 1;
      SetGameDefaults();
      RegCloseKey(hKey);
      UpdateSystemOptionsMenu();
      WritePrefsToRegistry();
    }
    else
    {
      RegQueryValueExA(hKey, "Music Volume", 0, &Type, &Data, &cbData);
      RegQueryValueExA(hKey, "Sound Volume", 0, &Type, &soundVolume, &cbData);
      RegQueryValueExA(hKey, "Walk Speed", 0, &Type, &walkSpeed, &cbData);
      RegQueryValueExA(hKey, "Computer Walk Speed", 0, &Type, &gConfig, &cbData);
      RegQueryValueExA(hKey, "Show Route", 0, &Type, &showRoute, &cbData);
      RegQueryValueExA(hKey, "Blackout Computer", 0, &Type, &blackoutComputer, &cbData);
      RegQueryValueExA(hKey, "Sound Quality", 0, &Type, &useCDMusic, &cbData);
      RegQueryValueExA(hKey, "Use Opera", 0, &Type, &useOpera, &cbData);
      RegQueryValueExA(hKey, "Direct Connect Com Port", 0, &Type, &directConnectComPort, &cbData);
      RegQueryValueExA(hKey, "Direct Connect Baud Rate", 0, &Type, &directConnectBaudRate, &cbData);
      RegQueryValueExA(hKey, "Modem Com Port", 0, &Type, &modemComPort, &cbData);
      RegQueryValueExA(hKey, "Modem Baud Rate", 0, &Type, &modemBaudRate, &cbData);
      cbData = 99;
      RegQueryValueExA(hKey, "Modem Init String", 0, &Type, &modemInitString, &cbData);
      cbData = 4;
      RegQueryValueExA(hKey, "Unique System ID", 0, &Type, &uniqueSystemID, &cbData);
      *(&uniqueSystemID + 3) = 0;
      cbData = 31;
      RegQueryValueExA(hKey, "Network Default Name", 0, &Type, &networkDefaultName, &cbData);
      cbData = 4;
      RegQueryValueExA(hKey, "Autosave", 0, &Type, &shouldAutosave, &cbData);
      RegQueryValueExA(hKey, "Slow Video", 0, &Type, &slowVideo, &cbData);
      RegQueryValueExA(hKey, "Show Combat Grid", 0, &Type, &showCombatGrid, &cbData);
      RegQueryValueExA(hKey, "Show Combat Mouse Hex", 0, &Type, &showCombatMouseHex, &cbData);
      RegQueryValueExA(hKey, "Combat Shade Level", 0, &Type, (LPBYTE)&combatShadeLevel, &cbData);
      RegQueryValueExA(hKey, "Combat Army Info Level", 0, &Type, &combatArmyInfoLevel, &cbData);
      RegQueryValueExA(hKey, "Evil Interface Usage", 0, &Type, &evilInterfaceUsage, &cbData);
      RegQueryValueExA(hKey, "Quick Combat Level", 0, &Type, &quickCombatLevel, &cbData);
      RegQueryValueExA(hKey, "Combat Speed", 0, &Type, &combatSpeed, &cbData);
      RegQueryValueExA(hKey, "Auto Combat Use Spells", 0, &Type, &autoCombatUseSpells, &cbData);
      RegQueryValueExA(hKey, "First Map Offset", 0, &Type, &firstMapOffset, &cbData);
      RegQueryValueExA(hKey, "Current Map Offset", 0, &Type, &currentMapOffset, &cbData);
      RegQueryValueExA(hKey, "Show Object Boxes", 0, &Type, &showObjectBoxes, &cbData);
      RegQueryValueExA(hKey, "Editor Screen Animation", 0, &Type, &editorScreenAnimation, &cbData);
      RegQueryValueExA(hKey, "Editor Palette Cycling", 0, &Type, &editorPaletteCycling, &cbData);
      RegQueryValueExA(hKey, "Main Game Show Menu", 0, &Type, (LPBYTE)&bMenu, &cbData);
      RegQueryValueExA(hKey, "Main Game X", 0, &Type, (LPBYTE)&bMenu + 4, &cbData);
      RegQueryValueExA(hKey, "Main Game Y", 0, &Type, (LPBYTE)&bMenu + 8, &cbData);
      RegQueryValueExA(hKey, "Main Game Width", 0, &Type, (LPBYTE)&bMenu + 12, &cbData);
      RegQueryValueExA(hKey, "Main Game Height", 0, &Type, (LPBYTE)&bMenu + 16, &cbData);
      RegQueryValueExA(hKey, "Main Game Full Screen", 0, &Type, (LPBYTE)&bMenu + 20, &cbData);
      RegQueryValueExA(hKey, "Main Game Color Mouse Cursor", 0, &Type, (LPBYTE)&bMenu + 24, &cbData);
      RegQueryValueExA(hKey, "Editor Show Menu", 0, &Type, (LPBYTE)&bMenu + 28, &cbData);
      RegQueryValueExA(hKey, "Editor X", 0, &Type, (LPBYTE)&bMenu + 32, &cbData);
      RegQueryValueExA(hKey, "Editor Y", 0, &Type, (LPBYTE)&bMenu + 36, &cbData);
      RegQueryValueExA(hKey, "Editor Width", 0, &Type, (LPBYTE)&bMenu + 40, &cbData);
      RegQueryValueExA(hKey, "Editor Height", 0, &Type, (LPBYTE)&bMenu + 44, &cbData);
      RegQueryValueExA(hKey, "Editor Full Screen", 0, &Type, (LPBYTE)&bMenu + 48, &cbData);
      RegQueryValueExA(hKey, "Editor Color Mouse Cursor", 0, &Type, (LPBYTE)&bMenu + 52, &cbData);
      cbData = 99;
      if ( RegQueryValueExA(hKey, "AppPath", 0, &Type, &gcRegAppPath, &cbData) )
        strcpy((char *)&gcRegAppPath, (const char *)&unk_51EAC8);
      if ( RegQueryValueExA(hKey, "CDDrive", 0, &Type, &gcRegCDRomPath, &cbData) )
        strcpy((char *)&gcRegCDRomPath, (const char *)&unk_51EAD4);
      RegCloseKey(hKey);
      v0 = 28 * giCurExe;
      if ( *(&bMenu + 7 * giCurExe + 3) <= 0 )
        *(BOOL *)((char *)&bMenu + v0 + 12) = 320;
      if ( *(BOOL *)((char *)&bMenu + v0 + 16) <= 0 )
        *(BOOL *)((char *)&bMenu + v0 + 16) = 240;
      if ( *(BOOL *)((char *)&bMenu + v0 + 4) < 0 )
        *(BOOL *)((char *)&bMenu + v0 + 4) = 0;
      if ( *(BOOL *)((char *)&bMenu + v0 + 4) > giMainVideoModeHeight - 200 )
        *(BOOL *)((char *)&bMenu + v0 + 4) = giMainVideoModeHeight - 200;
      if ( *(BOOL *)((char *)&bMenu + v0 + 8) < 0 )
        *(BOOL *)((char *)&bMenu + v0 + 8) = 0;
      if ( *(BOOL *)((char *)&bMenu + v0 + 8) > giMainVideoModeWidth - 200 )
        *(BOOL *)((char *)&bMenu + v0 + 8) = giMainVideoModeWidth - 200;
    }
  }
}