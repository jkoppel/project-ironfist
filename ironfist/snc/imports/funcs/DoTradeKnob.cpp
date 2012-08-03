{
  char v7; // [sp+Ch] [bp-90h]@12
  char v8; // [sp+28h] [bp-74h]@12
  char v9; // [sp+44h] [bp-58h]@10
  tag_message a2a; // [sp+60h] [bp-3Ch]@9
  int v11; // [sp+7Ch] [bp-20h]@10
  int v12; // [sp+98h] [bp-4h]@4

  while ( a1 != 16 && a1 != 64 )
  {
    if ( a1 == 4 )
    {
      v12 = a5 - tpX - 75;
      qtyToTrade = v12 * (iMaxUnitsToTrade + 1) / 187;
      if ( qtyToTrade < 0 )
        qtyToTrade = 0;
      if ( iMaxUnitsToTrade < qtyToTrade )
        qtyToTrade = iMaxUnitsToTrade;
      (*(void (__fastcall **)(mouseManager *, int))(LODWORD(gpMouseManager->vtable) + 8))(
        gpMouseManager,
        v12 * (iMaxUnitsToTrade + 1) % 187);
      UpdateTradingPost((void *)1);
    }
    Process1WindowsMessage();
    memcpy(&a1, inputManager::GetEvent(gpInputManager, &a2a), 0x1Cu);
    if ( a1 == 4 )
    {
      memcpy(&v11, inputManager::PeekEvent(gpInputManager, &v9), 0x1Cu);
      while ( v11 == 4 )
      {
        memcpy(&a1, inputManager::GetEvent(gpInputManager, (tag_message *)&v8), 0x1Cu);
        memcpy(&v11, inputManager::PeekEvent(gpInputManager, &v7), 0x1Cu);
      }
    }
  }
  UpdateTradingPost((void *)1);
}