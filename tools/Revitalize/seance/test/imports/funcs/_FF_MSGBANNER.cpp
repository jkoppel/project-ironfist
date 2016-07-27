{
  int result; // eax@1

  result = dword_520D0C;
  if ( dword_520D0C == 1 || !dword_520D0C && dword_520D10 == 1 )
  {
    _NMSG_WRITE(252);
    if ( dword_521820 )
      dword_521820();
    result = _NMSG_WRITE(255);
  }
  return result;
}
