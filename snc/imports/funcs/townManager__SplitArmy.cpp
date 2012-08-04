{
  heroWindowManager *result; // eax@9
  void *v2; // [sp+14h] [bp-38h]@1
  heroWindow *thisa; // [sp+20h] [bp-2Ch]@1
  signed int v4; // [sp+24h] [bp-28h]@10
  int evt; // [sp+28h] [bp-24h]@6
  int v6; // [sp+2Ch] [bp-20h]@9
  int v7; // [sp+30h] [bp-1Ch]@9
  char *v8; // [sp+40h] [bp-Ch]@9
  __int16 v9; // [sp+44h] [bp-8h]@1
  __int16 v10; // [sp+48h] [bp-4h]@1

  v2 = this;
  v10 = 1;
  v9 = 4;
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    *(_DWORD *)((char *)v2 + 358) = heroWindow::heroWindow(thisa, 177, 20, "splitwin.bin");
  else
    *(_DWORD *)((char *)v2 + 358) = 0;
  if ( !*(_DWORD *)((char *)v2 + 358) )
    MemError();
  *(_DWORD *)((char *)v2 + 362) = 0;
  *(_DWORD *)((char *)v2 + 366) = *(_WORD *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128)
                                           + 2 * *(_DWORD *)((char *)v2 + 226)
                                           + 5);
  evt = 512;
  if ( *(_DWORD *)(*(_DWORD *)((char *)v2 + 230) + 128) == *(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128) )
    sprintf(gText, "Move how many troops?");
  else
    sprintf(
      gText,
      "Move how many %s troops from %s to %s?",
      gArmyNames[*(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128) + *(_DWORD *)((char *)v2 + 226))],
      &aHeroSArmy_0[("Garrison" - "Hero's Army") & ((*(_DWORD *)((char *)v2 + 222) == *(_DWORD *)((char *)v2 + 210)) - 1)],
      &aHeroSArmy[("Garrison" - "Hero's Army") & ((*(_DWORD *)((char *)v2 + 230) == *(_DWORD *)((char *)v2 + 210)) - 1)]);
  v6 = 3;
  v7 = 1;
  v8 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v2 + 358), (Event *)&evt);
  sprintf(gText, "%d", *(_DWORD *)((char *)v2 + 362));
  v7 = 4;
  v8 = gText;
  heroWindow::BroadcastMessage(*(heroWindow **)((char *)v2 + 358), (Event *)&evt);
  heroWindowManager::DoDialog(
    gpWindowManager,
    *(heroWindow **)((char *)v2 + 358),
    (int (__fastcall *)(tag_message *))SplitArmyHandler,
    0);
  operator delete(*(void **)((char *)v2 + 358));
  result = gpWindowManager;
  if ( gpWindowManager->buttonPressedCode == 30722 )
  {
    v4 = 0;
    if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128) + *(_DWORD *)((char *)v2 + 226)) == *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 230) + 128) + *(_DWORD *)((char *)v2 + 234)) )
      v4 = 1;
    if ( v4 )
    {
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 230) + 128) + 2 * *(_DWORD *)((char *)v2 + 234) + 5) += *((_WORD *)v2 + 181);
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 230) + 128) + *(_DWORD *)((char *)v2 + 234)) = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128) + *(_DWORD *)((char *)v2 + 226));
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 230) + 128) + 2 * *(_DWORD *)((char *)v2 + 234) + 5) = *(_DWORD *)((char *)v2 + 362);
    }
    result = (heroWindowManager *)(*(_WORD *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128)
                                            + 2 * *(_DWORD *)((char *)v2 + 226)
                                            + 5)
                                 - *(_DWORD *)((char *)v2 + 362));
    *(_WORD *)(*(_DWORD *)(*(_DWORD *)((char *)v2 + 222) + 128) + 2 * *(_DWORD *)((char *)v2 + 226) + 5) = (_WORD)result;
  }
  return result;
}