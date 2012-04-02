void __cdecl waitForMouseRelease()
{
  InputEvent a2; // [sp+Ch] [bp-3Ch]@3
  InputEvent evt; // [sp+28h] [bp-20h]@3
  bool i; // [sp+44h] [bp-4h]@1

  sub_4CE9D0(mouseManager);
  for ( i = 0;
        !i;
        i = evt.eventCode == INPUT_RIGHT_UP_EVENT_CODE
         || evt.eventCode == INPUT_LEFT_CLICK_EVENT_CODE
         || evt.eventCode == INPUT_LEFT_UP_EVENT_CODE )
  {
    yieldToGlobalUpdater();
    passOnMessages();
    memcpy(&evt, InputManager::nextInputEvent(inputManager, &a2), sizeof(evt));
  }
  sub_4CEA00(mouseManager);
}
