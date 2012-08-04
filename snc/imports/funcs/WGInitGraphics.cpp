{
  int v0; // ST34_4@5

  if ( !hdcImage )
  {
    if ( thunk_WinGRecommendDIBFormat() )
    {
      word_52FFFE = 8;
      dword_530000 = 0;
      Orientation = dword_52FFF8;
    }
    else
    {
      screenImage = 40;
      word_52FFFC = 1;
      word_52FFFE = 8;
      dword_530000 = 0;
      dword_530004 = 0;
      dword_530010 = 0;
      dword_530014 = 0;
    }
    dword_52FFF4 = 640;
    dword_52FFF8 = -480;
    InitializePalette();
    hdcImage = (HDC)thunk_WinGCreateDC();
    dword_52FFF4 = 640;
    dword_52FFF8 = -480;
    v0 = thunk_WinGCreateBitmap();
    dword_530004 = Orientation * dword_52FFF8 * dword_52FFF4;
    gbmOldMonoBitmap = SelectObject(hdcImage, (HGDIOBJ)v0);
    lpInitWin = (bitmap *)dword_530418;
    PatBlt(hdcImage, 0, 0, iMainWinScreenWidth, iMainWinScreenHeight, 0x42u);
  }
}