{
  bitmap *screenBuf; // edx@1
  int result; // eax@2

  screenBuf = gpWindowManager->screenBuffer;
  if ( mirror )
    result = FlipIconToBitmap(this, screenBuf, x, y, spriteIdx, 0, 0, 0, 640, 480, 0);
  else
    result = IconToBitmap(this, screenBuf, x, y, spriteIdx, 0, 0, 0, 640u, 480, 0);
  return result;
}