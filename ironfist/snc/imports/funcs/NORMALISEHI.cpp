{
  int result; // eax@2

  if ( lastPP > a1 )
    result = a1;
  else
    result = a1 - lastPP;
  return result;
}