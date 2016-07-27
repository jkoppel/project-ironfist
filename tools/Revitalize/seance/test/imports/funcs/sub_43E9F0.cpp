{
  int v2; // eax@16
  int v3; // [sp+Ch] [bp-4Ch]@1
  TextWidget *v4; // [sp+18h] [bp-40h]@11
  GUIIcon *v5; // [sp+1Ch] [bp-3Ch]@6
  GUIIcon *v6; // [sp+20h] [bp-38h]@1
  void *content; // [sp+24h] [bp-34h]@11
  int evt; // [sp+2Ch] [bp-2Ch]@16
  int v9; // [sp+30h] [bp-28h]@16
  int v10; // [sp+34h] [bp-24h]@16
  char *v11; // [sp+44h] [bp-14h]@16
  int v12; // [sp+48h] [bp-10h]@1
  sample_resource res; // [sp+4Ch] [bp-Ch]@16
  int v14; // [sp+54h] [bp-4h]@1

  v3 = this;
  v14 = *(_WORD *)(this + 2 * *(_DWORD *)(this + 63603) + 12886);
  v12 = 105;
  v6 = (GUIIcon *)operator new(0x2Du);
  if ( v6 )
    *(_DWORD *)(v3 + 62515) = GUIIcon_constructor(v6, v12 + 16, 275, 0, 0, "townwind.icn", 0, 0, 902, 16, 1);
  else
    *(_DWORD *)(v3 + 62515) = 0;
  if ( !*(_DWORD *)(v3 + 62515) )
    fatalOutOfMemoryError();
  v5 = (GUIIcon *)operator new(0x2Du);
  if ( v5 )
    *(_DWORD *)(v3 + 62519) = GUIIcon_constructor(
                                v5,
                                v12 + 36,
                                280,
                                72,
                                51,
                                "spells.icn",
                                spell_table[v14].spriteIdx,
                                0,
                                903,
                                17,
                                1);
  else
    *(_DWORD *)(v3 + 62519) = 0;
  if ( !*(_DWORD *)(v3 + 62519) )
    fatalOutOfMemoryError();
  content = KBAlloc(0xC8u, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E530 + 34);
  sprintf((char *)content, "%s", spell_names[v14]);
  v4 = (TextWidget *)operator new(0x2Bu);
  if ( v4 )
    *(_DWORD *)(v3 + 62615) = TextWidget_constructor(
                                v4,
                                v12 + 34,
                                332,
                                80,
                                24,
                                (char *)content,
                                "smalfont.fnt",
                                1,
                                904,
                                512,
                                1);
  else
    *(_DWORD *)(v3 + 62615) = 0;
  if ( !*(_DWORD *)(v3 + 62615) )
    fatalOutOfMemoryError();
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)(v3 + 62515), -1);
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)(v3 + 62519), -1);
  GUIWindow::insertElement((GUIWindow *)a2, *(AbstractGUIComponent **)(v3 + 62615), -1);
  sprintf(
    globBuf,
    "Through eagle-eyed observation, %s is able to learn the magic spell '%s'.",
    *(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 63603) + 12935) + 10,
    spell_names[v14]);
  evt = 512;
  v9 = 3;
  v10 = 101;
  v11 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)(v3 + 63595), (Event *)&evt);
  GUIWindow::repaintAndUpdateScreen(combatManager->combatEndWindow);
  res = stru_5230F8;
  v2 = nextRandomInt(1, 5);
  sprintf(globBuf, "pickup%02d.82M", v2);
  res = playSample(globBuf);
  waitForSampleToFinish(-1, res);
}
