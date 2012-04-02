void __thiscall Bitmap::copyFrom(Bitmap *to, Bitmap *from, __int16 x, __int16 y)
{
  blit(from, x, y, to->width, to->height, to, 0, 0);
}
