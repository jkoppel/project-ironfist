{
  char v1; // al@3
  char v2; // al@3
  void *v3; // [sp+Ch] [bp-24h]@1
  tag_message evt; // [sp+10h] [bp-20h]@1
  int skill; // [sp+2Ch] [bp-4h]@1

  v3 = this;
  evt.eventCode = 512;
  evt.xCoordOrKeycode = 3;
  evt.payload = gText;
  for ( skill = 0; skill < 4; ++skill )
  {
    evt.yCoord = skill + 67;
    v1 = hero::Stats(*(hero **)((char *)v3 + 62), (PRIMARY_SKILL)skill);
    sprintf(gText, "%d", v1);
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
    evt.yCoord = skill + 72;
    v2 = hero::Stats(*(hero **)((char *)v3 + 66), (PRIMARY_SKILL)skill);
    sprintf(gText, "%d", v2);
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
  for ( skill = 0; skill < 5; ++skill )
  {
    evt.yCoord = skill + 78;
    if ( *(_BYTE *)(*(_DWORD *)((char *)v3 + 62) + skill + 101) == -1 )
    {
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
    }
    else
    {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
      evt.xCoordOrKeycode = 4;
      evt.payload = (void *)*(_BYTE *)(*(_DWORD *)((char *)v3 + 62) + skill + 101);
    }
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
  for ( skill = 0; skill < 5; ++skill )
  {
    evt.yCoord = skill + 116;
    if ( *(_BYTE *)(*(_DWORD *)((char *)v3 + 62) + skill + 101) == -1 )
    {
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
    }
    else
    {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
      evt.xCoordOrKeycode = 3;
      sprintf(gText, "%d", *(_WORD *)(*(_DWORD *)((char *)v3 + 62) + 2 * skill + 106));
      evt.payload = gText;
    }
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
  for ( skill = 0; skill < 5; ++skill )
  {
    evt.yCoord = skill + 83;
    if ( *(_BYTE *)(*(_DWORD *)((char *)v3 + 66) + skill + 101) == -1 )
    {
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
    }
    else
    {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
      evt.xCoordOrKeycode = 4;
      evt.payload = (void *)*(_BYTE *)(*(_DWORD *)((char *)v3 + 66) + skill + 101);
    }
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
  for ( skill = 0; skill < 5; ++skill )
  {
    evt.yCoord = skill + 121;
    if ( *(_BYTE *)(*(_DWORD *)((char *)v3 + 66) + skill + 101) == -1 )
    {
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
    }
    else
    {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
      evt.xCoordOrKeycode = 3;
      sprintf(gText, "%d", *(_WORD *)(*(_DWORD *)((char *)v3 + 66) + 2 * skill + 106));
      evt.payload = gText;
    }
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
  for ( skill = 0; skill < 14; ++skill )
  {
    evt.yCoord = skill + 88;
    if ( *(_BYTE *)(*(_DWORD *)((char *)v3 + 62) + skill + 213) == -1 )
    {
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
    }
    else
    {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
      evt.xCoordOrKeycode = 4;
      evt.payload = (void *)*(_BYTE *)(*(_DWORD *)((char *)v3 + 62) + skill + 213);
    }
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
  for ( skill = 0; skill < 14; ++skill )
  {
    evt.yCoord = skill + 102;
    if ( *(_BYTE *)(*(_DWORD *)((char *)v3 + 66) + skill + 213) == -1 )
    {
      evt.xCoordOrKeycode = 6;
      evt.payload = (void *)4;
    }
    else
    {
      evt.xCoordOrKeycode = 5;
      evt.payload = (void *)4;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
      evt.xCoordOrKeycode = 4;
      evt.payload = (void *)*(_BYTE *)(*(_DWORD *)((char *)v3 + 66) + skill + 213);
    }
    heroWindow::BroadcastMessage(*(heroWindow **)((char *)v3 + 54), (Event *)&evt);
  }
}