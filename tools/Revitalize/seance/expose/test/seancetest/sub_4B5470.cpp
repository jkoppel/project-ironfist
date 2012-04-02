void __stdcall sub_4B5470(signed int a1, int a2)
{
  int v2; // ST30_4@3
  int v3; // ST2C_4@3
  int v4; // ST34_4@3
  MapTile *v5; // ST24_4@3
  char v6; // al@3

  sprintf(globBuf, "Player %d built hero in town %d.\n", curPlayerIdx, *(_BYTE *)a1);
  debugLog(globBuf);
  if ( debugLogLevel >= 3 )
  {
    sub_4CAA50(globBuf);
    sleep(1500);
  }
  curPlayer->resources[6] -= dword_4F1DA8;
  curPlayer->heroesOwned[curPlayer->numHeroes++] = curPlayer->heroesForPurchase[a2];
  v2 = *(_BYTE *)(a1 + 4);
  v3 = *(_BYTE *)(a1 + 5);
  v4 = (int)&gameObject->heroes[curPlayer->heroesForPurchase[a2]];
  sub_4281E0(gameObject, gameObject->heroes[curPlayer->heroesForPurchase[a2]].field_2, 1u);
  *(_WORD *)(v4 + 4) = -99;
  *(_WORD *)(v4 + 7) = -99;
  *(_BYTE *)(v4 + 3) = curPlayerIdx;
  *(_DWORD *)(v4 + 25) = v2;
  *(_DWORD *)(v4 + 29) = v3;
  *(_DWORD *)(v4 + 227) = 0;
  *(_BYTE *)(v4 + 44) = 2;
  *(_DWORD *)(v4 + 53) = Hero::getStartingMovementPoints((Hero *)v4);
  *(_DWORD *)(v4 + 49) = *(_DWORD *)(v4 + 53);
  *(_WORD *)(v4 + 45) = *(&gameObject->map.tiles[v2].objType + 12 * v3 * gameObject->map.width);
  *(_WORD *)(v4 + 47) = (unsigned __int8)((unsigned __int8)(*(&gameObject->map.tiles[v2].flags
                                                            + 6 * v3 * gameObject->map.width) >> 8) >> -5);
  *(&gameObject->map.tiles[v2].objType + 12 * v3 * gameObject->map.width) = -86;
  v5 = &gameObject->map.tiles[v3 * gameObject->map.width] + v2;
  v5->flags = v5->flags & 7 | 8 * curPlayer->heroesForPurchase[a2];
  gameObject->relatedToHeroForHireStatus[*(_BYTE *)(v4 + 2)] = *(_BYTE *)(a1 + 1);
  sub_42E680();
  sub_4C3190(3, *(_BYTE *)(v4 + 2), *(_DWORD *)(v4 + 25), *(_DWORD *)(v4 + 29), -999, 0, 0);
  *(_BYTE *)(a1 + 23) = *(_BYTE *)(v4 + 2);
  Castle::grantHeroSpellsFromMageGuild((Castle *)a1, 0);
  v6 = GameInfo::getRandomHeroFromHeroPool(gameObject, curPlayerIdx, -1, 1);
  curPlayer->heroesForPurchase[a2] = v6;
  gameObject->relatedToHeroForHireStatus[curPlayer->heroesForPurchase[a2]] = 64;
  dword_532C58 = 1;
  sub_4B43E0(v4, a1, 0, (int)&unk_5305C8);
  unknown_libname_21();
}
