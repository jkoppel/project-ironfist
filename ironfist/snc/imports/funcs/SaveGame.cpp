{
  int v1; // [sp+14h] [bp-30h]@14
  char v2; // [sp+18h] [bp-2Ch]@8
  int v3; // [sp+20h] [bp-24h]@1
  int v4; // [sp+24h] [bp-20h]@19
  char v5; // [sp+28h] [bp-1Ch]@8
  int i; // [sp+38h] [bp-Ch]@1
  int v7; // [sp+3Ch] [bp-8h]@1
  baseManager *a2; // [sp+40h] [bp-4h]@15

  v3 = 0;
  v7 = 0;
  advManager::DisableButtons(gpAdvManager);
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  for ( i = 0; i < 6; ++i )
  {
    if ( !gpGame->couldBePlayerAlive[i] )
    {
      if ( gbHumanPlayer[i] )
        ++v7;
    }
  }
  if ( gbInCampaign )
  {
    sprintf(&v2, ".GMC");
    sprintf(&v5, "*.GMC");
  }
  else if ( xIsPlayingExpansionCampaign )
  {
    sprintf(&v2, ".GXC");
    sprintf(&v5, "*.GXC");
  }
  else if ( xIsExpansionMap )
  {
    sprintf(&v2, ".GX%d", v7);
    sprintf(&v5, "*.GX%d", v7);
  }
  else
  {
    sprintf(&v2, ".GM%d", v7);
    sprintf(&v5, "*.GM%d", v7);
  }
  v1 = (int)operator new(1071);
  if ( v1 )
    a2 = (baseManager *)fileRequester::fileRequester(v1, 131, 58, 3, &v5, ".\\GAMES\\", &v2);
  else
    a2 = 0;
  if ( !a2 )
    MemError();
  v4 = executive::DoDialog(gpExec, a2);
  if ( v4 == 30722 )
  {
    v3 = 1;
    bFreshSave = 1;
    v3 = game::SaveGame(gpGame, gLastFilename, 0, 0);
    if ( v3 )
      NormalDialog("Game saved successfully.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  operator delete(a2);
  advManager::EnableButtons(gpAdvManager);
  return v3;
}