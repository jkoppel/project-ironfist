{
  debugLog("GUON1");
  if ( (unsigned __int8)byte_51257C == 1 )
  {
    dword_524750 = 4;
    sprintf(globBuf, "Initializing network.\n\n  Press 'CANCEL' to abort.");
    display_message_window(globBuf, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    if ( !dword_523018 )
      terminate(0);
    dword_524750 = 1;
    sprintf(globBuf, "Waiting On Guest.\n\n  Press 'CANCEL' to abort.");
    debugLog("GUON2");
    display_message_window(globBuf, 6, -1, -1, -1, 0, -1, 0, -1, 0);
    debugLog("GUON3");
    if ( !dword_523018 )
      terminate(0);
    debugLog("GUON4");
  }
  else
  {
    if ( (unsigned __int8)byte_51257C == 2 )
    {
      dword_524750 = 3;
      sprintf(globBuf, "Initializing network.\n\n  Press 'CANCEL' to abort.");
      display_message_window(globBuf, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( !dword_523018 )
        terminate(0);
      dword_524750 = 2;
      sprintf(globBuf, "Waiting On Host.\n\n  Press 'CANCEL' to abort.");
      display_message_window(globBuf, 6, -1, -1, -1, 0, -1, 0, -1, 0);
      if ( !dword_523018 )
        terminate(0);
    }
  }
  debugLog("GUON5");
  return 0;
}
