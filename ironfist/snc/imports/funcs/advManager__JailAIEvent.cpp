{
  signed int result; // eax@2
  char *v6; // ST24_4@4
  int v7; // [sp+14h] [bp-4h]@1

  v7 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
  if ( gpGame->relatedToHeroForHireStatus[v7] == 65 )
  {
    result = gpCurPlayer->numHeroes;
    if ( result < 8 )
    {
      gpGame->heroes[v7].probablyOwnerIdx = *(_BYTE *)(a3 + 3);
      gpGame->relatedToHeroForHireStatus[v7] = *(_BYTE *)(a3 + 3);
      v6 = (char *)&gpGame->heroes[v7];
      advManager::EraseObj((mapCell *)this, a2, a4, a5);
      gpCurPlayer->heroesOwned[gpCurPlayer->numHeroes++] = v7;
      *(_DWORD *)(v6 + 25) = a4;
      *(_DWORD *)(v6 + 29) = a5;
      *(_DWORD *)(v6 + 227) = 0;
      v6[44] = 2;
      *(_DWORD *)(v6 + 53) = hero::CalcMobility((hero *)v6);
      *(_DWORD *)(v6 + 49) = *(_DWORD *)(v6 + 53);
      *(_WORD *)(v6 + 45) = *(_BYTE *)(a2 + 9);
      *(_WORD *)(v6 + 47) = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
      *(_BYTE *)(a2 + 9) = -86;
      *(_WORD *)(a2 + 4) = 8 * v7 | *(_WORD *)(a2 + 4) & 7;
      result = SendMapChange(3, v7, a4, a5, -999, 0, 0);
    }
  }
  else
  {
    result = advManager::EraseObj((mapCell *)this, a2, a4, a5);
  }
  return result;
}