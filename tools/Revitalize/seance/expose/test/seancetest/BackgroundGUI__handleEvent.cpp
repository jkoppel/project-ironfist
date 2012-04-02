signed int __thiscall BackgroundGUI::handleEvent(BackgroundGUI *this, InputEvent *evt)
{
  __int16 v2; // si@1
  INPUT_EVENT_CODE code; // eax@1
  signed int result; // eax@3
  GUIWindow *v5; // eax@7
  __int16 x; // bx@7
  __int16 y; // di@7

  v2 = this->flagsRelatedToShouldDisplayAndPerhapsMouseCode;
  code = evt->eventCode;
  if ( v2 & 2 )
  {
    switch ( code )
    {
      default:
        result = AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
        break;
      case INPUT_LEFT_CLICK_EVENT_CODE:
      case INPUT_RIGHT_CLICK:
        v5 = this->parentWindow;
        x = evt->xCoordOrKeycode - LOWORD(v5->xOffset);
        y = evt->yCoord - LOWORD(v5->yOffset);
        if ( this->offsetX > x
          || this->offsetY > y
          || this->offsetX + this->width <= x
          || this->offsetY + this->height <= y )
        {
          result = 0;
        }
        else
        {
          if ( evt->eventCode == INPUT_RIGHT_CLICK )
          {
            evt->inputTypeBitmask = INPUT_GUI_MESSAGE_CODE;
            evt->xCoordOrKeycode = 14;
          }
          else
          {
            this->flagsRelatedToShouldDisplayAndPerhapsMouseCode = v2 | 1;
            evt->xCoordOrKeycode = 12;
          }
          evt->eventCode = 512;
          evt->yCoord = this->fieldID;
          result = 2;
        }
        break;
      case INPUT_LEFT_UP_EVENT_CODE:
      case INPUT_RIGHT_UP_EVENT_CODE:
        if ( v2 & 1 )
        {
          this->flagsRelatedToShouldDisplayAndPerhapsMouseCode = v2 & 0xFFFE;
          evt->eventCode = 512;
          evt->xCoordOrKeycode = 13;
          evt->yCoord = this->fieldID;
          result = 2;
        }
        else
        {
          result = 0;
        }
        break;
    }
  }
  else
  {
    if ( code == 512 )
      result = AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
    else
      result = 0;
  }
  return result;
}
