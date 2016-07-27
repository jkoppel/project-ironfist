{
  float v4; // STF8_4@4
  int v5; // ST24_4@31
  size_t v6; // eax@31
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
  GUIIcon *v17; // [sp+28h] [bp-CCh]@204
  GUIIcon *v18; // [sp+2Ch] [bp-C8h]@199
  TextWidget *v19; // [sp+30h] [bp-C4h]@191
  GUIIcon *v20; // [sp+34h] [bp-C0h]@186
  GUIIcon *v21; // [sp+38h] [bp-BCh]@181
  TextWidget *v22; // [sp+3Ch] [bp-B8h]@173
  GUIIcon *v23; // [sp+40h] [bp-B4h]@168
  GUIIcon *v24; // [sp+44h] [bp-B0h]@158
  TextWidget *v25; // [sp+48h] [bp-ACh]@152
  GUIIcon *v26; // [sp+4Ch] [bp-A8h]@145
  GUIIcon *v27; // [sp+50h] [bp-A4h]@140
  GUIIcon *v28; // [sp+54h] [bp-A0h]@135
  GUIIcon *v29; // [sp+58h] [bp-9Ch]@130
  TextWidget *v30; // [sp+5Ch] [bp-98h]@124
  GUIIcon *v31; // [sp+60h] [bp-94h]@119
  TextWidget *v32; // [sp+64h] [bp-90h]@97
  GUIIcon *v33; // [sp+68h] [bp-8Ch]@92
  GUIIcon *v34; // [sp+6Ch] [bp-88h]@79
  GUIIcon *v35; // [sp+70h] [bp-84h]@67
  GUIIcon *v36; // [sp+74h] [bp-80h]@59
  GUIIcon *v37; // [sp+78h] [bp-7Ch]@54
  GUIIcon *v38; // [sp+7Ch] [bp-78h]@42
  GUIIcon *v39; // [sp+80h] [bp-74h]@36
  TextWidget *v40; // [sp+84h] [bp-70h]@31
  GUIIcon *v41; // [sp+88h] [bp-6Ch]@25
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
  void *content; // [sp+DCh] [bp-18h]@31
  void *contenta; // [sp+DCh] [bp-18h]@97
  void *contentb; // [sp+DCh] [bp-18h]@124
  void *contentc; // [sp+DCh] [bp-18h]@152
  void *contentd; // [sp+DCh] [bp-18h]@173
  void *contente; // [sp+DCh] [bp-18h]@191
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
    if ( dword_525208[dword_511E64] > 4 )
    {
      v4 = 303.0 / (double)(dword_525208[dword_511E64] - 4);
      dword_511E70->offsetY = (signed __int64)((double)dword_511E68[dword_511E64] * v4 + 18.0 + 0.4);
    }
    else
    {
      dword_511E70->offsetY = 169;
    }
  }
  if ( a4 || dword_511E64 != dword_525214 || dword_511E68[dword_525214] != dword_525210 )
  {
    for ( i = 0; i < 4; ++i )
    {
      for ( skill = 0; skill < 70; ++skill )
      {
        if ( *((_DWORD *)dword_511E5C + 70 * i + skill) )
        {
          GUIWindow::removeComponent(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * i + skill));
          v43 = *((_DWORD *)dword_511E5C + 70 * i + skill);
          if ( v43 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v43 + 4))(v43);
          *((_DWORD *)dword_511E5C + 70 * i + skill) = 0;
        }
        if ( *((_DWORD *)dword_511E60 + 70 * i + skill) )
        {
          GUIWindow::removeComponent(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * i + skill));
          v42 = *((_DWORD *)dword_511E60 + 70 * i + skill);
          if ( v42 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v42 + 4))(v42);
          *((_DWORD *)dword_511E60 + 70 * i + skill) = 0;
        }
      }
    }
    for ( j = 0; j < 4; ++j )
    {
      v83 = 0;
      v85 = 200 * j + 200;
      if ( j + dword_511E68[dword_511E64] >= dword_525208[dword_511E64] )
        break;
      v41 = (GUIIcon *)operator new(0x2Du);
      if ( v41 )
        *((_DWORD *)dword_511E60 + 70 * j) = GUIIcon_constructor(
                                               v41,
                                               30,
                                               86 * j + 17,
                                               594,
                                               82,
                                               "overview.icn",
                                               dword_511E64 + 10,
                                               0,
                                               200 * j + 202,
                                               16,
                                               1);
      else
        *((_DWORD *)dword_511E60 + 70 * j) = 0;
      if ( !*((_DWORD *)dword_511E60 + 70 * j) )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j), -1);
      if ( dword_511E64 == 1 )
      {
        v54 = (int)((char *)v13 + 100 * *(&curPlayer->castlesOwned[j] + dword_511E68[dword_511E64]) + 2899);
        v5 = word_511E74 + 79;
        v6 = strlen((const char *)v13 + 100 * *(&curPlayer->castlesOwned[j] + dword_511E68[dword_511E64]) + 2986);
        content = KBAlloc(v6 + 1, "F:\\h2xsrc\\Source\\Overview.cpp", v5);
        strcpy((char *)content, (const char *)(v54 + 87));
        v40 = (TextWidget *)operator new(0x2Bu);
        if ( v40 )
          *((_DWORD *)dword_511E5C + 70 * j) = TextWidget_constructor(
                                                 v40,
                                                 35,
                                                 86 * j + 80,
                                                 132,
                                                 10,
                                                 (char *)content,
                                                 "smalfont.fnt",
                                                 1,
                                                 200 * j + 203,
                                                 512,
                                                 1);
        else
          *((_DWORD *)dword_511E5C + 70 * j) = 0;
        GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * j), -1);
        v84 = 1;
        imgIdx = *(_BYTE *)(v54 + 3);
        if ( !(*(_BYTE *)(v54 + 24) & 0x40) )
          imgIdx += 6;
        v39 = (GUIIcon *)operator new(0x2Du);
        if ( v39 )
          *((_DWORD *)dword_511E60 + 70 * j + 1) = GUIIcon_constructor(
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
          *((_DWORD *)dword_511E60 + 70 * j + 1) = 0;
        if ( !*((_DWORD *)dword_511E60 + 70 * j + 1) )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + 1), -1);
        v68 = 2;
        if ( sub_4D05D8((int)&gameObject->_7[72], *(_BYTE *)v54) )
        {
          v38 = (GUIIcon *)operator new(0x2Du);
          if ( v38 )
            *((_DWORD *)dword_511E60 + 70 * j + 2) = GUIIcon_constructor(
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
            *((_DWORD *)dword_511E60 + 70 * j + 2) = 0;
          if ( !*((_DWORD *)dword_511E60 + 70 * j + 2) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + 2), -1);
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
          v37 = (GUIIcon *)operator new(0x2Du);
          if ( v37 )
            *((_DWORD *)dword_511E60 + 70 * j + v68) = GUIIcon_constructor(
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
            *((_DWORD *)dword_511E60 + 70 * j + v68) = 0;
          if ( !*((_DWORD *)dword_511E60 + 70 * j + v68) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v68), -1);
          v69 = v68 + 1;
          v36 = (GUIIcon *)operator new(0x2Du);
          if ( v36 )
          {
            if ( v56 )
              v16 = *(_BYTE *)(v54 + 3);
            else
              v16 = *(_BYTE *)(v55 + 24);
            *((_DWORD *)dword_511E60 + 70 * j + v69) = GUIIcon_constructor(
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
            *((_DWORD *)dword_511E60 + 70 * j + v69) = 0;
          }
          if ( !*((_DWORD *)dword_511E60 + 70 * j + v69) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v69), -1);
          v70 = v69 + 1;
          v35 = (GUIIcon *)operator new(0x2Du);
          if ( v35 )
          {
            if ( v56 )
              v15 = 0;
            else
              v15 = *(_DWORD *)(v55 + 53);
            v7 = sub_4586A0(v15);
            *((_DWORD *)dword_511E60 + 70 * j + v70) = GUIIcon_constructor(
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
            *((_DWORD *)dword_511E60 + 70 * j + v70) = 0;
          }
          if ( !*((_DWORD *)dword_511E60 + 70 * j + v70) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v70), -1);
          v71 = v70 + 1;
          if ( *(_BYTE *)(v54 + 3) != 1 && *(_BYTE *)(v54 + 3) )
            v52 = 20;
          else
            v52 = 10;
          v34 = (GUIIcon *)operator new(0x2Du);
          if ( v34 )
          {
            if ( v56 )
              v14 = v52;
            else
              v14 = *(_WORD *)v55;
            v8 = sub_458720(v14);
            *((_DWORD *)dword_511E60 + 70 * j + v71) = GUIIcon_constructor(
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
            *((_DWORD *)dword_511E60 + 70 * j + v71) = 0;
          }
          if ( !*((_DWORD *)dword_511E60 + 70 * j + v71) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v71), -1);
          v68 = v71 + 1;
        }
        v57 = 0;
        for ( skilla = 0; skilla < 5; ++skilla )
        {
          if ( *(_BYTE *)(skilla + v54 + 8) != -1 && (signed int)*(_WORD *)(v54 + 2 * skilla + 13) > 0 )
          {
            v33 = (GUIIcon *)operator new(0x2Du);
            if ( v33 )
              *((_DWORD *)dword_511E60 + 70 * j + v68) = GUIIcon_constructor(
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
              *((_DWORD *)dword_511E60 + 70 * j + v68) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v68) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v68++), -1);
            contenta = KBAlloc(6u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 238);
            sprintf((char *)contenta, "%d", *(_WORD *)(v54 + 2 * skilla + 13));
            v32 = (TextWidget *)operator new(0x2Bu);
            if ( v32 )
              *((_DWORD *)dword_511E5C + 70 * j + v84) = TextWidget_constructor(
                                                           v32,
                                                           41 * v57 + 173,
                                                           86 * j + 81,
                                                           40,
                                                           12,
                                                           (char *)contenta,
                                                           "smalfont.fnt",
                                                           1,
                                                           skilla + (_WORD)v85 + 10,
                                                           512,
                                                           1);
            else
              *((_DWORD *)dword_511E5C + 70 * j + v84) = 0;
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * j + v84++), -1);
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
            v31 = (GUIIcon *)operator new(0x2Du);
            if ( v31 )
              *((_DWORD *)dword_511E60 + 70 * j + v68) = GUIIcon_constructor(
                                                           v31,
                                                           41 * v58 + 378,
                                                           86 * j + 35,
                                                           42,
                                                           40,
                                                           "mons32.icn",
                                                           dwelling_creatures[*(_BYTE *)(v54 + 3)][v59],
                                                           0,
                                                           v85 + (_WORD)v59 + 15,
                                                           17,
                                                           1);
            else
              *((_DWORD *)dword_511E60 + 70 * j + v68) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v68) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v68++), -1);
            contentb = KBAlloc(6u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 298);
            sprintf((char *)contentb, "%d", *(_WORD *)(v54 + 2 * v59 + 30));
            v30 = (TextWidget *)operator new(0x2Bu);
            if ( v30 )
              *((_DWORD *)dword_511E5C + 70 * j + v84) = TextWidget_constructor(
                                                           v30,
                                                           41 * v58 + 378,
                                                           86 * j + 81,
                                                           40,
                                                           12,
                                                           (char *)contentb,
                                                           "smalfont.fnt",
                                                           1,
                                                           v85 + (_WORD)v59 + 27,
                                                           512,
                                                           1);
            else
              *((_DWORD *)dword_511E5C + 70 * j + v84) = 0;
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * j + v84++), -1);
            ++v58;
          }
        }
      }
      else
      {
        thisa = (int)((char *)v13 + 250 * *(&curPlayer->heroesOwned[j] + dword_511E68[dword_511E64]) + 10180);
        v29 = (GUIIcon *)operator new(0x2Du);
        if ( v29 )
          *((_DWORD *)dword_511E60 + 70 * j + 1) = GUIIcon_constructor(
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
          *((_DWORD *)dword_511E60 + 70 * j + 1) = 0;
        if ( !*((_DWORD *)dword_511E60 + 70 * j + 1) )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + 1), -1);
        v28 = (GUIIcon *)operator new(0x2Du);
        if ( v28 )
          *((_DWORD *)dword_511E60 + 70 * j + 2) = GUIIcon_constructor(
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
          *((_DWORD *)dword_511E60 + 70 * j + 2) = 0;
        if ( !*((_DWORD *)dword_511E60 + 70 * j + 2) )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + 2), -1);
        v27 = (GUIIcon *)operator new(0x2Du);
        if ( v27 )
        {
          v9 = sub_4586A0(*(_DWORD *)(thisa + 53));
          *((_DWORD *)dword_511E60 + 70 * j + 3) = GUIIcon_constructor(
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
          *((_DWORD *)dword_511E60 + 70 * j + 3) = 0;
        }
        if ( !*((_DWORD *)dword_511E60 + 70 * j + 3) )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + 3), -1);
        v26 = (GUIIcon *)operator new(0x2Du);
        if ( v26 )
        {
          v10 = sub_458720(*(_WORD *)thisa);
          *((_DWORD *)dword_511E60 + 70 * j + 4) = GUIIcon_constructor(
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
          *((_DWORD *)dword_511E60 + 70 * j + 4) = 0;
        }
        if ( !*((_DWORD *)dword_511E60 + 70 * j + 4) )
          fatalOutOfMemoryError();
        GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + 4), -1);
        v72 = 5;
        for ( skillc = 0; (signed int)skillc < 4; ++skillc )
        {
          contentc = KBAlloc(4u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 386);
          v11 = Hero::getPrimarySkill((Hero *)thisa, skillc);
          sprintf((char *)contentc, "%d", v11);
          v25 = (TextWidget *)operator new(0x2Bu);
          if ( v25 )
            *((_DWORD *)dword_511E5C + 70 * j + v83) = TextWidget_constructor(
                                                         v25,
                                                         35 * skillc + 105,
                                                         86 * j + 39,
                                                         14,
                                                         8,
                                                         (char *)contentc,
                                                         "smalfont.fnt",
                                                         1,
                                                         skillc + (_WORD)v85 + 142,
                                                         512,
                                                         2);
          else
            *((_DWORD *)dword_511E5C + 70 * j + v83) = 0;
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * j + v83++), -1);
        }
        for ( skilld = 0; skilld < 4; ++skilld )
        {
          v24 = (GUIIcon *)operator new(0x2Du);
          if ( v24 )
            *((_DWORD *)dword_511E60 + 70 * j + v72) = GUIIcon_constructor(
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
            *((_DWORD *)dword_511E60 + 70 * j + v72) = 0;
          if ( !*((_DWORD *)dword_511E60 + 70 * j + v72) )
            fatalOutOfMemoryError();
          GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v72++), -1);
        }
        v48 = 0;
        for ( skille = 0; skille < 5; ++skille )
        {
          if ( *(_BYTE *)(skille + thisa + 101) != -1 && (signed int)*(_WORD *)(thisa + 2 * skille + 106) > 0 )
          {
            v23 = (GUIIcon *)operator new(0x2Du);
            if ( v23 )
              *((_DWORD *)dword_511E60 + 70 * j + v72) = GUIIcon_constructor(
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
              *((_DWORD *)dword_511E60 + 70 * j + v72) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v72) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v72++), -1);
            contentd = KBAlloc(6u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 445);
            sprintf((char *)contentd, "%d", *(_WORD *)(thisa + 2 * skille + 106));
            v22 = (TextWidget *)operator new(0x2Bu);
            if ( v22 )
              *((_DWORD *)dword_511E5C + 70 * j + v83) = TextWidget_constructor(
                                                           v22,
                                                           40 * v48 + 30,
                                                           86 * j + 87,
                                                           40,
                                                           12,
                                                           (char *)contentd,
                                                           "smalfont.fnt",
                                                           1,
                                                           skille + (_WORD)v85 + 109,
                                                           512,
                                                           1);
            else
              *((_DWORD *)dword_511E5C + 70 * j + v83) = 0;
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * j + v83++), -1);
            ++v48;
          }
        }
        for ( skillf = 0; skillf < 8; ++skillf )
        {
          v44 = sub_498B10((Hero *)thisa, skillf);
          if ( v44 != -1 )
          {
            v46 = skillf / 4;
            v49 = (unsigned __int8)((char)skillf % -4);
            v21 = (GUIIcon *)operator new(0x2Du);
            if ( v21 )
              *((_DWORD *)dword_511E60 + 70 * j + v72) = GUIIcon_constructor(
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
              *((_DWORD *)dword_511E60 + 70 * j + v72) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v72) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v72), -1);
            v73 = v72 + 1;
            v20 = (GUIIcon *)operator new(0x2Du);
            if ( v20 )
              *((_DWORD *)dword_511E60 + 70 * j + v73) = GUIIcon_constructor(
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
              *((_DWORD *)dword_511E60 + 70 * j + v73) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v73) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v73), -1);
            v72 = v73 + 1;
            contente = KBAlloc(2u, "F:\\h2xsrc\\Source\\Overview.cpp", word_511E74 + 507);
            v12 = Hero::getSecondarySkillLevelWithBonii((Hero *)thisa, (SECONDARY_SKILL)v44);
            sprintf((char *)contente, "%d", v12);
            v19 = (TextWidget *)operator new(0x2Bu);
            if ( v19 )
              *((_DWORD *)dword_511E5C + 70 * j + v83) = TextWidget_constructor(
                                                           v19,
                                                           35 * v49 + 255,
                                                           86 * j + 42 * v46 + 45,
                                                           8,
                                                           8,
                                                           (char *)contente,
                                                           "smalfont.fnt",
                                                           1,
                                                           skillf + (_WORD)v85 + 162,
                                                           512,
                                                           2);
            else
              *((_DWORD *)dword_511E5C + 70 * j + v83) = 0;
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E5C + 70 * j + v83++), -1);
          }
        }
        v51 = 0;
        for ( skillg = 0; skillg < 14; ++skillg )
        {
          if ( *(_BYTE *)(skillg + thisa + 213) != -1 )
          {
            v47 = v51 / 7;
            v50 = v51 % 7;
            v18 = (GUIIcon *)operator new(0x2Du);
            if ( v18 )
              *((_DWORD *)dword_511E60 + 70 * j + v72) = GUIIcon_constructor(
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
              *((_DWORD *)dword_511E60 + 70 * j + v72) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v72) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v72), -1);
            v74 = v72 + 1;
            v17 = (GUIIcon *)operator new(0x2Du);
            if ( v17 )
              *((_DWORD *)dword_511E60 + 70 * j + v74) = GUIIcon_constructor(
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
              *((_DWORD *)dword_511E60 + 70 * j + v74) = 0;
            if ( !*((_DWORD *)dword_511E60 + 70 * j + v74) )
              fatalOutOfMemoryError();
            GUIWindow::insertElement(dword_511E58, *((AbstractGUIComponent **)dword_511E60 + 70 * j + v74), -1);
            v72 = v74 + 1;
            ++v51;
          }
        }
      }
    }
    if ( a2 )
    {
      GUIWindow::repaintComponentsInRange(dword_511E58, 0, 110, 999);
      HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 30, 16, 0x262u, 341);
    }
  }
}
