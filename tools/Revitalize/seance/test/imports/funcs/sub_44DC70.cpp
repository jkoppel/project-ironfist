{
  signed int result; // eax@3
  void *v2; // [sp+Ch] [bp-24h]@1
  TextWidget *v3; // [sp+10h] [bp-20h]@24
  TextWidget *thisa; // [sp+14h] [bp-1Ch]@19
  GUIIcon *v5; // [sp+18h] [bp-18h]@14
  GUIIcon *v6; // [sp+1Ch] [bp-14h]@9
  void *content; // [sp+20h] [bp-10h]@19
  void *v8; // [sp+24h] [bp-Ch]@24
  __int16 imgIdx; // [sp+2Ch] [bp-4h]@1

  v2 = this;
  imgIdx = 0;
  if ( dword_50EAB0 || dword_50EAA0 != 1 )
  {
    sub_44D610(this);
    dword_50EAA0 = 1;
    if ( gameObject->day == 1 && (gameObject->month != 1 || gameObject->week != 1 || gameObject->day != 1) )
      imgIdx = gameObject->week;
    v6 = (GUIIcon *)operator new(0x2Du);
    if ( v6 )
      *(_DWORD *)((char *)v2 + 58) = GUIIcon_constructor(v6, 480, 392, 159, 71, "stonback.icn", 0, 0, 2000, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 58) = 0;
    if ( !*(_DWORD *)((char *)v2 + 58) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 58), -1);
    v5 = (GUIIcon *)operator new(0x2Du);
    if ( v5 )
      *(_DWORD *)((char *)v2 + 62) = GUIIcon_constructor(v5, 480, 392, 143, 71, "sunmoon.icn", imgIdx, 0, 2001, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 62) = 0;
    if ( !*(_DWORD *)((char *)v2 + 62) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 62), -1);
    content = KBAlloc(0x1Eu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F424 + 41);
    sprintf((char *)content, "%s: %d  %s: %d", "Month", gameObject->month, "Week", gameObject->week);
    thisa = (TextWidget *)operator new(0x2Bu);
    if ( thisa )
      *(_DWORD *)((char *)v2 + 106) = TextWidget_constructor(
                                        thisa,
                                        479,
                                        424,
                                        145,
                                        12,
                                        (char *)content,
                                        "smalfont.fnt",
                                        1,
                                        2100,
                                        512,
                                        1);
    else
      *(_DWORD *)((char *)v2 + 106) = 0;
    if ( !*(_DWORD *)((char *)v2 + 106) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 106), -1);
    v8 = KBAlloc(0x1Eu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F424 + 67);
    sprintf((char *)v8, "%s: %d", "Day", gameObject->day);
    v3 = (TextWidget *)operator new(0x2Bu);
    if ( v3 )
      *(_DWORD *)((char *)v2 + 106) = TextWidget_constructor(
                                        v3,
                                        479,
                                        438,
                                        145,
                                        25,
                                        (char *)v8,
                                        "bigfont.fnt",
                                        1,
                                        2100,
                                        512,
                                        1);
    else
      *(_DWORD *)((char *)v2 + 106) = 0;
    if ( !*(_DWORD *)((char *)v2 + 106) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v2 + 154), *(AbstractGUIComponent **)((char *)v2 + 106), -1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
