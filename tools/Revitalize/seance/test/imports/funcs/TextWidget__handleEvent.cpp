{
  __int16 v2; // dx@1
  TextWidget *thisa; // ebx@1
  INPUT_EVENT_CODE code; // eax@1
  signed int result; // eax@3
  __int16 v6; // bp@13
  GUIWindow *v7; // edi@13
  __int16 v8; // ax@13
  __int16 v9; // si@13
  int v10; // eax@26
  __int16 v11; // ax@30
  void *msg; // esi@30
  unsigned int contentsLen; // ebp@33

  v2 = this->field_16;
  thisa = this;
  code = evt->eventCode;
  if ( !(v2 & 2) )
  {
    if ( code == 512 )
      result = AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
    else
      result = 0;
    return result;
  }
  if ( (signed int)code <= 16 )
  {
    if ( code != 16 )
    {
      if ( code != 8 )
        return AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
      goto LABEL_13;
    }
LABEL_21:
    if ( v2 & 1 )
    {
      LOBYTE(v2) = v2 & 0xFE;
      this->field_16 = v2;
      if ( evt->eventCode == INPUT_RIGHT_UP_EVENT_CODE )
        evt->inputTypeBitmask = 512;
      evt->eventCode = 512;
      evt->xCoordOrKeycode = 13;
      evt->yCoord = this->fieldID;
      result = 2;
    }
    else
    {
      result = 0;
    }
    return result;
  }
  if ( code == 32 )
  {
LABEL_13:
    v6 = this->offsetX;
    v7 = this->parentWindow;
    v8 = evt->xCoordOrKeycode - LOWORD(v7->xOffset);
    v9 = evt->yCoord - LOWORD(v7->yOffset);
    if ( v6 > v8 || this->offsetY > v9 || v6 + this->width <= v8 || this->offsetY + this->height <= v9 )
    {
      result = 0;
    }
    else
    {
      LOBYTE(v2) = v2 | 1;
      this->field_16 = v2;
      if ( evt->eventCode == 32 )
        evt->inputTypeBitmask = 512;
      evt->eventCode = 512;
      evt->xCoordOrKeycode = 12;
      evt->yCoord = this->fieldID;
      result = 2;
    }
    return result;
  }
  if ( code == INPUT_RIGHT_UP_EVENT_CODE )
    goto LABEL_21;
  if ( code != 512 )
    return AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
  v10 = evt->xCoordOrKeycode;
  if ( v10 != 3 )
  {
    if ( v10 == 8 && this->fieldID == evt->yCoord )
    {
      this->field_28 = (__int16)evt->payload;
      return 1;
    }
    return AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
  }
  if ( this->fieldID != evt->yCoord )
    return AbstractGUIComponent::handleEvent((AbstractGUIComponent *)this, (Event *)evt);
  v11 = this->field_14;
  msg = evt->payload;
  if ( v11 == 512 || v11 == 16384 )
  {
    contentsLen = (unsigned __int16)strlen((const char *)evt->payload);
    if ( strlen(thisa->content) < contentsLen )
    {
      KBFree(thisa->content, (int)"F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 211);
      thisa->content = (char *)KBAlloc(contentsLen + 5, "F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 212);
    }
    strcpy(thisa->content, (const char *)msg);
    result = 1;
  }
  else
  {
    result = 1;
    this->content = (char *)msg;
  }
  return result;
}
