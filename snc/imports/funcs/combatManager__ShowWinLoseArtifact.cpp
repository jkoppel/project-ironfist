{
  int v3; // eax@16
  void *v4; // [sp+Ch] [bp-48h]@1
  textWidget *v5; // [sp+18h] [bp-3Ch]@11
  iconWidget *v6; // [sp+1Ch] [bp-38h]@6
  iconWidget *v7; // [sp+20h] [bp-34h]@1
  char *content; // [sp+24h] [bp-30h]@11
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
  sprintf(gText, "You have captured an enemy artifact!");
  evt = 512;
  v10 = 3;
  v11 = 101;
  v12 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v4 + 63595), (Event *)&evt);
  v7 = (iconWidget *)operator new(45);
  if ( v7 )
    *(_DWORD *)((char *)v4 + 62515) = iconWidget::iconWidget(v7, 136, 310, 80, 80, "winloseb.icn", 0, 0, 2001, 16, 1);
  else
    *(_DWORD *)((char *)v4 + 62515) = 0;
  if ( !*(_DWORD *)((char *)v4 + 62515) )
    MemError();
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)((char *)v4 + 62515), -1);
  v6 = (iconWidget *)operator new(45);
  if ( v6 )
    *(_DWORD *)((char *)v4 + 62519) = iconWidget::iconWidget(
                                        v6,
                                        144,
                                        318,
                                        64,
                                        64,
                                        "artifact.icn",
                                        a3 + 1,
                                        0,
                                        2002,
                                        16,
                                        1);
  else
    *(_DWORD *)((char *)v4 + 62519) = 0;
  if ( !*(_DWORD *)((char *)v4 + 62519) )
    MemError();
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)((char *)v4 + 62519), -1);
  content = (char *)BaseAlloc(0x3Cu, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E34C + 43);
  sprintf(content, gArtifactNames[a3]);
  v5 = (textWidget *)operator new(43);
  if ( v5 )
    *(_DWORD *)((char *)v4 + 62615) = textWidget::textWidget(
                                        v5,
                                        16,
                                        397,
                                        320,
                                        12,
                                        content,
                                        "smalfont.fnt",
                                        1,
                                        2101,
                                        512,
                                        1);
  else
    *(_DWORD *)((char *)v4 + 62615) = 0;
  if ( !*(_DWORD *)((char *)v4 + 62615) )
    MemError();
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)((char *)v4 + 62615), -1);
  heroWindow::DrawWindow(gpCombatManager->combatEndWindow);
  res = NULL_SAMPLE2;
  v3 = SRandom(1, 5);
  sprintf(gText, "pickup%02d.82M", v3);
  res = LoadPlaySample(gText);
  WaitEndSample(-1, res);
}