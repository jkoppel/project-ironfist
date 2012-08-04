{
  heroWindow *thisa; // [sp+Ch] [bp-1Ch]@1
  int width; // [sp+10h] [bp-18h]@1
  unsigned int widtha; // [sp+10h] [bp-18h]@9
  int oldY; // [sp+14h] [bp-14h]@1
  int oldX; // [sp+18h] [bp-10h]@1
  int height; // [sp+1Ch] [bp-Ch]@1
  int heighta; // [sp+1Ch] [bp-Ch]@9
  int newY; // [sp+20h] [bp-8h]@1
  int newX; // [sp+24h] [bp-4h]@1

  thisa = this;
  oldX = this->xOffset;
  oldY = this->yOffset;
  width = this->width;
  height = this->height;
  newX = deltaX + this->xOffset;
  newY = deltaY + this->yOffset;
  if ( newX < 0 )
    newX = 0;
  if ( newY < 0 )
    newY = 0;
  if ( newX + this->width > 640 )
    newX = 640 - this->width;
  if ( newY + this->height > 480 )
    newY = 480 - this->height;
  bitmap::DrawToBuffer(this->bitmap, this->xOffset, this->yOffset);
  thisa->xOffset = newX;
  thisa->yOffset = newY;
  bitmap::GrabBitmap(thisa->bitmap, gpWindowManager->screenBuffer, thisa->xOffset, thisa->yOffset);
  heroWindow::DrawWindow(thisa, 0);
  widtha = abs(thisa->xOffset - oldX) + width;
  heighta = abs(thisa->yOffset - oldY) + height;
  if ( thisa->xOffset < oldX )
    oldX = thisa->xOffset;
  if ( thisa->yOffset < oldY )
    oldY = thisa->yOffset;
  heroWindowManager::UpdateScreenRegion(gpWindowManager, oldX, oldY, widtha, heighta);
}