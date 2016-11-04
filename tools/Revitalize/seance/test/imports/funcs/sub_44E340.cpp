{
  signed int result; // eax@3
  void *v2; // [sp+Ch] [bp-58h]@1
  TextWidget *thisa; // [sp+10h] [bp-54h]@27
  GUIIcon *v4; // [sp+14h] [bp-50h]@9
  GUIIcon *v5; // [sp+18h] [bp-4Ch]@4
  int v6; // [sp+1Ch] [bp-48h]@4
  char content[36]; // [sp+20h] [bp-44h]@22
  char v8; // [sp+44h] [bp-20h]@4
  char v9; // [sp+45h] [bp-1Fh]@4
  char v10; // [sp+46h] [bp-1Eh]@4
  char v11; // [sp+47h] [bp-1Dh]@4
  char v12; // [sp+48h] [bp-1Ch]@4
  char v13; // [sp+49h] [bp-1Bh]@4
  char v14; // [sp+4Ah] [bp-1Ah]@4
  char v15; // [sp+4Bh] [bp-19h]@4
  char v16; // [sp+4Ch] [bp-18h]@4
  char v17; // [sp+50h] [bp-14h]@4
  char v18; // [sp+51h] [bp-13h]@4
  char v19; // [sp+52h] [bp-12h]@4
  char v20; // [sp+53h] [bp-11h]@4
  char v21; // [sp+54h] [bp-10h]@4
  char v22; // [sp+55h] [bp-Fh]@4
  char v23; // [sp+56h] [bp-Eh]@4
  char v24; // [sp+57h] [bp-Dh]@4
  char v25; // [sp+58h] [bp-Ch]@4
  int i; // [sp+5Ch] [bp-8h]@14
  int v27; // [sp+60h] [bp-4h]@4

  v2 = this;
  if ( dword_50EAB0 || dword_50EAA0 != 2 )
  {
    sub_44D610(this);
    dword_50EAA0 = 2;
    v17 = 59;
    v18 = 59;
    v19 = 59;
    v20 = 59;
    v21 = 59;
    v22 = 59;
    v23 = 28;
    v24 = 28;
    v25 = 28;
    v8 = 15;
    v9 = 38;
    v10 = 61;
    v11 = 85;
    v12 = 109;
    v13 = -124;
    v14 = 123;
    v15 = 27;
    v16 = 80;
    v6 = 0;
    v27 = 0;
    v5 = (GUIIcon *)operator new(0x2Du);
    if ( v5 )
      *(_DWORD *)((char *)v2 + 58) = GUIIcon_constructor(v5, 480, 392, 159, 71, "stonback.icn", 0, 0, 2000, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 58) = 0;
    if ( !*(_DWORD *)((char *)v2 + 58) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 58), -1);
    v4 = (GUIIcon *)operator new(0x2Du);
    if ( v4 )
      *(_DWORD *)((char *)v2 + 62) = GUIIcon_constructor(v4, 481, 393, 143, 71, "ressmall.icn", 0, 0, 2001, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 62) = 0;
    if ( !*(_DWORD *)((char *)v2 + 62) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 62), -1);
    for ( i = 0; curPlayer->numCastles > i; ++i )
    {
      if ( gameObject->castles[curPlayer->castlesOwned[i]].buildingsBuiltFlags & 0x40 )
        ++v27;
      else
        ++v6;
    }
    for ( i = 0; i < 9; ++i )
    {
      *(_DWORD *)&content[4 * i] = KBAlloc(8u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F544 + 50);
      if ( i >= 7 )
      {
        if ( i == 7 )
          sprintf(*(char **)&content[28], "%d", v27);
        else
          sprintf(*(char **)&content[4 * i], "%d", v6);
      }
      else
      {
        sprintf(*(char **)&content[4 * i], "%d", curPlayer->resources[i]);
      }
      thisa = (TextWidget *)operator new(0x2Bu);
      if ( thisa )
        *(_DWORD *)((char *)v2 + 4 * i + 106) = TextWidget_constructor(
                                                  thisa,
                                                  (unsigned __int8)*(&v8 + i) + 464,
                                                  *(&v17 + i) + 395,
                                                  32,
                                                  12,
                                                  *(char **)&content[4 * i],
                                                  "smalfont.fnt",
                                                  1,
                                                  i + 2100,
                                                  512,
                                                  1);
      else
        *(_DWORD *)((char *)v2 + 4 * i + 106) = 0;
      if ( !*(_DWORD *)((char *)v2 + 4 * i + 106) )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(
        *(GUIWindow **)((char *)v2 + 154),
        *(AbstractGUIComponent **)((char *)v2 + 4 * i + 106),
        -1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
