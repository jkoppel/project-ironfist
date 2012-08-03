{
  int result; // eax@2

  if ( a2 == a1 )
  {
    result = a2;
  }
  else if ( a2 >= a1 )
  {
    result = a1 + (signed int)rand() % (a2 - a1 + 1);
  }
  else
  {
    result = a1;
  }
  return result;
}