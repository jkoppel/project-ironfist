signed int __thiscall AbstractGUIComponent::handleEvent(AbstractGUIComponent *this, Event *evt)
{
  AbstractGUIComponent *thisa; // esi@1
  signed int result; // eax@3
  __int16 offX; // bp@4
  GUIWindow *window; // eax@4
  __int16 x; // dx@4
  __int16 y; // di@4
  __int16 offY; // ax@5
  __int16 v9; // ax@13
  void *v10; // eax@17
  __int16 v11; // cx@19
  __int16 v12; // ax@20
  void *v13; // edi@27

  thisa = this;
  if ( evt->inputEvt.eventCode == INPUT_MOUSEMOVE_EVENT_CODE )
  {
    offX = this->offsetX;
    window = this->parentWindow;
    x = evt->inputEvt.xCoordOrKeycode - LOWORD(window->xOffset);
    y = evt->inputEvt.yCoord - LOWORD(window->yOffset);
    if ( x < offX )
      return 0;
    offY = this->offsetY;
    if ( y < offY || offX + this->width <= x || offY + this->height <= y )
      return 0;
    evt->inputEvt.yCoord = this->fieldID;
    result = 2;
  }
  else
  {
    if ( evt->inputEvt.eventCode != INPUT_GUI_MESSAGE_CODE )
      return 0;
    switch ( evt->inputEvt.xCoordOrKeycode )
    {
      default:
        return 0;
      case GUI_MESSAGE_REPAINT:
        if ( this->field_16 & 4 )
          this->vtable->paint(this);
        if ( !(thisa->field_16 & 8) )
          return 0;
        v9 = thisa->field_14;
        if ( v9 == 8 || v9 == 512 )
          return 0;
        Bitmap::colorSubstituteRectangle(
          HeroWindowManager::instance->screenBuffer,
          (signed __int16)(LOWORD(thisa->parentWindow->xOffset) + thisa->offsetX),
          (signed __int16)(LOWORD(thisa->parentWindow->yOffset) + thisa->offsetY),
          thisa->width,
          thisa->height,
          0);
        return 0;
      case GUI_MESSAGE_ADD_FLAGS:
        if ( this->fieldID != evt->inputEvt.yCoord )
          return 0;
        v10 = evt->inputEvt.payload;
        if ( v10 == (void *)4096 )
        {
          result = 1;
          LOBYTE(this->field_16) |= 8u;
        }
        else
        {
          v11 = (unsigned __int16)v10 | this->field_16;
          thisa->field_16 = v11;
          if ( v11 & 8 )
          {
            thisa->vtable->paint(thisa);
            v12 = thisa->field_14;
            if ( v12 != 8 )
            {
              if ( v12 != 512 )
                Bitmap::colorSubstituteRectangle(
                  HeroWindowManager::instance->screenBuffer,
                  (signed __int16)(LOWORD(thisa->parentWindow->xOffset) + thisa->offsetX),
                  (signed __int16)(LOWORD(thisa->parentWindow->yOffset) + thisa->offsetY),
                  thisa->width,
                  thisa->height,
                  0);
            }
          }
          if ( HIBYTE(thisa->field_16) & 0x40 )
          {
            HeroWindowManager::redrawRectangle(
              HeroWindowManager::instance,
              thisa->parentWindow->xOffset + thisa->offsetX,
              thisa->parentWindow->yOffset + thisa->offsetY,
              thisa->width,
              thisa->height);
            HIBYTE(thisa->field_16) &= 0xBFu;
          }
          result = 1;
        }
        return result;
      case GUI_MESSAGE_SET_IMG_IDX|GUI_MESSAGE_REPAINT:
        if ( this->fieldID != evt->inputEvt.yCoord )
          return 0;
        v13 = evt->inputEvt.payload;
        if ( v13 == (void *)4096 )
        {
          result = 1;
          LOBYTE(this->field_16) &= 0xF7u;
        }
        else
        {
          this->field_16 &= ~(_WORD)v13;
          if ( (unsigned __int8)v13 & 8 )
            this->vtable->paint(this);
          if ( (unsigned __int16)v13 & 0x4000 )
            HeroWindowManager::redrawRectangle(
              HeroWindowManager::instance,
              thisa->parentWindow->xOffset + thisa->offsetX,
              thisa->parentWindow->yOffset + thisa->offsetY,
              thisa->width,
              thisa->height);
          result = 1;
        }
        return result;
      case GUI_MESSAGE_SET_OFFSETX:
        if ( this->fieldID != evt->inputEvt.yCoord )
          return 0;
        this->offsetX = (__int16)evt->inputEvt.payload;
        return 1;
      case GUI_MESSAGE_SET_OFFSETY:
        if ( this->fieldID != evt->inputEvt.yCoord )
          return 0;
        this->offsetY = (__int16)evt->inputEvt.payload;
        return 1;
      case GUI_MESSAGE_SET_WIDTH:
        if ( this->fieldID != evt->inputEvt.yCoord )
          return 0;
        this->width = (__int16)evt->inputEvt.payload;
        result = 1;
        break;
    }
  }
  return result;
}
