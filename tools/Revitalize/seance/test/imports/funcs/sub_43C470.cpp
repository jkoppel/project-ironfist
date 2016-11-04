{
  signed int result; // eax@2

  if ( a1 == 13 )
  {
    result = 5;
  }
  else
  {
    if ( a1 >= 1 && (a1 <= 3 || a1 == 5) )
      result = a1;
    else
      result = a1;
  }
  return result;
}
