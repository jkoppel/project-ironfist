{
  int v3; // eax@16
  void *v4; // [sp+Ch] [bp-48h]@1
  TextWidget *v5; // [sp+18h] [bp-3Ch]@11
  GUIIcon *v6; // [sp+1Ch] [bp-38h]@6
  GUIIcon *v7; // [sp+20h] [bp-34h]@1
  void *content; // [sp+24h] [bp-30h]@11
  int evt; // [sp+28h] [bp-2Ch]@1
  int v10; // [sp+2Ch] [bp-28h]@1
  int v11; // [sp+30h] [bp-24h]@1
  char *v12; // [sp+40h] [bp-14h]@1
  __int16 v13; // [sp+44h] [bp-10h]@1
  __int16 v14; // [sp+48h] [bp-Ch]@1
  sample_resource res; // [sp+4Ch] [bp-8h]@16

  v4 = this;
  v14 = 320;
  v13 = 458;
  sprintf(globBuf, "You have captured an enemy artifact!");
  evt = 512;
  v10 = 3;
  v11 = 101;
  v12 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v4 + 63595), (Event *)&evt);
  v7 = (GUIIcon *)operator new(0x2Du);
  if ( v7 )
    *(_DWORD *)((char *)v4 + 62515) = GUIIcon_constructor(v7, 136, 310, 80, 80, "winloseb.icn", 0, 0, 2001, 16, 1);
  else
    *(_DWORD *)((char *)v4 + 62515) = 0;
  if ( !*(_DWORD *)((char *)v4 + 62515) )
    fatalOutOfMemoryError();
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v4 + 62515), -1);
  v6 = (GUIIcon *)operator new(0x2Du);
  if ( v6 )
    *(_DWORD *)((char *)v4 + 62519) = GUIIcon_constructor(v6, 144, 318, 64, 64, "artifact.icn", a3 + 1, 0, 2002, 16, 1);
  else
    *(_DWORD *)((char *)v4 + 62519) = 0;
  if ( !*(_DWORD *)((char *)v4 + 62519) )
    fatalOutOfMemoryError();
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v4 + 62519), -1);
  content = KBAlloc(0x3Cu, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E34C + 43);
  sprintf((char *)content, artifactNames[a3]);
  v5 = (TextWidget *)operator new(0x2Bu);
  if ( v5 )
    *(_DWORD *)((char *)v4 + 62615) = TextWidget_constructor(
                                        v5,
                                        16,
                                        397,
                                        320,
                                        12,
                                        (char *)content,
                                        "smalfont.fnt",
                                        1,
                                        2101,
                                        512,
                                        1);
  else
    *(_DWORD *)((char *)v4 + 62615) = 0;
  if ( !*(_DWORD *)((char *)v4 + 62615) )
    fatalOutOfMemoryError();
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v4 + 62615), -1);
  GUIWindow::repaintAndUpdateScreen(combatManager->combatEndWindow);
  res = stru_5230F8;
  v3 = nextRandomInt(1, 5);
  sprintf(globBuf, "pickup%02d.82M", v3);
  res = playSample(globBuf);
  waitForSampleToFinish(-1, res);
}
