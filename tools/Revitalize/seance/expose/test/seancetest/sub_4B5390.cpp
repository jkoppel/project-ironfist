void __stdcall sub_4B5390(signed int a1, signed int a2)
{
  int v2; // ST10_4@1
  char *v3; // eax@1
  signed int i; // [sp+10h] [bp-20h]@3
  int v5[7]; // [sp+14h] [bp-1Ch]@3

  v2 = *(_BYTE *)a1;
  v3 = buildingName(*(_BYTE *)(a1 + 3), a2);
  sprintf(globBuf, "Player %d built %s in town %d.\n", curPlayerIdx, v3, v2);
  debugLog(globBuf);
  if ( debugLogLevel >= 3 )
  {
    sub_4CAA50(globBuf);
    sleep(1500);
  }
  sub_432120(*(_BYTE *)(a1 + 3), a2, v5, *(_BYTE *)(a1 + 28));
  for ( i = 0; i < 7; ++i )
    curPlayer->resources[i] -= v5[i];
  Castle::buildBuilding((Castle *)a1, a2);
  unknown_libname_21();
}
