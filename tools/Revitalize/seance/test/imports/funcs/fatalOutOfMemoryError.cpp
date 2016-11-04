{
  if ( !outOfMemoryErrorLock )
  {
    outOfMemoryErrorLock = 1;
    debugLog("Out of Memory");
    sprintf(globBuf, off_4F71C8, "Out of memory.", 6400);
    terminate(globBuf);
  }
}
