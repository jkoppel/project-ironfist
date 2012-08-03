{
  int v2; // ST30_4@3
  int v3; // ST2C_4@3
  int v4; // ST34_4@3
  mapCell *v5; // ST24_4@3
  char v6; // al@3

  sprintf(gText, "Player %d built hero in town %d.\n", giCurPlayer, *(_BYTE *)a1);
  LogStr(gText);
  if ( giDebugLevel >= 3 )
  {
    AiPrint(gText);
    DelayMilli(1500);
  }
  gpCurPlayer->resources[6] -= gHeroGoldCost;
  gpCurPlayer->heroesOwned[gpCurPlayer->numHeroes++] = gpCurPlayer->heroesForPurchase[a2];
  v2 = *(_BYTE *)(a1 + 4);
  v3 = *(_BYTE *)(a1 + 5);
  v4 = (int)&gpGame->heroes[gpCurPlayer->heroesForPurchase[a2]];
  game::SetRandomHeroArmies(gpGame, gpGame->heroes[gpCurPlayer->heroesForPurchase[a2]].couldBeHeroIdx, 1u);
  *(_WORD *)(v4 + 4) = -99;
  *(_WORD *)(v4 + 7) = -99;
  *(_BYTE *)(v4 + 3) = giCurPlayer;
  *(_DWORD *)(v4 + 25) = v2;
  *(_DWORD *)(v4 + 29) = v3;
  *(_DWORD *)(v4 + 227) = 0;
  *(_BYTE *)(v4 + 44) = 2;
  *(_DWORD *)(v4 + 53) = hero::CalcMobility((hero *)v4);
  *(_DWORD *)(v4 + 49) = *(_DWORD *)(v4 + 53);
  *(_WORD *)(v4 + 45) = *(&gpGame->map.tiles[v2].objType + 12 * v3 * gpGame->map.width);
  *(_WORD *)(v4 + 47) = (unsigned __int8)((unsigned __int8)(*(&gpGame->map.tiles[v2].flags + 6 * v3 * gpGame->map.width) >> 8) >> -5);
  *(&gpGame->map.tiles[v2].objType + 12 * v3 * gpGame->map.width) = -86;
  v5 = &gpGame->map.tiles[v3 * gpGame->map.width] + v2;
  v5->flags = v5->flags & 7 | 8 * gpCurPlayer->heroesForPurchase[a2];
  gpGame->relatedToHeroForHireStatus[*(_BYTE *)(v4 + 2)] = *(_BYTE *)(a1 + 1);
  CheckValidAvailableHeroes();
  SendMapChange(3, *(_BYTE *)(v4 + 2), *(_DWORD *)(v4 + 25), *(_DWORD *)(v4 + 29), -999, 0, 0);
  *(_BYTE *)(a1 + 23) = *(_BYTE *)(v4 + 2);
  town::GiveSpells((town *)a1, 0);
  v6 = game::GetNewHeroId(gpGame, giCurPlayer, -1, 1);
  gpCurPlayer->heroesForPurchase[a2] = v6;
  gpGame->relatedToHeroForHireStatus[gpCurPlayer->heroesForPurchase[a2]] = 64;
  bHeroBuiltThisTurn = 1;
  philAI::HeroInteractionAtTown(v4, a1, 0, (int)&unk_5305C8);
  ShowStatus();
}