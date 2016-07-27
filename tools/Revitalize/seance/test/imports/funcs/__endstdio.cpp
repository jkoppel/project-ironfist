{
  int result; // eax@1

  result = _flushall();
  if ( byte_520B78 )
    result = _fcloseall();
  return result;
}
