{
  if ( iLastMsgNumHumanPlayers != 1 && iMPBaseType != 2 )
  {
    if ( KBTickCount() > glTimers )
    {
      NGKPcursorFlashOn = 1 - NGKPcursorFlashOn;
      glTimers = KBTickCount() + 360;
    }
    if ( (signed int)a2 > 0 )
      strncpy(cNGKPDisplay, a1, a2);
    if ( NGKPcursorFlashOn )
      cNGKPDisplay[a2] = 31;
    else
      cNGKPDisplay[a2] = 95;
    if ( strlen((int)a1) <= (unsigned int)a2 )
      cNGKPDisplay[a2 + 1] = 0;
    else
      strcpy(&cNGKPDisplay[a2 + 1], (char *)&a1[a2]);
  }
}