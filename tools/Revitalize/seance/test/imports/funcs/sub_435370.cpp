{
  Castle *v2; // eax@1
  Castle *v3; // eax@3
  size_t v4; // eax@39
  char v6; // [sp+10h] [bp-D0h]@2
  size_t v7; // [sp+DCh] [bp-4h]@6

  v2 = sub_498B70((Hero *)a1);
  if ( computeLuck((Hero *)a1, 0, v2) <= 0 )
  {
    v3 = sub_498B70((Hero *)a1);
    if ( computeLuck((Hero *)a1, 0, v3) )
      sprintf(&v6, off_4F6428);
    else
      sprintf(&v6, off_4F6424);
  }
  else
  {
    sprintf(&v6, off_4F6420);
  }
  sprintf(globBuf, off_4F642C, &v6);
  v7 = strlen(globBuf);
  if ( sub_498B70((Hero *)a1)
    && sub_498B70((Hero *)a1)->factionID == 2
    && BYTE1(sub_498B70((Hero *)a1)->buildingsBuiltFlags) & 0x20 )
    strcat(globBuf, off_4F6450);
  if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_LUCKY_RABBITS_FOOT) )
    strcat(globBuf, off_4F6430);
  if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_GOLDEN_HORSESHOE) )
    strcat(globBuf, off_4F6434);
  if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_GAMBLERS_LUCKY_COIN) )
    strcat(globBuf, off_4F6438);
  if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_FOUR_LEAF_CLOVER) )
    strcat(globBuf, off_4F643C);
  if ( *(_BYTE *)(a1 + 227) & 0x10 )
    strcat(globBuf, off_4F6440);
  if ( *(_BYTE *)(a1 + 228) & 0x20 )
    strcat(globBuf, off_4F6454);
  if ( *(_BYTE *)(a1 + 227) & 4 )
    strcat(globBuf, off_4F6444);
  if ( *(_BYTE *)(a1 + 228) & 0x40 )
    strcat(globBuf, off_4F6458);
  if ( *(_BYTE *)(a1 + 125) == 1 )
    strcat(globBuf, off_4F645C);
  if ( *(_BYTE *)(a1 + 125) == 2 )
    strcat(globBuf, off_4F6460);
  if ( *(_BYTE *)(a1 + 125) == 3 )
    strcat(globBuf, off_4F6464);
  if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_MASTHEAD) && *(_BYTE *)(a1 + 227) & 0x80 )
    strcat(globBuf, off_4F6468);
  if ( *(_BYTE *)(a1 + 229) & 0x10 )
    strcat(globBuf, off_4F646C);
  if ( Hero::hasArtifact((Hero *)a1, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
    strcat(globBuf, off_4F6470);
  v4 = strlen(globBuf);
  if ( v4 == v7 )
    strcat(globBuf, off_4F6448);
  return display_message_window(globBuf, a2, -1, -1, -1, 0, -1, 0, -1, 0);
}
