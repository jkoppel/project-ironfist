{
  signed int result; // eax@2

  if ( giGraphicsType == 1 )
    result = 0;
  else
    result = DDSetPalette();
  return result;
}