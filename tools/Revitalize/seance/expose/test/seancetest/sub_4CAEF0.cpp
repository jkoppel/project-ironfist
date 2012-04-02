void __fastcall sub_4CAEF0(const char *a1, int a2, int a3, const char *a4, unsigned int a5, int a6)
{
  int v6; // ebx@1
  int v7; // edx@1
  int v8; // ebp@1
  int v9; // eax@3
  int v10; // eax@5
  int v11; // ebp@7
  GUIWindow *v12; // eax@7
  const char *v13; // edi@12
  int v14; // esi@16
  int v15; // ecx@16
  int evt; // [sp+10h] [bp-9Ch]@12
  int v17; // [sp+14h] [bp-98h]@12
  int v18; // [sp+18h] [bp-94h]@12
  char *v19; // [sp+28h] [bp-84h]@12
  char *msg; // [sp+2Ch] [bp-80h]@1
  signed int protoCategory; // [sp+30h] [bp-7Ch]@1
  int spriteIdx; // [sp+34h] [bp-78h]@1
  char filename; // [sp+38h] [bp-74h]@7
  char v24; // [sp+48h] [bp-64h]@14

  msg = (char *)a1;
  v6 = a2;
  v7 = mouseManager->spriteIdx;
  v8 = mouseManager->cursorDisabled;
  protoCategory = mouseManager->cursorCategory;
  spriteIdx = v7;
  if ( v8 )
  {
    do
      MouseManager::enableCursor(mouseManager);
    while ( mouseManager->cursorDisabled );
  }
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  dword_532E6C = (char *)v6;
  dword_532E74 = a3;
  strcpy((char *)v6, (const char *)&unk_51F104);
  v9 = 16 * Font::numLinesNeededToDisplay(bigFont, msg, 240);
  if ( a5 )
    v9 += 39;
  v10 = (v9 + 15) / 45;
  if ( v10 > 6 )
    v10 = 6;
  v11 = 45 * v10 - (((a5 < 1) - 1) & 0x1E) + 95;
  sprintf(&filename, "evntwin%d.bin", v10);
  v12 = (GUIWindow *)operator new(0x44u);
  if ( v12 )
    dword_532E68 = GUIWindow_constructorFromFile(v12, 177, 20, &filename);
  else
    dword_532E68 = 0;
  if ( !dword_532E68 )
    fatalOutOfMemoryError();
  v19 = msg;
  evt = 512;
  v17 = 3;
  v18 = 1;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  v13 = a4;
  if ( !a4 )
    v13 = (const char *)&unk_51F118;
  strcpy(&v24, v13);
  v19 = &v24;
  v18 = 10;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  strcpy((char *)v6, &v24);
  v17 = 6;
  v19 = (char *)6;
  evt = 512;
  v18 = 30721;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  v18 = 30727;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  v18 = 30728;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  v18 = 30725;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  v18 = 30726;
  GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  if ( !a5 )
  {
    v18 = 30722;
    GUIWindow::processMessage((GUIWindow *)dword_532E68, (Event *)&evt);
  }
  v14 = 0;
  v15 = (int)operator new(0x4Eu);
  if ( v15 )
    v14 = sub_4D8A90(v15, 35, v11, 251, 20, a3, v6, "bigfont.fnt", 0, "buybuild.icn", 3, 10, 0, 4, 10, 3);
  if ( !v14 )
    fatalOutOfMemoryError();
  dword_532E64 = 213;
  dword_532E60 = v11 + 23;
  GUIWindow::insertElement((GUIWindow *)dword_532E68, (AbstractGUIComponent *)v14, -1);
  if ( a6 )
  {
    dword_532E5C = 0;
    dword_4F199C = 0;
  }
  else
  {
    dword_532E5C = 2;
  }
  HeroWindowManager::displayWindow(
    HeroWindowManager::instance,
    (GUIWindow *)dword_532E68,
    (int (__fastcall *)(InputEvent *))sub_4CB280,
    0);
  operator delete(dword_532E68);
  MouseManager::loadMSE(mouseManager, byte_51F138, spriteIdx, protoCategory);
  dword_4F199C = 1;
}
