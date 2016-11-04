{
  HeroWindowManager *thisa; // ebp@1
  int left; // eax@2
  int actualWidth; // edi@2
  int top; // esi@4
  int actualHeight; // ebx@4
  AbstractResource *v10; // ecx@12
  Bitmap *v11; // ecx@14

  thisa = this;
  if ( dword_524C14 )
  {
    left = x;
    actualWidth = width;
    if ( x < 0 )
    {
      x = 0;
      actualWidth = left + width;
    }
    top = y;
    actualHeight = height;
    if ( y < 0 )
    {
      actualHeight = y + height;
      top = 0;
    }
    if ( actualWidth + x > 640 )
      actualWidth = 640 - x;
    if ( top + actualHeight > 480 )
      actualHeight = 480 - top;
    if ( actualWidth > 0 && actualHeight > 0 )
    {
      v10 = (AbstractResource *)this->someBMP;
      if ( v10 )
        v10->vtable->cleanUp(v10, 1);
      v11 = (Bitmap *)operator new(0x1Au);
      if ( v11 )
        thisa->someBMP = Bitmap_constructor(v11, 0, actualWidth, actualHeight);
      else
        thisa->someBMP = 0;
      blit(HeroWindowManager::instance->screenBuffer, x, top, actualWidth, actualHeight, thisa->someBMP, 0, 0);
    }
  }
}
