void __thiscall sub_498F20(void *this, int a2, int a3, int a4)
{
  void *thisa; // [sp+Ch] [bp-350h]@1
  int v5; // [sp+14h] [bp-348h]@9
  GUIWindow *v6; // [sp+1Ch] [bp-340h]@1
  int evt; // [sp+20h] [bp-33Ch]@11
  int v8; // [sp+24h] [bp-338h]@11
  int v9; // [sp+28h] [bp-334h]@11
  char *v10; // [sp+38h] [bp-324h]@11
  int v11; // [sp+3Ch] [bp-320h]@6
  int v12; // [sp+40h] [bp-31Ch]@6
  int v13; // [sp+44h] [bp-318h]@6
  int v14; // [sp+48h] [bp-314h]@6
  int v15; // [sp+4Ch] [bp-310h]@6
  int v16; // [sp+50h] [bp-30Ch]@6
  int v17; // [sp+54h] [bp-308h]@6
  int thisb; // [sp+58h] [bp-304h]@2
  RGB a1; // [sp+5Ch] [bp-300h]@1

  thisa = this;
  memcpy(&a1, palette->contents, 0x300u);
  dword_519244 = 1;
  dword_52FF3C = a2;
  dword_52FF40 = a3;
  dword_52FF44 = a4;
  HeroWindowManager::instance->field_56 = 0;
  dword_4F19A0 = 2;
  sub_499220(thisa, *(_DWORD *)((char *)thisa + 470) + 7, *(_DWORD *)((char *)thisa + 474) + 7);
  sub_499480(thisa);
  HeroWindowManager::instance->field_56 = 1;
  sprintf(globBuf, "viewlgnd.bin");
  v6 = (GUIWindow *)operator new(0x44u);
  if ( v6 )
    thisb = (int)GUIWindow_constructorFromFile(v6, 480, 16, globBuf);
  else
    thisb = 0;
  if ( !thisb )
    fatalOutOfMemoryError();
  v11 = (int)"MINE";
  v12 = (int)"RSRC";
  v13 = (int)"RTFX";
  v14 = (int)"TWNS";
  v15 = (int)"HROS";
  v16 = (int)"_ALL";
  v17 = (int)"WRLD";
  if ( a2 != 53 || a3 || a4 )
    v5 = a2 - 48;
  else
    v5 = 6;
  sprintf(globBuf, "view%s.icn", *(&v11 + v5));
  evt = 512;
  v8 = 9;
  v9 = 3;
  v10 = globBuf;
  GUIWindow::processMessage((GUIWindow *)thisb, (Event *)&evt);
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)thisb,
    (int (__fastcall *)(InputEvent *))sub_49A7D0,
    0);
  operator delete((void *)thisb);
  sub_44AA80((int)thisa, 1, 0);
  sub_4991C0();
  dword_519244 = 0;
  HeroWindowManager::instance->field_56 = 0;
  sub_4506B0(thisa, 1, 0);
  dword_4F19A0 = 0;
  HeroWindowManager::instance->field_56 = 1;
  someSortOfPaletteSwap((PaletteContents *)&a1, 1);
}
