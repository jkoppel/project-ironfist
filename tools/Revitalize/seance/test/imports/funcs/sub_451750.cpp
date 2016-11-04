{
  int v1; // [sp+14h] [bp-30h]@14
  char v2; // [sp+18h] [bp-2Ch]@8
  int v3; // [sp+20h] [bp-24h]@1
  int v4; // [sp+24h] [bp-20h]@19
  char v5; // [sp+28h] [bp-1Ch]@8
  int i; // [sp+38h] [bp-Ch]@1
  int v7; // [sp+3Ch] [bp-8h]@1
  AbstractManager *a2; // [sp+40h] [bp-4h]@15

  v3 = 0;
  v7 = 0;
  sub_4561E0((int)advManager);
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  for ( i = 0; i < 6; ++i )
  {
    if ( !gameObject->couldBePlayerAlive[i] )
    {
      if ( dword_524810[i] )
        ++v7;
    }
  }
  if ( loadOrNewGameSelected )
  {
    sprintf(&v2, ".GMC");
    sprintf(&v5, "*.GMC");
  }
  else
  {
    if ( byte_5304A0 )
    {
      sprintf(&v2, ".GXC");
      sprintf(&v5, "*.GXC");
    }
    else
    {
      if ( inExpansion )
      {
        sprintf(&v2, ".GX%d", v7);
        sprintf(&v5, "*.GX%d", v7);
      }
      else
      {
        sprintf(&v2, ".GM%d", v7);
        sprintf(&v5, "*.GM%d", v7);
      }
    }
  }
  v1 = (int)operator new(0x42Fu);
  if ( v1 )
    a2 = (AbstractManager *)FileRequester_constructor(v1, 131, 58, 3, &v5, ".\\GAMES\\", &v2);
  else
    a2 = 0;
  if ( !a2 )
    fatalOutOfMemoryError();
  v4 = ManagerManager::weirdAddAndRemoveManagerThing(managerManager, a2);
  if ( v4 == 30722 )
  {
    v3 = 1;
    dword_5235D8 = 1;
    v3 = GameInfo::saveGame(gameObject, byte_5240B0, 0, 0);
    if ( v3 )
      display_message_window("Game saved successfully.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  operator delete(a2);
  sub_4562C0((int)advManager);
  return v3;
}
