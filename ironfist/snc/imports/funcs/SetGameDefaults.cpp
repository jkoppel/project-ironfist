{
  BOOL *v0; // eax@1
  signed int v1; // ebx@2
  signed int v2; // eax@6
  int v3; // esi@6
  signed int v4; // esi@6
  int v5; // edi@6
  signed int v6; // esi@6
  int v7; // edi@6
  int v8; // eax@6
  signed __int64 v9; // qax@6
  int result; // eax@6
  signed __int64 v11; // qt2@6

  v0 = &bMenu + 5;
  *(_DWORD *)&Data = 1;
  *(_DWORD *)&soundVolume = 1;
  *(_DWORD *)&shouldAutosave = 1;
  *(_DWORD *)&showRoute = 1;
  do
  {
    v1 = giMainVideoModeWidth;
    *(v0 - 5) = 1;
    *(v0 - 4) = 10;
    *(v0 - 3) = 10;
    v0[1] = 0;
    *v0 = 1;
    if ( v1 > 640 )
    {
      *(v0 - 2) = 640;
      *(v0 - 1) = 480;
    }
    else
    {
      *(v0 - 2) = 480;
      *(v0 - 1) = 360;
    }
    v0 += 7;
  }
  while ( (unsigned int)v0 < (unsigned int)&showCombatGrid );
  *(_DWORD *)&showCombatGrid = 0;
  *(_DWORD *)&showCombatMouseHex = 0;
  combatShadeLevel = 0;
  *(_DWORD *)&combatArmyInfoLevel = 0;
  *(_DWORD *)&evilInterfaceUsage = 0;
  *(_DWORD *)&useOpera = 1;
  *(_DWORD *)&quickCombatLevel = 0;
  *(_DWORD *)&combatSpeed = 0;
  *(_DWORD *)&autoCombatUseSpells = 0;
  *(_DWORD *)&blackoutComputer = 0;
  *(_DWORD *)&currentMapOffset = 0;
  v2 = rand();
  *(_DWORD *)&showObjectBoxes = 0;
  *(_DWORD *)&editorScreenAnimation = 0;
  *(_DWORD *)&editorPaletteCycling = 0;
  *(_DWORD *)&firstMapOffset = v2 % 32001;
  gbFirstTimeThrough = 1;
  *(_DWORD *)&slowVideo = 3;
  *(_DWORD *)&gConfig = 3;
  *(_DWORD *)&walkSpeed = 2;
  strcpy((char *)&networkDefaultName, "The Unknown Hero");
  *(_DWORD *)&uniqueSystemID = 0;
  v3 = (signed int)rand() % 999999 + 1;
  v4 = KBTickCount() + v3;
  *(&uniqueSystemID + 2) = byte_51E6E4[v4 % 36];
  v5 = (signed int)rand() % 999999 + 1;
  v6 = v5 + KBTickCount() + v4;
  *(&uniqueSystemID + 1) = byte_51E6E4[v6 % 36];
  v7 = (signed int)rand() % 999999 + 1;
  v8 = KBTickCount();
  byte_5248D7 = 0;
  v9 = v6 + v7 + v8;
  v11 = v9 % 26;
  result = v9 / 26;
  uniqueSystemID = v11 + 65;
  return result;
}