{
  signed int result; // eax@2

  if ( _fpclass(SLODWORD(a1), SHIDWORD(a1)) & 0x90 )
  {
    result = 0;
  }
  else if ( _frnd(a1) == a1 )
  {
    if ( _frnd(a1 * 0.5) == a1 * 0.5 )
      result = 2;
    else
      result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}