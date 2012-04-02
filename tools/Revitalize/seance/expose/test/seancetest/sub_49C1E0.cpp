void __thiscall sub_49C1E0(void *this)
{
  int y; // [sp+10h] [bp-14h]@3
  MACRO_DDERR errorCode; // [sp+14h] [bp-10h]@5
  MACRO_DDERR errorCodea; // [sp+14h] [bp-10h]@8
  MACRO_DDERR errorCodeb; // [sp+14h] [bp-10h]@11
  MACRO_DDERR errorCodec; // [sp+14h] [bp-10h]@13
  MACRO_DDERR errorCoded; // [sp+14h] [bp-10h]@17
  int x; // [sp+18h] [bp-Ch]@3
  unsigned int heightNeededToDisplay; // [sp+1Ch] [bp-8h]@3
  unsigned int width; // [sp+20h] [bp-4h]@3

  if ( !dword_519708 && (void *)*(&mainWindows + 7 * gameOrEditorIdx + 5) != this )
  {
    x = *(&mainWindows + 7 * gameOrEditorIdx + 1);
    y = *(&mainWindows + 7 * gameOrEditorIdx + 2);
    width = *(&mainWindows + 7 * gameOrEditorIdx + 3);
    heightNeededToDisplay = *(&mainWindows + 7 * gameOrEditorIdx + 4);
    dword_519708 = 1;
    *(&mainWindows + 7 * gameOrEditorIdx + 5) = (BOOL)this;
    if ( *(&mainWindows + 7 * gameOrEditorIdx + 5) )
      sub_485B30(0);
    errorCode = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*directDrawObject)[20].lpVtbl)(
                  directDrawObject,
                  windowHandle,
                  19);
    if ( errorCode )
      fatalDirectDrawError(errorCode, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 21);
    if ( *(&mainWindows + 7 * gameOrEditorIdx + 5) )
    {
      errorCodea = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))(*directDrawObject)[21].lpVtbl)(
                     directDrawObject,
                     640,
                     480,
                     8);
      if ( errorCodea )
        fatalDirectDrawError(errorCodea, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 27);
    }
    else
    {
      errorCodeb = ((int (__cdecl *)(_DWORD))(*directDrawObject)[19].lpVtbl)(directDrawObject);
      if ( errorCodeb )
        fatalDirectDrawError(errorCodeb, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 34);
      errorCodec = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))(*directDrawObject)[20].lpVtbl)(
                     directDrawObject,
                     windowHandle,
                     8);
      if ( errorCodec )
        fatalDirectDrawError(errorCodec, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 39);
    }
    if ( dword_519714 )
    {
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)dword_519714 + 8))(dword_519714);
      dword_519714 = 0;
    }
    sub_49AE20();
    errorCoded = (*(int (__cdecl **)(_DWORD, _DWORD))(*(_DWORD *)dword_519714 + 124))(dword_519714, dword_519720);
    if ( errorCoded )
      fatalDirectDrawError(errorCoded, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519DB4 + 51);
    propagateSettingChanges();
    dword_519708 = 0;
    if ( *(&mainWindows + 7 * gameOrEditorIdx + 5) )
    {
      *(&mainWindows + 7 * gameOrEditorIdx + 1) = x;
      *(&mainWindows + 7 * gameOrEditorIdx + 2) = y;
      *(&mainWindows + 7 * gameOrEditorIdx + 3) = width;
      *(&mainWindows + 7 * gameOrEditorIdx + 4) = heightNeededToDisplay;
    }
    else
    {
      sub_485B30(1);
      setWindowRectangle(x, y, width, heightNeededToDisplay);
    }
    sub_49AEC0();
  }
}
