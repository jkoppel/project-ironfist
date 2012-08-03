{
  signed int result; // eax@2

  if ( giGraphicsType == 1 )
    result = WGQueryNewPalette();
  else
    result = DDQueryNewPalette();
  return result;
}