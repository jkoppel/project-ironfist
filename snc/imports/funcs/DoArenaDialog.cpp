{
  __int16 imgIdx; // [sp+10h] [bp-80h]@10
  textWidget *v2; // [sp+18h] [bp-78h]@16
  iconWidget *v3; // [sp+1Ch] [bp-74h]@8
  heroWindow *this; // [sp+20h] [bp-70h]@1
  int evt; // [sp+30h] [bp-60h]@6
  int v6; // [sp+34h] [bp-5Ch]@6
  int v7; // [sp+38h] [bp-58h]@6
  char *v8; // [sp+48h] [bp-48h]@6
  int xOff; // [sp+4Ch] [bp-44h]@1
  int v10; // [sp+50h] [bp-40h]@1
  int v11; // [sp+5Ch] [bp-34h]@1
  int i; // [sp+64h] [bp-2Ch]@6
  int v13; // [sp+68h] [bp-28h]@6
  int v14; // [sp+6Ch] [bp-24h]@6
  int v15; // [sp+70h] [bp-20h]@1
  char filename; // [sp+74h] [bp-1Ch]@1
  int guiObj[3]; // [sp+84h] [bp-Ch]@17

  v15 = 5;
  v11 = 306;
  v10 = 405;
  xOff = 159;
  choice = 0;
  sprintf(&filename, "evntwin%d.bin", 5);
  this = (heroWindow *)operator new(68);
  if ( this )
    arenaWinPtr = heroWindow::heroWindow(this, xOff, 28, &filename);
  else
    arenaWinPtr = 0;
  if ( !arenaWinPtr )
    MemError();
  strcpy(
    gText,
    "You enter the arena and face a pack of vicious lions.  You handily defeat them, to the wild cheers of the crowd.  Impressed by your skill, the aged trainer of gladiators agrees to train you in a skill of your choice.");
  v13 = font::LineLength(bigFont, gText, 244);
  v14 = 16 * v13;
  evt = 512;
  v6 = 3;
  v7 = 1;
  v8 = gText;
  heroWindow::BroadcastMessage(arenaWinPtr, (Event *)&evt);
  for ( i = 0; i < 3; ++i )
  {
    v3 = (iconWidget *)operator new(45);
    if ( v3 )
    {
      if ( choice == i )
        imgIdx = i + 4;
      else
        imgIdx = i;
      skillWidget[i] = (int)iconWidget::iconWidget(
                              v3,
                              60 * i + 84,
                              244,
                              39,
                              34,
                              "xprimary.icn",
                              imgIdx,
                              0,
                              i + 100,
                              16,
                              1);
    }
    else
    {
      skillWidget[i] = 0;
    }
    if ( !skillWidget[i] )
      MemError();
    v2 = (textWidget *)operator new(43);
    if ( v2 )
      guiObj[i] = (int)textWidget::textWidget(
                         v2,
                         60 * i + 79,
                         282,
                         49,
                         24,
                         gStatNames[i],
                         "smalfont.fnt",
                         1,
                         -1,
                         512,
                         1);
    else
      guiObj[i] = 0;
    if ( !guiObj[i] )
      MemError();
    heroWindow::AddWidget(arenaWinPtr, (widget *)skillWidget[i], -1);
    heroWindow::AddWidget(arenaWinPtr, (widget *)guiObj[i], -1);
  }
  evt = 512;
  v6 = 6;
  v8 = (char *)6;
  v7 = 30727;
  heroWindow::BroadcastMessage(arenaWinPtr, (Event *)&evt);
  v7 = 30728;
  heroWindow::BroadcastMessage(arenaWinPtr, (Event *)&evt);
  v7 = 30721;
  heroWindow::BroadcastMessage(arenaWinPtr, (Event *)&evt);
  v7 = 30725;
  heroWindow::BroadcastMessage(arenaWinPtr, (Event *)&evt);
  v7 = 30726;
  heroWindow::BroadcastMessage(arenaWinPtr, (Event *)&evt);
  heroWindowManager::DoDialog(gpWindowManager, arenaWinPtr, (int (__fastcall *)(tag_message *))ArenaWindowHandler, 0);
  operator delete(arenaWinPtr);
  return choice;
}