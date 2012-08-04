{
  int v2; // eax@16
  int v3; // [sp+Ch] [bp-4Ch]@1
  textWidget *v4; // [sp+18h] [bp-40h]@11
  iconWidget *v5; // [sp+1Ch] [bp-3Ch]@6
  iconWidget *v6; // [sp+20h] [bp-38h]@1
  char *content; // [sp+24h] [bp-34h]@11
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
  v6 = (iconWidget *)operator new(45);
  if ( v6 )
    *(_DWORD *)(v3 + 62515) = iconWidget::iconWidget(v6, v12 + 16, 275, 0, 0, "townwind.icn", 0, 0, 902, 16, 1);
  else
    *(_DWORD *)(v3 + 62515) = 0;
  if ( !*(_DWORD *)(v3 + 62515) )
    MemError();
  v5 = (iconWidget *)operator new(45);
  if ( v5 )
    *(_DWORD *)(v3 + 62519) = iconWidget::iconWidget(
                                v5,
                                v12 + 36,
                                280,
                                72,
                                51,
                                "spells.icn",
                                gsSpellInfo[v14].spriteIdx,
                                0,
                                903,
                                17,
                                1);
  else
    *(_DWORD *)(v3 + 62519) = 0;
  if ( !*(_DWORD *)(v3 + 62519) )
    MemError();
  content = (char *)BaseAlloc(0xC8u, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E530 + 34);
  sprintf(content, "%s", gSpellNames[v14]);
  v4 = (textWidget *)operator new(43);
  if ( v4 )
    *(_DWORD *)(v3 + 62615) = textWidget::textWidget(v4, v12 + 34, 332, 80, 24, content, "smalfont.fnt", 1, 904, 512, 1);
  else
    *(_DWORD *)(v3 + 62615) = 0;
  if ( !*(_DWORD *)(v3 + 62615) )
    MemError();
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)(v3 + 62515), -1);
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)(v3 + 62519), -1);
  heroWindow::AddWidget((heroWindow *)a2, *(widget **)(v3 + 62615), -1);
  sprintf(
    gText,
    "Through eagle-eyed observation, %s is able to learn the magic spell '%s'.",
    *(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 63603) + 12935) + 10,
    gSpellNames[v14]);
  evt = 512;
  v9 = 3;
  v10 = 101;
  v11 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)(v3 + 63595), (Event *)&evt);
  heroWindow::DrawWindow(gpCombatManager->combatEndWindow);
  res = NULL_SAMPLE2;
  v2 = SRandom(1, 5);
  sprintf(gText, "pickup%02d.82M", v2);
  res = LoadPlaySample(gText);
  WaitEndSample(-1, res);
}