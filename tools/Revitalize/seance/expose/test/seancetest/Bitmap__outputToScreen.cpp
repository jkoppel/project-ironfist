void __fastcall Bitmap::outputToScreen(Bitmap *bmp, int x, int y, unsigned int width, int height, int screenX, signed int screenY)
{
  int v7; // ebp@2
  signed int v8; // ebx@3
  int v9; // eax@3
  int v10; // esi@4
  int v11; // eax@14
  RECT Rect; // [sp+14h] [bp-10h]@28

  if ( HeroWindowManager::instance->screenBuffer == bmp || (v7 = 0, height <= 0) )
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
      memcpy(
        &HeroWindowManager::instance->screenBuffer->contents[screenX] + v9,
        &bmp->contents[bmp->width * v10] + x,
        width);
      v9 += 640;
    }
    while ( v7 < height );
  }
  if ( fullScreenRelated && !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
  {
    if ( couldBeScreenWidth != 640 || couldBeScreenHeight != 480 )
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
  Rect.left = screenX * couldBeScreenWidth / 640;
  Rect.top = couldBeScreenHeight * screenY / 480;
  Rect.right = couldBeScreenWidth * (v8 + screenX) / 640 - 1;
  Rect.bottom = couldBeScreenHeight * (height + screenY) / 480 - 1;
  if ( !InvalidateRect(windowHandle, &Rect, 0) )
    debugLog("InvalidateRect Failed");
  if ( !UpdateWindow(windowHandle) )
    debugLog("UpdateWindow Failed");
}
