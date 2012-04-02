signed int __fastcall sub_497970(int a1, int a2, int a3)
{
  int v3; // ST1C_4@1
  signed int result; // eax@12
  GUIWindow *this; // [sp+1Ch] [bp-8h]@3
  int v6; // [sp+20h] [bp-4h]@9

  v3 = a1;
  dword_52FF34 = a2;
  dword_52FF30 = a1;
  sub_456000(advManager, 4);
  viewedHero = &gameObject->heroes[v3];
  dword_4F7458 = 1;
  if ( !a3 )
    sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    heroWindow = GUIWindow_constructorFromFile(this, 0, 0, "herowind.bin");
  else
    heroWindow = 0;
  if ( !heroWindow )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(heroWindow, 6);
  dword_518DC4 = heroWindow;
  if ( viewedHero->field_2 == curPlayer->_1[0] )
  {
    v6 = usedToCheckForBoatByCastle(advManager, viewedHero->x, viewedHero->y);
    if ( *(_BYTE *)(v6 + 9) != 170 )
    {
      *(_WORD *)&viewedHero->_4[12] = *(_BYTE *)(v6 + 9);
      *(_WORD *)&viewedHero->_4[14] = (unsigned __int8)((unsigned __int8)(*(_WORD *)(v6 + 4) >> 8) >> -5);
    }
  }
  sub_497B90();
  sub_497920();
  sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    heroWindow,
    (int (__fastcall *)(InputEvent *))viewHeroWindowCallback,
    0);
  sub_4C7C60(HeroWindowManager::instance, 1, 8, 0);
  operator delete(heroWindow);
  dword_518DC4 = 0;
  if ( HeroWindowManager::instance->buttonPressedCode == 30723 )
  {
    result = 1;
  }
  else
  {
    *(_DWORD *)&viewedHero->_4[16] = Hero::getStartingMovementPoints(viewedHero);
    dword_4F7458 = 0;
    viewedHero = 0;
    result = 0;
  }
  return result;
}
