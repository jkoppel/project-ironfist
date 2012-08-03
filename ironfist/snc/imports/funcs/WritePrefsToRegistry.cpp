{
  HKEY hKey; // [sp+Ch] [bp-CCh]@1
  const CHAR SubKey; // [sp+10h] [bp-C8h]@1
  char v2; // [sp+74h] [bp-64h]@1

  strcpy(&v2, (const char *)&unk_51EB30);
  strcpy((char *)&SubKey, "SOFTWARE\\New World Computing\\Heroes of Might and Magic 2\\1.0");
  hKey = 0;
  if ( !RegOpenKeyExA(HKEY_LOCAL_MACHINE, &SubKey, 0, 0xF003Fu, &hKey) )
  {
    RegSetValueExA(hKey, "Music Volume", 0, REG_DWORD, &Data, 4u);
    RegSetValueExA(hKey, "Sound Volume", 0, REG_DWORD, &soundVolume, 4u);
    RegSetValueExA(hKey, "Walk Speed", 0, REG_DWORD, &walkSpeed, 4u);
    RegSetValueExA(hKey, "Computer Walk Speed", 0, REG_DWORD, &gConfig, 4u);
    RegSetValueExA(hKey, "Show Route", 0, REG_DWORD, &showRoute, 4u);
    RegSetValueExA(hKey, "Blackout Computer", 0, REG_DWORD, &blackoutComputer, 4u);
    RegSetValueExA(hKey, "Sound Quality", 0, REG_DWORD, &useCDMusic, 4u);
    RegSetValueExA(hKey, "Use Opera", 0, REG_DWORD, &useOpera, 4u);
    RegSetValueExA(hKey, "Direct Connect Com Port", 0, REG_DWORD, &directConnectComPort, 4u);
    RegSetValueExA(hKey, "Direct Connect Baud Rate", 0, REG_DWORD, &directConnectBaudRate, 4u);
    RegSetValueExA(hKey, "Modem Com Port", 0, REG_DWORD, &modemComPort, 4u);
    RegSetValueExA(hKey, "Modem Baud Rate", 0, REG_DWORD, &modemBaudRate, 4u);
    RegSetValueExA(hKey, "Modem Init String", 0, REG_SZ, &modemInitString, 98u);
    RegSetValueExA(hKey, "Unique System ID", 0, REG_SZ, &uniqueSystemID, 4u);
    RegSetValueExA(hKey, "Network Default Name", 0, REG_SZ, &networkDefaultName, 30u);
    RegSetValueExA(hKey, "Autosave", 0, REG_DWORD, &shouldAutosave, 4u);
    RegSetValueExA(hKey, "Slow Video", 0, REG_DWORD, &slowVideo, 4u);
    RegSetValueExA(hKey, "Show Combat Grid", 0, REG_DWORD, &showCombatGrid, 4u);
    RegSetValueExA(hKey, "Show Combat Mouse Hex", 0, REG_DWORD, &showCombatMouseHex, 4u);
    RegSetValueExA(hKey, "Combat Shade Level", 0, REG_DWORD, (const BYTE *)&combatShadeLevel, 4u);
    RegSetValueExA(hKey, "Combat Army Info Level", 0, REG_DWORD, &combatArmyInfoLevel, 4u);
    RegSetValueExA(hKey, "Evil Interface Usage", 0, REG_DWORD, &evilInterfaceUsage, 4u);
    RegSetValueExA(hKey, "Quick Combat Level", 0, REG_DWORD, &quickCombatLevel, 4u);
    RegSetValueExA(hKey, "Combat Speed", 0, REG_DWORD, &combatSpeed, 4u);
    RegSetValueExA(hKey, "Auto Combat Use Spells", 0, REG_DWORD, &autoCombatUseSpells, 4u);
    RegSetValueExA(hKey, "First Map Offset", 0, REG_DWORD, &firstMapOffset, 4u);
    RegSetValueExA(hKey, "Current Map Offset", 0, REG_DWORD, &currentMapOffset, 4u);
    RegSetValueExA(hKey, "Show Object Boxes", 0, REG_DWORD, &showObjectBoxes, 4u);
    RegSetValueExA(hKey, "Editor Screen Animation", 0, REG_DWORD, &editorScreenAnimation, 4u);
    RegSetValueExA(hKey, "Editor Palette Cycling", 0, REG_DWORD, &editorPaletteCycling, 4u);
    RegSetValueExA(hKey, "Main Game Show Menu", REG_NONE, 4u, (const BYTE *)&bMenu, 4u);
    RegSetValueExA(hKey, "Main Game X", 0, REG_DWORD, (const BYTE *)&bMenu + 4, 4u);
    RegSetValueExA(hKey, "Main Game Y", 0, REG_DWORD, (const BYTE *)&bMenu + 8, 4u);
    RegSetValueExA(hKey, "Main Game Width", 0, REG_DWORD, (const BYTE *)&bMenu + 12, 4u);
    RegSetValueExA(hKey, "Main Game Height", 0, REG_DWORD, (const BYTE *)&bMenu + 16, 4u);
    RegSetValueExA(hKey, "Main Game Full Screen", 0, REG_DWORD, (const BYTE *)&bMenu + 20, 4u);
    RegSetValueExA(hKey, "Main Game Color Mouse Cursor", 0, REG_DWORD, (const BYTE *)&bMenu + 24, 4u);
    RegSetValueExA(hKey, "Editor Show Menu", 0, REG_DWORD, (const BYTE *)&bMenu + 28, 4u);
    RegSetValueExA(hKey, "Editor X", 0, REG_DWORD, (const BYTE *)&bMenu + 32, 4u);
    RegSetValueExA(hKey, "Editor Y", 0, REG_DWORD, (const BYTE *)&bMenu + 36, 4u);
    RegSetValueExA(hKey, "Editor Width", 0, REG_DWORD, (const BYTE *)&bMenu + 40, 4u);
    RegSetValueExA(hKey, "Editor Height", 0, REG_DWORD, (const BYTE *)&bMenu + 44, 4u);
    RegSetValueExA(hKey, "Editor Full Screen", 0, REG_DWORD, (const BYTE *)&bMenu + 48, 4u);
    RegSetValueExA(hKey, "Editor Color Mouse Cursor", 0, REG_DWORD, (const BYTE *)&bMenu + 52, 4u);
    RegCloseKey(hKey);
  }
}