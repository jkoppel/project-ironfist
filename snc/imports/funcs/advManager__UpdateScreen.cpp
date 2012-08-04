{
  if ( a3 || bShowIt )
  {
    PollSound();
    giScrollX = this->field_1F6;
    giScrollY = this->field_1FA;
    if ( giLimitUpdMinX == -1 )
      BlitBitmapToScreen(gpWindowManager->screenBuffer, 16, 16, 0x1C0u, 448, 16, 16);
    else
      BlitBitmapToScreen(
        gpWindowManager->screenBuffer,
        giLimitUpdMinX,
        giLimitUpdMinY,
        giLimitUpdMaxX - giLimitUpdMinX,
        giLimitUpdMaxY - giLimitUpdMinY,
        giLimitUpdMinX,
        giLimitUpdMinY);
    giScrollY = 0;
    giScrollX = 0;
    PollSound();
    if ( KBTickCount() > glTimers )
    {
      ++this->field_202;
      ++this->field_1FE;
      if ( this->field_1FE >= 6 )
        this->field_1FE = 0;
      glTimers = KBTickCount() + 120;
      if ( this->field_1FE != 1 && this->field_1FE != 3 && this->field_1FE != 5 )
      {
        ++this->field_20A;
        this->field_20A %= 18;
        ++this->field_212;
        this->field_212 %= 18;
      }
      else
      {
        ++this->field_20E;
        this->field_20E %= 18;
        ++this->field_216;
        this->field_216 %= 18;
      }
    }
    giLimitUpdMinX = -1;
    Process1WindowsMessage();
  }
  else if ( KBTickCount() > glTimers )
  {
    glTimers = KBTickCount() + 120;
  }
}