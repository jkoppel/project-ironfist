{
  int thisa; // [sp+Ch] [bp-3Ch]@1
  GUIWindow *thisb; // [sp+18h] [bp-30h]@1
  signed int i; // [sp+1Ch] [bp-2Ch]@7
  int v4; // [sp+20h] [bp-28h]@1
  int v5; // [sp+40h] [bp-8h]@1
  int v6; // [sp+44h] [bp-4h]@1

  thisa = (int)this;
  sub_456000(this, 4);
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  v5 = *(_DWORD *)&walkSpeed;
  v6 = *(_DWORD *)&evilInterfaceUsage;
  v4 = *(_DWORD *)(thisa + 678);
  dword_524D20 = 0;
  sub_450880((AdvManager *)thisa);
  thisb = (GUIWindow *)operator new(0x44u);
  if ( thisb )
    dword_524E9C = GUIWindow_constructorFromFile(thisb, 160, 33, "spanel.bin");
  else
    dword_524E9C = 0;
  if ( !dword_524E9C )
    fatalOutOfMemoryError();
  setOptionsScreenTitles(dword_524E9C, 2);
  sub_457CC0((void *)1);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    dword_524E9C,
    (int (__fastcall *)(InputEvent *))sub_458020,
    0);
  operator delete(dword_524E9C);
  if ( *(_DWORD *)&walkSpeed != v5 )
  {
    for ( i = 0; i < 9; ++i )
      ResourceManager::reduceReferenceCountToResource(resourceManager, *(AbstractResource **)(thisa + 4 * i + 850));
    sub_443DA0((AdvManager *)thisa, *(signed int *)&walkSpeed);
  }
  if ( dword_524D20 )
    propagateSettingChanges();
  if ( *(_DWORD *)&evilInterfaceUsage != v6 )
    sub_444550((void *)thisa, 1, -1);
  if ( v4 )
    sub_450820(thisa, 0);
}
