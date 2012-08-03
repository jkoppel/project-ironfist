{
  if ( gShingleAnim )
  {
    if ( KBTickCount() > iNextShingleAnim )
    {
      iNextShingleAnim = KBTickCount() + 250;
      iShingleAnimFrame = (iShingleAnimFrame + 1) % 39;
      icon::DrawToBuffer(gShingleAnim, 0, 0, iShingleAnimFrame + 1, 0);
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 46, 176, 0x8Bu, 187);
    }
  }
}