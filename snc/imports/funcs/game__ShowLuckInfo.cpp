{
  town *v2; // eax@1
  town *v3; // eax@3
  int v4; // eax@39
  char v6; // [sp+10h] [bp-D0h]@2
  int v7; // [sp+DCh] [bp-4h]@6

  v2 = hero::GetOccupiedTown((hero *)a1);
  if ( game::GetLuck((hero *)a1, 0, v2) <= 0 )
  {
    v3 = hero::GetOccupiedTown((hero *)a1);
    if ( game::GetLuck((hero *)a1, 0, v3) )
      sprintf(&v6, off_4F6428);
    else
      sprintf(&v6, off_4F6424);
  }
  else
  {
    sprintf(&v6, cLuckInfo);
  }
  sprintf(gText, off_4F642C, &v6);
  v7 = strlen((int)gText);
  if ( hero::GetOccupiedTown((hero *)a1)
    && hero::GetOccupiedTown((hero *)a1)->factionID == 2
    && BYTE1(hero::GetOccupiedTown((hero *)a1)->buildingsBuiltFlags) & 0x20 )
    strcat(gText, off_4F6450);
  if ( hero::HasArtifact((hero *)a1, ARTIFACT_LUCKY_RABBITS_FOOT) )
    strcat(gText, off_4F6430);
  if ( hero::HasArtifact((hero *)a1, ARTIFACT_GOLDEN_HORSESHOE) )
    strcat(gText, off_4F6434);
  if ( hero::HasArtifact((hero *)a1, ARTIFACT_GAMBLERS_LUCKY_COIN) )
    strcat(gText, off_4F6438);
  if ( hero::HasArtifact((hero *)a1, ARTIFACT_FOUR_LEAF_CLOVER) )
    strcat(gText, off_4F643C);
  if ( *(_BYTE *)(a1 + 227) & 0x10 )
    strcat(gText, off_4F6440);
  if ( *(_BYTE *)(a1 + 228) & 0x20 )
    strcat(gText, off_4F6454);
  if ( *(_BYTE *)(a1 + 227) & 4 )
    strcat(gText, off_4F6444);
  if ( *(_BYTE *)(a1 + 228) & 0x40 )
    strcat(gText, off_4F6458);
  if ( *(_BYTE *)(a1 + 125) == 1 )
    strcat(gText, off_4F645C);
  if ( *(_BYTE *)(a1 + 125) == 2 )
    strcat(gText, off_4F6460);
  if ( *(_BYTE *)(a1 + 125) == 3 )
    strcat(gText, off_4F6464);
  if ( hero::HasArtifact((hero *)a1, ARTIFACT_MASTHEAD) && *(_BYTE *)(a1 + 227) & 0x80 )
    strcat(gText, off_4F6468);
  if ( *(_BYTE *)(a1 + 229) & 0x10 )
    strcat(gText, off_4F646C);
  if ( hero::HasArtifact((hero *)a1, ARTIFACT_BATTLE_GARB_OF_ANDURAN) )
    strcat(gText, off_4F6470);
  v4 = strlen((int)gText);
  if ( v4 == v7 )
    strcat(gText, off_4F6448);
  return NormalDialog(gText, a2, -1, -1, -1, 0, -1, 0, -1, 0);
}