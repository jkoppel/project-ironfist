{
  char result; // al@2

  if ( KBTickCount() >= iLastActionTime + 250 )
  {
    iLastActionTime = KBTickCount();
    if ( iModemCommandPos >= strlen((int)cModemCommand) )
    {
      write_buffer(L"\r", 1);
      result = 1;
    }
    else
    {
      write_buffer(&cModemCommand[iModemCommandPos++], 1);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}