{
  int v3; // ST18_4@17
  void *v4; // [sp+Ch] [bp-2Ch]@1
  signed int v5; // [sp+14h] [bp-24h]@3
  int evt; // [sp+18h] [bp-20h]@14
  int v7; // [sp+1Ch] [bp-1Ch]@14
  unsigned int v8; // [sp+20h] [bp-18h]@16
  unsigned int v9; // [sp+30h] [bp-8h]@16
  int i; // [sp+34h] [bp-4h]@14

  v4 = this;
  if ( a3 == -1 )
    a3 = giCurWatchPlayer;
  v5 = 0;
  if ( *(_DWORD *)&evilInterfaceUsage != 2 || gbUseEvilInterface )
  {
    if ( *(_DWORD *)&evilInterfaceUsage == 1 && gbUseEvilInterface )
    {
      v5 = 1;
    }
    else if ( !*(_DWORD *)&evilInterfaceUsage && gpGame->players[a3]._4[0] != gbUseEvilInterface )
    {
      v5 = 1;
    }
  }
  else
  {
    v5 = 1;
  }
  if ( v5 )
  {
    gbUseEvilInterface = 1 - gbUseEvilInterface;
    if ( a2 )
    {
      evt = 512;
      v7 = 60;
      for ( i = 0; i < 37; ++i )
      {
        v8 = resourceManager::MakeId(gpResourceManager, cEvilTranslate[i][1 - gbUseEvilInterface], 0);
        v9 = resourceManager::MakeId(gpResourceManager, cEvilTranslate[i][gbUseEvilInterface], 0);
        heroWindow::BroadcastMessage(*(heroWindow **)((char *)v4 + 154), (Event *)&evt);
      }
      v3 = bShowIt;
      bShowIt = 1;
      advManager::RedrawAdvScreen(v4, 1, 1);
      bShowIt = v3;
    }
  }
}