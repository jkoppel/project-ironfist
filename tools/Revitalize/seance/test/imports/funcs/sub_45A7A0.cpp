{
  int v1; // [sp+Ch] [bp-5Ch]@1
  int v2; // [sp+20h] [bp-48h]@7
  char v3; // [sp+44h] [bp-24h]@1
  char v4; // [sp+54h] [bp-14h]@3
  AbstractManager *a2; // [sp+64h] [bp-4h]@8

  v1 = (int)this;
  strcpy(&v3, byte_524740);
  strcpy(byte_522FE8, byte_5110D4);
  if ( dword_4F7494 && byte_51AC64 )
  {
    display_message_window(
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
    sprintf(&v4, "*.%s", "MP2");
  }
  else
  {
    if ( inExpansion )
      sprintf(&v4, "*.%s", "MX2");
    else
      sprintf(&v4, "*.%s", "MP2");
  }
  v2 = (int)operator new(0x42Fu);
  if ( v2 )
    a2 = (AbstractManager *)FileRequester_constructor(v2, 212, 9, 1, &v4, ".\\MAPS\\", &v4);
  else
    a2 = 0;
  if ( !a2 )
    fatalOutOfMemoryError();
  if ( ManagerManager::weirdAddAndRemoveManagerThing(managerManager, a2) == 30722 )
  {
    operator delete(a2);
    strcpy(byte_524740, byte_5240B0);
    if ( _strcmpi(&v3, byte_524740) )
    {
      strcpy((char *)(v1 + 1126), byte_524740);
      sub_45A980(v1, 0);
    }
  }
  else
  {
    operator delete(a2);
    strcpy(byte_524740, &v3);
  }
}
