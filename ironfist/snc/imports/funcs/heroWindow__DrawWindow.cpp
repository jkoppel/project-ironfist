{
  heroWindow *thisa; // [sp+Ch] [bp-24h]@1
  tag_message evt; // [sp+10h] [bp-20h]@1
  widget *comp; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  gpMouseManager->couldBeShowMouse = 0;
  comp = this->lastComponent;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = 2;
  while ( comp )
  {
    PollSound();
    if ( lowID == -65535 && highID == 65535 )
    {
      comp->vtable->handleEvent(comp, &evt);
    }
    else if ( comp->fieldID >= lowID )
    {
      if ( comp->fieldID <= highID )
        comp->vtable->handleEvent(comp, &evt);
    }
    comp = comp->prevInLinkedList;
  }
  PollSound();
  if ( updateScreen && (thisa->flags1 & 0x7FFF) != 1 )
  {
    heroWindowManager::UpdateScreenRegion(gpWindowManager, thisa->xOffset, thisa->yOffset, thisa->width, thisa->height);
    PollSound();
  }
  gpMouseManager->couldBeShowMouse = 1;
}