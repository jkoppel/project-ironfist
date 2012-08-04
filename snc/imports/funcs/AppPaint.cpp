{
  signed int result; // eax@2

  if ( giGraphicsType == 1 )
    result = WGAppPaint(this);
  else
    result = DDAppPaint(this);
  return result;
}