{
  heroWindow *result; // eax@2
  char *v6; // ST30_4@5
  void *v7; // [sp+Ch] [bp-14h]@1
  int v8; // [sp+14h] [bp-Ch]@1
  int res[2]; // [sp+18h] [bp-8h]@1

  v7 = this;
  *(_QWORD *)res = NULL_SAMPLE2;
  v8 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
  if ( gpGame->relatedToHeroForHireStatus[v8] == 65 )
  {
    if ( gpCurPlayer->numHeroes < 8 )
    {
      playTrackForLocationVisit(*(_BYTE *)(a2 + 9) & 0x7F, 0, (_QWORD *)res);
      NormalDialog(
        "In a dazzling display of daring, you break into the local jail and free the hero imprisoned there, who, in return, pledges loyalty to your cause.",
        1,
        -1,
        -1,
        -1,
        0,
        -1,
        0,
        -1,
        0);
      gpGame->heroes[v8].probablyOwnerIdx = *(_BYTE *)(a3 + 3);
      gpGame->relatedToHeroForHireStatus[v8] = *(_BYTE *)(a3 + 3);
      v6 = (char *)&gpGame->heroes[v8];
      advManager::EraseObj((mapCell *)v7, a2, a4, a5);
      gpCurPlayer->heroesOwned[gpCurPlayer->numHeroes++] = v8;
      *(_DWORD *)(v6 + 25) = a4;
      *(_DWORD *)(v6 + 29) = a5;
      *(_DWORD *)(v6 + 227) = 0;
      v6[44] = 2;
      *(_DWORD *)(v6 + 53) = hero::CalcMobility((hero *)v6);
      *(_DWORD *)(v6 + 49) = *(_DWORD *)(v6 + 53);
      *(_WORD *)(v6 + 45) = *(_BYTE *)(a2 + 9);
      *(_WORD *)(v6 + 47) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
      *(_BYTE *)(a2 + 9) = -86;
      *(_WORD *)(a2 + 4) = 8 * v8 | *(_WORD *)(a2 + 4) & 7;
      result = (heroWindow *)SendMapChange(3, v8, a4, a5, -999, 0, 0);
    }
    else
    {
      result = NormalDialog(
                 "You already have 8 heroes, and regretfully must leave the prisoner in this jail to languish in agony for untold days.",
                 1,
                 -1,
                 -1,
                 -1,
                 0,
                 -1,
                 0,
                 -1,
                 0);
    }
  }
  else
  {
    NormalDialog(
      "The jailer tells you that the hero who was imprisoned here has been released by the king who imprisoned him.",
      1,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
    result = (heroWindow *)advManager::EraseObj((mapCell *)v7, a2, a4, a5);
  }
  return result;
}