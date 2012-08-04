{
  int v3; // ST24_4@20
  int v4; // eax@20
  void *v5; // [sp+Ch] [bp-50h]@1
  char v6; // [sp+10h] [bp-4Ch]@2
  textWidget *thisa; // [sp+14h] [bp-48h]@20
  int v8; // [sp+1Ch] [bp-40h]@14
  int a4; // [sp+20h] [bp-3Ch]@11
  __int16 v10; // [sp+24h] [bp-38h]@11
  __int16 v11; // [sp+26h] [bp-36h]@11
  __int16 v12; // [sp+28h] [bp-34h]@11
  __int16 v13; // [sp+2Ah] [bp-32h]@11
  char *a1; // [sp+2Ch] [bp-30h]@20
  int evt; // [sp+30h] [bp-2Ch]@8
  int v16; // [sp+34h] [bp-28h]@8
  int v17; // [sp+38h] [bp-24h]@8
  bool v18; // [sp+48h] [bp-14h]@8
  int a2a; // [sp+4Ch] [bp-10h]@11
  __int16 v20; // [sp+50h] [bp-Ch]@11
  __int16 v21; // [sp+52h] [bp-Ah]@11
  __int16 v22; // [sp+54h] [bp-8h]@11
  __int16 v23; // [sp+56h] [bp-6h]@11
  int i; // [sp+58h] [bp-4h]@11

  v5 = this;
  giOverviewType = a2;
  if ( a2 )
    v6 = gpCurPlayer->numCastles;
  else
    v6 = gpCurPlayer->numHeroes;
  iOverviewItems = v6;
  if ( giOverviewTop[giOverviewType] > v6 - 4 )
    giOverviewTop[giOverviewType] = iOverviewItems - 4;
  if ( giOverviewTop[giOverviewType] < 0 )
    giOverviewTop[giOverviewType] = 0;
  evt = 512;
  v16 = 4;
  v17 = 102;
  v18 = giOverviewType + 6;
  heroWindow::BroadcastMessage(overWin, (Event *)&evt);
  v16 = 4;
  v17 = 100;
  v18 = giOverviewType == 0;
  heroWindow::BroadcastMessage(overWin, (Event *)&evt);
  v16 = 4;
  v17 = 101;
  if ( giOverviewType == 1 )
    v18 = 3;
  else
    v18 = 2;
  heroWindow::BroadcastMessage(overWin, (Event *)&evt);
  a2a = 15204387;
  v20 = 377;
  v21 = 35;
  v22 = 177;
  v23 = 379;
  a4 = 9306306;
  v10 = 241;
  v11 = 140;
  v12 = 199;
  v13 = 239;
  for ( i = 0; i < 3; ++i )
  {
    if ( textWidgetTitle[i] )
    {
      heroWindow::RemoveWidget(overWin, (widget *)textWidgetTitle[i]);
      v8 = textWidgetTitle[i];
      if ( v8 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
      textWidgetTitle[i] = 0;
    }
  }
  for ( i = 0; i < 3; ++i )
  {
    v3 = word_5120D0 + 42;
    v4 = strlen((int)(&cOverviewText)[4 * (i + 3 * giOverviewType)]);
    a1 = (char *)BaseAlloc(v4 + 1, "F:\\h2xsrc\\Source\\Overview.cpp", v3);
    strcpy(a1, (&cOverviewText)[4 * (i + 3 * giOverviewType)]);
    thisa = (textWidget *)operator new(43);
    if ( thisa )
      textWidgetTitle[i] = (int)textWidget::textWidget(
                                  thisa,
                                  *(int *)((char *)&a2a + 6 * giOverviewType + 2 * i),
                                  3,
                                  *(int *)((char *)&a4 + 6 * giOverviewType + 2 * i),
                                  12,
                                  a1,
                                  "smalfont.fnt",
                                  1,
                                  i + 110,
                                  512,
                                  1);
    else
      textWidgetTitle[i] = 0;
    heroWindow::AddWidget(overWin, (widget *)textWidgetTitle[i], -1);
  }
  game::SetupDynamicStuff(v5, 0, 1, 0);
  if ( a3 )
    heroWindow::DrawWindow(overWin, a3, 100, 999);
}