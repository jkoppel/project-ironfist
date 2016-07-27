{
  int v3; // ST40_4@15
  int v4; // ST3C_4@15
  int v5; // eax@15
  MapTile *v6; // ST28_4@15
  int v7; // ST44_4@17
  int v8; // eax@17
  char v9; // al@17
  void *v11; // [sp+Ch] [bp-68h]@1
  GUIWindow *thisa; // [sp+20h] [bp-54h]@1
  int evt; // [sp+38h] [bp-3Ch]@6
  int v14; // [sp+3Ch] [bp-38h]@7
  int v15; // [sp+40h] [bp-34h]@7
  int v16; // [sp+50h] [bp-24h]@7
  __int16 v17; // [sp+54h] [bp-20h]@1
  __int16 v18; // [sp+58h] [bp-1Ch]@1
  __int16 v19; // [sp+5Ch] [bp-18h]@1
  __int16 v20; // [sp+60h] [bp-14h]@1
  __int16 v21; // [sp+64h] [bp-10h]@1
  int i; // [sp+68h] [bp-Ch]@8
  __int16 v23; // [sp+6Ch] [bp-8h]@1
  int v24; // [sp+70h] [bp-4h]@8

  v11 = this;
  v18 = 2;
  v19 = 3;
  v23 = 4;
  v21 = 6;
  v20 = 8;
  v17 = 9;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    *(_DWORD *)((char *)v11 + 358) = GUIWindow_constructorFromFile(thisa, 177, 16, "rcrthero.bin");
  else
    *(_DWORD *)((char *)v11 + 358) = 0;
  if ( !*(_DWORD *)((char *)v11 + 358) )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(*(GUIWindow **)((char *)v11 + 358), 20);
  *(_DWORD *)((char *)v11 + 374) = (char *)gameObject + 250 * curPlayer->heroesForPurchase[a2] + 10180;
  *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 3) = curPlayerIdx;
  evt = 512;
  if ( a3 )
  {
    v14 = 6;
    v16 = 2;
    v15 = 8;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
    v15 = 9;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
    v15 = 30722;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
    v14 = 5;
    v16 = 4096;
    v15 = 8;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
    v15 = 9;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
    v15 = 30722;
    GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
  }
  v24 = 0;
  for ( i = 0; i < 14; ++i )
  {
    if ( *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + i + 213) != -1 )
    {
      if ( *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + i + 213) != 81 )
        ++v24;
    }
  }
  sprintf(
    globBuf,
    "%s is a level %d %s with %d artifacts.",
    *(_DWORD *)((char *)v11 + 374) + 10,
    *(_WORD *)(*(_DWORD *)((char *)v11 + 374) + 61),
    (&off_4F5AF8)[4 * *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 23)],
    v24);
  v14 = 3;
  v15 = 1;
  v16 = (int)globBuf;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
  sprintf(globBuf, "port%04d.icn", *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 24));
  v14 = 9;
  v15 = 2;
  v16 = (int)globBuf;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v11 + 358), (Event *)&evt);
  *(_DWORD *)((char *)v11 + 370) = -1;
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    *(GUIWindow **)((char *)v11 + 358),
    (int (__fastcall *)(InputEvent *))sub_431D10,
    0);
  operator delete(*(void **)((char *)v11 + 358));
  if ( *(_DWORD *)((char *)v11 + 370) == -1 )
  {
    if ( *(_DWORD *)((char *)v11 + 346) )
      sub_409850((TownManager *)v11, *(GUIWindow **)((char *)v11 + 354), 0);
    if ( *(_DWORD *)((char *)v11 + 346) )
      GUIWindow::repaintAndUpdateScreen(*(GUIWindow **)((char *)v11 + 354));
  }
  else
  {
    *(_DWORD *)((char *)v11 + 370) = a2;
    curPlayer->resources[6] -= dword_4F1DA8;
    curPlayer->heroesOwned[curPlayer->numHeroes++] = curPlayer->heroesForPurchase[*(_DWORD *)((char *)v11 + 370)];
    v3 = *(_BYTE *)(*(_DWORD *)((char *)v11 + 54) + 4);
    v4 = *(_BYTE *)(*(_DWORD *)((char *)v11 + 54) + 5);
    *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 25) = v3;
    *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 29) = v4;
    v5 = *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 227);
    *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 227) = v5 & 0x600000;
    *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 44) = 2;
    *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 53) = Hero::getStartingMovementPoints(*(Hero **)((char *)v11 + 374));
    *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 49) = *(_DWORD *)(*(_DWORD *)((char *)v11 + 374) + 53);
    *(_WORD *)(*(_DWORD *)((char *)v11 + 374) + 45) = *(&gameObject->map.tiles[v3].objType
                                                      + 12 * v4 * gameObject->map.width);
    *(_WORD *)(*(_DWORD *)((char *)v11 + 374) + 47) = (unsigned __int8)((unsigned __int8)(*(&gameObject->map.tiles[v3].flags
                                                                                          + 6
                                                                                          * v4
                                                                                          * gameObject->map.width) >> 8) >> -5);
    *(&gameObject->map.tiles[v3].objType + 12 * v4 * gameObject->map.width) = -86;
    v6 = &gameObject->map.tiles[v4 * gameObject->map.width] + v3;
    v6->flags = v6->flags & 7 | 8 * curPlayer->heroesForPurchase[*(_DWORD *)((char *)v11 + 370)];
    sub_4C3190(3, *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 2), v3, v4, -999, 0, 0);
    *(_DWORD *)((char *)v11 + 334) = 1;
    *(_BYTE *)(*(_DWORD *)((char *)v11 + 54) + 23) = *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 2);
    gameObject->relatedToHeroForHireStatus[curPlayer->heroesForPurchase[*(_DWORD *)((char *)v11 + 370)]] = curPlayerIdx;
    sub_42E680();
    if ( *(_BYTE *)(*(_DWORD *)((char *)v11 + 54) + 24) & 1 )
      Castle::grantHeroSpellsFromMageGuild(*(Castle **)((char *)v11 + 54), 0);
    v7 = curPlayer->heroesForPurchase[1 - *(_DWORD *)((char *)v11 + 370)] / 9;
    v8 = unseededNextRand(1, 5);
    v9 = GameInfo::getRandomHeroFromHeroPool(gameObject, curPlayerIdx, (v7 + v8) % 6, 0);
    curPlayer->heroesForPurchase[*(_DWORD *)((char *)v11 + 370)] = v9;
    gameObject->relatedToHeroForHireStatus[curPlayer->heroesForPurchase[*(_DWORD *)((char *)v11 + 370)]] = 64;
  }
  Bankbox::refreshCaptions(*(Bankbox **)((char *)v11 + 238), 1);
  HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 6, 30720, 16392);
  *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 3) = -1;
  if ( *(_DWORD *)((char *)v11 + 370) != -1 )
    *(_BYTE *)(*(_DWORD *)((char *)v11 + 374) + 3) = curPlayerIdx;
  return *(_DWORD *)((char *)v11 + 370) != -1;
}
