int __thiscall sub_4CE8F0(MouseManager *this)
{
  int v1; // edx@1
  MouseManager *thisa; // esi@1
  int cursorIdx; // edi@1
  int newCursorWidth; // eax@1
  int *widthPtr; // ecx@1
  int v6; // eax@3
  int v7; // edi@3
  int *heightPtr; // edx@3
  int width; // ecx@5

  v1 = this->field_66;
  thisa = this;
  cursorIdx = this->cursorIdx;
  newCursorWidth = cursorDimensions[cursorIdx].width;
  widthPtr = &this->cursorWidth;
  if ( v1 + newCursorWidth > 640 )
    newCursorWidth = 640 - v1;
  *widthPtr = newCursorWidth;
  v6 = cursorDimensions[cursorIdx].height;
  v7 = thisa->field_6A;
  heightPtr = &thisa->cursorHeight;
  if ( v7 + v6 > 480 )
    v6 = 480 - v7;
  width = *widthPtr;
  *heightPtr = v6;
  Bitmap::blitTo(
    HeroWindowManager::instance->screenBuffer,
    thisa->bitmap,
    0,
    0,
    thisa->cursorTopLeftX,
    thisa->cursorTopLeftY,
    width,
    *heightPtr);
  return rasterize(
           thisa->cursorIcon,
           HeroWindowManager::instance->screenBuffer,
           thisa->field_66,
           thisa->field_6A,
           thisa->spriteIdx,
           1,
           0,
           0,
           640u,
           480,
           0);
}
