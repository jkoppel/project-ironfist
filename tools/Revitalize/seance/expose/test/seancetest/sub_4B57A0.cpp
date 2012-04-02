void __stdcall sub_4B57A0(int a1, int a2, int a3)
{
  int v3; // ST14_4@1
  char *v4; // eax@1
  double v5; // st7@14
  float v6; // ST3C_4@15
  signed int v7; // [sp+18h] [bp-34h]@3
  signed int v8; // [sp+1Ch] [bp-30h]@9
  signed int i; // [sp+20h] [bp-2Ch]@3
  signed int j; // [sp+20h] [bp-2Ch]@10
  signed int k; // [sp+20h] [bp-2Ch]@20
  float v12; // [sp+24h] [bp-28h]@12
  int creatureType; // [sp+28h] [bp-24h]@3
  int arr[7]; // [sp+2Ch] [bp-20h]@20
  float v15; // [sp+48h] [bp-4h]@9

  v3 = *(_BYTE *)a1;
  v4 = getCreatureSingularName(dwelling_creatures[*(_BYTE *)(a1 + 3)][a2]);
  sprintf(globBuf, "Player %d built %d %s in town %d.\n", curPlayerIdx, a3, v4, v3);
  debugLog(globBuf);
  if ( debugLogLevel >= 3 )
  {
    sub_4CAA50(globBuf);
    sleep(1500);
  }
  creatureType = dwelling_creatures[*(_BYTE *)(a1 + 3)][a2];
  v7 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(_BYTE *)(i + a1 + 8) == -1 || *(_BYTE *)(i + a1 + 8) == creatureType )
      v7 = 1;
  }
  v15 = 1000000000.0;
  v8 = -1;
  if ( !v7 )
  {
    for ( j = 0; j < 5; ++j )
    {
      v12 = (double)((signed int)*(_WORD *)(a1 + 2 * j + 13) * creature_table[*(_BYTE *)(j + a1 + 8)].fight_value);
      if ( creature_table[*(_BYTE *)(j + a1 + 8)].faction != *(_BYTE *)(a1 + 3) )
        v12 = v12 * 0.35;
      v5 = ((double)creature_table[*(_BYTE *)(j + a1 + 8)].fight_value + 500.0) / 500.0 * v12;
      if ( v5 < v15 )
      {
        v6 = v5;
        v15 = v6;
        v8 = j;
      }
    }
    if ( v8 == -1 )
      v8 = 0;
    curPlayer->resources[6] += *(_WORD *)(a1 + 2 * v8 + 13) * creature_table[*(_BYTE *)(v8 + a1 + 8)].cost;
    *(_BYTE *)(v8 + a1 + 8) = -1;
    *(_WORD *)(a1 + 2 * v8 + 13) = 0;
  }
  getCreatureCosts(creatureType, arr);
  for ( k = 0; k < 7; ++k )
    curPlayer->resources[k] -= a3 * arr[k];
  *(_WORD *)(a1 + 2 * a2 + 30) -= a3;
  ArmyInfo::addCreatures((ArmyInfo *)(a1 + 8), creatureType, a3, -1);
  unknown_libname_21();
}
