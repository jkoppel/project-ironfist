{
  int idx; // edx@2
  int headerOffset; // ebx@2
  LONG right; // esi@3
  H2RECT *recta; // edi@3
  int imgOffsetY; // eax@3
  LONG left; // esi@4
  int offY; // esi@5
  bitmap *screenBuf; // edx@25
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

  if ( gbComputeExtent )
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
    if ( gbSaveBiggestExtent )
    {
      if ( giMinExtentX > recta->left )
        giMinExtentX = recta->left;
      if ( giMinExtentY > recta->top )
        giMinExtentY = recta->top;
      if ( recta->right > giMaxExtentX )
        giMaxExtentX = recta->right;
      if ( recta->bottom > giMaxExtentY )
        giMaxExtentY = recta->bottom;
    }
    if ( gbReturnAfterComputeExtent )
      return 0;
  }
  else
  {
    offY = offsetY;
    idx = imageIdx;
    recta = rect;
  }
  if ( gbLimitToExtent
    && (!gbCurrArmyDrawn
     || recta->left > giMaxExtentX
     || recta->right < giMinExtentX
     || recta->top > giMaxExtentY
     || recta->bottom < giMinExtentY) )
    return 0;
  if ( a12 )
  {
    v19 = idx;
    screenBuf = gpWindowManager->screenBuffer;
    if ( mirrored )
      FlipIconToBitmapYModify((int)this, (int)screenBuf, offsetX, offY, v19, 1, 0, 0, 640, 444, a11, a12);
    else
      IconToBitmapYModify(this, screenBuf, offsetX, offY, v19, 1, 0, 0, 640u, 444, a11, a12);
    return 1;
  }
  if ( paletteSubstitution )
  {
    if ( mirrored )
      FlipIconToBitmapColorTable(
        this,
        gpWindowManager->screenBuffer,
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
      IconToBitmapColorTable(
        this,
        gpWindowManager->screenBuffer,
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
  if ( !gbLimitToExtent )
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
      IconToBitmap(this, gpWindowManager->screenBuffer, offsetX, offY, idx, 1, 0, 0, 0x280u, 444, a11);
      return 1;
    }
LABEL_38:
    FlipIconToBitmap(this, gpWindowManager->screenBuffer, v18, v20, v21, v22, v23, v24, v25, v26, v27);
    return 1;
  }
  v27 = a11;
  if ( mirrored )
  {
    v26 = giMaxExtentY - giMinExtentY + 1;
    v25 = giMaxExtentX - giMinExtentX + 1;
    v24 = giMinExtentY;
    v23 = giMinExtentX;
    v22 = 1;
    v21 = idx;
    v20 = offY;
    v18 = offsetX;
    goto LABEL_38;
  }
  IconToBitmap(
    this,
    gpWindowManager->screenBuffer,
    offsetX,
    offY,
    idx,
    1,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1,
    a11);
  return 1;
}