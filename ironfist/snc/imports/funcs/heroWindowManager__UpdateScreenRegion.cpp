{
  heroWindowManager *thisa; // esi@1

  thisa = this;
  gpMouseManager->couldBeShowMouse = 0;
  PollSound();
  BlitBitmapToScreen(thisa->screenBuffer, offsetX, offsetY, width, height, offsetX, offsetY);
  gpMouseManager->couldBeShowMouse = 1;
  PollSound();
}