{
  void *v1; // esi@1

  v1 = this;
  if ( giDebugLevel >= 2 )
  {
    FillBitmapArea(gpWindowManager->screenBuffer, 0, 460, 0x280u, 20, 0);
    font::DrawBoundedString(smallFont, (const char *)v1, 0, 464, 640, 16, 1, 0);
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 460, 0x280u, 20, 0, 460);
  }
}