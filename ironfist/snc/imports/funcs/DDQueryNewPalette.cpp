{
  signed int result; // eax@2

  if ( gbWinGraphBusy )
  {
    result = 1;
  }
  else if ( gbForegroundApp )
  {
    result = SetPalette();
  }
  else
  {
    result = 1;
  }
  return result;
}