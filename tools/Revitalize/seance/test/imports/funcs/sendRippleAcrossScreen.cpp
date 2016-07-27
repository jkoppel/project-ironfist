{
  signed int xOffset; // ecx@2
  int x; // edi@3
  unsigned __int8 *targContents; // ebx@6
  int y; // eax@6
  unsigned __int8 *ptr; // ebp@6
  unsigned int width; // eax@11
  int xOff; // edx@11
  signed int leftX; // [sp+10h] [bp-2C4h]@1
  char yDistortionForOffset[51]; // [sp+14h] [bp-2C0h]@1
  int nextFrameTime; // [sp+48h] [bp-28Ch]@2
  Bitmap *toBmp; // [sp+4Ch] [bp-288h]@1
  Bitmap *fromBmp; // [sp+50h] [bp-284h]@1
  char firstRowWrittenFor[640]; // [sp+54h] [bp-280h]@1

  toBmp = bmp2;
  fromBmp = bmp1;
  MouseManager::disableCursor(mouseManager);
  yDistortionForOffset[0] = 0;
  yDistortionForOffset[1] = 0;
  yDistortionForOffset[2] = 0;
  yDistortionForOffset[3] = 0;
  yDistortionForOffset[4] = 0;
  yDistortionForOffset[5] = 0;
  yDistortionForOffset[6] = 0;
  yDistortionForOffset[7] = 1;
  yDistortionForOffset[8] = 1;
  yDistortionForOffset[9] = 1;
  yDistortionForOffset[10] = 1;
  yDistortionForOffset[11] = 1;
  yDistortionForOffset[12] = 2;
  yDistortionForOffset[13] = 2;
  yDistortionForOffset[14] = 2;
  yDistortionForOffset[15] = 2;
  yDistortionForOffset[16] = 3;
  yDistortionForOffset[17] = 3;
  yDistortionForOffset[18] = 4;
  yDistortionForOffset[19] = 5;
  yDistortionForOffset[23] = 7;
  yDistortionForOffset[24] = 7;
  yDistortionForOffset[25] = 7;
  yDistortionForOffset[26] = 7;
  yDistortionForOffset[27] = 7;
  yDistortionForOffset[20] = 6;
  yDistortionForOffset[21] = 6;
  yDistortionForOffset[22] = 6;
  yDistortionForOffset[28] = 6;
  yDistortionForOffset[29] = 6;
  yDistortionForOffset[30] = 6;
  yDistortionForOffset[31] = 5;
  yDistortionForOffset[35] = 2;
  yDistortionForOffset[36] = 2;
  yDistortionForOffset[37] = 2;
  yDistortionForOffset[38] = 2;
  yDistortionForOffset[39] = 1;
  yDistortionForOffset[40] = 1;
  yDistortionForOffset[41] = 1;
  yDistortionForOffset[42] = 1;
  yDistortionForOffset[43] = 1;
  yDistortionForOffset[44] = 0;
  yDistortionForOffset[45] = 0;
  yDistortionForOffset[46] = 0;
  yDistortionForOffset[32] = 4;
  yDistortionForOffset[33] = 3;
  yDistortionForOffset[34] = 3;
  yDistortionForOffset[47] = 0;
  yDistortionForOffset[48] = 0;
  yDistortionForOffset[49] = 0;
  yDistortionForOffset[50] = 0;
  memset(firstRowWrittenFor, 0, sizeof(firstRowWrittenFor));
  leftX = -25;
  do
  {
    yieldToGlobalUpdater();
    nextFrameTime = getTickCount();
    xOffset = 0;
    nextFrameTime = (signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 9.0 + (double)nextFrameTime);
    do
    {
      x = leftX + xOffset - 25;
      if ( x >= 0 && x < 640 && firstRowWrittenFor[x] != yDistortionForOffset[xOffset] )
      {
        targContents = &toBmp->contents[x];
        y = rippleStrengt * (unsigned __int8)yDistortionForOffset[xOffset];
        for ( ptr = &fromBmp->contents[640 * y] + x; y < height; ++y )
        {
          *targContents = *ptr;
          if ( y - height == -1 )
            break;
          targContents += 640;
          ptr += 640;
        }
        firstRowWrittenFor[x] = yDistortionForOffset[xOffset];
      }
      ++xOffset;
    }
    while ( xOffset <= 50 );
    width = 41;
    xOff = leftX - 22;
    if ( leftX - 22 < 0 )
    {
      width = xOff + 41;
      xOff = 0;
    }
    if ( (signed int)(xOff + width) > 640 )
      width = 640 - xOff;
    if ( (signed int)width >= 1 )
    {
      renderBitmapToScreenWithWinG(HeroWindowManager::instance->screenBuffer, xOff, 0, width, height, xOff, 0);
      sleepUntilPointer(&nextFrameTime);
    }
    leftX += 4;
  }
  while ( leftX < 665 );
  MouseManager::enableCursor(mouseManager);
}
