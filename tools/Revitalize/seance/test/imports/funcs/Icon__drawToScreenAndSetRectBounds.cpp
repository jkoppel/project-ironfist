{
  int idx; // edx@2
  int headerOffset; // ebx@2
  LONG right; // esi@3
  H2RECT *recta; // edi@3
  int imgOffsetY; // eax@3
  LONG left; // esi@4
  int offY; // esi@5
  Bitmap *screenBuf; // edx@25
  int v18; // [sp-24h] [bp-34h]@35
  int v19; // [sp-20h] [bp-30h]@25
  int v20; // [sp-20h] [bp-30h]@35
  int v21; // [sp-1Ch] [bp-2Ch]@35
  signed int v22; // [sp-18h] [bp-28h]@35
  int v23; // [sp-14h] [bp-24h]@35
  int v24; // [sp-10h] [bp-20h]@35
  int v25; // [sp-Ch] [bp-1Ch]@35
  int v26; // [sp-8h] [bp-18h]@35
  int v27; // [sp-4h] [bp-14h]@33

  if ( dword_4F7480 )
  {
    idx = imageIdx;
    headerOffset = imageIdx;
    if ( mirrored )
    {
      right = offsetX - this->headersAndImageData[headerOffset].offsetX;
      recta = rect;
      rect->right = right;
      rect->left = right - this->headersAndImageData[headerOffset].width + 1;
      imgOffsetY = this->headersAndImageData[headerOffset].offsetY;
    }
    else
    {
      recta = rect;
      left = offsetX + this->headersAndImageData[headerOffset].offsetX;
      rect->left = left;
      rect->right = left + this->headersAndImageData[headerOffset].width - 1;
      imgOffsetY = this->headersAndImageData[headerOffset].offsetY;
    }
    offY = offsetY;
    recta->top = imgOffsetY + offsetY;
    recta->bottom = imgOffsetY + offsetY + this->headersAndImageData[headerOffset].height - 1;
    if ( dword_4F7484 )
    {
      if ( combatScreenRedrawRectLeft > recta->left )
        combatScreenRedrawRectLeft = recta->left;
      if ( combatScreenRedrawRectTop > recta->top )
        combatScreenRedrawRectTop = recta->top;
      if ( recta->right > combatScreenRedrawRectRight )
        combatScreenRedrawRectRight = recta->right;
      if ( recta->bottom > combatScreenRedrawRectBot )
        combatScreenRedrawRectBot = recta->bottom;
    }
    if ( dword_4F1998 )
      return 0;
  }
  else
  {
    offY = offsetY;
    idx = imageIdx;
    recta = rect;
  }
  if ( dword_4F7488
    && (!dword_4F748C
     || recta->left > combatScreenRedrawRectRight
     || recta->right < combatScreenRedrawRectLeft
     || recta->top > combatScreenRedrawRectBot
     || recta->bottom < combatScreenRedrawRectTop) )
    return 0;
  if ( a12 )
  {
    v19 = idx;
    screenBuf = HeroWindowManager::instance->screenBuffer;
    if ( mirrored )
      sub_4DD1B0((int)this, (int)screenBuf, offsetX, offY, v19, 1, 0, 0, 640, 444, a11, a12);
    else
      sub_4DD740(this, screenBuf, offsetX, offY, v19, 1, 0, 0, 640u, 444, a11, a12);
    return 1;
  }
  if ( paletteSubstitution )
  {
    if ( mirrored )
      rasterizeWithSubstitutionMirrored(
        this,
        HeroWindowManager::instance->screenBuffer,
        offsetX,
        offY,
        idx,
        1,
        0,
        0,
        640,
        444,
        a11,
        paletteSubstitution);
    else
      rasterizeWithSubstitution(
        this,
        HeroWindowManager::instance->screenBuffer,
        offsetX,
        offY,
        idx,
        1,
        0,
        0,
        640u,
        444,
        a11,
        paletteSubstitution,
        1);
    return 1;
  }
  if ( !dword_4F7488 )
  {
    v27 = a11;
    v26 = 444;
    v25 = 640;
    v24 = 0;
    v23 = 0;
    v22 = 1;
    v21 = idx;
    v20 = offY;
    v18 = offsetX;
    if ( !mirrored )
    {
      rasterize(this, HeroWindowManager::instance->screenBuffer, offsetX, offY, idx, 1, 0, 0, 0x280u, 444, a11);
      return 1;
    }
LABEL_38:
    rasterizeMirrored(this, HeroWindowManager::instance->screenBuffer, v18, v20, v21, v22, v23, v24, v25, v26, v27);
    return 1;
  }
  v27 = a11;
  if ( mirrored )
  {
    v26 = combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1;
    v25 = combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1;
    v24 = combatScreenRedrawRectTop;
    v23 = combatScreenRedrawRectLeft;
    v22 = 1;
    v21 = idx;
    v20 = offY;
    v18 = offsetX;
    goto LABEL_38;
  }
  rasterize(
    this,
    HeroWindowManager::instance->screenBuffer,
    offsetX,
    offY,
    idx,
    1,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1,
    a11);
  return 1;
}
