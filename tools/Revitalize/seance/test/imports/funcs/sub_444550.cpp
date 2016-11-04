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
    a3 = dword_523EDC;
  v5 = 0;
  if ( *(_DWORD *)&evilInterfaceUsage != 2 || useEvilBorders )
  {
    if ( *(_DWORD *)&evilInterfaceUsage == 1 && useEvilBorders )
    {
      v5 = 1;
    }
    else
    {
      if ( !*(_DWORD *)&evilInterfaceUsage && gameObject->players[a3]._4[0] != useEvilBorders )
        v5 = 1;
    }
  }
  else
  {
    v5 = 1;
  }
  if ( v5 )
  {
    useEvilBorders = 1 - useEvilBorders;
    if ( a2 )
    {
      evt = 512;
      v7 = 60;
      for ( i = 0; i < 37; ++i )
      {
        v8 = ResourceManager::setResource(resourceManager, goodEvilIcons[i][1 - useEvilBorders], 0);
        v9 = ResourceManager::setResource(resourceManager, goodEvilIcons[i][useEvilBorders], 0);
        GUIWindow::processMessage(*(GUIWindow **)((char *)v4 + 154), (Event *)&evt);
      }
      v3 = dword_524C14;
      dword_524C14 = 1;
      sub_4506B0(v4, 1, 1);
      dword_524C14 = v3;
    }
  }
}
