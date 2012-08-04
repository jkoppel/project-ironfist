{
  heroWindow *window; // eax@1
  button *thisa; // esi@1
  int xPos; // edi@1
  int yPos; // ebx@1
  char v6; // zf@1
  int v7; // ecx@3
  signed __int16 result; // ax@3

  window = this->parentWindow;
  thisa = this;
  xPos = (signed __int16)(LOWORD(window->xOffset) + HIWORD(this->flags));
  yPos = (signed __int16)(LOWORD(window->yOffset) + this->offsetY);
  icon::DrawToBuffer(this->icon, xPos, yPos, this->armedImageIdx, 0);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, xPos, yPos, thisa->width, thisa->height);
  LOBYTE(thisa->flags) |= 1u;
  evt->eventCode = 512;
  evt->yCoord = thisa->fieldID;
  v6 = thisa->field_28 == 1;
  evt->xCoordOrKeycode = 10;
  if ( !v6 )
    evt->xCoordOrKeycode = 12;
  v7 = KBTickCount() + 60;
  result = 2;
  dword_524BF0 = v7;
  iLeftRightSave = evt->inputTypeBitmask & 0x300;
  return result;
}