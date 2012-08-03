{
  int v2; // eax@14
  void *v3; // [sp+Ch] [bp-3Ch]@1
  textWidget *v4; // [sp+18h] [bp-30h]@6
  iconWidget *v5; // [sp+1Ch] [bp-2Ch]@1
  char *content; // [sp+20h] [bp-28h]@6
  int evt; // [sp+24h] [bp-24h]@14
  int v8; // [sp+28h] [bp-20h]@14
  int v9; // [sp+2Ch] [bp-1Ch]@14
  char *v10; // [sp+3Ch] [bp-Ch]@14
  sample_resource res; // [sp+40h] [bp-8h]@14

  v3 = this;
  v5 = (iconWidget *)operator new(45);
  if ( v5 )
    *(_DWORD *)((char *)v3 + 62515) = iconWidget::iconWidget(v5, 173, 270, 32, 30, "mons32.icn", 47, 0, 900, 16, 1);
  else
    *(_DWORD *)((char *)v3 + 62515) = 0;
  if ( !*(_DWORD *)((char *)v3 + 62515) )
    MemError();
  content = (char *)BaseAlloc(9u, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E3D8 + 19);
  sprintf(content, "%d", *(_DWORD *)&giSkeletonsCreated);
  v4 = (textWidget *)operator new(43);
  if ( v4 )
    *(_DWORD *)((char *)v3 + 62615) = textWidget::textWidget(
                                        v4,
                                        165,
                                        300,
                                        32,
                                        12,
                                        content,
                                        "smalfont.fnt",
                                        1,
                                        901,
                                        512,
                                        1);
  else
    *(_DWORD *)((char *)v3 + 62615) = 0;
  if ( !*(_DWORD *)((char *)v3 + 62615) )
    MemError();
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)((char *)v3 + 62515), -1);
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)((char *)v3 + 62615), -1);
  if ( *(_DWORD *)&giSkeletonsCreated <= 1 )
    sprintf(
      gText,
      "Practicing the dark arts of necromancy, you are able to raise one of the enemy's dead to return under your service as a Skeleton.");
  else
    sprintf(
      gText,
      "Practicing the dark arts of necromancy, you are able to raise %d of the enemy's dead to return under your service as Skeletons.",
      *(_DWORD *)&giSkeletonsCreated);
  evt = 512;
  v8 = 3;
  v9 = 101;
  v10 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 63595), (Event *)&evt);
  heroWindow::DrawWindow(gpCombatManager->combatEndWindow);
  res = NULL_SAMPLE2;
  v2 = SRandom(1, 5);
  sprintf(gText, "pickup%02d.82M", v2);
  res = LoadPlaySample(gText);
  WaitEndSample(-1, res);
}