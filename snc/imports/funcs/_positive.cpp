{
  signed int result; // eax@1

  result = 1;
  if ( *(double *)a1 < 0.0 )
    result = 0;
  return result;
}