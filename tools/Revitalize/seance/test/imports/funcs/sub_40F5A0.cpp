{
  char v7; // [sp+Ch] [bp-90h]@12
  char v8; // [sp+28h] [bp-74h]@12
  char v9; // [sp+44h] [bp-58h]@10
  InputEvent a2a; // [sp+60h] [bp-3Ch]@9
  int v11; // [sp+7Ch] [bp-20h]@10
  int v12; // [sp+98h] [bp-4h]@4

  while ( a1 != 16 && a1 != 64 )
  {
    if ( a1 == 4 )
    {
      v12 = a5 - dword_522C08 - 75;
      dword_522C14 = v12 * (dword_522C04 + 1) / 187;
      if ( dword_522C14 < 0 )
        dword_522C14 = 0;
      if ( dword_522C04 < dword_522C14 )
        dword_522C14 = dword_522C04;
      (*(void (__fastcall **)(MouseManager *, int))(LODWORD(mouseManager->vtable) + 8))(
        mouseManager,
        v12 * (dword_522C04 + 1) % 187);
      market_related((void *)1);
    }
    passOnMessages();
    memcpy(&a1, InputManager::nextInputEvent(inputManager, &a2a), 0x1Cu);
    if ( a1 == 4 )
    {
      memcpy(&v11, InputManager::lastInputEvent(inputManager, &v9), 0x1Cu);
      while ( v11 == 4 )
      {
        memcpy(&a1, InputManager::nextInputEvent(inputManager, (InputEvent *)&v8), 0x1Cu);
        memcpy(&v11, InputManager::lastInputEvent(inputManager, &v7), 0x1Cu);
      }
    }
  }
  market_related((void *)1);
}
