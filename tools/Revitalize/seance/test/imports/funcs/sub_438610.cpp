{
  int result; // eax@3
  __int16 v16; // ax@41
  __int16 v17; // ax@46
  __int16 v18; // ax@54
  __int16 v19; // ax@59
  int y; // [sp+Ch] [bp-90h]@1
  int x; // [sp+10h] [bp-8Ch]@1
  GUIIcon *v22; // [sp+14h] [bp-88h]@58
  GUIIcon *v23; // [sp+18h] [bp-84h]@53
  GUIIcon *v24; // [sp+1Ch] [bp-80h]@45
  GUIIcon *v25; // [sp+20h] [bp-7Ch]@40
  GUIIcon *v26; // [sp+24h] [bp-78h]@33
  GUIIcon *v27; // [sp+28h] [bp-74h]@28
  GUIIcon *v28; // [sp+2Ch] [bp-70h]@23
  GUIIcon *v29; // [sp+30h] [bp-6Ch]@18
  GUIIcon *this; // [sp+34h] [bp-68h]@11
  GUIWindow *v31; // [sp+38h] [bp-64h]@4
  AbstractGUIComponent *guiObj; // [sp+3Ch] [bp-60h]@12
  AbstractGUIComponent *guiObja; // [sp+3Ch] [bp-60h]@19
  AbstractGUIComponent *guiObjb; // [sp+3Ch] [bp-60h]@24
  AbstractGUIComponent *guiObjc; // [sp+3Ch] [bp-60h]@29
  AbstractGUIComponent *guiObjd; // [sp+3Ch] [bp-60h]@34
  AbstractGUIComponent *guiObje; // [sp+3Ch] [bp-60h]@41
  AbstractGUIComponent *guiObjf; // [sp+3Ch] [bp-60h]@46
  AbstractGUIComponent *guiObjg; // [sp+3Ch] [bp-60h]@54
  AbstractGUIComponent *guiObjh; // [sp+3Ch] [bp-60h]@59
  int k; // [sp+4Ch] [bp-50h]@38
  int l; // [sp+4Ch] [bp-50h]@51
  int i; // [sp+50h] [bp-4Ch]@7
  int j; // [sp+5Ch] [bp-40h]@9
  int v45; // [sp+68h] [bp-34h]@1
  int v46; // [sp+74h] [bp-28h]@7
  int v47; // [sp+78h] [bp-24h]@7
  int v48; // [sp+84h] [bp-18h]@7
  int v49; // [sp+88h] [bp-14h]@7
  int v50; // [sp+94h] [bp-8h]@1

  y = a2;
  x = a1;
  v45 = (a6 - 1) / 48 + 1;
  v50 = (a7 - 1) / 48 + 1;
  *a8 = 48 * ((a6 - 1) / 48 + 1) + 48;
  *a9 = 48 * v50 + 48;
  if ( a3 )
  {
    x = ((a4 - (48 * v45 + 32)) >> 1) - 16 + a1;
    y = ((a5 - (48 * v50 + 32)) >> 1) + a2;
  }
  *(_DWORD *)a10 = x + 32;
  *(_DWORD *)a11 = y + 16;
  *(_DWORD *)a12 = *(_DWORD *)a10 + 48 * v45 - 1;
  result = *(_DWORD *)a11 + 48 * v50 - 1;
  *(_DWORD *)a13 = result;
  if ( !a15 )
  {
    v31 = (GUIWindow *)operator new(0x44u);
    if ( v31 )
      *a14 = (int)GUIWindow_constructor(v31, x, y, *a8, *a9, 16386);
    else
      *a14 = 0;
    v46 = *(_DWORD *)a10 - x;
    v48 = *(_DWORD *)a11 - y;
    v47 = *(_DWORD *)a12 - x;
    v49 = *(_DWORD *)a13 - y;
    for ( i = 0; i < v50; ++i )
    {
      for ( j = 0; j < v45; ++j )
      {
        this = (GUIIcon *)operator new(0x2Du);
        if ( this )
          guiObj = (AbstractGUIComponent *)GUIIcon_constructor(
                                             this,
                                             v46 + 48 * j,
                                             v48 + 48 * i,
                                             48,
                                             48,
                                             "stonebk2.icn",
                                             12,
                                             0,
                                             -1,
                                             16,
                                             1);
        else
          guiObj = 0;
        if ( !guiObj )
          fatalOutOfMemoryError();
        GUIWindow::insertElement((GUIWindow *)*a14, guiObj, -1);
      }
    }
    v29 = (GUIIcon *)operator new(0x2Du);
    if ( v29 )
      guiObja = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v29,
                                          v46 - 40,
                                          v48 - 40,
                                          72,
                                          72,
                                          "stonebk2.icn",
                                          0,
                                          0,
                                          -1,
                                          16,
                                          1);
    else
      guiObja = 0;
    if ( !guiObja )
      fatalOutOfMemoryError();
    GUIWindow::insertElement((GUIWindow *)*a14, guiObja, -1);
    v28 = (GUIIcon *)operator new(0x2Du);
    if ( v28 )
      guiObjb = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v28,
                                          v47 - 23,
                                          v48 - 40,
                                          72,
                                          72,
                                          "stonebk2.icn",
                                          1,
                                          0,
                                          -1,
                                          16,
                                          1);
    else
      guiObjb = 0;
    if ( !guiObjb )
      fatalOutOfMemoryError();
    GUIWindow::insertElement((GUIWindow *)*a14, guiObjb, -1);
    v27 = (GUIIcon *)operator new(0x2Du);
    if ( v27 )
      guiObjc = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v27,
                                          v47 - 23,
                                          v49 - 23,
                                          72,
                                          72,
                                          "stonebk2.icn",
                                          2,
                                          0,
                                          -1,
                                          16,
                                          1);
    else
      guiObjc = 0;
    if ( !guiObjc )
      fatalOutOfMemoryError();
    GUIWindow::insertElement((GUIWindow *)*a14, guiObjc, -1);
    v26 = (GUIIcon *)operator new(0x2Du);
    if ( v26 )
      guiObjd = (AbstractGUIComponent *)GUIIcon_constructor(
                                          v26,
                                          v46 - 40,
                                          v49 - 23,
                                          72,
                                          72,
                                          "stonebk2.icn",
                                          3,
                                          0,
                                          -1,
                                          16,
                                          1);
    else
      guiObjd = 0;
    if ( !guiObjd )
      fatalOutOfMemoryError();
    GUIWindow::insertElement((GUIWindow *)*a14, guiObjd, -1);
    for ( k = 0; k < v45; ++k )
    {
      v25 = (GUIIcon *)operator new(0x2Du);
      if ( v25 )
      {
        v16 = unseededNextRand(4, 5);
        guiObje = (AbstractGUIComponent *)GUIIcon_constructor(
                                            v25,
                                            (_WORD)v46 + 48 * k - 24,
                                            v48 - 40,
                                            72,
                                            72,
                                            "stonebk2.icn",
                                            v16,
                                            0,
                                            -1,
                                            16,
                                            1);
      }
      else
      {
        guiObje = 0;
      }
      if ( !guiObje )
        fatalOutOfMemoryError();
      GUIWindow::insertElement((GUIWindow *)*a14, guiObje, -1);
      v24 = (GUIIcon *)operator new(0x2Du);
      if ( v24 )
      {
        v17 = unseededNextRand(8, 9);
        guiObjf = (AbstractGUIComponent *)GUIIcon_constructor(
                                            v24,
                                            (_WORD)v46 + 48 * k - 24,
                                            v49 - 23,
                                            72,
                                            72,
                                            "stonebk2.icn",
                                            v17,
                                            0,
                                            -1,
                                            16,
                                            1);
      }
      else
      {
        guiObjf = 0;
      }
      if ( !guiObjf )
        fatalOutOfMemoryError();
      GUIWindow::insertElement((GUIWindow *)*a14, guiObjf, -1);
    }
    for ( l = 0; ; ++l )
    {
      result = (a7 - 1) / 48 + 1;
      if ( l >= v50 )
        break;
      v23 = (GUIIcon *)operator new(0x2Du);
      if ( v23 )
      {
        v18 = unseededNextRand(10, 11);
        guiObjg = (AbstractGUIComponent *)GUIIcon_constructor(
                                            v23,
                                            v46 - 40,
                                            (_WORD)v48 + 48 * l - 24,
                                            72,
                                            72,
                                            "stonebk2.icn",
                                            v18,
                                            0,
                                            -1,
                                            16,
                                            1);
      }
      else
      {
        guiObjg = 0;
      }
      if ( !guiObjg )
        fatalOutOfMemoryError();
      GUIWindow::insertElement((GUIWindow *)*a14, guiObjg, -1);
      v22 = (GUIIcon *)operator new(0x2Du);
      if ( v22 )
      {
        v19 = unseededNextRand(6, 7);
        guiObjh = (AbstractGUIComponent *)GUIIcon_constructor(
                                            v22,
                                            v47 - 23,
                                            (_WORD)v48 + 48 * l - 24,
                                            72,
                                            72,
                                            "stonebk2.icn",
                                            v19,
                                            0,
                                            -1,
                                            16,
                                            1);
      }
      else
      {
        guiObjh = 0;
      }
      if ( !guiObjh )
        fatalOutOfMemoryError();
      GUIWindow::insertElement((GUIWindow *)*a14, guiObjh, -1);
    }
  }
  return result;
}
