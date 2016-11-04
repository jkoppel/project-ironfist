{
  signed int result; // eax@3
  int v2; // ST24_4@11
  size_t v3; // eax@11
  void *v4; // [sp+Ch] [bp-2Ch]@1
  TextWidget *v5; // [sp+10h] [bp-28h]@25
  GUIIcon *v6; // [sp+14h] [bp-24h]@20
  TextWidget *thisa; // [sp+18h] [bp-20h]@11
  GUIIcon *v8; // [sp+1Ch] [bp-1Ch]@4
  void *v9; // [sp+20h] [bp-18h]@25
  __int16 height; // [sp+24h] [bp-14h]@18
  int v11; // [sp+2Ch] [bp-Ch]@9
  signed int width; // [sp+30h] [bp-8h]@18
  void *content; // [sp+34h] [bp-4h]@11

  v4 = this;
  if ( dword_50EAB0 || dword_50EAA0 != 5 )
  {
    sub_44D610(this);
    dword_50EAA0 = 5;
    v8 = (GUIIcon *)operator new(0x2Du);
    if ( v8 )
      *(_DWORD *)((char *)v4 + 58) = GUIIcon_constructor(v8, 480, 392, 159, 71, "stonback.icn", 0, 0, 2000, 16, 1);
    else
      *(_DWORD *)((char *)v4 + 58) = 0;
    if ( !*(_DWORD *)((char *)v4 + 58) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v4 + 154), *(AbstractGUIComponent **)((char *)v4 + 58), -1);
    LOWORD(v11) = 0;
    if ( *(_DWORD *)&a7 < 0 )
      v11 = 32 - 6 * Font::numLinesNeededToDisplay(smallFont, byte_524A00, 143);
    v2 = word_50F4C4 + 38;
    v3 = strlen(byte_524A00);
    content = KBAlloc(v3 + 1, "F:\\h2xsrc\\Source\\ADVMGR.CPP", v2);
    sprintf((char *)content, byte_524A00);
    thisa = (TextWidget *)operator new(0x2Bu);
    if ( thisa )
      *(_DWORD *)((char *)v4 + 106) = TextWidget_constructor(
                                        thisa,
                                        480,
                                        v11 + 398,
                                        143,
                                        36,
                                        (char *)content,
                                        "smalfont.fnt",
                                        1,
                                        2100,
                                        512,
                                        1);
    else
      *(_DWORD *)((char *)v4 + 106) = 0;
    if ( !*(_DWORD *)((char *)v4 + 106) )
      fatalOutOfMemoryError();
    GUIWindow::insertElement(*(GUIWindow **)((char *)v4 + 154), *(AbstractGUIComponent **)((char *)v4 + 106), -1);
    if ( *(_DWORD *)&a7 >= 0 )
    {
      if ( *(_DWORD *)&a7 == 6 )
      {
        width = 76;
        height = 26;
      }
      else
      {
        width = 38;
        height = 32;
      }
      v6 = (GUIIcon *)operator new(0x2Du);
      if ( v6 )
        *(_DWORD *)((char *)v4 + 62) = GUIIcon_constructor(
                                         v6,
                                         (143 - width) / 2 + 480,
                                         463 - height - 14,
                                         width,
                                         height,
                                         "resource.icn",
                                         a7,
                                         0,
                                         2001,
                                         16,
                                         1);
      else
        *(_DWORD *)((char *)v4 + 62) = 0;
      if ( !*(_DWORD *)((char *)v4 + 62) )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)((char *)v4 + 154), *(AbstractGUIComponent **)((char *)v4 + 62), -1);
      v9 = KBAlloc(8u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F4C4 + 80);
      sprintf((char *)v9, "%d", dword_5249E4);
      v5 = (TextWidget *)operator new(0x2Bu);
      if ( v5 )
        *(_DWORD *)((char *)v4 + 110) = TextWidget_constructor(
                                          v5,
                                          511,
                                          453,
                                          80,
                                          12,
                                          (char *)v9,
                                          "smalfont.fnt",
                                          1,
                                          2101,
                                          512,
                                          1);
      else
        *(_DWORD *)((char *)v4 + 110) = 0;
      if ( !*(_DWORD *)((char *)v4 + 110) )
        fatalOutOfMemoryError();
      GUIWindow::insertElement(*(GUIWindow **)((char *)v4 + 154), *(AbstractGUIComponent **)((char *)v4 + 110), -1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
