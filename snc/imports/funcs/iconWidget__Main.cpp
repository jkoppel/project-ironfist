{
  iconWidget *thisa; // esi@1
  __int16 v3; // cx@1
  signed int result; // eax@4
  INPUT_EVENT_CODE evtCode; // edx@6
  heroWindow *parent; // ebp@14
  __int16 xRelParent; // ax@14
  __int16 yRelParent; // bx@14
  resource *v9; // ST00_4@36

  thisa = this;
  v3 = this->field_16;
  if ( !(v3 & 2) )
  {
    if ( evt->eventCode != 512 )
      return 0;
    if ( evt->xCoordOrKeycode != 60 )
      return widget::Main((widget *)thisa, (Event *)evt);
  }
  evtCode = evt->eventCode;
  if ( evt->eventCode <= INPUT_LEFT_UP_EVENT_CODE )
  {
    if ( evt->eventCode != INPUT_LEFT_UP_EVENT_CODE )
    {
      if ( evtCode != INPUT_LEFT_CLICK_EVENT_CODE )
        return widget::Main((widget *)thisa, (Event *)evt);
      goto LABEL_14;
    }
    goto LABEL_23;
  }
  if ( evtCode == INPUT_RIGHT_CLICK )
  {
LABEL_14:
    parent = thisa->parentWindow;
    xRelParent = evt->xCoordOrKeycode - LOWORD(parent->xOffset);
    yRelParent = evt->yCoord - LOWORD(parent->yOffset);
    if ( xRelParent < thisa->offsetX
      || yRelParent < thisa->offsetY
      || thisa->offsetX + thisa->width <= xRelParent
      || thisa->offsetY + thisa->height <= yRelParent )
    {
      result = 0;
    }
    else
    {
      if ( evtCode == INPUT_RIGHT_CLICK )
      {
        evt->inputTypeBitmask = INPUT_GUI_MESSAGE_CODE;
        evt->xCoordOrKeycode = 14;
      }
      else
      {
        LOBYTE(v3) = v3 | 1;
        thisa->field_16 = v3;
        evt->xCoordOrKeycode = 12;
      }
      evt->eventCode = INPUT_GUI_MESSAGE_CODE;
      evt->yCoord = thisa->fieldID;
      result = 2;
    }
    return result;
  }
  if ( evtCode == INPUT_RIGHT_UP_EVENT_CODE )
  {
LABEL_23:
    if ( v3 & 1 )
    {
      LOBYTE(v3) = v3 & 0xFE;
      thisa->field_16 = v3;
      evt->xCoordOrKeycode = GUI_MESSAGE_BUTTON_PRESSED;
      evt->eventCode = INPUT_GUI_MESSAGE_CODE;
      evt->yCoord = thisa->fieldID;
      result = 2;
    }
    else
    {
      result = 0;
    }
    return result;
  }
  if ( evtCode != INPUT_GUI_MESSAGE_CODE )
    return widget::Main((widget *)thisa, (Event *)evt);
  switch ( evt->xCoordOrKeycode )
  {
    default:
      return widget::Main((widget *)thisa, (Event *)evt);
    case GUI_MESSAGE_SET_IMG_IDX:
      if ( thisa->fieldID != evt->yCoord )
        return widget::Main((widget *)thisa, (Event *)evt);
      thisa->imgIdx = (__int16)evt->payload;
      return 1;
    case 8:
      if ( thisa->fieldID != evt->yCoord )
        return widget::Main((widget *)thisa, (Event *)evt);
      thisa->field_27 = (unsigned int)evt->payload & 0xFF;
      return 1;
    case GUI_MESSAGE_SET_ICON:
      if ( thisa->fieldID != evt->yCoord )
        return widget::Main((widget *)thisa, (Event *)evt);
      if ( thisa->icon )
      {
        resourceManager::Dispose(gpResourceManager, (resource *)thisa->icon);
        thisa->icon = resourceManager::GetIcon(gpResourceManager, (const char *)evt->payload);
      }
      result = 1;
      break;
    case GUI_MESSAGE_REPLACE_ICON:
      if ( evt->yCoord == thisa->iconFileID )
      {
        v9 = (resource *)thisa->icon;
        thisa->iconFileID = (int)evt->payload;
        resourceManager::Dispose(gpResourceManager, v9);
        thisa->icon = resourceManager::GetIcon(gpResourceManager, (int)evt->payload);
      }
      result = 0;
      break;
  }
  return result;
}