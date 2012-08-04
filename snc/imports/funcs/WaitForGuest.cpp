{
  char result; // al@4

  if ( iWaitForGuestStatus )
  {
    if ( iWaitForGuestStatus == 1 )
    {
      if ( nb_stat(6) & 1 )
      {
        nb_sess(5, 6);
        return 1;
      }
      if ( KBTickCount() > iLastBroadcastTime + 500 )
      {
        iLastBroadcastTime = KBTickCount();
        nb_snd(0, 0, 0);
      }
    }
    result = 0;
  }
  else
  {
    if ( !nb_sess(3, 6) )
      ++iWaitForGuestStatus;
    result = 0;
  }
  return result;
}