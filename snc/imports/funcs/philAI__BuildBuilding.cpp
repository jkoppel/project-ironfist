{
  int v2; // ST10_4@1
  char *v3; // eax@1
  signed int i; // [sp+10h] [bp-20h]@3
  int v5[7]; // [sp+14h] [bp-1Ch]@3

  v2 = *(_BYTE *)a1;
  v3 = GetBuildingName(*(_BYTE *)(a1 + 3), a2);
  sprintf(gText, "Player %d built %s in town %d.\n", giCurPlayer, v3, v2);
  LogStr(gText);
  if ( giDebugLevel >= 3 )
  {
    AiPrint(gText);
    DelayMilli(1500);
  }
  GetBuildingCost(*(_BYTE *)(a1 + 3), a2, v5, *(_BYTE *)(a1 + 28));
  for ( i = 0; i < 7; ++i )
    gpCurPlayer->resources[i] -= v5[i];
  town::BuildBuilding((town *)a1, a2);
  ShowStatus();
}