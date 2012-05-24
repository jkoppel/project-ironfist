{
  GUIWindow *thisa; // [sp+Ch] [bp-24h]@1
  InputEvent evt; // [sp+10h] [bp-20h]@1
  AbstractGUIComponent *comp; // [sp+2Ch] [bp-4h]@1

  thisa = this;
  mouseManager->couldBeShowMouse = 0;
  comp = this->lastComponent;
  evt.eventCode = INPUT_GUI_MESSAGE_CODE;
  evt.xCoordOrKeycode = 2;
  while ( comp )
  {
    yieldToGlobalUpdater();
    if ( lowID == -65535 && highID == 65535 )
    {
      comp->vtable->handleEvent(comp, &evt);
    }
    else
    {
      if ( comp->fieldID >= lowID )
      {
        if ( comp->fieldID <= highID )
          comp->vtable->handleEvent(comp, &evt);
      }
    }
    comp = comp->prevInLinkedList;
  }
  yieldToGlobalUpdater();
  if ( updateScreen && (thisa->flags1 & 0x7FFF) != 1 )
  {
    HeroWindowManager::redrawRectangle(
      HeroWindowManager::instance,
      thisa->xOffset,
      thisa->yOffset,
      thisa->width,
      thisa->height);
    yieldToGlobalUpdater();
  }
  mouseManager->couldBeShowMouse = 1;
}
