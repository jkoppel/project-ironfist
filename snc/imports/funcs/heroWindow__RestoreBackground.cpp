{
  heroWindow *result; // eax@5
  heroWindow *thisa; // [sp+Ch] [bp-Ch]@1
  bitmap *bmp; // [sp+14h] [bp-4h]@3

  thisa = this;
  if ( gbDrawWindowBackground )
  {
    bitmap::DrawToBuffer(this->bitmap, this->xOffset, this->yOffset);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, thisa->xOffset, thisa->yOffset, thisa->width, thisa->height);
  }
  bmp = thisa->bitmap;
  if ( bmp )
    ((void (__thiscall *)(_DWORD))bmp->vtable->cleanUp)(bmp);
  result = thisa;
  thisa->bitmap = NULL;
  return result;
}