{
  int v7; // ebp@2
  signed int v8; // ebx@3
  int v9; // eax@3
  int v10; // esi@4
  int v11; // eax@14
  RECT Rect; // [sp+14h] [bp-10h]@28

  if ( gpWindowManager->screenBuffer == bmp || (v7 = 0, height <= 0) )
  {
    v8 = width;
  }
  else
  {
    v8 = width;
    v9 = 640 * screenY;
    do
    {
      v10 = v7++ + y;
      memcpy(&gpWindowManager->screenBuffer->contents[screenX] + v9, &bmp->contents[bmp->width * v10] + x, width);
      v9 += 640;
    }
    while ( v7 < height );
  }
  if ( gbEnlargeScreenBlit && !*(&bMenu + 7 * giCurExe + 5) )
  {
    if ( iMainWinScreenWidth != 640 || iMainWinScreenHeight != 480 )
    {
      if ( screenX > 0 )
        --screenX;
      if ( screenY > 0 )
        --screenY;
      if ( v8 < 637 )
        v8 += 4;
      if ( height < 637 )
      {
        v11 = height + 4;
        goto LABEL_23;
      }
    }
    else
    {
      if ( v8 < 640 )
        ++v8;
      if ( height < 640 )
      {
        v11 = height + 1;
LABEL_23:
        height = v11;
        goto LABEL_24;
      }
    }
  }
LABEL_24:
  if ( dword_4F1CC0 )
  {
    if ( screenY >= 411 )
      return;
    if ( height + screenY >= 411 )
      height = 411 - screenY;
  }
  Rect.left = screenX * iMainWinScreenWidth / 640;
  Rect.top = iMainWinScreenHeight * screenY / 480;
  Rect.right = iMainWinScreenWidth * (v8 + screenX) / 640 - 1;
  Rect.bottom = iMainWinScreenHeight * (height + screenY) / 480 - 1;
  if ( !InvalidateRect(hwndApp, &Rect, 0) )
    LogStr("InvalidateRect Failed");
  if ( !UpdateWindow(hwndApp) )
    LogStr("UpdateWindow Failed");
}