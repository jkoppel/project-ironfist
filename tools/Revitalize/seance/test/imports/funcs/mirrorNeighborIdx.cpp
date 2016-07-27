{
  int result; // eax@2

  if ( a1 >= 6 )
  {
    if ( a1 == 6 )
      result = 7;
    else
      result = 6;
  }
  else
  {
    result = (a1 + 3) % 6;
  }
  return result;
}
