{
  signed int result; // eax@2
  void *v2; // [sp+Ch] [bp-1Ch]@1
  void *a1; // [sp+10h] [bp-18h]@9
  int y; // [sp+14h] [bp-14h]@9
  int x; // [sp+18h] [bp-10h]@9
  unsigned int heightNeededToDisplay; // [sp+1Ch] [bp-Ch]@9
  unsigned int width; // [sp+20h] [bp-8h]@9
  int v8; // [sp+24h] [bp-4h]@9

  v2 = this;
  if ( (void *)giGraphicsType == this )
  {
    result = 1;
  }
  else if ( this != (void *)1 || gbWinGAttached )
  {
    if ( this != (void *)2 || gbDDrawAttached )
    {
      v8 = *(&bMenu + 7 * giCurExe + 5);
      x = *(&bMenu + 7 * giCurExe + 1);
      y = *(&bMenu + 7 * giCurExe + 2);
      width = *(&bMenu + 7 * giCurExe + 3);
      heightNeededToDisplay = *(&bMenu + 7 * giCurExe + 4);
      a1 = BaseAlloc(0x4B000u, "F:\\h2xsrc\\Source\\wingraph.cpp", word_519F88 + 18);
      memcpy(a1, gpWindowManager->screenBuffer->contents, 0x4B000u);
      if ( v2 == (void *)1 )
      {
        *(&bMenu + 7 * giCurExe + 5) = 0;
        DDCleanUpWinGraphics();
        giGraphicsType = 1;
        WGInitGraphics();
        gpWindowManager->screenBuffer->contents = (unsigned __int8 *)lpInitWin;
      }
      else
      {
        WGCleanUpWinGraphics();
        giGraphicsType = 2;
        DDInitGraphics();
        gpWindowManager->screenBuffer->contents = (unsigned __int8 *)lpInitWin;
      }
      memcpy(gpWindowManager->screenBuffer->contents, a1, 0x4B000u);
      BaseFree(a1, (int)"F:\\h2xsrc\\Source\\wingraph.cpp", word_519F88 + 39);
      if ( v8 )
      {
        if ( v2 == (void *)1 )
        {
          SetMenuStatus(1);
          ResizeWindow(x, y, width, heightNeededToDisplay);
        }
      }
      BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 640u, 480, 0, 0);
      UpdatePalette(gpBufferPalette->contents);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}