{
  int result; // eax@2

  if ( dword_510BEC )
    result = SmackClose(dword_510BEC);
  dword_510BEC = 0;
  if ( dword_510BF0 )
    result = SmackClose(dword_510BF0);
  dword_510BF0 = 0;
  return result;
}
