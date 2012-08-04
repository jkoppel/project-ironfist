{
  button *thisa; // ebx@1
  __int16 v3; // ax@4
  signed __int16 result; // ax@5
  __int16 v5; // cx@7
  __int16 v6; // ax@7
  INPUT_EVENT_CODE code; // edi@11
  __int16 v8; // ax@23
  __int16 v9; // ax@30
  heroWindow *v10; // eax@37
  __int16 v11; // si@37
  __int16 v12; // dx@37
  __int16 v13; // cx@38
  __int16 v14; // ax@39
  int v15; // eax@42
  __int16 v16; // cx@45
  __int16 v17; // ax@46
  __int16 v18; // di@52
  heroWindow *v19; // ecx@52
  __int16 v20; // ax@52
  int v21; // edx@52
  __int16 v22; // cx@53
  __int16 v23; // cx@58
  __int16 v24; // cx@61
  icon *buttonIcon; // ST10_4@70
  tag_message a2; // [sp+Ch] [bp-20h]@60

  thisa = this;
  if ( this->field_14 == 4096 && this->flags & 1 && KBTickCount() > dword_524BF0 )
  {
    v3 = LOWORD(thisa->flags);
    if ( v3 & 1 )
    {
      LOBYTE(v3) = v3 & 0xFE;
      LOWORD(thisa->flags) = v3;
      thisa->vtable->paint((widget *)thisa);
      heroWindowManager::UpdateScreenRegion(
        gpWindowManager,
        HIWORD(thisa->flags) + thisa->parentWindow->xOffset,
        thisa->offsetY + thisa->parentWindow->yOffset,
        thisa->width,
        thisa->height);
      e->xCoordOrKeycode = 13;
      e->eventCode = 512;
      e->yCoord = thisa->fieldID;
      e->inputTypeBitmask = iLeftRightSave;
      result = 2;
      iLeftRightSave = 0;
    }
    else
    {
      result = 0;
    }
    return result;
  }
  v5 = LOWORD(thisa->flags);
  v6 = thisa->flags & 2;
  if ( !(thisa->flags & 2) )
  {
    if ( e->eventCode == 512 )
      result = widget::Main((widget *)thisa, (Event *)e);
    else
      result = 0;
    return result;
  }
  code = e->eventCode;
  if ( e->eventCode > INPUT_LEFT_CLICK_EVENT_CODE )
  {
    if ( code == INPUT_LEFT_UP_EVENT_CODE )
    {
      if ( v5 & 4 && v5 & 1 )
      {
        LOBYTE(v5) = v5 & 0xFE;
        LOWORD(thisa->flags) = v5;
        thisa->vtable->paint((widget *)thisa);
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          thisa->parentWindow->xOffset + HIWORD(thisa->flags),
          thisa->parentWindow->yOffset + thisa->offsetY,
          thisa->width,
          thisa->height);
        e->xCoordOrKeycode = 13;
        e->eventCode = 512;
        e->yCoord = thisa->fieldID;
        e->inputTypeBitmask = iLeftRightSave;
        result = 2;
        iLeftRightSave = 0;
        return result;
      }
      return widget::Main((widget *)thisa, (Event *)e);
    }
    if ( code != 32 )
    {
      if ( code != 512 || e->xCoordOrKeycode != 60 )
        return widget::Main((widget *)thisa, (Event *)e);
      if ( e->yCoord == thisa->icnFileID )
      {
        buttonIcon = thisa->icon;
        thisa->icnFileID = (int)e->payload;
        resourceManager::Dispose(gpResourceManager, (resource *)buttonIcon);
        thisa->icon = resourceManager::GetIcon(gpResourceManager, (int)e->payload);
      }
      return 0;
    }
    goto LABEL_36;
  }
  if ( e->eventCode == INPUT_LEFT_CLICK_EVENT_CODE )
  {
LABEL_36:
    if ( !(v5 & 4) )
      return widget::Main((widget *)thisa, (Event *)e);
    v10 = thisa->parentWindow;
    v11 = e->xCoordOrKeycode - LOWORD(v10->xOffset);
    v12 = e->yCoord - LOWORD(v10->yOffset);
    if ( code == INPUT_RIGHT_CLICK )
    {
      v13 = HIWORD(thisa->flags);
      if ( v11 < v13 || (v14 = thisa->offsetY, v12 < v14) || v13 + thisa->width <= v11 || v14 + thisa->height <= v12 )
      {
        result = 0;
      }
      else
      {
        e->xCoordOrKeycode = 14;
        e->eventCode = 512;
        v15 = thisa->fieldID;
        e->inputTypeBitmask = 512;
        e->yCoord = v15;
        result = 2;
      }
    }
    else if ( v5 & 8
  || (v16 = HIWORD(thisa->flags), v11 < v16)
  || (v17 = thisa->offsetY, v12 < v17)
  || v16 + thisa->width <= v11
  || v17 + thisa->height <= v12 )
    {
      result = 0;
    }
    else
    {
      button::Select(thisa, e);
      while ( e->eventCode != 16 )
      {
        if ( e->eventCode == 64 )
          break;
        PollSound();
        (*(void (__thiscall **)(mouseManager *))(LODWORD(gpMouseManager->vtable) + 8))(gpMouseManager);
        if ( e->eventCode == 4 )
        {
          v18 = HIWORD(thisa->flags);
          v19 = thisa->parentWindow;
          v21 = e->yCoord;
          v20 = e->xCoordOrKeycode - LOWORD(v19->xOffset);
          LOWORD(v21) = v21 - LOWORD(v19->yOffset);
          if ( v20 < v18
            || (v22 = thisa->offsetY, (signed __int16)v21 < v22)
            || v18 + thisa->width <= v20
            || v22 + thisa->height <= (signed __int16)v21 )
          {
            v23 = LOWORD(thisa->flags);
            if ( thisa->flags & 1 )
            {
              LOBYTE(v23) = v23 & 0xFE;
              LOWORD(thisa->flags) = v23;
              ((void (__fastcall *)(button *, int))thisa->vtable->paint)(thisa, v21);
              heroWindowManager::UpdateScreenRegion(
                gpWindowManager,
                HIWORD(thisa->flags) + thisa->parentWindow->xOffset,
                thisa->offsetY + thisa->parentWindow->yOffset,
                thisa->width,
                thisa->height);
              e->xCoordOrKeycode = 13;
              e->eventCode = 512;
              e->yCoord = thisa->fieldID;
              e->inputTypeBitmask = iLeftRightSave;
              iLeftRightSave = 0;
            }
          }
          else if ( !(thisa->flags & 1) )
          {
            button::Select(thisa, e);
          }
        }
        Process1WindowsMessage();
        memcpy(e, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
      }
      v24 = LOWORD(thisa->flags);
      if ( thisa->flags & BUTTON_IS_ARMED )
      {
        LOBYTE(v24) = v24 & 0xFE;
        LOWORD(thisa->flags) = v24;
        thisa->vtable->paint((widget *)thisa);
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          HIWORD(thisa->flags) + thisa->parentWindow->xOffset,
          thisa->offsetY + thisa->parentWindow->yOffset,
          thisa->width,
          thisa->height);
        e->xCoordOrKeycode = 13;
        result = 2;
        e->eventCode = 512;
        e->yCoord = thisa->fieldID;
        e->inputTypeBitmask = iLeftRightSave;
        iLeftRightSave = 0;
      }
      else
      {
        result = 1;
      }
    }
    return result;
  }
  if ( code != 1 )
  {
    if ( code == INPUT_KEYUP_EVENT_CODE && v6 && v5 & 4 && !(v5 & 8) )
    {
      v9 = thisa->field_2A;
      if ( v9 == -1 || v9 != e->xCoordOrKeycode )
      {
        result = 0;
      }
      else if ( v5 & 1 )
      {
        LOBYTE(v5) = v5 & 0xFE;
        LOWORD(thisa->flags) = v5;
        thisa->vtable->paint((widget *)thisa);
        heroWindowManager::UpdateScreenRegion(
          gpWindowManager,
          HIWORD(thisa->flags) + thisa->parentWindow->xOffset,
          thisa->offsetY + thisa->parentWindow->yOffset,
          thisa->width,
          thisa->height);
        e->xCoordOrKeycode = 13;
        result = 2;
        e->eventCode = 512;
        e->yCoord = thisa->fieldID;
        e->inputTypeBitmask = iLeftRightSave;
        iLeftRightSave = 0;
      }
      else
      {
        result = 0;
      }
      return result;
    }
    return widget::Main((widget *)thisa, (Event *)e);
  }
  if ( !v6 || !(v5 & 4) || v5 & 8 )
    return widget::Main((widget *)thisa, (Event *)e);
  v8 = thisa->field_2A;
  if ( v8 == -1 || v8 != e->xCoordOrKeycode )
    result = 0;
  else
    result = button::Select(thisa, e);
  return result;
}