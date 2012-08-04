{
  int result; // eax@1

  result = _flushall();
  if ( _exitflag )
    result = _fcloseall();
  return result;
}