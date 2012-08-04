{
  bitmap *thisa; // esi@1
  bitmap *screenBuf; // edx@2
  int screenWidth; // ebx@2
  int thisRight; // eax@2
  unsigned __int8 v7; // zf@2
  unsigned __int8 v8; // sf@2
  unsigned __int8 v9; // of@2
  __int16 v10; // ax@2
  unsigned int v11; // edx@7
  int v12; // edi@7
  unsigned int v13; // ecx@7
  int v14; // ebx@10
  int v15; // eax@12
  int v16; // eax@14
  bitmap *to; // [sp+14h] [bp-4h]@12

  thisa = from;
  if ( x < 0 )
  {
    v10 = y;
  }
  else
  {
    screenBuf = gpWindowManager->screenBuffer;
    screenWidth = screenBuf->width;
    thisRight = x + from->width;
    v9 = __OFSUB__(thisRight, screenWidth);
    v7 = thisRight == screenWidth;
    v8 = thisRight - screenWidth < 0;
    v10 = y;
    if ( (unsigned __int8)(v8 ^ v9) | v7 && y >= 0 && y + from->height <= screenBuf->height )
    {
      PollSound();
      BlitBitmap(thisa, 0, 0, thisa->width, thisa->height, gpWindowManager->screenBuffer, x, y);
      PollSound();
      return;
    }
  }
  v11 = from->width;
  v12 = from->height;
  v13 = x;
  if ( x < 0 )
  {
    v11 += x;
    v13 = 0;
  }
  if ( v10 >= 0 )
  {
    v14 = v10;
  }
  else
  {
    v12 += v10;
    v14 = 0;
  }
  v15 = gpWindowManager->screenBuffer->width;
  to = gpWindowManager->screenBuffer;
  if ( (signed int)(v13 + v11) > v15 )
    v11 = v15 - v13;
  v16 = to->height;
  if ( v12 + v14 > v16 )
    v12 = v16 - v14;
  if ( (signed int)v11 >= 0 )
  {
    if ( v12 >= 0 )
      BlitBitmap(thisa, 0, 0, v11, v12, to, v13, v14);
  }
}