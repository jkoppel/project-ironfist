int __thiscall GUIWindow::grabBitmapFromScreen(GUIWindow *this)
{
  GUIWindow *thisa; // [sp+Ch] [bp-8h]@1
  Bitmap *bmp; // [sp+10h] [bp-4h]@1

  thisa = this;
  bmp = (Bitmap *)operator new(26);
  if ( bmp )
    thisa->bitmap = Bitmap_constructor(bmp, 33, thisa->width, thisa->height);
  else
    thisa->bitmap = 0;
  yieldToGlobalUpdater();
  Bitmap::getContentsFromScreen(thisa->bitmap, thisa->xOffset, thisa->yOffset);
  yieldToGlobalUpdater();
  return 0;
}
