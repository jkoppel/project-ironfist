{
  int v1; // eax@13
  int v2; // [sp+Ch] [bp-5Ch]@1
  int v3; // [sp+20h] [bp-48h]@7
  char a1; // [sp+44h] [bp-24h]@1
  char v5; // [sp+54h] [bp-14h]@3
  baseManager *a2; // [sp+64h] [bp-4h]@8

  v2 = (int)this;
  strcpy(&a1, gMapName);
  strcpy(gcCurMapName, byte_5110D4);
  if ( gbRemoteOn && xNetHasOldPlayers )
  {
    NormalDialog(
      "At least one player does not have the Heroes II Expansion set.  You will only be able to choose from original Heroes II games.",
      1,
      -1,
      -1,
      -1,
      0,
      -1,
      0,
      -1,
      0);
    sprintf(&v5, "*.%s", "MP2");
  }
  else if ( xIsExpansionMap )
  {
    sprintf(&v5, "*.%s", "MX2");
  }
  else
  {
    sprintf(&v5, "*.%s", "MP2");
  }
  v3 = (int)operator new(1071);
  if ( v3 )
    a2 = (baseManager *)fileRequester::fileRequester(v3, 212, 9, 1, &v5, ".\\MAPS\\", &v5);
  else
    a2 = 0;
  if ( !a2 )
    MemError();
  if ( executive::DoDialog(gpExec, a2) == 30722 )
  {
    operator delete(a2);
    strcpy(gMapName, gLastFilename);
    LOBYTE(v1) = stricmp(&a1, gMapName);
    if ( v1 )
    {
      strcpy((char *)(v2 + 1126), gMapName);
      game::ProcessNewMap(v2, 0);
    }
  }
  else
  {
    operator delete(a2);
    strcpy(gMapName, &a1);
  }
}