{
  GUIWindow *result; // eax@5
  GUIWindow *thisa; // [sp+Ch] [bp-Ch]@1
  Bitmap *bitmap; // [sp+14h] [bp-4h]@3

  thisa = this;
  if ( dword_4F1CC4 )
  {
    Bitmap::drawToScreenBuffer(this->bitmap, this->xOffset, this->yOffset);
    HeroWindowManager::redrawRectangle(
      HeroWindowManager::instance,
      thisa->xOffset,
      thisa->yOffset,
      thisa->width,
      thisa->height);
  }
  bitmap = thisa->bitmap;
  if ( bitmap )
    ((void (__thiscall *)(_DWORD))bitmap->vtable->cleanUp)(bitmap);
  result = thisa;
  thisa->bitmap = NULL;
  return result;
}
