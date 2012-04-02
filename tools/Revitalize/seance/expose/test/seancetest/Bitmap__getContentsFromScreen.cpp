void __thiscall Bitmap::getContentsFromScreen(Bitmap *to, __int16 xOff, __int16 yOff)
{
  blit(HeroWindowManager::instance->screenBuffer, xOff, yOff, to->width, to->height, to, 0, 0);
}
