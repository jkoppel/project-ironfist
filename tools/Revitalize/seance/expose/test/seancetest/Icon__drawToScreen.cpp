int __thiscall Icon::drawToScreen(Icon *this, int x, int y, int spriteIdx, int mirror)
{
  Bitmap *screenBuf; // edx@1
  int result; // eax@2

  screenBuf = HeroWindowManager::instance->screenBuffer;
  if ( mirror )
    result = rasterizeMirrored(this, screenBuf, x, y, spriteIdx, 0, 0, 0, 640, 480, 0);
  else
    result = rasterize(this, screenBuf, x, y, spriteIdx, 0, 0, 0, 640u, 480, 0);
  return result;
}
