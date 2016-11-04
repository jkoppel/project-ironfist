{
  char result; // al@3

  if ( a1 < 'a' || a1 > 'z' )
    result = a1;
  else
    result = a1 - 32;
  return result;
}
