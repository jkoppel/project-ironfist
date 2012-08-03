{
  float v4; // STF8_4@4
  int v5; // ST24_4@31
  int v6; // eax@31
  __int16 v7; // ax@71
  __int16 v8; // ax@83
  __int16 v9; // ax@141
  __int16 v10; // ax@146
  char v11; // al@152
  char v12; // al@191
  void *v13; // [sp+18h] [bp-DCh]@1
  signed int v14; // [sp+1Ch] [bp-D8h]@81
  int v15; // [sp+20h] [bp-D4h]@69
  unsigned __int8 v16; // [sp+24h] [bp-D0h]@61
  iconWidget *v17; // [sp+28h] [bp-CCh]@204
  iconWidget *v18; // [sp+2Ch] [bp-C8h]@199
  textWidget *v19; // [sp+30h] [bp-C4h]@191
  iconWidget *v20; // [sp+34h] [bp-C0h]@186
  iconWidget *v21; // [sp+38h] [bp-BCh]@181
  textWidget *v22; // [sp+3Ch] [bp-B8h]@173
  iconWidget *v23; // [sp+40h] [bp-B4h]@168
  iconWidget *v24; // [sp+44h] [bp-B0h]@158
  textWidget *v25; // [sp+48h] [bp-ACh]@152
  iconWidget *v26; // [sp+4Ch] [bp-A8h]@145
  iconWidget *v27; // [sp+50h] [bp-A4h]@140
  iconWidget *v28; // [sp+54h] [bp-A0h]@135
  iconWidget *v29; // [sp+58h] [bp-9Ch]@130
  textWidget *v30; // [sp+5Ch] [bp-98h]@124
  iconWidget *v31; // [sp+60h] [bp-94h]@119
  textWidget *v32; // [sp+64h] [bp-90h]@97
  iconWidget *v33; // [sp+68h] [bp-8Ch]@92
  iconWidget *v34; // [sp+6Ch] [bp-88h]@79
  iconWidget *v35; // [sp+70h] [bp-84h]@67
  iconWidget *v36; // [sp+74h] [bp-80h]@59
  iconWidget *v37; // [sp+78h] [bp-7Ch]@54
  iconWidget *v38; // [sp+7Ch] [bp-78h]@42
  iconWidget *v39; // [sp+80h] [bp-74h]@36
  textWidget *v40; // [sp+84h] [bp-70h]@31
  iconWidget *v41; // [sp+88h] [bp-6Ch]@25
  int v42; // [sp+90h] [bp-64h]@17
  int v43; // [sp+98h] [bp-5Ch]@13
  signed int v44; // [sp+9Ch] [bp-58h]@180
  int thisa; // [sp+A0h] [bp-54h]@130
  int v46; // [sp+A4h] [bp-50h]@181
  int v47; // [sp+A4h] [bp-50h]@199
  __int16 v48; // [sp+A8h] [bp-4Ch]@164
  __int16 v49; // [sp+ACh] [bp-48h]@181
  int v50; // [sp+ACh] [bp-48h]@199
  signed int v51; // [sp+B0h] [bp-44h]@196
  signed int v52; // [sp+B4h] [bp-40h]@77
  __int16 imgIdx; // [sp+B8h] [bp-3Ch]@34
  int v54; // [sp+BCh] [bp-38h]@31
  int v55; // [sp+C0h] [bp-34h]@48
  signed int v56; // [sp+C4h] [bp-30h]@48
  __int16 v57; // [sp+C8h] [bp-2Ch]@88
  __int16 v58; // [sp+C8h] [bp-2Ch]@102
  signed int v59; // [sp+CCh] [bp-28h]@105
  char *a1; // [sp+DCh] [bp-18h]@31
  char *a1a; // [sp+DCh] [bp-18h]@97
  char *a1b; // [sp+DCh] [bp-18h]@124
  char *a1c; // [sp+DCh] [bp-18h]@152
  char *a1d; // [sp+DCh] [bp-18h]@173
  char *a1e; // [sp+DCh] [bp-18h]@191
  signed int i; // [sp+E0h] [bp-14h]@8
  signed int j; // [sp+E0h] [bp-14h]@22
  int v68; // [sp+E4h] [bp-10h]@41
  int v69; // [sp+E4h] [bp-10h]@59
  int v70; // [sp+E4h] [bp-10h]@67
  int v71; // [sp+E4h] [bp-10h]@75
  int v72; // [sp+E4h] [bp-10h]@150
  int v73; // [sp+E4h] [bp-10h]@186
  int v74; // [sp+E4h] [bp-10h]@204
  signed int skill; // [sp+E8h] [bp-Ch]@10
  signed int skilla; // [sp+E8h] [bp-Ch]@88
  signed int skillb; // [sp+E8h] [bp-Ch]@102
  PRIMARY_SKILL skillc; // [sp+E8h] [bp-Ch]@150
  signed int skilld; // [sp+E8h] [bp-Ch]@156
  signed int skille; // [sp+E8h] [bp-Ch]@164
  int skillf; // [sp+E8h] [bp-Ch]@178
  signed int skillg; // [sp+E8h] [bp-Ch]@196
  int v83; // [sp+ECh] [bp-8h]@24
  signed int v84; // [sp+ECh] [bp-8h]@34
  int v85; // [sp+F0h] [bp-4h]@24

  v13 = this;
  if ( a3 )
  {
    if ( giOverviewItems[giOverviewType] > 4 )
    {
      v4 = 303.0 / (double)(giOverviewItems[giOverviewType] - 4);
      OVScrollKnob->offsetY = (signed __int64)((double)giOverviewTop[giOverviewType] * v4 + 18.0 + 0.4);
    }
    else
    {
      OVScrollKnob->offsetY = 169;
    }
  }
  if ( a4 || giOverviewType != iLastDynamicType || giOverviewTop[iLastDynamicType] != iLastDynamicTop )
  {
    for ( i = 0; i < 4; ++i )
    {
      for ( skill = 0; skill < 70; ++skill )
      {
        if ( *((_DWORD *)textWidgetDynamic + 70 * i + skill) )
        {
          heroWindow::RemoveWidget(overWin, *((widget **)textWidgetDynamic + 70 * i + skill));
          v43 = *((_DWORD *)textWidgetDynamic + 70 * i + skill);
          if ( v43 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v43 + 4))(v43);
          *((_DWORD *)textWidgetDynamic + 70 * i + skill) = 0;
        }
        if ( *((_DWORD *)iconWidgetDynamic + 70 * i + skill) )
        {
          heroWindow::RemoveWidget(overWin, *((widget **)iconWidgetDynamic + 70 * i + skill));
          v42 = *((_DWORD *)iconWidgetDynamic + 70 * i + skill);
          if ( v42 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v42 + 4))(v42);
          *((_DWORD *)iconWidgetDynamic + 70 * i + skill) = 0;
        }
      }
    }
    for ( j = 0; j < 4; ++j )
    {
      v83 = 0;
      v85 = 200 * j + 200;
      if ( j + giOverviewTop[giOverviewType] >= giOverviewItems[giOverviewType] )
        break;
      v41 = (iconWidget *)operator new(45);
      if ( v41 )
        *((_DWORD *)iconWidgetDynamic + 70 * j) = iconWidget::iconWidget(
                                                    v41,
                                                    30,
                                                    86 * j + 17,
                                                    594,
                                                    82,
                                                    "overview.icn",
                                                    giOverviewType + 10,
                                                    0,
                                                    200 * j + 202,
                                                    16,
                                                    1);
      else
        *((_DWORD *)iconWidgetDynamic + 70 * j) = 0;
      if ( !*((_DWORD *)iconWidgetDynamic + 70 * j) )
        MemError();
      heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j), -1);
      if ( giOverviewType == 1 )
      {
        v54 = (int)((char *)v13 + 100 * *(&gpCurPlayer->castlesOwned[j] + giOverviewTop[giOverviewType]) + 2899);
        v5 = word_511E74 + 79;
        v6 = strlen((int)((char *)v13 + 100 * *(&gpCurPlayer->castlesOwned[j] + giOverviewTop[giOverviewType]) + 2986));
        a1 = (char *)BaseAlloc(v6 + 1, "F:\\h2xsrc\\Source\\Overview.cpp", v5);
        strcpy(a1, (char *)(v54 + 87));
        v40 = (textWidget *)operator new(43);
        if ( v40 )
          *((_DWORD *)textWidgetDynamic + 70 * j) = textWidget::textWidget(
                                                      v40,
                                                      35,
                                                      86 * j + 80,
                                                      132,
                                                      10,
                                                      a1,
                                                      "smalfont.fnt",
                                                      1,
                                                      200 * j + 203,
                                                      512,
                                                      1);
        else
          *((_DWORD *)textWidgetDynamic + 70 * j) = 0;
        heroWindow::AddWidget(overWin, *((widget **)textWidgetDynamic + 70 * j), -1);
        v84 = 1;
        imgIdx = *(_BYTE *)(v54 + 3);
        if ( !(*(_BYTE *)(v54 + 24) & 0x40) )
          imgIdx += 6;
        v39 = (iconWidget *)operator new(45);
        if ( v39 )
          *((_DWORD *)iconWidgetDynamic + 70 * j + 1) = iconWidget::iconWidget(
                                                          v39,
                                                          47,
                                                          86 * j + 36,
                                                          46,
                                                          22,
                                                          "minitown.icn",
                                                          imgIdx,
                                                          0,
                                                          200 * j + 204,
                                                          16,
                                                          1);
        else
          *((_DWORD *)iconWidgetDynamic + 70 * j + 1) = 0;
        if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + 1) )
          MemError();
        heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + 1), -1);
        v68 = 2;
        if ( BitTest(&gpGame->_7[72], *(_BYTE *)v54) )
        {
          v38 = (iconWidget *)operator new(45);
          if ( v38 )
            *((_DWORD *)iconWidgetDynamic + 70 * j + 2) = iconWidget::iconWidget(
                                                            v38,
                                                            42,
                                                            86 * j + 31,
                                                            0,
                                                            0,
                                                            "locators.icn",
                                                            24,
                                                            0,
                                                            200 * j + 244,
                                                            16,
                                                            1);
          else
            *((_DWORD *)iconWidgetDynamic + 70 * j + 2) = 0;
          if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + 2) )
            MemError();
          heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + 2), -1);
          v68 = 3;
        }
        v56 = 0;
        v55 = 0;
        if ( *(_BYTE *)(v54 + 23) == -1 )
        {
          if ( *(_BYTE *)(v54 + 25) & 0x80 )
            v56 = 1;
        }
        else
        {
          v55 = (int)((char *)v13 + 250 * *(_BYTE *)(v54 + 23) + 10180);
        }
        if ( v55 || v56 )
        {
          v37 = (iconWidget *)operator new(45);
          if ( v37 )
            *((_DWORD *)iconWidgetDynamic + 70 * j + v68) = iconWidget::iconWidget(
                                                              v37,
                                                              112,
                                                              86 * j + 36,
                                                              46,
                                                              22,
                                                              "portxtra.icn",
                                                              0,
                                                              0,
                                                              200 * j + 239,
                                                              16,
                                                              1);
          else
            *((_DWORD *)iconWidgetDynamic + 70 * j + v68) = 0;
          if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v68) )
            MemError();
          heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v68), -1);
          v69 = v68 + 1;
          v36 = (iconWidget *)operator new(45);
          if ( v36 )
          {
            if ( v56 )
              v16 = *(_BYTE *)(v54 + 3);
            else
              v16 = *(_BYTE *)(v55 + 24);
            *((_DWORD *)iconWidgetDynamic + 70 * j + v69) = iconWidget::iconWidget(
                                                              v36,
                                                              107,
                                                              86 * j + 31,
                                                              51,
                                                              27,
                                                              &aMinicapt_icn[("miniport.icn" - "minicapt.icn") & ((v56 != 0) - 1)],
                                                              v16,
                                                              0,
                                                              200 * j + 240,
                                                              16,
                                                              1);
          }
          else
          {
            *((_DWORD *)iconWidgetDynamic + 70 * j + v69) = 0;
          }
          if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v69) )
            MemError();
          heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v69), -1);
          v70 = v69 + 1;
          v35 = (iconWidget *)operator new(45);
          if ( v35 )
          {
            if ( v56 )
              v15 = 0;
            else
              v15 = *(_DWORD *)(v55 + 53);
            v7 = GetMobilityFrame(v15);
            *((_DWORD *)iconWidgetDynamic + 70 * j + v70) = iconWidget::iconWidget(
                                                              v35,
                                                              112,
                                                              86 * j + 36,
                                                              0,
                                                              0,
                                                              "mobility.icn",
                                                              v7,
                                                              0,
                                                              200 * j + 243,
                                                              16,
                                                              1);
          }
          else
          {
            *((_DWORD *)iconWidgetDynamic + 70 * j + v70) = 0;
          }
          if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v70) )
            MemError();
          heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v70), -1);
          v71 = v70 + 1;
          if ( *(_BYTE *)(v54 + 3) != 1 && *(_BYTE *)(v54 + 3) )
            v52 = 20;
          else
            v52 = 10;
          v34 = (iconWidget *)operator new(45);
          if ( v34 )
          {
            if ( v56 )
              v14 = v52;
            else
              v14 = *(_WORD *)v55;
            v8 = GetManaFrame(v14);
            *((_DWORD *)iconWidgetDynamic + 70 * j + v71) = iconWidget::iconWidget(
                                                              v34,
                                                              151,
                                                              86 * j + 36,
                                                              0,
                                                              0,
                                                              "mana.icn",
                                                              v8,
                                                              0,
                                                              200 * j + 241,
                                                              16,
                                                              1);
          }
          else
          {
            *((_DWORD *)iconWidgetDynamic + 70 * j + v71) = 0;
          }
          if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v71) )
            MemError();
          heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v71), -1);
          v68 = v71 + 1;
        }
        v57 = 0;
        for ( skilla = 0; skilla < 5; ++skilla )
        {
          if ( *(_BYTE *)(skilla + v54 + 8) != -1 && (signed int)*(_WORD *)(v54 + 2 * skilla + 13) > 0 )
          {
            v33 = (iconWidget *)operator new(45);
            if ( v33 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v68) = iconWidget::iconWidget(
                                                                v33,
                                                                41 * v57 + 173,
                                                                86 * j + 35,
                                                                42,
                                                                40,
                                                                "mons32.icn",
                                                                *(_BYTE *)(skilla + v54 + 8),
                                                                0,
                                                                skilla + (_WORD)v85 + 5,
                                                                17,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v68) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v68) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v68++), -1);
            a1a = (char *)BaseAlloc(6u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 238);
            sprintf(a1a, "%d", *(_WORD *)(v54 + 2 * skilla + 13));
            v32 = (textWidget *)operator new(43);
            if ( v32 )
              *((_DWORD *)textWidgetDynamic + 70 * j + v84) = textWidget::textWidget(
                                                                v32,
                                                                41 * v57 + 173,
                                                                86 * j + 81,
                                                                40,
                                                                12,
                                                                a1a,
                                                                "smalfont.fnt",
                                                                1,
                                                                skilla + (_WORD)v85 + 10,
                                                                512,
                                                                1);
            else
              *((_DWORD *)textWidgetDynamic + 70 * j + v84) = 0;
            heroWindow::AddWidget(overWin, *((widget **)textWidgetDynamic + 70 * j + v84++), -1);
            ++v57;
          }
        }
        v58 = 0;
        for ( skillb = 0; skillb < 12; ++skillb )
        {
          switch ( skillb )
          {
            case 0:
              v59 = 0;
              break;
            case 1:
              v59 = 1;
              break;
            case 2:
              v59 = 6;
              break;
            case 3:
              v59 = 2;
              break;
            case 4:
              v59 = 7;
              break;
            case 5:
              v59 = 3;
              break;
            case 6:
              v59 = 8;
              break;
            case 7:
              v59 = 4;
              break;
            case 8:
              v59 = 9;
              break;
            case 9:
              v59 = 5;
              break;
            case 10:
              v59 = 10;
              break;
            default:
              v59 = 11;
              break;
          }
          if ( (1 << (v59 + 19)) & *(_DWORD *)(v54 + 24) )
          {
            v31 = (iconWidget *)operator new(45);
            if ( v31 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v68) = iconWidget::iconWidget(
                                                                v31,
                                                                41 * v58 + 378,
                                                                86 * j + 35,
                                                                42,
                                                                40,
                                                                "mons32.icn",
                                                                gDwellingType[*(_BYTE *)(v54 + 3)][v59],
                                                                0,
                                                                v85 + (_WORD)v59 + 15,
                                                                17,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v68) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v68) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v68++), -1);
            a1b = (char *)BaseAlloc(6u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 298);
            sprintf(a1b, "%d", *(_WORD *)(v54 + 2 * v59 + 30));
            v30 = (textWidget *)operator new(43);
            if ( v30 )
              *((_DWORD *)textWidgetDynamic + 70 * j + v84) = textWidget::textWidget(
                                                                v30,
                                                                41 * v58 + 378,
                                                                86 * j + 81,
                                                                40,
                                                                12,
                                                                a1b,
                                                                "smalfont.fnt",
                                                                1,
                                                                v85 + (_WORD)v59 + 27,
                                                                512,
                                                                1);
            else
              *((_DWORD *)textWidgetDynamic + 70 * j + v84) = 0;
            heroWindow::AddWidget(overWin, *((widget **)textWidgetDynamic + 70 * j + v84++), -1);
            ++v58;
          }
        }
      }
      else
      {
        thisa = (int)((char *)v13 + 250 * *(&gpCurPlayer->heroesOwned[j] + giOverviewTop[giOverviewType]) + 10180);
        v29 = (iconWidget *)operator new(45);
        if ( v29 )
          *((_DWORD *)iconWidgetDynamic + 70 * j + 1) = iconWidget::iconWidget(
                                                          v29,
                                                          35,
                                                          86 * j + 21,
                                                          46,
                                                          22,
                                                          "portxtra.icn",
                                                          0,
                                                          0,
                                                          200 * j + 300,
                                                          16,
                                                          1);
        else
          *((_DWORD *)iconWidgetDynamic + 70 * j + 1) = 0;
        if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + 1) )
          MemError();
        heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + 1), -1);
        v28 = (iconWidget *)operator new(45);
        if ( v28 )
          *((_DWORD *)iconWidgetDynamic + 70 * j + 2) = iconWidget::iconWidget(
                                                          v28,
                                                          30,
                                                          86 * j + 16,
                                                          51,
                                                          27,
                                                          "miniport.icn",
                                                          *(_BYTE *)(thisa + 24),
                                                          0,
                                                          200 * j + 301,
                                                          16,
                                                          1);
        else
          *((_DWORD *)iconWidgetDynamic + 70 * j + 2) = 0;
        if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + 2) )
          MemError();
        heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + 2), -1);
        v27 = (iconWidget *)operator new(45);
        if ( v27 )
        {
          v9 = GetMobilityFrame(*(_DWORD *)(thisa + 53));
          *((_DWORD *)iconWidgetDynamic + 70 * j + 3) = iconWidget::iconWidget(
                                                          v27,
                                                          35,
                                                          86 * j + 21,
                                                          0,
                                                          0,
                                                          "mobility.icn",
                                                          v9,
                                                          0,
                                                          200 * j + 303,
                                                          16,
                                                          1);
        }
        else
        {
          *((_DWORD *)iconWidgetDynamic + 70 * j + 3) = 0;
        }
        if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + 3) )
          MemError();
        heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + 3), -1);
        v26 = (iconWidget *)operator new(45);
        if ( v26 )
        {
          v10 = GetManaFrame(*(_WORD *)thisa);
          *((_DWORD *)iconWidgetDynamic + 70 * j + 4) = iconWidget::iconWidget(
                                                          v26,
                                                          74,
                                                          86 * j + 21,
                                                          0,
                                                          0,
                                                          "mana.icn",
                                                          v10,
                                                          0,
                                                          200 * j + 241,
                                                          16,
                                                          1);
        }
        else
        {
          *((_DWORD *)iconWidgetDynamic + 70 * j + 4) = 0;
        }
        if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + 4) )
          MemError();
        heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + 4), -1);
        v72 = 5;
        for ( skillc = 0; (signed int)skillc < 4; ++skillc )
        {
          a1c = (char *)BaseAlloc(4u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 386);
          v11 = hero::Stats((hero *)thisa, skillc);
          sprintf(a1c, "%d", v11);
          v25 = (textWidget *)operator new(43);
          if ( v25 )
            *((_DWORD *)textWidgetDynamic + 70 * j + v83) = textWidget::textWidget(
                                                              v25,
                                                              35 * skillc + 105,
                                                              86 * j + 39,
                                                              14,
                                                              8,
                                                              a1c,
                                                              "smalfont.fnt",
                                                              1,
                                                              skillc + (_WORD)v85 + 142,
                                                              512,
                                                              2);
          else
            *((_DWORD *)textWidgetDynamic + 70 * j + v83) = 0;
          heroWindow::AddWidget(overWin, *((widget **)textWidgetDynamic + 70 * j + v83++), -1);
        }
        for ( skilld = 0; skilld < 4; ++skilld )
        {
          v24 = (iconWidget *)operator new(45);
          if ( v24 )
            *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = iconWidget::iconWidget(
                                                              v24,
                                                              35 * skilld + 87,
                                                              86 * j + 17,
                                                              35,
                                                              30,
                                                              "overview.icn",
                                                              15,
                                                              0,
                                                              skilld + (_WORD)v85 + 170,
                                                              16,
                                                              1);
          else
            *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = 0;
          if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v72) )
            MemError();
          heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v72++), -1);
        }
        v48 = 0;
        for ( skille = 0; skille < 5; ++skille )
        {
          if ( *(_BYTE *)(skille + thisa + 101) != -1 && (signed int)*(_WORD *)(thisa + 2 * skille + 106) > 0 )
          {
            v23 = (iconWidget *)operator new(45);
            if ( v23 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = iconWidget::iconWidget(
                                                                v23,
                                                                40 * v48 + 30,
                                                                86 * j + 47,
                                                                42,
                                                                40,
                                                                "mons32.icn",
                                                                *(_BYTE *)(skille + thisa + 101),
                                                                0,
                                                                skille + (_WORD)v85 + 104,
                                                                17,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v72) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v72++), -1);
            a1d = (char *)BaseAlloc(6u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 445);
            sprintf(a1d, "%d", *(_WORD *)(thisa + 2 * skille + 106));
            v22 = (textWidget *)operator new(43);
            if ( v22 )
              *((_DWORD *)textWidgetDynamic + 70 * j + v83) = textWidget::textWidget(
                                                                v22,
                                                                40 * v48 + 30,
                                                                86 * j + 87,
                                                                40,
                                                                12,
                                                                a1d,
                                                                "smalfont.fnt",
                                                                1,
                                                                skille + (_WORD)v85 + 109,
                                                                512,
                                                                1);
            else
              *((_DWORD *)textWidgetDynamic + 70 * j + v83) = 0;
            heroWindow::AddWidget(overWin, *((widget **)textWidgetDynamic + 70 * j + v83++), -1);
            ++v48;
          }
        }
        for ( skillf = 0; skillf < 8; ++skillf )
        {
          v44 = hero::GetNthSS((hero *)thisa, skillf);
          if ( v44 != -1 )
          {
            v46 = skillf / 4;
            v49 = (unsigned __int8)((char)skillf % -4);
            v21 = (iconWidget *)operator new(45);
            if ( v21 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = iconWidget::iconWidget(
                                                                v21,
                                                                35 * v49 + 233,
                                                                86 * j + 42 * v46 + 20,
                                                                34,
                                                                34,
                                                                "overview.icn",
                                                                12,
                                                                0,
                                                                skillf + (_WORD)v85 + 154,
                                                                16,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v72) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v72), -1);
            v73 = v72 + 1;
            v20 = (iconWidget *)operator new(45);
            if ( v20 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v73) = iconWidget::iconWidget(
                                                                v20,
                                                                35 * v49 + 234,
                                                                86 * j + 42 * v46 + 21,
                                                                32,
                                                                32,
                                                                "miniss.icn",
                                                                v44,
                                                                0,
                                                                skillf + (_WORD)v85 + 146,
                                                                16,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v73) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v73) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v73), -1);
            v72 = v73 + 1;
            a1e = (char *)BaseAlloc(2u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 507);
            v12 = hero::GetSSLevel((hero *)thisa, (SECONDARY_SKILL)v44);
            sprintf(a1e, "%d", v12);
            v19 = (textWidget *)operator new(43);
            if ( v19 )
              *((_DWORD *)textWidgetDynamic + 70 * j + v83) = textWidget::textWidget(
                                                                v19,
                                                                35 * v49 + 255,
                                                                86 * j + 42 * v46 + 45,
                                                                8,
                                                                8,
                                                                a1e,
                                                                "smalfont.fnt",
                                                                1,
                                                                skillf + (_WORD)v85 + 162,
                                                                512,
                                                                2);
            else
              *((_DWORD *)textWidgetDynamic + 70 * j + v83) = 0;
            heroWindow::AddWidget(overWin, *((widget **)textWidgetDynamic + 70 * j + v83++), -1);
          }
        }
        v51 = 0;
        for ( skillg = 0; skillg < 14; ++skillg )
        {
          if ( *(_BYTE *)(skillg + thisa + 213) != -1 )
          {
            v47 = v51 / 7;
            v50 = v51 % 7;
            v18 = (iconWidget *)operator new(45);
            if ( v18 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = iconWidget::iconWidget(
                                                                v18,
                                                                35 * v50 + 378,
                                                                86 * j + 42 * v47 + 20,
                                                                34,
                                                                34,
                                                                "overview.icn",
                                                                12,
                                                                0,
                                                                skillg + (_WORD)v85 + 128,
                                                                16,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v72) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v72) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v72), -1);
            v74 = v72 + 1;
            v17 = (iconWidget *)operator new(45);
            if ( v17 )
              *((_DWORD *)iconWidgetDynamic + 70 * j + v74) = iconWidget::iconWidget(
                                                                v17,
                                                                35 * v50 + 379,
                                                                86 * j + 42 * v47 + 21,
                                                                32,
                                                                32,
                                                                "artfx.icn",
                                                                *(_BYTE *)(skillg + thisa + 213),
                                                                0,
                                                                skillg + (_WORD)v85 + 114,
                                                                16,
                                                                1);
            else
              *((_DWORD *)iconWidgetDynamic + 70 * j + v74) = 0;
            if ( !*((_DWORD *)iconWidgetDynamic + 70 * j + v74) )
              MemError();
            heroWindow::AddWidget(overWin, *((widget **)iconWidgetDynamic + 70 * j + v74), -1);
            v72 = v74 + 1;
            ++v51;
          }
        }
      }
    }
    if ( a2 )
    {
      heroWindow::DrawWindow(overWin, 0, 110, 999);
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 30, 16, 0x262u, 341);
    }
  }
}