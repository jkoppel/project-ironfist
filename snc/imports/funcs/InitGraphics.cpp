{
  LogStr("IG1");
  ConnectToDLLs();
  LogStr("IG2");
  if ( *(&bMenu + 7 * giCurExe + 5) )
    giGraphicsType = 2;
  else
    giGraphicsType = 1;
  if ( giGraphicsType == 1 )
  {
    LogStr("IG3");
    WGInitGraphics();
    LogStr("IG4");
  }
  else
  {
    LogStr("IG5");
    DDInitGraphics();
    LogStr("IG6");
  }
}