{
  int v2; // ebx@6
  void *v4; // [sp+14h] [bp-100h]@1
  int v5; // [sp+18h] [bp-FCh]@24
  int v6; // [sp+1Ch] [bp-F8h]@30
  int v7; // [sp+20h] [bp-F4h]@12
  char v8; // [sp+24h] [bp-F0h]@21
  int v9; // [sp+ECh] [bp-28h]@1
  int v10; // [sp+F0h] [bp-24h]@5
  int row; // [sp+F4h] [bp-20h]@3
  int col; // [sp+F8h] [bp-1Ch]@1
  float v13; // [sp+FCh] [bp-18h]@12
  int creatureType; // [sp+100h] [bp-14h]@12
  int v15; // [sp+104h] [bp-10h]@1
  int v16; // [sp+108h] [bp-Ch]@12
  int v17; // [sp+10Ch] [bp-8h]@6
  int v18; // [sp+110h] [bp-4h]@1

  v4 = this;
  v9 = 100;
  v18 = -1;
  v15 = -1;
  for ( col = *(_DWORD *)(a2 + 25) - 3; *(_DWORD *)(a2 + 25) + 3 >= col; ++col )
  {
    for ( row = *(_DWORD *)(a2 + 29) - 3; *(_DWORD *)(a2 + 29) + 3 >= row; ++row )
    {
      v10 = usedToCheckForBoatByCastle((AdvManager *)v4, col, row);
      if ( *(_BYTE *)(v10 + 9) == 152 )
      {
        v2 = abs(*(_DWORD *)(a2 + 29) - row);
        v17 = abs(*(_DWORD *)(a2 + 25) - col) + v2;
        if ( v17 < v9 )
        {
          v9 = v17;
          v15 = col;
          v18 = row;
        }
      }
    }
  }
  if ( v9 == 100 )
  {
    display_message_window(
      "You must be within 3 spaces of a monster for the Visions spell to work.",
      1,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
    return 0;
  }
  v10 = usedToCheckForBoatByCastle((AdvManager *)v4, v15, v18);
  creatureType = *(_BYTE *)(v10 + 3);
  v7 = ((unsigned __int8)(*(_WORD *)(v10 + 4) >> 8) >> -5) & 0;
  v16 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v10 + 4) >> 8) >> -5);
  sprintf(globBuf, "{%d %s}\n\n", v16, creaturePluralNames[creatureType]);
  v13 = (double)getArmyStrength((ArmyInfo *)(a2 + 101), (Hero *)a2, 0, 0, 0, 0)
      / (double)(v16 * creature_table[creatureType].fight_value);
  if ( !ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a2 + 101), creatureType)
    || v13 <= 2.0
    || Hero::hasArtifact((Hero *)a2, ARTIFACT_HIDEOUS_MASK)
    || creatureType == 59
    || creatureType == 62
    || creatureType == 63
    || creatureType == 64
    || creatureType == 65 )
    goto LABEL_37;
  if ( !v7 )
  {
    if ( *(_BYTE *)(a2 + 120) )
    {
      if ( *(_BYTE *)(a2 + 120) == 3 )
      {
        v5 = v16;
      }
      else
      {
        if ( *(_BYTE *)(a2 + 120) == 2 )
          v5 = v16 / 2;
        else
          v5 = v16 / 4;
      }
      if ( !v5 )
        v5 = 1;
      v6 = v16 * creature_table[creatureType].cost;
      if ( gameObject->players[*(_BYTE *)(a2 + 3)].resources[6] >= v6 )
      {
        if ( v16 == v5 )
          sprintf(&v8, "All the creatures will join us...\n\nfor a fee of %d gold.", v6);
        else
          sprintf(&v8, "%d of the creatures will join us...\n\nfor a fee of %d gold.", v16, v6);
        strcat(globBuf, &v8);
        goto LABEL_40;
      }
      if ( v13 <= 5.0 )
        goto LABEL_39;
      goto LABEL_38;
    }
LABEL_37:
    if ( v13 <= 5.0 )
    {
LABEL_39:
      sprintf(&v8, "I fear these creatures are in the mood for a fight.");
      strcat(globBuf, &v8);
      goto LABEL_40;
    }
LABEL_38:
    sprintf(&v8, "These weak creatures will surely flee before us.");
    strcat(globBuf, &v8);
    goto LABEL_40;
  }
  sprintf(&v8, "The creatures are willing to join us!");
  strcat(globBuf, &v8);
LABEL_40:
  display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
  return 1;
}
