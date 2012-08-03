{
  heroWindow *thisa; // [sp+Ch] [bp-8h]@1
  bitmap *bmp; // [sp+10h] [bp-4h]@1

  thisa = this;
  bmp = (bitmap *)operator new(26);
  if ( bmp )
    thisa->bitmap = bitmap::bitmap(bmp, 33, thisa->width, thisa->height);
  else
    thisa->bitmap = 0;
  PollSound();
  bitmap::GrabScreen(thisa->bitmap, thisa->xOffset, thisa->yOffset);
  PollSound();
  return 0;
}