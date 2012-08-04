{
  LogStr("ServiceProvider:");
  _strupr(prefix);
  LogInt((int)prefix, a1, -999, -999, -999, -999, -999, -999);
  if ( FindStringInString(prefix, "IPX") )
  {
    IPXGuid = a1;
  }
  else if ( FindStringInString(prefix, (const char *)&off_4ED330) )
  {
    TCPGuid = a1;
  }
  return 1;
}