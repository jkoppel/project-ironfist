{
  int v2; // [sp+14h] [bp-28h]@1
  int evt; // [sp+18h] [bp-24h]@18
  int v4; // [sp+1Ch] [bp-20h]@18
  int v5; // [sp+20h] [bp-1Ch]@18
  int v6; // [sp+30h] [bp-Ch]@18
  char *v7; // [sp+34h] [bp-8h]@1
  int i; // [sp+38h] [bp-4h]@5

  v2 = a1;
  v7 = &buf[1];
  switch ( buf[0] )
  {
    case 1:
      *((_DWORD *)dword_4ED2E8 + dword_4ED2E0) = KBAlloc(a1 - 1, "F:\\h2xsrc\\Source\\Wsnetwin.cpp", word_511CE0 + 10);
      memcpy(*((void **)dword_4ED2E8 + dword_4ED2E0), &buf[1], v2 - 1);
      *((_DWORD *)dword_4ED2EC + dword_4ED2E0) = v2;
      dword_4ED2E0 = (dword_4ED2E0 + 1) % 200;
      break;
    case 2:
      if ( (unsigned __int8)byte_51257C == 1 )
      {
        if ( dword_524A6C )
        {
          for ( i = 1; i < dword_5235D4; ++i )
          {
            if ( *((_DWORD *)&dword_522B78 + i) == a2 || (char *)&dword_526CE0 + 34 * i == v7 )
            {
              sub_45F5F0(*((_DWORD *)&dword_522B78 + i), 4, 0, 0);
              return;
            }
          }
          *((_DWORD *)&dword_522B78 + dword_5235D4) = a2;
          logUpTo7Ints((int)"Got HereIAm from ", a2, -999, -999, -999, -999, -999, -999);
          memcpy((char *)&dword_526CE0 + 34 * dword_5235D4, v7, 0x22u);
          if ( !byte_526CFC[34 * dword_5235D4] )
            byte_51AC64 = 1;
          sub_45F5F0(*((_DWORD *)&dword_522B78 + dword_5235D4++), 4, 0, 0);
        }
        else
        {
          sub_45F5F0(a2, 5, 0, 0);
        }
      }
      break;
    case 3:
      dword_5235D4 = *v7;
      dword_523F14 = v7[1];
      logUpTo7Ints((int)"WSMSGSTARTUP", dword_523F14, a2, -999, -999, -999, -999, -999);
      memcpy(&dword_522B78, v7 + 2, 0x18u);
      dword_4ED2F0 = 1;
      break;
    case 5:
      sprintf(cp, "The Host already has a game in progress and is not accepting new players.");
      display_message_window(cp, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      terminate(0);
      break;
    case 4:
      sprintf(cp, "Waiting for other remote player to set up game.");
      evt = 512;
      v4 = 3;
      v5 = 1;
      v6 = (int)cp;
      GUIWindow::processMessage(eventWindow, (Event *)&evt);
      GUIWindow::repaintAndUpdateScreen(eventWindow);
      dword_511780 = 1;
      break;
    default:
      sprintf(cp, "Unknown message: %d\n", buf[0]);
      if ( debugLogLevel > 0 )
      {
        sprintf(globBuf, cp);
        display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      debugLog(cp);
      break;
  }
}
