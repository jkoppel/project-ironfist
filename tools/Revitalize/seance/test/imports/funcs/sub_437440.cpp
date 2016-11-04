{
  const void *result; // eax@1
  char a2[28]; // [sp+Ch] [bp-40h]@3
  int v2; // [sp+28h] [bp-24h]@3
  int v3; // [sp+44h] [bp-8h]@1
  int v4; // [sp+48h] [bp-4h]@1

  v4 = 0;
  v3 = 0;
  result = (const void *)InputManager::resetInfoFields(inputManager);
  while ( !v3 )
  {
    yieldToGlobalUpdater();
    passOnMessages();
    result = InputManager::nextInputEvent(inputManager, (InputEvent *)a2);
    memcpy(&v2, result, 28u);
    if ( v2 == 1 || v2 == 8 || v2 == 16 || v2 == 32 || v2 == 64 )
      v3 = 1;
  }
  return result;
}
