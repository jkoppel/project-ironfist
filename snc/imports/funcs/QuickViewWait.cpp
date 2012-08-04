{
  tag_message a2; // [sp+Ch] [bp-3Ch]@3
  tag_message evt; // [sp+28h] [bp-20h]@3
  bool i; // [sp+44h] [bp-4h]@1

  mouseManager::ReallyHidePointer(gpMouseManager);
  for ( i = 0;
        !i;
        i = evt.eventCode == INPUT_RIGHT_UP_EVENT_CODE
         || evt.eventCode == INPUT_LEFT_CLICK_EVENT_CODE
         || evt.eventCode == INPUT_LEFT_UP_EVENT_CODE )
  {
    PollSound();
    Process1WindowsMessage();
    memcpy(&evt, inputManager::GetEvent(gpInputManager, &a2), sizeof(evt));
  }
  mouseManager::ReallyShowPointer(gpMouseManager);
}