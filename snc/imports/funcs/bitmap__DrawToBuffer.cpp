{
  bitmap *thisa; // esi@1

  thisa = from;
  PollSound();
  BlitBitmap(thisa, 0, 0, thisa->width, thisa->height, gpWindowManager->screenBuffer, x, y);
  PollSound();
}