{
  townManager *thisa; // [sp+Ch] [bp-8h]@1
  int i; // [sp+10h] [bp-4h]@1

  thisa = this;
  PollSound();
  icon::DrawToBuffer(thisa->couldBeBackground, 0, 0, 0, 0);
  PollSound();
  for ( i = 0; thisa->curBuilding > i; ++i )
  {
    townObject::Draw(thisa->buildingDisplays[i], a3);
    PollSound();
  }
  heroWindow::DrawWindow(thisa->townScreen, 0, 136, 137);
  PollSound();
  if ( a2 )
    BlitBitmapToScreen(gpWindowManager->screenBuffer, 0, 0, 0x280u, 256, 0, 0);
  PollSound();
}