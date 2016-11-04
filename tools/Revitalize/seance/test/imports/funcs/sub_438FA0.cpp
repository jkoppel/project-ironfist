{
  GUIWindow *result; // eax@4
  int v5; // [sp+10h] [bp-200h]@1
  char msg; // [sp+14h] [bp-1FCh]@12
  int v7; // [sp+208h] [bp-8h]@1
  int i; // [sp+20Ch] [bp-4h]@17

  v5 = a1;
  v7 = 0;
  if ( !a2 )
  {
    if ( (_BYTE)a4 )
    {
      if ( (char)a3 == dword_523F14 )
      {
        sub_46D360();
        sprintf(globBuf, "You have been eliminated from the game!!!");
        result = display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        dword_4EF268 = 1;
        dword_522FF8 = 0;
        return result;
      }
      sprintf(globBuf, "%s has been vanquished!", (char *)&dword_526CE0 + 34 * (char)a3 + 4);
      display_message_window(globBuf, 1, -1, -1, 9, gameObject->players[SBYTE1(a3)].color, -1, -1, -1, 5000);
    }
    else
    {
      if ( BYTE2(a4) )
      {
        if ( BYTE3(a3) )
          sprintf(
            &msg,
            "Host player %s reports that player %s has been timed out of the game.  The game will continue with a computer player filling in for %s.",
            (char *)&dword_526CE0 + 34 * a1 + 4,
            (char *)&dword_526CE0 + 34 * (char)a3 + 4,
            (char *)&dword_526CE0 + 34 * (char)a3 + 4);
        else
          sprintf(
            &msg,
            "Host player %s reports that player %s has exited the game.  The game will continue with a computer player filling in for %s.",
            (char *)&dword_526CE0 + 34 * a1 + 4,
            (char *)&dword_526CE0 + 34 * (char)a3 + 4,
            (char *)&dword_526CE0 + 34 * (char)a3 + 4);
        v7 = 1;
      }
      else
      {
        GameInfo::saveGame(gameObject, "PLYREXIT", 1, 0);
        sprintf(
          globBuf,
          "%s left the game, and the %s decided to terminate the entire game.  The game has been saved as 'PLYREXIT'.  Do you wish to play on alone with the computer taking over for all human players?",
          (char *)&dword_526CE0 + 34 * (char)a3 + 4,
          (char *)&dword_526CE0 + 34 * v5 + 4);
        display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
        {
          sub_438F30();
        }
        else
        {
          sub_46D360();
          terminate(0);
        }
      }
    }
  }
  if ( (char)a3 < dword_523F14 )
    --dword_523F14;
  dword_524810[SBYTE1(a3)] = 0;
  for ( i = (char)a3; i < 5; ++i )
  {
    dword_526DB0[i] = dword_526DB4[i];
    *((_DWORD *)&dword_522B78 + i) = dword_522B7C[i];
    strcpy((char *)&dword_526CE0 + 34 * i + 4, (const char *)&dword_526CE0 + 34 * (i + 1) + 4);
  }
  for ( i = 0; i < 6; ++i )
  {
    if ( *((_BYTE *)&byte_5247A0 + i) == (char)a3 )
    {
      *((_BYTE *)&byte_5247A0 + i) = -1;
    }
    else
    {
      if ( *((_BYTE *)&byte_5247A0 + i) > (char)a3 )
        --*((_BYTE *)&byte_5247A0 + i);
    }
  }
  --dword_5235D4;
  dword_4F31B8 = -2;
  result = (GUIWindow *)SBYTE2(a3);
  if ( BYTE2(a3) )
    result = (GUIWindow *)sub_456A10();
  if ( v7 )
    result = display_message_window(&msg, 1, -1, -1, -1, -1, -1, -1, -1, 5000);
  return result;
}
