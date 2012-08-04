{
  int v2; // eax@35
  int v3; // ST1C_4@40
  int v4; // ST14_4@40
  int v5; // ebx@40
  int v6; // ST04_4@40
  int v7; // ebx@40
  ICNHeader *v8; // eax@40
  combatManager *thisa; // [sp+Ch] [bp-1A4h]@1
  textWidget *v10; // [sp+10h] [bp-1A0h]@44
  iconWidget *this; // [sp+14h] [bp-19Ch]@39
  textWidget *v12; // [sp+18h] [bp-198h]@29
  textWidget *v13; // [sp+1Ch] [bp-194h]@23
  textWidget *v14; // [sp+20h] [bp-190h]@13
  icon *res; // [sp+24h] [bp-18Ch]@35
  int lossesToDisplay; // [sp+28h] [bp-188h]@37
  int v17; // [sp+2Ch] [bp-184h]@37
  char *content; // [sp+30h] [bp-180h]@13
  char *contenta; // [sp+30h] [bp-180h]@23
  char *contentb; // [sp+30h] [bp-180h]@29
  char *contentc; // [sp+30h] [bp-180h]@44
  int distinctCreaturesLost[2]; // [sp+50h] [bp-160h]@6
  int j; // [sp+58h] [bp-158h]@6
  int i; // [sp+5Ch] [bp-154h]@1
  int v25; // [sp+60h] [bp-150h]@21
  __int16 v26; // [sp+64h] [bp-14Ch]@1
  int numLostCreature[2][20]; // [sp+68h] [bp-148h]@10
  __int16 v28; // [sp+108h] [bp-A8h]@1
  int idxOfLostCreature[2][20]; // [sp+10Ch] [bp-A4h]@10
  int v30; // [sp+1ACh] [bp-4h]@37

  thisa = ecx0;
  v28 = 320;
  v26 = 458;
  for ( i = 0; i < 25; ++i )
  {
    *(_DWORD *)&ecx0->_14[4 * i] = 0;
    *(_DWORD *)&ecx0->_14[4 * i + 100] = 0;
  }
  for ( i = 0; i < 2; ++i )
  {
    distinctCreaturesLost[i] = 0;
    for ( j = 0; j < 20; ++j )
    {
      if ( ecx0->creatures[i][j].creatureIdx != -1 )
      {
        if ( ecx0->creatures[i][j].initialQuantity > ecx0->creatures[i][j].quantity )
        {
          idxOfLostCreature[i][distinctCreaturesLost[i]] = ecx0->creatures[i][j].creatureIdx;
          numLostCreature[i][distinctCreaturesLost[i]++] = ecx0->creatures[i][j].initialQuantity
                                                         - ecx0->creatures[i][j].quantity;
        }
      }
    }
  }
  content = (char *)BaseAlloc(30u, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E5E0 + 35);
  sprintf(content, "Battlefield Casualties");
  v14 = (textWidget *)operator new(43);
  if ( v14 )
    thisa->battlefieldCasualtiesTextWidget = textWidget::textWidget(
                                               v14,
                                               16,
                                               263,
                                               320,
                                               20,
                                               content,
                                               "smalfont.fnt",
                                               1,
                                               2110,
                                               512,
                                               1);
  else
    thisa->battlefieldCasualtiesTextWidget = 0;
  if ( !thisa->battlefieldCasualtiesTextWidget )
    MemError();
  heroWindow::AddWidget(window, (widget *)thisa->battlefieldCasualtiesTextWidget, -1);
  for ( i = 0; i < 2; ++i )
  {
    if ( i )
      v25 = 346;
    else
      v25 = 279;
    contenta = (char *)BaseAlloc(0x1Eu, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E5E0 + 56);
    sprintf(contenta, &aAttacker[("Defender" - "Attacker") & ((i == 0) - 1)]);
    v13 = (textWidget *)operator new(43);
    if ( v13 )
      thisa->sideCasualtiesTitleTextWidget[i] = (int)textWidget::textWidget(
                                                       v13,
                                                       16,
                                                       v25 + 3,
                                                       320,
                                                       20,
                                                       contenta,
                                                       "smalfont.fnt",
                                                       1,
                                                       2110,
                                                       512,
                                                       1);
    else
      thisa->sideCasualtiesTitleTextWidget[i] = 0;
    if ( !thisa->sideCasualtiesTitleTextWidget[i] )
      MemError();
    heroWindow::AddWidget(window, (widget *)thisa->sideCasualtiesTitleTextWidget[i], -1);
    if ( distinctCreaturesLost[i] <= 0 )
    {
      contentb = (char *)BaseAlloc(0xAu, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E5E0 + 75);
      sprintf(contentb, "None");
      v12 = (textWidget *)operator new(43);
      if ( v12 )
        *(_DWORD *)&thisa->_14[28 * i + 100] = textWidget::textWidget(
                                                 v12,
                                                 16,
                                                 v25 + 21,
                                                 320,
                                                 20,
                                                 contentb,
                                                 "smalfont.fnt",
                                                 1,
                                                 5 * i + 2100,
                                                 512,
                                                 1);
      else
        *(_DWORD *)&thisa->_14[28 * i + 100] = 0;
      if ( !*(_DWORD *)&thisa->_14[28 * i + 100] )
        MemError();
      heroWindow::AddWidget(window, *(widget **)&thisa->_14[28 * i + 100], -1);
    }
    res = resourceManager::GetIcon(gpResourceManager, "mons32.icn");
    v2 = distinctCreaturesLost[i];
    if ( v2 >= 7 )
      v2 = 7;
    lossesToDisplay = v2;
    v30 = 40;
    v17 = (320 - 40 * v2) / 2 + 3;
    for ( j = 0; j < lossesToDisplay; ++j )
    {
      this = (iconWidget *)operator new(45);
      if ( this )
      {
        v3 = j + 5 * i + 2000;
        v4 = idxOfLostCreature[i][j];
        v5 = v25 + 19 - GetIconEntry(res, idxOfLostCreature[i][j])->offsetY;
        v6 = v5 - GetIconEntry(res, idxOfLostCreature[i][j])->height + 32;
        v7 = v17 + v30 * j + 16 - GetIconEntry(res, idxOfLostCreature[i][j])->offsetX;
        v8 = GetIconEntry(res, idxOfLostCreature[i][j]);
        *(_DWORD *)&thisa->_14[4 * (j + 7 * i)] = iconWidget::iconWidget(
                                                    this,
                                                    (32 - v8->width) / 2 + (_WORD)v7 + 1,
                                                    v6,
                                                    32,
                                                    28,
                                                    "mons32.icn",
                                                    v4,
                                                    0,
                                                    v3,
                                                    16,
                                                    1);
      }
      else
      {
        *(_DWORD *)&thisa->_14[4 * (j + 7 * i)] = 0;
      }
      if ( !*(_DWORD *)&thisa->_14[4 * (j + 7 * i)] )
        MemError();
      contentc = (char *)BaseAlloc(9u, "F:\\h2xsrc\\Source\\COMMAND.CPP", word_50E5E0 + 119);
      sprintf(contentc, "%d", numLostCreature[i][j]);
      v10 = (textWidget *)operator new(43);
      if ( v10 )
        *(_DWORD *)&thisa->_14[4 * (j + 7 * i) + 100] = textWidget::textWidget(
                                                          v10,
                                                          (_WORD)v17 + v30 * (_WORD)j + 16,
                                                          v25 + 53,
                                                          32,
                                                          12,
                                                          contentc,
                                                          "smalfont.fnt",
                                                          1,
                                                          (_WORD)j + 5 * i + 2100,
                                                          512,
                                                          1);
      else
        *(_DWORD *)&thisa->_14[4 * (j + 7 * i) + 100] = 0;
      if ( !*(_DWORD *)&thisa->_14[4 * (j + 7 * i) + 100] )
        MemError();
      heroWindow::AddWidget(window, *(widget **)&thisa->_14[4 * (j + 7 * i)], -1);
      heroWindow::AddWidget(window, *(widget **)&thisa->_14[4 * (j + 7 * i) + 100], -1);
    }
    resourceManager::Dispose(gpResourceManager, (resource *)res);
  }
}