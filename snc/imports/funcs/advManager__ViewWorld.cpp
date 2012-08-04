{
  int var348; // [sp+14h] [bp-348h]@9
  heroWindow *v6; // [sp+1Ch] [bp-340h]@1
  int evt; // [sp+20h] [bp-33Ch]@11
  int v9; // [sp+24h] [bp-338h]@11
  int v10; // [sp+28h] [bp-334h]@11
  char *v11; // [sp+38h] [bp-324h]@11
  int v12; // [sp+3Ch] [bp-320h]@6
  int v13; // [sp+40h] [bp-31Ch]@6
  int v14; // [sp+44h] [bp-318h]@6
  int v15; // [sp+48h] [bp-314h]@6
  int v16; // [sp+4Ch] [bp-310h]@6
  int v17; // [sp+50h] [bp-30Ch]@6
  int v18; // [sp+54h] [bp-308h]@6
  int thisb; // [sp+58h] [bp-304h]@2
  RGB a1; // [sp+5Ch] [bp-300h]@1

  memcpy(&a1, gpBufferPalette->contents, 0x300u);
  gbInViewWorld = 1;
  iVWWhatToDraw = a2;
  iVWDrawAllObjs = a3;
  iVWDrawAllTerrains = a4;
  gpWindowManager->field_56 = 0;
  giCycleType = 2;
  advManager::VWInit(this, this->viewX + 7, this->viewY + 7);
  advManager::VWCompleteDraw(this);
  gpWindowManager->field_56 = 1;
  sprintf(gText, "viewlgnd.bin");
  v6 = (heroWindow *)operator new(68);
  if ( v6 )
    thisb = (int)heroWindow::heroWindow(v6, 480, 16, gText);
  else
    thisb = 0;
  if ( !thisb )
    MemError();
  v12 = (int)"MINE";
  v13 = (int)"RSRC";
  v14 = (int)"RTFX";
  v15 = (int)"TWNS";
  v16 = (int)"HROS";
  v17 = (int)"_ALL";
  v18 = (int)"WRLD";
  if ( a2 != 53 || a3 || a4 )
    var348 = a2 - 48;
  else
    var348 = 6;
  sprintf(gText, "view%s.icn", *(&v12 + var348));
  evt = 512;
  v9 = 9;
  v10 = 3;
  v11 = gText;
  heroWindow::BroadcastMessage((heroWindow *)thisb, (Event *)&evt);
  heroWindowManager::DoDialog(
    gpWindowManager,
    (heroWindow *)thisb,
    (int (__fastcall *)(tag_message *))ViewWorldDialogHandler,
    0);
  operator delete((void *)thisb);
  advManager::UpdateRadar((int)this, 1, 0);
  advManager::VWCleanup();
  gbInViewWorld = 0;
  gpWindowManager->field_56 = 0;
  advManager::RedrawAdvScreen(this, 1, 0);
  giCycleType = 0;
  gpWindowManager->field_56 = 1;
  SetPalette((PaletteContents *)&a1, 1);
}