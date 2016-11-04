{
  INPUT_EVENT_CODE v3; // [sp+Ch] [bp-50h]@3
  InputEvent a2a; // [sp+20h] [bp-3Ch]@3
  char v5; // [sp+3Ch] [bp-20h]@1
  char v6; // [sp+40h] [bp-1Ch]@1
  GUIWindow *window; // [sp+44h] [bp-18h]@1
  int v8; // [sp+48h] [bp-14h]@1
  char v9; // [sp+4Ch] [bp-10h]@1
  char v10; // [sp+50h] [bp-Ch]@1
  char v11; // [sp+54h] [bp-8h]@1
  char v12; // [sp+58h] [bp-4h]@1

  sub_438610(
    0,
    0,
    1,
    640,
    480,
    48 * a1,
    48 * a2,
    (int *)&v10,
    (int *)&v6,
    (int)&v11,
    (int)&v9,
    (int)&v5,
    (int)&v12,
    (int *)&window,
    0);
  HeroWindowManager::addWindow(HeroWindowManager::instance, window, -1, 1);
  v8 = 0;
  InputManager::resetInfoFields(inputManager);
  while ( !v8 )
  {
    passOnMessages();
    v3 = InputManager::nextInputEvent(inputManager, &a2a)->eventCode;
    if ( v3 == 1 || v3 == 8 || v3 == 32 )
      v8 = 1;
  }
  HeroWindowManager::removeWindow(HeroWindowManager::instance, window);
  return operator delete(window);
}
