{
  if ( !gbInMemError )
  {
    gbInMemError = 1;
    LogStr("Out of Memory");
    sprintf(gText, cOutOfMemory, "Out of memory.", 6400);
    ShutDown(gText);
  }
}