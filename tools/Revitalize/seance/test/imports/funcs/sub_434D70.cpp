{
  Castle *v2; // eax@1
  Castle *v3; // eax@3
  size_t v4; // eax@69
  int v6; // [sp+10h] [bp-DCh]@15
  signed int v7; // [sp+14h] [bp-D8h]@1
  char v8; // [sp+18h] [bp-D4h]@2
  int i; // [sp+E0h] [bp-Ch]@15
  size_t v10; // [sp+E4h] [bp-8h]@6
  int v11; // [sp+E8h] [bp-4h]@11

  v7 = 0;
  v2 = sub_498B70((Hero *)a1);
  if ( ArmyInfo::computeMorale((ArmyInfo *)(a1 + 101), (Hero *)a1, v2, 0) <= 0 )
  {
    v3 = sub_498B70((Hero *)a1);
    if ( ArmyInfo::computeMorale((ArmyInfo *)(a1 + 101), (Hero *)a1, v3, 0) )
      sprintf(&v8, off_4F68A0);
    else
      sprintf(&v8, off_4F689C);
  }
  else
  {
    sprintf(&v8, off_4F6898);
  }
  sprintf(globBuf, off_4F68A4, &v8);
  v10 = strlen(globBuf);
  if ( ArmyInfo::hasNonUndead((ArmyInfo *)(a1 + 101)) )
  {
    strcat(globBuf, off_4F68EC);
  }
  else
  {
    if ( ArmyInfo::hasUndead((ArmyInfo *)(a1 + 101)) || Hero::hasArtifact((Hero *)a1, ARTIFACT_ARM_OF_THE_MARTYR) )
    {
      strcat(globBuf, off_4F68F0);
      v7 = 1;
    }
    v11 = ArmyInfo::computeMoraleBonusForAlignments((ArmyInfo *)(a1 + 101), -1);
    if ( v7 && v11 > 0 )
      v11 = 0;
    if ( v11 > 0 )
    {
      v6 = 0;
      for ( i = 0; i < 5; ++i )
      {
        if ( *(_BYTE *)(i + a1 + 101) != -1 )
          v6 = creature_table[*(_BYTE *)(i + a1 + 101)].faction;
      }
      sprintf(&v8, off_4F68AC, (&off_4F5AF8)[4 * v6]);
      strcat(globBuf, &v8);
    }
    if ( v11 == -1 )
    {
      sprintf(&v8, off_4F68B0);
      strcat(globBuf, &v8);
    }
    if ( v11 == -2 )
    {
      sprintf(&v8, off_4F68B4);
      strcat(globBuf, &v8);
    }
    if ( v11 == -3 )
    {
      sprintf(&v8, off_4F68E8);
      strcat(globBuf, &v8);
    }
    if ( sub_498B70((Hero *)a1)
      && sub_498B70((Hero *)a1)->factionID == 1
      && BYTE1(sub_498B70((Hero *)a1)->buildingsBuiltFlags) & 0x20 )
      strcat(globBuf, off_4F68FC);
    if ( sub_498B70((Hero *)a1) && sub_498B70((Hero *)a1)->buildingsBuiltFlags & 4 )
      strcat(globBuf, off_4F6900);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_MEDAL_OF_VALOR) )
      strcat(globBuf, off_4F68B8);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_MEDAL_OF_COURAGE) )
      strcat(globBuf, off_4F68BC);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_MEDAL_OF_HONOR) )
      strcat(globBuf, off_4F68C0);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_MEDAL_OF_DISTINCTION) )
      strcat(globBuf, off_4F68C4);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_FIZBIN_OF_MISFOURTUNE) )
      strcat(globBuf, off_4F68C8);
    if ( *(_BYTE *)(a1 + 227) & 2 )
      strcat(globBuf, off_4F68CC);
    if ( *(_BYTE *)(a1 + 227) & 8 )
      strcat(globBuf, off_4F68D0);
    if ( *(_BYTE *)(a1 + 228) & 1 )
      strcat(globBuf, off_4F68D4);
    if ( *(_BYTE *)(a1 + 227) & 0x20 )
      strcat(globBuf, off_4F68D8);
    if ( *(_BYTE *)(a1 + 227) & 0x40 )
      strcat(globBuf, off_4F68DC);
    if ( *(_BYTE *)(a1 + 228) & 2 )
      strcat(globBuf, off_4F68F4);
    if ( *(_BYTE *)(a1 + 228) & 4 )
      strcat(globBuf, off_4F68F8);
    if ( *(_BYTE *)(a1 + 122) == 1 )
      strcat(globBuf, off_4F6904);
    if ( *(_BYTE *)(a1 + 122) == 2 )
      strcat(globBuf, off_4F6908);
    if ( *(_BYTE *)(a1 + 122) == 3 )
      strcat(globBuf, off_4F690C);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_MASTHEAD) && *(_BYTE *)(a1 + 227) & 0x80 )
      strcat(globBuf, off_4F6910);
    if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
      strcat(globBuf, off_4F6914);
    v4 = strlen(globBuf);
    if ( v4 == v10 )
      strcat(globBuf, off_4F68E4);
  }
  return display_message_window(globBuf, a2, -1, -1, -1, 0, -1, 0, -1, 0);
}
