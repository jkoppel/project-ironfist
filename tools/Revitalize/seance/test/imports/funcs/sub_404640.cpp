{
  debugLog("ServiceProvider:");
  _strupr(prefix);
  logUpTo7Ints((int)prefix, a1, -999, -999, -999, -999, -999, -999);
  if ( sub_4C9110(prefix, "IPX") )
  {
    dword_4ED2D4 = a1;
  }
  else
  {
    if ( sub_4C9110(prefix, (const char *)&off_4ED330) )
      dword_4ED2D8 = a1;
  }
  return 1;
}
