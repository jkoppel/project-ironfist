{
  int v2; // eax@14
  void *v3; // [sp+Ch] [bp-3Ch]@1
  TextWidget *v4; // [sp+18h] [bp-30h]@6
  GUIIcon *v5; // [sp+1Ch] [bp-2Ch]@1
  void *content; // [sp+20h] [bp-28h]@6
  int evt; // [sp+24h] [bp-24h]@14
  int v8; // [sp+28h] [bp-20h]@14
  int v9; // [sp+2Ch] [bp-1Ch]@14
  char *v10; // [sp+3Ch] [bp-Ch]@14
  sample_resource res; // [sp+40h] [bp-8h]@14

  v3 = this;
  v5 = (GUIIcon *)operator new(0x2Du);
  if ( v5 )
    *(_DWORD *)((char *)v3 + 62515) = GUIIcon_constructor(v5, 173, 270, 32, 30, "mons32.icn", 47, 0, 900, 16, 1);
  else
    *(_DWORD *)((char *)v3 + 62515) = 0;
  if ( !*(_DWORD *)((char *)v3 + 62515) )
    fatalOutOfMemoryError();
  content = KBAlloc(9u, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E3D8 + 19);
  sprintf((char *)content, "%d", *(_DWORD *)&skeletonsToRaise);
  v4 = (TextWidget *)operator new(0x2Bu);
  if ( v4 )
    *(_DWORD *)((char *)v3 + 62615) = TextWidget_constructor(
                                        v4,
                                        165,
                                        300,
                                        32,
                                        12,
                                        (char *)content,
                                        "smalfont.fnt",
                                        1,
                                        901,
                                        512,
                                        1);
  else
    *(_DWORD *)((char *)v3 + 62615) = 0;
  if ( !*(_DWORD *)((char *)v3 + 62615) )
    fatalOutOfMemoryError();
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v3 + 62515), -1);
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)((char *)v3 + 62615), -1);
  if ( *(_DWORD *)&skeletonsToRaise <= 1 )
    sprintf(
      globBuf,
      "Practicing the dark arts of necromancy, you are able to raise one of the enemy's dead to return under your service as a Skeleton.");
  else
    sprintf(
      globBuf,
      "Practicing the dark arts of necromancy, you are able to raise %d of the enemy's dead to return under your service as Skeletons.",
      *(_DWORD *)&skeletonsToRaise);
  evt = 512;
  v8 = 3;
  v9 = 101;
  v10 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)((char *)v3 + 63595), (Event *)&evt);
  GUIWindow::repaintAndUpdateScreen(combatManager->combatEndWindow);
  res = stru_5230F8;
  v2 = nextRandomInt(1, 5);
  sprintf(globBuf, "pickup%02d.82M", v2);
  res = playSample(globBuf);
  waitForSampleToFinish(-1, res);
}
