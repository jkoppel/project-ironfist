{
  void *v2; // eax@2
  int v3; // eax@28
  signed int v4; // [sp+Ch] [bp-10h]@1
  int i; // [sp+10h] [bp-Ch]@17

  v4 = 0;
  dword_526DB0[(char)a1] = 199999999;
  GameInfo::saveGame(gameObject, "PLYREXIT", 1, 0);
  if ( (_BYTE)a2 )
  {
    BYTE2(a2) = 1;
    v2 = (void *)(char)a1;
    if ( (char)a1 == dword_523F14 )
    {
      v4 = 1;
    }
    else
    {
      sprintf(globBuf, "%s has been vanquished!", (char *)&dword_526CE0 + 34 * (char)a1 + 4);
      v2 = display_message_window(globBuf, 1, -1, -1, 9, gameObject->players[SBYTE1(a1)].color, -1, -1, -1, 5000);
      BYTE2(a2) = 1;
    }
  }
  else
  {
    if ( BYTE3(a1) )
      sprintf(
        globBuf,
        "%s has been timed out of the game.  The current game has been saved as 'PLYREXIT'.  Do you wish to continue playing with a computer player filling in for %s?",
        (char *)&dword_526CE0 + 34 * (char)a1 + 4,
        (char *)&dword_526CE0 + 34 * (char)a1 + 4);
    else
      sprintf(
        globBuf,
        "%s is exiting the game.  The current game has been saved as 'PLYREXIT'.  Do you wish to continue playing with a computer player filling in for %s?",
        (char *)&dword_526CE0 + 34 * (char)a1 + 4,
        (char *)&dword_526CE0 + 34 * (char)a1 + 4);
    display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
    v2 = HeroWindowManager::instance;
    BYTE2(a2) = HeroWindowManager::instance->buttonPressedCode == 30725;
  }
  if ( dword_5235D4 == 2 )
  {
    if ( (_BYTE)a2 && !BYTE1(a2) )
      sub_46E1D0(&a1, 1 - dword_523F14, 7u, 33, 1, 1, -1);
    if ( !v4 )
    {
      --dword_5235D4;
      dword_524810[SBYTE1(a1)] = 0;
      sub_46D360();
      sub_456A10();
    }
  }
  else
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( (char)a1 != i || !(_BYTE)a2 || BYTE1(a2) )
      {
        v2 = (void *)(char)a1;
        if ( (char)a1 == i )
          continue;
        v2 = (void *)dword_5235D4;
        if ( i >= dword_5235D4 )
          continue;
        v2 = (void *)i;
        if ( dword_523F14 == i )
          continue;
      }
      v2 = (void *)sub_46E1D0(&a1, i, 7u, 33, 1, 1, -1);
    }
    if ( !v4 )
    {
      LOBYTE(v2) = BYTE2(a2);
      v3 = (_DWORD)v2 << 16;
      LOWORD(v3) = a2;
      sub_438FA0(0, 1, a1, v3);
    }
  }
  if ( v4 )
  {
    sprintf(globBuf, "You have been eliminated from the game!!!");
    sub_46D360();
    display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
    dword_4EF268 = 1;
    dword_522FF8 = 0;
  }
  else
  {
    if ( !BYTE2(a2) )
      terminate(0);
  }
}
