{
  int v1; // [sp+Ch] [bp-24h]@1
  GUIWindow *thisa; // [sp+18h] [bp-18h]@1
  int row; // [sp+1Ch] [bp-14h]@7
  int v4; // [sp+20h] [bp-10h]@7
  int col; // [sp+24h] [bp-Ch]@7
  int v6; // [sp+28h] [bp-8h]@6
  GUIWindow *window; // [sp+2Ch] [bp-4h]@2

  v1 = (int)this;
  thisa = (GUIWindow *)operator new(0x44u);
  if ( thisa )
    window = GUIWindow_constructorFromFile(thisa, 0, 0, "dimdoor.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  HeroWindowManager::displayWindow(HeroWindowManager::instance, window, (int (__fastcall *)(InputEvent *))sub_451A50, 0);
  operator delete(window);
  v6 = (int)&gameObject->heroes[curPlayer->_1[0]];
  if ( HeroWindowManager::instance->buttonPressedCode == 1 )
  {
    col = *(_DWORD *)(v1 + 470) + *(_DWORD *)(v1 + 486);
    row = *(_DWORD *)(v1 + 474) + *(_DWORD *)(v1 + 490);
    v4 = usedToCheckForBoatByCastle(
           (AdvManager *)v1,
           *(_DWORD *)(v1 + 470) + *(_DWORD *)(v1 + 486),
           *(_DWORD *)(v1 + 474) + *(_DWORD *)(v1 + 490));
    if ( (!(*(_BYTE *)(v6 + 227) & 0x80) || !tileToTerrainType[*(_WORD *)v4])
      && (*(_BYTE *)(v6 + 227) & 0x80 || tileToTerrainType[*(_WORD *)v4]) )
    {
      SoundManager::couldBePlayCDTrack(soundManager, 1);
      sub_453A20((void *)v1, v6, __PAIR__(row, col), 0, 0);
      SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[*(_DWORD *)(v1 + 166)]);
    }
    else
    {
      display_message_window("Dimension Door failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      sub_44AA80(v1, 1, 0);
    }
    Hero::spendSpellPointsFor(&gameObject->heroes[curPlayer->_1[0]], 56);
  }
  else
  {
    sub_44AA80(v1, 1, 0);
  }
}
