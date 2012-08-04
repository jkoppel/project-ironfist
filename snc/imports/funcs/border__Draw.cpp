{
  heroWindow *window; // eax@1
  border *thisa; // esi@1
  int v3; // ebx@1
  int v4; // edi@1
  int v5; // eax@1
  __int16 x; // di@1
  __int16 y; // bx@1

  window = this->parentWindow;
  thisa = this;
  v3 = window->yOffset;
  v4 = window->xOffset;
  v5 = this->backgroundType;
  x = this->offsetX + v4;
  y = this->offsetY + v3;
  switch ( v5 )
  {
    case BACKGROUND_IS_SOLID:
      FillBitmapArea(gpWindowManager->screenBuffer, x, y, this->width, this->height, this->color);
      break;
    case BACKGROUND_IS_FROM_FILE:
      PollSound();
      BlitBitmap(thisa->bitmap, 0, 0, thisa->width, thisa->height, gpWindowManager->screenBuffer, x, y);
      PollSound();
      break;
    case BACKGROUND_IS_FROM_FILE|BACKGROUND_IS_ICON:
      icon::DrawToBuffer(this->icon, x, y, 0, 0);
      break;
  }
}